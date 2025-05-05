#ifndef _MACROS_H
#define _MACROS_H

#include "types.h"

#define NULL ((void *)0)

#ifdef __ASSEMBLER__

#define ALIGN(x, a) ((x + (a - 1)) & ~(a - 1))

#else

static inline u32 READ32(u32 addr) {
    return *(u32 *)addr;
}

static inline void WRITE32(u32 addr, u32 data) {
    *(u32 *)addr = data;
}

static inline u32 READV32(u32 addr) {
    return *(volatile u32 *)addr;
}

static inline void WRITEV32(u32 addr, u32 data) {
    *(volatile u32 *)addr = data;
}

#define ALIGN0(x, a) ({ (x) = (typeof(x))((u32)(x) + ((a) - 1)); })
#define ALIGN1(x, a) ({ (x) = (typeof(x))((u32)(x) & ~((a) - 1)); })

#define ALIGN(x, a)                                                            \
    ({                                                                         \
        ALIGN0(x, a);                                                          \
        ALIGN1(x, a);                                                          \
    })

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

#endif

#endif