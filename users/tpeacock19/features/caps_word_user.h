#include QMK_KEYBOARD_H
#include "core/core.h"

__attribute__((weak)) bool
caps_word_press_user(uint16_t keycode)
{
  switch (keycode)
    {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_MINS:
      /* case TD(DANCE_1): */
    case DOTMIN:
    case COMPAR:

#if defined(TAP_DANCE_ENABLE)
    case TD(DANCE_2):
    case TD(DANCE_3):
#endif
      add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_LSFT:
    case OSM(MOD_LSFT):
    case REPEAT:
    case SWAPKEY:
    case LINQ:
      return true;
    default:
      return false; // Deactivate Caps Word.
    }
}
