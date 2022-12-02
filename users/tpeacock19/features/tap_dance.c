#include "tap_dance.h"

int
cur_dance(qk_tap_dance_state_t *state)
{
  if (state->count == 1)
    {
      if (state->interrupted)
        {
          return SINGLE_TAP;
        }
      else
        {
          if (!state->pressed)
            return SINGLE_TAP;
          else
            return SINGLE_HOLD;
        }
    }
  else if (state->count == 2)
    {
      if (state->interrupted)
        return DOUBLE_SINGLE_TAP;
      else if (state->pressed)
        return DOUBLE_HOLD;
      else
        return DOUBLE_TAP;
    }
  else
    return MORE_TAPS;
}

// This works well if you want this key to work as a "fast modifier".
// It favors being held over being tapped.
int
hold_cur_dance(qk_tap_dance_state_t *state)
{
  if (state->count == 1)
    {
      if (state->interrupted)
        {
          if (!state->pressed)
            return SINGLE_TAP;
          else
            return SINGLE_HOLD;
        }
      else
        {
          if (!state->pressed)
            return SINGLE_TAP;
          else
            return SINGLE_HOLD;
        }
    }
  // If count = 2, and it has been interrupted - assume that user is
  // trying to type the letter associated with single tap.
  else if (state->count == 2)
    {
      if (state->pressed)
        return DOUBLE_HOLD;
      else
        return DOUBLE_TAP;
    }
  else
    return MORE_TAPS;
}

// Initialize tap structure associated with example tap dance key
static xtap l_base_tt_tap_state = { .is_press_action = true, .state = TD_NONE };

void
l_base_tt_finished(qk_tap_dance_state_t *state, void *user_data)
{
  l_base_tt_tap_state.state = cur_dance(state);
  switch (l_base_tt_tap_state.state)
    {
    case SINGLE_TAP:
    case SINGLE_INT:
    case SINGLE_HOLD:
      layer_lock_on(L_MODS);
      break;
    case DOUBLE_TAP:
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_HOLD:
      layer_lock_on(0);
      break;
    default:
      break;
    }
};

void
l_base_tt_reset(qk_tap_dance_state_t *state, void *user_data)
{
  // If the key was held down and now is released then switch off the
  // layer
  switch (l_base_tt_tap_state.state)
    {
    case SINGLE_TAP:
    case SINGLE_INT:
    case SINGLE_HOLD:
      if (!is_layer_locked(L_MODS))
        layer_lock_on(L_MODS);
      break;
    case DOUBLE_TAP:
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_HOLD:
      if (is_layer_locked(L_MODS))
        layer_lock_off(L_MODS);
      break;
    default:
      break;
    }
  l_base_tt_tap_state.state = TD_NONE;
};

void
safe_reset(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count >= 3)
    {
      // Reset the keyboard if you tap the key more than three times
      reset_keyboard();
      reset_tap_dance(state);
    }
}
