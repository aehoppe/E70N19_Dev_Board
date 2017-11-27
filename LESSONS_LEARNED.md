---
geometry: margin=1cm
---
# Lessons Learned

This project was a mixed bag for validating subsystems for our final project design. We had little success with our MCU and BLE module, but we were able to prove out our power management and LCD screen.

## Microcontroller

For this project we chose the ATSAME70N19 Arm Cortex-M7 microcontroller, with the hopes that it would be easy to work with and give us a lot of power and flexibility. We were familiar with Atmel ATmega 8-bit microcontrollers, and we thought this would give us an advantage moving up to 32-bit ARM core Atmel devices. We also selected this device for its purported ease of programming due to its USB-capable default bootloader. However, despite doing a bit of research before-hand about how to program the chip, we were unaware that the ATSAM series is actually known for having pretty awful software support.

We found this out when we got our board back and tried to actually program it. The bootloader that the chip comes with allowed for us to connect to the device, but when we tried to upload code nothing happened. We had a compiling firmware image, but we weren't able to get the device to respond in a predictable way. It was also difficult to find any documentation on memory mapping to debut that issue, nor could we find much top-leve documentation on how to do anything at all. We probably wouldn't have figured out how to get any code compiling without the help of the Atmel-START webapp that provided us with a massive directory of boilerplate code and drivers. We were able to build a main function that compiled, but we were defeated trying to debug the uploading process.

After spending some time trying to get anything working, we decided to abandon the efforts and focus on selecting another MCU. Using the lessons we learned from struggling with obstruse ATSAM documentation, we chose a manufacturer who is known for great programming support (STM) and which has a lot of firmware documentation. We made sure to pick a specific model with a lot of community support as well.


## BLE Module

Unfortunately we ran into similar issues with the BM71 bluetooth module as with our ATSAM microcontroller: we implemented the hardware correctly, but we were unable to program/use it. By default, the BM71 is configured to communicate with other BM71s using a proprietary protocol. In order to change this, you have to use a proprietary Windows program to modify device configuration. However, we hadn't foreseen this difficulty, and didn't design our hardware to allow the module to be connected to a computer separately.

We ended up deciding to spec an alternative BLE module which happened to have the exact same castellated footprint (and is probably the same chip with different firmware). This new module, however, has an open configuration spec, which will allow us to configure it using our MCU.

This is another instance of us learning how important it is to research *everything we need to use* (especially how to program it) for a component before deciding on something.

## Power Circuitry

The main saving grace of this board was that we did get the power-multiplexing circuitry worked out. There were a few issues at first, such as the 3.3V line being a saw-tooth 1.8V signal, but we traced it back to a simple schematic error and resolved it with rework. In the end, we were able to have a fully functional 5V to 3.3V regulator, a multiplexer that switched between USB and LiPoly battery, as well as an independent battery charger. This system wasn't particularly complicated or risky, but we succeeded in proving out a reusable subsystem for future designs.

## Testing our Project 3 LCD Screen

The last use we found for our board is using it to test our LCD screen for our 3rd project. The pitch for our LCD screen connector was 0.5mm, and the pitch for our MCU was also 0.5mm, so it was possible to put our connector on the footprint of the MCU. It was also lucky that our connector had 10 pins which needed to be different, and there was exactly 1 place where the MCU footprint had 10 pins that were contiguous, different, and routed to other parts of the board where we could connect a wire to them.

Thus, we were able to connect our LCD screen to an Arduino using our board and some trickery, and test the functionality. Although we did not get a perfect image displayed, we did find a lot of example code for working with our specific line of Sharp LCD screens, and we were able to display some scrambled lines adn pixels. We believe the reason we did not get a nice image is that we did not toggle the EXTCOMIN pin at a minimum of 1Hz which prevents charge buildup on the LCD screen. However, we did get enough information to convince ourselves that we could work with the screen for our final project.
