#include "common.h"

#include "73E0.h"

#include "7200.h"
#include "hw.h"
#include "led.h"

char D_80799CF0 = 'a';
int D_80799CF4 = 0;

void func_80787BE0(void) {
    func_80787C64(0x200);
    func_80787C24(0);
    func_80780CD0(0);
}

void func_80787C0C(void) {
    int i;

    for (i = 0; i < 0xC0; i++) {
        continue;
    }
}

void func_80787C24(u8 byte) {
    u32 data = (byte << 0x18) | (byte << 0x10) | (byte << 8) | byte;
    WRITE32(PHYS_TO_K1(0x1E5FFFFC), data);
    func_80787C0C();
}

void func_80787C64(s16 data) {
    func_80787FBC(0x600, data);
}

u32 func_80787C88(void) {
    return func_80787F80(0);
}

int func_80787CA4(int tx) {
    int rx;
    u32 status = func_80787AE8();
    func_80787AF4(status & ~1);

    while (!(func_80787C88() & 0x10)) {
        continue;
    }
    while (!(func_80787C88() & 0x10)) {
        continue;
    }

    rx = func_80787C88() & 0xF;

    func_80787C24((tx & 0xF) | 0x10);

    while (func_80787C88() & 0x10) {
        continue;
    }
    while (func_80787C88() & 0x10) {
        continue;
    }

    func_80787C24(0);

    func_80787AF4(status);

    return rx;
}

int func_80787D5C(int byte) {
    return (func_80787CA4(byte >> 4) << 4) | func_80787CA4(byte);
}

int func_80787D98(int halfword) {
    return (func_80787D5C(halfword >> 8) << 8) | func_80787D5C(halfword);
}

int func_80787DD4(int word) {
    return (func_80787D98(word >> 16) << 16) | func_80787D98(word);
}
void func_80787E10(void) {
    int matched = FALSE;
    while (matched == 0) {
        if ((func_80787CA4(0) == 0xF) && (func_80787CA4(0xF) == 0) &&
            (func_80787CA4(0xA) == 0xE) && (func_80787CA4(0xE) == 0xA)) {
            matched = TRUE;
        }
    }
}

void func_80787E9C(char *str) {
    for (; *str != 0; str++) {
        func_80787D5C(*str);
    }
}

int func_80787EE0(void) {
    D_80799CF4++;

    if (D_80799CF4 == 51) {
        D_80799CF4 = 0;

        func_80780CD0(D_80799CF0);
        D_80799CF0++;

        if (D_80799CF0 == 'd') {
            D_80799CF0 = 'g';
        }

        if (D_80799CF0 == 'h') {
            D_80799CF0 = 'a';
        }
    }

    if (func_80787C88() & 0x10) {
        return func_80787C88() & 0xF;
    } else {
        return 0;
    }
}
