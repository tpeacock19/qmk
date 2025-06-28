#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"
#if defined(LAYER_LOCK_ENABLE)
# include "quantum/layer_lock.h"
#endif
#if defined(HISTORY_ENABLE)
# include "history.h"
#endif

typedef struct
{
  uint16_t timer;
} custom_tapholds_t;

extern void disable_oneshot_layer(void);
extern void disable_oneshot_mods(void);
extern void check_oneshot_timeout(void);
extern void clear_locked_and_oneshot_mods(void);
extern void check_disable_oneshot_layer(uint16_t keycode);

extern process_record_result_t process_custom_taphold(uint16_t keycode,
						      keyrecord_t *record);
