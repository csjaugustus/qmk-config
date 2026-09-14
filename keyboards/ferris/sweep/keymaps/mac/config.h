#pragma once

// ZMK (piantor_pro_bt.keymap) → QMK. Per-key callbacks are in keymap.c;
// the *_PER_KEY flags are required or QMK ignores those functions.
//
// HRM hml/hmr: flavor balanced, tapping-term 200, quick-tap 175,
//   require-prior-idle 150, opposite-hand + thumbs, hold-trigger-on-release
//   → TAPPING_TERM 200, CHORDAL_HOLD, PERMISSIVE_HOLD (HRMs only),
//     QUICK_TAP 175 (HRMs only), FLOW_TAP 150 (HRMs only).
// &ht (C/V/H, [/]): flavor tap-preferred, tapping-term 200, no quick-tap
//   → no permissive, no hold-on-other-key-press, quick-tap 0.
// Thumbs (Space/NUM, Cmd/NAV, Ret/SYS): balanced/permissive, not
//   hold-on-press — a roll (thumb down, next key down, thumb up) stays a
//   tap. Nested (keep thumb down, tap other, release other) is the layer.
//   Thumbs are '*' in chordal layout so NAV+arrows (same hand) still work.
#define TAPPING_TERM 200
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define QUICK_TAP_TERM 175
#define QUICK_TAP_TERM_PER_KEY
#define FLOW_TAP_TERM 150

// Sea-Picro (rp2040_ce) exposes VBUS, so whichever half is plugged
// into USB becomes master. Flash the same UF2 to both halves.
// Typical setup: USB into the left half, TRRS between halves.
#define SPLIT_USB_DETECT

// Mouse-wheel on NAV: match zmk-config &msc (SCRL_SPD 16 notches/sec,
// acceleration-exponent 0, delay-ms 0). MAX_SPEED 1 keeps one tick per
// report; INTERVAL 1000/16. TIME_TO_MAX 0 with MAX_SPEED>1 would jump
// straight to that many ticks/report, which is not "no accel".
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 6
#define MOUSEKEY_MAX_SPEED 8
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 63
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
