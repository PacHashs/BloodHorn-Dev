# BloodHorn Library API

```
BLOODHORN DEVELOPMENT LIBRARY (boot/libb/):

CORE INITIALIZATION:
bh_status_t bh_initialize(bh_system_table_t* system_table)
- Initialize the BloodHorn library
- Set up system services integration
- Returns: BH_SUCCESS or error code

void bh_shutdown(void)
- Shutdown the library and cleanup resources
- Should be called before bootloader exit

bool bh_is_initialized(void)
- Check if library is initialized
- Returns: true if initialized, false otherwise

void bh_get_version(uint32_t* major, uint32_t* minor, uint32_t* patch)
- Get library version information
- Parameters: pointers to store version components

MEMORY MANAGEMENT:
void* bh_malloc(bh_size_t size)
- Allocate memory block
- Returns: pointer to allocated memory or NULL

void bh_free(void* ptr)
- Free allocated memory block
- Parameters: pointer to memory to free

bh_status_t bh_memory_copy(void* dest, const void* src, bh_size_t size)
- Copy memory between locations
- Handles overlapping regions safely

bh_status_t bh_memory_set(void* dest, int value, bh_size_t size)
- Set memory to specific value
- Similar to memset function

bh_status_t bh_memory_compare(const void* ptr1, const void* ptr2, bh_size_t size, int* result)
- Compare memory regions
- Returns comparison result in result parameter

CONSOLE OUTPUT:
void bh_putc(char c)
- Output single character to console
- Uses system table putc function or default

void bh_puts(const char* str)
- Output string to console with newline
- Null-terminated string parameter

void bh_printf(const char* format, ...)
- Formatted output to console
- Supports basic format specifiers (%d, %s, %x, %p, %c)

STRING OPERATIONS:
bh_size_t bh_string_length(const char* str)
- Get length of null-terminated string
- Returns: string length in characters

bh_status_t bh_string_copy(char* dest, const char* src, bh_size_t dest_size)
- Safe string copy with bounds checking
- Ensures null termination

STATUS HANDLING:
const char* bh_status_to_string(bh_status_t status)
- Convert status code to human-readable string
- Returns: string description of status code

STATUS CODES:
BH_SUCCESS                - Operation completed successfully
BH_PENDING               - Operation is pending
BH_TIMEOUT               - Operation timed out
BH_ERROR                 - Generic error
BH_INVALID_ARGUMENT      - Invalid argument provided
BH_INVALID_HANDLE        - Invalid handle provided
BH_INVALID_OPERATION     - Invalid operation attempted
BH_NOT_IMPLEMENTED       - Functionality not implemented
BH_NOT_SUPPORTED         - Operation not supported
BH_ACCESS_DENIED         - Access denied
BH_OUT_OF_MEMORY         - Out of memory
BH_OUT_OF_RESOURCES      - Out of resources
BH_DEVICE_ERROR          - Device error occurred
BH_IO_ERROR              - I/O error occurred
BH_NOT_FOUND             - Resource not found
BH_BUFFER_TOO_SMALL      - Buffer too small
BH_ALREADY_EXISTS        - Resource already exists

GRAPHICS API (graphics.h):
bh_status_t bh_graphics_initialize(const bh_graphics_init_params_t* params)
- Initialize graphics subsystem
- Configure display mode and parameters

bh_status_t bh_graphics_get_framebuffer(bh_framebuffer_t* fb)
- Get framebuffer information
- Returns display buffer details

bh_status_t bh_graphics_clear(bh_color_t color)
- Clear screen with specified color
- 32-bit RGBA color value

bh_status_t bh_graphics_draw_rect(const bh_rect_t* rect, bh_color_t color, bool filled)
- Draw rectangle on screen
- Supports filled and outline modes

bh_status_t bh_graphics_draw_text(const char* text, int32_t x, int32_t y, bh_color_t color, const bh_font_t* font)
- Render text at specified position
- Font parameter can be NULL for default

MEMORY MANAGEMENT API (memory.h):
void* bh_memory_allocate(bh_size_t size, bh_size_t alignment, bh_memory_flags_t flags)
- Allocate aligned memory with flags
- Supports various memory types

void bh_memory_free(void* ptr, bh_size_t size)
- Free allocated memory
- Size parameter for validation

bh_status_t bh_memory_get_map(bh_memory_map_t* map)
- Get system memory map
- Returns available memory regions

bh_status_t bh_memory_protect(void* addr, bh_size_t size, bh_protection_t prot)
- Set memory protection attributes
- Configure read/write/execute permissions

INPUT SYSTEM API (input.h):
bh_status_t bh_input_initialize(void)
- Initialize input subsystem
- Set up keyboard and mouse handling

void bh_input_poll_events(void)
- Poll for input events
- Should be called regularly

bh_input_action_t bh_input_get_key(bh_key_t key)
- Get key state (pressed/released)
- Returns current key status

bh_input_action_t bh_input_get_mouse_button(bh_mouse_button_t button)
- Get mouse button state
- Returns button press status

void bh_input_get_cursor_pos(double* xpos, double* ypos)
- Get current mouse cursor position
- Returns coordinates in screen space

FILESYSTEM API (fs.h):
bh_status_t bh_fs_initialize(void)
- Initialize filesystem subsystem
- Set up filesystem drivers

bh_status_t bh_file_open(const char* path, bh_file_mode_t mode, bh_file_t** file)
- Open file for reading/writing
- Returns file handle

bh_status_t bh_file_read(bh_file_t* file, void* buffer, bh_size_t size, bh_size_t* bytes_read)
- Read data from file
- Returns actual bytes read

bh_status_t bh_file_write(bh_file_t* file, const void* buffer, bh_size_t size, bh_size_t* bytes_written)
- Write data to file
- Returns actual bytes written

bh_status_t bh_file_close(bh_file_t* file)
- Close file handle
- Free associated resources

bool bh_file_exists(const char* path)
- Check if file exists
- Returns true if file found

TIME API (time.h):
bh_uint64_t bh_get_timestamp(void)
- Get high-resolution timestamp
- Returns nanoseconds since boot

bh_uint64_t bh_get_performance_counter(void)
- Get performance counter value
- Platform-specific high-resolution timer

bh_status_t bh_sleep_microseconds(bh_uint64_t microseconds)
- Sleep for specified microseconds
- Non-busy wait implementation

bh_status_t bh_get_time(bh_time_t* time, bh_time_capabilities_t* capabilities)
- Get current system time
- Returns time structure with date/time

DEBUG API (debug.h):
bh_status_t bh_debug_initialize(const bh_debug_config_t* config)
- Initialize debug subsystem
- Configure logging and output

void bh_debug_print(bh_debug_level_t level, bh_debug_category_t category, const char* file, bh_uint32_t line, const char* function, const char* format, ...)
- Print debug message
- Supports filtering by level and category

void bh_debug_hexdump(const void* data, bh_size_t size, bh_uintptr_t address)
- Print hexadecimal dump of memory
- Useful for debugging binary data

void bh_debug_break(void)
- Trigger debugger breakpoint
- Platform-specific debug interrupt

BOOT INFO API (bootinfo.h):
bh_status_t bh_bootinfo_initialize(bh_boot_info_t* info)
- Initialize boot information structure
- Set up for kernel handoff

bh_status_t bh_bootinfo_add_module(bh_boot_info_t* info, const bh_module_info_t* module)
- Add module to boot information
- Include kernel, initrd, drivers

bh_module_info_t* bh_bootinfo_find_module(const bh_boot_info_t* info, const char* name)
- Find module by name
- Returns module information or NULL

void bh_bootinfo_print_summary(const bh_boot_info_t* info)
- Print boot information summary
- Display loaded modules and settings

SYSTEM TABLE STRUCTURE:
typedef struct {
    // Memory management functions
    void* (*alloc)(bh_size_t size);
    void (*free)(void* ptr);
    
    // Console output functions
    void (*putc)(char c);
    void (*puts)(const char* str);
    void (*printf)(const char* format, ...);
    
    // System information functions
    bh_status_t (*get_memory_map)(bh_memory_descriptor_t** map, bh_size_t* map_size, bh_size_t* descriptor_size);
    bh_status_t (*get_graphics_info)(bh_graphics_info_t* info);
    void* (*get_rsdp)(void);
    void* (*get_boot_device)(void);
    
    // Power management functions
    void (*reboot)(void);
    void (*shutdown)(void);
    
    // Debug functions
    void (*debug_break)(void);
} bh_system_table_t;

INTEGRATION WITH UEFI:
The library integrates with UEFI services:
- Memory allocation uses UEFI AllocatePool/FreePool
- Console output redirects to UEFI console or serial
- Graphics uses UEFI Graphics Output Protocol
- File operations use UEFI Simple File System Protocol
- Time services use UEFI runtime services

ERROR HANDLING:
All functions return status codes for error checking
Use BH_SUCCEEDED(status) and BH_FAILED(status) macros
Convert status codes to strings with bh_status_to_string()
Debug builds include additional error checking and logging
```
