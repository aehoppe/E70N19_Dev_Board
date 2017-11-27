---
geometry: margin=1cm
---
# Lessons Learned

## Microcontroller

For this project we chose the ATSAME70N19 Arm Cortex-M7 microcontroller, with the hopes that it would be easy to work with and give us a lot of power and flexibility. However, despite doing a bit of research before-hand about how to program the chip, we were unaware that the ATSAM series is actually known for having pretty awful software support. 

We found this out when we got our board back and tried to actually program it. The Bootloader that the chip comes with allowed for us to connect to the device, but when we tried to upload code nothing happened. It was also difficult to find any documentation on how to do anything, and we probably wouldn't have figured out how to get any code compiling without the help of the ATmel-Start webapp (which was hard to find as well).

After spending some time trying to get anything working, we decided to abandon the efforts and focus on selecting another MCU. Using the lessons we learned from the ATSAM, we chose a chip from a manufacture who is known for great programming support (STM) and which has a lot of documentation on how to program.


## BLE Module

Sadly, the BLE module we selected (BM71) had the same issue as the ATSAM in that we could not figure out a way to easily work with it. By default, the BM71 is configured to communicate with other BM71s using a proprietary protocol. In order to change this, you have to use a proprietary program on Windows that will let you change the configurations. However, this would require a bit more hardware-planning beforehand in order to allow the module to be connected to the computer. 

We ended up deciding to spec an alternative BLE module which happened to have the exact same castellated footprint (and is probably the same chip with different firmware). This new module, however, has an open configuration spec, which will allow us to configure it using our MCU.

This is another instance of us learning how important it is to research *everything we need to use* (especially how to program it) for a component before deciding on something.

## Power Circuitry

The main saving grace of this board was that we did get the power-multiplexing circuitry worked out. There were a few issues at first, such as the 3.3V line being a saw-tooth 1.8V signal, but we figured them out by doing some simple re-work. In the end, we were able to have a fully functional 5V to 3.3V regulator, a multiplexer that switched between USB and battery, as well as a battery charger. None of these are particularly difficult to do, but the fact that it was the only system that worked makes it important.

## Jankily Testing an LCD Screen

The last use we found for our board is using it to test our LCD screen for our 3rd project. The pitch for our LCD screen connector was 0.5mm, and the pitch for our MCU was also 0.5mm, so it was possible to put our connector on the footprint of the MCU. It was also lucky that our connector had 10 pins which needed to be different, and there was exactly 1 place where the MCU footprint had 10 pins that were contiguous, different, and routed to other parts of the board where we could connect a wire to them.

Thus, we were able to connect our LCD screen to an Arduino using our board and some trickery, and test the functionality. Although we did not get a perfect image displayed, we did find a lot of example code for working with the LCD screen, and we got random lines to display. We believe the reason we did not get a nice image is that we did not toggle the EXTCOMIN pin at a minimum of 1Hz which prevents charge buildup on the LCD screen. However, we did get enough information to convince ourselves that we could work with the screen for our final project.

