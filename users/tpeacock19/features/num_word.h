#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"

#ifndef NUM_WORD_IDLE_TIMEOUT
# define NUM_WORD_IDLE_TIMEOUT 5000 // Default timeout of 5 seconds.
#endif				    // NUM_WORD_IDLE_TIMEOUT

#if NUM_WORD_IDLE_TIMEOUT > 0

/** @brief Matrix scan task for Num Word feature */
extern void num_word_task(void);

/** @brief Resets timer for Num Word idle timeout. */
extern void num_word_reset_idle_timer(void);
#else
static inline void
num_word_task(void)
{
}
#endif // NUM_WORD_IDLE_TIMEOUT > 0

extern void num_word_on(void);	   /**< Activates Num Word. */
extern void num_word_off(void);	   /**< Deactivates Num Word. */
extern void num_word_toggle(void); /**< Toggles Num Word. */
extern bool is_num_word_on(void);  /**< Gets whether currently active. */

extern process_record_result_t process_num_word(uint16_t keycode,
						keyrecord_t *record);

/**
 * @brief Weak function for user-level Num Word press modification.
 *
 * @param keycode   Keycode registered by matrix press, per keymap
 * @return true     Continue Num Word
 * @return false    Stop Num Word
 */
__attribute__((weak)) bool num_word_press_user(uint16_t keycode);
