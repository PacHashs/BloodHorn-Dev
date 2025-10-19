# BloodHorn Bootloader Documentation

## Overview
This directory contains comprehensive documentation for the BloodHorn bootloader project. The documentation covers the bootloader's features, configuration, and usage.

## Available Documentation

### Core Documentation
- **Overview.md** - Project overview and key features
- **Boot-Protocols.md** - Supported boot protocols and their specifications
- **Configuration.md** - Configuration file formats and options
- **Library-API.md** - Developer API reference for the BloodHorn library

### Specialized Features
- **COREBOOT_INTEGRATION.md** - Integration with Coreboot firmware
- **BloodChain-Protocol.md** - BloodChain Boot Protocol specification
- **Network-Boot.md** - Network boot capabilities
- **Recovery-Shell.md** - Recovery system and shell functionality

## Supported Architectures
- x86-64 (AMD64)
- IA-32 (i386)
- ARM64 (AArch64)
- RISC-V 64
- LoongArch 64

## Boot Protocols
- Linux Boot Protocol (bzImage and EFI stub support)
- Multiboot 1 and 2
- Limine Protocol
- BloodChain Boot Protocol (BCBP)
- UEFI Chainloading
- PXE Network Boot

## Filesystem Support
- FAT12/16/32
- ext2/3/4
- ISO9660

## Security Features
- UEFI Secure Boot integration
- TPM-based measured boot
- Cryptographic verification of boot components

## Building and Usage
For build instructions and basic usage, see the main project README.md file.

## Contributing
Documentation contributions are welcome. Please ensure all documentation is accurate and reflects the actual capabilities of the software.
