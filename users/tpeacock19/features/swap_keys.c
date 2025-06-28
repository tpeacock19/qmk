#include "swap_keys.h"
#include "history.h"

bool key_swapped = false;

static uint8_t
find_swap_keycode(const uint8_t (*table)[2], uint8_t table_size_bytes,
		  uint8_t target)
{
  const uint8_t *keycodes = (const uint8_t *) table;
  for (uint8_t i = 0; i < table_size_bytes; ++i)
    {
#if defined CONTROLLER && CONTROLLER == atmel - dfu
      if (target == pgm_read_byte(keycodes + i))
	{
	  // Xor (i ^ 1) the index to get the other element in the pair.
	  return pgm_read_byte(keycodes + (i ^ 1));
	}
#else
      if (target == keycodes[i])
	{
	  // Xor (i ^ 1) the index to get the other element in the pair.
	  return keycodes[(i ^ 1)];
	}
#endif
    }
  return KC_NO;
}

static uint16_t
find_swap_key(void)
{
  uint16_t keycode = get_history(1)->record.keycode;
  uint8_t mods = get_history(1)->modifier;

  uint16_t alt_keycode = find_swap_keycode_user(keycode, mods);

  if (alt_keycode != KC_TRANSPARENT)
    {
      return alt_keycode;
    }

  // Convert 8-bit mods to the 5-bit format used in keycodes. This is lossy:
  // if left and right handed mods were mixed, they all become right handed.
  mods = ((mods & 0xf0) ? /* set right hand bit */ 0x10 : 0)
	 // Combine right and left hand mods.
	 | (((mods >> 4) | mods) & 0xf);

  switch (keycode)
    {
    case QK_MODS ... QK_MODS_MAX: // Unpack modifier + basic key.
      mods |= QK_MODS_GET_MODS(keycode);
      keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
      break;

#ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
# ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
# endif // NO_ACTION_LAYER
#endif	// NO_ACTION_TAPPING
    }
  if (IS_QK_BASIC(keycode))
    {
      if ((mods & (MOD_LCTL | MOD_LALT | MOD_LGUI)))
	{
	  // The last key was pressed with a modifier other than Shift.
	  // The following maps
	  //   mod + F <-> mod + B
	  // and a few others, supporting several core hotkeys used in
	  // Emacs, Vim, less, and other programs.
	  // clang-format off
            static const uint8_t pairs[][2] PROGMEM = {
                {KC_F   , KC_B   },  // Forward / Backward.
                {KC_D   , KC_U   },  // Down / Up.
                {KC_N   , KC_P   },  // Next / Previous.
                {KC_A   , KC_E   },  // Home / End.
                {KC_O   , KC_I   },  // Older / Newer in Vim jump list.
            };
	  // clang-format on
	  alt_keycode = find_swap_keycode(pairs, sizeof(pairs), keycode);
	}
      else
	{
	  // The last key was pressed with no mods or only Shift. The
	  // following map a few more Vim hotkeys.
	  // clang-format off
            static const uint8_t pairs[][2] PROGMEM = {
                {KC_J   , KC_K   },  // Down / Up.
                {KC_H   , KC_L   },  // Left / Right.
                // These two lines map W and E to B, and B to W.
                {KC_W   , KC_B   },  // Forward / Backward by word.
                {KC_E   , KC_B   },  // Forward / Backward by word.
            };
	  // clang-format on
	  alt_keycode = find_swap_keycode(pairs, sizeof(pairs), keycode);
	}

      if (!alt_keycode)
	{
	  // The following key pairs are considered with any mods.
	  // clang-format off
            static const uint8_t pairs[][2] PROGMEM = {
                {KC_LEFT, KC_RGHT},  // Left / Right Arrow.
                {KC_UP  , KC_DOWN},  // Up / Down Arrow.
                {KC_HOME, KC_END },  // Home / End.
                {KC_PGUP, KC_PGDN},  // Page Up / Page Down.
                {KC_BSPC, KC_DEL },  // Backspace / Delete.
                {KC_LBRC, KC_RBRC},  // Brackets [ ] and { }.
#ifdef EXTRAKEY_ENABLE
                {KC_WBAK, KC_WFWD},  // Browser Back / Forward.
                {KC_MNXT, KC_MPRV},  // Next / Previous Media Track.
                {KC_MFFD, KC_MRWD},  // Fast Forward / Rewind Media.
                {KC_VOLU, KC_VOLD},  // Volume Up / Down.
                {KC_BRIU, KC_BRID},  // Brightness Up / Down.
#endif  // EXTRAKEY_ENABLE
#ifdef MOUSEKEY_ENABLE
                {KC_MS_L, KC_MS_R},  // Mouse Cursor Left / Right.
                {KC_MS_U, KC_MS_D},  // Mouse Cursor Up / Down.
                {KC_WH_L, KC_WH_R},  // Mouse Wheel Left / Right.
                {KC_WH_U, KC_WH_D},  // Mouse Wheel Up / Down.
#endif  // MOUSEKEY_ENABLE
            };
	  // clang-format on
	  alt_keycode = find_swap_keycode(pairs, sizeof(pairs), keycode);
	}

      if (alt_keycode)
	{
	  // Combine basic keycode with mods.
	  return (mods << 8) | alt_keycode;
	}
    }

  return KC_NO; // No alternate key found.
}

process_record_result_t
process_swap_key(uint16_t keycode, keyrecord_t *record)
{
  static keyrecord_t swapped_record = { 0 };
  if (key_swapped)
    {
      return PROCESS_RECORD_CONTINUE;
    }
  if (swap_key_press_user(keycode, record))
    {
      if (record->event.pressed)
	{
	  swapped_record = (keyrecord_t){
#ifndef NO_ACTION_TAPPING
	    .tap.interrupted = false,
	    .tap.count = 0,
#endif
	    .keycode = find_swap_key(),
	  };
	}

      // Early return if there is no alternate key defined.
      if (!swapped_record.keycode)
	{
	  return PROCESS_RECORD_RETURN_FALSE;
	}

      if (record->event.pressed)
	{
	  key_swapped = true;
	}
      swapped_record.event = record->event;
      process_record(&swapped_record);
      clear_history_index(1);
      set_history(extract_keycode_from(swapped_record.keycode), swapped_record,
		  extract_mods_from(swapped_record.keycode));
      key_swapped = false;
      return PROCESS_RECORD_RETURN_FALSE;
    }
  return PROCESS_RECORD_CONTINUE;
}

__attribute__((weak)) bool
swap_key_press_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case SWAPKEY:
      return true;
    default:
      return false;
    }
}

__attribute__((weak)) uint16_t
find_swap_keycode_user(uint16_t keycode, uint8_t mods)
{
  return KC_TRANSPARENT;
}
