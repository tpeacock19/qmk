#include "core/core.h"
#include "history.h"

static int sindex = 0;
static int rindex = 0;
static int d = 0;

process_record_result_t
process_adaptive_key(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
    {
#define START1(flag, key, ...)                                  \
 /* check current keycode & previous one */                     \
 if (!timer_expired(record->event.time,                         \
                    (get_history(1)->record.keydown + ADAPTIVE_TERM))) \
  {                                                             \
   sindex = flag;                                               \
   rindex = 0;                                                  \
   switch (get_history(1)->record.keycode)                     \
    {                                                           \
    case key:                                                   \
     switch (QK_MODS_GET_BASIC_KEYCODE(keycode))                \
      {
#define END1 \
 }           \
 }           \
 }

#define START2(flag, key, key2, ...)                            \
 /* check term for two previous */                              \
 if (!timer_expired(get_history(1)->record.keydown,                    \
                    (get_history(2)->record.keydown + ADAPTIVE_TERM))) \
  {                                                             \
   switch (get_history(2)->record.keycode)                     \
    {                                                           \
    case key:                                                   \
     START1(2, key2)

#define END2 \
 }           \
 }           \
 }           \
 }           \
 }

#define START(flag, keys...) START##flag(flag, keys)

#define END(flag) END##flag

#define _GET_OVERRIDE(_1, _2, _3, NAME, ...) NAME

#define _INSERT_1(key) tap_code16(key);

#define _INSERT_2(key1, key2) \
 _INSERT_1(key1)              \
 tap_code16(key2);

#define _INSERT_3(key1, key2, key3) \
 _INSERT_2(key1, key2)              \
 tap_code16(key3);

#define INSERT_KEYS(...) \
 _GET_OVERRIDE(__VA_ARGS__, _INSERT_3, _INSERT_2, _INSERT_1)(__VA_ARGS__)

#define DELETE_TO(rindex)                    \
 d = (sindex - rindex);                      \
 if (d > 0 && d != 0)                        \
  {                                          \
   for (uint8_t i = sindex; i > rindex; i--) \
    tap_code(KC_BSPC);                       \
  }

#define REPLACE(rindex, next_key, keys...)    \
 case next_key:                               \
  DELETE_TO(rindex)                           \
  INSERT_KEYS(keys);                          \
  if (d > 1)                                  \
   {                                          \
    for (uint8_t i = sindex; i > rindex; i--) \
     tap_code(get_history(i - 1)->record.keycode);   \
   }                                          \
  if (d > 0 && d != 0)                        \
   {                                          \
    tap_code_history(next_key, record);       \
   }                                          \
  return PROCESS_RECORD_RETURN_FALSE;

#define ADD(next_key, keys...) \
 case next_key:                \
  INSERT_KEYS(next_key, keys)  \
  return PROCESS_RECORD_RETURN_FALSE;

#define ALL(next_key, keys...) \
 case next_key:                \
  DELETE_TO(0)                 \
  INSERT_KEYS(keys)            \
  return PROCESS_RECORD_RETURN_FALSE;

#define REP(place, next_key, keys...) REPLACE((place - 1), next_key, keys)

#define STRING(next_key, string) \
 case next_key:                  \
  DELETE_TO(0)                   \
  SEND_STRING(string);           \
  return PROCESS_RECORD_RETURN_FALSE;

#if defined(BASE_HD_GOLD)
# include "../ak_hd_gold.def"
#endif
#if defined(BASE_COLEMAK)
# include "../ak_colemak.def"
#endif
    }
  return PROCESS_RECORD_CONTINUE;
}

#undef START1
#undef START2
#undef START
#undef END1
#undef END2
#undef END
#undef DELETE
#undef REPLACE
#undef REP
#undef ALL
#undef ADD
#undef _INSERT_1
#undef _INSERT_2
#undef _INSERT_3
#undef _INSERT_KEYS
#undef _GET_OVERRIDE
/* #undef STR2 */
/* #undef STR3 */
#undef STRING
/* #undef STR */
