# BloodHorn

<p align="center">
  <img src="Z.png" alt="BloodHorn Logo" width="500"/>
  <br>
  <em>Fast, secure, and reliable system bootstrapping</em>
</p>

## About BloodHorn

BloodHorn is a modern, high-performance bootloader built on the EDK2 framework with Coreboot integration. Designed for speed, security, and reliability, it provides a robust foundation for system initialization across multiple architectures.

## Project History

### Origins (2016)
The BloodHorn project originated from an open-source bootloader prototype discovered in 2016. The initial codebase was developed by an anonymous contributor and shared on a technical forum in 4chan. The current maintainer recognized its potential and began maintaining and expanding the project.

### Development Timeline
- **2016-2018**: Core functionality refinement and initial testing
- **2019-2021**: Major architectural improvements and feature additions
- **2022-2023**: Codebase modernization and security enhancements
- **2024-Present**: Active maintenance and community development

### Project Philosophy
BloodHorn is developed with a focus on:
- Technical excellence
- Minimal resource usage
- Clean, maintainable code
- Practical functionality over marketing

## Support Me

If you like this project and want to support me, you can donate through [Liberapay](https://liberapay.com/Listedroot/donate).

[![Build Status](https://ci.codeberg.org/api/badges/PacHashs/BloodHorn/status.svg)](https://ci.codeberg.org/PacHashs/BloodHorn)

[![Donate using Liberapay](https://liberapay.com/assets/widgets/donate.svg)](https://liberapay.com/Listedroot/donate)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-x86__64%20%7C%20ARM64%20%7C%20RISC--V%20%7C%20LoongArch-blue)](https://codeberg.org/PacHashs/BloodHorn)

## Getting Started

### Prerequisites
- Git
- Python 3.7 or later
- C/C++ toolchain (GCC/Clang on Linux/macOS, MSVC on Windows)
- EDK2 (pre-installed and configured)

### Building from Source

#### Linux/macOS
```bash
git clone --recursive https://codeberg.org/PacHashs/BloodHorn.git
cd BloodHorn
```

#### Windows
```cmd
git clone --recursive https://codeberg.org/PacHashs/BloodHorn.git
cd BloodHorn
```

### Installing BloodHorn
### Building BloodHorn

#### Linux/macOS
```bash
# Release build
build -p BloodHorn.dsc -b RELEASE -t GCC5 -a X64

# Debug build
build -p BloodHorn.dsc -b DEBUG -t GCC5 -a X64
```

#### Windows
```cmd
:: Release build
build -p BloodHorn.dsc -b RELEASE -t VS2019 -a X64

:: Debug build
build -p BloodHorn.dsc -b DEBUG -t VS2019 -a X64
```

Output files:
- `Build/BloodHorn/RELEASE_<TOOLCHAIN>/X64/BloodHorn.efi`
- `Build/BloodHorn/DEBUG_<TOOLCHAIN>/X64/BloodHorn.efi`

## Installation

### Linux/macOS
```bash
# Mount EFI partition (if not already mounted)
mount /dev/sdX1 /mnt/efi

# Install BloodHorn
cp Build/BloodHorn/RELEASE_GCC5/X64/BloodHorn.efi /mnt/efi/EFI/BOOT/BOOTX64.EFI
```

### Windows (Admin)
```cmd
:: Install to default boot location
copy Build\BloodHorn\RELEASE_VS2019\X64\BloodHorn.efi C:\EFI\Microsoft\Boot\bootmgfw.efi
```

> **Note:** Always back up your existing bootloader before installation.

## Project Structure

```
BloodHorn/
├── BloodHorn.dsc       # Main build configuration
├── BloodHorn.fdf       # FD image layout
├── BloodHorn.inf       # Module definition
├── coreboot/           # Coreboot integration
├── uefi/              # UEFI implementation
├── security/          # TPM and security features
├── fs/                # Filesystem support
├── net/               # Network booting
└── plugins/           # Extensible modules
```

## Features

- **Architectures**: x86_64, ARM64, RISC-V, LoongArch
- **Security**: Secure Boot, TPM 2.0, file verification
- **Firmware**: Coreboot + UEFI hybrid
- **Configuration**: INI/JSON/UEFI variables
- **UI**: Text and graphical interfaces with localization
- **Performance**: Optimized boot times
   ```

4. **Basic Configuration**:
   Create a minimal `bloodhorn.ini` at your EFI partition root:
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

5. **Optional but Fancy**:
   - Localization: `\locales\en.ini`
   - Fancy fonts: `/fonts/ter-16n.psf`
   - Your favorite OS (we don't judge... much)
## Features That Make GRUB Look Like a Dial-Up Connection

- **Architectures**: x86_64, ARM64, RISC-V, LoongArch - Like a UN meeting, but for your computer's soul
- **Protocols**: Linux, Multiboot 1/2, Limine, Chainload, PXE, BloodChain - More protocols than your ex has excuses
- **Security**: Secure Boot, TPM 2.0, file verification - We've got more layers than an onion (and might make you cry less)
- **Config**: INI/JSON/UEFI vars - Because one way to do things is boring, and three is a party
- **UI**: Text/graphical with localization - Now with 100% fewer "grub>" prompts that make you question your life choices
- **Firmware**: Coreboot + UEFI hybrid - Like peanut butter and chocolate, but for your firmware
- **Recovery Mode**: For when you thought "rm -rf /" was a good idea at 3 AM
- **Boot Speed**: Faster than you can say "I'll just check Reddit while I wait"

## Project Structure (Where the Magic Happens)

```
BloodHorn/
├── BloodHorn.dsc       # Main build configuration
├── BloodHorn.fdf       # FD image layout
├── BloodHorn.inf       # Module information
├── coreboot/           # Coreboot integration
├── uefi/              # UEFI-specific code
├── security/          # TPM, Secure Boot, and other fun stuff
├── fs/                # Filesystem support
├── net/               # Network booting (for when you're feeling brave)
└── plugins/           # Because why not make it more complicated?

# EDK2 Components We've Adopted
├── MdeModulePkg/      # Because we're not masochists
├── CryptoPkg/         # For when you need to encrypt your bootloader's diary
├── EmbeddedPkg/       # For that embedded feeling
└── BaseTools/         # The unsung heroes of the build process
```

## Advanced Configuration

### Coreboot Integration
BloodHorn and Coreboot go together like peanut butter and chocolate (if they were both made of code):
- Auto-detects Coreboot firmware
- Uses Coreboot tables when available
- Falls back to UEFI services when needed

### Secure Boot (For the Paranoid)
```ini
[security]
secure_boot = true
tpm_support = true
key_file = /path/to/your/key.pem
```

### Network Boot (Because Local Storage is So 2020)
```ini
[network]
pxe_enabled = true
tftp_server = 192.168.1.100
boot_file = /pxelinux.0
```

**Coreboot Integration:** BloodHorn automatically detects and adapts to Coreboot firmware when running as a payload, providing enhanced hardware control and performance while maintaining UEFI compatibility.

## Documentation
- `docs/Overview.md` – high-level overview
- `docs/Configuration.md` – all config options (themes, fonts, locales, entries)
- `docs/Boot-Protocols.md` – supported protocols
- `docs/COREBOOT_INTEGRATION.md` – hybrid mode details

**Coreboot Integration:** For detailed information about BloodHorn's Coreboot firmware integration, see `docs/COREBOOT_INTEGRATION.md`.

## Why BloodHorn? (Asking for a Friend)

### You'll Love BloodHorn If You've Ever:
- Wanted to high-five your bootloader (metaphorically, please don't touch the screen)
- Thought "I wish this boot process had more personality"
- Wasted hours configuring GRUB only to get a blinking cursor
- Wanted to feel like a hacker without actually having to hack anything

### Choose BloodHorn When:
- **You value your time** - Boots faster than you can say "I'll just check my phone"
- **You like options** - More configuration choices than a hipster coffee shop
- **You make mistakes** - Recovery mode that doesn't judge (much)
- **You're not a morning person** - Because neither are we

### Stick With GRUB If You:
- Enjoy typing commands that look like they're in Klingon
- Think booting should be a social activity (with all that waiting around)
- Believe "minimalist" means "I like staring at a command prompt"
- Have a poster of Linus Torvalds on your wall (we see you)

### Real Developers (and Their Computers) Love BloodHorn
- **For the rebels** who think "standards are just suggestions"
- **For the optimists** who think "it worked once, ship it!"
- **For the realists** who know they'll be debugging this at 2 AM
- **For the dreamers** who believe one day their code will be as cool as BloodHorn

> *"I used to have a life. Then I found BloodHorn. Now I spend all my time booting things just for fun."*  
> — Probably someone, somewhere, hopefully

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
