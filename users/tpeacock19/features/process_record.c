#include "process_record.h"
#include "keycodes.h"
#include "process_layer_lock.h"

__attribute__((weak)) bool
pre_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  return true;
}
__attribute__((weak)) bool
process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
  return true;
};

bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
  current_modifier = get_mods() | get_weak_mods();
#ifndef NO_ACTION_ONESHOT
  current_modifier |= get_oneshot_mods();
#endif // NO_ACTION_ONESHOT
  /* current_modifier |= extract_mods_from(keycode); */
#if defined(CAPS_WORD_ENABLE)
  if (is_caps_word_on())
    {
      current_modifier |= MOD_BIT(KC_LSFT);
    }
#endif
  current_keycode_mod_state = extract_mods_from(keycode);
  current_layer = get_highest_layer(layer_state);
  isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
  isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
  isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
  /* if (isShifted) */
  /*   { */
  /*     current_modifier |= MOD_BIT(KC_LSFT); */
  /*   } */
#if defined(ACHORDION_ENABLE)
  if (!process_achordion(keycode, record))
    {
      return false;
    }
#endif

#if defined(OS_TOGGLE_ENABLE)
  switch (process_os_toggle(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

  if (!process_record_keymap(keycode, record))
    {
      return false;
    };

#if defined(ADAPTIVE_KEYS_ENABLE)
  switch (process_adaptive_key(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(CUSTOM_REPEAT_KEY_ENABLE)
  switch (process_custom_repeat_key(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(LAYER_LOCK_ENABLE)
  if (!process_layer_lock(keycode, record))
    {
      return false;
    }
#endif

#if defined(NUMWORD_ENABLE)
  switch (process_num_word(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(SWAP_KEYS_ENABLE)
  switch (process_swap_key(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(CUSTOM_TAPHOLD_ENABLE)
  switch (process_custom_taphold(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(CUSTOM_SHIFT_ENABLE)
  switch (process_custom_shift_keys(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      /* key_shifted = false; */
      break;
    };
#endif

#if defined(ESC_MOD_ENABLE)
  switch (process_esc_mod(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(HISTORY_ENABLE)
  switch (process_history(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

  /* last_modifier = current_modifier; */

  return true;
};

__attribute__((weak)) void
post_process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
}

void
post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  post_process_record_keymap(keycode, record);
#if defined(CUSTOM_TAPHOLD_ENABLE)
  check_disable_oneshot_layer(keycode);
#endif
}

/* void */
/* keyboard_post_init_user(void) */
/* { */
/*   // Customise these values to desired behaviour */
/*   debug_enable = true; */
/*   /\* debug_matrix=true; *\/ */
/*   debug_keyboard = true; */
/*   // debug_mouse=true; */
/* } */
