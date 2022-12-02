#include "keycodes.h"

#if defined(TAP_DANCE_ENABLE)
bool
is_key_on_tap(uint16_t keycode)
{
  switch (keycode)
    {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      return true;
    }
  if ((keycode > CUSTOM_KEYCODE_START && keycode < CUSTOM_KEYCODE_END))
    {
      return true;
    }
  for (int i = TD_CODE_START + 1; i < TD_CODE_END; i++)
    {
      if (TD(i) == keycode)
    {
      return true;
    }
    }
  keycode = extract_base_tapping_keycode(keycode);
  if (IS_KEY(keycode))
    {
      return true;
    }
  return false;
}
#endif

uint8_t
extract_mods_from(uint16_t keycode)
{
  return QK_MODS_GET_MODS(keycode);
  /* switch (keycode) */
  /*   { */
  /*   case QK_MODS ... QK_MODS_MAX: */
  /*     break; */
  /*   default: */
  /*     return 0; */
  /*   } */

  /* uint8_t mods_to_send = 0; */

  /* if (keycode & QK_RMODS_MIN) */
  /*   { // Right mod flag is set */
  /*     if (keycode & QK_LCTL) */
  /*   mods_to_send |= MOD_BIT(KC_RIGHT_CTRL); */
  /*     if (keycode & QK_LSFT) */
  /*   mods_to_send |= MOD_BIT(KC_RIGHT_SHIFT); */
  /*     if (keycode & QK_LALT) */
  /*   mods_to_send |= MOD_BIT(KC_RIGHT_ALT); */
  /*     if (keycode & QK_LGUI) */
  /*   mods_to_send |= MOD_BIT(KC_RIGHT_GUI); */
  /*   } */
  /* else */
  /*   { */
  /*     if (keycode & QK_LCTL) */
  /*   mods_to_send |= MOD_BIT(KC_LEFT_CTRL); */
  /*     if (keycode & QK_LSFT) */
  /*   mods_to_send |= MOD_BIT(KC_LEFT_SHIFT); */
  /*     if (keycode & QK_LALT) */
  /*   mods_to_send |= MOD_BIT(KC_LEFT_ALT); */
  /*     if (keycode & QK_LGUI) */
  /*   mods_to_send |= MOD_BIT(KC_LEFT_GUI); */
  /*   } */

  /* return mods_to_send; */
}

uint8_t
extract_keycode_from(uint16_t keycode)
{
  return QK_MODS_GET_BASIC_KEYCODE(keycode);
  /* switch (keycode) */
  /*   { */
  /*   case QK_MODS ... QK_MODS_MAX: */
  /*     break; */
  /*   default: */
  /*     return keycode; */
  /*   } */
  /* static const uint16_t all_mods = QK_LCTL | QK_LSFT | QK_LALT | QK_LGUI */
  /*                  | QK_RCTL | QK_RSFT | QK_RALT | QK_RGUI; */

  /* return (keycode & ~(all_mods)); */
}

uint16_t
extract_base_tapping_keycode16(uint16_t keycode)
{
  // Get the base tapping keycode of a mod- or layer-tap key.
  return keycode &= 0x1fff;
}
uint16_t
extract_base_tapping_keycode(uint16_t keycode)
{
  // Get the base tapping keycode of a mod- or layer-tap key.
  return keycode &= 0xff;
}

/* Extract layer from `MO(layer)` or `TT(layer)` keys */
uint8_t
extract_mott_layer(uint16_t keycode)
{
  return keycode & 255;
}
/* Extract layer from `LT(layer, key)` keys */
uint8_t
extract_lt_layer(uint16_t keycode)
{
  return (keycode >> 8) & 15;
}

/* Extract Layer from `LT(layer, key)`, `MO(layer)` or `TT(layer)` keys */
uint8_t
extract_tap_layer(uint16_t keycode)
{
  switch (keycode)
    {
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:		  // `MO(layer)` keys.
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX: // `TT(layer)`.
      return extract_mott_layer(keycode);
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX: // `LT(layer, key)` keys.
      return extract_lt_layer(keycode);
    default:
      return 0;
    }
}

void
clear_shift(void)
{
  del_oneshot_mods(MOD_MASK_SHIFT);
  unregister_mods(MOD_MASK_SHIFT);
}

bool isOneShotLockedShift = false;
bool isOneShotShift = false;
bool isShifted = false;
