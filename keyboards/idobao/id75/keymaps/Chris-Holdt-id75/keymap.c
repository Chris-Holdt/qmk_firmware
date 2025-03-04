/* Copyright 2018 MechMerlin
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

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {};

// Define combos
const uint16_t PROGMEM alt_combo[] = {KC_A, KC_D, COMBO_END};
const uint16_t PROGMEM change_workspace_combo[] = {KC_F, KC_J, COMBO_END};
// END Combos

combo_t key_combos[] = {
    COMBO(alt_combo, KC_LALT),
    COMBO(change_workspace_combo, OSL(5))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_ortho_5x15( // Default layer
    KC_ESC,         KC_1,    KC_2,    KC_3,           KC_4,     KC_5,    KC_PGUP,               TO(1),   KC_PGDN, KC_6,           KC_7,           KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,         KC_Q,    KC_W,    KC_E,           KC_R,     KC_T,    KC_7,                  KC_8,    KC_9,    KC_Y,           KC_U,           KC_I,    KC_O,    KC_P,    KC_END,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,           KC_F,     KC_G,    KC_4,                  KC_5,    KC_6,    KC_H,           KC_J,           KC_K,    KC_L,    KC_SCLN, LT(4, KC_NUBS),
    KC_LSFT,        KC_Z,    KC_X,    KC_C,           KC_V,     KC_B,    KC_1,                  KC_2,    KC_3,    KC_N,           KC_M,           KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    KC_LCTL,        KC_LGUI, KC_LALT, LT(3, KC_GRV),  OSL(1),   KC_SPC,  MT(MOD_LGUI, KC_TAB),  KC_0,    KC_DEL,  SFT_T(KC_BSPC), LT(2, KC_ENT),  KC_LGUI, KC_DOWN, KC_UP,   KC_RGHT
  ),
 [1] = LAYOUT_ortho_5x15(// Numpad, shifted keys ( (), {}, [], <>, FN Keys, screen switching )
    KC_TRNS, KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_TRNS, TO(2),   KC_TRNS, KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11,
    KC_TRNS, KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_E), LGUI(KC_W), LGUI(KC_R), KC_TRNS, KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_LPRN,    KC_LCBR,    KC_LBRC,    KC_TRNS, KC_TRNS, KC_TRNS, KC_RBRC, KC_RCBR,    KC_RPRN,    KC_NUHS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_GRV,     KC_MINS,    KC_UNDS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,  KC_PLUS,    KC_LT,      KC_GT,      KC_PGUP, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,    TO(0),      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PGDN, KC_TRNS
 ),
 [2] = LAYOUT_ortho_5x15(// HJKL as arrow keys like VIM, and quick access to symbols
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, TO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS,
    KC_TRNS, KC_EXLM, S(KC_2), S(KC_3), KC_DLR,   KC_PERC, KC_TRNS, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, TO(0),   TO(1),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
 [3] = LAYOUT_ortho_5x15( // F Keys
    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,   RGB_RMOD, KC_TRNS, RGB_MOD,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_F13,  KC_F14,  KC_F15,  KC_F16,   KC_F17,   KC_F18,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, TO(0),    TO(2),    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
 [4] = LAYOUT_ortho_5x15(// Media, bootmode and sleep
    QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_SLEP, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_MUTE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
 ),
 [5] = LAYOUT_ortho_5x15(// Workspace switching
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),  LGUI(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
 ),
};

