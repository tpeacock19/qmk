#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"
#include "send_string/send_string.h"

#if defined(REPEAT_KEYS_ENABLE)
# include "repeat_key.h"
#endif

#if defined(SWAP_KEYS_ENABLE)
# include "swap_keys.h"
#endif

#define HISTORY_TIMEOUT_MS 5000 // Timeout in milliseconds.
#define HISTORY_SIZE 8		// Number of keys in `history` buffer.

extern process_record_result_t process_history(uint16_t keycode,
                                               keyrecord_t *record);

void tap_code_history(uint8_t keycode, keyrecord_t *record);
void tap_code_mod_history(uint8_t keycode, uint8_t modifier,
                                 keyrecord_t *record);
void tap_code_history16(uint16_t keycode, keyrecord_t *record);
void tap_code_mod_history16(uint16_t keycode, uint8_t modifier,
                                   keyrecord_t *record);

void clear_history_keys(void);
void clear_history_index(int n);

typedef struct
{
  uint16_t keycode;
  uint8_t modifier;
  uint16_t keydown;
} history_key_t;

extern history_key_t *get_history(int n);

extern void shift_history_keys(void);

extern void history_matrix_scan_user(void);
