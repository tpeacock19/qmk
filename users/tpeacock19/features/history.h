#pragma once

#include "keyboard.h"
#include QMK_KEYBOARD_H
#include "core/core.h"
#include "send_string/send_string.h"
#if defined(REPEAT_KEY_ENABLE)
# include "repeat_key_user.h"
#endif
#if defined(CUSTOM_REPEAT_KEY_ENABLE)
# include "custom_repeat_key.h"
#endif

#if defined(SWAP_KEYS_ENABLE)
# include "swap_keys.h"
#endif

#define HISTORY_TIMEOUT_MS 5000 // Timeout in milliseconds.
#define HISTORY_SIZE 6		// Number of keys in `history` buffer.

extern process_record_result_t process_history(uint16_t keycode,
					       keyrecord_t *record);

void tap_code_history(uint8_t keycode, keyrecord_t *record);
void tap_code_history16(uint16_t keycode, keyrecord_t *record);

void clear_history_keys(void);
void clear_history_index(int n);

typedef struct
{
  uint8_t modifier;
  keyrecord_t record;
} history_key_t;
extern bool key_swapped;
extern history_key_t *get_history(int n);
extern int8_t get_repeat_key_count(void);
extern bool swap_key_press_user(uint16_t keycode, keyrecord_t *record);
extern void shift_history_keys(void);
extern void set_history(uint16_t keycode, keyrecord_t record,
			uint8_t current_modifier);

extern void history_matrix_scan_user(void);
