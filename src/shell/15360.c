#include "common.h"

typedef struct chunk_s {
    char name[4];
    struct chunk_s *next;
    struct chunk_s *prev;
    int size;
} chunk_t;

extern void* D_8023F650;

void func_80215760(u8* dst, u8* src, int len) {
    while (len != 0) {
        *(dst++) = *(src++);
        len--;
    }
}

int func_80215788(u8* src1, u8* src2, int len) {
    int i;

    for (i = 0; i < len; i++) {
        if (src1[i] != src2[i]) {
            return -1;
        }
    }
    
    return 0;
}

void* func_802157C8(void* dst, int c, int len) {
    int i;
    u8* ptr = dst;

    for (i = 0; i < len; i++) {
        *(ptr++) = c;
    }
    return dst;
}

static inline chunk_t *getFirst(void) {
    return D_8023F650;
}

chunk_t * func_802157F0(chunk_t* chunk) {
    return chunk->next;
}

chunk_t * func_802157FC(chunk_t* chunk) {
    return chunk->prev;
}

void func_80215808(void* start, void* end) {
    chunk_t* first;
    chunk_t* last;
    chunk_t* prev;
    int size;

    ALIGN0(start, 0x10);
    ALIGN0(end, 0x10);
    
    ALIGN1(start, 0x10);
    ALIGN1(end, 0x10);
    
    D_8023F650 = start;

    first = start;
    last = end;
    prev = end - sizeof(chunk_t);

    size = end - start - 2 * sizeof(chunk_t);
    
    first->name[0] = 'D';
    first->name[1] = 'M';
    first->name[2] = 'F';
    first->next = prev;
    first->prev = NULL;
    first->size = size;
    
    prev->name[0] = 'D';
    prev->name[1] = 'M';
    prev->name[2] = 'T';
    prev->next = NULL;
    prev->prev = first;
    prev->size = 0;
}

void* func_80215874(int size) {
    chunk_t* cur = D_8023F650;
    chunk_t * next;
    
    ALIGN(size, 0x10);
    if (size == 0) {
        return NULL;
    }
    
    while (1) {
        if (cur->name[2] == 'T') {
            return NULL;
        }
        if ((cur->name[2] == 'F') && (size < cur->size)) {
            break;
        }
        cur = cur->next;
    }
    
    next = (void*)((u32)cur + size + sizeof(chunk_t));
    
    next->name[0] = 'D';
    next->name[1] = 'M';
    next->name[2] = 'F';
    next->prev = cur;
    next->next = cur->next;
    next->size = cur->size - size - sizeof(chunk_t);
    
    cur->name[2] = 'R';
    cur->size = size;
    cur->next = next;
    
    return (void*)((u32)cur + sizeof(chunk_t));
}

int func_8021591C(void* addr) {
    chunk_t* prev;
    chunk_t* cur;

    if (addr == NULL) {
        return -1;
    }
    
    cur = addr - sizeof(chunk_t);
    
    if (cur->name[0] != 'D') {
        return -1;
    }
    
    if (cur->name[1] != 'M') {
        return -1;
    } 
    
    if (cur->name[2] != 'R') {
        return -1;
    }
    
    cur->name[2] = 'F';
    while(cur->name[2] == 'F') {
        prev = cur;
        cur = cur->prev;
        if (cur == NULL) {
            break;
        }
    }
    
    cur = prev;
    while (cur->name[2] == 'F') {
        cur->name[2] = '~';
        cur = cur->next;
    }

    prev->size = (u32)cur - (u32)prev - sizeof(chunk_t);
    prev->next = cur;
    prev->name[2] = 'F';
    cur->prev = prev;
    
    return 1;
}
