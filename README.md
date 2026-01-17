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
