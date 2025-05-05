#include "common.h"
#include "regs.h"

#include "si.h"

#define PIF_RAM(addr) (0x1FC00000 + (addr))

void func_80042410(void) {
    volatile SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);
    
    while ((u32)si->PIF_addr_read_broken & 3) { // BUG: wrong address!
        continue;
    }
}

u32 func_8004242C(u32 *addr) {
    func_80042410();
    return READ32(addr);
}

void func_80042454(u32 *addr, u32 data) {
    func_80042410();
    WRITE32(addr, data);
}

void func_80042488(void) {
    const u32 addr = PHYS_TO_K1(PIF_RAM(0x7FC));
    func_80042454(addr, func_8004242C(addr) | 8);
}
