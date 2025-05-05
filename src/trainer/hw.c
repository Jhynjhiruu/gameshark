#include "common.h"

#include "hw.h"

u32 D_80799D00 = 0x00400000;
u32 D_80799D04 = 0xB0000000;

u32 func_80787F80(u32 offset) {
    u32 addr = D_80799D04 | D_80799D00 | offset;

    func_80788050();
    return READ32(addr);
}

void func_80787FBC(u32 offset, u32 data) {
    u32 doubled_data = ((u16)data << 16) | (u16)data;
    u32 addr = D_80799D04 | D_80799D00 | offset;

    WRITEV32(addr, doubled_data);
    func_80788050();
}

void func_80788000(u32 data) {
    u32 masked = (data & 0x0F000000) | 0x10000000;

    func_80787FBC(0x400, masked >> 24);
    D_80799D04 = masked | 0xB0000000;
}
