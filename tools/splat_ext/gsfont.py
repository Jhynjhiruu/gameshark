from typing import Optional, Union, Dict, List
from pathlib import Path

from ...util import log, options

from ...segtypes.common.bin import CommonSegBin

from subprocess import run
from tempfile import TemporaryDirectory

class N64SegGsfont(CommonSegBin):
    @staticmethod
    def parse_num_chars(yaml: Union[Dict, List]) -> int:
        if isinstance(yaml, dict):
            return yaml["chars"]
        else:
            if len(yaml) < 4:
                log.error(f"Error: {yaml} is missing chars parameter")
            return yaml[3]
    
    @staticmethod
    def parse_extra_path(yaml: Union[Dict, List]) -> str:
        if isinstance(yaml, dict):
            return yaml["extra_path"]
        else:
            if len(yaml) < 5:
                log.error(f"Error: {yaml} is missing extra path parameter")
            return yaml[4]
        
    @staticmethod
    def parse_extra_offset(yaml: Union[Dict, List]) -> str:
        if isinstance(yaml, dict):
            return yaml["extra_offset"]
        else:
            if len(yaml) < 6:
                log.error(f"Error: {yaml} is missing extra offset parameter")
            return yaml[5]
        
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

        self.chars = self.parse_num_chars(yaml)
        self.extra = self.parse_extra_path(yaml)
        self.extra_offset = self.parse_extra_offset(yaml)

    def get_linker_section(self) -> str:
        return ".text"
    
    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.png"

    def extra_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.extra}.png"
    
    def split(self, rom_bytes: bytes):
        path = self.out_path()
        assert path is not None
        path.parent.mkdir(parents=True, exist_ok=True)

        extra_path = self.extra_path()
        assert extra_path is not None
        extra_path.parent.mkdir(parents=True, exist_ok=True)

        if self.rom_end is None:
            log.error(
                f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
            )

        if self.size is None or self.size <= 0:
            log.error(f"Segment {self.name} has zero size.")
        
        with TemporaryDirectory() as tempdir:
            with open(f"{tempdir}/{self.name}.bin", "wb") as g:
                assert isinstance(self.rom_start, int)
                assert isinstance(self.rom_end, int)
                g.write(rom_bytes[self.rom_start:self.rom_end])
            
            run([f"make", "-C", "tools", "gsfont", f"ARGS={tempdir.replace('\\', '/')}/{self.name}.bin {str(path).replace('\\', '/')} {str(extra_path).replace('\\', '/')} extract {self.vram_start} {self.chars} {self.extra_offset}"])
