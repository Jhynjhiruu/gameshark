#include "common.h"
#include "regs.h"

#include "3650.h"
#include "hw.h"

void func_800424C0(void) {
    volatile VI_regs_t *vi = (void *)PHYS_TO_K1(0x04400000);

    while ((vi->cur_line & 0x3FE) != 2) {
        continue;
    }
    while ((vi->cur_line & 0x3FE) == 2) {
        continue;
    }
}

void func_80042504(u32 data) {
    func_800405BC(0x800, data);
    func_8004267C();
}

int func_8004252C(char to_display) {
    int index = 0;
    int rv = 0xFF;

    static u8 table[] = {
        ' ', 0x00, '.', 0x7F, '0', 0x84, '1',  0x9F, '2',  0xC8, '3', 0x8A,
        '4', 0x93, '5', 0xA2, '6', 0xA0, '7',  0x8F, '8',  0x80, '9', 0x82,
        'E', 0xE0, 'F', 0xE1, 'H', 0x91, 'L',  0xF4, 'O',  0x84, 'P', 0xC1,
        'R', 0x81, 'a', 0xFE, 'b', 0xFD, 'c',  0xFB, 'd',  0xF7, 'e', 0xEF,
        'f', 0xDF, 'g', 0xBF, 'z', 0xEA, '\0', 0xFF, 0xFF, 0x00,
    };

    while (table[index] != 0xFF) {
        if (table[index] == to_display) {
            rv = table[index + 1];
            break;
        }

        index += 2;
    }

    return rv;
}

void func_80042584(char to_display) {
    u32 pattern;
    int toWrite;

    func_800426D4(0x600);
    toWrite = func_8004252C(to_display) | 0x10000;
    while (toWrite > 0x100) {
        pattern = (toWrite & 1) ? 0x02000200 : 0;
        func_80042504(pattern);
        func_80042504(pattern | 0x04000400);
        func_80042504(pattern);
        toWrite = toWrite / 2;
    };
    func_800426D4(0x200);
}

void func_80042628(char to_display) {
    func_80042584(to_display);
}
