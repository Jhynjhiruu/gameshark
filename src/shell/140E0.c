#include "common.h"
#include "include_asm.h"

#include "1FB00.h"

extern u64 D_80249868;

int func_802144E0(void) {
    return 0x41;
}

void func_802144E8(void) {}

void func_802144F0(void) {}

INCLUDE_ASM("asm/shell/nonmatchings/140E0", func_802144F8);

void func_80214704(void) {}

void func_8021470C(void) {}

void func_80214714(void) {}

INCLUDE_ASM("asm/shell/nonmatchings/140E0", func_8021471C);

void func_802147B4(void) {}

void func_802147BC(void) {}

void func_802147C4(void) {}

void func_802147CC(int arg0, int arg1, int arg2, int arg3) {
    func_80220370(arg0, arg1, arg2, arg3);
}

void func_802147E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 r, u8 g, u8 b) {
    u64 temp_v1 = ((r >> 3) << 11) | ((g >> 3) << 6) | ((b >> 3) << 1);
    D_80249868 = temp_v1 | (temp_v1 << 0x10) | (temp_v1 << 0x20) | (temp_v1 << 0x30);
    func_8021FF00(arg0 - 0x40, arg1, arg2, arg3);
}

void func_80214880(void) {}

void func_80214888(void) {}

void func_80214890(void) {}
