# Implementing a LwIP and FreeRTOS™ v1 UDP echo server on the STM32F7 series

## Summary
This guide explains how to implement a LwIP and FreeRTOS™ v1 UDP echo server on the STM32F7 series, focusing on the STM32F767 MCU. Complete steps and detailed instructions are provided in this knowledge base [article](https://community.st.com/t5/stm32-mcus/implementing-a-lwip-and-freertos-v1-udp-echo-server-on-the/ta-p/780261).

## Hardware
This example is provided for the following MCU and can be tailored for any other F7 series microcontrollers with slight memory address variations:
- [NUCLEO-F767ZI](https://www.st.com/en/microcontrollers-microprocessors/stm32f767zi.html#overview)

## Software
- [STM32CubeIDE v1.18.1](https://www.st.com/en/development-tools/stm32cubeide.html)
- [STM32CubeMX v6.14.1](https://www.st.com/en/development-tools/stm32cubemx.html)
- Packet generator, for example, [Packet Sender](https://packetsender.com/download)
- (Optional) DHCP server, for example, [Tftpd32](http://tftpd32.jounin.net/) 

## How to use this example
Compile the code. Using an application or utility like **Packet Sender**, you can test whether the server is successfully receiving UDP test messages. The board can obtain its IP address in two ways: either dynamically from a DHCP server running on the testing computer or network using, for example, Tftpd32, or through a statically defined IP address. In this example, we format a UDP packet to send to port 7 using the IP address, whether it is assigned by the DHCP server or manually configured.
![demo](_htmresc/Demo1.png)
After this, you should see that the response echoed back by the UDP server running on the board, confirming that the server is functioning correctly and everything is working as intended.
![demo](_htmresc/Demo2.png)

## Additional resources
Here are some useful links to assist with development using the LwIP middleware within ST's ecosystem:
- [UM1713: Developing applications on STM32Cube with LwIP TCP/IP stack](https://www.st.com/content/ccc/resource/technical/document/user_manual/65/e8/20/db/16/36/45/f7/DM00103685.pdf/files/DM00103685.pdf/jcr:content/translations/en.DM00103685.pdf "https://www.st.com/content/ccc/resource/technical/document/user_manual/65/e8/20/db/16/36/45/f7/dm00103685.pdf/files/dm00103685.pdf/jcr:content/translations/en.dm00103685.pdf")
- [LwIP documentation](https://www.nongnu.org/lwip/2_1_x/index.html)
- [GitHub: STMicroelectronics](https://github.com/STMicroelectronics)
- [UM1974: STM32 Nucleo-144 boards (MB1137)](https://www.st.com/resource/en/user_manual/um1974-stm32-nucleo144-boards-mb1137-stmicroelectronics.pdf "https://www.st.com/resource/en/user_manual/um1974-stm32-nucleo144-boards-mb1137-stmicroelectronics.pdf")
- [RM0410: STM32F76xxx and STM32F77xxx advanced Arm®-based 32-bit MCUs](https://www.st.com/resource/en/reference_manual/rm0410-stm32f76xxx-and-stm32f77xxx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf "https://www.st.com/resource/en/reference_manual/rm0410-stm32f76xxx-and-stm32f77xxx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf")

## Troubleshooting
Please refer to the [CONTRIBUTING.MD](CONTRIBUTING.MD) guide.
