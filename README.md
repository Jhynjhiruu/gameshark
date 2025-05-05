# GameShark Pro firmware decompilation

A WIP matching decompilation of the GameShark Pro firmware.

## Compatibility

Currently, this repo supports the following versions:

 - GameShark Pro v3.3 (April), SHA-1 `5ac1387c18b0632f7d4c1106eb591d801835c57e`

## Dependencies

- `build-essential` or your OS's equivalent
- Modern Python 3
- Modern Rust

On non-Windows OSes, you'll also need `wine` with a 32-bit prefix or equivalent.

You'll also need a MIPS toolchain and binutils installed. By default, the repository looks for `mips-linux-gnu-XXX` on Linux and assumes `libdragon` is installed (i.e. `%N64_INST%` is defined and the toolchain is installed to `%N64_INST%\bin\`) on Windows.

Then, install the Python libraries `splat64`, `spimdisasm`, `n64img`, `pygfxd` and `crunch64` (`pip3 install <package>`), and install the Rust binary `pigment64` (`cargo install pigment64`).

## Setup

Clone the repository recursively (using the `--recursive`) flag.

Place a copy of the GameShark Pro v3.3 (April) firmware in the root of the repository, renamed to `baserom.z64`, and a copy of CIC 7105's IPL3 (i.e. bytes 0x40-0xFFF inclusive of a game that uses CIC 7105 or 6105) in `tools/gscrc/` as `cic7105.bin`.

From the root of the repository, run `make split`. This will build all of the tools, and then split the binary.

Then, run `make -f Makefile.shell split` and `make -f Makefile.trainer split` to split the shell and trainer.

## Building

To build the shell, run `make -f Makefile.shell` from the root of the repository.

To build the trainer, run `make -f Makefile.trainer` from the root of the repository.

To build the whole firmware, run `make` from the root of the repository. Note that building using the built `shell.bin` and `trainer.bin` is not yet supported.
