.PHONY: tools_setup tools_clean sike sharkpatch fsblob gscheat gscrc gsfont

ifeq ($(OS),Windows_NT)
	EXESUFFIX := .exe
else
	EXESUFFIX :=
endif

CARGO := cargo build
CARGO_CLEAN := cargo clean
CARGOFLAGS := --release
CARGO_TARGET := target/release

SIKE_BASE := sike/$(CARGO_TARGET)/sike
SHARKPATCH_BASE := sharkpatch/$(CARGO_TARGET)/sharkpatch
FSBLOB_BASE := fsblob/$(CARGO_TARGET)/fsblob
GSCHEAT_BASE := gscheat/$(CARGO_TARGET)/gscheat
GSCRC_BASE := gscrc/$(CARGO_TARGET)/gscrc
GSFONT_BASE := gsfont/$(CARGO_TARGET)/gsfont

SIKE := $(SIKE_BASE)$(EXESUFFIX)
SHARKPATCH := $(SHARKPATCH_BASE)$(EXESUFFIX)
FSBLOB := $(FSBLOB_BASE)$(EXESUFFIX)
GSCHEAT := $(GSCHEAT_BASE)$(EXESUFFIX)
GSCRC := $(GSCRC_BASE)$(EXESUFFIX)
GSFONT := $(GSFONT_BASE)$(EXESUFFIX)

tools_setup: $(SIKE) $(SHARKPATCH) $(FSBLOB) $(GSCHEAT) $(GSCRC) $(GSFONT)

tools_clean:
	(cd sike && $(CARGO_CLEAN))
	(cd sharkpatch && $(CARGO_CLEAN))
	(cd fsblob && $(CARGO_CLEAN))
	(cd gscheat && $(CARGO_CLEAN))
	(cd gscrc && $(CARGO_CLEAN))
	(cd gsfont && $(CARGO_CLEAN))

$(SIKE):
	(cd sike && $(CARGO) $(CARGOFLAGS))

$(SHARKPATCH):
	(cd sharkpatch && $(CARGO) $(CARGOFLAGS))

$(FSBLOB):
	(cd fsblob && $(CARGO) $(CARGOFLAGS))

$(GSCHEAT):
	(cd gscheat && $(CARGO) $(CARGOFLAGS))

$(GSCRC): gscrc/cic7105.bin
	(cd gscrc && $(CARGO) $(CARGOFLAGS))

$(GSFONT):
	(cd gsfont && $(CARGO) $(CARGOFLAGS))

sike: $(SIKE)
	(cd .. && $(CURDIR)/$(SIKE) $(ARGS))

sharkpatch: $(SHARKPATCH)
	(cd .. && $(CURDIR)/$(SHARKPATCH) $(ARGS))

fsblob: $(FSBLOB)
	(cd .. && $(CURDIR)/$(FSBLOB) $(ARGS))

gscheat: $(GSCHEAT)
	(cd .. && $(CURDIR)/$(GSCHEAT) $(ARGS))

gscrc: $(GSCRC)
	(cd .. && $(CURDIR)/$(GSCRC) $(ARGS))

gsfont: $(GSFONT)
	(cd .. && $(CURDIR)/$(GSFONT) $(ARGS))

-include $(SIKE_BASE).d
-include $(SHARKPATCH_BASE).d
-include $(FSBLOB_BASE).d
-include $(GSCHEAT_BASE).d
-include $(GSCRC_BASE).d
-include $(GSFONT_BASE).d
