#ifndef _F8E0_H
#define _F8E0_H

#include "types.h"

typedef struct {
    /* 0x0 */ u16 unk0; /* inferred */
    /* 0x2 */ u16 unk2; /* inferred */
    /* 0x4 */ u16 unk4; /* inferred */
} cheat;                /* size = 0x6 */

typedef struct {
    /* 0x000 */ cheat *unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ char unk_8[0x3C]; /* maybe part of unk4[0x10]? */
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04C */ char unk_4C[4];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ char unk_58[0x20]; /* maybe part of unk54[9]? */
    /* 0x078 */ s32 unk78;
    /* 0x07C */ char unk_7C[8]; /* maybe part of unk78[3]? */
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08C */ char unk_8C[0x28]; /* maybe part of unk88[0xB]? */
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ s32 unkB8;
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ s32 unkC4;
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ s32 unkCC;
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ s32 unkD4;
    /* 0x0D8 */ s32 unkD8;
    /* 0x0DC */ s32 unkDC;
    /* 0x0E0 */ s32 unkE0;
    /* 0x0E4 */ char unk_E4[4];
    /* 0x0E8 */ s32 unkE8; /* inferred */
    /* 0x0EC */ s32 unkEC;
    /* 0x0F0 */ s32 unkF0;
    /* 0x0F4 */ char unk_F4[0x14]; /* maybe part of unkF0[6]? */
    /* 0x108 */ s32 unk108;
    /* 0x10C */ char unk_10C[0x24]; /* maybe part of unk108[0xA]? */
    /* 0x130 */ s32 unk130;
    /* 0x134 */ char unk_134[0x2C]; /* maybe part of unk130[0xC]? */
    /* 0x160 */ s32 unk160;
} unk; /* size = 0x164 */

extern unk *D_80799E10;

void func_80790B74(void);

#endif