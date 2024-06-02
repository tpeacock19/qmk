#include "keycodes.h"
#undef CONTROLLER
#define CONTROLLER atmel-dfu
#include "tpeacock19.h"


 // START-MUGUR-REGION

 #include QMK_KEYBOARD_H
#include "version.h"


/* Macros */


/* Tap Dances */



/* Leader Keys */


/* Combos */
enum {KC_W__KC_F, KC_U__KC_Y, MT_MOD_LCTL_KC_T__KC_G, MT_MOD_LGUI_KC_D__KC_V, KC_M__MT_MOD_LCTL_KC_N, KC_K__MT_MOD_LGUI_KC_H, MT_MOD_LSFT_KC_S__MT_MOD_LSFT_KC_E, MT_MOD_LCTL_KC_T__MT_MOD_LCTL_KC_N, MT_MOD_LSFT_KC_E__OS_MODS, MT_MOD_LCTL_KC_N__OS_MODS, MT_MOD_LALT_KC_I__OS_MODS, KC_O__OS_MODS, MT_MOD_LGUI_KC_H__OS_MODS, MT_MOD_LSFT_KC_S__MOD_SPC, MT_MOD_LCTL_KC_T__MOD_SPC, MT_MOD_LALT_KC_R__MOD_SPC, KC_A__MOD_SPC, MT_MOD_LGUI_KC_D__MOD_SPC, MT_MOD_LALT_KC_I__MOD_SPC, MT_MOD_LALT_KC_R__OS_MODS, KC_Y__MOD_SPC, KC_W__OS_MODS, OS_MODS__DOTMIN, NAV_SFT__SYM_RPT, MOD_SPC__OS_MODS, OS_MODS__SYM_RPT, MOD_SPC__NAV_SFT}; 

const uint16_t PROGMEM kc_w__kc_f[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM kc_u__kc_y[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM mt_mod_lctl_kc_t__kc_g[] = {MT(MOD_LCTL, KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM mt_mod_lgui_kc_d__kc_v[] = {MT(MOD_LGUI, KC_D), KC_V, COMBO_END};
const uint16_t PROGMEM kc_m__mt_mod_lctl_kc_n[] = {KC_M, MT(MOD_LCTL, KC_N), COMBO_END};
const uint16_t PROGMEM kc_k__mt_mod_lgui_kc_h[] = {KC_K, MT(MOD_LGUI, KC_H), COMBO_END};
const uint16_t PROGMEM mt_mod_lsft_kc_s__mt_mod_lsft_kc_e[] = {MT(MOD_LSFT, KC_S), MT(MOD_LSFT, KC_E), COMBO_END};
const uint16_t PROGMEM mt_mod_lctl_kc_t__mt_mod_lctl_kc_n[] = {MT(MOD_LCTL, KC_T), MT(MOD_LCTL, KC_N), COMBO_END};
const uint16_t PROGMEM mt_mod_lsft_kc_e__os_mods[] = {MT(MOD_LSFT, KC_E), OS_MODS, COMBO_END};
const uint16_t PROGMEM mt_mod_lctl_kc_n__os_mods[] = {MT(MOD_LCTL, KC_N), OS_MODS, COMBO_END};
const uint16_t PROGMEM mt_mod_lalt_kc_i__os_mods[] = {MT(MOD_LALT, KC_I), OS_MODS, COMBO_END};
const uint16_t PROGMEM kc_o__os_mods[] = {KC_O, OS_MODS, COMBO_END};
const uint16_t PROGMEM mt_mod_lgui_kc_h__os_mods[] = {MT(MOD_LGUI, KC_H), OS_MODS, COMBO_END};
const uint16_t PROGMEM mt_mod_lsft_kc_s__mod_spc[] = {MT(MOD_LSFT, KC_S), MOD_SPC, COMBO_END};
const uint16_t PROGMEM mt_mod_lctl_kc_t__mod_spc[] = {MT(MOD_LCTL, KC_T), MOD_SPC, COMBO_END};
const uint16_t PROGMEM mt_mod_lalt_kc_r__mod_spc[] = {MT(MOD_LALT, KC_R), MOD_SPC, COMBO_END};
const uint16_t PROGMEM kc_a__mod_spc[] = {KC_A, MOD_SPC, COMBO_END};
const uint16_t PROGMEM mt_mod_lgui_kc_d__mod_spc[] = {MT(MOD_LGUI, KC_D), MOD_SPC, COMBO_END};
const uint16_t PROGMEM mt_mod_lalt_kc_i__mod_spc[] = {MT(MOD_LALT, KC_I), MOD_SPC, COMBO_END};
const uint16_t PROGMEM mt_mod_lalt_kc_r__os_mods[] = {MT(MOD_LALT, KC_R), OS_MODS, COMBO_END};
const uint16_t PROGMEM kc_y__mod_spc[] = {KC_Y, MOD_SPC, COMBO_END};
const uint16_t PROGMEM kc_w__os_mods[] = {KC_W, OS_MODS, COMBO_END};
const uint16_t PROGMEM os_mods__dotmin[] = {OS_MODS, DOTMIN, COMBO_END};
const uint16_t PROGMEM nav_sft__sym_rpt[] = {NAV_SFT, SYM_RPT, COMBO_END};
const uint16_t PROGMEM mod_spc__os_mods[] = {MOD_SPC, OS_MODS, COMBO_END};
const uint16_t PROGMEM os_mods__sym_rpt[] = {OS_MODS, SYM_RPT, COMBO_END};
const uint16_t PROGMEM mod_spc__nav_sft[] = {MOD_SPC, NAV_SFT, COMBO_END};

combo_t key_combos[27] = {
[KC_W__KC_F] = COMBO(kc_w__kc_f, KC_Z),
[KC_U__KC_Y] = COMBO(kc_u__kc_y, LINQ),
[MT_MOD_LCTL_KC_T__KC_G] = COMBO(mt_mod_lctl_kc_t__kc_g, KC_TAB),
[MT_MOD_LGUI_KC_D__KC_V] = COMBO(mt_mod_lgui_kc_d__kc_v, KC_ESCAPE),
[KC_M__MT_MOD_LCTL_KC_N] = COMBO(kc_m__mt_mod_lctl_kc_n, KC_ENTER),
[KC_K__MT_MOD_LGUI_KC_H] = COMBO(kc_k__mt_mod_lgui_kc_h, KC_BSPC),
[MT_MOD_LSFT_KC_S__MT_MOD_LSFT_KC_E] = COMBO(mt_mod_lsft_kc_s__mt_mod_lsft_kc_e, CW_TOGG),
[MT_MOD_LCTL_KC_T__MT_MOD_LCTL_KC_N] = COMBO(mt_mod_lctl_kc_t__mt_mod_lctl_kc_n, NW_TOGG),
[MT_MOD_LSFT_KC_E__OS_MODS] = COMBO(mt_mod_lsft_kc_e__os_mods, KC_1),
[MT_MOD_LCTL_KC_N__OS_MODS] = COMBO(mt_mod_lctl_kc_n__os_mods, KC_3),
[MT_MOD_LALT_KC_I__OS_MODS] = COMBO(mt_mod_lalt_kc_i__os_mods, KC_5),
[KC_O__OS_MODS] = COMBO(kc_o__os_mods, KC_7),
[MT_MOD_LGUI_KC_H__OS_MODS] = COMBO(mt_mod_lgui_kc_h__os_mods, KC_9),
[MT_MOD_LSFT_KC_S__MOD_SPC] = COMBO(mt_mod_lsft_kc_s__mod_spc, KC_0),
[MT_MOD_LCTL_KC_T__MOD_SPC] = COMBO(mt_mod_lctl_kc_t__mod_spc, KC_2),
[MT_MOD_LALT_KC_R__MOD_SPC] = COMBO(mt_mod_lalt_kc_r__mod_spc, KC_4),
[KC_A__MOD_SPC] = COMBO(kc_a__mod_spc, KC_6),
[MT_MOD_LGUI_KC_D__MOD_SPC] = COMBO(mt_mod_lgui_kc_d__mod_spc, KC_8),
[MT_MOD_LALT_KC_I__MOD_SPC] = COMBO(mt_mod_lalt_kc_i__mod_spc, LCTL(KC_TAB)),
[MT_MOD_LALT_KC_R__OS_MODS] = COMBO(mt_mod_lalt_kc_r__os_mods, LCTL(LSFT(KC_TAB))),
[KC_Y__MOD_SPC] = COMBO(kc_y__mod_spc, XWFWD),
[KC_W__OS_MODS] = COMBO(kc_w__os_mods, XWBAK),
[OS_MODS__DOTMIN] = COMBO(os_mods__dotmin, XWTOG),
[NAV_SFT__SYM_RPT] = COMBO(nav_sft__sym_rpt, BASETOGG),
[MOD_SPC__OS_MODS] = COMBO(mod_spc__os_mods, OSL(L_WNAV)),
[OS_MODS__SYM_RPT] = COMBO(os_mods__sym_rpt, OSL(L_EMACS)),
[MOD_SPC__NAV_SFT] = COMBO(mod_spc__nav_sft, OSL(L_SWNAV))
};

/* Layer Codes and Matrix */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_COLEMAK] = LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOTE, KC_A, MT(MOD_LALT, KC_R), MT(MOD_LSFT, KC_S), MT(MOD_LCTL, KC_T), KC_G, KC_M, MT(MOD_LCTL, KC_N), MT(MOD_LSFT, KC_E), MT(MOD_LALT, KC_I), KC_O, KC_Z, KC_X, KC_C, MT(MOD_LGUI, KC_D), KC_V, KC_K, MT(MOD_LGUI, KC_H), COMPAR, DOTMIN, SLSEXC, NAV_SFT, OS_MODS, MOD_SPC, SYM_RPT),

	[L_GOLD] = LAYOUT(KC_J, KC_G, KC_M, KC_P, KC_V, KC_SEMICOLON, KC_DOT, KC_SLASH, KC_DOUBLE_QUOTE, KC_QUOTE, KC_R, MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_D), KC_B, KC_COMMA, MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_E), MT(MOD_LALT, KC_I), KC_H, KC_X, KC_F, KC_L, MT(MOD_LGUI, KC_C), KC_W, KC_MINUS, MT(MOD_LGUI, KC_U), KC_O, KC_Y, KC_K, NAV_SFT, MOD_T, MOD_SPC, SYM_RPT),

	[L_SYM] = LAYOUT(KC_NO, LALT(KC_LEFT_ANGLE_BRACKET), KC_HASH, KC_COLON, KC_SEMICOLON, KC_EQUAL, KC_AMPERSAND, KC_AT, LALT(KC_RIGHT_ANGLE_BRACKET), KC_NO, KC_BACKSLASH, KC_QUOTE, LINCBR, LINPRN, LINBRC, KC_ASTERISK, KC_DOLLAR, LALT(KC_PERCENT), LALT(KC_EXCLAIM), KC_NO, KC_NO, KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO, KC_CIRCUMFLEX, COMPAR, DOTMIN, SLSEXC, OSL(L_NUM), KC_TRNS, KC_NO, KC_TRNS),

	[L_NUM] = LAYOUT(KC_DOWN, KC_PLUS, KC_EQUAL, KC_AT, KC_NO, KC_NO, KC_HASH, KC_EXCLAIM, KC_PERCENT, KC_AMPERSAND, KC_6, KC_4, MT(MOD_LSFT, KC_0), KC_2, KC_UP, OSM(MOD_LSFT), KC_3, MT(MOD_LSFT, KC_1), KC_5, KC_7, KC_X, KC_DOLLAR, KC_ASTERISK, KC_8, KC_NO, KC_BSPC, KC_9, COMPAR, DOTMIN, SLSEXC, TO(0), KC_TRNS, KC_TRNS, KC_TRNS),

	[L_MODS] = LAYOUT(KC_NO, XWBAK, KC_PAGE_DOWN, LCTL(LSFT(KC_TAB)), KC_NO, KC_NO, LCTL(KC_TAB), KC_PAGE_UP, XWFWD, KC_NO, OSL(L_SWNAV), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), XREDO, KC_DELETE, OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT), OSL(L_MEDIA), XUNDO, XCUT, XCOPY, OSM(MOD_LGUI), XPAST, KC_BSPC, OSM(MOD_LGUI), KC_ESCAPE, KC_TAB, LLOCK, TO(0), KC_TRNS, KC_ENTER, SWAPKEY),

	[L_NAV] = LAYOUT(KC_NO, XWBAK, KC_MS_UP, LCTL(LSFT(KC_TAB)), KC_NO, KC_NO, LCTL(KC_TAB), KC_NO, XWFWD, BASETOGG, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TO(L_EMACS), TG_OS, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_NO, KC_MS_BTN1, KC_MS_BTN2, KC_APPLICATION, TG_LIN, TO(0), KC_TRNS, LLOCK, OSL(L_WNAV)),

	[L_WNAV] = LAYOUT(XCLOSE, XWBAK, LGUI(KC_F), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XWFWD, KC_NO, G(KC_6), G(KC_4), G(KC_0), G(KC_2), LGUI(KC_RIGHT), LGUI(KC_LEFT), G(KC_3), G(KC_1), G(KC_5), G(KC_7), XLOCK, KC_NO, LGUI(KC_N), G(KC_8), G(KC_EQL), G(KC_MINS), G(KC_9), LGUI(KC_E), XWTOG, KC_NO, TO(0), KC_TRNS, XSRCH, G(KC_TAB)),

	[L_SWNAV] = LAYOUT(XCLOSE, XWBAK, LGUI(KC_F), KC_NO, KC_NO, KC_NO, KC_NO, LGUI(LSFT(KC_U)), XWFWD, KC_NO, S(G(KC_6)), S(G(KC_4)), S(G(KC_0)), S(G(KC_2)), S(G(KC_RIGHT)), S(G(KC_LEFT)), S(G(KC_3)), S(G(KC_1)), S(G(KC_5)), S(G(KC_7)), XLOCK, XWMOVL, KC_N, S(G(KC_8)), G(KC_EQL), G(KC_MINS), S(G(KC_9)), KC_E, XWMOV, KC_NO, TO(0), KC_TRNS, S(G(KC_SPC)), S(G(KC_TAB))),

	[L_MEDIA] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LGUI, KC_LCTL, KC_NO, KC_AUDIO_MUTE, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MS_BTN1, KC_MS_BTN2, KC_MS_WH_RIGHT, KC_F20, TO(0), KC_TRNS, KC_ENTER, TO(L_FUNC)),

	[L_FUNC] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F6, KC_F4, KC_NO, KC_F2, KC_NO, KC_NO, KC_F3, KC_F1, KC_F5, KC_F7, KC_NO, KC_F12, KC_F10, KC_F8, KC_NO, KC_NO, KC_F9, KC_F11, KC_NO, KC_NO, TO(0), KC_TRNS, KC_NO, MYRESET),

	[L_EMACS] = LAYOUT(LCTL(KC_G), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, REPEAT, KC_TAB, KC_NO, LCTL(LALT(KC_R)), LCTL(LALT(KC_T)), LCTL(KC_G), LCTL(LALT(KC_SPACE)), LCTL(LALT(KC_F)), LCTL(LALT(KC_B)), LCTL(LALT(LGUI(KC_U))), KC_ENTER, LALT(KC_X), KC_NO, LALT(KC_MINUS), LCTL(LALT(KC_K)), KC_NO, LCTL(LALT(KC_U)), LCTL(LALT(KC_D)), LCTL(KC_LEFT_ANGLE_BRACKET), LCTL(KC_RIGHT_ANGLE_BRACKET), LCTL(LALT(KC_E)), TO(0), KC_TRNS, KC_NO, REPEAT)
};

/* Per Key Tapping Terms */
 

// END-MUGUR-REGION              
