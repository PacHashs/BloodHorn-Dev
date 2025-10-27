/*
 * BloodHorn Bootloader
 *
 * This file is part of BloodHorn and is licensed under the MIT License.
 * See the root of the repository for license details.
 */
#include "theme.h"
#include "compat.h"
#include "localization.h"
#include "../config/config_ini.h"
#include "../config/config_json.h"
#include "../config/config_env.h"

static struct BootMenuTheme current_theme = {
    .background_color = 0x1A1A2E,
    .header_color = 0x2D2D4F,
    .highlight_color = 0x4A4A8A,
    .text_color = 0xCCCCCC,
    .selected_text_color = 0xFFFFFF,
    .footer_color = 0x8888AA,
    .background_image = NULL
};

void SetBootMenuTheme(const struct BootMenuTheme* theme) {
    memcpy(&current_theme, theme, sizeof(struct BootMenuTheme));
}
const struct BootMenuTheme* GetBootMenuTheme(void) {
    return &current_theme;
}

/**
 * Load theme and language configuration from config files
 */
void LoadThemeAndLanguageFromConfig(void) {
    struct boot_menu_entry entries[32];
    int count = parse_ini("config.ini", entries, 32);

    if (count > 0) {
        for (int i = 0; i < count; i++) {
            if (strcmp(entries[i].name, "language") == 0) {
                SetLanguage(entries[i].path);
            }
        }
    }

    // Set default language to English if not specified
    SetLanguage("en");
}