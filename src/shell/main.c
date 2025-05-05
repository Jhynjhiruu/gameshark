#include "common.h"

#include "main.h"

#include "109A0.h"
#include "114D0.h"
#include "144A0.h"
#include "15360.h"
#include "17280.h"
#include "178C0.h"
#include "17A50.h"
#include "18410.h"
#include "6380.h"
#include "C9A0.h"
#include "DF40.h"
#include "FED0.h"
#include "ai.h"
#include "scousers.h"

extern u32 D_802432F0;

extern void *D_80245428;

extern u32 D_80249648;
extern u32 D_802497B0;
extern volatile int D_802497C0;
extern u32 D_802497D0;
extern u32 D_802497D4;

extern u64 D_80249868;
extern u32 *D_80249870;

extern void *D_8024A000;

extern u64 D_8024A190;
extern void *D_8024A19C;
extern void *D_8024A1A0;

extern void *D_8024ADA8;

extern u32 D_8024B7C0[100];

int D_80225880 = 0;
int D_80225884 = 0x00010000;

void func_80200400(void) {
    D_80249648 = func_80218C4C();
    func_80218C5C(D_80249648 & ~1);
    func_80217D40(0xBE000000);
    D_80249870 = (void *)0x80000318;
    D_802497B0 = 1;
    D_802497D0 = 0;
    D_802497C0 = *D_80249870;
    func_802182BC();
    func_802006FC();
    func_80206800(0);
    func_80200490(func_8021217C());
}

void func_80200490(int arg0) {
    char c;

    WRITE32(PHYS_TO_K1(0x04400000), 0);
    WRITE32(PHYS_TO_K1(0x80000200), D_802497D4);
    func_802076F0();
    c = 0;
    if (arg0 != 0) {
        c = '.';
    }
    func_80206800(c);
    if ((D_80228284 == 0) && (arg0 != 0)) {
        WRITE32(PHYS_TO_K1(0x80000200), D_8022826C);
    }
    if (D_802497B0 == 1) {
        WRITE32(PHYS_TO_K1(0x80000318), D_802497C0);
    }
    func_80218BBC();
    if ((D_802497C0 >= 0x800000) && (D_80227BF0 == 1)) {
        func_80218C2C(0x80780800);
    } else if (arg0 != 0) {
        if ((D_802497C0 == 0x800000) && (D_80228284 == 1)) {
            WRITE32(PHYS_TO_K1(0x80000200), PHYS_TO_K1(0x807C5C00));
        }
        if (D_802497D0 == 1) {
            func_802188C0();
        } else {
            func_80218810();
        }
    }
    func_80218BBC();
    func_802005E4();
}

void func_802005E4(void) {
    int i;

    u32 *dst;
    u32 *src;
    u32 loadaddr;
    u32 *func;

    u32 readaddr = PHYS_TO_K1(0x10000008);

    loadaddr = READ32(readaddr);
    if (D_80228260 != 0) {
        loadaddr = D_80228264;
    }

    if (loadaddr > 0x80100000U) {
        loadaddr = 0x80000400;
    } else {
        loadaddr = loadaddr + 0x100000;
    }

    func = (u32 *)loadaddr;

    src = (u32 *)func_80218A8C;
    dst = func;
    for (i = 0; i < 0x40; i++) {
        dst[i] = src[i];
    }

    func_80218BBC();

    readaddr = PHYS_TO_K1(0x10000008);
    loadaddr = READ32(readaddr);
    if (D_80228260 != 0) {
        loadaddr = D_80228264;
    }

    readaddr = PHYS_TO_K1(0x10001000);

    func_80218BBC();

    src = D_8024B7C0;
    dst = func + 0x400;
    for (i = 0; i < 100; i++) {
        dst[i] = src[i];
    }

    func_80218BBC();

    ((void (*)(u32, u32, u32 *))func)(loadaddr, readaddr, dst);
}

void func_802006FC(void) {
    WRITE32(PHYS_TO_K1(0x80000318), 0x400000);

    func_80217680();
    func_80206800(0x30);
    func_802154E0(0);
    func_80207A60();
    func_80215808((void *)0x80080000, (void *)0x80180000);
    D_8024A000 = func_80215874(0x2C);
    D_8024A19C = func_80215874(0x2C);
    D_8024A1A0 = func_80215874(0x2C);
    D_8024ADA8 = func_80215874(0x2C);
    D_802432F0 = func_80215874(0x10000);
    D_80245428 = func_80215874(0x8000);
    func_802061D0(0);
    func_802159D0();
    D_80249868 = 0;
    D_8024A190 = 0xF7BCF7BCF7BCF7BC;
    func_80218BBC();
    func_80212CDC();
    D_80228278 = 0;
    func_8020E340();
    D_80228278 = func_8020E5C8();
    func_802109C8();
    func_8020EDCC();
    func_802069E8();
}
