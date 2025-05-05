#include "common.h"
#include "include_asm.h"

#include "F8E0.h"

s32 D_80795980 = 8;
s32 D_80795984 = 0;

void *func_80781440(void *ptr) {
    ptr += 4;

    if ((int)ptr >= (int)0x806DA000) {
        return 0;
    } else {
        return ptr;
    }
}

void func_80781464(void) {
    return;
}

void func_8078146C(void) {
    return;
}

void func_80781474(void) {
    return;
}

void func_8078147C(s16 **out) {
    int cmp;
    int count;
    s16 **ptr = (void *)0x80400000;
    int i;

    count = D_80799E10->unkEC;
    D_80799E10->unkBC = count;

    cmp = D_80799E10->unkF0;

    i = 0;
    for (; count != 0; count--) {
        s16 *val = *ptr;
        ptr = func_80781440(ptr);
        if (ptr == NULL) {
            return;
        }
        if (*val == (s16)cmp) {
            out[i++] = val;
            if (i == 100) {
                D_80799E10->unkBC = 0x65;
                break;
            }
        }
    }
}

int func_80781558(s16 arg0) {
    u8 *byte_ptr = (void *)0x80000000;
    s16 *short_ptr = (void *)0x80000000;
    void **dest_ptr = (void *)0x80400000;
    int count = 0;

    D_80799E10->unkE8 |= 1;

    if (D_80795980 == 8) {
        while (byte_ptr != (void *)0x80400000) {
            if (*byte_ptr == (u8)arg0) {
                *dest_ptr = byte_ptr;
                count += 1;
                dest_ptr = func_80781440(dest_ptr);
                if (dest_ptr == NULL) {
                    break;
                }
            }
            byte_ptr += 1;
        }
    } else {
        while (short_ptr != (void *)0x80400000) {
            if (*short_ptr == arg0) {
                *dest_ptr = short_ptr;
                count += 1;
                dest_ptr = func_80781440(dest_ptr);
                if (dest_ptr == NULL) {
                    break;
                }
            }
            short_ptr += 1;
        }
    }
    return count;
}

INCLUDE_ASM("asm/trainer/nonmatchings/C40", func_80781640);

void func_8078176C(void) {
    return;
}
