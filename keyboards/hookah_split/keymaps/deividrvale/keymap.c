/* Copyright 2020 Deivid Vale
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
#include "keymap_br_abnt2.h"

enum layer {
    _QWERTY = 0,
    _SYMB,
    _NUM,
    _NAV,
    _FUNCTION,
};

// Left and right Control.
#define CTESC MT(MOD_LCTL, KC_ESC)
#define CTILD MT(MOD_RCTL, BR_TILD)

// Left and right Shift.
#define LSFBS LSFT_T(BR_BSLS)
#define RSFSL RSFT_T(BR_SLSH)

// Alpha keys that change layer.
#define N_QUOT LT(_NAV, BR_QUOT)

// Thumb keys that change layers.
#define S_BSPC LT(_SYMB, KC_BSPC)
#define S_TAB  LT(_SYMB, KC_TAB)
#define FN_ENT LT(_FUNCTION, KC_ENT)
#define FN_SPC LT(_FUNCTION, KC_SPC)
#define NV_ENT LT(_NAV, KC_ENT)

// Mod keys modifiers.
#define A_ALT ALT_T(KC_A)
#define CD_ALT ALT_T(BR_CCED)
#define NUM_TAB LT(_NUM, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        N_QUOT,  KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                                    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BR_ACUT,
        CTESC,   A_ALT,    KC_S,     KC_D,     KC_F,    KC_G,                                    KC_H,     KC_J,     KC_K,     KC_L,     CD_ALT,   CTILD,
        LSFBS,   KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,                                    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFSL,
                                     NV_ENT,   S_TAB,   NUM_TAB,                                 KC_DEL,   S_BSPC,   FN_SPC
    ),

    [_SYMB] = LAYOUT(
      KC_TAB,  KC_EXLM, KC_AT,   BR_LCBR, BR_RCBR, BR_DIAE,                                     _______,  _______,  _______,  _______,  BR_EQL,   BR_LBRC,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS,  KC_MINS,  BR_UNDS,  KC_ASTR,  KC_PERC,  BR_RBRC,
      _______, KC_PERC, KC_CIRC, BR_LBRC, BR_RBRC, KC_TILD,                                     KC_AMPR,  KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 KC_ENT,  KC_TAB,  KC_TAB,                                      KC_DEL,   S_BSPC,  KC_SPC
    ),

    [_NUM] = LAYOUT(
       KC_TAB, _______, _______, _______, _______, _______,                                     KC_PLUS, KC_7, KC_8, KC_9, KC_EQL, KC_MINS,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_4, KC_5, KC_6, KC_DOT, KC_ASTR,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_1, KC_2, KC_3, _______,KC_SLSH,
                                 _______, _______, _______,                                     _______, _______, KC_0
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_CAPSLOCK, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT,     KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_INSERT,   _______, _______, _______, _______, _______,
                                 _______, _______, _______,                                     KC_DEL, KC_BSPC, KC_SPC
    ),

    [_FUNCTION] = LAYOUT(
            _______,   _______,   _______,    _______,    _______,     _______,                                    KC_INSERT, KC_F9,  KC_F10,  KC_F11,    KC_F12, KC_PSCR,
            _______,   _______,   _______,    _______,    _______,     _______,                                    _______,   KC_F5,  KC_F6,   KC_F7,     KC_F8,  KC_SCROLLLOCK,
            _______,   _______,   _______,    _______,    _______,     _______,                                    _______,   KC_F1,  KC_F2,   KC_F3,     KC_F4,  KC_PAUSE,
                                              _______,    _______,     _______,                                    KC_DEL,    KC_BSPC,   KC_SPC
    ),

};

// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
