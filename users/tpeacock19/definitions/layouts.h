#pragma once
/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#include "quantum.h"
// readability
#define ___ KC_NO

/* #define LAYOUT_tp_ferris( \ */
/*         L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \ */
/*         L06, L07, L08, L09, L10, R06, R07, R08, R09, R10, \ */
/*         L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \ */
/*                   L16, L17, R16, R17       \ */
/*     ) \ */
/*     { \ */
/*         { L01, L02, L03, L04, L05 }, \ */
/*         { L06, L07, L08, L09, L10 }, \ */
/*         { L11, L12, L13, L14, L15 }, \ */
/*         { L16, L17, ___, ___ , ___}, \ */
/*         { R01, R02, R03, R04, R05 }, \ */
/*         { R06, R07, R08, R09, R10 }, \ */
/*         { R11, R12, R13, R14, R15 }, \ */
/*         { R16, R17, ___, ___, ___ }  \ */
/*     } */

/* #define LAYOUT LAYOUT_tp_ferris */

// clang-format off
#define LAYOUT_tp_ferris( \
        L00   ,L02   ,L03   ,L04   ,L05        ,R01   ,R02   ,R03   ,R04   ,R05   , \
        L06   ,L07   ,L08   ,L09   ,L10        ,R06   ,R07   ,R08   ,R09   ,R10   , \
        L11   ,L12   ,L13   ,L14   ,L15        ,R11   ,R12   ,R13   ,R14   ,R15   , \
                             L30   ,L17        ,R16   ,R17                          \
    ) \
    LAYOUT( \
        L00   ,L02   ,L03   ,L04   ,L05        ,R01   ,R02   ,R03   ,R04   ,R05   , \
        L06   ,L07   ,L08   ,L09   ,L10        ,R06   ,R07   ,R08   ,R09   ,R10   , \
        L11   ,L12   ,L13   ,L14   ,L15        ,R11   ,R12   ,R13   ,R14   ,R15   , \
                             L30   ,L17        ,R16   ,R17                          \
    )
// clang-format on
/* LAYOUT */
/* #define LAYOUT LAYOUT_tp_ferris */
