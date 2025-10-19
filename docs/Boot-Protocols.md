# Boot Protocols

## Overview

BloodHorn supports multiple boot protocols to provide flexibility in loading different types of operating system kernels and boot environments.

## Supported Protocols

### BloodChain Boot Protocol (BCBP)
BloodHorn's native boot protocol designed for advanced boot information passing and module loading.

**Key Features:**
- Advanced boot information passing
- Module loading support with metadata
- Memory map information
- Graphics framebuffer data
- ACPI/SMBIOS table pointers
- Secure boot status
- Platform-specific data

**BCBP Header Structure:**
- Signature: "BCBP"
- Version information
- Kernel base address and size
- Boot device information
- Module count and module array
- Memory map pointer
- Graphics framebuffer information
- ACPI RSDP pointer
- SMBIOS table pointer
- Security flags and status

### Linux Boot Protocol
Direct loading of Linux kernels using the standard Linux boot protocol.

**Supported Features:**
- bzImage and EFI stub kernel formats
- Setup header parsing and validation
- Command line parameter passing
- initrd/initramfs support
- Standard Linux boot sequence
- Multi-architecture support (x86, x86-64, ARM64)

**Boot Parameters:**
- Kernel image path specification
- Initial ramdisk path
- Command line arguments
- Boot parameters and options
- Memory layout configuration
- Device information passing

### Multiboot Protocol
Support for Multiboot and Multiboot2 specifications for cross-platform kernel loading.

**Features:**
- ELF kernel format support
- Module loading and enumeration
- Memory map provision
- Boot information structure
- Command line parsing
- Graphics mode setting

**Multiboot Capabilities:**
- Standard bootloader protocol compliance
- Cross-platform kernel compatibility
- Module management and metadata
- Memory mapping and allocation
- Boot device information
- Graphics initialization

### Limine Protocol
Modern boot protocol support for advanced boot environments.

**Capabilities:**
- Kernel loading and validation
- Module management system
- Graphics initialization and control
- Memory management functions
- Device tree support
- ACPI integration

### UEFI Chainloading
Chainloading support for other UEFI applications while preserving the UEFI environment.

**Chainload Process:**
1. Load target UEFI application into memory
2. Prepare execution environment
3. Transfer control to loaded application
4. Maintain UEFI services and protocols
5. Handle application return scenarios

**Features:**
- Protocol forwarding
- Image loading and validation
- Execution environment setup
- UEFI service preservation

### PXE Network Boot
Network-based kernel loading using PXE (Preboot Execution Environment).

**PXE Boot Flow:**
1. Network interface initialization and detection
2. DHCP client for IP address and boot server information
3. TFTP connection establishment with boot server
4. Kernel and initrd file download
5. Local boot process initiation

**Network Features:**
- DHCP configuration and address assignment
- TFTP file transfer protocol support
- Remote boot server connectivity
- Network device detection and configuration

## Protocol Selection

BloodHorn automatically detects and supports multiple protocols based on the kernel format and configuration:

- **Automatic Detection**: Identifies protocol based on file headers and signatures
- **Configuration Override**: Allows manual protocol selection via configuration
- **Fallback Support**: Provides fallback options for compatibility

## Implementation Notes

- All protocols maintain compatibility with existing standards
- Boot information structures are validated before use
- Memory management is handled per-protocol requirements
- Graphics and input support varies by protocol capabilities
