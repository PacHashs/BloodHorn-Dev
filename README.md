# BloodHorn

<p align="center">
  <img src="Z.png" alt="BloodHorn Logo" width="500"/>
  <br>
  <em>"The bootloader that doesn't boot . it grants booting privileges"</em>
</p>

## BloodHorn: The Bootloader That Doesn't Ask Stupid Questions

BloodHorn is the Chuck Norris of bootloaders - it doesn't boot your system, it allows your system to boot. Built on EDK2 with Coreboot integration, it's like giving your boot process a double shot of espresso. While other bootloaders are still asking if you want to start in safe mode, BloodHorn has already booted your OS, made coffee, and is now judging your choice of Linux distribution.

## Support Me

If you like this project and want to support me, you can donate through [Liberapay](https://liberapay.com/Listedroot/donate).

[![Build Status](https://ci.codeberg.org/api/badges/PacHashs/BloodHorn/status.svg)](https://ci.codeberg.org/PacHashs/BloodHorn)

[![Donate using Liberapay](https://liberapay.com/assets/widgets/donate.svg)](https://liberapay.com/Listedroot/donate)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-x86__64%20%7C%20ARM64%20%7C%20RISC--V%20%7C%20LoongArch-blue)](https://codeberg.org/PacHashs/BloodHorn)

## Quick Start: The BloodHorn Experience

### Prerequisites
- Git (for cloning repositories)
- Python 3.7 or later (for build tools)
- A C compiler (GCC on Linux/macOS, Visual Studio on Windows)
- EDK2 (EDK2 modules and packages that are needed are already included . )
- A healthy sense of adventure (and definitely a backup of your boot partition)

### Setting Up the Build Environment

#### Linux/macOS
```bash
# Clone the repository (if you haven't already)
git clone --recursive https://codeberg.org/PacHashs/BloodHorn.git
cd BloodHorn

# Initialize the EDK2 environment
. edk2/edksetup.sh

# Build the BaseTools
make -C edk2/BaseTools
```

#### Windows
```cmd
:: Clone the repository (if you haven't already)
git clone --recursive https://codeberg.org/PacHashs/BloodHorn.git
cd BloodHorn

:: Set up the environment
call edk2\edksetup.bat

:: Build the BaseTools
cd edk2\BaseTools
nmake all
cd ..\..
```

### Building BloodHorn

#### Linux/macOS
```bash
# For a release build
build -p BloodHorn.dsc -b RELEASE -t GCC5 -a X64

# For debugging
build -p BloodHorn.dsc -b DEBUG -t GCC5 -a X64
```

#### Windows
```cmd
:: For a release build
build -p BloodHorn.dsc -b RELEASE -t VS2019 -a X64

:: For debugging
build -p BloodHorn.dsc -b DEBUG -t VS2019 -a X64
```

The built EFI file will be available at:
```
Build/BloodHorn/RELEASE_GCC5/X64/BloodHorn.efi  # On Linux/macOS
Build/BloodHorn/RELEASE_VS2019/X64/BloodHorn.efi # On Windows with VS2019
Build/BloodHorn/RELEASE_CLANG38/X64/BloodHorn.efi # With Clang
```

## Installation (The Point of No Return)

### Linux/macOS
```bash
# Find your EFI partition (usually /boot/efi or /efi)
mount | grep efi

# Create a backup (because we're responsible adults)
sudo cp /path/to/efi/EFI/BOOT/BOOTX64.EFI /path/to/efi/EFI/BOOT/BOOTX64.BAK

# Install BloodHorn
sudo cp Build/BloodHorn/RELEASE_GCC5/X64/BloodHorn.efi /path/to/efi/EFI/BOOT/BOOTX64.EFI
```

### Windows (Admin Command Prompt)
```cmd
:: Backup the existing bootloader
copy C:\EFI\Microsoft\Boot\bootmgfw.efi C:\EFI\Microsoft\Boot\bootmgfw.BAK

:: Install BloodHorn
copy Build\BloodHorn\RELEASE_VS2019\X64\BloodHorn.efi C:\EFI\Microsoft\Boot\bootmgfw.efi
```

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
├── MdeModulePkg/      # Core UEFI functionality
├── CryptoPkg/         # For when you need to encrypt your bootloader's diary
├── SecurityPkg/       # Because security is important (apparently)
└── FatPkg/            # FAT filesystem support (for when you're feeling nostalgic)
```

## Features That Make GRUB Look Like a Dial-Up Connection

- **Architectures**: x86_64, ARM64, RISC-V, LoongArch - Like a UN meeting, but for your computer's soul
- **Protocols**: Linux, Multiboot 1/2, Limine, Chainload, PXE, BloodChain - More protocols than your ex has excuses
- **Security**: Secure Boot, TPM 2.0, file verification - We've got more layers than an onion (and might make you cry less)
- **Config**: INI/JSON/UEFI vars - Because one way to do things is boring, and three is a party
- **UI**: Text/graphical with localization - Now with 100% fewer "grub>" prompts that make you question your life choices
- **Firmware**: Coreboot + UEFI hybrid - Like peanut butter and chocolate, but for your firmware
- **Boot Speed**: Faster than you can say "I'll just check Reddit while I wait"
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
