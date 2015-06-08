/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

#define SHIFT(key) ACTION(ACT_MODS, (MOD_LSFT << 8) | (key))
#define CTRL(key) ACTION(ACT_MODS, (MOD_LCTL << 8) | (key))
#define ALT(key) ACTION(ACT_MODS, (MOD_LALT << 8) | (key))
#define GUI(key) ACTION(ACT_MODS, (MOD_LGUI << 8) | (key))
#define PANE(key) ACTION_MODS_KEY(MOD_LGUI | MOD_LALT | MOD_LCTL, (key))

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


#define KEYMAP( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
) {                                                                     \
  { K00, K01, K02, K03, K04, KC_NO, K05, K06, K07, K08, K09 }, \
  { K10, K11, K12, K13, K14, KC_NO, K15, K16, K17, K18, K19 }, \
  { K20, K21, K22, K23, K24, K35,   K25, K26, K27, K28, K29 }, \
  { K2A, K30, K31, K32, K33, K34,   K36, K37, K38, K39, K3A }      \
}

#define FN_LAYER   KEYMAP(SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_BSLS), \
                          SHIFT(CTRL(KC_UP)), KC_7, KC_8, KC_9, SHIFT(KC_8),       \
                          SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9), SHIFT(KC_0), KC_GRAVE, \
                          SHIFT(CTRL(KC_DOWN)), KC_4, KC_5, KC_6, SHIFT(KC_EQUAL),   \
                          SHIFT(KC_5), SHIFT(KC_6), KC_LBRC, KC_RBRC, SHIFT(KC_GRAVE), \
                          SHIFT(KC_7), KC_1, KC_2, KC_3, KC_BSLS,       \
                          KC_FN1, SHIFT(KC_INS), KC_LALT, KC_LSFT, KC_BSPC, KC_LGUI, KC_FN4, \
                          KC_SPC, KC_FN0, KC_DOT, KC_0, KC_EQUAL)

#define LAYER_TWO KEYMAP(KC_HOME, KC_UP, KC_END, KC_PGUP, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
                         KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
                         KC_NO, KC_NO, KC_LALT, KC_LSFT, KC_BSPC, KC_LGUI, KC_FN4, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_FN3)

#define MEDIA_LAYER KEYMAP(KC_SLEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, \
                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, \
                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
                           KC_FN6, KC_FN5, KC_LALT, KC_LSFT, KC_BSPC, KC_LGUI, KC_FN4, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_NO)

#define PANE_LAYER KEYMAP(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, \
                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, \
                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, PANE(KC_LEFT), PANE(KC_DOWN), PANE(KC_UP), PANE(KC_RIGHT), KC_NO, \
                          KC_FN6, KC_FN5, KC_LALT, KC_LSFT, KC_BSPC, KC_LGUI, KC_FN4, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_NO)

enum function_id {
  BOOTLOADER,
};

void bootloader(void);

#endif
