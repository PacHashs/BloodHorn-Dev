/**
 * @file bootinfo.h
 * @brief Boot information structures for BloodHorn
 */

#ifndef BLOODHORN_BOOTINFO_H
#define BLOODHORN_BOOTINFO_H

#include <bloodhorn/types.h>
#include <bloodhorn/memory.h>
#include <bloodhorn/graphics.h>

#ifdef __cplusplus
extern "C" {
#endif

// Boot information version
#define BH_BOOTINFO_VERSION_MAJOR   1
#define BH_BOOTINFO_VERSION_MINOR   0
#define BH_BOOTINFO_VERSION_PATCH   0
#define BH_BOOTINFO_SIGNATURE       0x424F4F5452464E49ULL  // "INFOBOOT"

// Boot loader types
typedef enum {
    BH_BOOTLOADER_UNKNOWN = 0,
    BH_BOOTLOADER_BLOODHORN,
    BH_BOOTLOADER_GRUB2,
    BH_BOOTLOADER_SYSTEMD_BOOT,
    BH_BOOTLOADER_REFIND,
    BH_BOOTLOADER_CLOVER,
    BH_BOOTLOADER_OPENCORE,
    BH_BOOTLOADER_LIMINE,
    BH_BOOTLOADER_STIVALE2,
    BH_BOOTLOADER_MULTIBOOT,
    BH_BOOTLOADER_MULTIBOOT2,
    BH_BOOTLOADER_CUSTOM
} bh_bootloader_type_t;

// Platform types
typedef enum {
    BH_PLATFORM_UNKNOWN = 0,
    BH_PLATFORM_BIOS,
    BH_PLATFORM_UEFI,
    BH_PLATFORM_COREBOOT,
    BH_PLATFORM_OPENFIRMWARE,
    BH_PLATFORM_UBOOT,
    BH_PLATFORM_CUSTOM
} bh_platform_type_t;

// Architecture types
typedef enum {
    BH_ARCH_UNKNOWN = 0,
    BH_ARCH_X86,
    BH_ARCH_X86_64,
    BH_ARCH_ARM,
    BH_ARCH_ARM64,
    BH_ARCH_RISCV32,
    BH_ARCH_RISCV64,
    BH_ARCH_LOONGARCH64,
    BH_ARCH_MIPS,
    BH_ARCH_MIPS64,
    BH_ARCH_POWERPC,
    BH_ARCH_POWERPC64,
    BH_ARCH_SPARC,
    BH_ARCH_SPARC64
} bh_architecture_t;

// Boot method
typedef enum {
    BH_BOOT_METHOD_UNKNOWN = 0,
    BH_BOOT_METHOD_LOCAL_DISK,
    BH_BOOT_METHOD_USB,
    BH_BOOT_METHOD_CD_DVD,
    BH_BOOT_METHOD_NETWORK_PXE,
    BH_BOOT_METHOD_NETWORK_TFTP,
    BH_BOOT_METHOD_NETWORK_HTTP,
    BH_BOOT_METHOD_NETWORK_NBD,
    BH_BOOT_METHOD_MEMORY,
    BH_BOOT_METHOD_CUSTOM
} bh_boot_method_t;

// Boot flags
typedef enum {
    BH_BOOT_FLAG_NONE           = 0x00000000,
    BH_BOOT_FLAG_ACPI_PRESENT   = 0x00000001,
    BH_BOOT_FLAG_SMBIOS_PRESENT = 0x00000002,
    BH_BOOT_FLAG_EDD_PRESENT    = 0x00000004,
    BH_BOOT_FLAG_VBE_PRESENT    = 0x00000008,
    BH_BOOT_FLAG_APM_PRESENT    = 0x00000010,
    BH_BOOT_FLAG_SMP_PRESENT    = 0x00000020,
    BH_BOOT_FLAG_CMDLINE_PRESENT= 0x00000040,
    BH_BOOT_FLAG_MODULES_PRESENT= 0x00000080,
    BH_BOOT_FLAG_DRIVES_PRESENT = 0x00000100,
    BH_BOOT_FLAG_CONFIG_PRESENT = 0x00000200,
    BH_BOOT_FLAG_NETWORK_PRESENT= 0x00000400,
    BH_BOOT_FLAG_SECURE_BOOT    = 0x00000800,
    BH_BOOT_FLAG_MEASURED_BOOT  = 0x00001000,
    BH_BOOT_FLAG_DEBUG_ENABLED  = 0x00002000,
    BH_BOOT_FLAG_VERBOSE_BOOT   = 0x00004000,
    BH_BOOT_FLAG_RECOVERY_MODE  = 0x00008000
} bh_boot_flags_t;

// Module types
typedef enum {
    BH_MODULE_TYPE_UNKNOWN = 0,
    BH_MODULE_TYPE_KERNEL,
    BH_MODULE_TYPE_INITRD,
    BH_MODULE_TYPE_DRIVER,
    BH_MODULE_TYPE_FIRMWARE,
    BH_MODULE_TYPE_CONFIG,
    BH_MODULE_TYPE_DATA,
    BH_MODULE_TYPE_MICROCODE,
    BH_MODULE_TYPE_RAMDISK,
    BH_MODULE_TYPE_CUSTOM
} bh_module_type_t;

// Module information
typedef struct {
    bh_module_type_t type;
    bh_uint32_t flags;
    bh_phys_addr_t start;
    bh_phys_addr_t end;
    bh_size_t size;
    char name[128];
    char cmdline[256];
    bh_uint32_t checksum;
    void* data;
} bh_module_info_t;

// Drive information
typedef struct {
    bh_uint8_t drive_number;
    bh_uint8_t mode;
    bh_uint16_t cylinders;
    bh_uint8_t heads;
    bh_uint8_t sectors;
    bh_uint16_t ports[4];
    bh_uint64_t total_sectors;
    bh_uint32_t sector_size;
} bh_drive_info_t;

// EDD (Enhanced Disk Drive) information
typedef struct {
    bh_uint8_t device;
    bh_uint8_t version;
    bh_uint16_t interface_support;
    bh_uint64_t sectors;
    bh_uint16_t bytes_per_sector;
    bh_uint32_t edd_config_params;
    bh_uint16_t signature;
    bh_uint8_t device_path_length;
    bh_uint8_t reserved[3];
    char host_bus[4];
    char interface[8];
    bh_uint8_t device_path[16];
} bh_edd_info_t;

// Network boot information
typedef struct {
    bh_uint32_t flags;
    bh_uint8_t hwaddr[16];
    bh_uint8_t hwaddr_len;
    bh_uint8_t hwtype;
    bh_uint16_t reserved;
    bh_uint32_t client_ip;
    bh_uint32_t server_ip;
    bh_uint32_t gateway_ip;
    bh_uint32_t subnet_mask;
    char server_name[64];
    char boot_file[128];
    char dhcp_vendor[64];
} bh_network_info_t;

// ACPI RSDP information
typedef struct {
    char signature[8];
    bh_uint8_t checksum;
    char oemid[6];
    bh_uint8_t revision;
    bh_uint32_t rsdt_address;
    bh_uint32_t length;
    bh_uint64_t xsdt_address;
    bh_uint8_t extended_checksum;
    bh_uint8_t reserved[3];
} bh_rsdp_info_t;

// SMBIOS information
typedef struct {
    bh_uint16_t version_major;
    bh_uint16_t version_minor;
    bh_phys_addr_t table_address;
    bh_size_t table_length;
    bh_uint16_t structure_count;
} bh_smbios_info_t;

// VBE (VESA BIOS Extensions) information
typedef struct {
    bh_uint32_t mode;
    bh_phys_addr_t framebuffer;
    bh_uint32_t pitch;
    bh_uint32_t width;
    bh_uint32_t height;
    bh_uint8_t bpp;
    bh_uint8_t memory_model;
    bh_uint8_t red_field_position;
    bh_uint8_t red_mask_size;
    bh_uint8_t green_field_position;
    bh_uint8_t green_mask_size;
    bh_uint8_t blue_field_position;
    bh_uint8_t blue_mask_size;
    bh_uint8_t reserved_field_position;
    bh_uint8_t reserved_mask_size;
    bh_uint8_t direct_color_mode_info;
} bh_vbe_info_t;

// EFI system table information
typedef struct {
    bh_uint64_t signature;
    bh_uint32_t revision;
    bh_uint32_t header_size;
    bh_uint32_t crc32;
    bh_uint32_t reserved;
    bh_uint16_t* firmware_vendor;
    bh_uint32_t firmware_revision;
    bh_phys_addr_t runtime_services;
    bh_phys_addr_t boot_services;
    bh_size_t number_of_table_entries;
    bh_phys_addr_t configuration_table;
} bh_efi_info_t;

// CPU information
typedef struct {
    char vendor_string[16];
    char brand_string[48];
    bh_uint32_t vendor_id;
    bh_uint32_t signature;
    bh_uint32_t features_ecx;
    bh_uint32_t features_edx;
    bh_uint32_t extended_features_ebx;
    bh_uint32_t extended_features_ecx;
    bh_uint32_t max_cpuid_leaf;
    bh_uint32_t max_extended_leaf;
    bh_uint32_t family;
    bh_uint32_t model;
    bh_uint32_t stepping;
    bh_uint32_t type;
    bh_uint32_t cache_line_size;
    bh_uint32_t cores_per_package;
    bh_uint32_t threads_per_core;
    bh_uint64_t base_frequency;
    bh_uint64_t max_frequency;
    bh_uint64_t bus_frequency;
} bh_cpu_info_t;

// Platform information
typedef struct {
    bh_platform_type_t type;
    bh_architecture_t arch;
    bh_uint32_t arch_revision;
    char platform_name[64];
    char firmware_vendor[64];
    char firmware_version[32];
    bh_uint32_t firmware_revision;
    bh_uint64_t firmware_date;
} bh_platform_info_t;

// Bootloader information
typedef struct {
    bh_bootloader_type_t type;
    char name[64];
    char version[32];
    bh_uint32_t version_major;
    bh_uint32_t version_minor;
    bh_uint32_t version_patch;
    bh_uint32_t build_number;
    char build_date[32];
    char build_time[32];
    bh_uint32_t features;
} bh_bootloader_info_t;

// Security information
typedef struct {
    bh_bool_t secure_boot_enabled;
    bh_bool_t measured_boot_enabled;
    bh_bool_t tpm_present;
    bh_uint8_t tpm_version;
    bh_uint8_t tpm_family;
    bh_uint16_t tpm_vendor_id;
    bh_uint32_t tpm_revision;
    bh_uint32_t security_flags;
    char certificate_authority[64];
} bh_security_info_t;

// Main boot information structure
typedef struct {
    // Header
    bh_uint64_t signature;
    bh_uint32_t version_major;
    bh_uint32_t version_minor;
    bh_uint32_t version_patch;
    bh_uint32_t size;
    bh_uint32_t checksum;
    bh_boot_flags_t flags;

    // Basic information
    bh_boot_method_t boot_method;
    bh_bootloader_info_t bootloader;
    bh_platform_info_t platform;
    bh_cpu_info_t cpu;

    // Memory information
    bh_memory_map_t memory_map;
    bh_phys_addr_t kernel_start;
    bh_phys_addr_t kernel_end;
    bh_size_t kernel_size;

    // Graphics information
    bh_graphics_info_t graphics;
    bh_vbe_info_t vbe;

    // Command line and modules
    char* command_line;
    bh_uint32_t module_count;
    bh_module_info_t* modules;

    // Hardware information
    bh_uint32_t drive_count;
    bh_drive_info_t* drives;
    bh_edd_info_t* edd_info;
    bh_network_info_t* network;

    // Firmware tables
    bh_rsdp_info_t* rsdp;
    bh_smbios_info_t* smbios;
    bh_efi_info_t* efi;

    // Security information
    bh_security_info_t security;

    // Timestamps
    bh_uint64_t boot_time;
    bh_uint64_t kernel_load_time;
    bh_uint64_t init_start_time;

    // Configuration
    char* config_file;
    bh_size_t config_size;
    void* custom_data;
    bh_size_t custom_data_size;

    // Reserved for future use
    bh_uint64_t reserved[16];

} bh_boot_info_t;

/**
 * @brief Initialize boot information structure
 * 
 * @param info Boot information structure to initialize
 * @return bh_status_t Status code
 */
bh_status_t bh_bootinfo_initialize(bh_boot_info_t* info);

/**
 * @brief Validate boot information structure
 * 
 * @param info Boot information structure to validate
 * @return bh_status_t Status code
 */
bh_status_t bh_bootinfo_validate(const bh_boot_info_t* info);

/**
 * @brief Calculate checksum for boot information
 * 
 * @param info Boot information structure
 * @return bh_uint32_t Calculated checksum
 */
bh_uint32_t bh_bootinfo_calculate_checksum(const bh_boot_info_t* info);

/**
 * @brief Add module to boot information
 * 
 * @param info Boot information structure
 * @param module Module information to add
 * @return bh_status_t Status code
 */
bh_status_t bh_bootinfo_add_module(bh_boot_info_t* info, const bh_module_info_t* module);

/**
 * @brief Find module by name
 * 
 * @param info Boot information structure
 * @param name Module name to search for
 * @return bh_module_info_t* Module information or NULL if not found
 */
bh_module_info_t* bh_bootinfo_find_module(const bh_boot_info_t* info, const char* name);

/**
 * @brief Find module by type
 * 
 * @param info Boot information structure
 * @param type Module type to search for
 * @return bh_module_info_t* First module of specified type or NULL if not found
 */
bh_module_info_t* bh_bootinfo_find_module_by_type(const bh_boot_info_t* info, bh_module_type_t type);

/**
 * @brief Get all modules of specified type
 * 
 * @param info Boot information structure
 * @param type Module type to search for
 * @param modules [out] Array to store found modules
 * @param max_modules Maximum number of modules to return
 * @return bh_size_t Number of modules found
 */
bh_size_t bh_bootinfo_get_modules_by_type(
    const bh_boot_info_t* info,
    bh_module_type_t type,
    bh_module_info_t* modules,
    bh_size_t max_modules
);

/**
 * @brief Print boot information summary
 * 
 * @param info Boot information structure
 */
void bh_bootinfo_print_summary(const bh_boot_info_t* info);

/**
 * @brief Print detailed boot information
 * 
 * @param info Boot information structure
 */
void bh_bootinfo_print_detailed(const bh_boot_info_t* info);

/**
 * @brief Serialize boot information to buffer
 * 
 * @param info Boot information structure
 * @param buffer Output buffer
 * @param buffer_size Size of output buffer
 * @param written [out] Number of bytes written
 * @return bh_status_t Status code
 */
bh_status_t bh_bootinfo_serialize(
    const bh_boot_info_t* info,
    void* buffer,
    bh_size_t buffer_size,
    bh_size_t* written
);

/**
 * @brief Deserialize boot information from buffer
 * 
 * @param buffer Input buffer
 * @param buffer_size Size of input buffer
 * @param info [out] Boot information structure
 * @return bh_status_t Status code
 */
bh_status_t bh_bootinfo_deserialize(
    const void* buffer,
    bh_size_t buffer_size,
    bh_boot_info_t* info
);

/**
 * @brief Free resources allocated for boot information
 * 
 * @param info Boot information structure
 */
void bh_bootinfo_cleanup(bh_boot_info_t* info);

// Global boot information pointer
extern bh_boot_info_t* bh_boot_info;

// Convenience macros
#define BH_BOOTINFO_HAS_FLAG(info, flag) (((info)->flags & (flag)) != 0)
#define BH_BOOTINFO_SET_FLAG(info, flag) ((info)->flags |= (flag))
#define BH_BOOTINFO_CLEAR_FLAG(info, flag) ((info)->flags &= ~(flag))

// String conversion functions
const char* bh_bootloader_type_to_string(bh_bootloader_type_t type);
const char* bh_platform_type_to_string(bh_platform_type_t type);
const char* bh_architecture_to_string(bh_architecture_t arch);
const char* bh_boot_method_to_string(bh_boot_method_t method);
const char* bh_module_type_to_string(bh_module_type_t type);

#ifdef __cplusplus
}
#endif

#endif // BLOODHORN_BOOTINFO_H
