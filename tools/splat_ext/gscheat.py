from typing import List, Optional
from pathlib import Path

from ...util import log, options

from os import makedirs
from os.path import dirname, realpath

from ...segtypes.common.bin import CommonSegBin

from struct import unpack
from subprocess import run
from tempfile import TemporaryDirectory

class N64SegGscheat(CommonSegBin):
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

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.txt"

    def split(self, rom_bytes):
        path = self.out_path()
        assert path is not None
        path.parent.mkdir(parents=True, exist_ok=True)

        if self.rom_end is None:
            log.error(
                f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
            )

        if self.size is None or self.size <= 0:
            log.error(f"Segment {self.name} has zero size.")

        self.log(f"Wrote {self.name} to {path}")
        with TemporaryDirectory() as tempdir:
            with open(f"{tempdir}/cheats.bin", "wb") as g:
                assert isinstance(self.rom_start, int)
                assert isinstance(self.rom_end, int)
                g.write(rom_bytes[self.rom_start:self.rom_end])
            run([f"make", "-C", "tools", "gscheat", f"ARGS={tempdir.replace('\\', '/')}/cheats.bin {str(path).replace('\\', '/')} extract"])
            
