#include "common.h"

extern u32 D_802283C0;

u32 func_802078E0(void) {
    u32 cartStart;

    D_802283C0 = 0x600000;
    func_80217D40(PHYS_TO_K1(0x12000000));
    cartStart = READ32(PHYS_TO_K1(0x12C00000));
    func_80217D40(PHYS_TO_K1(0x1E000000));
    D_802283C0 = 0x400000;
    return cartStart == 0xDEADBEEF;
}

INCLUDE_ASM(const s32, "scousers", func_80207940);

s32 func_80207A3C(s32* arg0, s32 arg1, s32 arg2) {
    if ((arg0[4] == arg1) && (arg0[5] == arg2)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM(const s32, "scousers", func_80207A60);

#ifndef NON_MATCHING
asm(".word 0x10433A5C");
#endif
