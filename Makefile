# Make magic that needs to happen

.PHONY: all setup split allclean splitclean distclean

.DEFAULT: all

# Settings you might want to play with

COMPARE := 1

# Settings you probably shouldn't play with

BASE_NAME := loader

C_FILES := src/main.c src/hw.c src/lzari.c src/pi.c src/si.c src/libc.c src/led.c src/3650.c
S_FILES := src/header.s src/loader.s src/util.s src/except_redir.s
D_FILES := data/fsblob.fsblob.s
B_FILES := assets/boot.bin assets/cheats.bin

FSBLOB_FILES := fs/shell.bin fs/gslogo3.bin fs/gslogo3.pal fs/tile1.tg~ fs/trainer.bin

# Flags

KEYCODES := "7101:Mario World 64 & Others:80180000" "7103:Diddy, 1080, Banjo, Griffey:80201000" "7106:Yoshis, F-Zero, C'World:80200400" "7105:Zelda:80190000"

# Flags that change based on whether we're matching or not

ifeq ($(COMPARE),1)
	PATCHES := 1558:3C038004AFB00010 157C:8FBF0014 17BC:00431025 3054:008010213C0280048C4229F0 32BC:3C088000 34B8:240300028C820010 3644:03E0000827BD00182402009F 39FA:726C6F676F33 3A94:3084319F32C8338A349335A2 3AA8:45E046E148914CF4 3ACC:48914CF4 3B0A:75743C16B6E4 3B18:AF535B5226F6DB55 21268:6C
	FSBLOB_ARGS := --pad 0x2B4E0
	GSCRC_ARGS := -e 0x80200400
else
	PATCHES := 
	FSBLOB_ARGS := --pad 0x2B4E0
	GSCRC_ARGS := 
endif

# Rules

# Main rule + match check
all: compare

include Makefile.common

compare: $(BUILD_DIR)/GS.bin
ifeq ($(COMPARE),1)
	@sha1sum $<
	@sha1sum -c $(BASE_NAME).sha1
endif

$(BUILD_DIR)/GS.bin: $(BINARY)
	$(TOOLS_DIR)/$(GSCRC) $< $@ -o 0x2FC00 $(KEYCODES) $(GSCRC_ARGS)

# Setup repo
setup:
	$(MAKE) -C $(TOOLS_DIR) tools_setup

# Clean build
allclean:
	$(RM) -rf $(BUILD_DIR)

# Remove all split assets
allsplitclean:
	$(RM) -rf asm assets fs

# Clean everything
distclean: allclean allsplitclean
	$(MAKE) -C $(TOOLS_DIR) tools_clean

include $(TOOLS_DIR)/Makefile
