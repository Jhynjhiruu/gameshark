#ifndef _TYPES_H
#define _TYPES_H

#ifndef __ASSEMBLER__

// clang-format off
typedef unsigned      char  u8;
typedef   signed      char  s8;
typedef unsigned     short u16;
typedef   signed     short s16;
typedef unsigned       int u32;
typedef   signed       int s32;
typedef unsigned long long u64;
typedef   signed long long s64;

typedef              float f32;
typedef             double f64;
// clang-format on

#define TRUE (1)
#define FALSE (0)

typedef u32 size_t;

typedef u8 Addr[];

#endif

#endif