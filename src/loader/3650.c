#include "common.h"

#include "3650.h"

#include "hw.h"
#include "led.h"

void func_80042650(void) {
    func_800426D4(0x200);
    func_80042694(0);
    func_80042584(0);
}

void func_8004267C(void) {
    int i;

    for (i = 0; i < 160; i++) {
        continue;
    }
}

void func_80042694(u8 data) {
    WRITE32(PHYS_TO_K1(0x1E5FFFFC),
            (data << 0x18) | (data << 0x10) | (data << 8) | data);
    func_8004267C();
}

void func_800426D4(s16 data) {
    func_800405BC(0x600, data);
}

u32 func_800426F8(void) {
    return func_80040580(0);
}

int func_80042714(int data) {
    int rv;

    u32 mask = func_80042350();
    func_8004235C(mask & ~1);

    while (!(func_800426F8() & 0x10)) {
        continue;
    }

    rv = func_800426F8() & 0xF;
    func_80042694((data & 0xF) | 0x10);

    while (func_800426F8() & 0x10) {
        continue;
    }

    func_80042694(0);
    func_8004235C(mask);

    return rv;
}

int func_800427A4(int byte) {
    return (func_80042714(byte >> 4) << 4) | func_80042714(byte);
}

int func_800427E0(int halfword) {
    return (func_800427A4(halfword >> 8) << 8) | func_800427A4(halfword);
}

int func_8004281C(int word) {
    return (func_800427E0(word >> 16) << 16) | func_800427E0(word);
}

void func_80042858(void) {
    int done = FALSE;

    while (done == FALSE) {
        if (func_80042714(0) != 0xF) {
            continue;
        }

        if (func_80042714(0xF) != 0) {
            continue;
        }

        if (func_80042714(0xA) != 0xE) {
            continue;
        }

        if ((func_80042714(0xE) != 0xA)) {
            continue;
        }

        done = TRUE;
    }
}

void func_800428E4(char *str) {
    for (; *str != 0; str++) {
        func_800427A4(*str);
    }
}

int func_80042928(void) {
    static char led_val = 'a';
    static int count = 0;

    count++;
    if (count == 11) {
        count = 0;

        func_80042584(led_val);

        led_val++;
        if (led_val == 'd') {
            led_val = 'g';
        }

        if (led_val == 'h') {
            led_val = 'a';
        }
    }

    if (func_800426F8() & 0x10) {
        return func_800426F8() & 0xF;
    } else {
        return 0;
    }
}
