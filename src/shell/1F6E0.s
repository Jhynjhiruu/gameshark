#include "asm.h"

#define SCREEN_WIDTH (640)
#define SCREEN_HEIGHT (480)
#define PIXEL_SIZE (2)

.set noat
.set noreorder
.set gp=64

LEAF(func_8021FAE0)
    PUSH(s0)
    PUSH(s1)
    PUSH(a3)

    # $a1 = K1_T0_K0(FrameBuffer) + (y * SCREEN_WIDTH + x) * PIXEL_SIZE
    li     s0, SCREEN_WIDTH * PIXEL_SIZE
    mult   a1, s0

    lw     a1, D_80249888

    li     s0, ~0x20000000
    and    a1, a1, s0

    add    a0, a0, a0
    add    a1, a1, a0

    mflo   s0
    add    a1, a1, s0

    # $a0 = ((x & 1) ? D_80218EC0 : D_80218EE4) + (ch - ' ') * 9 * sizeof(u32) * 2
    addi   a2, a2, -32
    add    a3, a2, a2
    add    a3, a3, a3

    sll    a2, a2, 5
    add    a2, a2, a3
    add    a2, a2, a2

    LI(s0, D_80218EE4)

    andi   a0, a0, (1 << 1)
    beqz   a0, 1f
     nop
    
    LI(s0, D_80218EC0)

1:
    add    a0, s0, a2
    
    # $s1 = colour
    POP(s1)

    NEXTW(s0, a0)

    jr     s0
     nop
END(func_8021FAE0)

LEAF(func_8021FB74)
    addi   a2, a2, -32
    add a3, a2, a2
    add a3, a3, a3

    PUSH(s0)
    PUSH(s1)
    PUSH(s2)
    PUSH(s3)
    PUSH(s4)
    PUSH(s5)
    PUSH(s6)
    PUSH(s7)

    li     s0, SCREEN_WIDTH * PIXEL_SIZE
    mult   a1, s0
    mflo   s0

    lw     a1, D_80249888

    add    a0, a0, a0
    add    a1, a1, s0
    add    a1, a1, a0

    LI(t9, D_80249868)
    ld     t9, 0(t9)

    andi   a2, a2, (~7 & 0xFFFF)

    li     v0, SCREEN_WIDTH * PIXEL_SIZE
    sub    v0, v0, a2
    sub    v0, v0, a2

    srl    a2, a2, 2

    LI(k0, jtbl_8021FC2C)
    andi   a0, a0, 3
    sll    a0, a0, 2
    add    k0, k0, a0
    lw     k0, 0(k0)

    LI(a0, D_8024A190)
    ld     a0, 0(a0)

    jr     k0
     addi  a2, a2, -1

# only needs to be exported for matching
EXPORT(jtbl_8021FC2C)
    .word label0
    .word label1
    .word label2
    .word label3

label0:
    MOVE(k0, a2)
    NEXTD(k1, a1)

    and    k1, k1, a0
    dsrl   k1, k1, 1
    or     k1, k1, t9
    sd     k1, -8(a1)

1:
    ld     k1, 0(a1)
    
    addi   k0, k0, -1
    
    and    k1, k1, a0
    dsrl   k1, k1, 1
    or     k1, k1, t9
    sd     k1, 0(a1)

    bnez   k0, 1b
     addi  a1, a1, 8
    
    addi   a3, a3, -1
    
    bnez   a3, label0
     add   a1, a1, v0
    
    POP(s7)
    POP(s6)
    POP(s5)
    POP(s4)
    POP(s3)
    POP(s2)
    POP(s1)
    POP(s0)

    jr     ra
     nop
    

label1:
    MOVE(k0, a2)
    NEXTH(k1, a1)

    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sh     k1, -2(a1)

    NEXTW(k1, a1)
    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sw     k1, -4(a1)

1:
    ld     k1, 0(a1)
    
    addi   k0, k0, -1
    
    and    k1, k1, a0
    dsrl   k1, k1, 1
    or     k1, k1, t9
    sd     k1, 0(a1)

    bnez   k0, 1b
     addi  a1, a1, 8
    
    lh     k1, 0(a1)
    addi   a3, a3, -1
    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sh     k1, 0(a1)
    addi   a1, a1, 2
    
    bnez   a3, label1
     add   a1, a1, v0
    
    POP(s7)
    POP(s6)
    POP(s5)
    POP(s4)
    POP(s3)
    POP(s2)
    POP(s1)
    POP(s0)

    jr     ra
     nop


label2:
    MOVE(k0, a2)
    NEXTW(k1, a1)

    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sw     k1, -4(a1)

1:
    ld     k1, 0(a1)

    addi   k0, k0, -1

    and    k1, k1, a0
    dsrl   k1, k1, 1
    or     k1, k1, t9
    sd     k1, 0(a1)

    bnez   k0, 1b
     addi  a1, a1, 8
    
    lw     k1, 0(a1)
    addi   a3, a3, -1
    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sw     k1, 0(a1)
    addi   a1, a1, 4
    bnez   a3, label2
     add   a1, a1, v0
    
    POP(s7)
    POP(s6)
    POP(s5)
    POP(s4)
    POP(s3)
    POP(s2)
    POP(s1)
    POP(s0)

    jr     ra
     nop

label3:
    MOVE(k0, a2)
    NEXTH(k1, a1)

    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sh     k1, -2(a1)

1:
    ld     k1, 0(a1)
    
    addi   k0, k0, -1
    
    and    k1, k1, a0
    dsrl   k1, k1, 1
    or     k1, k1, t9
    sd     k1, 0(a1)

    bnez   k0, 1b
     addi  a1, a1, 8
    
    lw     k1, 0(a1)
    addi   a1, a1, 4
    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sw     k1, -4(a1)

    lh     k1, 0(a1)
    addi   a3, a3, -1
    and    k1, k1, a0
    srl    k1, k1, 1
    or     k1, k1, t9
    sh     k1, 0(a1)
    addi   a1, a1, 2
    
    bnez   a3, label3
     add   a1, a1, v0
    
    POP(s7)
    POP(s6)
    POP(s5)
    POP(s4)
    POP(s3)
    POP(s2)
    POP(s1)
    POP(s0)

    jr     ra
     nop
END(func_8021FB74)

.set reorder
.set at