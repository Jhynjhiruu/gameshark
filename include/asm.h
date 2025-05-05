#ifndef _ASM_H
#define _ASM_H

/*
 * Copyright (c) 1995 Cygnus Support
 * Copyright (c) 2025 Jhynjhiruu
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

/* Standard MIPS register names: */
#define zero $0
#define z0 $0
#define AT $1
#define v0 $2
#define v1 $3
#define a0 $4
#define a1 $5
#define a2 $6
#define a3 $7
#define t0 $8
#define t1 $9
#define t2 $10
#define t3 $11
#define t4 $12
#define t5 $13
#define t6 $14
#define t7 $15
#define s0 $16
#define s1 $17
#define s2 $18
#define s3 $19
#define s4 $20
#define s5 $21
#define s6 $22
#define s7 $23
#define t8 $24
#define t9 $25
#define k0 $26 /* kernel private register 0 */
#define k1 $27 /* kernel private register 1 */
#define GP $28 /* global data pointer */
#define sp $29 /* stack-pointer */
#define fp $30 /* frame-pointer */
#define ra $31 /* return address */
#define pc $pc /* pc, used on mips16 */

#define fp0 $f0
#define fp1 $f1

/* Useful memory constants: */
#define K0BASE 0x80000000
#ifndef __mips64
#define K1BASE 0xA0000000
#define K0BASE_ADDR ((char *)K0BASE)
#define K1BASE_ADDR ((char *)K1BASE)
#else
#define K1BASE 0xFFFFFFFFA0000000LL
#define K0BASE_ADDR ((char *)0xFFFFFFFF80000000LL)
#define K1BASE_ADDR ((char *)K1BASE)
#endif

#ifdef __ASSEMBLER__
#define PHYS_TO_K0(a) a | K0BASE
#define PHYS_TO_K1(a) a | K1BASE
#define K0_TO_PHYS(a) a & 0x1FFFFFFF
#else
#define PHYS_TO_K0(a) ((unsigned)(a) | K0BASE)
#define PHYS_TO_K1(a) ((unsigned)(a) | K1BASE)
#define K0_TO_PHYS(a) ((unsigned)(a) & 0x1FFFFFFF)
#endif

/* Standard Co-Processor 0 registers */
#define C0_INX $0
#define C0_RAND $1
#define C0_ENTRYLO0 $2
#define C0_ENTRYLO1 $3
#define C0_CONTEXT $4
#define C0_PAGEMASK $5 /* Page mask */
#define C0_WIRED $6    /* # wired entries in tlb */
#define C0_BADVADDR $8
#define C0_COUNT $9      /* Timer Count Register */
#define C0_COMPARE $11   /* Timer Compare Register */
#define C0_SR $12        /* Status Register */
#define C0_CAUSE $13     /* last exception description */
#define C0_EPC $14       /* Exception error address */
#define C0_PRID $15      /* Processor Revision ID */
#define C0_CONFIG $16    /* CPU configuration */
#define C0_WATCHLO $18   /* Watchpoint */
#define C0_WATCHHI $19   /* Watchpoint */
#define C0_ECC $26       /* S-cache ECC and primary parity */
#define C0_CACHE_ERR $27 /* Cache error status */
#define C0_TAGLO $28     /* Cache operations */
#define C0_TAGHI $29     /* Cache operations */
#define C0_ERROR_EPC $30 /* ECC error prg. counter */

/* Standard Processor Revision ID Register field offsets */
#define PR_IMP 8

/* Standard Config Register field offsets */
#define CR_DB 4
#define CR_IB 5
#define CR_DC 6 /* NOTE v4121 semantics != 43,5xxx semantics */
#define CR_IC 9 /* NOTE v4121 semantics != 43,5xxx semantics */
#define CR_SC 17
#define CR_SS 20
#define CR_SB 22

/* Standard Status Register bitmasks: */
#define SR_CU1 0x20000000 /* Mark CP1 as usable */
#define SR_FR 0x04000000  /* Enable MIPS III FP registers */
#define SR_BEV 0x00400000 /* Controls location of exception vectors */
#define SR_PE 0x00100000  /* Mark soft reset (clear parity error) */

#define SR_KX 0x00000080 /* Kernel extended addressing enabled */
#define SR_SX 0x00000040 /* Supervisor extended addressing enabled */
#define SR_UX 0x00000020 /* User extended addressing enabled */

#define SR_ERL 0x00000004 /* Error level */
#define SR_EXL 0x00000002 /* Exception level */
#define SR_IE 0x00000001  /* Interrupts enabled */

/* Standard Cause Register bitmasks: */
#define CAUSE_EXC_MASK (0x1F << 2)
#define CAUSE_EXC_SYSCALL (8 << 2)
#define CAUSE_EXC_BREAKPOINT (9 << 2)
#define CAUSE_EXC_COPROCESSOR (11 << 2)

/* Standard (R4000) cache operations. Taken from "MIPS R4000
   Microprocessor User's Manual" 2nd edition: */

#define CACHE_I (0)  /* primary instruction */
#define CACHE_D (1)  /* primary data */
#define CACHE_SI (2) /* secondary instruction */
#define CACHE_SD (3) /* secondary data (or combined instruction/data) */

#define INDEX_INVALIDATE                                                       \
    (0) /* also encodes WRITEBACK if CACHE_D or CACHE_SD                       \
         */
#define INDEX_LOAD_TAG (1)
#define INDEX_STORE_TAG (2)
#define CREATE_DIRTY_EXCLUSIVE (3) /* CACHE_D and CACHE_SD only */
#define HIT_INVALIDATE (4)
#define CACHE_FILL (5)               /* CACHE_I only */
#define HIT_WRITEBACK_INVALIDATE (5) /* CACHE_D and CACHE_SD only */
#define HIT_WRITEBACK (6)            /* CACHE_I, CACHE_D and CACHE_SD only */
#define HIT_SET_VIRTUAL (7)          /* CACHE_SI and CACHE_SD only */

#define BUILD_CACHE_OP(o, c) (((o) << 2) | (c))

/* Individual cache operations: */
#define INDEX_INVALIDATE_I BUILD_CACHE_OP(INDEX_INVALIDATE, CACHE_I)
#define INDEX_WRITEBACK_INVALIDATE_D BUILD_CACHE_OP(INDEX_INVALIDATE, CACHE_D)
#define INDEX_INVALIDATE_SI BUILD_CACHE_OP(INDEX_INVALIDATE, CACHE_SI)
#define INDEX_WRITEBACK_INVALIDATE_SD BUILD_CACHE_OP(INDEX_INVALIDATE, CACHE_SD)

#define INDEX_LOAD_TAG_I BUILD_CACHE_OP(INDEX_LOAD_TAG, CACHE_I)
#define INDEX_LOAD_TAG_D BUILD_CACHE_OP(INDEX_LOAD_TAG, CACHE_D)
#define INDEX_LOAD_TAG_SI BUILD_CACHE_OP(INDEX_LOAD_TAG, CACHE_SI)
#define INDEX_LOAD_TAG_SD BUILD_CACHE_OP(INDEX_LOAD_TAG, CACHE_SD)

#define INDEX_STORE_TAG_I BUILD_CACHE_OP(INDEX_STORE_TAG, CACHE_I)
#define INDEX_STORE_TAG_D BUILD_CACHE_OP(INDEX_STORE_TAG, CACHE_D)
#define INDEX_STORE_TAG_SI BUILD_CACHE_OP(INDEX_STORE_TAG, CACHE_SI)
#define INDEX_STORE_TAG_SD BUILD_CACHE_OP(INDEX_STORE_TAG, CACHE_SD)

#define CREATE_DIRTY_EXCLUSIVE_D BUILD_CACHE_OP(CREATE_DIRTY_EXCLUSIVE, CACHE_D)
#define CREATE_DIRTY_EXCLUSIVE_SD                                              \
    BUILD_CACHE_OP(CREATE_DIRTY_EXCLUSIVE, CACHE_SD)

#define HIT_INVALIDATE_I BUILD_CACHE_OP(HIT_INVALIDATE, CACHE_I)
#define HIT_INVALIDATE_D BUILD_CACHE_OP(HIT_INVALIDATE, CACHE_D)
#define HIT_INVALIDATE_SI BUILD_CACHE_OP(HIT_INVALIDATE, CACHE_SI)
#define HIT_INVALIDATE_SD BUILD_CACHE_OP(HIT_INVALIDATE, CACHE_SD)

#define CACHE_FILL_I BUILD_CACHE_OP(CACHE_FILL, CACHE_I)
#define HIT_WRITEBACK_INVALIDATE_D                                             \
    BUILD_CACHE_OP(HIT_WRITEBACK_INVALIDATE, CACHE_D)
#define HIT_WRITEBACK_INVALIDATE_SD                                            \
    BUILD_CACHE_OP(HIT_WRITEBACK_INVALIDATE, CACHE_SD)

#define HIT_WRITEBACK_I BUILD_CACHE_OP(HIT_WRITEBACK, CACHE_I)
#define HIT_WRITEBACK_D BUILD_CACHE_OP(HIT_WRITEBACK, CACHE_D)
#define HIT_WRITEBACK_SD BUILD_CACHE_OP(HIT_WRITEBACK, CACHE_SD)

#define HIT_SET_VIRTUAL_SI BUILD_CACHE_OP(HIT_SET_VIRTUAL, CACHE_SI)
#define HIT_SET_VIRTUAL_SD BUILD_CACHE_OP(HIT_SET_VIRTUAL, CACHE_SD)

#define WATCH_WRITE (1 << 0)
#define WATCH_READ (1 << 1)
#define BUILD_WATCHLO(addr, op) K0_TO_PHYS(addr) | (op)
#define BUILD_WATCHHI(addr, op) 0

/* Useful macros: */
#ifdef __ASSEMBLER__
#define LEAF(x)                                                                \
    .globl x;                                                                  \
    .ent x, 0;                                                                 \
    x:;                                                                        \
    .frame sp, 0, ra

#define END(proc)                                                              \
    .end proc;                                                                 \
    .equ proc##_size, .- proc

#define EXPORT(x)                                                              \
    .globl x;                                                                  \
    x:

#define LA(reg, temp, addr)                                                    \
    lui temp, % hi(addr);                                                      \
    addiu reg, temp, % lo(addr);

#ifndef NON_MATCHING
#define LI(reg, val)                                                           \
    lui reg, % lo(val##_hi);                                                   \
    ori reg, reg, % lo(val);
#else
#define LI(reg, val) la reg, val;
#endif

#ifndef NON_MATCHING
#define LI_LOW(reg, val) ori reg, zero, val
#else
#define LI_LOW(reg, val) li reg, val
#endif

#define LOAD_RANGE(reg1, reg2, start, end, size)                               \
    lui reg1, % hi(start);                                                     \
    addiu reg2, reg1, % lo(end);                                               \
    addiu reg2, reg2, -size

#define PREV(reg, of, size, amt)                                               \
    addi of, of, -amt;                                                         \
    s##size reg, 0(of);

#define NEXT(reg, of, size, amt)                                               \
    l##size reg, 0(of);                                                        \
    addi of, of, amt;

#define PREVH(reg, of) PREV(reg, of, h, 2);
#define NEXTH(reg, of) NEXT(reg, of, h, 2);

#define PREVW(reg, of) PREV(reg, of, w, 4);
#define NEXTW(reg, of) NEXT(reg, of, w, 4);

#define PREVD(reg, of) PREV(reg, of, d, 8);
#define NEXTD(reg, of) NEXT(reg, of, d, 8);

#define PUSH(reg) PREVW(reg, sp);
#define POP(reg) NEXTW(reg, sp);

#define MOVE(dst, src) addi dst, src, 0;

#define MOVU(dst, src) addu dst, src, zero;

#endif

#endif