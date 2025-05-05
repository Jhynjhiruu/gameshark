#include "common.h"
#include "include_asm.h"

#include "14280.h"
#include "7200.h"
#include "7850.h"
#include "F8E0.h"
#include "hw.h"
#include "libc.h"

extern s32 D_8079B1D0;

void func_80780800(void) {
    u8 *ptr;
    int i;

    func_80788000(0xBE000000);

    WRITE32(PHYS_TO_K1(0x80000318), 0x400000);

    func_80787A58();

    D_80799E10 = (void *)PHYS_TO_K1(0x807E9C00);
    D_80799DF8 = PHYS_TO_K1(0x807C9C00);

    ptr = (void *)PHYS_TO_K1(0x807E9C00);
    // BUG: surely this must come from a hardcoded constant that wasn't updated?
    for (i = 0; i < sizeof(unk) + 4; i++) {
        ptr[i] = 0;
    }

    func_80785C30(PHYS_TO_K1(0x80600000), PHYS_TO_K1(0x80700000));
    func_8078EF74();

    D_8079B1D0 = 0;

    WRITE32(PHYS_TO_K1(0x8078040C), &D_80799E10->unk160);

    func_80790B74();

    D_80799E10->unk0 = (cheat *)((u32)D_80799E10 + sizeof(unk));

    D_80799E10->unkC8 = (u32)D_80799E10->unk0 + 0x148;
    D_80799E10->unkCC = D_80799E10->unk0;
    D_80799E10->unkD0 = D_80799E10->unkC8 + 0x194;
    D_80799E10->unkD4 = D_80799E10->unkD0 + 0xA4;

    func_80794A80();
}
