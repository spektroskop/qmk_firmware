#include QMK_KEYBOARD_H

enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN,
    _SYM,
};

enum unicode_names {
    EM_DASH,
    ARING_U,
    ARING_L,
    AELIG_U,
    AELIG_L,
    OSLASH_U,
    OSLASH_L
};

const uint32_t PROGMEM unicode_map[] = {
    [EM_DASH] = 0x2014,
    [ARING_U] = 0x00C5,
    [ARING_L] = 0x00E5,
    [AELIG_U] = 0x00C6,
    [AELIG_L] = 0x00E6,
    [OSLASH_U] = 0x00D8,
    [OSLASH_L] = 0x00F8,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define SPACE_SYM LT(_SYM, KC_SPC)
#define OSL_SYM OSL(_SYM)
#define ESC_SYM LT(_SYM, KC_ESC)
#define EM_DASH X(EM_DASH)
#define ARING XP(ARING_L, ARING_U)
#define AELIG XP(AELIG_L, AELIG_U)
#define OSLASH XP(OSLASH_L, OSLASH_U)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------------------.
     * |  Esc  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Bksp  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  Tab  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  Fn   | Ctrl  |  Alt  |  GUI  | Lower |     Space     | Raise | Left  | Down  |  Up   | Right |
     * `-----------------------------------------------------------------------------------------------'
     */

    [_QWERTY] = LAYOUT_planck_grid(
        ESC_SYM, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------------------.
     * |   `   |   1   |   2   |   3   |   4   |   5   |   -   |   =   |  Del  |  End  | PgDn  |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |   6   |   7   |   8   |   9   |   0   |   [   |   ]   |   \   |   '   |       |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |  F1   |  F2   |  F3   |  F4   |       |       |  F5   |  F6   |  F7   |  F8   |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |               |       |       |       |       |       |
     * `-----------------------------------------------------------------------------------------------'
     */

    [_LOWER] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_DEL,  KC_END,  KC_PGDN, _______,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, XXXXXXX, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------------------.
     * |   ~   |   !   |   @   |   #   |   $   |   %   |   _   |   +   |  Ins  | Home  | Pgup  |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |   ^   |   &   |   *   |   (   |   )   |   {   |   }   |   |   |   "   |       |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |  F9   |  F10  |  F11  |  F12  |       |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |               |       |       |       |       |       |
     * `-----------------------------------------------------------------------------------------------'
     */

    [_RAISE] = LAYOUT_planck_grid(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS, KC_PLUS, KC_INS,  KC_HOME, KC_PGUP, _______,
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO, XXXXXXX, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Fn
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | (sym)|  F11 |  F12 |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    Space    |      | Home |PgDown| PgUp | End  |
     * `-----------------------------------------------------------------------------------'
     */

    [_FN] = LAYOUT_planck_grid(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12, _______, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    /* Sym
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |  Ø   |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  Å   |      |      |      |      |      |  —   |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |  Æ   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_SYM] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, OSLASH,  _______, _______,
        _______, ARING,   _______, _______, _______, _______, _______, EM_DASH, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AELIG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Adjust
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |Unicod|      |      |RgbTgl|RgbMod|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |Reset |      |      |      |      |      |      |      |      |      |HueInc|HueDec|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Debug |      |      |      |      |      |      |      |      |      |SatInc|SatDec|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |BriInc|BriDec|
     * `-----------------------------------------------------------------------------------'
     */

    [_ADJUST] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC_MOD,  XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD,
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_HUD,
        DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, RGB_VAI, RGB_VAD
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
