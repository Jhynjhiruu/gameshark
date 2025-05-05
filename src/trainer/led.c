#include "common.h"

#include "led.h"

#include "hw.h"

void func_80780C50(s32 arg0) {
    func_80787FBC(0x800, arg0);
    // 6980.s
    func_80787C0C();
}

int func_80780C78(char to_display) {
    int index = 0;
    int rv = 0xFF;

    static u8 table[] = {
        ' ', 0x00, '.', 0x7F, '0',  0x84, '1',  0x9F, '2', 0xC8, '3', 0x8A,
        '4', 0x93, '5', 0xA2, '6',  0xA0, '7',  0x8F, '8', 0x80, '9', 0x82,
        'E', 0xE0, 'F', 0xE1, 'H',  0x91, 'L',  0xF4, 'O', 0x84, 'R', 0x81,
        'a', 0xFE, 'b', 0xFD, 'c',  0xFB, 'd',  0xF7, 'e', 0xEF, 'f', 0xDF,
        'g', 0xBF, 'z', 0xEA, '\0', 0xFF, 0xFF, 0x00,
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

void func_80780CD0(char to_display) {
    u32 pattern;
    int toWrite;

    func_80787C64(0x600);
    toWrite = func_80780C78(to_display) | 0x10000;
    while (toWrite > 0x100) {
        pattern = (toWrite & 1) ? 0x02000200 : 0;
        func_80780C50(pattern);
        func_80780C50(pattern | 0x04000400);
        func_80780C50(pattern);
        toWrite = toWrite / 2;
    };
    func_80787C64(0x200);
}

void func_80780D74(int data) {
    func_80780CD0(data & 0xFF);
}
