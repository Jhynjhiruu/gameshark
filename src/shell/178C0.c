#include "common.h"

#include "178C0.h"

#include "17990.h"

u32 D_802283C0 = 0x00400000;
u32 D_802283C4 = 0xB0000000;

u32 func_80217CC0(u32 offset) {
    u32 addr = D_802283C4 | D_802283C0 | offset;
    func_80217D90();
    return READ32(addr);
}

void func_80217CFC(u32 offset, u32 data) {
    u32 doubled_data = ((u16)data << 16) | (u16)data;
    u32 addr = D_802283C4 | D_802283C0 | offset;

    WRITEV32(addr, doubled_data);
    func_80217D90();
}

void func_80217D40(u32 data) {
    u32 masked = (data & 0x0F000000) | 0x10000000;

    func_80217CFC(0x400, masked >> 24);
    D_802283C4 = masked | 0xB0000000;
}
