from typing import List, Optional

from ...util import log

from os import makedirs
from os.path import dirname, realpath

from ...segtypes.common.data import CommonSegData

from struct import unpack
from subprocess import run
from tempfile import TemporaryDirectory

class N64SegFsblob(CommonSegData):
    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

    def split(self, rom_bytes):
        with TemporaryDirectory() as tempdir:
            with open(f"{tempdir}/comp.bin", "wb") as g:
                g.write(rom_bytes[self.rom_start:self.rom_end])
            makedirs(self.yaml["out_dir"], exist_ok = True)
            run([f"make", "-C", "tools", "fsblob", f"ARGS=extract -i {tempdir.replace('\\', '/')}/comp.bin -o {self.yaml['out_dir']}"])
            
