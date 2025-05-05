#include "asm.h"

.set noat
.set noreorder

#define INT_HANDLER (0x80000180)
#define REDIR_INT_HANDLER (0x80000120)

# this function is reached when osInitialize
# tries to write the interrupt handler trampoline
# to 0x80000180
LEAF(func_8006E000)
  addiu  sp, sp, -0x68

  sw     t0, 0x10(sp) # push all possible source registers
  sw     t1, 0x14(sp) # to the stack
  sw     t2, 0x18(sp)
  sw     t3, 0x1C(sp)
  sw     t4, 0x20(sp)
  sw     t5, 0x24(sp)
  sw     t6, 0x28(sp)
  sw     t7, 0x2C(sp)
  sw     t8, 0x30(sp)
  sw     t9, 0x34(sp)
  sw     a0, 0x38(sp)
  sw     a1, 0x3C(sp)
  sw     a2, 0x40(sp)
  sw     a3, 0x44(sp)
  sw     s0, 0x48(sp)
  sw     s1, 0x4C(sp)
  sw     s2, 0x50(sp)
  sw     s3, 0x54(sp)
  sw     s4, 0x58(sp)
  sw     s5, 0x5C(sp)
  sw     s6, 0x60(sp)
  sw     s7, 0x64(sp)

  addu   t0, sp, zero
  addiu  t1, t0, 0x68

  la     t2, INT_HANDLER

1:
  lw     t3, 0x10(t0) # loop through registers
   nop                # on the stack
  
  beq    t2, t3, 1f   # if the value equals
   nop                # 0x80000180, change it
  
  addiu  t0, t0, 4
  bne    t0, t1, 1b   # next offset
   nop
  bgez   zero, 2f     # checked all registers
   nop

1:
  la     t2, PHYS_TO_K1(REDIR_INT_HANDLER)
  sw     t2, 0x10(t0) # replace with 0xA0000120

2:
  lw     t0, 0x10(sp) # restore registers from the stack
  lw     t1, 0x14(sp)
  lw     t2, 0x18(sp)
  lw     t3, 0x1C(sp)
  lw     t4, 0x20(sp)
  lw     t5, 0x24(sp)
  lw     t6, 0x28(sp)
  lw     t7, 0x2C(sp)
  lw     t8, 0x30(sp)
  lw     t9, 0x34(sp)
  lw     a0, 0x38(sp)
  lw     a1, 0x3C(sp)
  lw     a2, 0x40(sp)
  lw     a3, 0x44(sp)
  lw     s0, 0x48(sp)
  lw     s1, 0x4C(sp)
  lw     s2, 0x50(sp)
  lw     s3, 0x54(sp)
  lw     s4, 0x58(sp)
  lw     s5, 0x5C(sp)
  lw     s6, 0x60(sp)
  lw     s7, 0x64(sp)

  addiu  sp, sp, 0x68

  eret                # arrived here from an exception
END(func_8006E000)

.set noreorder
.set noat

.balign 0x10

.skip (0xC00 - (. - func_8006E000)), 0xFF
