# Boot Protocols

```
BLOODCHAIN BOOT PROTOCOL (BCBP):
- Native BloodHorn protocol
- Advanced boot information passing
- Module loading support
- Memory map information
- Graphics framebuffer data
- ACPI/SMBIOS table pointers
- Secure boot status
- Platform-specific data

BCBP Header Structure:
- Signature: "BCBP"
- Version information
- Kernel base address
- Boot device information
- Module count and array
- Memory map pointer
- Graphics information
- ACPI RSDP pointer
- SMBIOS table pointer
- Security flags

LINUX BOOT PROTOCOL:
- Direct Linux kernel loading
- Setup header parsing
- Command line passing
- initrd/initramfs support
- Standard Linux boot sequence
- x86/x86_64/ARM64 support

Linux Boot Parameters:
- Kernel image path
- Initial ramdisk path
- Command line arguments
- Boot parameters
- Memory layout
- Device information

MULTIBOOT 1/2 PROTOCOL:
- Standard bootloader protocol
- Cross-platform kernel loading
- Module loading support
- Memory map provision
- Boot information structure

Multiboot Features:
- ELF kernel support
- Module enumeration
- Memory mapping
- Boot device information
- Command line parsing
- Graphics mode setting

LIMINE PROTOCOL:
- Modern boot protocol
- Advanced features
- Multiple architecture support
- Extensible design
- High-level abstractions

Limine Capabilities:
- Kernel loading
- Module management
- Graphics initialization
- Memory management
- Device tree support
- ACPI integration

UEFI CHAINLOADING:
- Boot other UEFI applications
- Preserve UEFI environment
- Protocol forwarding
- Image loading
- Execution transfer

Chainload Process:
1. Load target UEFI application
2. Prepare execution environment
3. Transfer control
4. Maintain UEFI services
5. Handle return scenarios

PXE NETWORK BOOT:
- Network-based kernel loading
- DHCP configuration
- TFTP file transfer
- Remote boot support
- Network device detection

PXE Boot Flow:
1. Network interface initialization
2. DHCP request for IP/boot server
3. TFTP connection to boot server
4. Kernel and initrd download
5. Local boot process initiation
```
