/* SPDX-License-Identifier: GPL-2.0-or-later
 *
 * macOS keymap for the 34-key Ferris Sweep, ported from
 * zmk-config config/piantor_pro_bt.keymap (MAC_LAYOUT).
 *
 * 42 -> 34: drop the unused outer columns and the outer thumb of each
 * hand (Piantor Caps / blank rightmost). Everything else keeps its
 * QWERTY position. See README.md for the mapping.
 */

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NUM,
    _NAV,
    _SYS,
};

enum custom_keycodes {
    PW_MAIN = SAFE_RANGE,
};

// Tap-preferred hold-taps (ZMK &ht). Hold sends the combo; tap sends the key.
#define HT_C    LT(0, KC_C)
#define HT_V    LT(0, KC_V)
#define HT_H    LT(0, KC_H)
#define HT_LBRC LT(0, KC_LBRC)
#define HT_RBRC LT(0, KC_RBRC)

#define HRM_A    LCTL_T(KC_A)
#define HRM_S    LALT_T(KC_S)
#define HRM_D    LSFT_T(KC_D)
#define HRM_F    LGUI_T(KC_F)
#define HRM_J    RGUI_T(KC_J)
#define HRM_K    RSFT_T(KC_K)
#define HRM_L    RALT_T(KC_L)
#define HRM_SCLN RCTL_T(KC_SCLN)

#define NAV_CMD LT(_NAV, KC_LGUI) /* tap Cmd / hold NAV */
#define NUM_SPC LT(_NUM, KC_SPC)
#define SYS_ENT LT(_SYS, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * Q    W    E    R    T        Y    U    I    O    P
     * A/⌃  S/⌥  D/⇧  F/⌘  G        H/h  J/⌘  K/⇧  L/⌥  ;/⌃
     * Z    X    C/h  V/h  B        N    M    ,    .    /
     *               SPC   ⌘             RET  BSPC
     *               NUM   NAV           SYS
     */
    [_QWERTY] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,        HT_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN,
        KC_Z,    KC_X,    HT_C,    HT_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   NUM_SPC, NAV_CMD,     SYS_ENT, KC_BSPC
    ),

    /*
     * NUM/SYM
     * !    @    #    $    %        7    8    9    =    `
     * ~    &    *    (    )        4    5    6    +    ^
     * -    [    ]    '    "        1    2    3    .    \
     *               ·     ·             0    ·
     */
    [_NUM] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_7,    KC_8,    KC_9,    KC_EQL,  KC_GRV,
        KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,     KC_4,    KC_5,    KC_6,    KC_PLUS, KC_CIRC,
        KC_MINS, HT_LBRC, HT_RBRC, KC_QUOT, KC_DQUO,     KC_1,    KC_2,    KC_3,    KC_DOT,  KC_BSLS,
                                   _______, _______,     KC_0,    _______
    ),

    /*
     * NAV
     * ·    ·    ·    ·    TAB      ·    ·    ·    ·    ·
     * ←    ↓    ↑    →    ·        ·    ⌘    ⇧    ⌥    ⌃
     * ·    ·    ·    ·    ESC      WH←  WH↑  WH↓  WH→  ·
     *               ·     ·             ·    ·
     */
    [_NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,     XXXXXXX, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,      MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, XXXXXXX,
                                   _______, _______,     _______, _______
    ),

    /*
     * SYSTEM (hold RET)
     * Caps ·    ·    ·    ·        ·    ·    Pass ·    ·
     * ·    MUTE V-   V+   play     ctl-alt-ent/arrows
     * ·    ·    ·    ·    ·        ·    opt-cmd-s-/ cmd-s-4 cmd-s-5 ·
     *               ·     ·             ·    ·
     */
    [_SYS] = LAYOUT_split_3x5_2(
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, PW_MAIN, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,     LCA(KC_ENT), LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_UP), LCA(KC_RGHT),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, A(G(S(KC_SLSH))), SGUI(KC_4), SGUI(KC_5), XXXXXXX,
                                   _______, _______,     _______, _______
    ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_2(
    'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R',
                   '*', '*',    '*', '*'
);
// clang-format on

static bool is_hrm(uint16_t keycode) {
    switch (keycode) {
        case HRM_A:
        case HRM_S:
        case HRM_D:
        case HRM_F:
        case HRM_J:
        case HRM_K:
        case HRM_L:
        case HRM_SCLN:
            return true;
        default:
            return false;
    }
}

static bool is_tap_preferred(uint16_t keycode) {
    switch (keycode) {
        case HT_C:
        case HT_V:
        case HT_H:
        case HT_LBRC:
        case HT_RBRC:
            return true;
        default:
            return false;
    }
}

static bool is_thumb_lt(uint16_t keycode) {
    switch (keycode) {
        case NUM_SPC:
        case NAV_CMD:
        case SYS_ENT:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // HRMs and thumbs: hold if another key is pressed and released before
    // tapping term (rolls stay taps). Not for &ht.
    (void)record;
    if (is_tap_preferred(keycode)) {
        return false;
    }
    return is_hrm(keycode) || is_thumb_lt(keycode);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    // ZMK quick-tap-ms is only set on hml/hmr. &ht and &lt leave it 0.
    (void)record;
    if (is_hrm(keycode)) {
        return QUICK_TAP_TERM;
    }
    return 0;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    // ZMK require-prior-idle-ms is only on HRMs, and vs any prior key.
    (void)record;
    (void)prev_keycode;
    if (is_hrm(keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HT_C:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_C));
                return false;
            }
            return true;
        case HT_V:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_V));
                return false;
            }
            return true;
        case HT_H:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(A(G(S(KC_C))));
                return false;
            }
            return true;
        case HT_LBRC:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            return true;
        case HT_RBRC:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;
            }
            return true;
        case PW_MAIN:
            if (record->event.pressed) {
                SEND_STRING("Antifuckingh4ck!");
            }
            return false;
    }
    return true;
}
