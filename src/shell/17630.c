#include "common.h"

#include "17630.h"

#include "17280.h"
#include "178C0.h"

void func_80217A30(char *str) {
    while (*str != 0) {
        func_8021781C(*str++);
    }
}

void func_80217A74(int nibble) {
    int masked = nibble & 0xF;
    func_8021781C(masked + (masked >= 10 ? 'A' - 10 : '0'));
}

void func_80217AA8(int byte) {
    func_80217A74(byte >> 4);
    func_80217A74(byte);
}

void func_80217AD8(int half) {
    func_80217AA8(half >> 8);
    func_80217AA8(half);
}

void func_80217B08(int word) {
    func_80217AD8(word >> 0x10);
    func_80217AD8(word);
}

void func_80217B38(int num, unsigned int base, int is_signed) {
    char *chars = "0123456789ABCDEF";
    int rem;

    if ((num < 0) && is_signed) {
        func_8021781C('-');
        num = -num;
    }

    rem = num / base;
    if (rem != 0) {
        func_80217B38(rem, base, 0);
    }

    func_8021781C(chars[num % base]);
}

void func_80217BC4(char *fmt, ...) {
    // almost certainly a fake match
    char *stack_pad[4];

    // these aren't necessarily from this function, but they're unused and need
    // to go somewhere
    // either this function or the next would be fine
    char *D_80224C64 = "%8 ";
    char *D_80224C68 = " %2";
    char *D_80224C6C = "-";
    char *D_80224C70 = "%2 ";
    char *D_80224C74 = " ";
    char *D_80224C78 = "%c";
    char *D_80224C7C = "\n";

    if (fmt[0])
        fmt = 0;
}

void func_80217BE0(void *unk0, int unk1) {
    int stack_pad[4];
    if (unk1)
        unk1 = 0;
}

void func_80217BEC(void) {
    D_802283C0 = 0x400000;
    D_802283C4 = 0xBE000000;
}
