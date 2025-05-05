#include "common.h"

#include "17990.h"

u32 D_802283B0 = 0;
u32 D_802283B4 = 0;

extern u8 D_8023F6B0[0x1000];

int func_80217C10(u32 addr) {
    u8 *ptr;
    u32 offset;

    if (addr < 0xB0000000) {
        return *(u8*)addr;
    }
    
    if (D_802283B0 == 0) {
        D_802283B0 = (u32)D_8023F6B0;
        ALIGN(D_802283B0, 0x10);
    }
    
    ptr = (u8*)D_802283B0;
    
    offset = addr - D_802283B4;
    
    if (offset < 0x1000) {
        return ptr[offset];
    } else {
        func_80217DAC(ptr, addr, 0x1000);
        D_802283B4 = addr;
        return ptr[0];
    }
}
