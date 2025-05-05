.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* Handwritten function */
.globl func_80794A80
.ent func_80794A80
func_80794A80:
      lui        $8, (0xA0000180 >> 16)
      ori        $8, $8, (0xA0000180 & 0xFFFF)
      lui        $9, %hi(func_80794ADC)
      addiu      $9, $9, %lo(func_80794ADC)
      lw         $10, 0x0($9)
      nop
      sw         $10, 0x0($8)
      lw         $10, 0x4($9)
      nop
      sw         $10, 0x4($8)
      lw         $10, 0x8($9)
      nop
      sw         $10, 0x8($8)
      lw         $10, 0xC($9)
      nop
      sw         $10, 0xC($8)
      addiu      $8, $0, 0x181
      mtc0       $8, $18
      nop
      mtc0       $0, $19
      nop
      jr         $31
       nop
.end func_80794A80

/* Handwritten function */
.globl func_80794ADC
.ent func_80794ADC
func_80794ADC:
      lui        $26, %hi(D_80794AEC)
      addiu      $26, $26, %lo(D_80794AEC)
      jr         $26
       nop
  glabel D_80794AEC
D_80794AEC:
      mfc0       $26, $13
      ori        $27, $0, 0x5C
      andi       $26, $26, 0x7C
      beq        $26, $27, .L80794B30
       nop
      bnez       $26, .L80794B20
       nop
      lui        $26, %hi(D_A4300008)
      lw         $26, %lo(D_A4300008)($26)
      nop
      andi       $27, $26, 0x2
      bnez       $27, .L80794B28
       nop
  .L80794B20:
      j          func_80000120
       nop
  .L80794B28:
      j          .L80794B40
       nop
  .L80794B30:
      lui        $26, (0xBEC2F000 >> 16)
      ori        $26, $26, (0xBEC2F000 & 0xFFFF)
      jr         $26
       nop
  .L80794B40:
      lui        $26, %hi(func_80794A44 + 0x2C)
      addiu      $26, $26, %lo(func_80794A44 + 0x2C)
      sw         $29, 0x0($26)
      lui        $29, (0x807FFF00 >> 16)
      ori        $29, $29, (0x807FFF00 & 0xFFFF)
      addiu      $29, $29, -0x4C
      sw         $31, 0x10($29)
      sw         $2, 0x14($29)
      sw         $3, 0x18($29)
      sw         $4, 0x1C($29)
      sw         $5, 0x20($29)
      sw         $6, 0x24($29)
      sw         $7, 0x28($29)
      sw         $8, 0x2C($29)
      sw         $9, 0x30($29)
      sw         $10, 0x34($29)
      sw         $11, 0x38($29)
      sw         $12, 0x3C($29)
      sw         $13, 0x40($29)
      sw         $14, 0x44($29)
      sw         $15, 0x48($29)
      jal        func_80793870
       nop
      beq        $0, $2, .L80794BB4
       nop
      mtc0       $0, $9
      nop
      mtc0       $0, $11
      nop
  .L80794BB4:
      lui        $26, %hi(D_8079A080)
      addiu      $26, $26, %lo(D_8079A080)
      lw         $27, 0x0($26)
      bnez       $27, .L80794BD0
       nop
      jal        func_80794C40
       nop
  .L80794BD0:
      lw         $31, 0x10($29)
      lw         $2, 0x14($29)
      lw         $3, 0x18($29)
      lw         $4, 0x1C($29)
      lw         $5, 0x20($29)
      lw         $6, 0x24($29)
      lw         $7, 0x28($29)
      lw         $8, 0x2C($29)
      lw         $9, 0x30($29)
      lw         $10, 0x34($29)
      lw         $11, 0x38($29)
      lw         $12, 0x3C($29)
      lw         $13, 0x40($29)
      lw         $14, 0x44($29)
      lw         $15, 0x48($29)
      addiu      $29, $29, 0x6C
      lui        $26, %hi(func_80794A44 + 0x2C)
      addiu      $26, $26, %lo(func_80794A44 + 0x2C)
      lw         $29, 0x0($26)
      lui        $26, %hi(D_8079A080)
      addiu      $26, $26, %lo(D_8079A080)
      lw         $27, 0x0($26)
      bnez       $27, .L80794C38
       nop
      j          func_807C5C00
       nop
  .L80794C38:
      j          func_80000120
       nop
  glabel func_80794C40
func_80794C40:
      addiu      $29, $29, -0x14
      sw         $4, 0x0($29)
      sw         $5, 0x4($29)
      sw         $6, 0x8($29)
      sw         $7, 0xC($29)
      sw         $14, 0x10($29)
      lui        $4, %hi(D_8078040C)
      lw         $4, %lo(D_8078040C)($4)
      lw         $7, 0x0($4)
      beqz       $7, .L80794D08
  .L80794C68:
       lwl       $5, 0x4($4)
      lwr        $5, 0x7($4)
      lui        $26, (0xD0000000 >> 16)
      and        $27, $5, $26
      bne        $27, $26, .L80794CD8
       lh        $6, 0x8($4)
      lui        $26, (0x1000000 >> 16)
      and        $27, $5, $26
      lui        $26, (0x80FFFFFF >> 16)
      ori        $26, $26, (0x80FFFFFF & 0xFFFF)
      bgtz       $27, .L80794CA0
       and       $5, $5, $26
      beq        $27, $27, .L80794CA4
       lb        $14, 0x0($5)
  .L80794CA0:
      lh         $14, 0x0($5)
  .L80794CA4:
      lui        $26, (0x2000000 >> 16)
      and        $27, $5, $26
      beq        $27, $26, .L80794CC4
       nop
      beq        $14, $6, .L80794CFC
       nop
      beq        $27, $27, .L80794CCC
       nop
  .L80794CC4:
      bne        $14, $6, .L80794CFC
       nop
  .L80794CCC:
      addi       $7, $7, -0x1
      beq        $27, $27, .L80794CFC
       addi      $4, $4, 0x6
  .L80794CD8:
      lui        $26, (0x1000000 >> 16)
      and        $27, $5, $26
      lui        $26, (0x80FFFFFF >> 16)
      ori        $26, $26, (0x80FFFFFF & 0xFFFF)
      bgtz       $27, .L80794CF8
       and       $5, $5, $26
      beq        $27, $27, .L80794CFC
       sb        $6, 0x0($5)
  .L80794CF8:
      sh         $6, 0x0($5)
  .L80794CFC:
      addi       $7, $7, -0x1
      bgtz       $7, .L80794C68
       addi      $4, $4, 0x6
  .L80794D08:
      lw         $4, 0x0($29)
      lw         $5, 0x4($29)
      lw         $6, 0x8($29)
      lw         $7, 0xC($29)
      lw         $14, 0x10($29)
      addiu      $29, $29, 0x14
      jr         $31
       nop
      lui        $26, %hi(D_3FFFF)
  .L80794D2C:
      lw         $7, 0x0($5)
      nop
      sw         $7, 0x0($4)
      addi       $4, $4, 0x4
      addi       $5, $5, 0x4
      addiu      $26, $26, %lo(D_3FFFF)
      bgtz       $26, .L80794D2C
       nop
      lui        $8, %hi(D_80003000)
      addiu      $9, $8, %lo(D_80003000)
      addiu      $9, $9, -0x10
  .L80794D58:
      cache      0x01, 0x0($8)
      sltu       $1, $8, $9
      bnez       $1, .L80794D58
       addiu     $8, $8, (0x80000010 & 0xFFFF)
      lui        $8, %hi(D_80006000)
      addiu      $9, $8, %lo(D_80006000)
      addiu      $9, $9, -0x20
  .L80794D74:
      cache      0x00, 0x0($8)
      sltu       $1, $8, $9
      bnez       $1, .L80794D74
       addiu     $8, $8, (0x80000020 & 0xFFFF)
      jr         $6
       nop
      lui        $4, (0x800002C0 >> 16)
      ori        $4, $4, (0x800002C0 & 0xFFFF)
      addiu      $5, $0, 0x1
      sw         $5, 0x0($4)
      lui        $5, (0x810BA3DC >> 16)
      ori        $5, $5, (0x810BA3DC & 0xFFFF)
      sw         $5, 0x4($4)
      addiu      $5, $0, 0x3F80
      sh         $5, 0x8($4)
      jr         $31
       nop
      daddiu     $18, $11, 0x6E20
      ldl        $14, 0x7420($11)
.end func_80794ADC
