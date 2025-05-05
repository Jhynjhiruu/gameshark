#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)                                              \
    __asm__(".section .text\n"                                                 \
            "    .set noat\n"                                                  \
            "    .set noreorder\n"                                             \
            "    .globl " #NAME ".NON_MATCHING\n"                              \
            "    #.type " #NAME ".NON_MATCHING, @object\n"                     \
            "    " #NAME ".NON_MATCHING:\n"                                    \
            "    .include \"" FOLDER "/" #NAME ".s\"\n"                        \
            "    .set reorder\n"                                               \
            "    .set at\n")
#endif

#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)                                           \
    __asm__(".section .rdata\n"                                               \
            "    .include \"" FOLDER "/" #NAME ".s\"\n"                        \
            ".section .text")
#endif