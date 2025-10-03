# BloodHorn

A bootloader supporting multiple architectures and boot protocols.

## Support Me

If you like this project and want to support me, you can donate through [Liberapay](https://liberapay.com/Listedroot/donate).

[![Donate using Liberapay](https://liberapay.com/assets/widgets/donate.svg)](https://liberapay.com/Listedroot/donate)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-x86__64%20%7C%20ARM64%20%7C%20RISC--V%20%7C%20LoongArch-blue)](https://codeberg.org/PacHashs/BloodHorn)

## Features
- Architectures: x86_64, ARM64, RISC-V, LoongArch
- Boot protocols: Linux, Multiboot 1/2, Limine, PXE, Chainloading
- Filesystems: FAT32, ext2/3/4
- Security: Secure Boot, TPM 2.0, file verification
- Network: PXE, TFTP, DHCP
- UI: Text and graphical modes
- Extensions: Lua scripting

## Building
1. Install EDK2 and required toolchain
2. Run: build -p BloodHorn/BloodHorn.dsc
3. Output will be in Build/BloodHorn/

## Usage
1. Copy BloodHorn.efi to your EFI partition
2. Configure your bootloader to load it
3. Place configuration files in the root of your boot partition:
   - config.ini for INI format
   - config.json for JSON format
   - Environment variables are also supported

## Documentation
See docs/ and other markdowns for detailed information on protocols and APIs.

## FAQ

### What is the size of BloodHorn?
BloodHorn source code is approximately 500 KB before compilation. After building, the bootloader binary ranges from 1.5 to 2 MB depending on enabled features and architecture.

### How do I contribute to BloodHorn?
Contributions are welcome! Please see our contribution guidelines in the docs/ directory and feel free to open issues or submit pull requests on our Codeberg repository.

### Does BloodHorn support Secure Boot?
Yes, BloodHorn includes comprehensive Secure Boot support with TPM 2.0 integration and cryptographic verification of all loaded modules.

## Contributors

- **[PacHash](https://github.com/PacHashs)** - Lead Developer
- **[UnpopularOpinion](https://github.com/unpopularopinionn)** - Main Team

- **[BillNyeTheScienceGuy](https://codeberg.org/BillNyeTheSienceGuy)** - Main Team

---

*BloodHorn was inspired by modern bootloaders, but all code is original and written from scratch for educational purposes and for use in future operating systems.*

## License
MIT
