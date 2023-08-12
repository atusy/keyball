/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    _______, KC_PSCR, LT(3,KC_TAB), KC_BTN1, KC_BTN2       , KC_BTN3       ,                                 _______       , _______, _______, _______, _______, _______,
    KC_LBRC, KC_Q   , KC_W        , KC_E   , KC_R          , KC_T          ,                                 KC_Y          , KC_U   , KC_I   , KC_O   , KC_P   , KC_RBRC,
    KC_GRV , KC_A   , KC_S        , KC_D   , KC_F          , KC_G          ,                                 KC_H          , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_EQL , KC_Z   , KC_X        , KC_C   , KC_V          , KC_B          , KC_ESC       ,    KC_BSPC     , KC_N          , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_MINS,
    _______, _______, KC_MENU     , KC_LWIN, LALT_T(KC_ENT), LSFT_T(KC_SPC), LT(3,KC_BSLS),    LT(1,KC_TAB), LCTL_T(KC_ENT), _______, _______, _______, KC_BTN1, TT(3)
  ),

  [1] = LAYOUT_universal(
    _______, KC_F1     , KC_F2     , KC_F3        , KC_F4        , KC_F5        ,                               KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11 ,
    _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3)   , LSFT(KC_4)   , LSFT(KC_5)   ,                               LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_F12 ,
    _______, KC_1      , KC_2      , KC_3         , KC_4         , KC_5         ,                               KC_6      , KC_7      , KC_8      , KC_9      , KC_0      , _______,
    _______, KC_LBRC   , KC_RBRC   , LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS), _______,             _______, _______   , _______   , _______   , _______   , _______   , _______,
    _______, _______   , _______   , _______      , _______      , _______      , _______,             _______, _______   , _______   , _______   , _______   , _______   , _______
  ),

  [2] = LAYOUT_universal(
    _______, _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______, _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______, _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______, _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______, _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    CPI_D100, CPI_I100  , _______   , KC_BTN1   , KC_BTN2   , KC_BTN3   ,                              _______   , _______   , _______   , _______   , _______   , _______,
    SCRL_DVI, LWIN(KC_1), LWIN(KC_2), LWIN(KC_3), LWIN(KC_4), LWIN(KC_5),                              LWIN(KC_6), LWIN(KC_7), LWIN(KC_8), LWIN(KC_9), LWIN(KC_0), _______,
    SCRL_DVD, _______   , _______   , _______   , _______   , _______   ,                              KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , _______   , _______,
    _______ , _______   , _______   , _______   , _______   , _______   , _______,            KC_DEL , KC_HOME   , KC_PGDN   , KC_PGUP   , KC_END    , KC_BTN3   , _______,
    _______ , _______   , _______   , _______   , _______   , _______   , _______,            _______, _______   , _______   , _______   , _______   , KC_BTN2   , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
