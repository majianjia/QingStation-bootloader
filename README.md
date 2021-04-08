# QingStation-bootloader

This repo is for the bootloader that used by QingStation. 
Details in [QingStation project (root)](https://github.com/majianjia/QingStation) and [QingStation firmware (application)](https://github.com/majianjia/QingStation-Firmware)

It is based on [RT-Thread Nano](https://github.com/RT-Thread/rtthread-nano) and [stm32-bootloader](https://github.com/akospasztor/stm32-bootloader).

# Basic

The current function is very basic, and is modified from the stm32-bootloader's example project. 
It can copy the binary file from SD card to application section. 

The application offset is `0x10000`, `64kB`.
And the whole section until the end of flash will be wiped out completely. 
It is not ideal yet. I am thinking of using only half of the flash for application and the other half for backup firmware, and use a few kb to store configurations. 

Currently no CRC checksum, to make it easy to use.

Information also printed through the uart in the debugging port (UART3), baud rate = `115200`.

**How to use:**

- Press `BTN` and reset the device. (Blue and Red LED on for `1` sec) 
- When BLUE flashing, release the `BTN`, will search `rtthread.bin` in SD card's root folder. (`<4`sec)

During updating, RED on means erasing flash, RED on + BLUE flashing means programming. 

After updating, RED off, BLUE flashing means booting up the Application. 

> Keep pressing `BTN` over `4` second will enter STM32 system bootloader  

# Contact
Please refer to [QingStation project (root)](https://github.com/majianjia/QingStation)

