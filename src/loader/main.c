#include "common.h"

#include "main.h"

#include "hw.h"
#include "led.h"
#include "libc.h"
#include "lzari.h"
#include "si.h"
#include "util.h"

void func_80040180(void) {
    int i;

    for (i = 0; i < (320 * 240 * 2); i++) {
        ((int *)0x80300000)[i] = 0;
    }

    func_80042488();
    func_80042100((void *)0x80180000, (void *)0x80200000);
    func_800402D8();
    func_80042584('5');

    for (i = 0; i < 60; i++) {
        func_800424C0();
    }

    func_80042584('4');

    for (i = 0; i < 60; i++) {
        func_800424C0();
    }

    func_80042584('3');
    func_80041FCC(0x80200400, "shell.bin");
    func_80042584('2');
    func_80041FCC(0x80780800, "trainer.bin");
    func_80042584('1');

    for (i = 0; i < 0x3c; i++) {
        func_800424C0();
    }

    func_80042330((void (*)())0x80200400);
}

u32 func_80040278(void) {
    u32 cartStart;

    D_80042AA0 = 0x600000;
    func_80040600(0xB2000000);
    cartStart = READ32(PHYS_TO_K1(0x12C00000));
    func_80040600(0xBE000000);
    D_80042AA0 = 0x400000;
    return cartStart == 0x80371240;
}

#define POS_Y 40
#define POS_X 24

#define WIDTH 320
#define HEIGHT 224

#define HSYNC 0xC15

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} RGB;

void func_800402D8(void) {
    u16 *var_s1;
    s32 var_s2;
    s32 var_t0;
    u8 r;
    u8 g;
    u8 b;
    RGB *temp_v1;
    u8 *var_s0;

    u32 *vi_regs;
    u32 addr;

    func_8004043C();
    addr = 0x80280000;
    func_80041FCC(addr, "gslogo3.pal");
    var_s0 = (u8 *)0x80281001;
    func_80041FCC(0x80281000, "gslogo3.bin");
    for (var_s2 = POS_Y, var_s1 = (u16 *)0x80306400; var_s2 < (HEIGHT - POS_Y); var_s2++, var_s1 += WIDTH) {
        func_800422C0();
        for (var_t0 = POS_X + 1; var_t0 < (WIDTH - POS_X) + 1; var_t0++) {
            temp_v1 = &((RGB *)addr)[*var_s0++];
            r = temp_v1->r;
            g = temp_v1->g;
            b = temp_v1->b;
            if ((r + g + b) > 0) {
                var_s1[var_t0] = (r << 0xB) | (g << 6) | (b << 1); // RGB5551 conversion
            }
        }
    };
    vi_regs = (u32 *)PHYS_TO_K1(0x04400000);
    vi_regs[0] = 0x10000 | 0x3000 | 0x00002; // the 0x3000 are two reserved bits
    vi_regs[1] = 0x80300000;
    vi_regs[2] = WIDTH;
    vi_regs[5] = (0x3E << 20) | (5 << 16) | (0x22 << 8) | (0x39 << 0);
    vi_regs[6] = 525;
    vi_regs[7] = HSYNC;
    vi_regs[8] = (HSYNC << 16) | (HSYNC << 0);
    vi_regs[9] = (0x6C << 16) | (0x2EC << 0);
    vi_regs[10] = (0x25 << 16) | (0x1FF << 0);
    vi_regs[11] = (0xE << 16) | (0x204 << 0);
    vi_regs[12] = 0x200;
    vi_regs[13] = 0x400;
}

void func_8004043C(void) {
    u16 *temp = (u16 *)0x80210000;
    u16 *temp2;

    s32 i;
    s32 j;

    func_80041FCC(0x80210000, "tile1.tg~");
    temp2 = temp;
    for (i = 0; i < 0x30; i++) {
        for (j = 0; j < 0x40; j++, temp2++) {
            *temp2 = ((u32)((*temp2 >> 7) | ((*temp2 & 0x7F) << 9)) >> 1) & 0x7BDE;
        }
    }

    for (i = 0; i < 0xF0; i += 0x30) {
        for (j = 0; j < 0x140; j += 0x40) {
            func_800404FC(j, i, temp);
        }
    }
}

void func_800404FC(s32 x, s32 y, u16 *data) {
    s32 var_a0;
    s32 var_a3 = 0;
    u16 *var_v1 = &((u16(*)[0x140])0x80300000)[y][x];
    for (var_a3 = 0; var_a3 < 0x30; var_a3++, var_v1 += 0x140) {
        for (var_a0 = 0; var_a0 < 0x40; var_a0++) {
            var_v1[var_a0] = *data++;
        }
    }
}
