#include "common.h"
#include "include_asm.h"
#include "regs.h"

#include "15360.h"
#include "17630.h"
#include "18410.h"
#include "20CD0.h"
#include "540.h"

extern s16 D_802406D8[];
extern s16 D_80243418[];
extern u32 *D_802497D8;

int D_80225A00 = 0;

u8 D_80225A04[8] = {
    0,
};

int D_80225A0C[] = {
    0x3BADD1E5,
    0xFADE0000,
};

int SelectedBank[] = {
    -1, -1, -1, -1, -1, -1,
};

int D_80225A2C[] = {
    // NumBanks
    1, 1, 1, 1, 1, 1,
};

int D_80225A44[] = {
    // NumPages
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
};

int D_80225A5C[] = {
    // NotesStart
    3, 3, 3, 3, 3, 3,
};

int D_80225A74[] = {
    // DataStart
    5, 5, 5, 5, 5, 5,
};

u8 D_80225A8C[] = {
    1, 2, 3, 7, 10, 11, 12, 13, 14, 15, 26, 29, 31, 32,
};

u16 D_80225A9C[0x1002] = {
    0x80, 0x80, 0x80, 0x80, 0x80,
};

int D_80227AA0 = 0;
int D_80227AA4 = 0;
int D_80227AA8 = 0;
int D_80227AAC = 0;
int D_80227AB0 = 0;
int D_80227AB4 = 0;
int D_80227AB8 = 0;
char D_80227ABC[20] = "ChrisU";

INCLUDE_ASM("asm/shell/nonmatchings/540", func_80200940);

INCLUDE_ASM("asm/shell/nonmatchings/540", func_80201164);

INCLUDE_ASM("asm/shell/nonmatchings/540", func_802014F4);

INCLUDE_ASM("asm/shell/nonmatchings/540", func_8020162C);

int func_802017E4(int which) {
    int i;
    int count = 0;

    for (i = D_80225A5C[which]; i < D_80225A44[which]; i++) {
        if (D_80243418[i] == 1) {
            count++;
        }
    }

    return count;
}

INCLUDE_ASM("asm/shell/nonmatchings/540", func_8020184C);

INCLUDE_ASM("asm/shell/nonmatchings/540", func_802018CC);

INCLUDE_ASM("asm/shell/nonmatchings/540", func_80201D44);

int func_80201E64(void) { // has_cpak
    return controller_status() & 1;
}

void func_80201E84(int which, int bank) { // select_bank
    u8 *ptr = (u8 *)D_802497D8;

    SelectedBank[which] = bank;

    func_802157C8(ptr + 9, bank, 0x20);
    write_chunk(0x400, which);
}

int func_80201EE0(int which) {
    u8 buf[0x100];
    int fat_pages;

    func_80217BC4("ReadSize %8\n", which);
    func_80201E84(which, 0);
    func_8020222C(buf, 0, sizeof(buf), which);

    D_80225A2C[which] = buf[0x3A];
    D_80225A44[which] = D_80225A2C[which] << 7;

    fat_pages = D_80225A2C[which] * 2;
    D_80225A5C[which] = fat_pages + 1;
    D_80225A74[which] = fat_pages + 3;

    return D_80225A44[which];
}

INCLUDE_ASM("asm/shell/nonmatchings/540", func_80201F90);

int func_802021C4(int which) {
    int i;
    int count = 0;

    for (i = D_80225A74[which]; i < D_80225A44[which]; i++) {
        if (D_80243418[i] == 3) {
            count += 1;
        }
    }

    return count;
}

void func_8020222C(void *dst, int address, int len, int which) { // read_cpak
    int bank;
    int adjusted_address;
    int adjusted_len;
    u8 *ptr;

    int a, l;
    int i;

    ptr = (u8 *)D_802497D8;
    bank = address >> 0x10;
    if (SelectedBank[which] != bank) {
        func_80201E84(which, bank);
    }

    adjusted_address = address;
    if (adjusted_address < 0) {
        adjusted_address += 0x1F;
    }
    a = adjusted_address >> 5;

    adjusted_len = len;
    if (adjusted_len < 0) {
        adjusted_len += 0x1F;
    }
    l = adjusted_len >> 5;

    for (i = 0; i < l; i++) {
        read_chunk(i + a, which);
        memcpy(dst + i * 0x20, ptr + 9, 0x20);
    }
}

INCLUDE_ASM("asm/shell/nonmatchings/540", func_8020237C);

void func_80202548(void *src, int address, int len, int which) { // write_cpak
    int bank;
    int adjusted_address;
    int adjusted_len;
    u8 *ptr;

    int a, l;
    int i;

    ptr = (u8 *)D_802497D8;
    bank = address >> 0x10;
    if (bank != SelectedBank[which]) {
        func_80201E84(which, bank);
    }

    adjusted_address = address;
    if (adjusted_address < 0) {
        adjusted_address += 0x1F;
    }
    a = adjusted_address >> 5;

    adjusted_len = len;
    if (adjusted_len < 0) {
        adjusted_len += 0x1F;
    }
    l = adjusted_len >> 5;

    for (i = 0; i < l; i++) {
        memcpy(ptr + 9, src + i * 0x20, 0x20);
        write_chunk(a + i, which);
        func_80222AAC(i * (0x92 / l));
    }
    func_80222AAC(0x92);
}

void func_802026E4(void *addr) { // write_pifram
    volatile SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);

    func_80202B88();

    si->DRAM_addr = (void *)K0_TO_PHYS(addr);
    si->PIF_addr_write = (void *)0x1FC007C0;
}

INCLUDE_ASM("asm/shell/nonmatchings/540", func_80202728);

void read_chunk(int address, int which) {
    while (TRUE) {
        u8 *buf = (u8 *)D_802497D8;
        int page_addr;
        int block_addr;

        int i;

        buf[0x00] = 0xFF;
        buf[0x01] = 0xFF;
        buf[0x02] = 0xFF;
        buf[0x03] = 0xFF;

        if (which > 1) {
            buf[0x00] = 0;
        }
        if (which > 2) {
            buf[0x01] = 0;
        }
        if (which > 3) {
            buf[0x02] = 0;
        }
        if (which > 4) {
            buf[0x03] = 0;
        }

        buf[0x04] = 3;
        buf[0x05] = 0x21;
        buf[0x06] = 2;

        page_addr = address << 5;
        block_addr = address >> 3;

        buf[0x07] = block_addr;
        buf[0x08] = page_addr;
        buf[0x08] |= calc_address_crc(address);

        buf[0x2A] = 0xFE;

        buf[0x3F] = 1;

        for (i = 0; i < 0x10; i++) {
            func_80218C18(&D_802497D8[i]);
        }

        func_802026E4(D_802497D8);

        for (i = 0; i < 330000; i++) {
            continue;
        }

        func_80202BAC(D_802497D8);

        for (i = 0; i < 330000; i++) {
            continue;
        }

        if (calc_data_crc(buf + 9) == buf[0x29]) {
            break;
        }
    }
}

void write_chunk(int address, int which) {
    while (TRUE) {
        u8 *buf = (u8 *)D_802497D8;
        int page_addr;
        int block_addr;

        int i;

        buf[0x00] = 0xFF;
        buf[0x01] = 0xFF;
        buf[0x02] = 0xFF;
        buf[0x03] = 0xFF;

        if (which > 1) {
            buf[0x00] = 0;
        }
        if (which > 2) {
            buf[0x01] = 0;
        }
        if (which > 3) {
            buf[0x02] = 0;
        }
        if (which > 4) {
            buf[0x03] = 0;
        }

        buf[0x04] = 0x23;
        buf[0x05] = 1;
        buf[0x06] = 3;

        page_addr = address << 5;
        block_addr = address >> 3;

        buf[0x07] = block_addr;
        buf[0x08] = page_addr;
        buf[0x08] |= calc_address_crc(address);

        buf[0x2A] = 0xFE;
        buf[0x2B] = 0xFE;
        buf[0x2C] = 0xFE;
        buf[0x2D] = 0xFE;

        buf[0x3F] = 1;

        for (i = 0; i < 0x10; i++) {
            func_80218C18(&D_802497D8[i]);
        }

        func_802026E4(D_802497D8);

        for (i = 0; i < 330000; i++) {
            continue;
        }

        func_80202BAC(D_802497D8);

        for (i = 0; i < 330000; i++) {
            continue;
        }

        if (calc_data_crc(buf + 9) == buf[0x29]) {
            break;
        }
    }
}

void func_80202B88(void) { // wait_si
    // BUG: should be volatile
    SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);

    while ((si->status & 3) != 0) {
        continue;
    }
}

void func_80202BAC(void *addr) { // read_pifram
    volatile SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);

    func_80202B88();
    
    si->DRAM_addr = (void *)K0_TO_PHYS(addr);
    si->PIF_addr_read = (void *)0x1FC007C0;
}

int calc_address_crc(u32 data) {
    s32 result;
    s32 mask;
    s32 inv;
    s32 bit;

    result = 0;

    for (mask = 0x400; mask != 0; mask >>= 1) {
        inv = result & 0x10;

        bit = inv ? 1 : 0;
        if (data & mask) {
            bit ^= 1;
        }

        result <<= 1;
        if (bit == 1) {
            result ^= 0x15;
        }
    }
    return result & 0x1F;
}

int calc_data_crc(u8 *data) {
    u8 result;
    int mask;
    int inv;
    int bit;

    int i;

    result = 0;
    for (i = 0; i < 0x20; i++) {
        for (mask = 0x80; mask != 0; mask >>= 1) {
            inv = result & 0x80;

            bit = inv ? 1 : 0;
            if (data[i] & mask) {
                bit ^= 1;
            }

            result <<= 1;
            if (bit == 1) {
                result ^= 0x85;
            }
        }
    }
    return result;
}

u8 controller_status(void) {
    int i;
    u8 *buf;

    func_80201D44();
    buf = (u8 *)D_802497D8;

    buf[0x00] = 0xFF;
    buf[0x01] = 1;
    buf[0x02] = 3;
    buf[0x03] = 0xFF;

    buf[0x07] = 0xFF;
    buf[0x08] = 1;
    buf[0x09] = 3;
    buf[0x0A] = 0xFF;

    buf[0x0E] = 0xFF;
    buf[0x0F] = 1;
    buf[0x10] = 3;
    buf[0x11] = 0xFF;

    buf[0x15] = 0xFF;
    buf[0x16] = 1;
    buf[0x17] = 3;
    buf[0x18] = 0xFF;

    buf[0x1C] = 0xFF;
    buf[0x1D] = 1;
    buf[0x1E] = 3;
    buf[0x1F] = 0xFF;

    buf[0x23] = 0xFE;
    buf[0x24] = 0xFE;

    buf[0x3F] = 1;

    for (i = 0; i < 0x10; i++) {
        func_80218C18(&D_802497D8[i]);
    }

    func_802026E4(D_802497D8);

    for (i = 0; i < 330000; i++) {
        continue;
    }

    func_80202BAC(D_802497D8);

    for (i = 0; i < 330000; i++) {
        continue;
    }

    return buf[0x06];
}

int func_80202DB0(u8 *arg0, int which) {
    int ret = func_802014F4(which);
    if (ret > 0) {
        s16 *temp_v0 = func_8020237C(which);
        if (temp_v0 != NULL) {
            int i = 0;
            u8 *ptr = arg0;
            int count = temp_v0[4];
            while (count != 0) {
                func_8020222C(ptr, D_802406D8[i++] * 0x100, 0x100, which);
                count--;
                ptr += 0x100;
            }
        } else {
            ret = 0;
        }
    } else {
        ret = -1;
        func_80217BC4("error in format\n");
    }

    return ret;
}

INCLUDE_ASM("asm/shell/nonmatchings/540", func_80202E70);

void func_80203044(u8 *dst, u8 *src, int len) {
    while (--len != -1) {
        *(dst++) = *(src++);
    }
}

void func_80203070(u8 *dst, int len) {
    while (--len != -1) {
        *(dst++) = 0;
    }
}
