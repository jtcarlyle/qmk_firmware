#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum layer_number {
  _XAH = 0,
  _QWE,
  _MMOD,
  _NAV,
  _MNAV,
  _PLV,
  _FUN,
  _MEDIA,
  _ADJUST,
};

// dual purpose tap-hold keys
#define CT_TAB CTL_T(KC_TAB)
#define LT_SPC LT(_NAV, KC_SPC)
#define MLT_SPC LT(_MNAV, KC_SPC)
#define GT_ESC GUI_T(KC_ESC)
#define LT_BSPC LT(_FUN, KC_BSPC)
#define ST_ENT SFT_T(KC_ENT)
#define GT_DEL GUI_T(KC_DEL)
#define AT_HOME ALT_T(KC_HOME)
#define AT_MINS ALT_T(KC_MINS)

// steno stuff
#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

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
  KC_GRV,  KC_8,    KC_7,    KC_3,   KC_4,    KC_5,                     KC_6,    KC_2,    KC_1,    KC_9,    KC_0,    KC_EQL,
  KC_BSLS, KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  AT_HOME, KC_A,    KC_O,    KC_E,   KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    AT_MINS,
  KC_LGUI, KC_SCLN, KC_Q,    KC_J,   KC_K,    KC_X, KC_LBRC,  KC_RBRC,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RGUI,
                            KC_MEH, GT_ESC, LT_SPC,  CT_TAB,  ST_ENT,  LT_BSPC, GT_DEL, KC_HYPR
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
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, MLT_SPC, _______, _______, _______, _______, _______
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
  _______,    _______,   _______,   _______,    _______,    _______,                     _______,  _______,    _______, _______,    _______,    _______,
  _______,    C(KC_ESC), C(KC_SPC), C(KC_BSPC), C(KC_DEL),  _______,                     C(KC_Z),  C(KC_LEFT), KC_UP,   C(KC_RGHT), C(KC_Y),    C(KC_EQL),
  MO(_MEDIA), KC_LGUI,   KC_LALT,   KC_LCTL,    KC_LSFT,    _______,                     KC_HOME,  KC_LEFT,    KC_DOWN, KC_RGHT,    KC_END,     C(KC_MINS),
  _______,    _______,   C(KC_X),   C(KC_C),    C(KC_V),    _______, _______, _______,   C(KC_F),  C(KC_UP),   KC_PGUP, KC_PGDN,    C(KC_DOWN), _______,
                                    _______,    _______,    _______, _______, S(KC_ENT), KC_F3,    S(KC_F3),   _______
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
  _______, C(KC_ESC), C(KC_SPC), A(KC_BSPC), A(KC_DEL),  _______,                     C(KC_Z),    A(KC_LEFT), KC_UP,   A(KC_RGHT), RCS(KC_Z),  C(KC_EQL),
  _______, KC_LGUI,   KC_LALT,   KC_LCTL,    KC_LSFT,    _______,                     C(KC_LEFT), KC_LEFT,    KC_DOWN, KC_RGHT,    C(KC_RIGHT),C(KC_MINS),
  _______, _______,   C(KC_X),   C(KC_C),    C(KC_V),    _______, _______, _______,   C(KC_F),    A(KC_UP),   KC_PGUP, KC_PGDN,    A(KC_DOWN), _______,
                                 _______,    _______,    _______, _______, S(KC_ENT), C(KC_G),    RCS(KC_G),  _______
),
/* PLOVER - A layer for stenotype
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
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

 [_PLV] = LAYOUT(
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  STN_N1,   STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,                     STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  STN_FN,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                    STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  STN_RES2, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, DF(_XAH), XXXXXXX, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                             STN_PWR, STN_A,    STN_O,  STN_AO,    STN_EU,  STN_E,   STN_U, STN_RE1
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
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   DF(_XAH),                   _______, KC_LCBR, KC_LPRN, KC_LBRC, KC_ASTR,   KC_CAPS,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_PLV), _______, _______, _______, KC_RCBR, KC_RPRN, KC_RBRC, TG(_MMOD), NK_TOGG,
                       _______, C(KC_ESC), C(KC_SPC),  C(KC_TAB), _______, _______, _______, _______
),

[_MEDIA] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______,
  _______, _______, _______, _______, _______, _______,                   _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_BRID, KC_BRIU, KC_MFFD, _______,
                   _______, _______, _______,  _______, _______, _______, _______, _______
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
