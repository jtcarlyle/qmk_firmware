#include QMK_KEYBOARD_H
#include "layout.h"

enum layer_number {
  DVO = 0,
  QWE,
  EXTL,
  EXTR,
};

// dual purpose mod/layer-tap keys
#define ST_SPC SFT_T(KC_SPC)
#define ST_ENT SFT_T(KC_ENT)
#define LT_TAB LT(EXTL, KC_TAB)
#define LT_BSPC LT(EXTR, KC_BSPC)
#define GT_UP GUI_T(KC_UP)
#define GT_RGHT GUI_T(KC_RGHT)
#define CT_ESC CTL_T(KC_ESC)
#define CT_MINS CTL_T(KC_MINS)
#define AT_LBRC ALT_T(KC_LBRC)
#define AT_RBRC ALT_T(KC_RBRC)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVO - Base Layer DVORAK with changed numbers
 * ESC, - double as CTRL
 * [, ] double as ALT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   7  |   8  |   9  |   0  |   5  |                    |   6  |   1  |   2  |   3  |   4  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \   |   "  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|  F11  |    |  F12  |------+------+------+------+------+------|
 * |  [   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |  ]   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Down |  Up  | Tab  | /  RET  /       \ SPC  \  | BKSPC |  <-  |  ->  |
 *                   |      | GUI  | EXT  |/ Shift /         \ Shift\ | EXT   | GUI  |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [DVO] = LAYOUT_LR(
      KC_GRV , KC_7   , KC_8   , KC_9   , KC_0   , KC_5   ,
      KC_BSLS, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,
      CT_ESC , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
      AT_LBRC, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_F11,
                                 KC_LEFT, GT_RGHT, LT_TAB , ST_ENT ,

               KC_6   , KC_1   , KC_2   , KC_3   , KC_4   , KC_EQL ,
               KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
               KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , CT_MINS,
      KC_F12 , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , AT_RBRC,
      ST_SPC , LT_BSPC, GT_UP  , KC_DOWN
    ),

/* QWE - QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   \   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  | LALT | Space | /CTRL  /       \ ESC  \  | Enter | RALT |  =  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * For gaming and lending to others
 * Full keyboard functionality in a semi-sane usable layout
 * Note that ESC is where Capslock normally is. I hope that this
 * can be reprogrammed in games
 *
 */
    [QWE] = LAYOUT_LR(
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
      KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
      KC_ESC , KC_A   , KC_S   , KC_S   , KC_D   , KC_F   ,
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_BSLS,
                              KC_LGUI , KC_LALT  , KC_SPC , KC_LCTL,

               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
               KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
               KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
      KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
      KC_ENT , KC_SPC , KC_RALT, KC_EQL
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
/* [_NAV] = LAYOUT( */
/*   _______,    _______,   _______,   _______,    _______,    _______,                     _______,  _______,    _______, _______,    _______,    _______, */
/*   _______,    C(KC_ESC), C(KC_SPC), C(KC_BSPC), C(KC_DEL),  _______,                     C(KC_Z),  C(KC_LEFT), KC_UP,   C(KC_RGHT), C(KC_Y),    C(KC_EQL), */
/*   MO(_MEDIA), KC_LGUI,   KC_LALT,   KC_LCTL,    KC_LSFT,    _______,                     KC_HOME,  KC_LEFT,    KC_DOWN, KC_RGHT,    KC_END,     C(KC_MINS), */
/*   _______,    _______,   C(KC_X),   C(KC_C),    C(KC_V),    _______, _______, _______,   C(KC_F),  C(KC_UP),   KC_PGUP, KC_PGDN,    C(KC_DOWN), _______, */
/*                                     _______,    _______,    _______, _______, S(KC_ENT), KC_F3,    S(KC_F3),   _______ */
/* ), */

/* SYML - function keys and symbols on the left hand (intended for cross hand use)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  F6  |  F1  | F2   |  F3   | F4   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   &  |   %  |  [   |   ]  |   ^  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  | ALT  | CTRL | SHIFT|      |-------.    ,-------|   |  |   :  |  (   |   )  |   \  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |-------|    |-------|   ~  |  $   |  {   |  }   |  @  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |       |     | /       /       \   _  \  |  DEL | HOME | END  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [EXTL] = LAYOUT_LR(
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, _______,
       _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______,
                                  _______, _______, _______, _______,

                         KC_F6  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,
                         KC_AMPR, KC_PERC, KC_LBRC, KC_RBRC, KC_CIRC, _______,
                         KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_BSLS, _______,
                KC_F14 , KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT  , _______,
                KC_UNDS, KC_DEL , KC_PGUP, KC_PGDN
    ),

/* SYMR - function keys and symbols on the left hand (intended for cross hand use)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |       |     |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  <   |  >   |  *   |      |                    |      |      |  DVO | QWE  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  +   |  /   |  -   |  =   |      |-------.    ,-------|      | SHIFT| CTRL |  ALT | GUI  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  !   | Mute | Vol- | Vol+ |      |-------|    |-------|      | Prev | Play | Stop | Next |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | PgDn  | PgUp |     | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [EXTR] = LAYOUT_LR(
       _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F5  ,
       _______, _______, KC_LABK, KC_RABK, KC_ASTR, _______,
       _______, KC_PLUS, KC_SLSH, KC_MINS, KC_EQL , KC_HASH,
       _______, KC_EXLM, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_F13 ,
                                  KC_HOME, KC_END , _______, _______,

                         _______, _______, _______, _______, _______, _______,
                         _______, _______, DF(DVO), DF(QWE), _______, _______,
                         _______, OS_RSFT, OS_RCTL, OS_RALT, OS_RGUI, _______,
                _______, _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______,
                                           _______, _______, _______, _______
    ),
};

/* layer_state_t layer_state_set_user(layer_state_t state) {
 *   return update_tri_layer_state(state, _FUN, _NAV, _ADJUST);
 * }
 */

// I don't use any of this junk since my OLED's don't work
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
