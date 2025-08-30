#ifndef BLOODHORN_FILE_UTILS_H
#define BLOODHORN_FILE_UTILS_H

#include <Uefi.h>
#include "../compat.h"

// Function declarations for file utilities
VOID* LoadImageFile(IN CONST CHAR16* FileName);
EFI_STATUS LoadFileToMemory(IN CONST CHAR8* FilePath, IN OUT EFI_PHYSICAL_ADDRESS* LoadAddress, OUT UINTN* FileSize);
BOOLEAN FileExists(IN CONST CHAR8* FilePath);
BOOLEAN CompareGuid(IN CONST EFI_GUID* Guid1, IN CONST EFI_GUID* Guid2);
UINT64 ALIGN_UP(IN UINT64 Value, IN UINT64 Alignment);

#endif // BLOODHORN_FILE_UTILS_H
