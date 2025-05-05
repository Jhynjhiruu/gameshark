#include "common.h"
#include "include_asm.h"
#include "regs.h"

s32 D_80799D10 = 0;

s32 D_80799D14[] = {
    0, 0, 0, 1, 2, 0, 0, 0, 0,
};

typedef struct {
    /* 0x0 */ s32 unk0; /* inferred */
    /* 0x4 */ s32 unk4; /* inferred */
    /* 0x8 */ s32 unk8; /* inferred */
} unk_struct;           /* size = 0xC */

unk_struct D_80799D38[] = {
    {0x000000C8, 0x000000C8, 0x0000005A}, {0x00000082, 0x00000082, 0x000000A0},
    {0x00000032, 0x00000032, 0x00000046}, {0x000000FF, 0x000000FF, 0x000000FF},
    {0x00000000, 0x00000000, 0x0000000A}, {0x00000000, 0x00000000, 0x00000000},
    {0x00000014, 0x00000014, 0x00000050}, {0x000000C8, 0x000000C8, 0x0000000A},
    {0x00000082, 0x00000082, 0x0000000A}, {0x00000032, 0x00000032, 0x0000000A},
    {0x0000000A, 0x0000000A, 0x00000082}, {0x00000000, 0x00000050, 0x00000000},
    {0x00000023, 0x00000023, 0x000000C8}, {0x0000008C, 0x00000014, 0x00000014},
    {0x000000C8, 0x00000028, 0x00000028}, {0x0000000A, 0x0000008C, 0x0000000A},
};

s32 D_80799DF8 = 0;

s32 D_80799DFC = 0;

s32 D_80799E00[] = {
    0,
    0,
    0,
    33,
};

extern s32 D_8079B254;
extern u8 D_8079B258[];

void func_80788050(void) {
    volatile PI_regs_t *pi = (void *)PHYS_TO_K1(0x04600000);

    while (pi->status & 3) {
        continue;
    }
}

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078806C);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078810C);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078D828);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078ED30);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078EDD0);

void func_8078EE80(u8 *arg0) {
    func_8078554C(arg0);
}

void func_8078EE9C(void) {
    // BUG: this is an array, not a pointer
    if (D_8079B258 != NULL) {
        func_80785D7C(D_8079B258);
    }
    if (D_80799DF8 != NULL) {
        func_80785D7C(D_80799DF8);
    }
    if (D_80799DFC != NULL) {
        func_80785D7C(D_80799DFC);
    }
}

void func_8078EEF4(void) {}

void func_8078EEFC(void) {}

void func_8078EF04(void) {}

void func_8078EF0C(void) {}

void func_8078EF14(void) {}

void func_8078EF1C(void) {
    func_8078796C(D_80799DF8, "menuf.tg~");
    func_80785ACC(D_80799DF8, 0x30, 0x41, 0);
    func_80785B10(D_80799DF8, 0x30, 0x41, 0x2A);
}

void func_8078EF74(void) {
    func_8078EF1C();
}

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078EF90);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078F11C);

void func_8078F564(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_807935B0(arg0 + (D_8079B254 / 2), arg1, arg2, arg3,
                  D_80799D38[arg4].unk0, D_80799D38[arg4].unk4,
                  D_80799D38[arg4].unk8);
}

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078F5C8);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078F904);

void *func_8078F990(u8 *ptr) {
    while (*ptr != 0) {
        ptr++;
    }
    return ptr + 1;
}

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078F9B4);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078FA30);

INCLUDE_ASM("asm/trainer/nonmatchings/7850", func_8078FBC4);

void func_80790088(void) {}

void func_80790090(void) {}

void func_80790098(void) {}

int func_807900A0(u8 *ptr) {
    int i;

    for (i = 0; *(ptr++) != 0; i++) {
        continue;
    }

    return i;
}

void func_807900C0(s32 arg0, s32 arg1, ...) {
    return;
}

s32 func_807900D4(void) {
    return 0;
}