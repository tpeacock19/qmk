#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"
#include "history.h"

#if defined(CUSTOM_SHIFT_ENABLE)
# include "custom_shift_keys.h"
#endif

typedef struct
{
  uint16_t keycode;
  uint16_t shifted_keycode;
} repeat_key_t;

extern const repeat_key_t repeat_keys[];

bool key_repeated;

extern void repeat_key(const keyrecord_t *record);

extern process_record_result_t process_repeat_key(uint16_t keycode,
                                                  keyrecord_t *record);

__attribute__((weak)) bool repeat_key_press_user(uint16_t keycode,
                                                 keyrecord_t *record);
