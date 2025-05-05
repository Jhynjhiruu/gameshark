#include "asm.h"

.set noat
.set noreorder

LEAF(func_800422C0)
    addiu  sp, sp, -0x1C
    
    sw     t0, 0x10(sp)
    sw     t1, 0x14(sp)
    sw     AT, 0x18(sp)

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

    lw     t0, 0x10(sp)
    lw     t1, 0x14(sp)
    lw     AT, 0x18(sp)

    jr     ra
     addiu sp, sp, 0x1C
END(func_800422C0)

LEAF(func_8004231C)
    cache  HIT_WRITEBACK_INVALIDATE_D, 0(a0)
    jr     ra
     nop
END(func_8004231C)

LEAF(func_80042328)
    jr     a0
     nop
END(func_80042328)

LEAF(func_80042330)
    addiu  sp, sp, -0x14

    sw     ra, 0x10(sp)

    jalr   a0
     nop
    
    lw     ra, 0x10(sp)

    addiu  sp, sp, 0x14

    jr     ra
     nop
END(func_80042330)

LEAF(func_80042350)
    mfc0   v0, C0_SR
    jr     ra
     nop
END(func_80042350)

LEAF(func_8004235C)
    mtc0   a0, C0_SR
    jr     ra
     nop
END(func_8004235C)

LEAF(func_80042368)
    mfc0   v0, C0_CAUSE
    jr     ra
     nop
END(func_80042368)

LEAF(func_80042374)
    mfc0   v0, C0_EPC
    jr     ra
     nop
END(func_80042374)

LEAF(func_80042380)
    addiu  sp, sp, -0x1C

    sw     ra, 0x10(sp)
    sw     t0, 0x14(sp)
    sw     t1, 0x18(sp)

    la     t0, 1f

    li     t1, 0x40850000 # mtc0 a1, ...
    or     t1, t1, a0
    sw     t1, 0(t0)

    jal    func_800422C0
     nop

1:
    mtc0   a1, C0_INX # placeholder instruction

    lw     t1, 0x18(sp)
    lw     t0, 0x14(sp)
    lw     ra, 0x10(sp)
    
    addiu  sp, sp, 0x1C

    jr     ra
     nop
END(func_80042380)

LEAF(func_800423C8)
    addiu  sp, sp, -0x1C

    sw     ra, 0x10(sp)
    sw     t0, 0x14(sp)
    sw     t1, 0x18(sp)

    la     t0, 1f

    li     t1, 0x40020000 # mfc0 v0, ...
    or     t1, t1, a0
    sw     t1, 0(t0)

    jal    func_800422C0
     nop

1:
    mfc0   v0, C0_INX # placeholder instruction

    lw     t1, 0x18(sp)
    lw     t0, 0x14(sp)
    lw     ra, 0x10(sp)
    
    addiu  sp, sp, 0x1C

    jr     ra
     nop
END(func_800423C8)

.set reorder
.set at
