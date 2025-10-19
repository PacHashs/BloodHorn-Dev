# BloodHorn Coreboot Integration

## Overview

BloodHorn bootloader supports integration with Coreboot firmware, providing an alternative to traditional UEFI firmware. This integration allows BloodHorn to leverage Coreboot's direct hardware control while maintaining UEFI compatibility for broader system support.

## Coreboot Integration Benefits

### Hardware Control
- **Direct Hardware Access**: Coreboot provides more direct control over hardware initialization compared to UEFI abstraction layers
- **Reduced Complexity**: Eliminates some UEFI overhead in the boot chain
- **Better Understanding**: Educational value for understanding low-level hardware initialization

### Performance Improvements
- **Faster Initialization**: Coreboot can provide faster hardware detection and setup
- **Reduced Memory Usage**: Smaller firmware footprint may leave more RAM available
- **Efficient Resource Management**: More direct memory mapping capabilities

### Flexibility
- **Source Code Access**: Coreboot's open-source nature allows for customization
- **Mainboard Optimization**: Can be tailored for specific hardware configurations
- **Research Platform**: Enables experimentation with boot technologies

## Implementation Architecture

### Hybrid Approach
BloodHorn implements a hybrid architecture that automatically detects the available firmware:

```c
// Automatic firmware detection
if (CorebootPlatformInit()) {
    // Use Coreboot for hardware services
    CorebootInitGraphics();
    CorebootInitStorage();
    CorebootInitNetwork();
    // Use UEFI for higher-level services
} else {
    // Pure UEFI mode for compatibility
}
```

### Hardware Services by Coreboot
- CPU initialization and configuration
- Memory controller setup and mapping
- PCI/PCIe bus enumeration
- Storage controller support (SATA/AHCI/NVMe)
- USB host controller initialization
- Network interface setup
- Graphics framebuffer initialization
- TPM configuration

### Bootloader Services Retained
- Boot protocol support (Linux, Multiboot, Limine, etc.)
- Filesystem operations for kernel loading
- Boot menu and user interface
- Configuration file parsing
- Lua scripting support
- Plugin system
- Recovery shell
- Security verification

## Code Organization

The Coreboot integration is contained in the `coreboot/` directory:

- **`coreboot_platform.c`**: Coreboot platform initialization and interface functions
- **`coreboot_platform.h`**: API definitions for Coreboot platform services
- **`coreboot_payload.c`**: Coreboot payload interface implementation
- **`coreboot_payload.h`**: Payload interface definitions

## Key Features

### Memory Management
```c
// Get Coreboot memory map
UINT32 mem_map_count = 0;
CONST COREBOOT_MEM_ENTRY* mem_map = CorebootGetMemoryMap(&mem_map_count);

// Find suitable memory region for kernel
UINT64 kernel_base = 0;
UINT64 largest_size = 0;
for (UINT32 i = 0; i < mem_map_count; i++) {
    if (mem_map[i].type == CB_MEM_RAM && mem_map[i].size > largest_size) {
        kernel_base = mem_map[i].addr;
        largest_size = mem_map[i].size;
    }
}
```

### Graphics Support
```c
// Initialize graphics using Coreboot framebuffer
if (CorebootInitGraphics()) {
    CONST COREBOOT_FB* framebuffer = CorebootGetFramebuffer();
    if (framebuffer) {
        // Use framebuffer for display
        Print(L"Framebuffer: %ux%u @ 0x%llx\n",
              framebuffer->x_resolution,
              framebuffer->y_resolution,
              framebuffer->physical_address);
    }
}
```

### System Information
```c
// Get Coreboot system information
if (CorebootIsPresent()) {
    CONST COREBOOT_SYSINFO* sysinfo = CorebootGetSysinfo();
    Print(L"Coreboot version: %a\n", sysinfo->version);
}
```

## Building with Coreboot Support

### Prerequisites
1. **EDK2 Development Environment**: Standard EDK2 build tools and environment
2. **Coreboot Source Code**: Coreboot repository for integration
3. **Cross-compilation Tools**: GCC toolchain for target architecture

### Build Process
1. **Setup Coreboot**:
   ```bash
   git clone https://github.com/coreboot/coreboot.git
   cd coreboot
   git checkout 4.22  # Use stable version
   ```

2. **Configure Coreboot** for BloodHorn payload support

3. **Build BloodHorn** with Coreboot integration:
   ```bash
   build -p BloodHorn/BloodHorn.dsc -a X64 -b RELEASE
   ```

### Coreboot Configuration Example
```makefile
# Mainboard configuration
CONFIG_MAINBOARD_DIR="mainboard/google/octopus"

# Payload configuration for BloodHorn
CONFIG_PAYLOAD_ELF=y
CONFIG_PAYLOAD_FILE="../Build/BloodHorn/X64/RELEASE/BloodHorn.efi"

# Hardware support
CONFIG_USB=y
CONFIG_SATA=y
CONFIG_NVME=y
CONFIG_PCIEXP=y

# Graphics support
CONFIG_FRAMEBUFFER_KEEP_VESA_MODE=n

# Security features
CONFIG_TPM=y
```

## Running BloodHorn as Coreboot Payload

### Payload Interface
BloodHorn implements the standard Coreboot payload interface:

```c
VOID EFIAPI BloodhornPayloadEntry(
  IN VOID* coreboot_table,  // Coreboot table pointer
  IN VOID* payload         // Payload address
);
```

The payload entry point handles:
1. Coreboot platform interface initialization
2. Hardware device setup (graphics, storage, network)
3. Boot menu display and user interaction
4. Kernel loading and execution

### Memory Layout
Coreboot provides a memory map that BloodHorn uses for:
- Kernel loading in available RAM regions
- Framebuffer access for graphics display
- Stack and heap memory allocation
- Device memory mapping

## Security Integration

### TPM Support
Coreboot handles TPM initialization, and BloodHorn uses it for:
- Boot component measurement and verification
- Secure boot implementation
- Key management operations

### Secure Boot
Coreboot provides firmware-based secure boot capabilities, while BloodHorn adds:
- Kernel signature verification
- Filesystem integrity checking
- Measured boot support

## Platform Compatibility

### Supported Hardware
- **Mainboards**: Any Coreboot-supported x86 mainboard
- **CPUs**: x86_64 and compatible processors
- **Memory**: DDR3/DDR4 support via Coreboot memory controllers
- **Storage**: SATA/AHCI, NVMe via Coreboot drivers
- **Graphics**: Native VGA and framebuffer support
- **Network**: Ethernet controllers supported by Coreboot

### Boot Protocol Compatibility
All existing boot protocols continue to work:
- Linux kernel (bzImage, EFI stub)
- Multiboot 1 and 2
- Limine protocol
- Chainloading (GRUB, other bootloaders)
- PXE network boot
- BloodChain protocol

## Troubleshooting

### Common Issues

1. **Coreboot Table Not Found**
   - Verify Coreboot firmware is properly installed and configured
   - Check mainboard compatibility with Coreboot
   - Ensure payload is correctly built and integrated

2. **Graphics Issues**
   - Verify framebuffer configuration in Coreboot setup
   - Check graphics hardware compatibility
   - Ensure correct video mode selection

3. **Storage Detection**
   - Verify storage controller support in Coreboot configuration
   - Check device enumeration and filesystem support
   - Confirm proper partition setup

### Debug Information
Enable debug logging for troubleshooting:

```c
// Enable verbose logging
Print(L"Debug: Coreboot table at 0x%llx\n", coreboot_table);
// Add additional debug output as needed
```

## Migration from UEFI

### Key Differences

| Feature | UEFI/EDK2 | Coreboot |
|---------|-----------|----------|
| Hardware Init | UEFI Services | Coreboot Direct Control |
| Graphics | GOP Protocol | Framebuffer Direct Access |
| Memory | UEFI Memory Map | Coreboot Memory Map |
| Storage | UEFI FS Protocol | Coreboot Block Devices |
| Network | UEFI Network Stack | Coreboot Network Drivers |
| Security | UEFI Auth Variables | Coreboot TPM Integration |

### Code Changes Required
1. **Replace UEFI Protocol Usage**:
   ```c
   // UEFI approach
   gBS->LocateProtocol(&gEfiGraphicsOutputProtocolGuid, NULL, &Gop);

   // Coreboot approach
   VOID* framebuffer = CorebootGetFramebufferAddress();
   ```

2. **Update Memory Management**:
   ```c
   // Use Coreboot memory map
   CONST COREBOOT_MEM_ENTRY* mem_map = CorebootGetMemoryMap(&count);
   ```

3. **Adapt Device Access**:
   ```c
   // Use Coreboot device interfaces
   if (CorebootInitStorage()) {
       // Access storage devices directly
   }
   ```

## Development Status

The Coreboot integration is experimental and serves as a platform for learning about firmware internals and boot process optimization. While it provides benefits in specific scenarios, UEFI compatibility ensures broader system support.

## Support and Development

For Coreboot-specific issues:
1. Verify hardware compatibility with Coreboot
2. Check BloodHorn build configuration
3. Review Coreboot documentation for mainboard support
4. Consult community resources for troubleshooting

This integration makes BloodHorn a flexible bootloader suitable for both traditional UEFI systems and Coreboot-based firmware environments.
