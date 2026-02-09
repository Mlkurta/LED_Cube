# LED Cube

<img src="https://github.com/user-attachments/assets/7b32e9a4-b581-448a-aa7e-f3892f88abc3" width="400" >

## About
This is a repository for an 8x8x8 RGB LED cube. This cube was originally designed and created by Kevin Darrah.  
More info about it is located here: https://www.kevindarrah.com/?p=1424

The project has been revised to work with an ESP32 (Devkit C in this case).  This MCU allows much more flash memory (4 MegaBytes vs 32 KB),
32 bit, dual-core high performance with 240 MHz clock (vs 8 bit single core 16 MHz), and 520 KB SRAM (vs 2KB). It also features Bluetooth / WiFi / ESP-Now capability
if you would like to control it remotely.

## How to setup
The recommended way (simplest) to get the files is by downloading the files all at once in a zip file.  You can do a git clone if you'd like as well, especially if you'd like to contribute to the repo.

Drop the files into a folder, within the folder that contains your Arduino sketches.  This is usually /username/Documents/Arduino if using Windows.

Next, you'll want to install the ESP-32 drivers in the Arduino IDE. Open Arduino IDE, open preferences, then in the additional boards manager URL box, paste this:
https://espressif.github.io/arduino-esp32/package_esp32_index.json
...if you have another links in there for other boards, leave them and separate them with a comma. Press OK and the required files will begin to download.

<img width="525" height="663" alt="Screenshot 2026-01-13 184716" src="https://github.com/user-attachments/assets/3307cdb6-30eb-47ee-91bf-2bc2e2ad812c" />


Next, in the main IDE window, open the "All_Anims_ESP.ino" file. The file should open and the top should populate with all of the additional files, provided they are in 
the same directory.

Before sketches can be loaded onto the device, a few settings under the "tools" dropdown need to be configured:


<img width="371" height="1020" alt="Screenshot 2026-01-13 184806" src="https://github.com/user-attachments/assets/d2c849cd-c6ff-48c7-b932-e970b124a3f5" />

## Making an animation

You can do this one of two ways: 1. Write your animation fully in the main "All_Anims_ESP.ino" file, in the void loop() portion, or 2. Create a new filename that defines your animation function, that the main program will call. This is generally preferred, but option 1 can work for a quick test if you have access to the cube.

Here's how you make the new filename + function.

Create a filename:

Open Arduino IDE and the "All_Anims_ESP.ino" file. In the top right, click the three dots and select "New Tab". Enter your desired filename, with a .h at the end. 

<img width="700" height="624" alt="Screenshot 2026-02-08 182315" src="https://github.com/user-attachments/assets/7590e464-d863-44c0-855f-4997a37e876f" />

In your new file, type "#pragma once" at the top and "include "LED.h"" below it.   

<img width="700" height="548" alt="Screenshot 2026-02-08 182714" src="https://github.com/user-attachments/assets/c9cc40c8-dfef-48f8-bbbc-52f5fa548252" />

Now you can create your animation function, just how you would any C function.  It's a good idea to create some variables for the cube's levels, rows and columns. The typical convention is i, j, and k respectively. Many animations will rely heavily on loops.

If the IEEE group is to ever make several of these animations and we want them to all show one right after another.... it's best to put a time constraint on your function (see example at the bottom) or have it iterate through a finite number of times so the other animations show.

Easiest way to keep time is to declare an unsigned long variable and say "youVariable = millis()" at the start. This creates a time stamp. You can then check that timestamp within your code. There already is a variable declared in the main file called "start"....but to access it in your file, you have to use the (C syntax) extern keyword, e.g. "extern unsigned long start;"

Just know that if you use the "while( millis() - start < 20000 ){" convention, you have to keep in mind both your time constraint and how much it takes to run through one time. If you put 20 seconds in your while() condition, and you have a 1 second delay between lighting all 512 LEDs sequentially, well your program is going to take 512 seconds minimum unless you're more clever about it.

Example program below that writes LEDs individually, one at a time, until they are all lit. It's really pointless to put a while loop time constraint on it, because this animation looks exactly the same every time it runs through, and no LEDs are turned off, so you don't even know it's running a second, third, n times through... but it's there anyway just to show what it looks like.


<img width="1087" height="1179" alt="Screenshot 2026-02-08 184650" src="https://github.com/user-attachments/assets/0b58bacb-28e4-4197-a6c6-84f9a9f15c24" />

## Integrating the animation in the main file.

Step 1.  In "All_Anims_ESP.ino", near the top,  Type #include "YourFilename.h"

<img width="600" height="682" alt="Screenshot 2026-02-08 182340" src="https://github.com/user-attachments/assets/5b7222d8-c648-4a27-8ad3-fa740bc79348" />

Step 2. In the void loop() function, around line 350 or so, place the name of your animation function:

<img width="600" height="488" alt="Screenshot 2026-02-08 182451" src="https://github.com/user-attachments/assets/680faae9-b86d-450d-b113-99685ab57dbf" />

Good practice is to add clean(); after your function... this turns all LEDs off before the next animation (or your animation) starts.

Provided your code compiles without errors, your animation should work. It may not do what you want it to do, but it will "work".

