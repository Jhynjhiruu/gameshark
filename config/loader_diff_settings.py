def apply(config, args):
    config["baseimg"] = "baserom.z64"
    config["myimg"] = "build/GS.bin"
    config["mapfile"] = "build/loader.map"
    config["source_directories"] = ["src/loader"]
    # config["show_line_numbers_default"] = True
    # config["arch"] = "mips"
    # config["map_format"] = "gnu" # gnu, mw, ms
    # config["build_dir"] = "build/" # only needed for mw and ms map format
    # config["expected_dir"] = "expected/" # needed for -o
    # config["makeflags"] = []
    # config["objdump_executable"] = ""