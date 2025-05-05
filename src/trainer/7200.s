.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

.globl func_80787A00
.ent func_80787A00
func_80787A00:
      addiu      $29, $29, -0x14
      sw         $31, 0x10($29)
      lui        $8, (0xBEC01000 >> 16)
      ori        $8, $8, (0xBEC01000 & 0xFFFF)
      lui        $9, (0x80000400 >> 16)
      ori        $9, $9, (0x80000400 & 0xFFFF)
      lui        $10, (0x3F000 >> 16)
      ori        $10, $10, (0x3F000 & 0xFFFF)
  .L80787A20:
      lw         $11, 0x0($8)
      addiu      $8, $8, 0x4
      sw         $11, 0x0($9)
      addiu      $10, $10, -0x4
      bnez       $10, .L80787A20
       addiu     $9, $9, 0x4
      jal        func_80787A58
       nop
      jal        func_800004A0
       nop
      lw         $31, 0x10($29)
      addiu      $29, $29, 0x14
      jr         $31
       nop
.end func_80787A00

.globl func_80787A58
.ent func_80787A58
func_80787A58:
      addiu      $29, $29, -0x1C
      sw         $8, 0x10($29)
      sw         $9, 0x14($29)
      sw         $1, 0x18($29)
      lui        $8, %hi(D_80003000)
      addiu      $9, $8, %lo(D_80003000)
      addiu      $9, $9, -0x10
  .L80787A74:
      cache      0x01, 0x0($8)
      sltu       $1, $8, $9
      bnez       $1, .L80787A74
       addiu     $8, $8, (0x80000010 & 0xFFFF)
      lui        $8, %hi(D_80006000)
      addiu      $9, $8, %lo(D_80006000)
      addiu      $9, $9, -0x20
  .L80787A90:
      cache      0x00, 0x0($8)
      sltu       $1, $8, $9
      bnez       $1, .L80787A90
       addiu     $8, $8, (0x80000020 & 0xFFFF)
      lw         $8, 0x10($29)
      lw         $9, 0x14($29)
      lw         $1, 0x18($29)
      jr         $31
       addiu     $29, $29, 0x1C
.end func_80787A58

.globl func_80787AB4
.ent func_80787AB4
func_80787AB4:
      cache      0x15, 0x0($4)
      jr         $31
       nop
.end func_80787AB4

.globl func_80787AC0
.ent func_80787AC0
func_80787AC0:
      jr         $4
       nop
      addiu      $29, $29, -0x14
      sw         $31, 0x10($29)
      jalr       $4
       nop
      lw         $31, 0x10($29)
      addiu      $29, $29, 0x14
      jr         $31
       nop
.end func_80787AC0

.globl func_80787AE8
.ent func_80787AE8
func_80787AE8:
      mfc0       $2, $12
      jr         $31
       nop
.end func_80787AE8

.globl func_80787AF4
.ent func_80787AF4
func_80787AF4:
      mtc0       $4, $12
      jr         $31
       nop
.end func_80787AF4

.globl func_80787B00
.ent func_80787B00
func_80787B00:
      mfc0       $2, $13
      jr         $31
       nop
.end func_80787B00

.globl func_80787B0C
.ent func_80787B0C
func_80787B0C:
      mfc0       $2, $14
      jr         $31
       nop
.end func_80787B0C

.globl func_80787B18
.ent func_80787B18
func_80787B18:
      addiu      $29, $29, -0x1C
      sw         $31, 0x10($29)
      sw         $8, 0x14($29)
      sw         $9, 0x18($29)
      lui        $8, %hi(D_80787B44)
      addiu      $8, $8, %lo(D_80787B44)
      lui        $9, (0x40850000 >> 16)
      or         $9, $9, $4
      sw         $9, 0x0($8)
      jal        func_80787A58
       nop
  glabel D_80787B44
D_80787B44:
      mtc0       $5, $0
      lw         $9, 0x18($29)
      lw         $8, 0x14($29)
      lw         $31, 0x10($29)
      addiu      $29, $29, 0x1C
      jr         $31
       nop
.end func_80787B18

.globl func_80787B60
.ent func_80787B60
func_80787B60:
      addiu      $29, $29, -0x1C
      sw         $31, 0x10($29)
      sw         $8, 0x14($29)
      sw         $9, 0x18($29)
      lui        $8, %hi(D_80787B8C)
      addiu      $8, $8, %lo(D_80787B8C)
      lui        $9, (0x40020000 >> 16)
      or         $9, $9, $4
      sw         $9, 0x0($8)
      jal        func_80787A58
       nop
  glabel D_80787B8C
D_80787B8C:
      mfc0       $2, $0
      lw         $9, 0x18($29)
      lw         $8, 0x14($29)
      lw         $31, 0x10($29)
      addiu      $29, $29, 0x1C
      jr         $31
       nop
.end func_80787B60
