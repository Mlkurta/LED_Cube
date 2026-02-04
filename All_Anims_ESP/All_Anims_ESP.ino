
/*
The 8x8x8 RGB LED Cube

by Kevin Darrah
www.kevindarrah.comcl
kevin@kevindarrah.com

Latest
V12 04/17/2013

Release Notes:
V11
- Fixed bug with BAM timing
- Moved Blank pin setup to ISR so pins are dead until they are written to

V12
bitwise operation to set pins LOW was incorrect
should be PORTx &= ~(1<<pinNumber);

Disclaimer:
Not a professional LED cube builder, this is how I did it, and this is my cube


Revised by Michael Kurta
V2.0
06/22/2022

V2.1
1/13/2026

*/
#include <SPI.h>// SPI Library used to clock data out to the shift registers

#include "Bouncy.h"
#include "BoxGrow.h"
#include "Bresenham.h"
#include "Color_wheel.h"
#include "Cornerboxes.h"
#include "Cornerpanel.h"
#include "Firework.h"
#include "Flasher.h"
#include "Folder.h"
#include "Harlem_shake.h"
// Step 1. put here: #include "Your_filename.h"
#include "example.h"
#include "LED.h"
#include "Letter_display.h"
#include "Lightlattice.h"
#include <math.h>
#include "Rain.h"
#include "Rainbow_fountain.h"
#include "Resonance.h"
#include "Sidecoil.h"
#include "Sinewave.h"
#include "Spiral.h"
#include "Statick.h"
#include "Wipe_out.h"

// ESP32 DevkitC-V4 specific pins
#define latch_pin 27// can use any pin you want to latch the shift registers                              / Green
#define blank_pin 4// same, can use any pin you want for this, just make sure you pull up via a 1k to 5V  / Yellow
#define data_pin 23// used by SPI, must be pin 11                                                         / Orange
#define clock_pin 18// used by SPI, must be 13                                                            / Blue
#define COLUMNS 100                                                                                       // Brown = GND, Red = 5V
//#define NUMWORKS 3
#define COLUMNSLAT 64
#define COORDS 2


hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

//***variables***variables***variables***variables***variables***variables***variables***variables
//These variables are used by multiplexing and Bit Angle Modulation Code
SPIClass * vspi = NULL;

int shift_out;//used in the code a lot in for(i= type loops
byte anode[8];//byte to write to the anode shift register, 8 of them, shifting the ON level in each byte in the array

//This is how the brightness for every LED is stored,  
//Each LED only needs a 'bit' to know if it should be ON or OFF, so 64 Bytes gives you 512 bits= 512 LEDs
//Since we are modulating the LEDs, using 4 bit resolution, each color has 4 arrays containing 64 bits each
byte red0[64], red1[64], red2[64], red3[64];
byte blue0[64], blue1[64], blue2[64], blue3[64];
byte green0[64], green1[64], green2[64], green3[64];
//notice how more resolution will eat up more of your precious RAM

int level=0;//keeps track of which level we are shifting data to
int anodelevel=0;//this increments through the anode levels
int BAM_Bit, BAM_Counter=0; // Bit Angle Modulation variables to keep track of things

//These variables can be used for other things
unsigned long start;//for a millis timer to cycle through the animations
unsigned long sTwo;
short endY = 0;
short endX = 0;
short eY = 0;
short eX = 0;
short eZ = 0;
const short colorWheel[42] = {15,0,0,15,8,0,15,15,0,8,15,0,0,15,0,0,15,8,0,15,15,0,8,15,0,0,15,8,0,15,15,0,15,15,0,8,15,15,15,15,15,15};
const short gridLat[COLUMNSLAT][COORDS] = {// i, j, then k columns
  {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},
  {0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},
  {0,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},
  {0,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},
  {0,4},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},
  {0,5},{1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},
  {0,6},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{7,6},
  {0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7},{7,7}};

const short grid[COLUMNS][COORDS] = {// i, j, then k columns
  {3,3},{4,3},{4,4},{3,4},
  {2,2},{3,2},{4,2},
  {5,2},{5,3},{5,4},
  {5,5},{4,5},{3,5},
  {2,5},{2,4},{2,3},
  {1,1},{2,1},{3,1},{4,1},{5,1},
  {6,1},{6,2},{6,3},{6,4},{6,5},
  {6,6},{5,6},{4,6},{3,6},{2,6},
  {1,6},{1,5},{1,4},{1,3},{1,2},
  {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},
  {7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},
  {7,7},{6,7},{5,7},{4,7},{3,7},{2,7},{1,7},
  {0,7},{0,6},{0,5},{0,4},{0,3},{0,2},{0,1},
  {-1,-1},{0,-1},{1,-1},{2,-1},{3,-1},{4,-1},{5,-1},{6,-1},{7,-1},
  {8,-1},{8,0},{8,1},{8,2},{8,3},{8,4},{8,5},{8,6},{8,7},
  {8,8},{7,8},{6,8},{5,8},{4,8},{3,8},{2,8},{1,8},{0,8},
  {-1,8},{-1,7},{-1,6},{-1,5},{-1,4},{-1,3},{-1,2},{-1,1},{-1,0}
};

const int w[2][8] = {
  {0,1,2,3,4,5,6,7},
  {7,6,5,4,3,2,1,0}
};

const byte A[6] =   {B00011110, B00101000, B01001000, B00101000, B00011110, B00000000};
const byte B[6] =   {B01111110, B01010010, B01010010, B00110010, B00001100, B00000000};
const byte C[6] =   {B00111100, B01000010, B01000010, B01000010, B01000010, B00000000};
const byte D[6] =   {B01111110, B01000010, B01000010, B00100100, B00011000, B00000000};
const byte E[6] =   {B01111110, B01010010, B01010010, B01010010, B01000010, B00000000};
const byte F[6] =   {B01111110, B01010000, B01010000, B01010000, B01000000, B00000000};
const byte Four[6]= {B01111000, B00001000, B00001000, B01111110, B00001000, B00000000};
const byte G[6] =   {B00111100, B01000010, B01000010, B01001010, B00101100, B00000000};
const byte H[6] =   {B01111110, B00010000, B00010000, B00010000, B01111110, B00000000};
const byte I[6] =   {B01000010, B01000010, B01111110, B01000010, B01000010, B00000000};
const byte J[6] =   {B01001000, B01000100, B01111100, B01000000, B01000000, B00000000};
const byte K[6] =   {B01111110, B00001000, B00011000, B00100100, B01000010, B00000000};
const byte L[6] =   {B01111100, B00000010, B00000010, B00000010, B00000010, B00000000};
const byte M[6] =   {B01111110, B00100000, B00010000, B00100000, B01111110, B00000000};
const byte N[6] =   {B01111110, B00010000, B00001000, B00000100, B01111110, B00000000};
const byte O[6] =   {B00111100, B01000010, B01000010, B01000010, B00111100, B00000000};
const byte P[6] =   {B01111110, B01001000, B01001000, B01001000, B00110000, B00000000};
const byte Q[6] =   {B00111100, B01000010, B01001010, B01000110, B00111110, B00000000};
const byte R[6] =   {B01111110, B01001000, B01001000, B01001000, B00110110, B00000000};
const byte S[6] =   {B00100010, B01010010, B01010010, B01010010, B01001100, B00000000};
const byte T[6] =   {B01000000, B01000000, B01111110, B01000000, B01000000, B00000000};
const byte Two[6] = {B00100110, B00101010, B01001010, B01010010, B01100010, B00000000};
const byte U[6] =   {B01111100, B00000010, B00000010, B00000010, B01111100, B00000000};
const byte V[6] =   {B01110000, B00001100, B00000010, B00001100, B01110000, B00000000};
const byte W[6] =   {B01111110, B00000100, B00001000, B00000100, B01111110, B00000000};
const byte X[6] =   {B01000110, B00101000, B00010000, B00101000, B01000110, B00000000};
const byte Y[6] =   {B01000000, B00100000, B00011110, B00100000, B01000000, B00000000};
const byte Z[6] =   {B01000110, B01001010, B01010010, B01100010, B01000010, B00000000};
const byte Sp[6] =  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
const byte Exp[6] = {B00000000, B01111010, B01111010, B00000000, B00000000, B00000000};
byte scroll[22];
char phrase[21] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', '-', 'I', 'E', 'E', 'E', '-', 'M', 'E', 'M', 'B', 'E', 'R', 'S', '\0'};
int ii[26][8];

//ISR(TIMER1_COMPA_vect){//***MultiPlex BAM***MultiPlex BAM***MultiPlex BAM***MultiPlex BAM***MultiPlex BAM***MultiPlex BAM***MultiPlex BAM
void IRAM_ATTR onTimer(){
  portENTER_CRITICAL_ISR(&timerMux);


  digitalWrite(blank_pin, HIGH);//The first thing we do is turn all of the LEDs OFF, by writing a 1 to the blank pin
  //Note, in my bread-boarded version, I was able to move this way down in the cube, meaning that the OFF time was minimized
  //do to signal integrity and parasitic capcitance, my rise/fall times, required all of the LEDs to first turn off, before updating
  //otherwise you get a ghosting effect on the previous level

//This is 4 bit 'Bit angle Modulation' or BAM, There are 8 levels, so when a '1' is written to the color brightness, 
//each level will have a chance to light up for 1 cycle, the BAM bit keeps track of which bit we are modulating out of the 4 bits
//Bam counter is the cycle count, meaning as we light up each level, we increment the BAM_Counter

  if(BAM_Counter==8)
  BAM_Bit++;
  else
  if(BAM_Counter==24)
  BAM_Bit++;
  else
  if(BAM_Counter==56)
  BAM_Bit++;

  BAM_Counter++;//Here is where we increment the BAM counter

  switch (BAM_Bit){//The BAM bit will be a value from 0-3, and only shift out the arrays corresponding to that bit, 0-3
  //Here's how this works, each case is the bit in the Bit angle modulation from 0-4, 
  //Next, it depends on which level we're on, so the byte in the array to be written depends on which level, but since each level contains 64 LED,
  //we only shift out 8 bytes for each color
  case 0:
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(red0[shift_out]);
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(green0[shift_out]); 
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(blue0[shift_out]);
    break;
  case 1:
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(red1[shift_out]);
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(green1[shift_out]); 
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(blue1[shift_out]);
    break;
  case 2:
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(red2[shift_out]);
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(green2[shift_out]); 
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(blue2[shift_out]);
  break;
  case 3:
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(red3[shift_out]);
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(green3[shift_out]); 
  for(shift_out=level; shift_out<level+8; shift_out++)
  vspi->transfer(blue3[shift_out]);
  //Here is where the BAM_Counter is reset back to 0, it's only 4 bit, but since each cycle takes 8 counts,
  //, it goes 0 8 16 32, and when BAM_counter hits 64 we reset the BAM
    if(BAM_Counter==120){
    BAM_Counter=0;
    BAM_Bit=0;
    }
    break;
  }//switch_case

  vspi->transfer(anode[anodelevel]);//finally, send out the anode level byte

  digitalWrite(latch_pin, HIGH); //Latch pin HIGH
  digitalWrite(latch_pin, LOW); //Latch pin LOW
  digitalWrite(blank_pin, LOW); //Blank pin LOW to turn on the LEDs with the new data

  anodelevel++;//inrement the anode level
  level = level+8;//increment the level variable by 8, which is used to shift out data, since the next level woudl be the next 8 bytes in the arrays

  if(anodelevel==8)//go back to 0 if max is reached
  anodelevel=0;
  if(level==64)//if you hit 64 on level, this means you just sent out all 63 bytes, so go back
  level=0;
  pinMode(blank_pin, OUTPUT);//moved down here so outputs are all off until the first call of this function
  portEXIT_CRITICAL_ISR(&timerMux);
}//***MultiPlex BAM END***ISR END******MultiPlex BAM END***ISR END******MultiPlex BAM END***ISR END******MultiPlex BAM END***ISR END***




//****setup****setup****setup****setup****setup****setup****setup****setup****setup****setup****setup****setup****setup
void setup(){
vspi = new SPIClass(VSPI);

//Serial.begin(115200);// if you need it?
noInterrupts();// kill interrupts until everybody is set up


timer = timerBegin(0, 320, true);
timerAttachInterrupt(timer, &onTimer, true);
timerAlarmWrite(timer, 30, true);
timerAlarmEnable(timer);

/*
This uses timer 0, with an APB frequency of 80 MHz.  The prescalar is 320.
So 80,000,000 / 320 is 250 KHz.     1/250 KHz = 4 us for every "tick".

The counter counts to 30 + 1. So it takes 4 us * 31 = 124 us of normal runtime to trigger another interrupt.
It takes approx (200 bits tx) / (8 MHz) = 25 us (times two since it TXs 1 byte at a time with 50/50 duty) = 50 us to transmit one SPI message.

So 50 us + 124 us = ~174 us to update one level (one BAM bit). 174 us * 120 BAM bits = 21 ms per complete cycle, or around 48 frames per second.
*/


// here I just set up the anode array, this is what's written to the anode shift register, to enable each level
anode[0]=B00000001;
anode[1]=B00000010;
anode[2]=B00000100;
anode[3]=B00001000;
anode[4]=B00010000;
anode[5]=B00100000;
anode[6]=B01000000;
anode[7]=B10000000;
// don't hate on how I assigned the values to this register! haha

//finally set up the Outputs
pinMode(latch_pin, OUTPUT);//Latch
pinMode(data_pin, OUTPUT);//MOSI DATA
pinMode(clock_pin, OUTPUT);//SPI Clock
//pinMode(blank_pin, OUTPUT);//Output Enable  important to do this last, so LEDs do not flash on boot up
vspi->begin();//start up the SPI library
vspi->beginTransaction(SPISettings(8000000,MSBFIRST,SPI_MODE0));
interrupts();//let the show begin, this lets the multiplexing start

}//***end setup***end setup***end setup***end setup***end setup***end setup***end setup***end setup***end setup***end setup

void loop(){//***start loop***start loop***start loop***start loop***start loop***start loop***start loop***start loop***start loop

//Each animation located in a sub routine
// To control an LED, you simply:
// LED(level you want 0-7, row you want 0-7, column you want 0-7, red brighness 0-15, green brighness 0-15, blue brighness 0-15);


clean();
scrollText();
clean();
fireWorks();
clean();
//boxGrow();
clean();
sideCoil();
clean();
chopstick3D();
clean();
rainbowFountain();
clean();
resonance();
clean();
spiral();
clean();
statick();
clean();
cornerboxes();
clean();
rainVersionTwo();
clean();
sinwaveTwo();
clean();
wipe_out();
clean();
bouncyvTwo();
clean();
color_wheelTWO();
clean();
folder();
clean();
// Step 2. Insert your animation function call, e.g. your_animation();
clean();
harlem_shake();
clean();
cornerPanel();
clean();
lightLattice();
clean();
bresenhamSpiralV2();
clean();


//example();
delay(200);



}//***end loop***end loop***end loop***end loop***end loop***end loop***end loop***end loop***end loop***end loop***end loop***end loop




//*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE
//*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE
//*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE
//*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE



