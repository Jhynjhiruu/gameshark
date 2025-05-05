#include "common.h"
#include "include_asm.h"

#include "pi.h"

u32 D_80042AA0 = 0x00400000;
u32 D_80042AA4 = 0xB0000000;

u32 func_80040580(u32 offset) {
    u32 addr = D_80042AA4 | D_80042AA0 | offset;

    func_80040560();
    return READ32(addr);
}

void func_800405BC(u32 offset, u32 data) {
    u32 doubled_data = ((u16)data << 16) | (u16)data;
    u32 addr = D_80042AA4 | D_80042AA0 | offset;

    WRITEV32(addr, doubled_data);
    func_80040560();
}

void func_80040600(u32 data) {
    u32 masked = (data & 0x0F000000) | 0x10000000;

    func_800405BC(0x400, masked >> 24);
    D_80042AA4 = masked | 0xB0000000;
}

void func_80040648(void) {
    func_800405BC(0x600, 0x7FF7FF);
}

void func_8004066C(u32 byte) {
    u32 mask;
    int bit;

    func_80040648();
    for (bit = 1; bit < 0x100; bit <<= 1) {
        mask = (byte & bit) ? 0x01000100 : 0;
        func_800405BC(0x800, mask);
        func_800405BC(0x800, mask | 0x02000200);
        func_800405BC(0x800, mask);
    }
}

int func_800406FC(u8 to_display) {
    int i;

    const u8 table[] = {
        '0',  0x84, '1',  0x9F, '2',  0xC8, '3',  0x8A, '4',  0x93, '5',
        0xA2, '6',  0xA0, '7',  0x8F, '8',  0x80, '9',  0x82, 'B',  0xFF,
    };

    for (i = 0; i < ARRAY_LEN(table); i += 2) {
        if (table[i] == to_display) {
            func_8004066C(table[i + 1]);
            return 1;
        }
    }

    return 0;
}
