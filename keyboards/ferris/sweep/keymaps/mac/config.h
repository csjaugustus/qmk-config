#pragma once

// Match zmk-config Piantor home-row mods:
//   tapping-term 200, quick-tap 175, require-prior-idle 150,
//   balanced + opposite-hand (chordal) + hold-trigger-on-release.
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define QUICK_TAP_TERM 175
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
