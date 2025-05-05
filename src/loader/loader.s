#include "asm.h"

#include "addrs.h"

EXPORT(entrypoint)

.org 32 * 4 # code starts at 0x1080

.set noat
.set noreorder

LEAF(func_80200480)
  la     t0, PHYS_TO_K1(0x10C01000)

  la     t1, 0x80040000
  la     t2, 0x3F000

1:
  lw     t3, 0(t0)
  addiu  t0, t0, 4

  sw     t3, 0(t1)
  addiu  t2, t2, -4

  bnez   t2, 1b
   addiu t1, t1, 4
  
  LA(t1, t0, 0x80003000)
  
  addiu  t1, t1, -0x10

1:
  cache  INDEX_WRITEBACK_INVALIDATE_D, 0(t0)
  sltu   AT, t0, t1
  bnez   AT, 1b
   addiu t0, t0, 0x10
  
  LA(t1, t0, 0x80006000)

  addiu  t1, t1, -0x20

1:
  cache  INDEX_INVALIDATE_I, 0(t0)
  sltu   AT, t0, t1
  bnez   AT, 1b
   addiu t0, t0, 0x20
  
  la     sp, STACK_TOP
  
  j      func_80040180
   nop
END(func_80200480)

LEAF(func_802004F4)
  li     t0, PHYS_TO_K1(0x04400000)

  li     t1, 0x13002
  sw     t1, 0x00(t0)

  li     t1, 0x80000000
  sw     t1, 0x04(t0)

  li     t1, 0x140
  sw     t1, 0x08(t0)

  li     t1, 0x3E52239
  sw     t1, 0x14(t0)

  li     t1, 0x20D
  sw     t1, 0x18(t0)

  li     t1, 0xC15
  sw     t1, 0x1C(t0)

  li     t1, 0xC150C15
  sw     t1, 0x20(t0)

  li     t1, 0x6C02EC
  sw     t1, 0x24(t0)

  li     t1, 0x2501FF
  sw     t1, 0x28(t0)

  li     t1, 0xE0204
  sw     t1, 0x2C(t0)

  li     t1, 0x200
  sw     t1, 0x30(t0)

  li     t1, 0x400
  sw     t1, 0x34(t0)

  bgez   zero, .
   nop
END(func_802004F4)

.set reorder
.set at
