# vi_pedal
Input / Command - Mode Selection via Foot-Pedal to Teensy

Very simple idea, stolen from someone ( I couldn't remember where but today I stumbled across the blog-post once more with the nice german title:
[Warum vim so geil ist](https://www.tobscore.com/warum-vim-so-geil-ist) )
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
That was the original idea.
As it turned out, a "proper" pedal, which is intended to be used, does not use a normal switch.
Instead it is using a infrared light barrier with a IR-LED and a Phototransistor.
So the wiring now looks like this:


```
+----------+-------VCC-------+
|          |                 |
R2         R1       +--------+-------+
|          |        |                |
|          +----12--+     TEENSY     |------- USB to PC
D1 --->    |        |                |
|  --->    T1       +--------+-------+
|          |                 |
+----------+------GND--------+

```

So now the polarity is inverted and the input-pin does not need a pullup.
The IR-Diode, Fototransistor and the two resistors are used as they have been in the original pedal,
which already was a USB-Pedal. But unfortunately it was not able to produce different keystrokes on push and and on release.
So the Teensy with the "intelligence" is needed.


Have fun
