#include "common.h"

#include "590.h"

#include "hw.h"

u32 D_80795950 = 0;
int D_80795954 = 1;
int D_80795958 = 1;
int D_8079595C = 0;

void func_80780D90(void) {
    return;
}

s32 func_80780D98(void) {
    return D_80795950;
}

void func_80780DA8(u32 arg0) {
    D_80795950 = arg0;
    WRITE32(PHYS_TO_K1(0x1E5FFFFC), arg0);
}

void func_80780DC0(int count) {
    int i;
    int j;

    for (i = count; i != 0; i--) {
        for (j = 0; j < 0x10000; j++) {
            continue;
        }
    }
}

void func_80780DF0(void) {
    int data = func_80780D98() & 0x7F7F7F7F;
    func_80780DA8(data);
    func_80780DC0(1);
    func_80780DA8(data | 0x80808080);
    func_80780DC0(100);
}

void func_80780E44(int value) {
    int data = func_80780D98() & 0xBFBFDFBF;

    if (value != 0) {
        data |= 0x40402040;
    }

    func_80780DA8(data);
}

void func_80780E8C(int value) {
    int data = func_80780D98() & 0xDFDFBFDF;

    if (value != 0) {
        data |= 0x20204020;
    }

    func_80780DA8(data);
}

u32 func_80780ED4(void) {
    return func_80787F80(0);
}

void func_80780EF0(int value) {
    int data = 0;

    if (value != 0) {
        data = 0x00400040;
    }

    while ((func_80780ED4() & 0x00400040) != data) {
        continue;
    }
}

void func_80780F40(int data) {
    int i;

    for (i = 0; i < 8; i++) {
        func_80780E44(1);

        func_80780E8C(data & 0x80);
        data <<= 1;

        func_80780EF0(1);

        func_80780E44(0);

        func_80780EF0(0);
    }
}

int func_80780FA8(void) {
    int i;
    int rv = 0;

    for (i = 0; i < 8; i++) {
        rv <<= 1;
        rv &= 0xFF;

        func_80780EF0(1);
        func_80780E44(1);
        func_80780EF0(0);

        if (func_80780ED4() & 0x00200020) {
            rv |= 1;
        }

        func_80780E44(0);
    }
    return rv;
}

s32 func_80781034(void) {
    s32 temp_a0;
    s32 temp_s3;
    s32 var_s0;
    s32 i;

    func_80780DF0();
    var_s0 = 0xAE;
    temp_s3 = func_80780ED4() & 0x00200020;
    for (i = 0; i < 0x10000000; i++) {
        func_80780E44(1);
        temp_a0 = var_s0 & 0x80;
        var_s0 <<= 1;
        if (temp_a0 != 0) {
            var_s0 |= 1;
        }
        var_s0 = var_s0 & 0xFF;
        func_80780E8C(temp_a0);
        func_80780DC0(1);
        func_80780E44(0);
        func_80780DC0(1);
        if ((func_80780ED4() & 0x00200020) != temp_s3) {
            break;
        }
    }
    return i < 0x10000000;
}

int func_80781104(u8 *buf, int len) {
    int crc;
    int cur;
    int tmp;

    int i;
    int j;

    crc = 0xFFFF;
    for (i = 0; i < len; i += 2) {
        cur = (buf[i] << 8) | buf[i + 1];
        for (j = 0; j < 16; j++) {
            tmp = crc & 0x8000;
            crc <<= 1;
            if (cur & 0x8000) {
                crc |= 1;
            }
            cur <<= 1;

            if (tmp) {
                crc ^= 0x8005;
            }

            crc &= 0xFFFF;
        }
    }
    return crc;
}

u32 func_8078116C(u32 arg0) {
    u8 sp10[8];
    u32 var_s0;
    int i;
    u32 temp_v0;

    sp10[0] = D_80795954;
    sp10[1] = D_80795958;
    sp10[2] = arg0 >> 0x18;
    sp10[3] = arg0 >> 0x10;
    sp10[4] = arg0 >> 8;
    sp10[5] = arg0;
    temp_v0 = func_80781104(sp10, 6);
    sp10[6] = temp_v0 >> 8;
    sp10[7] = temp_v0;
    for (i = 0; i < 8; i++) {
        func_80780F40(sp10[i]);
    }
    func_80780DC0(0xA);
    var_s0 = 0;
    for (i = 0; i < 4; i++) {
        var_s0 <<= 8;
        var_s0 |= func_80780FA8();
    }
    return var_s0;
}

void func_80781230(void) {
    if ((D_8079595C == 0) && (func_80781034() == 0)) {
        while (1) {
            continue;
        }
    }
    D_8079595C = 1;
}

int func_80781274(void) {
    D_80795954 = 2;
    D_80795958 = 2;

    if (func_8078116C(0x6962A1B4) == 0x04554321) {
        D_80795954 = 1;
        D_80795958 = 1;
        return 0;
    }
    return 1;
}
