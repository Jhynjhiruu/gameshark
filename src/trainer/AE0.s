.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* Handwritten function */
.globl func_807812E0
.ent func_807812E0
func_807812E0:
      lw         $15, 0x10($29)
      sll        $15, $15, 1
      addi       $7, $7, -0x1
  .L807812EC:
      addu       $8, $4, $0
      add        $4, $4, $15
      addu       $9, $5, $0
      addi       $5, $5, 0x280
      addu       $10, $6, $0
  .L80781300:
      lh         $2, 0x0($8)
      addi       $8, $8, 0x2
      beqz       $2, .L80781314
       addi      $10, $10, -0x1
      sh         $2, 0x0($9)
  .L80781314:
      bnez       $10, .L80781300
       addi      $9, $9, 0x2
      bnez       $7, .L807812EC
       addi      $7, $7, -0x1
      jr         $31
       nop
.end func_807812E0

/* Handwritten function */
.globl func_8078132C
.ent func_8078132C
func_8078132C:
      addi       $29, $29, -0x4
      sw         $16, 0x0($29)
      addi       $29, $29, -0x4
      sw         $17, 0x0($29)
      addi       $29, $29, -0x4
      sw         $22, 0x0($29)
      addi       $29, $29, -0x4
      sw         $23, 0x0($29)
      addiu      $16, $0, 0x500
      mult       $5, $16
      mflo       $16
      lui        $5, %hi(D_8079B238)
      lw         $5, %lo(D_8079B238)($5)
      addiu      $22, $0, 0x2F
      add        $5, $5, $16
      add        $4, $4, $4
      add        $5, $5, $4
      lui        $16, (0xDFFFFFF8 >> 16)
      ori        $16, $16, (0xDFFFFFF8 & 0xFFFF)
      and        $6, $6, $16
  .L8078137C:
      ld         $16, 0x0($6)
      ld         $17, 0x8($6)
      sd         $16, 0x0($5)
      ld         $16, 0x10($6)
      sd         $17, 0x8($5)
      ld         $17, 0x18($6)
      sd         $16, 0x10($5)
      ld         $16, 0x20($6)
      sd         $17, 0x18($5)
      ld         $17, 0x28($6)
      sd         $16, 0x20($5)
      ld         $16, 0x30($6)
      sd         $17, 0x28($5)
      ld         $17, 0x38($6)
      sd         $16, 0x30($5)
      ld         $16, 0x40($6)
      sd         $17, 0x38($5)
      ld         $17, 0x48($6)
      sd         $16, 0x40($5)
      ld         $16, 0x50($6)
      sd         $17, 0x48($5)
      ld         $17, 0x58($6)
      sd         $16, 0x50($5)
      ld         $16, 0x60($6)
      sd         $17, 0x58($5)
      ld         $17, 0x68($6)
      sd         $16, 0x60($5)
      ld         $16, 0x70($6)
      sd         $17, 0x68($5)
      ld         $17, 0x78($6)
      sd         $16, 0x70($5)
      sd         $17, 0x78($5)
      addi       $5, $5, 0x500
      addi       $6, $6, 0x80
      bnez       $22, .L8078137C
       addi      $22, $22, -0x1
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
.end func_8078132C
