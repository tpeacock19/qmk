#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"

#if defined(NUMWORD_ENABLE)
# include "num_word.h"
#endif
#if defined(CAPS_WORD_ENABLE)
# include "quantum/caps_word.h"
#endif

extern process_record_result_t process_esc_mod(uint16_t keycode,
                                               keyrecord_t *record);

extern bool is_num_word_on(void);  /**< Activates Num Word. */
extern void num_word_on(void);	   /**< Activates Num Word. */
extern void num_word_off(void);	   /**< Activates Num Word. */
extern bool is_caps_word_on(void); /**< Activates Num Word. */
extern void caps_word_on(void);	   /**< Activates Num Word. */
extern void caps_word_off(void);   /**< Activates Num Word. */
