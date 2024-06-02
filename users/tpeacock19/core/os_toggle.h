#pragma once

#include "core.h"
#if defined(HISTORY_ENABLE)
# include "features/history.h"
#endif

typedef enum
{
  LINUX = 0,
  MACOS = 1,
  WINDOWS = 2,
} os_type_t;

typedef struct
{
  os_type_t type;
} os_t;

os_t os;

extern process_record_result_t process_os_toggle(uint16_t keycode,
						 keyrecord_t *record);
