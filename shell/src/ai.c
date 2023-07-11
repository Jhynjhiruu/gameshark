#include "common.h"
#include "linker.h"

extern s32 D_80227C10;

#ifdef BUG_FIX_AUDIO
    #define AUDIO_SAMPLE_RATE 11025
    #define DACRATE (VI_NTSC_CLOCK / AUDIO_SAMPLE_RATE) - 1
    #define BITRATE 15
    #define SAMPLES_TO_LEN(x) (x)
#else
    #define DACRATE 11025 // looks like they forgot to apply the formula to calculate this properly
    #define BITRATE 8
    #define SAMPLES_TO_LEN(x) ((x) >> 2) // shift once for 16-bit, and once more for stereo - both errors
#endif


void func_802061A0(void* addr, int len, u32 dacrate, u32 bitrate, u32 is_error) {
    vu32* ai_regs = (vu32*)PHYS_TO_K1(AI_BASE_REG);
#ifdef BUG_FIX_AUDIO
    if (ai_regs[3] & is_error) {
        return; // prevent sfx playing twice
    }
    ai_regs[0] = (u32)addr;
    ai_regs[1] = len; // no need to shift here
#else
    ai_regs[0] = (u32)addr;
    if (len < 0) {
        len += 7; // useless?
    }
    ai_regs[1] = len >> 3; // bug
#endif
    ai_regs[2] = AI_CONTROL_DMA_ON;
    ai_regs[4] = dacrate;
    ai_regs[5] = bitrate;
}

void func_802061D0(s32 arg0) {
    //if (D_80227C10 != 0) {
        if (arg0 == 0) {
            func_802061A0(sfx0_bin, SAMPLES_TO_LEN(sfx1_bin - sfx0_bin), DACRATE, BITRATE, 0);        
        } else {
            func_802061A0(sfx1_bin, SAMPLES_TO_LEN(_2D25C_bin - sfx1_bin), DACRATE, BITRATE, AI_STATUS_DMA_BUSY);
        }
    //}
}

#ifndef NON_MATCHING
asm(".word 0x6C6F7701");
#endif

