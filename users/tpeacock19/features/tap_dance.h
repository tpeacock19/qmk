#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"
#if defined(HISTORY_ENABLE)
# include "history.h"
#endif
#if defined(LAYER_LOCK_ENABLE)
# include "layer_lock.h"
#endif

// Define a type for as many tap dance states as you need
/* typedef enum { TD_NONE, TD_UNKNOWN, SINGLE_INT, SINGLE_TAP, SINGLE_HOLD,
 * DOUBLE_HOLD, DOUBLE_TAP, DOUBLE_SINGLE_TAP, MORE_TAPS } td_state_t; */

/* typedef struct { */
/*     bool       is_press_action; */
/*     td_state_t state; */
/* } td_tap_t; */

/* uint16_t key_timer; */

/* // Determine the current tap dance state */
/* #if defined(TAP_DANCE_ENABLE) */
/* enum { DANCE_1, DANCE_2, DANCE_3, DANCE_4, DANCE_5, DANCE_6 }; */
/* #endif */

// Functions associated with individual tap dances
extern void safe_reset(qk_tap_dance_state_t *state, void *user_data);
extern void l_base_tt_finished(qk_tap_dance_state_t *state, void *user_data);
extern void l_base_tt_reset(qk_tap_dance_state_t *state, void *user_data);
