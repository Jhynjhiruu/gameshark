#include "common.h"
#include "regs.h"

void func_80040560(void) {
    volatile PI_regs_t *pi = (void *)PHYS_TO_K1(0x04600000);

    while (pi->status & 3) {
        continue;
    }
}
