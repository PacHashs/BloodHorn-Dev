# BloodHorn Bootloader Overview

BloodHorn is a UEFI bootloader designed to support multiple architectures and boot protocols. It provides a flexible platform for loading operating systems with various boot methods.

## Supported Architectures
- **x86-64 (AMD64)** - Primary target architecture
- **IA-32 (i386)** - 32-bit x86 support
- **ARM64 (AArch64)** - ARM 64-bit architecture
- **RISC-V 64** - RISC-V 64-bit support
- **LoongArch 64** - LoongArch architecture support

## Boot Protocols
- **BloodChain Boot Protocol (BCBP)** - Native protocol for BloodHorn
- **Linux Boot Protocol** - Direct kernel loading with bzImage and EFI stub support
- **Multiboot 1 and 2** - Standard bootloader protocols
- **Limine Protocol** - Modern boot protocol support
- **UEFI Chainloading** - Boot other UEFI applications
- **PXE Network Boot** - Network-based booting support

## Key Features
- Interactive boot menu with theme support
- Multi-language localization system
- Mouse and keyboard input handling
- Secure boot integration with UEFI
- Network booting capabilities (PXE, TFTP)
- Recovery shell for system maintenance
- Plugin system with Lua scripting support
- Multiple filesystem support (FAT32, ext2/3/4, ISO9660)
- Configuration via INI, JSON, or environment variables

## Security Features
- UEFI Secure Boot integration
- TPM-based measured boot support
- Cryptographic verification of boot components
- Secure recovery mode
- Audit logging capabilities

## Library Integration
BloodHorn includes a development library (`boot/libb/`) that provides:
- Hardware abstraction layer
- Graphics and input APIs
- Filesystem operations
- Memory management functions
- Debug and logging framework

## Configuration
BloodHorn supports multiple configuration formats:
- **INI files** (`bloodhorn.ini`)
- **JSON files** (`bloodhorn.json`)
- **Environment variables** (`BLOODHORN_*`)

## Boot Process
1. UEFI firmware loads BloodHorn bootloader
2. System initialization and hardware detection
3. BloodHorn library initialization
4. Configuration file loading and parsing
5. Theme and localization setup
6. Boot menu display and user interaction
7. Selected boot protocol execution
8. Kernel loading and handoff to operating system

## Development Status
BloodHorn is an experimental bootloader project focused on providing a clean, modular, and adaptable boot environment. It serves as a reference implementation for UEFI bootloaders and supports educational purposes for firmware-level development.
