/* Copyright 2015-2017 Mario Traina
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum vcore_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum vcore_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};

#define _____ KC_TRNS
#define __x__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,---------------------------------------------------------------------------------------------.
 * |   Esc   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  `  | Bksp  |
 * |---------------------------------------------------------------------------------------------|
 * |   Tab   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;   |   '        |
 * |---------------------------------------------------------------------------------------------|
 * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |    \      |
 * |---------------------------------------------------------------------------------------------|
 * |   Ctrl |  optn |  cmd  | Lower |  Space   |  Enter   |  Raise  |  down | left  |   right    |
 * `---------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TILD, KC_BSPC,
  KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_DOWN, KC_LEFT, KC_RGHT
),

/* Lower
 * ,---------------------------------------------------------------------------------------------.
 * |   `     |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |   =  |  (   |  )   |
 * |---------------------------------------------------------------------------------------------|
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | lft  | down |  up  | rght |   {   |     }      |
 * |---------------------------------------------------------------------------------------------|
 * |           |  F6  |  F7  |  F8  |  F9  | F10  |   F11  | F12  |       |        |   [  | ]    |
 * |---------------------------------------------------------------------------------------------|
 * |        |       |       |       |          |    0     |         |        |       |           |
 * `---------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, KC_LPRN, KC_RPRN,
  _____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_LCBR, KC_RCBR,
  _____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _____, _____, KC_LBRC, KC_RBRC,
  _____, _____, _____, _____, _____, KC_0, _____, _____, _____, _____
),

/* Raise
 * ,---------------------------------------------------------------------------------------------.
 * |   `     |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Home | End  |
 * |---------------------------------------------------------------------------------------------|
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6   |   4  |   5  |   6  |      |            |
 * |---------------------------------------------------------------------------------------------|
 * |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |      |           |
 * |---------------------------------------------------------------------------------------------|
 * |        |       |       |       |          |     0    |         |        |       |           |
 * `---------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_HOME, KC_END,
  _____, _____, _____, _____, _____, _____, _____, KC_4, KC_5, KC_6, _____, _____,
  _____, _____, _____, _____, _____, _____, _____, KC_1, KC_2, KC_3, _____, _____,
  _____, _____, _____, _____, _____, KC_0, _____, _____, _____, _____
),

/* Adjust (Lower - Raise)
 * ,---------------------------------------------------------------------------------------------.
 * | Qwerty  |      |      |      |      |      |      |      |      |      |      |      |      |
 * |---------------------------------------------------------------------------------------------|
 * |          |      |      |      |      |      |      |      |      |      |      |            |
 * |---------------------------------------------------------------------------------------------|
 * |           |      |      |      |      |     |       |      |      |      |      |           |
 * |---------------------------------------------------------------------------------------------|
 * |        |       |       |       |          |          |         |        |        |  Reset   |
 * `---------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
  QWERTY,__x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, _____,
  _____, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, _____,
  _____, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, __x__, _____,
  _____, _____, _____, _____, _____, _____, _____, _____, _____, RESET
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
