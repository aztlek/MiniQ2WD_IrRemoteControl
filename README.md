# MiniQ2WD_IrRemoteControl

This is a program for the MiniQ 2WD robot, it is used to control the robot
with the infrared remote control that comes in the kit. But the control that
is achieved with this program is much more complete than the example robot
program. Some of the additional features are:

* The turns of the robot are more controllable.
* Turns can also be done when the robot is moving forward, backward, or stopped.
* The speed of the robot can be increased and decreased.

## The robot

The MiniQ 2WD robot is based on an Arduino Leonardo. It is manufactured by
DfRobot https://www.dfrobot.com and its product page is https://www.dfrobot.com/product-555.html.
According to the manufacturer:

> This upgraded version of MiniQ 2WD Kit comes with new Arduino Leonardo
  controller but also integrates useful modules such as buzzer, RGB LED,
  photosensitive diode, infrared LED receiver and compass.

###  Features

Also according to the manufacturer's features they are:

* ​Micro USB for download the code(bootloader: Leonardo)
* A compass inside
* WS2812 RGB LED for controlling the color by only one pin
* Soft buttons for giving you more comfortable feeling
* Two Infrared transmitters and 1 infrared receiver for obstacle detection and
  avoidance. Also includes an IR remote control to easily control its features
  remotely
* I2C port(Gadgeteer) for communicate with other devices

## Install IRremote library

This program uses the * IRremote * library whose original page
is https://z3t0.github.io/Arduino-IRremote/. But * MiniQ2WD_IrRemoteControl*
uses the version found on the product page https://www.dfrobot.com/product-555.html
in the title * Documents * in the link [IR Remote control sample code](https://github.com/Arduinolibrary/DFRobot_MiniQ_2WD_V2.0_ROB0081/raw/master/IR_Remote_Control.rar).

To install the library, follow these steps:

### Install in Debian Stretch (9)

In shell:

```bash
su -
wget https://github.com/Arduinolibrary/DFRobot_MiniQ_2WD_V2.0_ROB0081/raw/master/IR_Remote_Control.rar
unrar-free IR_Remote_Control.rar
cd IR_Remote_Control/library/
cp -r IRremote /usr/share/arduino/libraries
```

In Arduino IDE 2.1.0.5 (version in Debian Stretch): ```arduino Sketch -> Import library -> Add library```.
Select the library in ```/usr/share/arduino/libraries```

## License

Copyright (C) 2020 Luis Alejandro Bernal Romero (Aztlek)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
