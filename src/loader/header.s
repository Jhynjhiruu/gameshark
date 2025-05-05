.section .data

.word 0x80371240       /* PI BSB Domain 1 register */
.word 0x0000000F       /* Clockrate setting */
.word entrypoint       /* Entrypoint address */
.word 0x00001444       /* Revision */
.word 0xEA6D5BF8       /* Checksum 1 */
.word 0xE2B4696C       /* Checksum 2 */
.word 0x00000000       /* Unknown 1 */
.word 0x00000000       /* Unknown 2 */
.ascii "(C) MUSHROOM &NU" /* Internal name */
.ascii "15:56 Apr 4 " /* Build date */
.word 0x08D02702       /* Unknown 4 */
