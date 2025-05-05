#include "common.h"

#include "17A50.h"

#include "17810.h"
#include "178C0.h"
#include "17990.h"
#include "17F00.h"
#include "6380.h"
#include "18410.h"

// not really sure where this variable should live!
extern s32 D_80225884;

extern s32 D_80243314;

void func_80217E50(u32 addr, u32 data) {
    int segment;
    int *ptr;

    segment = D_802283C4 | 0xE00000;
    ptr = (int *)(segment | ((addr & 1) << 0x14) | ((addr & 0x1FFFE) << 1));

    func_80217D90();

    *ptr = data << 0x10;

    func_80217D90();
}

int func_80217EB8(u32 addr) {
    int val;

    val = D_802283C4 | 0xE00000;
    val |= ((addr & 1) << 0x14);
    val |= ((addr & 0x1FFFE) << 1);

    func_80217D90();

    val = *(int *)val;

    if ((addr & 1) == 0) {
        val = val >> 0x10;
    }

    val &= 0xFFFF;

    func_80217D90();

    return val;
}

void func_80217F28(void) {
    u32 prev;
    int i;

    for (i = 0; i < 1000; i++) {
        continue;
    }

    prev = func_80217EB8(0);

    while ((prev & 0x4040) != (func_80217EB8(0) & 0x4040)) {
        prev = func_80217EB8(0);
    }
}

void func_80217F74(int addr, u8* src, int len) {
    u32 mask;
    char led_char = 'a';
    u8 * ptr = src;
    int i;
    
    mask = func_80218C4C();
    func_80218C5C(mask & ~1);
    
    ALIGN(len, 0x100);
    
    len = len >> 8;
    addr = addr >> 1;

    func_80217F28();
    for (; len != 0; len--) {
        if ((len & 0x3F) == 0) {
            func_80206800(led_char);
            led_char += 2;
            if (led_char == 'g') {
                led_char = 'a';
            }
        }
        
        func_80217E50(0x5555, 0xAAAA);
        func_80217E50(0x2AAA, 0x5555);
        func_80217E50(0x5555, 0xA0A0);
        
        for (i = 0; i < 0x80; i++) {
            int hi = *(ptr++);
            int lo = *(ptr++);
            func_80217E50(addr++, (hi << 8) | lo);
        }
        func_80217F28();
    }
    func_80218C5C(mask);
}

int func_80218094(u32 addr, u8 *src, int len) {
    u32 temp = 0xC00000;

    ALIGN(len, 0x100);

    addr = addr | temp | D_802283C4;
    for (; len != 0; len--) {
        if (func_80217C10(addr++) != *(src++)) {
            return -1;
        }
    }
    return 0;
}

void func_80218118(u32 addr, u8 *dst, int len) {
    u32 temp = 0xC00000;

    ALIGN(len, 0x100);

    addr = addr | temp | D_802283C4;
    for (; len != 0; len--) {
        *(dst++) = func_80217C10(addr++);
    }
    func_80218BBC();
}

void func_80218190(void) {
    func_80217F28();
    func_80217E50(0x5555, 0xAAAA);
    func_80217E50(0x2AAA, 0x5555);
    func_80217E50(0x5555, 0x8080);
    func_80217E50(0x5555, 0xAAAA);
    func_80217E50(0x2AAA, 0x5555);
    func_80217E50(0x5555, 0x1010);
    func_80217F28();
}

void func_802181FC(u32 arg0, u8 *arg1, s32 arg2) {
    func_80218118(arg0, arg1, arg2);
}

void func_80218218(int arg0, u16 *arg1, u32 arg2) {
    D_80243314 = 0;
    func_80218430();
    if (D_802283D2 != 4) {
        func_80217F74(arg0, arg1, arg2);
        return;
    }
    D_80243314 = func_80218640(arg1, arg2, arg0);
}

int func_802182A0(u32 arg0, u8 *arg1, s32 arg2) {
    func_80218094(arg0, arg1, arg2);
}

void func_802182BC(void) {
    func_80218430();
    if (D_802283D2 == 4) {
        D_80225884 = 0x40000;
    }
}
