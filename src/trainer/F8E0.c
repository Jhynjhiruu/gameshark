#include "common.h"
#include "include_asm.h"

#include "73E0.h"
#include "F8E0.h"

#include "strings.h"

unk *D_80799E10 = NULL;

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_807900E0);

void func_807901F8(void) {
    if (D_80799E10->unk4 == 0) {
        D_80799E10->unk4 = 1;
        return;
    }
    D_80799E10->unk4 = 0;
}

void func_8079021C(void) {
    func_807900E0(D_80799E10->unk88, 0);
}

void func_80790244(void) {
    func_807900E0(D_80799E10->unk88, 1);
}

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_8079026C);

void func_80790604(void) {}

void func_8079060C(void) {
    if (D_80799E10->unk44 == 0) {
        D_80799E10->unk44 = 1;
    }
    D_80799E10->unk50 = 0;
    D_80799E10->unk54 = 0;
    D_80799E10->unk108 = 0;
}

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80790638);
void func_80790A00(s32 arg0, s32 arg1) {
    func_80787A58();

    if (arg1 != 0) {
        func_807935B0(0, 0, 0x140, 0xF0, 0, 0, 0);
        func_8078F5C8(2, 0x18, 0x9C, 0x90, 0);
        func_8078F5C8(0xA2, 0x18, 0x9C, 0x90, 0);
        func_8078EF90(2, 0x18, 0xE, D_80799E20[STR_POSSIBILITIES], 0);
        func_8078EF90(0xA2, 0x18, 0xE, D_80799E20[STR_ACTIVE_CODES], 0);
    }

    func_807935B0(0, 0xB0, 0x140, 0x40, 0, 0, 0);

    func_80793504(0xB0, D_80799E20[STR_HIGHLIGHT], 0xFFFEFFFE);
    func_80793504(0xC8, D_80799E20[STR_START_RETURNS_TO_GAME], 0xFFFEFFFE);
    func_80793504(0xD0, D_80799E20[STR_HEX_DECIMAL_MEMORY_EDITOR], 0xFFFEFFFE);

    if (arg0 == 0) {
        func_80793504(0xB8, D_80799E20[STR_COPY_TO_ACTIVE_CODES], 0xFFFEFFFE);
        func_80793504(0xC0, D_80799E20[STR_MOVE_TO_ACTIVE_CODES], 0xFFFEFFFE);
    } else {
        func_80793504(0xB8, D_80799E20[STR_DELETE_A_CODE], 0xFFFEFFFE);
        func_80793504(0xC0, D_80799E20[STR_EDIT_A_CODE], 0xFFFEFFFE);
    }

    func_80792F8C();
}

void func_80790B74(void) {
    D_80799E10->unkB8 = 0;
    D_80799E10->unkDC = 0;
    D_80799E10->unkE0 = 0;
    D_80799E10->unkC0 = 0;
    D_80799E10->unkC4 = 0;
}

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80790B94);

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80790C68);

void func_80790D80(s32 arg0) {
    func_807935B0(0, 0xD8, 0x140, 8, 0, 0, 0);
    func_80793504(0xD8, arg0, 0xFFC0FFC0);
    D_80799E10->unkB8 = 0x78;
}

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80790DE4);

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80790ECC);

void func_80790F54(void) {}

int func_80790F5C(void) {
    if (D_80799E10->unkD8 == 1) {
        if (D_80799E10->unkC4 > 0) {
            D_80799E10->unkC4--;
            return 1;
        }
        if (D_80799E10->unkE0 > 0) {
            D_80799E10->unkE0--;
            return 1;
        }
    } else {
        if (D_80799E10->unkC0 > 0) {
            D_80799E10->unkC0--;
            return 1;
        }
        if (D_80799E10->unkDC > 0) {
            D_80799E10->unkDC--;
            return 1;
        }
    }
    return 0;
}

int func_80790FDC(void) {
    int count;
    int limit;

    if (D_80799E10->unkD8 == 1) {
        count = D_80799E10->unkE0 + D_80799E10->unkC4;
        limit = D_80799E10->unk160 - 1;
        if (count < limit) {
            if (D_80799E10->unkC4 <= 12) {
                D_80799E10->unkC4++;
                return 1;
            } else {
                D_80799E10->unkE0++;
                return 1;
            }
        }
    } else {
        count = D_80799E10->unkDC + D_80799E10->unkC0;
        limit = D_80799E10->unkBC - 1;
        if (count < limit) {
            if (D_80799E10->unkC0 <= 12) {
                D_80799E10->unkC0++;
                return 1;
            } else {
                D_80799E10->unkDC++;
                return 1;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80791084);

s32 func_80791780(void) {
    return func_80787EE0() == 3;
}

void func_807917A4(void) {
    while (TRUE) {
        while (func_80787D5C(0x67) != 0x47) {
            continue;
        }
        if (func_80787D5C(0x74) == 0x54) {
            break;
        }
    }
}

int func_807917F0(int tx) {
    int rx = func_80787D5C(tx >> 0x18) << 0x18;
    rx |= (func_80787D5C(tx >> 0x10) << 0x10);
    rx |= (func_80787D5C(tx >> 8) << 8);
    rx |= func_80787D5C(tx);
    return rx;
}

s32 func_80791850(void) {
    return func_807917F0(0);
}

s32 func_8079186C(s32 data) {
    return func_807917F0(data);
}

void func_80791888(int write) {
    char ledval = 'c';
    int checksum = 0;
    int count = 0;
    int len;
    int tmp;

    // also matches as a do-while loop
    u8 *ptr = -1;
    while (ptr != NULL) {

        ptr = func_807917F0(0);
        len = func_807917F0(0);

        if (ptr == NULL) {
            break;
        }

        tmp = (u32)ptr;
        if (tmp >= 0xBE000000) {
            tmp = 0x80000400;
            ptr = 0x80000400;
        }

        if ((tmp - 0x80780000) <= 0x80000) {
            tmp = 0x80000400;
            ptr = 0x80000400;
        }

        if (write == 0) {
            for (; len > 0; len -= 1) {
                count++;
                if ((count % 0x400) == 0) {
                    func_80780CD0(ledval++);

                    if (ledval == 'g') {
                        ledval = 'c';
                    }
                }

                tmp = *(ptr++);
                func_80787D5C(tmp);
                checksum += tmp;
            }
            checksum &= 0xFF;
        } else {
            count++;
            for (; len > 0; len -= 1) {
                if ((count % 0x400) == 0) {
                    func_80780CD0(ledval++);

                    if (ledval == 'g') {
                        ledval = 'c';
                    }
                }

                tmp = func_80787D5C(0);
                *(ptr++) = tmp;
                checksum += tmp;
            }
            checksum &= 0xFF;
        }
    }
    func_80787D5C(checksum);
}

INCLUDE_ASM("asm/trainer/nonmatchings/F8E0", func_80791A14);

void func_80791AB4(void) {
    int temp_s0;
    int temp_s1;

    while (TRUE) {
        while (TRUE) {
            while ((func_80787D5C('g') != 'G')) {
                continue;
            }
            if (func_80787D5C('t') == 'T') {
                break;
            }
        }

        switch (func_80787D5C(0)) {
            case 0x1:
                func_80791888(0);
                break;

            case 0x2:
                func_80791888(1);
                break;

            case 0x64:

                return;

            case 0x65:
                func_80787D5C(2);
                return;

            case 0x69:
                temp_s0 = func_807917F0(0);
                temp_s1 = func_807917F0(0);
                if (D_80799E10->unk160 == 0x28) {
                    func_80787D5C(0xFE);
                } else if (func_80790ECC(temp_s0) == -1) {
                    func_80790B94(temp_s0, temp_s1);
                    func_80787D5C(0);
                } else {
                    func_80787D5C(0xFF);
                }
                break;

            case 0x6A:
                func_80787D5C(D_80799E10->unk160);
                break;

            case 0x6B:
                temp_s0 = func_807917F0(0) & 0xFCFFFFFF;
                temp_s1 = func_80790ECC(temp_s0);
                if (temp_s1 != -1) {
                    func_80790DE4(temp_s1);
                }
                break;

            case 0x70:
                func_80791A14();
                break;

            case 0x72:
                func_80794A44();
                return;

            case 0x7F:
                func_80791CDC();
                return;
        }
    }
}

void func_80791CDC(void) {
    char ledval = 'c';
    int checksum = 0;
    int count = 0;

    int *ptr = func_80787DD4(0);
    int len = func_80787DD4(0);

    if (ptr != 0) {
        for (; len > 0; len -= 4) {
            int data;

            count++;
            if ((count % 0x400) == 0) {
                func_80780CD0(ledval++);

                if (ledval == 'g') {
                    ledval = 'c';
                }
            }

            data = *(ptr++);
            func_80787DD4(data);
            checksum += data;
        }
        checksum &= 0xFF;
    }
    func_80787D5C(checksum);
}
