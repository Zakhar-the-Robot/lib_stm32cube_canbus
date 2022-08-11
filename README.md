# lib_stm32cube_canbus


[![Main - Page](https://img.shields.io/badge/Project-Zakhar%20the%20Robot-yellow)](https://zakhar-the-robot.github.io/doc/ "See the Project Main Page") [![Main - Page](https://img.shields.io/badge/Sources-Zakhar%20the%20Robot-blue)](https://github.com/Zakhar-the-Robot "See Project Sources on Github")
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Poorly implemented qCAN library for stm32. Supported only a presence message and message transmission.

## Hardware

- Tested with stm32f4.
- Uses hardcoded `hspi2` for communication.

## How to build

- Configure your Stm32Cube firmware to use SPI2 for communication.
- Set up the project to use FreeRTOS.
- Add mk-file to your Makefile (e.g. `include Libraries/lib_stm32cube_canbus/lib_stm32cube_canbus.mk`)

## How to use

- Start the main task `qcan_start(DEVICE_ID);` (DEVICE_ID: 0...7)
- Transmit can messages `qcan_transmit(&txMessage);`
