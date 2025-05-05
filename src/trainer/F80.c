#include "common.h"
#include "include_asm.h"

#include "F8E0.h"

void func_80781780(void) {
    return;
}

void func_80781788(void) {
    return;
}

void func_80781790(void) {
    return;
}

void func_80781798(void) {
    return;
}

void func_807817A0(void) {
    return;
}

void func_807817A8(s32 arg0) {
    func_807935B0(0x35, 0xC9, (arg0 / 1240) + 4, 9, 0x8C, 0x2A, 0);
}

s32 func_80781800(s32 arg0) {
    return arg0;
}

void func_80781808(void) {
    return;
}

int func_80781810(void) {
    if (D_80799E10->unkEC) {
        D_80799E10->unk78 = 0x16;
        D_80799E10->unk84 = 9;
    } else {
        D_80799E10->unk78 = 0x15;
        D_80799E10->unk84 = 8;
    }
    return 0;
}

void func_80781848(void) {
    return;
}

void func_80781850(void) {
    return;
}

s32 func_80781858(void) {
    return 0;
}

s32 func_80781860(void) {
    return 0;
}

s32 func_80781868(void) {
    return 0;
}

INCLUDE_ASM("asm/trainer/nonmatchings/F80", func_80781870);

int func_8078193C(int arg0) {
    // undefined behaviour
    return;
}

void func_80781944(void) {
    D_80799E10->unk130 = func_8078193C(D_80799E10->unk48);
}