
#ifndef _REGS_H
#define _REGS_H

// Taken from libdragon
// https://github.com/DragonMinded/libdragon/blob/da0db7ae3ec8bdba518b8e397f2c6b7819173123/include/regsinternal.h

#include "reg_addrs.h"

#include "types.h"

typedef struct AI_regs_s {
    volatile void *address;
    u32 length;
    u32 control;
    u32 status;
    u32 dacrate;
    u32 bitrate;
} AI_regs_t;

typedef struct VI_regs_s {
    u32 control;
    void *framebuffer;
    u32 width;
    u32 v_int;
    u32 cur_line;
    u32 timing;
    u32 v_sync;
    u32 h_sync;
    u32 h_sync2;
    u32 h_limits;
    u32 v_limits;
    u32 color_burst;
    u32 h_scale;
    u32 v_scale;
} VI_regs_t;

typedef struct PI_regs_s {
    volatile void *ram_address;
    u32 pi_address;
    u32 read_length;
    u32 write_length;
    u32 status;
    u32 dom1_latency;
    u32 dom1_pulse_width;
    // TODO: add remaining registers
} PI_regs_t;

typedef struct SI_regs_s {
    volatile void *DRAM_addr;
    volatile void *PIF_addr_read;
    volatile void *PIF_addr_write_broken;
    u32 reserved2;
    volatile void *PIF_addr_write;
    volatile void *PIF_addr_read_broken;
    u32 status;
} SI_regs_t;

typedef struct SP_regs_s {
    volatile void *RSP_addr;
    volatile void *DRAM_addr;
    u32 rsp_read_length;
    u32 rsp_write_length;
    u32 status;
    u32 rsp_dma_full;
    u32 rsp_dma_busy;
    u32 rsp_semaphore;
} SP_regs_t;

#endif