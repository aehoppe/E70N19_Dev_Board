# E70N19_Dev_Board
 Repository for developing an ATSAME70N19-based dev board for Eclectronics FA 2017

## Brief Description of Board Design

Currently the board is designed to fit onto a 10cm X 10cm PCB. We will be using female header pins, much like an Arduino, on opposite edges of the PCB. 

## Changes to Schematic & BOM

There were no changes to the BOM.

The schematic had a few modifications based on feedback we received.

- Adding a voltage divider to TPS2112A to prevent brown out
- Added load capacitors to our RTC crystal
- Added a 10uF to BM71
- Added power LED to show status of power
- Changed nRST button to drive it to ground instead of power
- Added 30Ohm resistors to USB data lines
- Added connections to ground, 3v3 and VBUS to connectors
