/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PAREN,
  BRACK,
  ANGLE,
  SQUAR,
  DOT,
  VSCODE,
  TERM,
  CHROME,
  REDDIT,
  GOOGLE,
  YOUTUBE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | GUI  |  Alt |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | PgUp | Home |  Up  | End  | Cut  | Find |  ^   | -/_  | [/]  |  $   |  !   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |PgDown| Left | Down |Right | Copy |Paste |  *   | =/+  | (/)  | {/}  |  |   |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |SLeft |C.Row |SRight|      |  @   |  %   |  #   | </>  | ./,  |  &   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |ALeft | Spot |Finder|ARight|
 * `-------------------------------------------------------- ---------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_PGUP,   KC_HOME,       KC_UP,   KC_END ,        G(KC_X), G(KC_F),  S(KC_6), KC_MINS, SQUAR,     S(KC_4),     S(KC_1),        KC_DEL,
    KC_PGDOWN, KC_LEFT,       KC_DOWN, KC_RGHT,        G(KC_C), G(KC_V),  S(KC_8), KC_EQL,  PAREN,     BRACK,       S(KC_BSLS),     KC_GRAVE,
    _______,   SGUI(KC_LEFT), G(KC_D), SGUI(KC_RIGHT), _______, S(KC_1),  S(KC_5), S(KC_3),  ANGLE,     DOT,         S(KC_7),        _______,
    _______,   _______,       _______, _______,        _______, _______,  _______, _______, G(KC_TAB), G(KC_SPACE), G(A(KC_SPACE)), SGUI(KC_TAB)
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | UTab |TLeft |NewTab|TRight|VSCode|Reddit| All  |Save  |   1  |   2  |   3  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CloseT|Tools |Reload| Term |Google| Redo | Undo |   4  |   5  |   6  |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CloseW|NewWin|Chrome|      |UTube |      |      |   7  |   8  |   9  |  .   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |DLeft | DUp  |DDown |DRight|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    S(KC_TAB), C(S(KC_TAB)), G(KC_T),    C(KC_TAB), VSCODE,  REDDIT,  G(KC_A),    G(KC_S), KC_1,          KC_2,        KC_3,           KC_DEL,
    _______,   G(KC_W),      G(A(KC_I)), G(KC_R),   TERM,    GOOGLE,  SGUI(KC_Z), G(KC_Z), KC_4,          KC_5,        KC_6,           KC_0,
    _______,   G(S(KC_W)),   G(KC_N),    CHROME,    _______, YOUTUBE, _______,    _______, KC_7,          KC_8,        KC_9,           KC_DOT,
    _______,   _______,      _______,    _______,   _______, _______, _______,    _______, LCTL(KC_LEFT), LCTL(KC_UP), LCTL(KC_DOWN),  LCTL(KC_RIGHT)
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void open_app(char app[]){
  register_code(KC_LGUI);
  register_code(KC_SPACE);
  clear_keyboard();
  SEND_STRING(app);
  register_code(KC_ENTER);
  clear_keyboard();
}

void open_site(char site[]){
  register_code(KC_LGUI);
  register_code(KC_SPACE);
  clear_keyboard();
  SEND_STRING("Google Chrome");
  register_code(KC_ENTER);
  clear_keyboard();
  register_code(KC_LGUI);
  register_code(KC_T);
  clear_keyboard();
  register_code(KC_LGUI);
  register_code(KC_L);
  clear_keyboard();
  SEND_STRING(site);
  register_code(KC_ENTER);
  clear_keyboard();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PAREN:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
          clear_mods();
          register_code(KC_LSFT);
          register_code(KC_0);
        } else {
          register_code(KC_LSFT);
          register_code(KC_9);
        }
        clear_keyboard();
      }
      return false;
      break;
    case BRACK:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
          clear_mods();
          register_code(KC_LSFT);
          register_code(KC_RBRACKET);
        } else {
          register_code(KC_LSFT);
          register_code(KC_LBRACKET);
        }
        clear_keyboard();
      }
      return false;
      break;
    case ANGLE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
          clear_mods();
          register_code(KC_LSFT);
          register_code(KC_DOT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_COMMA);
        }
        clear_keyboard();
      }
      return false;
      break;
    case SQUAR:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
          clear_mods();
          register_code(KC_RBRACKET);
        } else {
          register_code(KC_LBRACKET);
        }
        clear_keyboard();
      }
      return false;
      break;
    case DOT:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
          clear_mods();
          register_code(KC_DOT);
        } else {
          register_code(KC_COMMA);
        }
        clear_keyboard();
      }
      return false;
      break;
    case VSCODE:
      if (record->event.pressed) {
        open_app("Visual Studio Code");
      }
      return false;
      break;
    case TERM:
      if (record->event.pressed) {
        open_app("Terminal");
      }
      return false;
      break;
    case CHROME:
      if (record->event.pressed) {
        open_app("Google Chrome");
      }
      return false;
      break;
    case REDDIT:
      if (record->event.pressed) {
        open_site("https://www.reddit.com/");
      }
      return false;
      break;
    case GOOGLE:
      if (record->event.pressed) {
        open_site("https://www.google.com/");
      }
      return false;
      break;
    case YOUTUBE:
      if (record->event.pressed) {
        open_site("https://www.youtube.com/");
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}