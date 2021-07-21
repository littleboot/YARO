# Firmware STM32
The controller board contains an STM32F1 series processor from STMicroelectronics (ST). The firmware is written in the STM32CubeIDE, a free IDE provided by ST. The build in CubeMx project configurator has been used to setup the project and initialize the peripherals using the HAL library (Hardware Abstraction Layer). If you are new to STM32 the HAL library is quite difficult to understand, it does not always work the way you think it should. I recommend reading the Reference manual and the chapter about the peripheral you are interested in (Even if you do not fully understand). After you have read the chapter you will have an idea which steps the HAL library should perform which helps a lot when debugging when something is not working.

ST also provides firmware examples and documentation both are part of the ["STM32CubeF1"](https://www.st.com/en/embedded-software/stm32cubef1.html) firmware package.


## Software
I have used the following (free) tools for this project, their are however other tools available that can do the same.
*  [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) (Development Environment)
* [STM32CubeProg](https://www.st.com/en/development-tools/stm32cubeprog.html) (Programming tool)
* [YAT terminal](https://sourceforge.net/projects/y-a-terminal/) (Terminal application)

## Hardware
No additional hardware is required for programming when using the serial bootloader. However I strongly recommend getting a STlink programmer (Stlink V2 V3 or V3-mini) when doing some development. These are not expensive and enable you to set breakpoints, read/write the peripheral registers and more. Its also much faster to program the device via SWD as compared to the serial bootloader. [Were to buy?](https://octopart.com/search?q=STLINK&currency=USD&specs=0)


## Programming
The MCU can be programmed using the build in bootloader or using the SWD (serial Wire Debug) interface.

### Serial bootloader
All STM32 processors have a build in [serial bootloader](https://www.st.com/resource/en/application_note/cd00264342-usart-protocol-used-in-the-stm32-bootloader-stmicroelectronics.pdf). To enter the bootloader on this STM32F103 it's boot0 pin must be low at startup. Once the device has entered the bootloader new firmware can be programmed via UART.

**To enter the bootloader on the controller board**
1. Press and hold the BOOT0 button
2. Press and release the Reset button
3. Release the BOOT0 button

**Entering the bootloader from software**  
The serial bootloader can also be entered via software by jumping to it's memory location. I have added a serial command to jump to the bootloader. This is quite handy when you can't access the buttons or the SWD pins when the PCB is inside an enclosure.

**Programming via the serial bootloader**  
Connect the controller board to your PC via a mini USB cable. Next
open "STM32CubeProgrammer", select the UART interface and correct COM port and connect to the device, select the new firmware file and start programming.

## SWD Programming
1. The STM32CubeIDE supports the STLINK, pressing the launch button will compile your project and program the device.
Pressing the debug button will do the same but starts a debug session after programming.
2. Same as the "Programming via the serial bootloader" instruction but you will have to select the STLINK as interface.

# Firmware Nextion Display (HMI)
The display used for this project is a Nextion 3.2" display (NX4024T032). It communicates with the STM32 on the controller board via UART. Development, testing and programming of the GUI can be done using the Nextion Editor.

## Software
* [Nextion Editor](https://nextion.tech/nextion-editor/)
