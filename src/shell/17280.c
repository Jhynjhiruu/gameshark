#include "common.h"

#include "17280.h"

#include "178C0.h"
#include "18410.h"
#include "5E30.h"
#include "6380.h"

void func_80217680(void) {
    func_80217724(0x200);
    func_802176C4(0);
    func_80206800(0);
}

void func_802176AC(void) {
    int i;

    for (i = 0; i < 0xC0; i++) {
        continue;
    }
}

void func_802176C4(u8 byte) {
    u32 data = (func_80206238() & 0xE0E0E0E0) |
               ((byte << 0x18) | (byte << 0x10) | (byte << 0x08) | byte);
    WRITE32(PHYS_TO_K1(0x1E5FFFFC), data);
    func_802176AC();
}

void func_80217724(s16 data) {
    func_80217CFC(0x600, data);
}

u32 func_80217748(void) {
    return func_80217CC0(0);
}

int func_80217764(int data) {
    int rv;

    u32 mask = func_80218C4C();
    func_80218C5C(mask & ~1);

    while (!(func_80217748() & 0x10)) {
        continue;
    }

    while (!(func_80217748() & 0x10)) {
        continue;
    }

    rv = func_80217748() & 0xF;
    func_802176C4((data & 0xF) | 0x10);

    while (func_80217748() & 0x10) {
        continue;
    }

    while (func_80217748() & 0x10) {
        continue;
    }

    func_802176C4(0);
    func_80218C5C(mask);

    return rv;
}

int func_8021781C(int byte) {
    return (func_80217764(byte >> 4) << 4) | func_80217764(byte);
}

int func_80217858(int half) {
    return (func_8021781C(half >> 8) << 8) | func_8021781C(half);
}

int func_80217894(int word) {
    return (func_80217858(word >> 0x10) << 0x10) | func_80217858(word);
}

void func_802178D0(void) {
    int done = FALSE;

    while (done == FALSE) {
        if (func_80217764(0) != 0xF) {
            continue;
        }

        if (func_80217764(0xF) != 0) {
            continue;
        }

        if (func_80217764(0xA) != 0xE) {
            continue;
        }

        if ((func_80217764(0xE) != 0xA)) {
            continue;
        }

        done = TRUE;
    }
}

void func_8021795C(char *str) {
    for (; *str != 0; str++) {
        func_8021781C(*str);
    }
}

int func_802179A0(void) {
    static char led_val = 'a';
    static int count = 0;

    count++;
    if (count == 11) {
        count = 0;

        led_val++;
        if (led_val == 'd') {
            led_val = 'g';
        }

        if (led_val == 'h') {
            led_val = 'a';
        }
    }

    if (func_80217748() & 0x10) {
        return func_80217748() & 0xF;
    } else {
        return 0;
    }
}
