from ...util import options

from ..common.header import CommonSegHeader


class N64SegGsheader(CommonSegHeader):
    def parse_header(self, rom_bytes):
        encoding = options.opts.header_encoding

        header_lines = []
        header_lines.append(".section .data\n")
        header_lines.append(
            self.get_line("word", rom_bytes[0x00:0x04], "PI BSB Domain 1 register")
        )
        header_lines.append(
            self.get_line("word", rom_bytes[0x04:0x08], "Clockrate setting")
        )
        header_lines.append(
            self.get_line("word", rom_bytes[0x08:0x0C], "Entrypoint address")
        )
        header_lines.append(self.get_line("word", rom_bytes[0x0C:0x10], "Revision"))
        header_lines.append(self.get_line("word", rom_bytes[0x10:0x14], "Checksum 1"))
        header_lines.append(self.get_line("word", rom_bytes[0x14:0x18], "Checksum 2"))
        header_lines.append(self.get_line("word", rom_bytes[0x18:0x1C], "Unknown 1"))
        header_lines.append(self.get_line("word", rom_bytes[0x1C:0x20], "Unknown 2"))

        if encoding != "word":
            header_lines.append(
                '.ascii "'
                + rom_bytes[0x20:0x30].decode(encoding).strip().ljust(16)
                + '" /* Internal name */'
            )
            header_lines.append(
                '.ascii "'
                + rom_bytes[0x30:0x3C].decode(encoding).strip().ljust(12)
                + '" /* Build date */'
            )
        else:
            for i in range(0x20, 0x30, 4):
                header_lines.append(
                    self.get_line("word", rom_bytes[i : i + 4], "Internal name")
                )
            for i in range(0x30, 0x3C, 4):
                header_lines.append(
                    self.get_line("word", rom_bytes[i : i + 4], "Build date")
                )

        header_lines.append(self.get_line("word", rom_bytes[0x3C:0x40], "Unknown 4"))
        header_lines.append("")

        return header_lines