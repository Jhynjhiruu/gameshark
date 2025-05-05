#ifndef _HW_H
#define _HW_H

#include "types.h"

extern u32 D_80042AA0;
extern u32 D_80042AA4;

u32 func_80040580(u32 offset);

void func_800405BC(u32 offset, u32 data);

void func_80040600(u32 data);

void func_80040648(void);

void func_8004066C(u32 byte);

int func_800406FC(u8 to_display);

#endif