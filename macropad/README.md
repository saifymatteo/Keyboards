# Macropad

Custom 4x4 Macropad with Rotary Encoder and an OLED screen. Fully design by me.

To view the whole case: [viewstl](https://www.viewstl.com/)

## Hardware

1. Pro Micro
2. EC11 Rotary Encoder x3 with Knobs
3. OLED 0.96 inch 128x64 i2C

## Getting Started

<!-- Refer `promicro/KBPinouts.png` for right side pin layout and `promicro/wiring_left.png` for left. Both wiring are similar, so can refer left side. -->

### Guide

This guide assumed you are already follow root `README.md`, specifically these:

1. Setup QMK and clone the repository
2. Setup VS Code for C development
3. Create symbolic link between this repository and QMK/Vial repository

The keyboard will be working on is in this directory `<path-to-qmk-repository>/keyboards/saifymatteo/macropad/firmware`.

### Compiles

To compile keyboard and keymap:

```bash
qmk compile -kb saifymatteo/macropad/firmware -km vial_matteo
```

Note:

- `-kb` is `saifymatteo/macropad/firmware` keyboard config
- `-km` is `vial_matteo` keyboard mapping

### Flashing

To flash, use QMK Toolbox.

To flash, choose based on your MCU:

Set local file to `saifymatteo_macropad_firmware_vial_matteo.hex` and MCU to `ATmega32U4`.

Start flashing by shorting RST and GND pin or press the reset switch on the back.

Once done, quickly press Flash.

If need to clear EEPROM, double press reset switch and press Clear EEPROM.

## VIAL

Alternative to remap your keymap, no need to reflash everytime want to change keymap.

Clone [vial-qmk](https://github.com/vial-kb/vial-qmk) to get started.

Creating the flash file for VIAL enabled are similar with QMK, the difference is that VIAL use `make` instead `qmk compile`

Ensure working directory in `vial-qmk` directory.

Run this to compile to `hex` file.

```bash
make saifymatteo/macropad/firmware:vial_matteo
```

### VIAL Flashing

Please see [QMK flashing](#flashing)
