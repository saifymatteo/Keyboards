# Keyboards

Powered by [QMK](https://qmk.fm/)

## Getting Started

Ensure these are installed:

1. Fork [QMK repository](https://github.com/qmk/qmk_firmware) or [VIAL repository](https://github.com/vial-kb/vial-qmk) and clone to your local machine
2. Setup QMK [through here](https://docs.qmk.fm/newbs_getting_started)
3. [QMK Toolbox](https://github.com/qmk/qmk_toolbox)

Optionally:

1. Use [QMK Configurator](https://config.qmk.fm) to setup custom keymap

This repository is intended to use together with symbolic link as it only contains necessary files for a QMK keyboard files.

To make symbolic link, use these:

1. MacOS/Linux - `ln -s <path-to-this-repo> <path-to-qmk-firmware>/keyboards/saifymatteo`
2. Windows - `New-Item -ItemType SymbolicLink -Force -Path <path-to-qmk-firmware>\keyboards\saifymatteo -Target <path-to-this-repo>`

### VS Code Setup

Follow this [guide](https://docs.qmk.fm/other_vscode). To summarise, these are what you need:

1. [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)

To configure, first need to compile to generate the `compile_commands.json`

Run this:

```bash
# Spender
qmk compile -kb saifymatteo/spender/firmware -km vial --compiledb

# Tractyl Manuster
qmk compile -kb saifymatteo/tractyl_manuster/firmware/rp2040 -km vial_rp2040 --compiledb
```

Then in VS Code, run these command palette in order:

1. `clangd: Download Language Server` - only needed to run once after extension installed
2. `clangd: Restart Language Server`

## Compiles & Flashing

### Spender

To compiles, run these:

```bash
# Compiles
make saifymatteo/spender/firmware:vial

# Flash
qmk flash saifymatteo_spender_firmware_vial.hex --mcu AT90USB1286
```

Then enter bootloader and it will auto flash

### Tractyl Manuster

To compiles, run these:

```bash
# Compiles
make saifymatteo/tractyl_manuster/firmware/rp2040:vial_rp2040
```

Then enter bootloader and copy paste `saifymatteo_tractyl_manuster_firmware_rp2040_vial_rp2040.uf2` into RP2040 drive
