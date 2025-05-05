#include "asm.h"

#include "addrs.h"
#include "reg_addrs.h"
#include "macros.h"

.set noreorder
.set gp=64

LEAF(func_80218810)
    li     t0, PHYS_TO_K0(INT_HANDLER)
    la     t1, D_80218870
    li     k0, 20
    li     k1, -1

1:
    lw     t2, 0(t1)
     nop
    sw     t2, 0(t0)

    addi   t0, t0, 4
    addi   t1, t1, 4
    add    k0, k0, k1

    bgtz   k0, 1b
     nop
    
    li     t0, BUILD_WATCHLO(INT_HANDLER, WATCH_WRITE)
    mtc0   t0, C0_WATCHLO
     nop
    mtc0   zero, C0_WATCHHI
     nop
    jr     ra
     nop
END(func_80218810)

LEAF(func_80218864)
    li     k0, UNK_ADDR
    jr     k0
     nop
END(func_80218864)

LEAF(func_80218870)
    mfc0   k0, C0_CAUSE

    LI_LOW(k1, CAUSE_EXC_MASK & ~CAUSE_EXC_SYSCALL)
    andi   k0, k0, CAUSE_EXC_MASK
    beq    k0, k1, 3f
     nop

    bnez   k0, 1f
     nop
    
    lw     k0, PHYS_TO_K1(MI_BASE) + 8 # MI_INTERRUPT
     nop
    andi   k1, k0, (1 << 1) # SI
    bnez   k1, 2f
     nop
    
1:
    j      PHYS_TO_K0(REDIR_INT_HANDLER)
     nop

2:  
    j      PHYS_TO_K0(CODE_HANDLER)
    # BUG: missing delay slot

3:
    li     k0, PHYS_TO_K1(EXCEPT_REDIR_VADDR)
    jr     k0
     nop
END(func_80218870)

LEAF(func_802188C0)
    li     t0, PHYS_TO_K0(INT_HANDLER)
    la     t1, func_80218988
    li     k0, ALIGN(func_80218988_size + func_80218998_size, 0x10) / 4
    li     k1, -1

1:
    lw     t2, 0(t1)
     nop
    sw     t2, 0(t0)

    addi   t0, t0, 4
    addi   t1, t1, 4
    add    k0, k0, k1

    bgtz   k0, 1b
     nop
    
    li     t0, PHYS_TO_K0(ALT_INT_HANDLER)
    la     t1, func_8021894C
    li     k0, ALIGN(func_8021894C_size, 0x10) / 4
    li     k1, -1

1:
    lw     t2, 0(t1)
     nop
    sw     t2, 0(t0)

    addi   t0, t0, 4
    addi   t1, t1, 4
    add    k0, k0, k1

    bgtz   k0, 1b
     nop
    
    li     t0, BUILD_WATCHLO(INT_HANDLER, WATCH_WRITE)
    mtc0   t0, C0_WATCHLO
     nop
    mtc0   zero, C0_WATCHHI
     nop
    
    jr     ra
     nop
END(func_802188C0)

LEAF(func_8021894C)
    mfc0   k0, C0_CAUSE
    
    LI_LOW(k1, CAUSE_EXC_MASK & ~CAUSE_EXC_SYSCALL)
    andi   k0, k0, CAUSE_EXC_MASK
    beq    k0, k1, 3f
     nop
    
    bnez   k0, 2f
    # BUG: missing delay slot

    lw     k0, PHYS_TO_K1(MI_BASE) + 8 # MI_INTERRUPT
    andi   k1, k0, (1 << 1) # SI
    bnez   k1, 2f
     nop

1:
    # BUG: this is just fallthrough, so the bnez is
    # unnecessary

2:
    j      PHYS_TO_K0(CODE_HANDLER)
     nop

3:
    j      PHYS_TO_K0(ALT_EXCEPT_REDIR_TRAMPOLINE)
     nop
END(func_8021894C)

LEAF(func_80218988)
    li     k0, PHYS_TO_K0(ALT_INT_HANDLER)
    jr     k0
     nop
END(func_80218988)

LEAF(func_80218998)
    li     k0, PHYS_TO_K1(EXCEPT_REDIR_VADDR)
    jr     k0
     nop
END(func_80218998)

LEAF(func_802189A8)
    addiu  sp, sp, -20
    sw     a0, 0x00(sp)
    sw     a1, 0x04(sp)
    sw     a2, 0x08(sp)
    sw     a3, 0x0C(sp)
    sw     t6, 0x10(sp)

    lw     a0, PHYS_TO_K0(UNK_POINTER)
    lw     a3, 0(a0)
    beqz   a3, exit_null
    # BUG: missing delay slot

loop:
    lwl    a1, 4(a0)
    lwr    a1, 7(a0)

    li     k0, 0xD0000000
    and    k1, a1, k0

    bne    k1, k0, L80218A40
     lh    a2, 8(a0)
    
    li     k0, 0x01000000
    and    k1, a1, k0

    li     k0, 0x80FFFFFF
    bgtz   k1, 1f
     and   a1, a1, k0
    
    # BUG: condition always holds
    beq    k1, k1, 2f
     lb    t6, 0(a1)

1:
    lh     t6, 0(a1)

2:
    li     k0, 0x02000000
    and    k1, a1, k0

    beq    k1, k0, 1f
     nop
    
    beq    t6, a2, next
     nop
    
    # BUG: condition always holds
    beq    k1, k1, 2f
     nop
    
1:
    bne    t6, a2, next
     nop
    
2:
    addi   a3, a3, -1
    # BUG: condition always holds
    beq    k1, k1, next
     addi  a0, a0, 6
    
L80218A40:
    li     k0, 0x01000000
    and    k1, a1, k0
    li     k0, 0x80FFFFFF
    bgtz   k1, 1f
     and   a1, a1, k0
    
    beq    k1, k1, next
     sb    a2, 0(a1)
    
1:
    sh     a2, 0(a1)

next:
    addi   a3, a3, -1
    bgtz   a3, loop
     addi  a0, a0, 6

exit_null:
    lw     a0, 0x00(sp)
    lw     a1, 0x04(sp)
    lw     a2, 0x08(sp)
    lw     a3, 0x0C(sp)
    lw     t6, 0x10(sp)
    j      PHYS_TO_K0(REDIR_INT_HANDLER)
     addiu sp, sp, 20
END(func_802189A8)

LEAF(func_80218A8C)
    MOVU(t3, a0)
    li     k0, 0x40000

1:
    lw     a3, 0(a1)
     nop
    sw     a3, 0(a0)

    addi   a0, a0, 4
    addi   a1, a1, 4
    addiu  k0, k0, -1
    
    bgtz   k0, 1b
     nop
    
1:
    li     k0, -1
    lw     a0, 0(a2)
    beq    k0, a0, done
     nop
    
    lw     a1, 4(a2)
    li     k0, 0x01000000
    and    k1, a0, k0
    li     k0, 0x80FFFFFF

    bgtz   k1, 2f
     and   a0, a0, k0
    
    # BUG: condition always holds
    beq    k1, k1, 3f
     sb    a1, 0(a0)

2:
    sh     a1, 0(a0)

3:
    addi   a2, a2, 8
    beq    a3, a3, 1b
     nop

done:
    LOAD_RANGE(t0, t1, 0x80000000, 0x80003000, 0x10)

1:
    cache  INDEX_WRITEBACK_INVALIDATE_D, 0(t0)
    bltu   t0, t1, 1b
     addiu t0, t0, 0x10
    
    LOAD_RANGE(t0, t1, 0x80000000, 0x80006000, 0x20)

1:
    cache  INDEX_INVALIDATE_I, 0(t0)
    bltu   t0, t1, 1b
     addiu t0, t0, 0x20
    
    li     sp, STACK_TOP

    jr     t3
     nop
END(func_80218A8C)

LEAF(func_80218B40)
    MOVU(t3, a0)
    li     k0, 0x40000

1:
    lw     a3, 0(a1)
     nop
    sw     a3, 0(a0)

    addi   a0, a0, 4
    addi   a1, a1, 4
    addiu  k0, k0, -1

    bgtz   k0, 1b
     nop
    
    LOAD_RANGE(t0, t1, 0x80000000, 0x80003000, 0x10)

1:
    cache  INDEX_WRITEBACK_INVALIDATE_D, 0(t0)
    bltu   t0, t1, 1b
     addiu t0, t0, 0x10
    
    LOAD_RANGE(t0, t1, 0x80000000, 0x80006000, 0x20)

1:
    cache  INDEX_INVALIDATE_I, 0(t0)
    bltu   t0, t1, 1b
     addiu t0, t0, 0x20
    
    li     sp, STACK_TOP
    
    jr     t3
     nop
END(func_80218B40)

LEAF(func_80218BB0)
    MOVU(sp, a0)
    jr     ra
     nop
END(func_80218BB0)

LEAF(func_80218BBC)
    addiu  sp, sp, -28
    sw     t0, 0x10(sp)
    sw     t1, 0x14(sp)
    sw     AT, 0x18(sp)

    LOAD_RANGE(t0, t1, 0x80000000, 0x80003000, 0x10)

1:
    cache  INDEX_WRITEBACK_INVALIDATE_D, 0(t0)
    bltu   t0, t1, 1b
     addiu t0, t0, 0x10
    
    LOAD_RANGE(t0, t1, 0x80000000, 0x80006000, 0x20)

1:
    cache  INDEX_INVALIDATE_I, 0(t0)
    bltu   t0, t1, 1b
     addiu t0, t0, 0x20
    
    lw     t0, 0x10(sp)
    lw     t1, 0x14(sp)
    lw     AT, 0x18(sp)
    jr     ra
     addiu sp, sp, 28
END(func_80218BBC)

LEAF(func_80218C18)
    cache  HIT_WRITEBACK_INVALIDATE_D, 0(a0)
    jr     ra
     nop
END(func_80218C18)

LEAF(func_80218C24)
    jr     a0
     nop
END(func_80218C24)

LEAF(func_80218C2C)
    addiu  sp, sp, -20
    sw     ra, 0x10(sp)

    jalr   a0
     nop
    
    lw     ra, 0x10(sp)
    addiu  sp, sp, 20
    jr     ra
     nop
END(func_80218C2C)

LEAF(func_80218C4C)
    mfc0   v0, C0_SR
     nop
    jr     ra
     nop
END(func_80218C4C)

LEAF(func_80218C5C)
    mtc0   a0, C0_SR
     nop
    jr     ra
     nop
END(func_80218C5C)

LEAF(func_80218C6C)
    mfc0   v0, C0_CAUSE
    jr     ra
     nop
END(func_80218C6C)

LEAF(func_80218C78)
    mfc0   v0, C0_EPC
    jr     ra
     nop
END(func_80218C78)

LEAF(func_80218C84)
    addiu  sp, sp, -28
    sw     ra, 0x10(sp)
    sw     t0, 0x14(sp)
    sw     t1, 0x18(sp)

    la     t0, 1f

    li     t1, 0x40850000 # mtc0 a1, ...
    or     t1, t1, a0
    sw     t1, 0(t0)

    jal    func_80218BBC
     nop
    
1:
    mtc0   a1, C0_INX # placeholder instruction

    lw     t1, 0x18(sp)
    lw     t0, 0x14(sp)
    lw     ra, 0x10(sp)
    addiu  sp, sp, 28

    jr     ra
     nop
END(func_80218C84)

LEAF(func_80218CCC)
    addiu  sp, sp, -28
    sw     ra, 0x10(sp)
    sw     t0, 0x14(sp)
    sw     t1, 0x18(sp)

    la     t0, 1f

    li     t1, 0x40020000 # mfc0 v0, ...
    or     t1, t1, a0
    sw     t1, 0(t0)

    jal    func_80218BBC
     nop
    
1:
    mfc0   v0, C0_INX # placeholder instruction

    lw     t1, 0x18(sp)
    lw     t0, 0x14(sp)
    lw     ra, 0x10(sp)
    addiu  sp, sp, 28

    jr     ra
     nop
END(func_80218CCC)

LEAF(func_80218D14)
    addiu  sp, sp, -28
    sw     t0, 0x14(sp)
    sw     t1, 0x18(sp)

    li     k0, PHYS_TO_K1(0x805FAE00)
    li     t0, PHYS_TO_K1(0x807C0000)
    li     k1, 0x40

1:
    lw     t1, 0x5C00(t0)
    addi   k1, k1, -1
    sw     t1, 0(k0)

    addi   t0, t0, 4

    bgtz   k1, 1b
     addi  k0, k0, 4
    
    lw     t1, 0x18(sp)
    lw     t0, 0x14(sp)

    li     k0, PHYS_TO_K1(0x805FAE00)
    jr     k0
     addiu sp, sp, 28
END(func_80218D14)

LEAF(func_80218D60)
    lw     t7, 0x10(sp)
    sll    t7, t7, 1
    addi   a3, a3, -1

1:
    MOVU(t0, a0)
    add    a0, a0, t7
    MOVU(t1, a1)
    addi   a1, a1, 640 * 2
    MOVU(t2, a2)

2:
    lh     v0, 0(t0)
    addi   t0, t0, 2
    beqz   v0, 3f
     addi  t2, t2, -1
    
    sh     v0, 0(t1)

3:
    bnez   t2, 2b
     addi  t1, t1, 2
    
    bnez   a3, 1b
     addi  a3, a3, -1
    
    jr     ra
     nop
END(func_80218D60)

LEAF(func_80218DAC)
    PUSH(s0)
    PUSH(s1)
    PUSH(s6)
    PUSH(s7)

    li     s0, 640 * 2
    mult   a1, s0
    
    mflo   s0
    lw     a1, D_80249888
    li     s6, 0x2F

    add    a1, a1, s0
    add    a0, a0, a0
    add    a1, a1, a0

    li     s0, ~0x20000007
    and    a2, a2, s0

1:
    ld     s0, 0x00(a2)
    ld     s1, 0x08(a2)
    sd     s0, 0x00(a1)
    ld     s0, 0x10(a2)
    sd     s1, 0x08(a1)
    ld     s1, 0x18(a2)
    sd     s0, 0x10(a1)
    ld     s0, 0x20(a2)
    sd     s1, 0x18(a1)
    ld     s1, 0x28(a2)
    sd     s0, 0x20(a1)
    ld     s0, 0x30(a2)
    sd     s1, 0x28(a1)
    ld     s1, 0x38(a2)
    sd     s0, 0x30(a1)
    ld     s0, 0x40(a2)
    sd     s1, 0x38(a1)
    ld     s1, 0x48(a2)
    sd     s0, 0x40(a1)
    ld     s0, 0x50(a2)
    sd     s1, 0x48(a1)
    ld     s1, 0x58(a2)
    sd     s0, 0x50(a1)
    ld     s0, 0x60(a2)
    sd     s1, 0x58(a1)
    ld     s1, 0x68(a2)
    sd     s0, 0x60(a1)
    ld     s0, 0x70(a2)
    sd     s1, 0x68(a1)
    ld     s1, 0x78(a2)
    sd     s0, 0x70(a1)
    sd     s1, 0x78(a1)

    addi   a1, a1, 640 * 2
    addi   a2, a2, 128
    bnez   s6, 1b
     addi  s6, s6, -1
    
    POP(s7)
    POP(s6)
    POP(s1)
    POP(s0)

    jr     ra
     nop
END(func_80218DAC)

.set reorder
