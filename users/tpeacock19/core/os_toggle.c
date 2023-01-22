#include "os_toggle.h"

os_t os = {.type = LINUX};

process_record_result_t
process_os_toggle(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
      // Change OS type

    case TG_MAC:
      if (record->event.pressed)
        {
          os.type = MACOS;
/* #if defined(HISTORY_ENABLE) */
/*           clear_history_keys(); */
/* #endif */
        }
    return PROCESS_RECORD_RETURN_FALSE;

    case TG_WIN:
      if (record->event.pressed)
        {
          os.type = WINDOWS;
/* #if defined(HISTORY_ENABLE) */
/*           clear_history_keys(); */
/* #endif */
        }
    return PROCESS_RECORD_RETURN_FALSE;

    case TG_LIN:
      if (record->event.pressed)
        {
          os.type = LINUX;
/* #if defined(HISTORY_ENABLE) */
/*           clear_history_keys(); */
/* #endif */
        }
    return PROCESS_RECORD_RETURN_FALSE;
    }

  return PROCESS_RECORD_CONTINUE;
}
