# vi_pedal
Input / Command - Mode Selection via Foot-Pedal to Teensy

Very simple idea, stolen from someone ( I cant remember where and whom )
You have a foot-pedal and can send keystrokes with this foot-pedal to your PC (via USB-HID)
In this case it is a vi-pedal:
- When pressing the pedal a "i" is sent once and you are in insert-mode
- when releasing the pedal a ESC is sent once and you are in command-mode 
Thats it.

As usual in my projects (shooting with canons to sparrows...) I used a Teensy.
Wiring is rather simple:
```
    SW               --------------- 
----/ ------ GND ----|             |
|                    |    Teensy   |------- USB to PC 
-------------12 -----|             |
                     ---------------
```
Have fun
