#ifndef _540_H
#define _540_H

#include "types.h"

int func_80201E64(void);

void func_8020222C(void *dst, int offset, int len, int index);

void func_802026E4(void *addr);

void read_chunk(int address, int which);

void write_chunk(int address, int which);

void func_80202B88(void);

void func_80202BAC(void *addr);

int calc_address_crc(u32 data);

int calc_data_crc(u8 *data);

u8 controller_status(void);

void func_80203044(u8 *dst, u8 *src, int len);

void func_80203070(u8 *dst, int len);

#endif