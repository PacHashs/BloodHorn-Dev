# BloodHorn Library API

## Overview

The BloodHorn development library (`boot/libb/`) provides a set of APIs for hardware abstraction, system services, and boot information management. It serves as a foundation for bootloader development and system integration.

## Core Library Functions

### Initialization and Management

```c
bh_status_t bh_initialize(bh_system_table_t* system_table)
```
Initialize the BloodHorn library with system service integration.
- **Parameters**: `system_table` - System service function table
- **Returns**: `BH_SUCCESS` or error status code

```c
void bh_shutdown(void)
```
Shutdown the library and cleanup resources. Should be called before bootloader exit.

```c
bool bh_is_initialized(void)
```
Check if library is initialized.
- **Returns**: `true` if initialized, `false` otherwise

```c
void bh_get_version(uint32_t* major, uint32_t* minor, uint32_t* patch)
```
Get library version information.
- **Parameters**: Pointers to store version components

### Memory Management

```c
void* bh_malloc(bh_size_t size)
```
Allocate memory block.
- **Parameters**: `size` - Size of memory to allocate
- **Returns**: Pointer to allocated memory or `NULL` on failure

```c
void bh_free(void* ptr)
```
Free allocated memory block.
- **Parameters**: `ptr` - Pointer to memory to free

```c
bh_status_t bh_memory_copy(void* dest, const void* src, bh_size_t size)
```
Copy memory between locations with overlap handling.

```c
bh_status_t bh_memory_set(void* dest, int value, bh_size_t size)
```
Set memory region to specific value.

### Console Output

```c
void bh_putc(char c)
```
Output single character to console.

```c
void bh_puts(const char* str)
```
Output null-terminated string to console.

```c
void bh_printf(const char* format, ...)
```
Formatted output to console with basic format specifiers (`%d`, `%s`, `%x`, `%p`, `%c`).

### String Operations

```c
bh_size_t bh_string_length(const char* str)
```
Get length of null-terminated string.

```c
bh_status_t bh_string_copy(char* dest, const char* src, bh_size_t dest_size)
```
Safe string copy with bounds checking and null termination.

### Status Handling

```c
const char* bh_status_to_string(bh_status_t status)
```
Convert status code to human-readable string.

**Common Status Codes:**
- `BH_SUCCESS` - Operation completed successfully
- `BH_ERROR` - Generic error
- `BH_INVALID_ARGUMENT` - Invalid argument provided
- `BH_OUT_OF_MEMORY` - Out of memory
- `BH_NOT_FOUND` - Resource not found
- `BH_NOT_IMPLEMENTED` - Functionality not implemented

## Graphics API

### Graphics Initialization

```c
bh_status_t bh_graphics_initialize(const bh_graphics_init_params_t* params)
```
Initialize graphics subsystem with display configuration.

```c
bh_status_t bh_graphics_get_framebuffer(bh_framebuffer_t* fb)
```
Get framebuffer information for display operations.

### Drawing Operations

```c
bh_status_t bh_graphics_clear(bh_color_t color)
```
Clear screen with specified 32-bit RGBA color.

```c
bh_status_t bh_graphics_draw_rect(const bh_rect_t* rect, bh_color_t color, bool filled)
```
Draw rectangle (filled or outline) at specified coordinates.

```c
bh_status_t bh_graphics_draw_text(const char* text, int32_t x, int32_t y, bh_color_t color, const bh_font_t* font)
```
Render text at specified position with optional font.

## Memory Management API

### Advanced Memory Operations

```c
void* bh_memory_allocate(bh_size_t size, bh_size_t alignment, bh_memory_flags_t flags)
```
Allocate aligned memory with specific flags.

```c
void bh_memory_free(void* ptr, bh_size_t size)
```
Free allocated memory with size validation.

```c
bh_status_t bh_memory_get_map(bh_memory_map_t* map)
```
Get system memory map with region information.

```c
bh_status_t bh_memory_protect(void* addr, bh_size_t size, bh_protection_t prot)
```
Set memory protection attributes (read/write/execute).

## Input System API

### Input Initialization

```c
bh_status_t bh_input_initialize(void)
```
Initialize input subsystem for keyboard and mouse handling.

```c
void bh_input_poll_events(void)
```
Poll for input events (should be called regularly).

### Key and Mouse Input

```c
bh_input_action_t bh_input_get_key(bh_key_t key)
```
Get key state (pressed/released).

```c
bh_input_action_t bh_input_get_mouse_button(bh_mouse_button_t button)
```
Get mouse button state.

```c
void bh_input_get_cursor_pos(double* xpos, double* ypos)
```
Get current mouse cursor position.

## Filesystem API

### File Operations

```c
bh_status_t bh_file_open(const char* path, bh_file_mode_t mode, bh_file_t** file)
```
Open file for reading/writing.

```c
bh_status_t bh_file_read(bh_file_t* file, void* buffer, bh_size_t size, bh_size_t* bytes_read)
```
Read data from file.

```c
bh_status_t bh_file_write(bh_file_t* file, const void* buffer, bh_size_t size, bh_size_t* bytes_written)
```
Write data to file.

```c
bh_status_t bh_file_close(bh_file_t* file)
```
Close file handle.

```c
bool bh_file_exists(const char* path)
```
Check if file exists.

## Time API

### Timing Functions

```c
bh_uint64_t bh_get_timestamp(void)
```
Get high-resolution timestamp in nanoseconds since boot.

```c
bh_status_t bh_sleep_microseconds(bh_uint64_t microseconds)
```
Sleep for specified microseconds (non-busy wait).

## Debug API

### Debug Operations

```c
void bh_debug_print(bh_debug_level_t level, bh_debug_category_t category, const char* file, bh_uint32_t line, const char* function, const char* format, ...)
```
Print debug message with filtering by level and category.

```c
void bh_debug_hexdump(const void* data, bh_size_t size, bh_uintptr_t address)
```
Print hexadecimal dump of memory region.

```c
void bh_debug_break(void)
```
Trigger debugger breakpoint.

## Boot Information API

### Boot Info Management

```c
bh_status_t bh_bootinfo_initialize(bh_boot_info_t* info)
```
Initialize boot information structure for kernel handoff.

```c
bh_status_t bh_bootinfo_add_module(bh_boot_info_t* info, const bh_module_info_t* module)
```
Add module (kernel, initrd, drivers) to boot information.

```c
bh_module_info_t* bh_bootinfo_find_module(const bh_boot_info_t* info, const char* name)
```
Find module by name in boot information.

```c
void bh_bootinfo_print_summary(const bh_boot_info_t* info)
```
Print summary of loaded modules and boot settings.

## System Table Integration

The library integrates with system services through the `bh_system_table_t` structure:

```c
typedef struct {
    // Memory management
    void* (*alloc)(bh_size_t size);
    void (*free)(void* ptr);

    // Console output
    void (*putc)(char c);
    void (*puts)(const char* str);
    void (*printf)(const char* format, ...);

    // System information
    bh_status_t (*get_memory_map)(bh_memory_descriptor_t** map, bh_size_t* map_size, bh_size_t* descriptor_size);
    bh_status_t (*get_graphics_info)(bh_graphics_info_t* info);
    void* (*get_rsdp)(void);
    void* (*get_boot_device)(void);

    // Power management
    void (*reboot)(void);
    void (*shutdown)(void);

    // Debug support
    void (*debug_break)(void);
} bh_system_table_t;
```

## UEFI Integration

The library integrates with UEFI services:
- Memory allocation uses UEFI `AllocatePool`/`FreePool`
- Console output redirects to UEFI console or serial port
- Graphics uses UEFI Graphics Output Protocol
- File operations use UEFI Simple File System Protocol
- Time services use UEFI runtime services

## Error Handling

All API functions return status codes for comprehensive error checking:

```c
// Check for success or failure
if (BH_SUCCEEDED(status)) {
    // Operation successful
} else {
    // Handle error
    const char* error_msg = bh_status_to_string(status);
    bh_debug_print(BH_DEBUG_ERROR, BH_DEBUG_GENERAL, __FILE__, __LINE__, __FUNCTION__,
                   "Operation failed: %s", error_msg);
}
```

Debug builds include additional error checking, logging, and validation.

## Usage Example

```c
#include <bloodhorn/bloodhorn.h>

// Initialize library with UEFI system table
bh_system_table_t system_table = {
    .alloc = (void* (*)(bh_size_t))AllocatePool,
    .free = (void (*)(void*))FreePool,
    .putc = bh_uefi_putc,
    .puts = bh_uefi_puts,
    .printf = (void (*)(const char*, ...))Print,
    // ... other function pointers
};

bh_status_t status = bh_initialize(&system_table);
if (BH_SUCCEEDED(status)) {
    // Library ready for use
    bh_printf("BloodHorn library initialized\n");
}
```

## Development Notes

- All functions are thread-safe where applicable
- Memory allocations are tracked for debugging
- Graphics operations are hardware-agnostic
- File operations support multiple filesystem types
- Debug output can be filtered by category and level
