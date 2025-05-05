#include "common.h"

#include "hw.h"

void func_807808E0(u32 addr, u32 arg1) {
    int segment;
    int *ptr;

    segment = D_80799D04 | 0xE00000;
    ptr = (int *)(segment | ((addr & 1) << 0x14) | ((addr & 0x1FFFE) << 1));

    func_80788050();

    *ptr = arg1 << 0x10;

    func_80788050();
}

int func_80780948(u32 addr) {
    int val;

    val = D_80799D04 | 0xE00000;
    val |= ((addr & 1) << 0x14);
    val |= ((addr & 0x1FFFE) << 1);

    func_80788050();

    val = *(int *)val;

    if ((addr & 1) == 0) {
        val = val >> 0x10;
    }

    val &= 0xFFFF;

    func_80788050();

    return val;
}

void func_807809B8(void) {
    u32 prev;
    int i;

    for (i = 0; i < 1000; i++) {
        continue;
    }

    prev = func_80780948(0);

    while ((prev & 0x4040) != (func_80780948(0) & 0x4040)) {
        prev = func_80780948(0);
    }
}

void func_80780A04(int addr, u8 *src, int len) {
    u32 mask;
    char led_char = 'a';
    u8 *ptr = src;
    int i;

    mask = func_80787AE8();
    func_80787AF4(mask & ~1);

    ALIGN(len, 0x100);

    len = len >> 8;
    addr = addr >> 1;

    func_807809B8();
    for (; len != 0; len--) {
        func_807808E0(0x5555, 0xAAAA);
        func_807808E0(0x2AAA, 0x5555);
        func_807808E0(0x5555, 0xA0A0);

        for (i = 0; i < 0x80; i++) {
            int hi = *(ptr++);
            int lo = *(ptr++);
            func_807808E0(addr++, (hi << 8) | lo);
        }
        func_807809B8();
    }
    func_80787AF4(mask);
}

int func_80780AE8(u32 addr, u8 *src, int len) {
    u32 temp = 0xC00000;

    ALIGN(len, 0x100);

    addr = addr | temp | D_80799D04;
    for (; len != 0; len--) {
        if (func_8078EDD0(addr++) != *(src++)) {
            return -1;
        }
    }
    return 0;
}

void func_80780B6C(u32 addr, u8 *dst, int len) {
    u32 temp = 0xC00000;

    ALIGN(len, 0x100);

    addr = addr | temp | D_80799D04;
    for (; len != 0; len--) {
        *(dst++) = func_8078EDD0(addr++);
    }
}

void func_80780BDC(void) {
    func_807809B8();
    func_807808E0(0x5555, 0xAAAA);
    func_807808E0(0x2AAA, 0x5555);
    func_807808E0(0x5555, 0x8080);
    func_807808E0(0x5555, 0xAAAA);
    func_807808E0(0x2AAA, 0x5555);
    func_807808E0(0x5555, 0x1010);
    func_807809B8();
}
