;;; qmk-keymap.el --- tpeacock19 fc660c keymap -*- lexical-binding: t; -*-
;;
;; Copyright (C) 2022 Trey Peacock
;;
;; Author: Trey Peacock <https://github/tpeacock19>
;; Maintainer: Trey Peacock <git@treypeacock.com>
;; Created: May 06, 2022
;; Modified: May 06, 2022
;; Version: 0.0.1
;; Keywords:
;; Homepage: https://github.com/tpeacock19/keymap
;; Package-Requires: ((emacs 29.0.50) (cl-lib "0.5"))
;;
;; This file is not part of GNU Emacs.
;;
;; This file is free software; you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published by the
;; Free Software Foundation; either version 3, or (at your option) any
;; later version.

;; This program is distributed in the hope that it will be useful, but
;; WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;; General Public License for more details.

;; For a full copy of the GNU General Public License
;; see <http://www.gnu.org/licenses/>.
;;
;;; Commentary:
;;
;; tpeacock19 ferris sweep keymap
;;
;;; Code:
;; * Colemak

;; ** combos
(defvar colemak-combo-keys
  '(;; Common
    ((w f) z)
    ((u y) linq)
    ;; ((m n) ent)
    ;; ((k h) bspc)
    ((C_t g) tab)
    ((G_d v) esc)
    ((m C_n) ent)
    ((k G_h) bspc)
    ;; Cases
    ;; ((s e) (RAW "CW_TOGG"))
    ;; ((n t) (RAW "NW_TOGG"))
    ((S_s S_e) (RAW "CW_TOGG"))
    ((C_t C_n) (RAW "NW_TOGG"))
    ;; Numbers
    ((S_e oslmod) 1)
    ((C_n oslmod) 3)
    ((M_i oslmod) 5)
    ((o oslmod) 7)
    ((G_h oslmod) 9)
    ((S_s mod_sp) 0)
    ((C_t mod_sp) 2)
    ((M_r mod_sp) 4)
    ((a mod_sp) 6)
    ((G_d mod_sp) 8)
    ;; Browsers
    ;; ((i mod_sp) n_tab)
    ;; ((r oslmod) p_tab)
    ((M_i mod_sp) n_tab)
    ((M_r oslmod) p_tab)
    ;; Workspaces
    ((y mod_sp) xwfwd)
    ((w oslmod) xwbak)
    ((oslmod dotmin) xwtog)
    ;; Layers
    ((navsft symrpt) basetog)
    ((mod_sp oslmod) (OSL "l_wnav"))
    ((oslmod symrpt) (OSL "l_emacs"))
    ((mod_sp navsft) (OSL "l_swnav"))))

;; ** defined keys
(defvar colemak-user-defined-keys
  '((lbase (TO "0"))
    (lsym (TO "l_sym"))
    (lnum (TO "l_sym"))
    (lmod (TO "l_mods"))
    (lmedia (TO "l_media"))
    (lfunc (TO "l_func"))
    (lemacs (TO "l_emacs"))
    (lnav (TO "l_nav"))
    (lwnav (TO "l_wnav"))
    (lswnav (TO "l_swnav"))
    (oslsym (OSL "l_sym"))
    (oswnav (OSL "l_wnav"))
    (oSwnav (OSL "l_swnav"))
    (osmedia (OSL "l_media"))
    (osemacs (OSL "l_emacs"))
    (osnum (OSL "l_num"))
    (mod_sp (RAW "MOD_SPC"))
    (mod_t (RAW "MOD_T"))
    ;; custom tap-holds
    (navsft (RAW "NAV_SFT"))
    (medsft (RAW "MED_SFT"))
    (navrpt (RAW "NAV_RPT"))
    (medrpt (RAW "MED_RPT"))
    (navrev (RAW "NAV_REV"))
    (symrpt (RAW "SYM_RPT"))
    (numrpt (RAW "NUM_RPT"))
    (symrev (RAW "SYM_REV"))
    (modnum (RAW "MOD_NUM"))
    (nummod (RAW "NUM_MOD"))
    (oslmod (RAW "OS_MODS"))
    ;; Swapper
    (swapkey (RAW "SWAPKEY"))
    ;; Repeat
    (rpt (RAW "REPEAT"))
    ;; emacs
    ;; (CM_?\% C-M-?\%)
    ;; (CM_?\, C-M-?\,)
    ;; (CM_?\- C-M-?\-)
    ;; (CM_?\. C-M-?\.)
    ;; (CM_?\/ C-M-?\/)
    ;; (CM_c C-M-c)
    ;; (CM_?\\ C-M-?\\)
    ;; (CM_?\_ C-M-?\_)
    ;; (CM_D C-M-S-d)
    ;; (CM_F C-M-S-f)
    ;; (CM_h C-M-h)
    ;; (CM_j C-M-j)
    ;; (CM_l C-M-l)
    ;; (CM_n C-M-n)
    ;; (CM_o C-M-o)
    ;; (CM_p C-M-p)
    ;; (CM_v C-M-v)
    ;; (CM_w C-M-w)
    (M_lt M-left_angle)
    (M_gt M-right_angle)
    (M_exc M-exclaim)
    (M_per M-percent)
    (M_amp M-ampersand)
    (M_mi M-mins)
    (CM_a C-M-a)
    (CM_b C-M-b)
    (CM_d C-M-d)
    (CM_e C-M-e)
    (CM_f C-M-f)
    (C_g C-g)
    (CM_k C-M-k)
    (CM_r C-M-r)
    (CM_t C-M-t)
    (CM_u C-M-u)
    (CMG_u C-M-G-u)
    (CM_lt C-left_angle)
    (CM_gt C-right_angle)
    (CM_spc (C-M-spc))
    ;; wnav
    (xcut (RAW "XCUT"))
    (xcopy (RAW "XCOPY"))
    (xpaste (RAW "XPAST"))
    (xredo (RAW "XREDO"))
    (xundo (RAW "XUNDO"))
    (xwfwd (RAW "XWFWD"))
    (xwtog (RAW "XWTOG"))
    (xwtog (RAW "XWTOGL"))
    (xwbak (RAW "XWBAK"))
    (xsrch (RAW "XSRCH"))
    (xwmov (RAW "XWMOV"))
    (xwmovl (RAW "XWMOVL"))
    (xclose (RAW "XCLOSE"))
    (M_s (M s))
    (S_n (S n))
    (C_d (C d))
    (G_c (G c))
    (C_a (C a))
    (G_u (G u))
    (M_r (M r))
    (S_s (S s))
    (C_t (C t))
    (G_d (G d))
    (M_i (M i))
    (S_e (S e))
    (C_n (C n))
    (G_h (G h))
    (G_t (G t))
    (G_n (G n))
    (G_e (G e))
    (S-0 (S 0))
    (S-1 (S 1))
    (G-0 (RAW "G(KC_0)"))
    (G-1 (RAW "G(KC_1)"))
    (G-2 (RAW "G(KC_2)"))
    (G-3 (RAW "G(KC_3)"))
    (G-4 (RAW "G(KC_4)"))
    (G-5 (RAW "G(KC_5)"))
    (G-6 (RAW "G(KC_6)"))
    (G-7 (RAW "G(KC_7)"))
    (G-8 (RAW "G(KC_8)"))
    (G-9 (RAW "G(KC_9)"))
    (mnrght (RAW "G(KC_EQL)"))
    (mnlft (RAW "G(KC_MINS)"))
    (wlck (RAW "XLOCK"))
    (Gtab (RAW "G(KC_TAB)"))
    (GStab (RAW "S(G(KC_TAB))"))
    ;; wnav
    (GS_dot (RAW "XMOTH"))
    (GS_n (G-S-n))
    (GS_u (G-S-u))
    (GS_q (G-S-q))
    (GS_e (G-S-e))
    (GSrght (RAW "S(G(KC_RIGHT))"))
    (GSlft (RAW "S(G(KC_LEFT))"))
    (GS-0 (RAW "S(G(KC_0))"))
    (GS-1 (RAW "S(G(KC_1))"))
    (GS-2 (RAW "S(G(KC_2))"))
    (GS-3 (RAW "S(G(KC_3))"))
    (GS-4 (RAW "S(G(KC_4))"))
    (GS-5 (RAW "S(G(KC_5))"))
    (GS-6 (RAW "S(G(KC_6))"))
    (GS-7 (RAW "S(G(KC_7))"))
    (GS-8 (RAW "S(G(KC_8))"))
    (GS-9 (RAW "S(G(KC_9))"))
    (GSspc (RAW "S(G(KC_SPC))"))
    (n_tab C-tab)
    (p_tab C-S-tab)
    (mlsft (OSM S))
    (mrsft (OSM S))
    (malt (OSM M))
    (mctl (OSM C))
    (mgui (OSM G))
    (basetog (RAW "BASETOGG"))
    (tgmac (RAW "TG_MAC"))
    (tgwin (RAW "TG_WIN"))
    (tgos (RAW "TG_OS"))
    (tglin (RAW "TG_LIN"))
    (gtbase (RAW "GOTOBASE"))
    (licbr (RAW "LINCBR"))
    (liprn (RAW "LINPRN"))
    (librc (RAW "LINBRC"))
    (linq (RAW "LINQ"))
    (llck (RAW "LLOCK"))
    (compar (RAW "COMPAR"))
    (dotmin (RAW "DOTMIN"))
    (slsexc (RAW "SLSEXC"))
    (myrst (RAW "MYRESET"))))

;; ** keymap
(defvar colemak-keymap
  '(("l_colemak"
     q      w      f      p      b             j      l      u      y      ?\'
     a      M_r    S_s    C_t    g             m      C_n    S_e    M_i    o
     z      x      c      G_d    v             k      G_h    compar dotmin slsexc
     navsft oslmod                                                  mod_sp symrpt)
    ("l_gold" ;; hd-gold
     j      g      m      p      v             ?\;    ?\.    ?\/    ?\"    ?\'
     r      M_s    S_n    C_d    b             ?\,    C_a    S_e    M_i    h
     x      f      l      G_c    w             ?\-    G_u    o      y      k
     navsft mod_t                                                   mod_sp symrpt)
    ("l_sym"
     -x-    M_lt   ?\#    ?\:    ?\;           ?\=    ?\&    ?\@    M_gt   -x-
     ?\\    ?\'    licbr  liprn  librc         ?\*    ?\$    M_per  M_exc  -x-
     -x-    ?\`    -x-    -x-    -x-           -x-    ?\^    compar dotmin slsexc
     osnum  ---                                                     -x-    ---)
    ("l_num"
     down   ?\+    ?\=    ?\@    -x-           -x-    ?\#    ?\!    ?\%    ?\&
     6      4      S-0    2      up            mlsft  3      S-1    5      7
     x      ?\$    ?\*    8      -x-           bspc   9      compar dotmin slsexc
     lbase  ---                                                     ---    ---)
    ("l_mods"
     -x-    xwbak  pgdn   p_tab  -x-           -x-    n_tab  pgup   xwfwd   -x-
     oSwnav malt   mlsft  mctl   xredo         del    mctl   mlsft  malt   osmedia
     xundo  xcut   xcopy  mgui   xpaste        bspc   mgui   esc    tab    llck
     lbase  ---                                                     ent    swapkey)
    ("l_nav"
     -x-    xwbak   ms_u   p_tab  -x-          -x-    n_tab  -x-    xwfwd   basetog
     -x-    ms_l   ms_d   ms_r   -x-           left   down   up     right  lemacs
     tgos  wh_l   wh_u   wh_d   wh_r          -x-    btn1   btn2   app    tglin
     ;; tgwin  wh_l   wh_u   wh_d   wh_r          -x-    btn1   btn2   xwtog  tglin
     lbase  ---                                                     llck   oswnav)
    ("l_wnav"
     xclose xwbak   G-f    -x-    -x-           -x-    -x-    -x-    xwfwd   -x-
     G-6    G-4    G-0    G-2    G-right       G-left G-3    G-1    G-5    G-7
     wlck   xwtogl    G-n    G-8    mnrght        mnlft  G-9    G-e    xwtog  -x-
     lbase  ---                                                     xsrch  Gtab)
    ("l_swnav"
     xclose xwbak   G-f    -x-    -x-           -x-   -x-    GS_u   xwfwd   -x-
     GS-6   GS-4   GS-0   GS-2   GSrght        GSlft GS-3   GS-1   GS-5   GS-7
     wlck   xwmovl GS-n   GS-8   mnrght        mnlft GS-9   GS-e   xwmov  -x-
     lbase  ---                                                    GSspc GStab)
    ("l_media"
     -x-    -x-    -x-    -x-    brid          briu   -x-    -x-    -x-    -x-
     -x-    lalt   lgui   lctl   -x-           mute   mprv   mply   mnxt   -x-
     -x-    -x-    -x-    lsft   vold          volu   btn1   btn2   wh_r   f20
     lbase  ---                                                     ent    lfunc)
    ("l_func"
     -x-    -x-    -x-    -x-    -x-           -x-    -x-    -x-    -x-    -x-
     f6     f4     -x-    f2     -x-           -x-    f3     f1     f5     f7
     -x-    f12    f10    f8     -x-           -x-    f9     f11    -x-    -x-
     lbase  ---                                                     -x-    myrst)
    ("l_emacs"
     C-g    -x-    -x-    -x-    -x-           -x-    -x-    -x-    -x-    rpt
     tab    -x-    CM_r   CM_t   C-g           CM_spc CM_f   CM_b   CMG_u  ent
     M-x    -x-    M_mi   CM_k   -x-           CM_u   CM_d   CM_lt  CM_gt  CM_e
     lbase  ---                                                     -x-    rpt)))

;; * HD Neu

;; ** combos
(defvar hd-neu-combo-keys
  '(
    ;; gold
    ((j g) z)
    ((k u) linq)
    ((s n) "sh")
    ((n d) "th")
    ((l c) "ch")
    ((h i) "wh")
    ((g m) "gh")
    ((m p) "ph")
    ;; elan
    ((y u) q)
    ((v g) z)
    ((y w) j)
    ((t n) "th")
    ((c e) "ch")
    ((s n) "sh")
    ((p h) "ph")
    ((g h) "gh")
    ((w o) "wh")
    ;; neu
    ((w f) z)
    ((y k) j)
    ;; ((s n) "sh")
    ((n t) "th")
    ((c l) "ch")
    ;; ((m p) "ph")
    ((g h) "gh")
    ;; ((h i) "wh")
    ))

;; *** defined keys
(defvar hd-neu-user-defined-keys
  '((to_1 (TO "l_base"))
    (to_2 (TO "l_num"))
    (to_3 (TO "l_mods"))
    (to_4 (TO "l_media"))
    (to_5 (TO "l_func"))
    (emc (TO "l_emacs"))
    (wnav (TO "l_wnav"))
    (tt_2 (TT "l_num"))
    (os2 (OSL "l_num"))
    (os3 (OSL "l_mods"))
    (tt_3 (TT "l_mods"))
    (nav_co (LT "l_nav" ?\,))
    (mod_t (LT "l_mods" t))
    (mod_ent (LT "l_mods" ent))
    (sym_sp (LT "l_sym" spc))
    (ltos2 (RAW "LTOSM2"))
    (ltos3 (RAW "LTOSM3"))
    (M_r (M r))
    (CM_?\% C-M-?\%)
    (CM_?\, C-M-?\,)
    (CM_?\- C-M-?\-)
    (M_mi M-mins)
    (CM_?\. C-M-?\.)
    (G_dot G-dot)
    (S_tab S-tab)
    (CM_?\/ C-M-?\/)
    (CM_c C-M-c)
    (CM_?\\ C-M-?\\)
    (CM_?\_ C-M-?\_)
    (CM_a C-M-a)
    (CM_b C-M-b)
    (CM_d C-M-d)
    (CM_D C-M-S-d)
    (CM_e C-M-e)
    (CM_f C-M-f)
    (CM_F C-M-S-f)
    (C_g C-g)
    (CM_h C-M-h)
    (CM_j C-M-j)
    (CM_k C-M-k)
    (CM_l C-M-l)
    (CM_n C-M-n)
    (CM_o C-M-o)
    (CM_p C-M-p)
    (CM_r C-M-r)
    (CM_t C-M-t)
    (CM_u C-M-u)
    (CMG_u C-M-G-u)
    (CM_v C-M-v)
    (CM_w C-M-w)
    (CM_lt C-left_angle)
    (CM_gt C-right_angle)
    (CM_spc (C-M-spc))
    (C_s (C s))
    (G_t (G t))
    (G_n (G n))
    (G-0 (RAW "G(KC_0)"))
    (G-1 (RAW "G(KC_1)"))
    (G-2 (RAW "G(KC_2)"))
    (G-3 (RAW "G(KC_3)"))
    (G-4 (RAW "G(KC_4)"))
    (G-5 (RAW "G(KC_5)"))
    (G-6 (RAW "G(KC_6)"))
    (G-7 (RAW "G(KC_7)"))
    (G-8 (RAW "G(KC_8)"))
    (G-9 (RAW "G(KC_9)"))
    (C_e (C e))
    (C_5 (C 5))
    (M_6 (M 6))
    (M_i (M i))
    (G_\' (G ?\'))
    (G_\+ (G ?\+))
    (S_\\ (S ?\\))
    (C_lbr (C ?\[))
    (C_lcl (C ?\{))
    (C_rbr (C ?\]))
    (M_ap (M ?\'))
    (M_spc (M spc))
    (G_spc (G spc))
    (M_vu (M volu))
    (M_mute (M mute))
    (G_vd (G vold))
    (G_S (G lsft))
    (M_up (M up))
    (G_dn (M down))
    (n_tab C-tab)
    (p_tab C-S-tab)
    (mlsft (OSM S))
    (mrsft (OSM S))
    (malt (OSM M))
    (mctl (OSM C))
    (mgui (OSM G))
    (CMspc (C M spc))
    (llck (RAW "LLOCK" ) )
    (rpt (RAW "REPEAT"))
    (rrpt (RAW "REV_RPT"))
    (to1 (DANCE-FN nil
                   (RAW "l_colemak_tt_finished")
                   (RAW "l_colemak_tt_reset")))
    (tt2 (DANCE-FN nil
                   (RAW "num_tt_finished")
                   (RAW "num_tt_reset")))
    (tt3 (DANCE-FN nil
                   (RAW "l_mods_tt_finished")
                   (RAW "l_mods_tt_reset")))
    (to4 (DANCE-FN nil
                   (RAW "l_media_tt_finished")
                   (RAW "l_media_tt_reset")))
    (Mt1 (DANCE-FN nil
                   (RAW "meta1_finished")
                   (RAW "meta1_reset")))
    (Gt1 (DANCE-FN nil
                   (RAW "gui1_finished")
                   (RAW "gui1_reset")))
    (Mt2 (DANCE-FN nil
                   (RAW "meta2_finished")
                   (RAW "meta2_reset")))
    (Gt2 (DANCE-FN nil
                   (RAW "gui2_finished")
                   (RAW "gui2_reset")))
    (Gto1 (DANCE-FN nil
                    (RAW "layer1_gui_finished")
                    (RAW "layer1_gui_reset")))
    (Gto2 (DANCE-FN nil
                    (RAW "layer2_gui_finished")
                    (RAW "layer2_gui_reset")))
    (CMsft (C M lsft))
    (Gspc (DANCE-FN nil
                    (RAW "spc_gui_finished")
                    (RAW "spc_gui_reset")))
    (M_qt (DANCE-FN nil
                    (RAW "meta_dquote_finished")
                    (RAW "meta_dquote_reset")))
    (M_pip (DANCE-FN nil
                     (RAW "meta_pipe_finished")
                     (RAW "meta_pipe_reset")))
    (dot_mi (DANCE-FN nil
                      (RAW "dot_minus_finished")
                      (RAW "dot_minus_reset")))
    (co_mi (DANCE-FN nil
                     (RAW "comma_minus_finished")
                     (RAW "comma_minus_reset")))
    (nav_cp (DANCE-FN nil
                      (RAW "nav_comma_paren_finished")
                      (RAW "nav_comma_paren_reset")))
    (co_pn (DANCE-FN nil
                     (RAW "comma_paren_finished")
                     (RAW "comma_paren_reset")))
    (dot_ex (DANCE-FN nil
                      (RAW "dot_exclaim_finished")
                      (RAW "dot_exclaim_reset")))
    (sl_pn (DANCE-FN nil
                     (RAW "slsh_paren_finished")
                     (RAW "slsh_paren_reset")))
    (sl_ex (DANCE-FN nil
                     (RAW "slsh_exclaim_finished")
                     (RAW "slsh_exclaim_reset")))
    (qt_td (DANCE-FN nil
                     (RAW "ql_finished")
                     (RAW "ql_reset")))
    (td_r (DANCE-FN (RAW "safe_reset")))))

;; ** keymap
(defvar hd-neu-keymap
  '(("l_base"
     w      f      m      p      v          ?\/    ?\.    ?\;    ?\"    ?\'
     r      s      n      t      b          rpt    a      e      i      h
     x      c      l      d      g          ?\-    u      o      y      k
     nav_co mlsft                                                sym_sp mod_ent)
    ("l_colemak"
     q      w      f      p      b          j      l      u      y      rpt
     a      r      s      t      g          m      n      e      i      o
     z      x      c      d      v          k      h      co_pn  dot_mi sl_ex
     os3    mlsft                                                spc    os2)
    ("l_nav"
     -x-    -x-    ms_u   -x-    -x-        -x-    -x-    up     -x-    S_tab
     esc    ms_l   ms_d   ms_r   -x-        -x-    left   down   right  tab
     -x-    wh_l   wh_d   wh_r   -x-        -x-    -x-    wh_u   -x-    emc
     to1    tab                                                  llck   wnav)
    ("l_mods"
     -x-    -x-    -x-    -x-    -x-        -x-    -x-    -x-    -x-    -x-
     esc    malt   mgui   mctl   mlsft      mlsft  mctl   mgui   malt   tab
     undo   cut    copy   paste  -x-        -x-    -x-    -x-    G_dot  emc
     to1    tab                                                  llck   to_4)
    ("l_num"
     down   ?\+    ?\*    ?\!    ---        x      ---    ---    rpt    ?\.
     6      4      0      2      up         ---    3      1      5      7
     ?\,    ?\.    ---    8      ---        ?\/    9      ?\(    ?\)    ?\_
     to_1   ent                                                  llck  to4)
    ("l_wnav"
     down   wbak   G-f    -x-    -x-        -x-    -x-    -x-    wfwd   -x-
     G-6    G-4    G-0    G-2    G-up       -x-    G-3    G-1    G-5    G-7
     -x-    -x-    -x-    G-8    -x-        -x-    G-9    G-n    G-e    -x-
     to_1   ent                                                  llck   -x-)
    ("l_num"
     ?\\    ?\`    ?\#    ?\:    ?\;        ?\=    7      8      9      ?\+
     esc    ?\'    ?\{    ?\(    ?\[        ?\*    4      5      6      ?\-
     mlsft  ?\.    ?\}    ?\)    ?\]        0      1      2      3      ---
     to_1   ent                                                  llck   to4)
    ("l_sym"
     ?\\    ?\`    ?\#    ?\:    ?\;        ?\=    7      8      9      ?\+
     esc    ?\'    ?\{    ?\(    ?\[        ?\*    4      5      6      ?\-
     mlsft  ?\.    ?\}    ?\)    ?\]        0      1      2      3      ---
     to_1   ent                                                  llck   to4)
    ("l_media"
     -x-    wh_d   ms_u   -x-    brid       briu   -x-    -x-    wh_u   -x-
     esc    ms_l   ms_d   ms_r   -x-        -x-    mprv   mply   mnxt   mute
     -x-    wh_l   -x-    -x-    vold       volu   btn1   btn2   wh_r   f20
     to_1   ---                                                  llck   to_5)
    ("l_func"
     -x-    -x-    -x-    -x-    -x-        f10    f7     f8     f9     -x-
     -x-    malt   mgui   mctl   -x-        f11    f4     f5     f6     del
     td_r   -x-    -x-    -x-    -x-        f12    f1     f2     f3     -x-
     to_1   -x-                                                  llck   to_2)
    ("l_emacs"
     C_g    -x-    -x-    ---    -x-        ---    -x-    ---    ---    rpt
     tab    -x-    CM_r   CM_t   ---        CM_spc CM_f   CM_b   CMG_u  ent
     CM_a   ---    M_mi   CM_k   ---        CM_u   CM_d   CM_lt  CM_gt  CM_e
     to_1   ---                                                  llck   to_2)))

;; * HD Elan

;; ** combos
(defvar hd-elan-combo-keys
  '(
    ;; gold
    ((j g) z)
    ((k u) q)
    ((s n) "sh")
    ((n d) "th")
    ((l c) "ch")
    ((h i) "wh")
    ((g m) "gh")
    ((m p) "ph")
    ;; elan
    ((y u) q)
    ((v g) z)
    ((y w) j)
    ((t n) "th")
    ((c e) "ch")
    ((s n) "sh")
    ((p h) "ph")
    ((g h) "gh")
    ((w o) "wh")
    ;; neu
    ((w f) z)
    ((y k) j)
    ;; ((s n) "sh")
    ((n t) "th")
    ((c l) "ch")
    ;; ((m p) "ph")
    ((g h) "gh")
    ;; ((h i) "wh")
    ))

;; ** defined keys
(defvar hd-elan-user-defined-keys
  '((to_1 (TO "l_base"))
    (to_2 (TO "l_num"))
    (to_3 (TO "l_mods"))
    (to_4 (TO "l_media"))
    (to_5 (TO "l_func"))
    (emc (TO "l_emacs"))
    (wnav (TO "l_wnav"))
    (tt_2 (TT "l_num"))
    (os2 (OSL "l_num"))
    (os3 (OSL "l_mods"))
    (tt_3 (TT "l_mods"))
    (nav_co (LT "l_nav" ?\,))
    (mod_t (LT "l_mods" t))
    (mod_ent (LT "l_mods" ent))
    (sym_sp (LT "l_sym" spc))
    (ltos2 (RAW "LTOSM2"))
    (ltos3 (RAW "LTOSM3"))
    (M_r (M r))
    (CM_?\% C-M-?\%)
    (CM_?\, C-M-?\,)
    (CM_?\- C-M-?\-)
    (M_mi M-mins)
    (CM_?\. C-M-?\.)
    (G_dot G-dot)
    (S_tab S-tab)
    (CM_?\/ C-M-?\/)
    (CM_c C-M-c)
    (CM_?\\ C-M-?\\)
    (CM_?\_ C-M-?\_)
    (CM_a C-M-a)
    (CM_b C-M-b)
    (CM_d C-M-d)
    (CM_D C-M-S-d)
    (CM_e C-M-e)
    (CM_f C-M-f)
    (CM_F C-M-S-f)
    (C_g C-g)
    (CM_h C-M-h)
    (CM_j C-M-j)
    (CM_k C-M-k)
    (CM_l C-M-l)
    (CM_n C-M-n)
    (CM_o C-M-o)
    (CM_p C-M-p)
    (CM_r C-M-r)
    (CM_t C-M-t)
    (CM_u C-M-u)
    (CMG_u C-M-G-u)
    (CM_v C-M-v)
    (CM_w C-M-w)
    (CM_lt C-left_angle)
    (CM_gt C-right_angle)
    (CM_spc (C-M-spc))
    (C_s (C s))
    (G_t (G t))
    (G_n (G n))
    (G-0 (RAW "G(KC_0)"))
    (G-1 (RAW "G(KC_1)"))
    (G-2 (RAW "G(KC_2)"))
    (G-3 (RAW "G(KC_3)"))
    (G-4 (RAW "G(KC_4)"))
    (G-5 (RAW "G(KC_5)"))
    (G-6 (RAW "G(KC_6)"))
    (G-7 (RAW "G(KC_7)"))
    (G-8 (RAW "G(KC_8)"))
    (G-9 (RAW "G(KC_9)"))
    (C_e (C e))
    (C_5 (C 5))
    (M_6 (M 6))
    (M_i (M i))
    (G_\' (G ?\'))
    (G_\+ (G ?\+))
    (S_\\ (S ?\\))
    (C_lbr (C ?\[))
    (C_lcl (C ?\{))
    (C_rbr (C ?\]))
    (M_ap (M ?\'))
    (M_spc (M spc))
    (G_spc (G spc))
    (M_vu (M volu))
    (M_mute (M mute))
    (G_vd (G vold))
    (G_S (G lsft))
    (M_up (M up))
    (G_dn (M down))
    (n_tab C-tab)
    (p_tab C-S-tab)
    (mlsft (OSM S))
    (mrsft (OSM S))
    (malt (OSM M))
    (mctl (OSM C))
    (mgui (OSM G))
    (CMspc (C M spc))
    (llck (RAW "LLOCK" ) )
    (rpt (RAW "REPEAT"))
    (rrpt (RAW "REV_RPT"))
    (to1 (DANCE-FN nil
                   (RAW "l_colemak_tt_finished")
                   (RAW "l_colemak_tt_reset")))
    (tt2 (DANCE-FN nil
                   (RAW "num_tt_finished")
                   (RAW "num_tt_reset")))
    (tt3 (DANCE-FN nil
                   (RAW "l_mods_tt_finished")
                   (RAW "l_mods_tt_reset")))
    (to4 (DANCE-FN nil
                   (RAW "l_media_tt_finished")
                   (RAW "l_media_tt_reset")))
    (Mt1 (DANCE-FN nil
                   (RAW "meta1_finished")
                   (RAW "meta1_reset")))
    (Gt1 (DANCE-FN nil
                   (RAW "gui1_finished")
                   (RAW "gui1_reset")))
    (Mt2 (DANCE-FN nil
                   (RAW "meta2_finished")
                   (RAW "meta2_reset")))
    (Gt2 (DANCE-FN nil
                   (RAW "gui2_finished")
                   (RAW "gui2_reset")))
    (Gto1 (DANCE-FN nil
                    (RAW "layer1_gui_finished")
                    (RAW "layer1_gui_reset")))
    (Gto2 (DANCE-FN nil
                    (RAW "layer2_gui_finished")
                    (RAW "layer2_gui_reset")))
    (CMsft (C M lsft))
    (Gspc (DANCE-FN nil
                    (RAW "spc_gui_finished")
                    (RAW "spc_gui_reset")))
    (M_qt (DANCE-FN nil
                    (RAW "meta_dquote_finished")
                    (RAW "meta_dquote_reset")))
    (M_pip (DANCE-FN nil
                     (RAW "meta_pipe_finished")
                     (RAW "meta_pipe_reset")))
    (dot_mi (DANCE-FN nil
                      (RAW "dot_minus_finished")
                      (RAW "dot_minus_reset")))
    (co_mi (DANCE-FN nil
                     (RAW "comma_minus_finished")
                     (RAW "comma_minus_reset")))
    (nav_cp (DANCE-FN nil
                      (RAW "nav_comma_paren_finished")
                      (RAW "nav_comma_paren_reset")))
    (co_pn (DANCE-FN nil
                     (RAW "comma_paren_finished")
                     (RAW "comma_paren_reset")))
    (dot_ex (DANCE-FN nil
                      (RAW "dot_exclaim_finished")
                      (RAW "dot_exclaim_reset")))
    (sl_pn (DANCE-FN nil
                     (RAW "slsh_paren_finished")
                     (RAW "slsh_paren_reset")))
    (sl_ex (DANCE-FN nil
                     (RAW "slsh_exclaim_finished")
                     (RAW "slsh_exclaim_reset")))
    (qt_td (DANCE-FN nil
                     (RAW "ql_finished")
                     (RAW "ql_reset")))
    (td_r (DANCE-FN (RAW "safe_reset")))))

;; ** keymap
(defvar hd-elan-keymap
  '(("l_base"
     v      g      h      p      k          ?\/    ?\(    ?\{    ?\"    ?\'
     r      s      n      t      f          rpt    a      e      c      i
     x      m      l      d      b          ?\-    u      o      w      y
     nav_co ?\.                                                  sym_sp mod_ent)
    ("l_colemak"
     q      w      f      p      b          j      l      u      y      rpt
     a      r      s      t      g          m      n      e      i      o
     z      x      c      d      v          k      h      co_pn  dot_mi sl_ex
     os3    mlsft                                                spc    os2)
    ("l_nav"
     -x-    -x-    ms_u   -x-    -x-        -x-    -x-    up     -x-    S_tab
     esc    ms_l   ms_d   ms_r   -x-        -x-    left   down   right  tab
     -x-    wh_l   wh_d   wh_r   -x-        -x-    -x-    wh_u   -x-    emc
     to1    tab                                                  llck   wnav)
    ("l_mods"
     -x-    -x-    -x-    -x-    -x-        -x-    -x-    -x-    -x-    -x-
     esc    malt   mgui   mctl   mlsft      mlsft  mctl   mgui   malt   tab
     undo   cut    copy   paste  -x-        -x-    -x-    -x-    G_dot  emc
     to1    tab                                                  llck   to_4)
    ("l_num"
     down   ?\+    ?\*    ?\!    ---        x      ---    ---    rpt    ?\.
     6      4      0      2      up         ---    3      1      5      7
     ?\,    ?\.    ---    8      ---        ?\/    9      ?\(    ?\)    ?\_
     to_1   ent                                                  llck  to4)
    ("l_wnav"
     down   wbak   G-f    -x-    -x-        -x-    -x-    -x-    wfwd   -x-
     G-6    G-4    G-0    G-2    G-up       -x-    G-3    G-1    G-5    G-7
     -x-    -x-    -x-    G-8    -x-        -x-    G-9    G-n    G-e    -x-
     to_1   ent                                                  llck   -x-)
    ("l_num"
     ?\\    ?\`    ?\#    ?\:    ?\;        ?\=    7      8      9      ?\+
     esc    ?\'    ?\{    ?\(    ?\[        ?\*    4      5      6      ?\-
     mlsft  ?\.    ?\}    ?\)    ?\]        0      1      2      3      ---
     to_1   ent                                                  llck   to4)
    ("l_sym"
     ?\\    ?\`    ?\#    ?\:    ?\;        ?\=    7      8      9      ?\+
     esc    ?\'    ?\{    ?\(    ?\[        ?\*    4      5      6      ?\-
     mlsft  ?\.    ?\}    ?\)    ?\]        0      1      2      3      ---
     to_1   ent                                                  llck   to4)
    ("l_media"
     -x-    wh_d   ms_u   -x-    brid       briu   -x-    -x-    wh_u   -x-
     esc    ms_l   ms_d   ms_r   -x-        -x-    mprv   mply   mnxt   mute
     -x-    wh_l   -x-    -x-    vold       volu   btn1   btn2   wh_r   f20
     to_1   ---                                                  llck   to_5)
    ("l_func"
     -x-    -x-    -x-    -x-    -x-        f10    f7     f8     f9     -x-
     -x-    malt   mgui   mctl   -x-        f11    f4     f5     f6     del
     td_r   -x-    -x-    -x-    -x-        f12    f1     f2     f3     -x-
     to_1   -x-                                                  llck   to_2)
    ("l_emacs"
     C_g    -x-    -x-    ---    -x-        ---    -x-    ---    ---    rpt
     tab    -x-    CM_r   CM_t   ---        CM_spc CM_f   CM_b   CMG_u  ent
     CM_a   ---    M_mi   CM_k   ---        CM_u   CM_d   CM_lt  CM_gt  CM_e
     to_1   ---                                                  llck   to_2)))

;; * HD Gold
(defvar hd-gold-combo-keys
  '(((n mod_sp) ent)
    ((mod_t oslmod) esc)
    ((h mod_sp) bspc)
    ((i mod_sp) n_tab)
    ((y mod_sp) wfwd)
    ((r oslmod) p_tab)
    ((w oslmod) wbak)
    ((d v) esc)
    ((t g) tab)
    ((m n) ent)
    ((s e) (RAW "CW_TOGG"))
    ((n t) (RAW "NUMWORD"))
    ((k h) bspc)
    ((mod_sp mod_t) lmedia)))
;; ** combos
(defvar hd-gold-combo-keys
  '(
    ;; gold
    ((e n) (RAW "CW_TOGG"))
    ((d a) (RAW "NUMWORD"))
    ((j g) z)
    ((k u) linq)
    ;; ((s n) "sh")
    ;; ((n d) "th")
    ;; ((l c) "ch")
    ;; ((h i) "wh")
    ;; ((g m) "gh")
    ;; ((m p) "ph")
    ))

;; ** defined keys
(defvar hd-gold-user-defined-keys
  '((lbase (TO "l_base"))
    (lsym (TO "l_sym"))
    (lnum (TO "l_sym"))
    (lmod (TO "l_mods"))
    (lmedia (TO "l_media"))
    (lfunc (TO "l_func"))
    (lemacs (TO "l_emacs"))
    (lnav (TO "l_nav"))
    (lwnav (TO "l_wnav"))
    (oslsym (OSL "l_sym"))
    (oswnav (OSL "l_wnav"))
    (osmedia (OSL "l_media"))
    (mod_sp (LT "l_mods" spc))
    ;; custom tap-holds
    (navsft (RAW "NAV_SFT"))
    (medsft (RAW "MED_SFT"))
    (navrpt (RAW "NAV_RPT"))
    (medrpt (RAW "MED_RPT"))
    (navrev (RAW "NAV_REV"))
    (symrpt (RAW "SYM_RPT"))
    (numrpt (RAW "NUM_RPT"))
    (symrev (RAW "SYM_REV"))
    (modnum (RAW "MOD_NUM"))
    (nummod (RAW "NUM_MOD"))
    (oslmod (RAW "OS_MODS"))
    (mod_t (RAW "MOD_T"))
    ;; Swapper
    (swapkey (RAW "SWAPKEY"))
    ;; Repeat
    (rpt (RAW "REPEAT"))
    ;; emacs
    ;; (CM_?\% C-M-?\%)
    ;; (CM_?\, C-M-?\,)
    ;; (CM_?\- C-M-?\-)
    ;; (CM_?\. C-M-?\.)
    ;; (CM_?\/ C-M-?\/)
    ;; (CM_c C-M-c)
    ;; (CM_?\\ C-M-?\\)
    ;; (CM_?\_ C-M-?\_)
    ;; (CM_D C-M-S-d)
    ;; (CM_F C-M-S-f)
    ;; (CM_h C-M-h)
    ;; (CM_j C-M-j)
    ;; (CM_l C-M-l)
    ;; (CM_n C-M-n)
    ;; (CM_o C-M-o)
    ;; (CM_p C-M-p)
    ;; (CM_v C-M-v)
    ;; (CM_w C-M-w)
    (M_lt M-left_angle)
    (M_gt M-right_angle)
    (M_exc M-exclaim)
    (M_per M-percent)
    (M_amp M-ampersand)
    (M_mi M-mins)
    (CM_a C-M-a)
    (CM_b C-M-b)
    (CM_d C-M-d)
    (CM_e C-M-e)
    (CM_f C-M-f)
    (C_g C-g)
    (CM_k C-M-k)
    (CM_r C-M-r)
    (CM_t C-M-t)
    (CM_u C-M-u)
    (CMG_u C-M-G-u)
    (CM_lt C-left_angle)
    (CM_gt C-right_angle)
    (CM_spc (C-M-spc))
    ;; wnav
    (G_dot G-dot)
    (G_t (G t))
    (G_n (G n))
    (G_e (G e))
    (G-0 (RAW "G(KC_0)"))
    (G-1 (RAW "G(KC_1)"))
    (G-2 (RAW "G(KC_2)"))
    (G-3 (RAW "G(KC_3)"))
    (G-4 (RAW "G(KC_4)"))
    (G-5 (RAW "G(KC_5)"))
    (G-6 (RAW "G(KC_6)"))
    (G-7 (RAW "G(KC_7)"))
    (G-8 (RAW "G(KC_8)"))
    (G-9 (RAW "G(KC_9)"))
    (n_tab C-tab)
    (p_tab C-S-tab)
    (mlsft (OSM S))
    (mrsft (OSM S))
    (malt (OSM M))
    (mctl (OSM C))
    (mgui (OSM G))
    (lcbr (RAW "LINCBR"))
    (lprn (RAW "LINPRN"))
    (lbrc (RAW "LINBRC"))
    (llck (RAW "LLOCK" ) )
    (compar (RAW "COMPAR"))
    (dotmin (RAW "DOTMIN"))
    (slsexc (RAW "SLSEXC"))
    (myrst (RAW "MYRESET"))))

;; ** keymap
(defvar hd-gold-keymap
  '(("l_base" ;; hd-gold
     j      g      m      p      v          ?\;    ?\.    ?\/    ?\"    ?\'
     r      s      n      d      b          ?\,    a      e      i      h
     x      f      l      c      w          ?\-    u      o      y      k
     navsft mod_t                                                mod_sp symrpt)
    ("l_sym"
     -x-    M_lt   ?\#    ?\:    ?\;           ?\=    ?\^    -x-    M_gt   -x-
     ?\\    ?\'    lcbr   lprn   lbrc          ?\*    mctl   M_exc  M_per  M_amp
     -x-    -x-    esc    ent    -x-           -x-    -x-    ---    ---    ---
     lbase  ---                                                     -x-)    ---
    ("l_num"
     down   ?\+    ?\*    ?\*    -x-           -x-    ?\#    ?\!    ?\%    ?\&
     6      4      0      2      up            -x-    3      1      5      7
     x      ?\.    ?\$    8      -x-           ?\/    9      ?\(    ?\)    ?\_
     lbase  ---                                                      ---    ---)
    ("l_mods"
     -x-    -x-    -x-    -x-    -x-           -x-    -x-    -x-    -x-    -x-
     -x-    malt   mgui   mctl   mlsft         mlsft  mctl   mgui   malt   -x-
     undo   cut    copy   paste  -x-           -x-    bspc   tab    del    lemacs
     lbase  ---                                                     ent    swapkey)
    ("l_nav"
     -x-    wbak   ms_u   p_tab  -x-           -x-    n_tab  -x-    wfwd   -x-
     -x-    ms_l   ms_d   ms_r   -x-           left   down   up     right  -x-
     -x-    wh_l   wh_u   wh_d   wh_r          -x-    ent    esc    G_dot  osmedia
     lbase  ---                                                     llck   oswnav)
    ;; ("l_num"
    ;;  ?\\    ?\`    ?\#    ?\:    ?\;           ?\=    7      8      9      ?\+
    ;;  esc    ?\'    ?\{    ?\(    ?\[           ?\*    4      5      6      ?\-
    ;;  mlsft  ?\.    ?\}    ?\)    ?\]           0      1      2      3      ---
    ;;  to_1   ent                                                     nav    to4)
    ("l_wnav"
     down   wbak   G-f    -x-    -x-           -x-    -x-    -x-    wfwd   -x-
     G-6    G-4    G-0    G-2    G-up          -x-    G-3    G-1    G-5    G-7
     -x-    -x-    -x-    G-8    -x-           -x-    G-9    G-n    G-e    -x-
     lbase  ---                                                     ---    rpt)
    ("l_media"
     -x-    -x-    -x-    -x-    brid          briu   -x-    -x-    -x-    -x-
     -x-    -x-    -x-    -x-    -x-           mute   mprv   mply   mnxt   -x-
     -x-    -x-    -x-    -x-    vold          volu   btn1   btn2   wh_r   f20
     lbase  ---                                                     ent    lfunc)
    ("l_func"
     -x-    -x-    -x-    -x-    -x-        -x-    -x-    -x-    -x-    -x-
     f6     f4     -x-    f2     -x-           -x-    f3     f1     f5     f7
     -x-    f12    f10    f8     -x-           -x-    f9     f11    -x-    -x-
     lbase  ---                                                     -x-    myrst)
    ("l_emacs"
     C_g    -x-    -x-    -x-    -x-        -x-    -x-    -x-    -x-    rpt
     tab    -x-    CM_r   CM_t   -x-        CM_spc CM_f   CM_b   CMG_u  ent
     CM_a   -x-    M_mi   CM_k   -x-        CM_u   CM_d   CM_lt  CM_gt  CM_e
     lbase   -x-                                                  llck   -x-)))



;; * Mugur

(let* (
       ;; (base "hd-gold") ;; hd-gold, colemak
       (base "colemak") ;; hd-gold, colemak
       (keymap (intern (format "%s-keymap" base)))
       (mugur-enum-layers nil)
       (mugur-enum-tapdances nil)
       (mugur-keymap-file-name "eqmk.c")
       (mugur-qmk-path "~/qmk/qmk_firmware/")
       (mugur-user-space-path "~/qmk/qmk_firmware/users/tpeacock19/")
       ;; (mugur-combos-file (expand-file-name "combos.def" mugur-user-space-path))
       (mugur-keyboard-name "ferris")
       (mugur-layout-name "LAYOUT")
       (mugur-keymap-name "tpeacock19")
       (mugur-tapping-term 180)
       (mugur-combo-term nil)
       (mugur-combo-progmem t)
       (mugur-leader-timeout 200)
       (mugur-leader-per-key-timing nil)
       (mugur-user-defined-keys
        (symbol-value (intern (format "%s-user-defined-keys" base))))
       (mugur-combo-keys
        (symbol-value (intern (format "%s-combo-keys" base)))))
  (org-babel-tangle-file (format "%s.org" base))
  (mugur-mugur (symbol-value keymap)))


(provide 'qmk-keymap)
;;; qmk-keymap.el
