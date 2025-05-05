.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* Handwritten function */
.globl func_80784940
.ent func_80784940
func_80784940:
      addi       $29, $29, -0x4
      sw         $16, 0x0($29)
      addi       $29, $29, -0x4
      sw         $17, 0x0($29)
      addi       $29, $29, -0x4
      sw         $18, 0x0($29)
      addi       $29, $29, -0x4
      sw         $19, 0x0($29)
      addi       $29, $29, -0x4
      sw         $20, 0x0($29)
      addi       $29, $29, -0x4
      sw         $21, 0x0($29)
      addi       $29, $29, -0x4
      sw         $22, 0x0($29)
      addi       $29, $29, -0x4
      sw         $23, 0x0($29)
      addiu      $2, $0, 0x140
      sub        $2, $2, $6
      sub        $2, $2, $4
      bgez       $2, .L80784998
       nop
      add        $6, $6, $2
  .L80784998:
      and        $4, $4, $4
      bgez       $4, .L807849AC
       nop
      add        $6, $6, $4
      xor        $4, $4, $4
  .L807849AC:
      addiu      $2, $0, 0xF0
      sub        $2, $2, $7
      sub        $2, $2, $5
      bgez       $2, .L807849C4
       nop
      add        $7, $7, $2
  .L807849C4:
      and        $5, $5, $5
      bgez       $5, .L807849D8
       nop
      add        $7, $7, $5
      xor        $5, $5, $5
  .L807849D8:
      blez       $6, .L80784D58
       nop
      blez       $7, .L80784D58
       nop
      addiu      $16, $0, 0x280
      mult       $5, $16
      mflo       $16
      lui        $27, %hi(D_8079B238)
      lw         $27, %lo(D_8079B238)($27)
      add        $27, $27, $16
      add        $27, $27, $4
      add        $27, $27, $4
      lui        $2, (0x80784A44 >> 16)
      ori        $2, $2, (0x80784A44 & 0xFFFF)
      andi       $4, $4, 0x3
      sll        $4, $4, 2
      add        $2, $2, $4
      addi       $5, $6, 0x0
      lui        $4, (0x8079B228 >> 16)
      ori        $4, $4, (0x8079B228 & 0xFFFF)
      ld         $4, 0x0($4)
      andi       $6, $6, 0xFFFC
      beqz       $6, .L80784D24
       nop
      lw         $2, 0x0($2)
      jr         $2
       nop
      lb         $24, 0x4A54($3)
      lb         $24, 0x4AF0($3)
      lb         $24, 0x4BBC($3)
      lb         $24, 0x4C70($3)
      addi       $5, $5, 0x0
  .L80784A58:
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80784A7C
  .L80784A6C:
       addi      $6, $6, -0x1
      sd         $4, 0x0($27)
      bnez       $6, .L80784A6C
       addi      $27, $27, 0x8
  .L80784A7C:
      andi       $6, $5, 0x3
      beqz       $6, .L80784A94
  .L80784A84:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784A84
       addi      $27, $27, 0x2
  .L80784A94:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      bnez       $7, .L80784A58
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
      addi       $5, $5, -0x3
  .L80784AF4:
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addiu      $6, $0, 0x1
      beqz       $6, .L80784B14
  .L80784B04:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784B04
       addi      $27, $27, 0x2
  .L80784B14:
      addiu      $6, $0, 0x1
      beqz       $6, .L80784B2C
  .L80784B1C:
       addi      $6, $6, -0x1
      sw         $4, 0x0($27)
      bnez       $6, .L80784B1C
       addi      $27, $27, 0x4
  .L80784B2C:
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80784B48
  .L80784B38:
       addi      $6, $6, -0x1
      sd         $4, 0x0($27)
      bnez       $6, .L80784B38
       addi      $27, $27, 0x8
  .L80784B48:
      andi       $6, $5, 0x3
      beqz       $6, .L80784B60
  .L80784B50:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784B50
       addi      $27, $27, 0x2
  .L80784B60:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      bnez       $7, .L80784AF4
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
      addi       $5, $5, -0x2
  .L80784BC0:
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addiu      $6, $0, 0x1
      beqz       $6, .L80784BE0
  .L80784BD0:
       addi      $6, $6, -0x1
      sw         $4, 0x0($27)
      bnez       $6, .L80784BD0
       addi      $27, $27, 0x4
  .L80784BE0:
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80784BFC
  .L80784BEC:
       addi      $6, $6, -0x1
      sd         $4, 0x0($27)
      bnez       $6, .L80784BEC
       addi      $27, $27, 0x8
  .L80784BFC:
      andi       $6, $5, 0x3
      beqz       $6, .L80784C14
  .L80784C04:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784C04
       addi      $27, $27, 0x2
  .L80784C14:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      bnez       $7, .L80784BC0
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
      addi       $5, $5, -0x1
  .L80784C74:
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addiu      $6, $0, 0x1
      beqz       $6, .L80784C94
  .L80784C84:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784C84
       addi      $27, $27, 0x2
  .L80784C94:
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80784CB0
  .L80784CA0:
       addi      $6, $6, -0x1
      sd         $4, 0x0($27)
      bnez       $6, .L80784CA0
       addi      $27, $27, 0x8
  .L80784CB0:
      andi       $6, $5, 0x3
      beqz       $6, .L80784CC8
  .L80784CB8:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784CB8
       addi      $27, $27, 0x2
  .L80784CC8:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      bnez       $7, .L80784C74
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
  .L80784D24:
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addi       $6, $5, 0x0
      beqz       $6, .L80784D44
  .L80784D34:
       addi      $6, $6, -0x1
      sh         $4, 0x0($27)
      bnez       $6, .L80784D34
       addi      $27, $27, 0x2
  .L80784D44:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      bnez       $7, .L80784D24
       addi      $27, $27, 0x280
  .L80784D58:
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
.end func_80784940

/* Handwritten function */
.globl func_80784DA0
.ent func_80784DA0
func_80784DA0:
      addi       $29, $29, -0x4
      sw         $16, 0x0($29)
      addi       $29, $29, -0x4
      sw         $17, 0x0($29)
      addi       $29, $29, -0x4
      sw         $18, 0x0($29)
      addi       $29, $29, -0x4
      sw         $19, 0x0($29)
      addi       $29, $29, -0x4
      sw         $20, 0x0($29)
      addi       $29, $29, -0x4
      sw         $21, 0x0($29)
      addi       $29, $29, -0x4
      sw         $22, 0x0($29)
      addi       $29, $29, -0x4
      sw         $23, 0x0($29)
      addiu      $2, $0, 0x140
      sub        $2, $2, $6
      sub        $2, $2, $4
      bgez       $2, .L80784DF8
       nop
      add        $6, $6, $2
  .L80784DF8:
      and        $4, $4, $4
      bgez       $4, .L80784E0C
       nop
      add        $6, $6, $4
      xor        $4, $4, $4
  .L80784E0C:
      addiu      $2, $0, 0xF0
      sub        $2, $2, $7
      sub        $2, $2, $5
      bgez       $2, .L80784E24
       nop
      add        $7, $7, $2
  .L80784E24:
      and        $5, $5, $5
      bgez       $5, .L80784E38
       nop
      add        $7, $7, $5
      xor        $5, $5, $5
  .L80784E38:
      blez       $6, .L807852FC
       nop
      blez       $7, .L807852FC
       nop
      addiu      $16, $0, 0x280
      mult       $5, $16
      mflo       $16
      lui        $27, %hi(D_8079B238)
      lw         $27, %lo(D_8079B238)($27)
      add        $27, $27, $16
      add        $27, $27, $4
      add        $27, $27, $4
      addu       $26, $27, $0
      lui        $2, (0xDFFFFFFF >> 16)
      ori        $2, $2, (0xDFFFFFFF & 0xFFFF)
      and        $26, $26, $2
      lui        $2, (0x80784EB4 >> 16) # D_80784EB4
      ori        $2, $2, (0x80784EB4 & 0xFFFF)
      andi       $4, $4, 0x3
      sll        $4, $4, 2
      add        $4, $4, $2
      lw         $4, 0x0($4)
      addi       $5, $6, 0x0
      lui        $2, (0x8079B300 >> 16)
      ori        $2, $2, (0x8079B300 & 0xFFFF)
      ld         $2, 0x0($2)
      andi       $6, $6, 0xFFFC
      beqz       $6, .L807852A4
       nop
      jr         $4
       nop
# D_80784EB4:
      lb         $24, 0x4EC4($3)
      lb         $24, 0x4F94($3)
      lb         $24, 0x50B4($3)
      lb         $24, 0x51AC($3)
      addi       $5, $5, 0x0
  .L80784EC8:
      addi       $29, $29, -0x4
      sw         $26, 0x0($29)
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80784F04
  .L80784EE4:
       addi      $6, $6, -0x1
      ld         $4, 0x0($26)
      and        $4, $4, $2
      dsrl       $4, $4, 1
      sd         $4, 0x0($27)
      addi       $26, $26, 0x8
      bnez       $6, .L80784EE4
       addi      $27, $27, 0x8
  .L80784F04:
      andi       $6, $5, 0x3
      beqz       $6, .L80784F2C
  .L80784F0C:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L80784F0C
       addi      $27, $27, 0x2
  .L80784F2C:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      lw         $26, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      addi       $26, $26, 0x280
      bnez       $7, .L80784EC8
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
      addi       $5, $5, -0x3
  .L80784F98:
      addi       $29, $29, -0x4
      sw         $26, 0x0($29)
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addiu      $6, $0, 0x1
      beqz       $6, .L80784FD0
  .L80784FB0:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L80784FB0
       addi      $27, $27, 0x2
  .L80784FD0:
      addiu      $6, $0, 0x1
      beqz       $6, .L80784FF8
  .L80784FD8:
       addi      $6, $6, -0x1
      lw         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sw         $4, 0x0($27)
      addi       $26, $26, 0x4
      bnez       $6, .L80784FD8
       addi      $27, $27, 0x4
  .L80784FF8:
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80785024
  .L80785004:
       addi      $6, $6, -0x1
      ld         $4, 0x0($26)
      and        $4, $4, $2
      dsrl       $4, $4, 1
      sd         $4, 0x0($27)
      addi       $26, $26, 0x8
      bnez       $6, .L80785004
       addi      $27, $27, 0x8
  .L80785024:
      andi       $6, $5, 0x3
      beqz       $6, .L8078504C
  .L8078502C:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L8078502C
       addi      $27, $27, 0x2
  .L8078504C:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      lw         $26, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      addi       $26, $26, 0x280
      bnez       $7, .L80784F98
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
      addi       $5, $5, -0x2
  .L807850B8:
      addi       $29, $29, -0x4
      sw         $26, 0x0($29)
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addiu      $6, $0, 0x1
      beqz       $6, .L807850F0
  .L807850D0:
       addi      $6, $6, -0x1
      lw         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sw         $4, 0x0($27)
      addi       $26, $26, 0x4
      bnez       $6, .L807850D0
       addi      $27, $27, 0x4
  .L807850F0:
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L8078511C
  .L807850FC:
       addi      $6, $6, -0x1
      ld         $4, 0x0($26)
      and        $4, $4, $2
      dsrl       $4, $4, 1
      sd         $4, 0x0($27)
      addi       $26, $26, 0x8
      bnez       $6, .L807850FC
       addi      $27, $27, 0x8
  .L8078511C:
      andi       $6, $5, 0x3
      beqz       $6, .L80785144
  .L80785124:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L80785124
       addi      $27, $27, 0x2
  .L80785144:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      lw         $26, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      addi       $26, $26, 0x280
      bnez       $7, .L807850B8
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
      addi       $5, $5, -0x1
  .L807851B0:
      addi       $29, $29, -0x4
      sw         $26, 0x0($29)
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addiu      $6, $0, 0x1
      beqz       $6, .L807851E8
  .L807851C8:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L807851C8
       addi      $27, $27, 0x2
  .L807851E8:
      addi       $6, $5, 0x0
      srl        $6, $6, 2
      beqz       $6, .L80785214
  .L807851F4:
       addi      $6, $6, -0x1
      ld         $4, 0x0($26)
      and        $4, $4, $2
      dsrl       $4, $4, 1
      sd         $4, 0x0($27)
      addi       $26, $26, 0x8
      bnez       $6, .L807851F4
       addi      $27, $27, 0x8
  .L80785214:
      andi       $6, $5, 0x3
      beqz       $6, .L8078523C
  .L8078521C:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L8078521C
       addi      $27, $27, 0x2
  .L8078523C:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      lw         $26, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      addi       $26, $26, 0x280
      bnez       $7, .L807851B0
       addi      $27, $27, 0x280
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
  .L807852A4:
      addi       $29, $29, -0x4
      sw         $26, 0x0($29)
      addi       $29, $29, -0x4
      sw         $27, 0x0($29)
      addi       $6, $5, 0x0
      beqz       $6, .L807852DC
  .L807852BC:
       addi      $6, $6, -0x1
      lh         $4, 0x0($26)
      and        $4, $4, $2
      srl        $4, $4, 1
      sh         $4, 0x0($27)
      addi       $26, $26, 0x2
      bnez       $6, .L807852BC
       addi      $27, $27, 0x2
  .L807852DC:
      lw         $27, 0x0($29)
      addi       $29, $29, 0x4
      lw         $26, 0x0($29)
      addi       $29, $29, 0x4
      addi       $7, $7, -0x1
      addi       $26, $26, 0x280
      bnez       $7, .L807852A4
       addi      $27, $27, 0x280
  .L807852FC:
      lw         $23, 0x0($29)
      addi       $29, $29, 0x4
      lw         $22, 0x0($29)
      addi       $29, $29, 0x4
      lw         $21, 0x0($29)
      addi       $29, $29, 0x4
      lw         $20, 0x0($29)
      addi       $29, $29, 0x4
      lw         $19, 0x0($29)
      addi       $29, $29, 0x4
      lw         $18, 0x0($29)
      addi       $29, $29, 0x4
      lw         $17, 0x0($29)
      addi       $29, $29, 0x4
      lw         $16, 0x0($29)
      addi       $29, $29, 0x4
      jr         $31
       nop
.end func_80784DA0

.globl func_80785344
.ent func_80785344
func_80785344:
      sw         $2, 0x8($10)
      addiu      $2, $0, 0x20D
      sw         $4, 0x14($10)
      sll        $6, $6, 11
      sll        $7, $7, 6
      or         $6, $6, $7
      lui        $3, %hi(D_8079B238)
      lw         $2, 0x10($29)
      lw         $3, %lo(D_8079B238)($3)
      sll        $2, $2, 1
      or         $6, $6, $2
      sll        $2, $5, 2
      addu       $2, $2, $5
      sll        $2, $2, 6
      addu       $2, $2, $4
      sll        $2, $2, 1
      addu       $2, $2, $3
      jr         $31
       sh        $6, 0x0($2)
.end func_80785344
