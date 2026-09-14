# qmk-config

QMK userspace for a **wired Ferris Sweep** (beekeeb pre-soldered, RP2040 Sea-Picro).

The keymap is the **macOS** variant from [`csjaugustus/zmk-config`](https://github.com/csjaugustus/zmk-config) (`config/piantor_pro_bt.keymap` with `MAC_LAYOUT`), squashed from the Piantor’s 42 keys onto the Sweep’s 34.

## Hardware

| | |
|---|---|
| Keyboard | Ferris Sweep, 34 keys (3×5 + 2 thumbs / half) |
| Controller | RP2040 Sea-Picro (Pro Micro pinout) |
| Firmware | QMK, `CONVERT_TO=rp2040_ce` |
| Split | Wired TRRS. USB into **either** half (VBUS detect); typically the left. |

This will **not** run on the Piantor Pro BT (nRF52840 / ZMK / wireless).

## 42 → 34 mapping

Piantor outer columns were already blank on QWERTY/NAV, so they just disappear. Each hand also loses its **outer** thumb:

| Piantor thumbs (L→R) | Sweep thumbs |
|---|---|
| Caps · **SPC/NUM** · **⌘/NAV** | **SPC/NUM** · **⌘/NAV** |
| **RET/SYS** · **BSPC** · _(blank)_ | **RET/SYS** · **BSPC** |

Relocated / dropped:

- **Caps Lock** → SYSTEM `Q` (hold RET, tap Q)
- Bluetooth profile keys, `PWR`, `QK_BOOT`, and the far-right NUM dash column dropped. Flash via the Sea-Picro reset button (or Bootmagic: hold `Q`/`P` while plugging that half in).

## Layers

Hold behaviors are shown on the line beneath the key.

### 0 · QWERTY

```
Q    W    E    R    T   │   Y    U    I    O    P
A    S    D    F    G   │   H    J    K    L    ;
⌃    ⌥    ⇧    ⌘        │   ⌥⌘⇧C ⌘    ⇧    ⌥    ⌃
Z    X    C    V    B   │   N    M    ,    .    /
         ⌘C   ⌘V
           SPC  ⌘       │  RET  BSPC
           NUM  NAV     │  SYS
```

- Home-row mods `A S D F` / `J K L ;` = Ctrl / Alt / Shift / **Cmd**, opposite-hand only (QMK Chordal Hold, same idea as the ZMK `hml`/`hmr` setup).
- `H` hold = `⌥⌘⇧C`. `C` hold = `⌘C`; `V` hold = `⌘V`.
- Inner-left thumb **taps Cmd** / holds NAV. Inner-right thumb taps Return / holds SYSTEM.

ZMK timings copied across: tapping term 200 ms; HRMs are balanced + chordal + hold-on-other-key-*release*, quick-tap 175 ms, prior-idle 150 ms from last key *up* (ZMK last_tapped — not last press). `C`/`V`/`H`/`[`/`]` are tap-preferred (hold only after 200 ms). Thumbs are the same balanced/permissive rule as HRMs (a roll off the thumb stays a tap; keep the thumb down and tap the other key for the layer). Scroll is 16 notches/sec, no accel.

### 1 · NUM/SYM

```
!    @    #    $    %   │   7    8    9    =    `
~    &    *    (    )   │   4    5    6    +    ^
-    [    ]    '    "   │   1    2    3    .    \
    {    }
           ·    ·       │   0    ·
```

- `[` / `]` tap = square brackets; **hold** = `{` / `}`.

### 3 · NAV

```
·    ·    ·    ·   TAB  │   ·    ·    ·    ·    ·
←    ↓    ↑    →    ·   │   ·    ⌘    ⇧    ⌥    ⌃
·    ·    ·    ·   ESC  │  WH←  WH↑  WH↓  WH→   ·
           ·    ·       │   ·    ·
```

### 4 · SYSTEM

Held via **hold RET**.

```
Caps  ·    ·    ·    ·  │   ·    ·   Pass   ·    ·
 ·   MUTE  V-   V+  ▶⏸  │  ⌃⌥⏎  ⌃⌥←  ⌃⌥↓  ⌃⌥↑  ⌃⌥→
 ·    ·    ·    ·    ·  │   ·  ⌥⌘⇧/  ⌘⇧4  ⌘⇧5   ·
           ·    ·       │   ·    ·
```

- `I` = password macro (`pw_main`, same string as the ZMK keymap).
- No bootloader key. Each half already has a Sea-Picro reset button; hold it ~1 s to mount `RPI-RP2`. Backup: hold `Q` (left) or `P` (right) while plugging that half in (Bootmagic).

## Building

Builds are **manual-only** (`workflow_dispatch`), same as the ZMK repo.

```bash
# after pushing to main
gh workflow run build.yml --ref main --repo csjaugustus/qmk-config

gh run watch $(gh run list --repo csjaugustus/qmk-config --workflow build.yml --limit 1 --json databaseId --jq '.[0].databaseId') \
  --repo csjaugustus/qmk-config --exit-status --interval 20

gh run download <run_id> --repo csjaugustus/qmk-config -n firmware -D /tmp/qmk-fw
cp /tmp/qmk-fw/*.uf2 ~/Downloads/
```

The artifact is a single UF2 (both halves): `ferris_sweep_mac.uf2`.

Locally, with [QMK CLI](https://docs.qmk.fm/newbs) set up:

```bash
qmk config user.overlay_dir="$(realpath /Users/augustuschen/codebase/qmk-config)"
qmk compile -kb ferris/sweep -km mac
```

## Flashing

Flash **one half at a time**, TRRS **unplugged**.

1. Plug the half in via USB-C.
2. Hold the Sea-Picro **reset** button for ~1 s (or hold the top-outer key — `Q` on the left, `P` on the right — while plugging in).
3. The `RPI-RP2` drive mounts. Drag the UF2 onto it. The board reboots (~a few seconds). A “disk not ejected” warning is normal.
4. Repeat for the other half.
5. Plug TRRS back in. USB into the left half.

The stock VIAL firmware is overwritten. To go back, use [beekeeb’s Sweep firmware](https://docs.beekeeb.com/ferris-sweep-keyboard).
