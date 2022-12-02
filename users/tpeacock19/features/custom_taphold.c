#include "custom_taphold.h"
#include "keycodes.h"

extern uint8_t current_layer;

extern os_t os;

static custom_tapholds_t custom_tapholds = { .timer = 0 };
static bool holding_oneshot_layer = false;

static uint8_t oneshot_locked_mods;
static uint8_t oneshot_mods;

// Custom oneshot mods
int
oneshot_simple_record(keyrecord_t *record)
{
  if (record->tap.count != 0)
    {
      if (record->tap.interrupted)
	{
	  if (record->event.pressed)
	    return INT_PRESS;
	  else
	    return INT_RELEASE;
	}
      else
	{
	  if (record->event.pressed)
	    return TAP_PRESS;
	  else
	    return TAP_RELEASE;
	}
    }
  else if (record->event.pressed)
    {
      return HOLD_PRESS;
    }
  else
    return HOLD_RELEASE;
}

void
oneshot_mods_changed_user(uint8_t mods)
{
  if (mods)
    {
      custom_tapholds.timer = timer_read();
    }
  else
    {
      custom_tapholds.timer = 0;
    }
}

void
clear_locked_and_oneshot_mods(void)
{
  oneshot_locked_mods = get_oneshot_locked_mods();
  oneshot_mods = get_oneshot_mods();
  if (oneshot_locked_mods || oneshot_mods)
    {
      clear_oneshot_mods();
      clear_oneshot_locked_mods();
      unregister_mods(MOD_LSFT);
      unregister_mods(MOD_LCTL);
      unregister_mods(MOD_LALT);
      unregister_mods(MOD_RALT);
      unregister_mods(MOD_LGUI);
    }
}

void
clear_oneshot_mods_state(void)
{
  oneshot_locked_mods = get_oneshot_locked_mods();
  oneshot_mods = get_oneshot_mods();
  if (!(oneshot_locked_mods & MOD_LSFT) && (oneshot_mods & MOD_LSFT))
    {
      del_oneshot_mods(MOD_LSFT);
      unregister_mods(MOD_LSFT);
    }
  if (!(oneshot_locked_mods & MOD_LCTL) && (oneshot_mods & MOD_LCTL))
    {
      del_oneshot_mods(MOD_LCTL);
      unregister_mods(MOD_LCTL);
    }
  if (!(oneshot_locked_mods & MOD_LGUI) && (oneshot_mods & MOD_LGUI))
    {
      del_oneshot_mods(MOD_LGUI);
      unregister_mods(MOD_LGUI);
    }
  if (!(oneshot_locked_mods & MOD_LALT) && (oneshot_mods & MOD_LALT))
    {
      del_oneshot_mods(MOD_LALT);
      unregister_mods(MOD_LALT);
    }
  if (!(oneshot_locked_mods & MOD_RALT) && (oneshot_mods & MOD_RALT))
    {
      del_oneshot_mods(MOD_RALT);
      unregister_mods(MOD_RALT);
    }
}

void
disable_oneshot_layer(void)
{
  clear_oneshot_layer_state(ONESHOT_PRESSED);
  custom_tapholds.timer = 0;
}

void
disable_oneshot_mods(void)
{
  clear_oneshot_mods_state();
  custom_tapholds.timer = 0;
}

// Custom oneshot timeout

bool
custom_tapholds_expired(void)
{
  return custom_tapholds.timer > 0
	 && (timer_elapsed(custom_tapholds.timer) > CUSTOM_TAPHOLD_TIMEOUT);
}

void
check_oneshot_timeout(void)
{
  if (custom_tapholds_expired() && !holding_oneshot_layer)
    {
      disable_oneshot_mods();
      disable_oneshot_layer();
    }
}

/* __attribute__((weak)) void matrix_scan_user(void) { */
/*   check_oneshot_timeout(); */
/* } */

void
check_disable_oneshot_layer(uint16_t keycode)
{
  switch (keycode)
    {
      /* oneshot keys */
    case NUM_RPT:
    case SYM_RPT:
    case MED_SFT:
    case NAV_SFT:
    case COMPAR:
    case DOTMIN:
    case SLSEXC:
    case MOD_NUM:
    case NUM_MOD:
    case OS_MODS:
      break;
    default:
      if (!holding_oneshot_layer)
	{
	  disable_oneshot_layer();
	}
    }
}

__attribute__((weak)) void
post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  check_disable_oneshot_layer(keycode);
}

// Custom oneshot keycodes
process_record_result_t
process_custom_taphold(uint16_t keycode, keyrecord_t *record)
{
  /* bool isLinux = os.type == LINUX; */
  /* bool isWindows = os.type == WINDOWS; */
  /*****************************************************************************
    A simulated Tap-Dance can be accomplished with the oneshot_simple_record
    function defined previously. The specific keypress states are defined as
    follows:
    switch (oneshot_simple_record(record))
      {
      case TAP_PRESS:
      case TAP_RELEASE:
      case INT_PRESS:
      case INT_RELEASE:
      case HOLD_PRESS:
      case HOLD_RELEASE:
      }
   *****************************************************************************/

  uint8_t tapkey = extract_base_tapping_keycode(keycode);
  uint8_t layer = extract_tap_layer(keycode);

  switch (keycode)
    {
    case XWMOVL:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(S(KC_LEFT)), record);
#else
	      tap_code16(G(S(KC_LEFT)));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XWMOV:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(S(KC_RIGHT)), record);
#else
	      tap_code16(G(S(KC_RIGHT)));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(S(KC_DOT)), record);
#else
	      tap_code16(G(S(KC_DOT)));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XWTOG:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(KC_P), record);
#else
	      tap_code16(G(KC_P));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(KC_DOT), record);
#else
	      tap_code16(G(KC_DOT));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XREDO:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(C(KC_Y), record);
#else
	      tap_code16(C(KC_Y));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(KC_AGAIN, record);
#else
	      tap_code_history16(KC_AGAIN);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XUNDO:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(C(KC_Z), record);
#else
	      tap_code16(C(KC_Z));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(KC_UNDO, record);
#else
	      tap_code_history16(KC_UNDO);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XCLOSE:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(A(KC_F4), record);
#else
	      tap_code16(A(KC_F4));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(S(G(KC_Q)), record);
#else
	      tap_code_history16(S(G(KC_Q)));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XLOCK:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(KC_L), record);
#else
	      tap_code16(G(KC_L));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XSRCH:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(KC_S), record);
#else
	      tap_code16(G(KC_S));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(KC_SPC), record);
#else
	      tap_code16(G(KC_SPC));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XWBAK:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(C(KC_LEFT)), record);
#else
	      tap_code16(G(C(KC_LEFT)));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history(KC_WWW_BACK, record);
#else
	      tap_code(KC_WWW_BACK);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case XWFWD:
      switch (oneshot_simple_record(record))
	{
	case TAP_PRESS:
	  switch (os.type)
	    {
	    case WINDOWS:
#if defined(HISTORY_ENABLE)
	      tap_code_history16(G(C(KC_RIGHT)), record);
#else
	      tap_code16(G(C(KC_RIGHT)));
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    case LINUX:
#if defined(HISTORY_ENABLE)
	      tap_code_history(KC_WWW_FORWARD, record);
#else
	      tap_code(KC_WWW_FORWARD);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    default:
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case MOD_T:
      /* Tap: One-Shot Layer | Hold: Layer */
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
	  /* Act as a universal Layer Lock key for all */
	  if (current_layer != L_GOLD)
	    {
#if defined(LAYER_LOCK_ENABLE)
	      layer_lock_invert(current_layer);
#else
	      layer_invert(current_layer);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	  else
	    {
#if defined(HISTORY_ENABLE)
	      tap_code_history(tapkey, record);
#else
	      tap_code(tapkey);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	case HOLD_PRESS:
	  layer_on(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_RELEASE:
#if defined(LAYER_LOCK_ENABLE)
	  if (!is_layer_locked(layer))
#endif
	    layer_off(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

      /* Special Thumb Keys that when pressed from a non-base layer will lock
      the current layer */
      /* Tap: Key | Hold: Layer */
      /* Tap: One-Shot Layer | Hold: Layer */

    case OS_MODS:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
	  /* Act as a universal Layer Lock key for all */
	  if (current_layer != L_COLEMAK)
	    {
#if defined(LAYER_LOCK_ENABLE)
	      layer_lock_invert(current_layer);
#else
	      layer_invert(current_layer);
#endif
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	  else
	    {
	      /* Custom Tap: One-Shot Layer */
	    case OS_MODS:
	      set_oneshot_layer(tapkey, ONESHOT_PRESSED);
	      custom_tapholds.timer = timer_read();
	      return PROCESS_RECORD_RETURN_FALSE;
	    }
	case HOLD_PRESS:
	  layer_on(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_RELEASE:
#if defined(LAYER_LOCK_ENABLE)
	  if (!is_layer_locked(layer))
#endif
	    layer_off(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

      /* Tap: One-Shot Layer | Hold: Layer */
    case NUM_MOD:
    case MOD_NUM:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
	  set_oneshot_layer(tapkey, ONESHOT_PRESSED);
	  custom_tapholds.timer = timer_read();
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
	  /* case INT_PRESS: */
	  layer_on(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_RELEASE:
	  /* case INT_RELEASE: */
#if defined(LAYER_LOCK_ENABLE)
	  if (!is_layer_locked(layer))
#endif
	    layer_off(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

      /* Tap: One-Shot Shift | Hold: Layer */
    case MED_SFT:
    case NAV_SFT:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
	  if (record->tap.count == 2)
	    {
	      clear_shift();
#if defined(CAPS_WORD_ENABLE)
	      caps_word_toggle();
#endif
	    }
	  else if (isShifted)
	    {
	      clear_shift();
	    }
	  else
	    {
	      add_oneshot_mods(MOD_BIT(KC_LSFT));
	      custom_tapholds.timer = timer_read();
	    }
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_CONTINUE;
	}

      /* Tap: Repeat | Hold: Layer */
    case SYM_RPT:
    case NUM_RPT:
      switch (oneshot_simple_record(record))
	{
	  /* layer turned on for Interrupts, as well as hold  */
	case INT_PRESS:
	case HOLD_PRESS:
	  layer_on(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	case INT_RELEASE:
	case HOLD_RELEASE:
#if defined(LAYER_LOCK_ENABLE)
	  if (!is_layer_locked(layer))
#endif
	    layer_off(layer);
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_CONTINUE;
	}

      /* Linger Keys  */
    case LINBRC:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_LBRC, record);
#else
	  tap_code(KC_LBRC);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_RBRC, record);
#else
	  tap_code(KC_RBRC);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case LINPRN:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
	  /* SEND_STRING(SS_LCTL("xf")  "~/org"  SS_TAP(X_ENT)); */
#if defined(HISTORY_ENABLE)
	  tap_code_history16(KC_LPRN, record);
#else
	  tap_code16(KC_LPRN);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history16(KC_RPRN, record);
#else
	  tap_code16(KC_RPRN);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case LINCBR:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history16(KC_LCBR, record);
#else
	  tap_code16(KC_LCBR);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history16(KC_RCBR, record);
#else
	  tap_code16(KC_RCBR);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case LINQ:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:

	case TAP_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_Q, record);
#else
	  tap_code(KC_Q);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_Q, record);
	  clear_shift();
	  disable_oneshot_mods();
	  tap_code_mod_history(KC_U, 0, record);
#else
	  tap_code(KC_Q);
	  clear_shift();
	  disable_oneshot_mods();
	  tap_code(KC_U);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case SLSEXC:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_SLASH, record);
#else
	  tap_code(KC_SLASH);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case INT_RELEASE:
	case TAP_RELEASE:
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history16(KC_EXCLAIM, record);
#else
	  tap_code16(KC_EXCLAIM);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case COMPAR:
      switch (oneshot_simple_record(record))
	{
	case INT_RELEASE:
	case TAP_RELEASE:
	  return PROCESS_RECORD_RETURN_FALSE;
	case INT_PRESS:
	case TAP_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_COMM, record);
#else
	  tap_code(KC_COMM);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history16(KC_LEFT_PAREN, record);
#else
	  tap_code16(KC_LEFT_PAREN);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case DOTMIN:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
#if defined(HISTORY_ENABLE)
	  if (!(get_history(1)->modifier & MOD_MASK_SHIFT))
	    {
#endif
	      if (record->tap.count == 2)
		{
		  /* Typing double `.` will insert a space and add
			 oneshot shift to capitalize next sentence. */
		  tap_code(KC_SPC);
		  custom_tapholds.timer = timer_read();
		  add_oneshot_mods(MOD_BIT(KC_LSFT));
		}
	      else if (record->tap.count == 3)
		{
		  /* Three taps should insert an ellipsis, we need to
			 clear the actions taken by the `sentence end`
			 macro below */
		  clear_oneshot_mods();
		  clear_mods();
		  tap_code(KC_BSPC);
		  tap_code(KC_DOT);
#if defined(HISTORY_ENABLE)
		  tap_code_mod_history(KC_DOT, 0, record);
		}
	      else
		tap_code_history(KC_DOT, record);
	    }
	  else if (record->tap.count == 2)
	    {
	      /* Shifted double tap inserts a second ">" */
	      tap_code_history16(LSFT(KC_DOT), record);
	    }
	  else
	    tap_code_history(KC_DOT, record);
#else
	      tap_code(KC_DOT);
	    }
	  else
	    tap_code(KC_DOT);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	case HOLD_PRESS:
#if defined(HISTORY_ENABLE)
	  tap_code_history(KC_MINS, record);
#else
	  tap_code(KC_MINS);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case MYRESET:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
	  if (record->tap.count == 3)
	    {
	      // Reset the keyboard if you tap the key more than three
	      // times
	      reset_keyboard();
	    }
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}

    case GOTOBASE:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
#if defined(LAYER_LOCK_ENABLE)
	  if (is_layer_locked(L_GOLD))
	    layer_on(L_GOLD);
	  else
	    layer_on(L_COLEMAK);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}
    case BASETOGG:
      switch (oneshot_simple_record(record))
	{
	case INT_PRESS:
	case TAP_PRESS:
#if defined(LAYER_LOCK_ENABLE)
	  layer_lock_invert(L_GOLD);
#endif
	  return PROCESS_RECORD_RETURN_FALSE;
	default:
	  return PROCESS_RECORD_RETURN_FALSE;
	}
    }
  /* check_disable_oneshot(keycode ); */
  return PROCESS_RECORD_CONTINUE;
}
