```
BloodHorn is a production-grade UEFI bootloader with advanced features:

SUPPORTED ARCHITECTURES:
- x86-64 (AMD64) - Primary target
- IA-32 (i386) - 32-bit x86
- ARM64 (AArch64) - ARM 64-bit
- RISC-V 64 - RISC-V 64-bit
- LoongArch 64 - LoongArch

BOOT PROTOCOLS:
- BloodChain Boot Protocol (BCBP) - Native protocol
- Linux Boot Protocol - Direct kernel loading
- Multiboot 1/2 - Standard bootloader protocol
- Limine Protocol - Modern boot protocol
- UEFI Chainloading - Boot other UEFI applications
- PXE Network Boot - Network-based booting

KEY FEATURES:
- Interactive boot menu with theme support
- Multi-language localization
- Mouse and keyboard input
- Secure boot integration
- Network booting (PXE, TFTP, HTTP)
- Recovery shell and diagnostic tools
- Plugin system with Lua scripting
- Multiple filesystem support
- Configuration via INI, JSON, or environment variables

SECURITY FEATURES:
- UEFI Secure Boot integration
- TPM-based measured boot
- Cryptographic kernel verification
- Secure recovery mode
- Audit logging

LIBRARY INTEGRATION:
- BloodHorn development library (boot/libb/)
- Hardware abstraction layer
- Graphics and input APIs
- Filesystem operations
- Memory management
- Debug framework

CONFIGURATION FORMATS:
- INI files (bloodhorn.ini)
- JSON files (bloodhorn.json)
- Environment variables (BLOODHORN_*)

BOOT FLOW:
1. UEFI firmware loads BloodHorn
2. System initialization
3. BloodHorn library initialization
4. Configuration loading
5. Theme and localization setup
6. Boot menu display
7. User selection
8. Kernel loading and execution
```
