#include "common.h"
#include "regs.h"
#include "shell/linker.h"

#include "ai.h"

#include "C9A0.h"

// BUG: calculations here are wildly wrong

#ifdef BUG_FIX_AUDIO
#define AI_NTSC_DACRATE 48681818
#define AI_PAL_DACRATE 49656530
#define AI_MPAL_DACRATE 48628322

#define AUDIO_SAMPLE_RATE 11025
#define DACRATE (AI_NTSC_DACRATE / AUDIO_SAMPLE_RATE) - 1
#define BITRATE 15
#define SAMPLES_TO_LEN(x) (x)
#else
#define DACRATE 11025
#define BITRATE 8
#define SAMPLES_TO_LEN(x) ((x) >> 2)
#endif

void func_802061A0(void *address, int length, int dacrate, int bitrate) {
    volatile AI_regs_t *ai = (void *)PHYS_TO_K1(0x04500000);

    ai->address = address;

    if (length < 0) {
        length += 7;
    }

    ai->length = length >> 3;
    ai->control = 1;
    ai->dacrate = dacrate;
    ai->bitrate = bitrate;
}

void func_802061D0(int which) {
    if (D_80227C10 != 0) {
        if (which == 0) {
            func_802061A0(sfx0_DATA_START,
                          SAMPLES_TO_LEN(sfx0_DATA_END - sfx0_DATA_START),
                          DACRATE, BITRATE);
        } else {
            func_802061A0(sfx1_DATA_START,
                          SAMPLES_TO_LEN(sfx1_DATA_END - sfx1_DATA_START),
                          DACRATE, BITRATE);
        }
    }
}
