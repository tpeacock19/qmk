#include "combo.h"

#if defined(COMBO_TERM_PER_COMBO)
extern uint16_t
get_combo_term(uint16_t index, combo_t *combo)
{
  uint16_t key1 = combo->keys[0];
  uint16_t key2 = combo->keys[1];

  for (int i = 0; i < NUM_COMBO_TERMS; ++i)
    {
# if defined CONTROLLER && CONTROLLER == atmel-dfu
      if (key1 == pgm_read_word(&combo_terms[i].key1))
        {
          if (key2 == KC_NO || key2 == pgm_read_word(&combo_terms[i].key2))
            {
              return COMBO_TERM + pgm_read_word(&combo_terms[i].combo_term);
            }
        }
      else if (key1 == pgm_read_word(&combo_terms[i].key2)
               && key2 == pgm_read_word(&combo_terms[i].key1))
        {
          return COMBO_TERM + pgm_read_word(&combo_terms[i].combo_term);
        }
# else
      if (key1 == combo_terms[i].key1)
        {
          if (key2 == KC_NO || key2 == combo_terms[i].key2)
            {
              return COMBO_TERM + combo_terms[i].combo_term;
            }
        }
      else if (key1 == combo_terms[i].key2
               && key2 == combo_terms[i].key1)
        {
          return COMBO_TERM + combo_terms[i].combo_term;
        }
# endif
    }
  return COMBO_TERM;
}
#endif

#if defined(COMBO_MUST_HOLD_PER_COMBO)
extern bool
get_combo_must_hold(uint16_t index, combo_t *combo)
{
  if (KEYCODE_IS_MOD(combo->keycode)
      || (combo->keycode >= QK_MOMENTARY
          && combo->keycode <= QK_MOMENTARY_MAX) // MO(kc) keycodes
  )
    {
      return true;
    }
  return false;
}
#endif

#if defined(COMBO_MUST_TAP_PER_COMBO)
extern bool
get_combo_must_tap(uint16_t index, combo_t *combo)
{
  uint16_t key;
  uint8_t idx = 0;
# if defined CONTROLLER && CONTROLLER == atmel-dfu
  while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END)
# else
  while ((key = combo->keys[idx]) != COMBO_END)
#endif
    {
      switch (key)
        {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
          return true;
        }
      idx += 1;
    }
  return false;
}
#endif
