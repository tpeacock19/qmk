#include "keycodes.h"
#include "quantum_keycodes.h"

uint8_t
extract_mods_from(uint16_t keycode)
{
  switch (keycode)
    {
    case QK_MODS ... QK_MODS_MAX:
      return QK_MODS_GET_MODS(keycode);
    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
    case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
      return ((keycode) & 0x1F);
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      return QK_MOD_TAP_GET_MODS(keycode);
    default:
      return 0;
    }
}

uint8_t
extract_keycode_from(uint16_t keycode)
{
  switch (keycode)
    {
    case QK_MODS ... QK_MODS_MAX:
      return QK_MODS_GET_BASIC_KEYCODE(keycode);
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    case QK_SWAP_HANDS ... QK_SWAP_HANDS_MAX:
      return QK_SWAP_HANDS_GET_TAP_KEYCODE(keycode);
    default:
      return keycode;
    }
}

uint8_t
extract_layer_from(uint16_t keycode)
{
  switch (keycode)
    {
    case QK_TO ... QK_TO_MAX:
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
    case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
    case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
    case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX: // `TT(layer)`.
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
      return ((keycode) & 0x1F);
    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
      return QK_LAYER_MOD_GET_LAYER(keycode);
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX: // `LT(layer, key)` keys.
      return QK_LAYER_TAP_GET_LAYER(keycode);
    default:
      return 0;
    }
}

void
clear_shift(void)
{
  del_oneshot_mods(MOD_MASK_SHIFT);
  unregister_mods(MOD_MASK_SHIFT);
  unregister_weak_mods(MOD_LSFT);
}

bool isOneShotLockedShift = false;
bool isOneShotShift = false;
bool isShifted = false;
