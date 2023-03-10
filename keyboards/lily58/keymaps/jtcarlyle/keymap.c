#include QMK_KEYBOARD_H

enum layer_number {
  _XAH = 0,
  _QWE,
  _MMOD,
  _NAV,
  _MNAV,
  _FUN,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* XAH - Base Layer of Xah Lee style DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   8  |   7  |   3  |   4  |   5  |                    |   6  |   2  |   1  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \   |   "  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|  Alt  |    |  GUI  |------+------+------+------+------+------|
 * |  [   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |  ]   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  Meh |  Tab | Space| /  Ctrl /       \ Shift\  | BKSPC | Enter| Hyper|
 *                   |      |      | NAV  |/       /         \      \ | FUN   |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_XAH] = LAYOUT(
  KC_GRV,   KC_8,    KC_7,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_2,    KC_1,    KC_9,    KC_0,    KC_EQL,
  KC_BSLS,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  KC_ESC,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  KC_LBRC,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_LALT,  KC_RGUI,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RBRC,
                  KC_LGUI, KC_TAB, LT(_NAV, KC_SPC),  KC_LCTL,  KC_LSFT,  LT(_FUN, KC_BSPC), KC_ENT, KC_RALT
),
/* QWE - QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * for gaming and maybe lending to others
 * no mod-tap nav layer
 *
 */

 [_QWE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_RBRC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LBRC,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LALT,  KC_LGUI,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                           KC_LALT, KC_LCTL, KC_SPC, KC_TAB,   KC_LSFT,  LT(_FUN, KC_BSPC), KC_ENT, KC_HYPR
),
/* MMOD - Mac Modifiers
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MMOD] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_RCTL, _______, _______, _______, _______, _______, _______,
                  KC_LCTL, _______, LT(_MNAV, KC_SPC),  KC_LGUI, _______, _______, _______, KC_RGUI
),
/* NAV - Text editing/navigation layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |dmenu | IME  | ⌫w  |  ⌦w |      |                    | undo |  ←w  |   ↑  |  →w  | redo | zoom+|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  | Alt  | Ctrl |Shift |      |-------.    ,-------|  |←  |   ←  |   ↓  |   →  |  →|  | zoom-|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  cut | copy | paste|      |-------|    |-------| find | ←¶  | PgDn  | PgUp |  →¶  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \←find \  | find→ | Del |      |
 *                   |      |      |      |/       /         \      \ |       |     |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT(
  _______, _______,   _______,   _______,    _______,    _______,                    _______,  _______,    _______, _______,    _______,    _______,
  _______, C(KC_ESC), C(KC_SPC), C(KC_BSPC), C(KC_DEL),  _______,                    C(KC_Z),  C(KC_LEFT), KC_UP,   C(KC_RGHT), C(KC_Y),    C(KC_EQL),
  _______, KC_LGUI,   KC_LALT,   KC_LCTL,    KC_LSFT,    _______,                    KC_HOME,  KC_LEFT,    KC_DOWN, KC_RGHT,    KC_END,     C(KC_MINS),
  _______, _______,   C(KC_X),   C(KC_C),    C(KC_V),    _______, _______, _______,  C(KC_F),  C(KC_UP),   KC_PGDN, KC_PGUP,    C(KC_DOWN), _______,
                                 _______,    _______,    _______, _______, S(KC_F3), KC_F3, KC_DEL,     _______
),
/* MNAV - Text editing/navigation layer for MacOS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MNAV] = LAYOUT(
  _______, _______,   _______,   _______,    _______,    _______,                     _______,    _______,    _______, _______,    _______,    _______,
  _______, G(KC_ESC), G(KC_SPC), A(KC_BSPC), A(KC_DEL),  _______,                     G(KC_Z),    A(KC_LEFT), KC_UP,   A(KC_RGHT), LSG(KC_Z),  G(KC_EQL),
  _______, KC_LCTL,   KC_LALT,   KC_LGUI,    KC_LSFT,    _______,                     G(KC_LEFT), KC_LEFT,    KC_DOWN, KC_RGHT,    G(KC_RGHT), G(KC_MINS),
  _______, _______,   G(KC_X),   G(KC_C),    G(KC_V),    _______, _______, _______,   G(KC_F),    A(KC_UP),   KC_PGDN, KC_PGUP,    A(KC_DOWN), _______,
                                 _______,    _______,    _______, _______, LSG(KC_G), G(KC_G),    KC_DEL,     _______
),
/* FUN - function keys and symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |QWERTY|                    |      |   ^  |   &  |   $  |   %  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |DVORAK|-------.    ,-------|      |   {  |  (   |   [  |   *  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |ADJUST|-------|    |-------|      |   }  |   )  |   ]  |  MAC |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |       |Shift| /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,   _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   DF(_QWE),                   _______, KC_CIRC, KC_AMPR, KC_DLR,  KC_PERC,   _______,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   DF(_XAH),                   _______, KC_LCBR, KC_LPRN, KC_LBRC, KC_ASTR,   _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  MO(_NAV), _______, _______, _______, KC_RCBR, KC_RPRN, KC_RBRC, TG(_MMOD), _______,
                             _______, _______, KC_LSFT,  _______, _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * nothing here for now
 *
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _FUN, _NAV, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
