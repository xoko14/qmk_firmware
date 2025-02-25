/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "keycodes.h"
#include "badapple.h"

#define parse_uint32(bytes, index) bytes[index+0] + (bytes[index+1] << 8) + (bytes[index+2] << 16) + (bytes[index+3] << 24)
#define parse_uint16(bytes, index) bytes[index+0] + (bytes[index+1] << 8)

enum layers{
    _QWERT,
    _UPPER,
    _LOWER,
    _ADJUST,
    _TILDE
};

enum unicode_names{
    AACUTE,
    EACUTE,
    IACUTE,
    OACUTE,
    UACUTE,
    NTILDE,
    AACUTEC,
    EACUTEC,
    IACUTEC,
    OACUTEC,
    UACUTEC,
    NTILDEC,
};

enum custom_keymaps{
    SX_PSC = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  LT(4,KC_SPC),     KC_ENT,   MO(2), KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_UPPER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, KC_BTN1, KC_BTN2, KC_WH_U,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, QK_BOOT, KC_BTN3, KC_WH_D,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  SX_PSC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),


    [_TILDE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX,  UK_EAC, XXXXXXX, XXXXXXX,                      XXXXXXX,  UK_UAC,  UK_IAC,  UK_OAC, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  UK_AAC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, UC_LINX, UC_WINC,  UC_MAC,                      UK_NTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

};


const uint32_t unicode_map[] PROGMEM = {
    [AACUTE] = 0xe1, //a
    [EACUTE] = 0xe9, //e
    [IACUTE] = 0xed, //i
    [OACUTE] = 0xf3, //o
    [UACUTE] = 0xfa, //u
    [NTILDE] = 0xf1, //n
    [AACUTEC] = 0xc1, //A
    [EACUTEC] = 0xc9, //E
    [IACUTEC] = 0xcd, //I
    [OACUTEC] = 0xd3, //O
    [UACUTEC] = 0xda, //U
    [NTILDEC] = 0xd1, //N
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SX_PSC:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL(SS_TAP(X_PSCR)));
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
/*static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}*/

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void render_master(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERT:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _UPPER:
            oled_write_P(PSTR("Upper\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _TILDE:
            oled_write_P(PSTR("Tilde\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    oled_write_P(PSTR("\n"), false);

    switch(get_unicode_input_mode()){
        case UNICODE_MODE_LINUX:
            oled_write_ln_P(PSTR("linux"), false);
            break;
        case UNICODE_MODE_MACOS:
            oled_write_ln_P(PSTR("macos"), false);
            break;
        case UNICODE_MODE_WINCOMPOSE:
            oled_write_ln_P(PSTR("windows"), false);
            break;
        default:
            oled_write_ln_P(PSTR("unknown"), false);
    }

}


const uint8_t frame_height = badapple[0];
const uint8_t frame_width = badapple[1];
const uint32_t frame_count = parse_uint32(badapple, 3);
const uint8_t header_offset = 7;

uint32_t frame_current = 0;
uint32_t frame_pointer = header_offset;

uint16_t read_uint16(void){
    frame_pointer += 2;
    return parse_uint16(badapple, frame_pointer-2);
}

uint8_t read_uint8(void){
    return badapple[frame_pointer++];
}

void render_badapple_frame(void) {
    if(frame_current == frame_count){
        frame_current = 0;
        frame_pointer = header_offset;
    }

    uint16_t sections = read_uint16();
    uint8_t current_x = 0;
    uint8_t current_y = 0;
    for(uint16_t i = 0; i<sections; i++){
        uint8_t color = read_uint8();
        bool is_on = color != 0x00;
        uint16_t pixel_count = read_uint16();
        for(uint16_t p = 0; p<pixel_count; p++){
            uint8_t x = current_x;
            uint8_t y = current_y;

            if(x+1 >= frame_width) {
                current_x = 0;
                current_y++;
            }
            else {
                current_x++;
            }

            oled_write_pixel(x + 1, y, is_on);
        }
    }

    frame_current++;
}

void render_slave(void){
    //render_logo();
    render_badapple_frame();
}
bool oled_task_user(void) {
    if(is_keyboard_master()){
        render_master();
    } else {
        render_slave();
    }
    return false;
}
#endif

