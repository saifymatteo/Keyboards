# README

Inspiration from [Pteron](https://github.com/FSund/pteron-keyboard)

Refer STLs and Drawing (dxf or svg format) in STL folder

To view the whole case: [viewstl](https://www.viewstl.com/)

## Hardware

1. Teensy++ 2.0 with (AT90USB1286)

## Getting Started

`keymaps_spender.json` is a JSON representation of current configuration. This file need to be converted to C file and compile to `hex` before can be flash.

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

The keyboard will be working is in this directory `qmk_firmware/keyboards/handwired/spender`.

Copy `keymaps_spender.json` to `qmk_firmware` folder and run next command to convert

To convert keymap from JSON to C file, use this:

```bash
qmk json2c keymaps_spender.json >> keyboards/handwired/spender/keymaps/default/keymap.c
```

Ensure key maps are valid in `spender/keymaps/default/keymap.c`

Now we can compile to flash

To compile keyboard and keymap:

```bash
qmk compile -kb handwired/spender -km default
```

Note:

- `-kb` is `handwired/spender` keyboard config
- `-km` is `default` keyboard mapping

### Flashing

To flash, use QMK Toolbox.

Set local file to `\handwired_spender_default.hex` and MCU to `AT90USB1286`

Start flashing by shorting RST and GND pin or press the reset switch on the back.

Once done, quickly press Flash

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
make handwired/spender:vial
```

### VIAL Flashing

Please see [QMK flashing](#flashing)
