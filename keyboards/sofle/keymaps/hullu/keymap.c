#include <stdio.h>
#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _UPPER,
    _NUMPAD,
    _GAMESPACE
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_LEND,
    KC_DLINE,
    KC_LIB          // Library
};

// Tap dancing
enum tapdance_keycodes {
    TD_SPCENT,
    TD_BSPDEL,
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_SPCENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [TD_BSPDEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Different keys:
    * MO(F) = Momentarily activates _UPPER
    * TG(NP) = Toggle _NUMPAD
*/

/*
[_SAMPLE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
)
*/

/*
* BASE
* ,-----------------------------------------.                       ,-----------------------------------------.
* | ESC  |1!  F1|2"  F2|3#  F3|4¤  F4|5%  F5|                       |6&  F6|7/  F7|8(  F8|9)  F9|0= F10|+? F11|
* |------+------+------+------+------+------|                       |------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |                       |   Y  |   U  |   I  |   O  |   P  |BspcF12|
* |------+------+------+------+------+------|                       |------+------+------+------+------+------|
* |LShift|   A  |   S  |   D  |   F  |   G  |-------.       ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
* |------+------+------+------+------+------|  Play |       |MUTEALL|------+------+------+------+------+------|
* | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|       |-------|   N  |   M  |   ,  |   .  |   -  |  '*  |
* `-----------------------------------------/       /        \      \-----------------------------------------'
*            | <>|  | LWin | LALT |MO(F) | /SPCENT /          \SPCENT\  | RALT |      |      |      |
*            |      |      |      |      |/       /            \      \ |      |      |      |      |
*            `----------------------------------'               '------''---------------------------'
*/

[_BASE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  TD(TD_BSPDEL),
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LIB,                     _______, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLS,
         LT(0, KC_NUBS), KC_LWIN, KC_LALT,MO(_UPPER),TD(TD_SPCENT),          TD(TD_SPCENT),KC_RALT, _______, _______, _______
),
/* FLAYER
 * ,-----------------------------------------.                      ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                      |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                      |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.      ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |      |       |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |   {  |   }  |-------|      |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /       \      \-----------------------------------------'
 *            |      |      |      |MO(F) | /       /         \      \  |      |      |      |TG(NP)|
 *            |      |      |      |      |/       /           \      \ |      |      |      |      |
 *            `----------------------------------'              '------''---------------------------'
 */
[_UPPER] = LAYOUT(
  _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  _______,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_F12,
  _______,  KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,    _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN,KC_BSLS, _______,
                    _______, _______, _______,_______, _______,     _______, _______, _______, _______, _______
),
/* NUMPAD
 * ,-----------------------------------------.                      ,-----------------------------------------.
 * |      |      |      |      |      |      |                      |      |      |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                      |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.      ,-------|      |   4  |   5  |   5  |   +  |      |
 * |------+------+------+------+------+------|       |      |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|      |-------|      |   1  |   2  |   3  |Enter |      |
 * `-----------------------------------------/       /       \      \-----------------------------------------'
 *            |      |      |      |      | /       /         \      \  |   0  |   ,  |      |      |
 *            |      |      |      |      |/       /           \      \ |      |      |      |      |
 *            `----------------------------------'              '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______,  KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______,                      _______,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______,                      _______,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PENT, _______,
                    _______, _______, _______, _______, _______,    _______,  KC_P0 , KC_COMM, _______, _______
),

[_GAMESPACE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,  KC_SPC,     KC_ENT, _______, _______, _______, _______
)
};

// Library
bool libActive = false;

enum lib_keys {
    SPCNT,
    UPPER,
    NMPAD,
    SCROLL,
    MUTESYS,
    VOLUME,
    PREVNEXT,
    F13F14,
    LIBCOUNT
} activeKey = SCROLL;

int scrollSpeed = 1;

static void moveLib(bool clockwise) {
    if (activeKey == 0 && clockwise) {
        activeKey = LIBCOUNT -1;
    } else {
        activeKey += clockwise ? -1 : +1;
        if (activeKey >= LIBCOUNT) {
            activeKey = 0;
        }
    }
}

static char getLibValue(enum lib_keys key) {
    switch (key) {
        case SPCNT:
            return  IS_LAYER_ON(_GAMESPACE) ? 'Y' : 'N';
        case UPPER:
            return IS_LAYER_ON(_UPPER) ? 'Y' : 'N';
        case NMPAD:
            return IS_LAYER_ON(_NUMPAD) ? 'Y' : 'N';
        case SCROLL:
            char buffer[3];
            sprintf(buffer, "%d", scrollSpeed);
            buffer[2] = '\0';
            return buffer[0];
        case MUTESYS:
            return '-';
        case VOLUME:
            return 'V';
        case PREVNEXT:
            return '>';
        case F13F14:
            return 'F';
        case LIBCOUNT:
            return ' ';
    }
    return ' ';
}


static void doLibAction(bool clockwise) {
    switch (activeKey) {
        case SPCNT:
            if (clockwise) {
                layer_on(_GAMESPACE);
            } else {
                layer_off(_GAMESPACE);
            }
            return;
        case UPPER:
            if (clockwise) {
                layer_on(_UPPER);
            } else {
                layer_off(_UPPER);
            }
            return;
        case NMPAD:
            if (clockwise) {
                layer_on(_NUMPAD);
            } else {
                layer_off(_NUMPAD);
            }
            return;
        case SCROLL:
            scrollSpeed += clockwise ? 1 : -1;
            if (scrollSpeed > 9) {
                scrollSpeed = 9;
            } else if (scrollSpeed < 1) {
                scrollSpeed = 1;
            }
            return;
        case MUTESYS:
            tap_code(KC_MUTE);
            return;
        case VOLUME:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            return;
        case PREVNEXT:
            tap_code(clockwise ? KC_MNXT : KC_MPRV);
            return;
        case F13F14:
            tap_code(clockwise ? KC_F14 : KC_F13);
            return;
        case LIBCOUNT:
            return;
    }
    return;
}


#ifdef OLED_ENABLE
static const char image_Jhulgar[] PROGMEM =
{
    0x00, 0x00, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02, 0x02, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 0x0c, 0x08, 0x18, 0x30, 0xe0, 0x80, 0x00,
    0xfc, 0x27, 0xb1, 0x10, 0x60, 0x40, 0x80, 0x00, 0xe0, 0x30, 0x18, 0x0c, 0x06, 0x22, 0x22, 0xfa,
    0x22, 0x22, 0x06, 0x0c, 0x18, 0x30, 0xe0, 0x00, 0x00, 0x80, 0x40, 0x20, 0x90, 0x90, 0x63, 0xfe,
    0x7f, 0xe5, 0xa7, 0x12, 0x58, 0x24, 0xc3, 0x00, 0x1b, 0xe6, 0x02, 0x32, 0x14, 0x34, 0x94, 0xe5,
    0xd4, 0x34, 0x14, 0x32, 0x02, 0xe6, 0x9b, 0x80, 0x80, 0x81, 0xe2, 0x64, 0xbc, 0x09, 0xe2, 0x3f,
    0x00, 0x01, 0x03, 0x0e, 0x1c, 0x39, 0x30, 0x7d, 0x7e, 0xff, 0xff, 0xfc, 0xfc, 0xe2, 0xf2, 0xf2,
    0xe4, 0xf0, 0xfc, 0xf8, 0xff, 0xff, 0x7f, 0x7f, 0x21, 0x30, 0x19, 0x0c, 0x06, 0x03, 0x01, 0x00
};
static const char image_Wapice[] PROGMEM =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3e, 0x1e, 0x0e,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x1e, 0x3e, 0x3c, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x00,
    0x10, 0x18, 0x1e, 0x1e, 0x1e, 0x1e, 0xfe, 0xff, 0xff, 0xff, 0x1f, 0x1e, 0x3e, 0xfe, 0xfc, 0xe0,
    0xe0, 0xf0, 0xfc, 0xfc, 0xf0, 0xe0, 0xf0, 0xfc, 0xfe, 0x3e, 0x1e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x3f, 0x7e, 0xfc, 0xf0, 0xf0, 0xe3, 0xc7,
    0xc7, 0xc3, 0xc0, 0xc0, 0xc3, 0xc7, 0xc7, 0xe3, 0xf0, 0xf0, 0xfc, 0x7e, 0x3e, 0x1e, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Oled rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

// Oled main
bool oled_task_user(void) {
    oled_clear();
    if (!libActive) {
        oled_write_ln_P(PSTR("Junnu"), false);
        oled_set_cursor(0, 11);
        oled_write_raw_P(image_Jhulgar, sizeof(image_Jhulgar));
    }

    if (libActive) {
        oled_write_ln_P(PSTR("=LIB="), false);
        oled_write_ln_P(PSTR(""), false);

        switch (activeKey) {
            case SPCNT:
                oled_write_ln_P(PSTR("Spcn\n"), false);
                break;
            case UPPER:
                oled_write_ln_P(PSTR("Uppr\n"), false);
                break;
            case NMPAD:
                oled_write_ln_P(PSTR("Nmpd\n"), false);
                break;
            case SCROLL:
                oled_write_ln_P(PSTR("Scrl\n"), false);
                break;
            case MUTESYS:
                oled_write_ln_P(PSTR("Mute\n"), false);
                break;
            case VOLUME:
                oled_write_P(PSTR("Volum\n"), false);
                break;
            case PREVNEXT:
                oled_write_P(PSTR("<-M->\n"), false);
                break;
            case F13F14:
                oled_write_P(PSTR("13F14\n"), false);
                break;
            case LIBCOUNT:
                break;
        }
        oled_write_ln_P(PSTR(""), false);
        oled_write_P(PSTR("|:::|"), false);
        oled_write_P(PSTR("  "), false);
        oled_write_char(getLibValue(activeKey), false);
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("|:::|"), false);

        oled_set_cursor(0, 11);
        oled_write_raw_P(image_Wapice, sizeof(image_Wapice));
    }

    return false;
}
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_LIB:
            if (record->event.pressed) {
                libActive = true;
            } else {
                libActive = false;
            }
            return false;
        case LT(0, KC_NUBS): //sends colon on tap and semicolon on hold
            if (record->tap.count && record->event.pressed) {
                return true; // Return true for normal processing of tap keycode
                break;
            }
            else if (record->event.pressed) {
                tap_code16(RALT(KC_NUBS)); // Intercept hold function to send PIPE
                return false;
            }
            return true; // this allows for normal processing of key release!
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (libActive) {
            moveLib(clockwise);
        } else {
            for (int i = 0; i < scrollSpeed; i++) {
                tap_code(clockwise ? KC_DOWN : KC_UP);
            }
        }
    } else if (index == 1) {
        if (libActive) {
            doLibAction(clockwise);
        } else {
            for (int i = 0; i < scrollSpeed; i++) {
                tap_code(clockwise ? KC_RIGHT : KC_LEFT);
            }
        }
    }
    return false;
}

#endif
