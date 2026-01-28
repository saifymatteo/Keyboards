# LED Strip

Custom LED strip powered by generic Pro Micro

## Hardware

1. Pro Micro
2. Basic buttons x6
3. WS2182B LED strip

### Guide

This guide assumed you are already follow root `README.md`, specifically these:

1. Setup QMK and clone the repository
2. Setup VS Code for C development
3. Create symbolic link between this repository and QMK/Vial repository

The keyboard will be working on is in this directory `<path-to-qmk-repository>/keyboards/saifymatteo/led_strip/promicro_x6/firmware`.

### Compiles

Choose your version of how many LED are in the strip, example x6 means 6 LED in a single strip

To compile keyboard and keymap:

```bash
qmk compile -kb saifymatteo/led_strip/promicro_x6/firmware -km vial
```

Note:

- `-kb` is `saifymatteo/led_strip/promicro_x6/firmware` keyboard config
- `-km` is `vial` keyboard mapping

### Flashing

To flash, use QMK Toolbox.

To flash, choose based on your MCU:

Set local file to `saifymatteo_led_strip_firmware_promicro_x6_vial.hex` and MCU to `ATmega32U4`.

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
make saifymatteo/led_strip/promicro_x6/firmware:vial
```

### VIAL Flashing

Please see [QMK flashing](#flashing)
