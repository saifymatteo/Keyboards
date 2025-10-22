# README

Inspiration from [Schievel1](https://github.com/Schievel1/dactyl_manuform_r_track) and [noahprince22](https://github.com/noahprince22/tractyl-manuform-keyboard)

Use these STL files from u/Tonehaven2 instead:

- [left](https://gitlab.com/keyboards1/dm_left/-/blob/master/boolean/left.stl)

- [right](https://gitlab.com/keyboards1/dm_r_track/-/blob/master/boolean/right.stl)

To view the whole case: [viewstl](https://www.viewstl.com/)

## Hardware

1. Pro Micro 2x for both left and right.
    1. On the trackball side, we will use pretty much all of the pin
    2. This is for only USB C Pro Micro

## Getting Started

`keymaps_tractyl_manuform.json` is a JSON representation of current configuration. This file need to be converted to C file and compile to `hex` before can be flash.

Refer `KBPinouts.png` for right side pin layout and `wiring_left.png` for left. Both wiring are similar, so can refer left side

### Things to download

Clone [saifymatteo/qmk_firmware](https://github.com/saifymatteo/qmk_firmware) to get started.

Use [QMK Configurator](https://config.qmk.fm) to setup custom keymaps

- Download only the JSON keymap, cannot use the compiled from here

Download [QMK Toolbox](https://github.com/qmk/qmk_toolbox) for flashing

Download CLI [QMK MSYS](https://msys.qmk.fm/) for compiling and converting JSON

### Guide

Start QMK MSYS CLI to start compiles

From here, ensure working directory is inside the `qmk_firmware` folder.

```bash
cd D:/Git/qmk_firmware
```

Then you need to fetch the submodules, run this:

```bash
git submodule update --init --recursive
```

To confirm everything up to date, run:

```bash
qmk doctor
```

The keyboard will be working is in this directory `qmk_firmware/keyboards/handwired/tractyl_manuform`, specifically `5x6_right/promicro` and `5x6_right/keymaps/saifymatteo`

Copy `keymaps_tractyl_manuform.json` to `qmk_firmware` folder and run next command to convert

To convert keymap from JSON to C file, use this:

```bash
qmk json2c keymaps_tractyl_manuform.json >> keyboards/handwired/tractyl_manuform/5x6_right/keymaps/saifymatteo/keymap.c
```

Ensure key maps are valid in `5x6_right/keymaps/saifymatteo/keymap.c`

Now we can compile to flash

To compile keyboard and keymap:

```bash
qmk compile -kb handwired/tractyl_manuform/5x6_right/promicro -km saifymatteo
```

Note:

- `-kb` is `5x6_right/promicro` keyboard config
- `-km` is `5x6_right/saifymatteo` keyboard mapping

### Flashing

To flash, use QMK Toolbox.

Set local file to `\handwired_tractyl_manuform_5x6_right_promicro_saifymatteo.hex` and MCU to `ATmega32U4`

Start flashing by shorting RST and GND pin or press the reset switch on the back.

Once done, quickly press Flash

Note:

- You need to flash both side with the same `hex` file
- Communication between each side will be automatic once flashed

If need to clear EEPROM, double press reset switch and press Clear EEPROM

## VIAL

Alternative to remap your keymap, no need to reflash everytime want to change keymap.

Clone [saifymatteo/vial-qmk](https://github.com/saifymatteo/vial-qmk) to get started.

Creating the flash file for VIAL enabled are similar with QMK, the difference is that VIAL use `make` instead `qmk compile`

Ensure working directory in `vial-qmk` directory.

```bash
cd D:/Git/vial-qmk
```

Run this to compile to `hex` file

```bash
make handwired/tractyl_manuform/5x6_right/promicro:vial
```

### VIAL Flashing

Please see [QMK flashing](#flashing)

## Other sources

- Trackball Small | [Tractyl ManuForm Keyboard](https://github.com/noahprince22/tractyl-manuform-keyboard)
- Non-trackball | [Complete idiot guide for building a dactyl manuform keyboard](https://medium.com/swlh/complete-idiot-guide-for-building-a-dactyl-manuform-keyboard-53454845b065)
- Trackball RGB | [Track Beast build log: a trackball Dactyl-manuform](https://medium.com/@kincade/track-beast-build-log-a-trackball-dactyl-manuform-19eaa0880222)
- Non-trackball Wireless | [I Built A Wireless Dactyl Manuform](https://tuxtower.net/blog/dactylmanuform/)
- Trackball No Build Guide | [u/Tonehaven2](https://www.reddit.com/r/ErgoMechKeyboards/comments/l5n0ab/trackball_in_a_dactyl_manuform_5x6_by_uqqurn/)
