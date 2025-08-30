# Configuration System

```
CONFIGURATION FILE FORMATS:

INI FORMAT (bloodhorn.ini):
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

JSON FORMAT (bloodhorn.json):
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

ENVIRONMENT VARIABLES:
BLOODHORN_DEFAULT=linux
BLOODHORN_MENU_TIMEOUT=5
BLOODHORN_LINUX_KERNEL=/boot/vmlinuz
BLOODHORN_LINUX_INITRD=/boot/initrd.img
BLOODHORN_LINUX_CMDLINE=root=/dev/sda1 ro
BLOODHORN_THEME_BACKGROUND=0x000080
BLOODHORN_THEME_TEXT=0xFFFFFF
BLOODHORN_LANGUAGE=en
BLOODHORN_RECOVERY_ENABLED=1
BLOODHORN_SECURE_BOOT=1

CONFIGURATION LOADING PRIORITY:
1. INI file (bloodhorn.ini)
2. JSON file (bloodhorn.json)
3. Environment variables
4. Built-in defaults

THEME CONFIGURATION:
- background_color: Boot menu background (RGB hex)
- header_color: Title and header text color
- highlight_color: Menu selection highlight
- text_color: Regular menu text color
- selected_text_color: Selected item text color
- footer_color: Footer/status text color
- background_image: Background image file (BMP format)

LANGUAGE SETTINGS:
Supported Languages:
- en: English (default)
- es: Spanish
- fr: French
- de: German
- ja: Japanese
- zh: Chinese
- ru: Russian
- ar: Arabic

BOOT ENTRY CONFIGURATION:
Each boot entry can specify:
- kernel: Kernel image path
- initrd: Initial ramdisk path
- cmdline: Kernel command line arguments
- loader: UEFI application path (for chainloading)
- description: Human-readable description
- icon: Boot entry icon file
- hotkey: Keyboard shortcut key
- hidden: Hide from menu (boolean)
- secure: Require secure boot (boolean)

NETWORK CONFIGURATION:
- dhcp_enabled: Use DHCP for network configuration
- static_ip: Static IP address
- netmask: Network subnet mask
- gateway: Default gateway address
- dns_server: DNS server address
- boot_server: PXE boot server address
- tftp_server: TFTP server address
- http_server: HTTP boot server address

SECURITY CONFIGURATION:
- secure_boot: Enable secure boot verification
- measured_boot: Enable TPM measurements
- recovery_password: Recovery mode password hash
- shell_password: Shell access password hash
- timeout_action: Action after timeout (boot/shutdown/reboot)
- emergency_shell: Enable emergency shell access

VALIDATION RULES:
- Timeout values: 0-300 seconds
- Color values: 24-bit RGB (0x000000-0xFFFFFF)
- File paths: Absolute paths starting with /
- Boolean values: true/false, 1/0, yes/no
- Language codes: ISO 639-1 two-letter codes
- Network addresses: Valid IPv4 format
```
