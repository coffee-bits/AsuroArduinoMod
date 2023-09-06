# AsuroArduinoMod
> This project is using an Arduino pro micro instead of the original Atmega8L

I own a very old robot education platform called [ASURO](https://de.wikipedia.org/wiki/ASURO)

The main problem using this good old little thing was the old Atmega8L microcontroller platfofm that is programed by avrgcc or Atmel Studio (tm) and loaded by a serial bootloader via an IR light communication channel.

I wanted to bring this in the next level of microcontroller platforms since the modern versions are much easier to use and program. Most of the new platforms unfortunately are using 3.3V but the Asuro has been designed for a logic level of 5V.

My choice was then a Arduino pro micro which uses 5V logic level, has an USB serial interface for communication and program download and its pinning and functionality is quite similar to the Atmega8L.

## Goal of the project
- Replace the old Atmega8L with a "modern" but similar platform: Arduino pro micro instead of the Atmega8L
- create a base system using all the hardware functionalities provided by the Asuro platform
- create a communication interface on the serial port with a simple API procotol to enable other controllers with, for example a WIFI interface or camera, to control the robot platform

## Problems so far
### The old motors are dead
I had to replace the old motors with newer ones. I found a nice and cheap all in one solution...that does not fit and needs a holding frame. So I constructed a frame prototype:

![Asuro Robot Motor Hold](doc/Asuro Robot Motor Hold.jpg)