#ifndef BLOODHORN_FILE_UTILS_H
#define BLOODHORN_FILE_UTILS_H

#include <Uefi.h>
#include "../compat.h"

EFI_STATUS get_root_dir(EFI_FILE_HANDLE* root_dir);

#endif // BLOODHORN_FILE_UTILS_H
