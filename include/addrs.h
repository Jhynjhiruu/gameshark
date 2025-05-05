#ifndef _ADDRS_H
#define _ADDRS_H

#define STACK_TOP (0x80400000 - 0x100)

#define UNK_ADDR (0x80600000)

#define REDIR_INT_HANDLER (0x120)
#define INT_HANDLER (0x180)
#define ALT_EXCEPT_REDIR_TRAMPOLINE (0x190)
#define UNK_POINTER (0x200)
#define CODE_HANDLER (0x204)
#define ALT_INT_HANDLER (0x2C0)

#define BOOT_BASE (0x10)
#define RUN_BASE (0x1E)

#define FIRMWARE_PASSTHROUGH (0xC00000)

// should match data_ROM_START
#define EXCEPT_REDIR_PADDR (0x2F000)
#define EXCEPT_REDIR_VADDR                                                     \
    ((RUN_BASE << 24) | FIRMWARE_PASSTHROUGH | EXCEPT_REDIR_PADDR)

#endif