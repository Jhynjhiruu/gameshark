#include "common.h"
#include "linker.h"

#include "libc.h"

#include "fsblob.h"

unsigned long int textsize = 0;
unsigned long int codesize = 0;
unsigned long int printcount = 0;

void Error(char *message) {}

// these variables should be defined in different places, but the .bss ordering
// goes wrong if I try that

unsigned int GetBit_mask;
unsigned int PutBit_mask;
int *sym_to_char;
int *char_to_sym;
int D_80042A50;
unsigned int GetBit_buffer;
unsigned int PutBit_buffer;
int match_length;
unsigned int *sym_cum;
unsigned int *position_cum;
int *dad;
u8 *infile;
int D_80042A70;
int D_80042A74;
unsigned char *text_buf;
unsigned int *sym_freq;
int *lson;
int *rson;
u8 *outfile;
int D_80042A8C;
int match_position;

void PutBit(int bit) /* Output one bit (bit = 0,1) */ {
    if (bit)
        PutBit_buffer |= PutBit_mask;
    if ((PutBit_mask >>= 1) == 0) {
        outfile[D_80042A70++] = PutBit_buffer;
        if (D_80042A70 >= D_80042A8C) {
            Error("Write Error");
        }
        PutBit_buffer = 0;
        PutBit_mask = 128;
        codesize++;
    }
}

void FlushBitBuffer(void) /* Send remaining bits */ {
    int i;

    for (i = 0; i < 7; i++) {
        PutBit(0);
    };
}

int GetBit(void) /* Get one bit (0 or 1) */ {
    if ((GetBit_mask >>= 1) == 0) {
        GetBit_buffer = infile[D_80042A50++];
        GetBit_mask = 128;
    }
    return ((GetBit_buffer & GetBit_mask) != 0);
}

#define N 4096 /* size of ring buffer */
#define F 60   /* upper limit for match_length */
#define THRESHOLD                                                              \
    2         /* encode string into position and length                        \
                 if match_length is greater than this */
#define NIL N /* index for root of binary search trees */

void InitTree(void) /* Initialize trees */ {
    int i;

    /* For i = 0 to N - 1, rson[i] and lson[i] will be the right and
       left children of node i.  These nodes need not be initialized.
       Also, dad[i] is the parent of node i.  These are initialized to
       NIL (= N), which stands for 'not used.'
       For i = 0 to 255, rson[N + i + 1] is the root of the tree
       for strings that begin with character i.  These are initialized
       to NIL.  Note there are 256 trees. */

    for (i = N + 1; i <= N + 256; i++)
        rson[i] = NIL; /* root */
    for (i = 0; i < N; i++)
        dad[i] = NIL; /* node */
}

void InsertNode(int r)
/* Inserts string of length F, text_buf[r..r+F-1], into one of the
   trees (text_buf[r]'th tree) and returns the longest-match position
   and length via the global variables match_position and match_length.
   If match_length = F, then removes the old node in favor of the new
   one, because the old one will be deleted sooner.
   Note r plays double role, as tree node and position in buffer. */
{
    int i, p, cmp, temp;
    unsigned char *key;

    cmp = 1;
    key = &text_buf[r];
    p = N + 1 + key[0];
    rson[r] = lson[r] = NIL;
    match_length = 0;
    for (;;) {
        if (cmp >= 0) {
            if (rson[p] != NIL)
                p = rson[p];
            else {
                rson[p] = r;
                dad[r] = p;
                return;
            }
        } else {
            if (lson[p] != NIL)
                p = lson[p];
            else {
                lson[p] = r;
                dad[r] = p;
                return;
            }
        }
        for (i = 1; i < F; i++)
            if ((cmp = key[i] - text_buf[p + i]) != 0)
                break;
        if (i > THRESHOLD) {
            if (i > match_length) {
                match_position = (r - p) & (N - 1);
                if ((match_length = i) >= F)
                    break;
            } else if (i == match_length) {
                if ((temp = (r - p) & (N - 1)) < match_position)
                    match_position = temp;
            }
        }
    }
    dad[r] = dad[p];
    lson[r] = lson[p];
    rson[r] = rson[p];
    dad[lson[p]] = r;
    dad[rson[p]] = r;
    if (rson[dad[p]] == p)
        rson[dad[p]] = r;
    else
        lson[dad[p]] = r;
    dad[p] = NIL; /* remove p */
}

void DeleteNode(int p) /* Delete node p from tree */
{
    int q;

    if (dad[p] == NIL)
        return; /* not in tree */
    if (rson[p] == NIL)
        q = lson[p];
    else if (lson[p] == NIL)
        q = rson[p];
    else {
        q = lson[p];
        if (rson[q] != NIL) {
            do {
                q = rson[q];
            } while (rson[q] != NIL);
            rson[dad[q]] = lson[q];
            dad[lson[q]] = dad[q];
            lson[q] = lson[p];
            dad[lson[p]] = q;
        }
        rson[q] = rson[p];
        dad[rson[p]] = q;
    }
    dad[q] = dad[p];
    if (rson[dad[p]] == p)
        rson[dad[p]] = q;
    else
        lson[dad[p]] = q;
    dad[p] = NIL;
}

/********** Arithmetic Compression **********/

/*  If you are not familiar with arithmetic compression, you should read
        I. E. Witten, R. M. Neal, and J. G. Cleary,
            Communications of the ACM, Vol. 30, pp. 520-540 (1987),
    from which much have been borrowed.  */

#define M 15

/*	Q1 (= 2 to the M) must be sufficiently large, but not so
    large as the unsigned long 4 * Q1 * (Q1 - 1) overflows.  */

#define Q1 (1UL << M)
#define Q2 (2 * Q1)
#define Q3 (3 * Q1)
#define Q4 (4 * Q1)
#define MAX_CUM (Q1 - 1)

#define N_CHAR (256 - THRESHOLD + F)
/* character code = 0, 1, ..., N_CHAR - 1 */

unsigned long int low = 0, high = Q4, value = 0;
int shifts = 0; /* counts for magnifying low and high around Q2 */

void StartModel(void) /* Initialize model */
{
    int ch, sym, i;

    sym_cum[N_CHAR] = 0;
    for (sym = N_CHAR; sym >= 1; sym--) {
        ch = sym - 1;
        char_to_sym[ch] = sym;
        sym_to_char[sym] = ch;
        sym_freq[sym] = 1;
        sym_cum[sym - 1] = sym_cum[sym] + sym_freq[sym];
    }
    sym_freq[0] = 0; /* sentinel (!= sym_freq[1]) */
    position_cum[N] = 0;
    for (i = N; i >= 1; i--)
        position_cum[i - 1] = position_cum[i] + 10000 / (i + 200);
    /* empirical distribution function (quite tentative) */
    /* Please devise a better mechanism! */
}

void UpdateModel(int sym) {
    int i, c, ch_i, ch_sym;

    if (sym_cum[0] >= MAX_CUM) {
        c = 0;
        for (i = N_CHAR; i > 0; i--) {
            sym_cum[i] = c;
            c += (sym_freq[i] = (sym_freq[i] + 1) >> 1);
        }
        sym_cum[0] = c;
    }
    for (i = sym; sym_freq[i] == sym_freq[i - 1]; i--)
        ;
    if (i < sym) {
        ch_i = sym_to_char[i];
        ch_sym = sym_to_char[sym];
        sym_to_char[i] = ch_sym;
        sym_to_char[sym] = ch_i;
        char_to_sym[ch_i] = sym;
        char_to_sym[ch_sym] = i;
    }
    sym_freq[i]++;
    while (--i >= 0)
        sym_cum[i]++;
}

static void Output(int bit) /* Output 1 bit, followed by its complements */
{
    PutBit(bit);
    for (; shifts > 0; shifts--)
        PutBit(!bit);
}

void EncodeChar(int ch) {
    int sym;
    unsigned long int range;

    sym = char_to_sym[ch];
    range = high - low;
    high = low + (range * sym_cum[sym - 1]) / sym_cum[0];
    low += (range * sym_cum[sym]) / sym_cum[0];
    for (;;) {
        if (high <= Q2)
            Output(0);
        else if (low >= Q2) {
            Output(1);
            low -= Q2;
            high -= Q2;
        } else if (low >= Q1 && high <= Q3) {
            shifts++;
            low -= Q1;
            high -= Q1;
        } else
            break;
        low += low;
        high += high;
    }
    UpdateModel(sym);
}

void EncodePosition(int position) {
    unsigned long int range;

    range = high - low;
    high = low + (range * position_cum[position]) / position_cum[0];
    low += (range * position_cum[position + 1]) / position_cum[0];
    for (;;) {
        if (high <= Q2)
            Output(0);
        else if (low >= Q2) {
            Output(1);
            low -= Q2;
            high -= Q2;
        } else if (low >= Q1 && high <= Q3) {
            shifts++;
            low -= Q1;
            high -= Q1;
        } else
            break;
        low += low;
        high += high;
    }
}

void EncodeEnd(void) {
    shifts++;
    if (low < Q1)
        Output(0);
    else
        Output(1);
    FlushBitBuffer(); /* flush bits remaining in buffer */
}

int BinarySearchSym(unsigned int x)
/* 1      if x >= sym_cum[1],
   N_CHAR if sym_cum[N_CHAR] > x,
   i such that sym_cum[i - 1] > x >= sym_cum[i] otherwise */
{
    int i, j, k;

    i = 1;
    j = N_CHAR;
    while (i < j) {
        k = (i + j) / 2;
        if (sym_cum[k] > x)
            i = k + 1;
        else
            j = k;
    }
    return i;
}

int BinarySearchPos(unsigned int x)
/* 0 if x >= position_cum[1],
   N - 1 if position_cum[N] > x,
   i such that position_cum[i] > x >= position_cum[i + 1] otherwise */
{
    int i, j, k;

    i = 1;
    j = N;
    while (i < j) {
        k = (i + j) / 2;
        if (position_cum[k] > x)
            i = k + 1;
        else
            j = k;
    }
    return i - 1;
}

void StartDecode(void) {
    int i;

    for (i = 0; i < M + 2; i++)
        value = 2 * value + GetBit();
}

int DecodeChar(void) {
    int sym, ch;
    unsigned long int range;

    range = high - low;
    sym = BinarySearchSym(
        (unsigned int)(((value - low + 1) * sym_cum[0] - 1) / range));
    high = low + (range * sym_cum[sym - 1]) / sym_cum[0];
    low += (range * sym_cum[sym]) / sym_cum[0];
    for (;;) {
        if (low >= Q2) {
            value -= Q2;
            low -= Q2;
            high -= Q2;
        } else if (low >= Q1 && high <= Q3) {
            value -= Q1;
            low -= Q1;
            high -= Q1;
        } else if (high > Q2)
            break;
        low += low;
        high += high;
        value = 2 * value + GetBit();
    }
    ch = sym_to_char[sym];
    UpdateModel(sym);
    return ch;
}

int DecodePosition(void) {
    int position;
    unsigned long int range;

    range = high - low;
    position = BinarySearchPos(
        (unsigned int)(((value - low + 1) * position_cum[0] - 1) / range));
    high = low + (range * position_cum[position]) / position_cum[0];
    low += (range * position_cum[position + 1]) / position_cum[0];
    for (;;) {
        if (low >= Q2) {
            value -= Q2;
            low -= Q2;
            high -= Q2;
        } else if (low >= Q1 && high <= Q3) {
            value -= Q1;
            low -= Q1;
            high -= Q1;
        } else if (high > Q2)
            break;
        low += low;
        high += high;
        value = 2 * value + GetBit();
    }
    return position;
}

/********** Encode and Decode **********/

s32 Encode(u8 *arg0, u8 *arg1, s32 arg2) {
    int i, c, len, r, s, last_match_length;

    text_buf = func_80042178((N + F - 1) * sizeof(unsigned char));
    lson = func_80042178((N + 1) * sizeof(int));
    rson = func_80042178((N + 257) * sizeof(int));
    dad = func_80042178((N + 1) * sizeof(int));
    char_to_sym = func_80042178(N_CHAR * sizeof(int));
    sym_to_char = func_80042178((N_CHAR + 1) * sizeof(int));
    sym_freq = func_80042178((N_CHAR + 1) * sizeof(int));
    sym_cum = func_80042178((N_CHAR + 1) * sizeof(int));
    position_cum = func_80042178((N + 1) * sizeof(int));
    textsize = 0;
    codesize = 0;
    printcount = 0;
    PutBit_buffer = 0;
    PutBit_mask = 128;
    GetBit_buffer = 0;
    GetBit_mask = 0;
    low = 0;
    high = Q4;
    value = 0;
    outfile = arg0;
    infile = arg1;
    D_80042A74 = arg2;
    textsize = arg2;
    D_80042A8C = arg2;
    D_80042A50 = 0;
    D_80042A70 = 0;

    for (i = 0; i < 4; i++) {
        outfile[D_80042A70++] = D_80042A74 >> (i * 8);
    }
    codesize += 4;
    if (textsize == 0) {
        return 0;
    }
    textsize = 0;
    StartModel();
    InitTree();
    s = 0;
    r = N - F;
    for (i = s; i < r; i++) {
        text_buf[i] = ' ';
    }

    for (len = 0; (len < F) && (D_80042A50 < D_80042A74); len++) {
        c = infile[D_80042A50++];
        text_buf[r + len] = c;
    }

    textsize = len;
    for (i = 1; i <= F; i++) {
        InsertNode(r - i);
    }
    InsertNode(r);

    do {
        if (match_length > len) {
            match_length = len;
        }

        if (match_length > len) {
            match_length = len;
        }
        if (match_length <= THRESHOLD) {
            match_length = 1;
            EncodeChar(text_buf[r]);
        } else {
            EncodeChar(255 - THRESHOLD + match_length);
            EncodePosition(match_position - 1);
        }

        last_match_length = match_length;

        for (i = 0; (i < last_match_length) && (D_80042A50 < D_80042A74); i++) {
            c = infile[D_80042A50++];
            DeleteNode(s);

            text_buf[s] = c;

            if (s < F - 1) {
                text_buf[s + N] = c;
            }

            s = (s + 1) & (N - 1);
            r = (r + 1) & (N - 1);

            InsertNode(r);
        }

        while (i++ < last_match_length) {
            DeleteNode(s);
            s = (s + 1) & (N - 1);
            r = (r + 1) & (N - 1);
            if (--len) {
                InsertNode(r);
            }
        }
    } while (len > 0);
    EncodeEnd();
    func_8004224C(position_cum);
    func_8004224C(sym_cum);
    func_8004224C(sym_freq);
    func_8004224C(sym_to_char);
    func_8004224C(char_to_sym);
    func_8004224C(dad);
    func_8004224C(rson);
    func_8004224C(lson);
    func_8004224C(text_buf);
    return D_80042A70;
}

s32 Decode(void *loadaddr, u8 *dataStart) {
    int i, j, k, r, c;
    unsigned long int count;

    text_buf = func_80042178((N + F - 1) * sizeof(unsigned char));
    lson = func_80042178((N + 1) * sizeof(int));
    rson = func_80042178((N + 257) * sizeof(int));
    dad = func_80042178((N + 1) * sizeof(int));
    char_to_sym = func_80042178(N_CHAR * sizeof(int));
    sym_to_char = func_80042178((N_CHAR + 1) * sizeof(int));
    sym_freq = func_80042178((N_CHAR + 1) * sizeof(int));
    sym_cum = func_80042178((N_CHAR + 1) * sizeof(int));
    position_cum = func_80042178((N + 1) * sizeof(int));
    textsize = 0;
    codesize = 0;
    printcount = 0;
    PutBit_buffer = 0;
    PutBit_mask = 0x80;
    GetBit_buffer = 0;
    GetBit_mask = 0;
    low = 0;
    high = 0x20000;
    value = 0;
    outfile = loadaddr;
    infile = dataStart;
    D_80042A50 = 0;
    D_80042A70 = 0;

    textsize = 0;
    for (i = 0; i < 4; i++) {
        textsize |= infile[D_80042A50] << (i * 8);
        D_80042A50++;
    }

    D_80042A8C = textsize;
    if (textsize == 0) {
        return 0;
    }
    StartDecode();
    StartModel();
    for (i = 0; i < 0xFC4; i++) {
        text_buf[i] = 0x20;
    }

    r = 0xFC4;
    count = 0;
    while (count < textsize) {
        c = DecodeChar();
        if (c < 0x100) {
            outfile[D_80042A70++] = c;
            text_buf[r++] = c;
            r &= 0xFFF;
            count++;
        } else {
            i = ((r - DecodePosition()) - 1) & 0xFFF;
            j = c - 0xFD;
            for (k = 0; k < j; k++) {
                c = text_buf[(i + k) & 0xFFF];
                outfile[D_80042A70++] = c;
                text_buf[r++] = c;
                r &= 0xFFF;
                count++;
            }
        }
    }

    func_8004224C(position_cum);
    func_8004224C(sym_cum);
    func_8004224C(sym_freq);
    func_8004224C(sym_to_char);
    func_8004224C(char_to_sym);
    func_8004224C(dad);
    func_8004224C(rson);
    func_8004224C(lson);
    func_8004224C(text_buf);

    return D_80042A70;
}

typedef struct {
    u32 length;
    char name[12];
    u8 fileData[0];
} FileEntry;

void func_80041FCC(void *loadAddr, char *filename) {
    u8 *ptr;
    u32 temp;

    ptr = FSBLOB;
    while (1) {
        s32 i = 1;
        temp = filename[0];
        while (temp != 0 && temp == ((FileEntry *)ptr)->name[i - 1]) {
            temp = filename[i];
            i++;
        }
        if (temp == 0) {
            break;
        }
        i = ptr[0] << 24;
        i |= ptr[1] << 16;
        i |= ptr[2] << 8;
        i |= ptr[3];
        ptr += i;
    }
    Decode(loadAddr, ((FileEntry *)ptr)->fileData);
}
