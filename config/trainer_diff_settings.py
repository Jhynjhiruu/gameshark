def apply(config, args):
    config["baseimg"] = "fs/loader/trainer.bin"
    config["myimg"] = "build/trainer.bin"
    config["mapfile"] = "build/trainer.map"
    config["source_directories"] = ["src/trainer"]
    # config["show_line_numbers_default"] = True
    # config["arch"] = "mips"
    # config["map_format"] = "gnu" # gnu, mw, ms
    # config["build_dir"] = "build/" # only needed for mw and ms map format
    # config["expected_dir"] = "expected/" # needed for -o
    # config["makeflags"] = []
    # config["objdump_executable"] = ""