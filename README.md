ddr_pad_controller
==================

Arduino Dance Dance Revolution Controller

I had an Arduino sitting around from forever ago and decided to try to revive a knock-off DDR Mat that had a bad controller box.

To use this, you need a few things:

1. The bounce2 library: https://github.com/thomasfredericks/Bounce-Arduino-Wiring
2. The ability to flash your Arduino to a HID Keyboard device (See: http://mitchtech.net/arduino-usb-hid-keyboard/)
3. A DDR Mat that you would like to use via USB on a computer.

Once you have the Bounce2 library installed and have figured out the flash to HID and back dance, load the code to your arduino, hook up the ground and buttons wires to the pinouts listed in the .ino file and it may work for you as well.
