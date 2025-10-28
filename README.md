# BloodHorn

<p align="center">
  <img src="Z.png" alt="BloodHorn Logo" width="500"/>
</p>

<div align="center">
  <img src="winerr.png" alt=":(" width="22" style="vertical-align:middle; margin-right:6px;"/>
  <strong>Temporary Discontinued Notice</strong>
</div>

<p align="center">
  This project is <strong>temporarily discontinued</strong> until <strong>January 1, 2026</strong> due to mental health reasons affecting the main maintainer.
  During this period, <strong>no new commits</strong> will be pushed, <strong>pull requests will not be reviewed or merged</strong>,
  and <strong>issues will not be triaged</strong>.
  Thank you for your understanding and patience.
</p>

## Support Me

If you like this project and want to support me, you can donate through [Liberapay](https://liberapay.com/Listedroot/donate).

[![Build Status](https://ci.codeberg.org/api/badges/PacHashs/BloodHorn/status.svg)](https://ci.codeberg.org/PacHashs/BloodHorn)

[![Donate using Liberapay](https://liberapay.com/assets/widgets/donate.svg)](https://liberapay.com/Listedroot/donate)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-x86__64%20%7C%20ARM64%20%7C%20RISC--V%20%7C%20LoongArch-blue)](https://codeberg.org/PacHashs/BloodHorn)

## Quick Start

1. Build with EDK2: `build -p BloodHorn/BloodHorn.dsc`
2. Copy `BloodHorn.efi` to your EFI system partition.
3. Add a minimal config at the partition root as `bloodhorn.ini`:

```ini
[boot]
default = linux
menu_timeout = 5
language = en
font_path = /fonts/ter-16n.psf

[linux]
kernel = /boot/vmlinuz
initrd = /boot/initrd.img
cmdline = root=/dev/sda1 ro quiet
```

4. Optional assets:
   - Localization file: `\\locales\\en.ini` (key=value strings)
   - PSF1 font: `/fonts/ter-16n.psf` (referenced by `boot.font_path`)
5. Boot BloodHorn from your firmware menu. Press any key to open the menu during the countdown.
## Features
- **Architectures**: x86_64, ARM64, RISC-V, LoongArch
- **Protocols**: Linux, Multiboot 1/2, Limine, Chainload, PXE, BloodChain
- **Security**: Secure Boot, TPM 2.0, file verification
- **Config**: INI/JSON/UEFI vars, layered with sane defaults
- **UI**: Text/graphical, localization via `\\locales\\<lang>.ini`, PSF1 font loading
- **Firmware**: Coreboot + UEFI hybrid with auto-detection

## Building
- Install EDK2 and required toolchain
- Build: `build -p BloodHorn/BloodHorn.dsc`
- Output: `Build/BloodHorn/`

## Usage
- Copy `BloodHorn.efi` to your EFI partition and select it in firmware.
- Put `bloodhorn.ini` or `bloodhorn.json` at the partition root (UEFI vars `BLOODHORN_*` override files).
- Optional: `\\locales\\<lang>.ini` and PSF1 font under `/fonts/` referenced by `boot.font_path`.

**Coreboot Integration:** BloodHorn automatically detects and adapts to Coreboot firmware when running as a payload, providing enhanced hardware control and performance while maintaining UEFI compatibility.

## Documentation
- `docs/Overview.md` – high-level overview
- `docs/Configuration.md` – all config options (themes, fonts, locales, entries)
- `docs/Boot-Protocols.md` – supported protocols
- `docs/COREBOOT_INTEGRATION.md` – hybrid mode details

**Coreboot Integration:** For detailed information about BloodHorn's Coreboot firmware integration, see `docs/COREBOOT_INTEGRATION.md`.

## Why BloodHorn vs. Limine or GRUB?

BloodHorn is not a drop-in replacement for GRUB or Limine. It targets a modern, clean, and extensible codebase with Coreboot + UEFI hybrid support and a focus on developer experience. adding to that that bloodhorn is still underdevelopment. issues and bugs may rise more often then more mature bootloaders like limine or grub.

When you might prefer BloodHorn:

- **Hybrid Coreboot + UEFI**: Needs direct Coreboot init while keeping UEFI services.
- **Minimal, modern codebase**: Easier to read/extend than legacy loaders.
- **Custom protocols and experimentation**: Native BloodChain protocol and Lua/plugins.
- **Config flexibility**: INI/JSON/UEFI-variables with simple merging and sane defaults.
- **Built-in localization + font selection**: `\locales\<lang>.ini` and PSF font loading via config.

When you might prefer GRUB or Limine:

- **Broad distro integration**: GRUB has mature tooling and OS installer support.
- **Complex filesystems and modules**: GRUB's module ecosystem may be required.
- **Existing ecosystem configs**: If you already rely on Limine or GRUB configs/scripts.
- **Special boot flows**: GRUB chainloading/menu scripting already meets your needs.

Summary: choose BloodHorn for a modern, hackable bootloader with Coreboot hybrid support and straightforward configuration; choose GRUB/Limine for large ecosystem integration and long-established workflows.

## FAQ

### What is the size of BloodHorn?
BloodHorn source code is approximately 500 KB before compilation. After building, the bootloader binary ranges from 1.5 to 2 MB depending on enabled features and architecture.

### How do I contribute to BloodHorn?
Contributions are welcome! Please see our contribution guidelines in the docs/ directory and feel free to open issues or submit pull requests on our Codeberg repository.

### Does BloodHorn support Secure Boot?
Yes, BloodHorn includes comprehensive Secure Boot support with TPM 2.0 integration and cryptographic verification of all loaded modules.

### Does BloodHorn support Coreboot firmware?
Yes, BloodHorn features comprehensive Coreboot firmware integration with automatic detection and hybrid initialization. When running as a Coreboot payload, it leverages Coreboot's direct hardware control for enhanced performance while maintaining UEFI compatibility for broader system support.

## Contributors

- **[PacHash](https://github.com/PacHashs)** - Lead Developer
- **[BillNyeTheScienceGuy](https://codeberg.org/BillNyeTheSienceGuy)** - Main Team

---

*BloodHorn was inspired by modern bootloaders, but all code is original and written from scratch for educational purposes and for use in future operating systems.*

## License
MIT.
