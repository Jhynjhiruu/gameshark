#include "common.h"
#include "include_asm.h"

#include "scousers.h"

#include "178C0.h"

u32 func_802078E0(void) {
    u32 cartStart;

    D_802283C0 = 0x600000;
    func_80217D40(0xB2000000);
    cartStart = READ32(PHYS_TO_K1(0x12C00000));
    func_80217D40(0xBE000000);
    D_802283C0 = 0x400000;
    return cartStart == 0x80371240;
}

INCLUDE_ASM("asm/shell/nonmatchings/scousers", func_80207940);

int func_80207A3C(u32 *header, u32 crc1, u32 crc2) {
    if ((header[4] == crc1) && (header[5] == crc2)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/shell/nonmatchings/scousers", func_80207A60);
