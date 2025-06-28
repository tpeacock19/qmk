#include QMK_KEYBOARD_H
#include "core/core.h"
#include "process_auto_shift.h"

bool
get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case ALT_R:
    case SFT_S:
    case CRL_T:
    case GUI_D:

    case ALT_I:
    case SFT_E:
    case CRL_N:
    case GUI_H:
      return true;
    default:
      /* if (IS_RETRO(keycode)) */

      /*   { */
      /*     return true; */
      /*   } */
      return false;
    }
}

/* void */
/* autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) */
/* { */
/*   switch (keycode) */
/*     { */
/*     default: */
/*       if (shifted) */
/*         { */
/*           add_weak_mods(MOD_BIT(KC_LSFT)); */
/*         } */
/*       // & 0xFF gets the Tap key for Tap Holds, required when using Retro
 * Shift */
/*       register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode); */
/*     } */
/* } */

/* void */
/* autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record)
 */
/* { */
/*   switch (keycode) */
/*     { */
/*     default: */
/*       // & 0xFF gets the Tap key for Tap Holds, required when using Retro
 * Shift */
/*       // The IS_RETRO check isn't really necessary here, always using */
/*       // keycode & 0xFF would be fine. */
/*       unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode); */
/*     } */
/* } */
