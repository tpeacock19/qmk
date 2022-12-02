#include "num_word.h"

/** @brief True when Num Word is active. */
static bool num_word_active = false;

#if NUM_WORD_IDLE_TIMEOUT > 0
// Constrain timeout to a sensible range. With 16-bit timers, the
// longest timeout possible is 32768 ms, rounded here to 30000 ms = half
// a minute.
# if NUM_WORD_IDLE_TIMEOUT < 100 || NUM_WORD_IDLE_TIMEOUT > 30000
#  error "NUM_WORD_IDLE_TIMEOUT must be between 100 and 30000 ms"
# endif

/** @brief Deadline for idle timeout. */
static uint16_t idle_timer = 0;

void
num_word_task(void)
{
  if (num_word_active && timer_expired(timer_read(), idle_timer))
    {
      num_word_off();
    }
}

void
num_word_reset_idle_timer(void)
{
  idle_timer = timer_read() + NUM_WORD_IDLE_TIMEOUT;
}
#endif // NUM_WORD_IDLE_TIMEOUT > 0

void
num_word_on(void)
{
  if (num_word_active)
    {
      return;
    }

  num_word_active = true;
  layer_on(L_NUM);
}
void
num_word_off(void)
{
  if (!num_word_active)
    {
      return;
    }
  num_word_active = false;
  layer_off(L_NUM);
}

void
num_word_toggle(void)
{
  if (num_word_active)
    {
      num_word_off();
    }
  else
    {
      num_word_on();
    }
}

bool
is_num_word_on(void)
{
  return num_word_active;
}

process_record_result_t
process_num_word(uint16_t keycode, keyrecord_t *record)
{
  if (keycode == NW_TOGG)
    { // Pressing CAPSWRD toggles Caps Word.
      if (record->event.pressed)
        {
          num_word_toggle();
        }
      return PROCESS_RECORD_RETURN_FALSE;
    }
  if (num_word_press_user(keycode))
    {
      send_keyboard_report();
      return PROCESS_RECORD_CONTINUE;
    }
  return PROCESS_RECORD_CONTINUE;
}

__attribute__((weak)) bool
num_word_press_user(uint16_t keycode)
{
  if (!num_word_active)
    return true;

  switch (keycode)
    {
    case KC_1 ... KC_0:
    case KC_COMM:
    case KC_DOT:
    case KC_SLSH:
    case KC_MINUS:
    case KC_ASTERISK:
    case KC_PLUS:
    case KC_COLON:
    case KC_EQUAL:
    case KC_UNDS:
    case KC_BSPC:
    case KC_X:
    case KC_NO:
      return true;
    default:
      num_word_off();
      return false;
    }
}
