# Configuration System

## Overview

BloodHorn supports multiple configuration methods to customize boot behavior, themes, and system settings. Configuration can be specified through files or environment variables, with a defined priority order.

## Configuration File Formats

### INI Format (`bloodhorn.ini`)

```ini
[boot]
default = linux
menu_timeout = 5
theme_background_color = 0x000080
theme_header_color = 0xFFFFFF
theme_highlight_color = 0xFF8000
theme_text_color = 0xFFFFFF
theme_selected_text_color = 0x000000
theme_footer_color = 0xC0C0C0
theme_background_image = background.bmp
language = en

[linux]
kernel = /boot/vmlinuz
initrd = /boot/initrd.img
cmdline = root=/dev/sda1 ro quiet splash

[windows]
loader = /EFI/Microsoft/Boot/bootmgfw.efi
description = Windows Boot Manager

[recovery]
enabled = true
timeout = 30
shell_access = true
```

### JSON Format (`bloodhorn.json`)

```json
{
  "boot": {
    "default": "linux",
    "menu_timeout": 5,
    "theme": {
      "background_color": "0x000080",
      "header_color": "0xFFFFFF",
      "highlight_color": "0xFF8000",
      "text_color": "0xFFFFFF",
      "selected_text_color": "0x000000",
      "footer_color": "0xC0C0C0",
      "background_image": "background.bmp"
    },
    "language": "en"
  },
  "entries": {
    "linux": {
      "kernel": "/boot/vmlinuz",
      "initrd": "/boot/initrd.img",
      "cmdline": "root=/dev/sda1 ro quiet splash"
    },
    "windows": {
      "loader": "/EFI/Microsoft/Boot/bootmgfw.efi",
      "description": "Windows Boot Manager"
    }
  },
  "recovery": {
    "enabled": true,
    "timeout": 30,
    "shell_access": true
  }
}
```

## Environment Variables

BloodHorn can be configured using environment variables with the `BLOODHORN_` prefix:

```bash
export BLOODHORN_DEFAULT=linux
export BLOODHORN_MENU_TIMEOUT=5
export BLOODHORN_LINUX_KERNEL=/boot/vmlinuz
export BLOODHORN_LINUX_INITRD=/boot/initrd.img
export BLOODHORN_LINUX_CMDLINE="root=/dev/sda1 ro"
export BLOODHORN_THEME_BACKGROUND=0x000080
export BLOODHORN_THEME_TEXT=0xFFFFFF
export BLOODHORN_LANGUAGE=en
export BLOODHORN_RECOVERY_ENABLED=1
export BLOODHORN_SECURE_BOOT=1
```

## Configuration Loading Priority

BloodHorn loads configuration in the following order (later sources override earlier ones):

1. **INI file** (`bloodhorn.ini`)
2. **JSON file** (`bloodhorn.json`)
3. **Environment variables** (`BLOODHORN_*`)
4. **Built-in defaults**

## Boot Configuration Options

### Global Settings
- `default`: Default boot entry name
- `menu_timeout`: Menu timeout in seconds (0-300)
- `language`: Interface language (en, es, fr, de, etc.)
- `theme_*`: Theme color and appearance settings

### Boot Entry Configuration
Each boot entry supports the following options:

- `kernel`: Path to kernel image file
- `initrd`: Path to initial ramdisk file
- `cmdline`: Kernel command line arguments
- `loader`: Path to UEFI application for chainloading
- `description`: Human-readable description for menu
- `hidden`: Hide entry from boot menu (true/false)
- `hotkey`: Keyboard shortcut key for quick selection

## Theme Configuration

### Color Settings
- `theme_background_color`: Boot menu background color (RGB hex, e.g., 0x000080)
- `theme_header_color`: Title and header text color
- `theme_highlight_color`: Menu selection highlight color
- `theme_text_color`: Regular menu text color
- `theme_selected_text_color`: Selected item text color
- `theme_footer_color`: Footer and status text color

### Visual Elements
- `theme_background_image`: Background image file path (BMP format supported)

## Network Configuration

Network settings for PXE boot and remote configuration:

- `dhcp_enabled`: Enable DHCP for automatic network configuration (true/false)
- `static_ip`: Static IP address (IPv4 format)
- `netmask`: Network subnet mask
- `gateway`: Default gateway address
- `dns_server`: DNS server address
- `boot_server`: PXE boot server address
- `tftp_server`: TFTP server address

## Security Configuration

- `secure_boot`: Enable secure boot verification (true/false)
- `measured_boot`: Enable TPM-based boot measurements (true/false)
- `recovery_password`: Password hash for recovery mode access
- `shell_password`: Password hash for shell access
- `timeout_action`: Action after menu timeout (boot/shutdown/reboot)
- `emergency_shell`: Enable emergency shell access (true/false)

## Supported Languages

BloodHorn supports multiple interface languages:

- `en`: English (default)
- `es`: Spanish
- `fr`: French
- `de`: German
- `ja`: Japanese
- `zh`: Chinese
- `ru`: Russian
- `ar`: Arabic

## Validation Rules

- **Timeout values**: 0-300 seconds
- **Color values**: 24-bit RGB hexadecimal (0x000000-0xFFFFFF)
- **File paths**: Absolute paths starting with `/`
- **Boolean values**: `true`/`false`, `1`/`0`, `yes`/`no`
- **Language codes**: ISO 639-1 two-letter codes
- **Network addresses**: Valid IPv4 address format

## Configuration Examples

### Simple Linux Boot
```ini
[boot]
default = linux
menu_timeout = 10

[linux]
kernel = /boot/vmlinuz
initrd = /boot/initrd.img
cmdline = root=/dev/sda1 ro quiet
```

### Multi-Boot Setup
```ini
[boot]
default = linux
menu_timeout = 5

[linux]
kernel = /boot/vmlinuz-linux
initrd = /boot/initrd-linux.img
cmdline = root=/dev/sda1 ro quiet

[windows]
loader = /EFI/Microsoft/Boot/bootmgfw.efi
description = Windows 10

[recovery]
enabled = true
timeout = 30
```

### Network Boot Configuration
```ini
[boot]
default = pxe
menu_timeout = 15

[network]
dhcp_enabled = true
boot_server = 192.168.1.100
tftp_server = 192.168.1.100

[pxe]
kernel = /boot/kernel.efi
initrd = /boot/initrd.img
cmdline = root=/dev/nfs nfsroot=192.168.1.100:/nfs/root rw
```

## Troubleshooting Configuration

If configuration files are not loading properly:

1. Verify file syntax and format
2. Check file permissions and location
3. Ensure environment variables are properly set
4. Review BloodHorn logs for parsing errors
5. Test with minimal configuration to isolate issues
