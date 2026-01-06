#include "action_layer.h"
#include "pointing_device_auto_mouse.h"
#include "quantum_keycodes.h"
#include "quantum_keycodes_legacy.h"
#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  DRAG_SCROLL,
  TOGGLE_SCROLL,
  NAVI_INC_CPI,
  NAVI_DEC_CPI,
  NAVI_TURBO,
  NAVI_AIM
};



enum tap_dance_codes {
  DANCE_0,
};

#define _BASE_LAYER 0
#define _GAME_LAYER 1
#define _MOUSE_LAYER 5
#define _MLT(key) LT(_MOUSE_LAYER, key)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_LAYER] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,               KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_ESC,         LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,               KC_H,           RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),KC_QUOTE,
    KC_GRAVE,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,               KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       MO(3),
                                                                    LT(2, KC_BSPC), LT(4, KC_TAB),      _MLT(KC_ENTER), KC_SPACE
  ),
  // Gaming Layer - Turns off HRMods on left half.
  [_GAME_LAYER] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,               KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,               KC_MS_BTN1,     KC_MS_BTN2,     RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),KC_QUOTE,
    KC_GRAVE,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,               KC_MS_BTN4,     KC_MS_BTN5,     KC_COMMA,       KC_DOT,         KC_SLASH,       MO(3),
                                                                    KC_BSPC,        KC_SPACE,           KC_MS_BTN3,     LT(2, KC_SPACE)
  ),
  [2] = LAYOUT_voyager(
    DF(_BASE_LAYER),_______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        KC_LPRN,        KC_RPRN,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        KC_LABK,        KC_RABK,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        KC_LCBR,        KC_RCBR,        _______,
    DF(_GAME_LAYER),_______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        KC_LBRC,        KC_RBRC,        _______,
                                                                    _______,        _______,            _______,        _______
  ),
  [3] = LAYOUT_voyager(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,              KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_PSCR,
    _______,        KC_F11,         KC_F12,         KC_F13,         KC_F14,         _______,            _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,            _______,        _______
  ),
  [4] = LAYOUT_voyager(
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,            _______,        _______
  ),
  // Mouse Layer
  [_MOUSE_LAYER] = LAYOUT_voyager(
    NAVI_DEC_CPI,   NAVI_INC_CPI,   _______,        _______,        _______,        QK_LLCK,            _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        KC_MS_BTN3,     TOGGLE_SCROLL,      KC_MS_BTN3,     _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        KC_MS_BTN2,     KC_MS_BTN1,     DRAG_SCROLL,        KC_MS_BTN1,     KC_MS_BTN2,     _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,            _______,        _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,            _______,        _______

  ),
};

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t *record) {
    // Treat all keys as mouse keys when in the automouse layer so that any key set resets the timeout without leaving the layer.
    if (!layer_state_is(AUTO_MOUSE_TARGET_LAYER)) {
        // When depressing a mouse key with a LT key at the same time, the mouse key tracker is not decremented.
        // This is a workaround to fix that
        if (IS_MOUSE_KEYCODE(keycode) && !record->event.pressed) {
            return true;
        }
        return false;
    } else {
        return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MODS ... QK_MODS_MAX:
            // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
            // applied to the mouse key that was pressed.
            if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
                if (record->event.pressed) {
                    add_mods(QK_MODS_GET_MODS(keycode));
                    send_keyboard_report();
                    wait_ms(2);
                    register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
                    return false;
                } else {
                    wait_ms(2);
                    del_mods(QK_MODS_GET_MODS(keycode));
                }
            }
            break;

        case DRAG_SCROLL:
            if (record->event.pressed) {
                set_scrolling = true;
            } else {
                set_scrolling = false;
            }
            return false;
        case TOGGLE_SCROLL:
            if (record->event.pressed) {
                set_scrolling = !set_scrolling;
            }
            return false;
            break;
        case NAVI_TURBO:
            if (record->event.pressed) {
                navigator_turbo = true;
            } else {
                navigator_turbo = false;
            }
            return false;
        case NAVI_AIM:
            if (record->event.pressed) {
                navigator_aim = true;
            } else {
                navigator_aim = false;
            }
            return false;
        case NAVI_INC_CPI:
            if (record->event.pressed) {
                pointing_device_set_cpi(1);
            }
            return false;
        case NAVI_DEC_CPI:
            if (record->event.pressed) {
                pointing_device_set_cpi(0);
            }
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case DF(_GAME_LAYER):
            layer_off(get_auto_mouse_layer());
            set_auto_mouse_enable(false);
            return true;
        case DF(_BASE_LAYER):
            set_auto_mouse_enable(true);
            return true;
    }
    return true;
}
