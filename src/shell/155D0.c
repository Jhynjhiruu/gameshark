#include "common.h"
#include "regs.h"

#include "155D0.h"

#include "18410.h"

// really these should be u32, but they used int for some reason
extern int D_8023F660[];
extern int *D_802497BC;

void func_802159D0(void) { // reset_channels
    int *tmp;
    int i;

    tmp = D_8023F660;
    ALIGN(tmp, 0x10);
    D_802497BC = tmp;

    D_802497BC[0] = 0xFDFDFDFD;
    D_802497BC[1] = 0xFDFDFE00;

    func_80218C18(D_802497BC);
    func_80218C18(D_802497BC + 0x04 / sizeof(int));
    func_80218C18(D_802497BC + 0x3C / sizeof(int));
    func_80215CB8(D_802497BC);

    for (i = 0; i < 33000; i++) {
        continue;
    }

    func_80215CFC(D_802497BC);

    for (i = 0; i < 33000; i++) {
        continue;
    }
}

int func_80215A8C(void) { // read_controller
    int i;

    D_802497BC[0x00 / sizeof(int)] = 0xFF010401;
    D_802497BC[0x08 / sizeof(int)] = 0xFE000000;
    D_802497BC[0x3C / sizeof(int)] = 1;

    func_80218C18(D_802497BC);
    func_80218C18(D_802497BC + 0x04 / sizeof(int));
    func_80218C18(D_802497BC + 0x08 / sizeof(int));
    func_80218C18(D_802497BC + 0x3C / sizeof(int));
    func_80215CB8(D_802497BC);

    for (i = 0; i < 43000; i++) {
        continue;
    }

    func_80215CFC(D_802497BC);

    for (i = 0; i < 43000; i++) {
        continue;
    }

    return func_80215BE8();
}

void func_80215B4C(void) { // start_read
    D_802497BC[0x00 / sizeof(int)] = 0xFF010401;
    D_802497BC[0x08 / sizeof(int)] = 0xFE000000;
    D_802497BC[0x3C / sizeof(int)] = 1;

    func_80218C18(D_802497BC + 0x00 / sizeof(int));
    func_80218C18(D_802497BC + 0x04 / sizeof(int));
    func_80218C18(D_802497BC + 0x08 / sizeof(int));
    func_80218C18(D_802497BC + 0x3C / sizeof(int));

    func_80215CB8(D_802497BC);
}

void func_80215BC4(void) {
    func_80215CFC(D_802497BC);
}

int func_80215BE8(void) {
    int input;
    int dirs = 0;

    func_80205FBC();

    // y axis
    input = D_802497BC[1] & 0x80;
    if (input) {
        if ((D_802497BC[1] & 0xFF) < 0xC0) {
            dirs += 1;
        }
    } else {
        if ((D_802497BC[1] & 0xFF) > 0x40) {
            dirs += 2;
        }
    }

    // x axis
    input = D_802497BC[1] & 0x8000;
    if (input) {
        if ((D_802497BC[1] & 0xFF00) < 0xC000) {
            dirs += 4;
        }
    } else {
        if ((D_802497BC[1] & 0xFF00) > 0x4000) {
            dirs += 8;
        }
    }

    return (D_802497BC[1] & 0xFFFF0000) + dirs;
}

void func_80215C94(void) {
    // BUG: should be volatile
    SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);

    while ((si->status & 3) != 0) {
        continue;
    }
}

void func_80215CB8(void *addr) {
    volatile SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);

    func_80215C94();

    si->DRAM_addr = (void *)K0_TO_PHYS(addr);
    si->PIF_addr_write = 0x1FC007C0;
}

void func_80215CFC(void *addr) {
    volatile SI_regs_t *si = (void *)PHYS_TO_K1(0x04800000);

    func_80215C94();

    si->DRAM_addr = (void *)K0_TO_PHYS(addr);
    si->PIF_addr_read = 0x1FC007C0;
}
