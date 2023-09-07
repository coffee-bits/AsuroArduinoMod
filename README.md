- [AsuroArduinoMod](#asuroarduinomod)
  - [Goal of the project](#goal-of-the-project)
  - [Problems so far](#problems-so-far)
    - [The old motors are dead](#the-old-motors-are-dead)
  - [State of the project](#state-of-the-project)
    - [Software](#software)
    - [Hardware](#hardware)


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

![Asuro Robot Motor Hold](/doc/Asuro%20Robot%20Motor%20Hold.png)

## State of the project
### Software
The software is currently in experimentl state. All Asuro interfaces are going to be testet with the new connections on the Arduino pro micro. The interface driver functions are going to be rewritten without the usage of the original api.

### Hardware
> connections
All hardware interfaces of the Asuro have been connected to according pins of the Arduino pro micro.

| Pin | Asuro                                                                           | Arduino | Pin | Asuro                                                                                               | Arduino |
| --- | ------------------------------------------------------------------------------- | ------- | --- | --------------------------------------------------------------------------------------------------- | ------- |
| 1   | Rset                                                                            | \-      | 15  | Motor 1 PWM                                                                                         | D6      |
| 2   | IR Receiver<br>SFH5110-36                                                       | D2      | 16  | Motor 2 PWM                                                                                         | D5      |
| 3   | IR Diode -<br>SFH 415-U                                                         | GND     | 17  | IR Diode +<br>SFH 415-U                                                                             | D10     |
| 4   | Color LED                                                                       | D7      | 18  | Motor 2_T7/8                                                                                        | D13     |
| 5   | Taster Int                                                                      | D3      | 19  | Motor 2 T5/6                                                                                        | D9      |
| 6   | Motor 1_T1/2                                                                    | D11     | 20  | AVCC                                                                                                | n.a.    |
| 7   | VCC                                                                             | 5V      | 21  | Aref                                                                                                | AREF    |
| 8   | GND                                                                             | GND     | 22  | AGND                                                                                                | n.a.    |
| 9   | Quarz                                                                           | \-      | 23  | Phototransistor T12 analog<br>LPT80A, Fototransistor, farbloses Gehäuse<br>LED D16 +<br>LED 5mm rot | A0      |
| 10  | Quarz                                                                           | \-      | 24  | Phototransistor T11<br>LPT80A, Fototransistor, farbloses Gehäuse<br>LED D15 +<br>LED 5mm rot        | A1      |
| 11  | Motor 1_T3/4                                                                    | D12     | 25  | Phototransistor T10 analog<br>SFH 300 Fototransistor 5mm                                            | A2      |
| 12  | LED Line                                                                        | D4      | 26  | Phototransistor T11 analog<br>SFH300, Fototransistor 5mm                                            | A3      |
| 13  | LED 13/14 +<br>IRL80A IR-LED rosafarbenes Gehäuse<br>LED 15/16 -<br>LED 5mm rot | D7      | 27  | Taster Analog Input                                                                                 | A4      |
| 14  | Color LED                                                                       | D8      | 28  | Spannungsteiler 12k/10k                                                                             | A5      |

> Prototype state

![Asuro Prototype 1.1](/doc/AsuroRework1.jpg)
![Asuro Prototype 1.2](/doc/AsuroRework2.jpg)
![Asuro Prototype 1.3](/doc/AsuroRework3.jpg)