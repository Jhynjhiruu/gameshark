SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    main_ROM_START = __romPos;
    main_VRAM = ADDR(.main);
    .main 0x80200400 : AT(main_ROM_START) SUBALIGN(16)
    {
        main_TEXT_START = .;
        build/us/src/main.c.o(.text);
        build/us/src/540.c.o(.text);
        build/us/src/2CA0.c.o(.text);
        build/us/src/5050.c.o(.text);
        build/us/src/ai.c.o(.text);
        build/us/src/5E30.c.o(.text);
        build/us/src/6380.c.o(.text);
        build/us/src/scousers.c.o(.text);
        build/us/src/7D60.c.o(.text);
        build/us/src/D880.c.o(.text);
        build/us/src/DF40.c.o(.text);
        build/us/src/FED0.c.o(.text);
        build/us/src/109A0.c.o(.text);
        build/us/src/155D0.c.o(.text);
        build/us/src/17280.c.o(.text);
        build/us/src/17810.c.o(.text);
        build/us/src/17990.c.o(.text);
        build/us/src/17A50.c.o(.text);
        build/us/src/17F00.c.o(.text);
        build/us/asm/us/18410.s.o(.text);
        build/us/src/20CD0.c.o(.text);
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_DATA_START = .;
        main_c = .;
        build/us/src/main.c.o(.data);
        _540_c = .;
        build/us/src/540.c.o(.data);
        _2CA0_c = .;
        build/us/src/2CA0.c.o(.data);
        _5050_c = .;
        build/us/src/5050.c.o(.data);
        ai_c = .;
        build/us/src/ai.c.o(.data);
        _5E30_c = .;
        build/us/src/5E30.c.o(.data);
        _6380_c = .;
        build/us/src/6380.c.o(.data);
        scousers_c = .;
        build/us/src/scousers.c.o(.data);
        _7D60_c = .;
        build/us/src/7D60.c.o(.data);
        D880_c = .;
        build/us/src/D880.c.o(.data);
        DF40_c = .;
        build/us/src/DF40.c.o(.data);
        FED0_c = .;
        build/us/src/FED0.c.o(.data);
        _109A0_c = .;
        build/us/src/109A0.c.o(.data);
        _155D0_c = .;
        build/us/src/155D0.c.o(.data);
        _17280_c = .;
        build/us/src/17280.c.o(.data);
        _17810_c = .;
        build/us/src/17810.c.o(.data);
        _17990_c = .;
        build/us/src/17990.c.o(.data);
        _17A50_c = .;
        build/us/src/17A50.c.o(.data);
        _17F00_c = .;
        build/us/src/17F00.c.o(.data);
        _18410_s = .;
        build/us/asm/us/18410.s.o(.data);
        _20CD0_c = .;
        build/us/src/20CD0.c.o(.data);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
        main_RODATA_START = .;
        build/us/src/main.c.o(.rodata);
        build/us/src/540.c.o(.rodata);
        build/us/src/2CA0.c.o(.rodata);
        build/us/src/5050.c.o(.rodata);
        build/us/src/ai.c.o(.rodata);
        build/us/src/5E30.c.o(.rodata);
        build/us/src/6380.c.o(.rodata);
        build/us/src/scousers.c.o(.rodata);
        build/us/src/7D60.c.o(.rodata);
        build/us/src/D880.c.o(.rodata);
        build/us/src/DF40.c.o(.rodata);
        build/us/src/FED0.c.o(.rodata);
        build/us/src/109A0.c.o(.rodata);
        build/us/src/155D0.c.o(.rodata);
        build/us/src/17280.c.o(.rodata);
        build/us/src/17810.c.o(.rodata);
        build/us/src/17990.c.o(.rodata);
        build/us/src/17A50.c.o(.rodata);
        build/us/src/17F00.c.o(.rodata);
        build/us/asm/us/18410.s.o(.rodata);
        build/us/src/20CD0.c.o(.rodata);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
    }
    main_bss_VRAM = ADDR(.main_bss);
    .main_bss (NOLOAD) : SUBALIGN(16)
    {
        main_BSS_START = .;
        build/us/src/main.c.o(.bss);
        build/us/src/540.c.o(.bss);
        build/us/src/2CA0.c.o(.bss);
        build/us/src/5050.c.o(.bss);
        build/us/src/ai.c.o(.bss);
        build/us/src/5E30.c.o(.bss);
        build/us/src/6380.c.o(.bss);
        build/us/src/scousers.c.o(.bss);
        build/us/src/7D60.c.o(.bss);
        build/us/src/D880.c.o(.bss);
        build/us/src/DF40.c.o(.bss);
        build/us/src/FED0.c.o(.bss);
        build/us/src/109A0.c.o(.bss);
        build/us/src/155D0.c.o(.bss);
        build/us/src/17280.c.o(.bss);
        build/us/src/17810.c.o(.bss);
        build/us/src/17990.c.o(.bss);
        build/us/src/17A50.c.o(.bss);
        build/us/src/17F00.c.o(.bss);
        build/us/asm/us/18410.s.o(.bss);
        build/us/src/20CD0.c.o(.bss);
        main_BSS_END = .;
        main_BSS_SIZE = ABSOLUTE(main_BSS_END - main_BSS_START);
    }
    __romPos += SIZEOF(.main);
    __romPos = ALIGN(__romPos, 16);
    main_ROM_END = __romPos;
    main_VRAM_END = .;

    data_ROM_START = __romPos;
    data_VRAM = ADDR(.data);
    .data main_VRAM_END : AT(data_ROM_START) SUBALIGN(1)
    {
        data_DATA_START = .;
        _22720_bin = .;
        build/us/assets/us/22720.bin.o(.data);
        font_png = .;
        build/us/assets/us/font.png.o(.data);
        _25480_bin = .;
        build/us/assets/us/25480.bin.o(.data);
        fsblob_bin = .;
        build/us/assets/us/fsblob.bin.o(.data);
        sfxpad_bin = .;
        build/us/assets/us/sfxpad.bin.o(.data);
        sfx0_bin = .;
        build/us/assets/us/sfx0.bin.o(.data);
        sfx1_bin = .;
        build/us/assets/us/sfx1.bin.o(.data);
        _2D25C_bin = .;
        . += 4;
        build/us/assets/us/2D25C.bin.o(.data);
        data_DATA_END = .;
        data_DATA_SIZE = ABSOLUTE(data_DATA_END - data_DATA_START);
    }
    __romPos += SIZEOF(.data);
    data_ROM_END = __romPos;
    data_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
