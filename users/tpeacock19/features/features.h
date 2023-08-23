#pragma once

#include "esc_mod.h"
#include "process_record.h"

#if defined(ACHORDION_ENABLE)
# include "achordion.h"
# include "achordion_user.h"
#endif

#if defined(ADAPTIVE_KEYS_ENABLE)
# include "features/adaptive_keys.h"
#endif

#if defined(COMBO_ENABLE)
# include "combo.h"
#endif

#if !defined(NO_ACTION_TAPPING)
# include "tapping.h"
#endif

#if defined(AUTO_SHIFT_ENABLE)
# include "auto_shift_user.h"
#endif

#if defined(LAYER_LOCK_ENABLE)
# include "layer_lock.h"
#endif

#if defined(TAP_DANCE_ENABLE)
# include "tap_dance.h"
#endif

#if defined(CAPS_WORD_ENABLE)
# include "caps_word_user.h"
#endif

#if defined(CUSTOM_TAPHOLD_ENABLE)
# include "custom_taphold.h"
#endif

#if defined(CUSTOM_SHIFT_ENABLE)
# include "custom_shift_keys.h"
#endif

#if defined(SWAP_KEYS_ENABLE)
# include "swap_keys.h"
#endif

#if defined(HISTORY_ENABLE)
# include "history.h"
#endif

#if defined(NUMWORD_ENABLE)
# include "num_word.h"
# include "num_word_user.h"
#endif

#if defined(REPEAT_KEYS_ENABLE)
# include "repeat_key.h"
# include "repeat_key_user.h"
#endif
