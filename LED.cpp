#ifndef LED_CPP
#define LEP_CPP
#include "LED.h"

uint8_t clamp_voxel(uint8_t);
uint8_t clamp_intensity(uint8_t);
extern uint8_t red0[], red1[], red2[], red3[], green0[], green1[], green2[], green3[], blue0[], blue1[], blue2[], blue3[];

void LED(int16_t level, int16_t row, int16_t column, uint8_t red, uint8_t green, uint8_t blue){

  // First, check and make sure nothing went beyond the limits, just clamp things at either 0 or 7 for location, and 0 or 15 for brightness
  if(level<0)
  level=0;
  if(level>7)
  level=7;
  if(row<0)
  row=0;
  if(row>7)
  row=7;
  if(column<0)
  column=0;
  if(column>7)
  column=7;  
  if(red<0)
  red=0;
  if(red>15)
  red=15;
  if(green<0)
  green=0;
  if(green>15)
  green=15;
  if(blue<0)
  blue=0;
  if(blue>15)
  blue=15;

/*   -----Branchless Programming (attempt)------
  level = clamp_voxel(level);
  row = clamp_voxel(row);
  column = clamp_voxel(column);
  red = clamp_intensity(red);
  green = clamp_intensity(green);
  blue = clamp_intensity(blue);
*/
  
   //There are 512 LEDs in the cube, so when we write to level 2, column 5, row 4, that needs to be translated into a number from 0 to 511
  
  //This looks confusing, I know...
  uint8_t whichbyte = uint8_t(((level*64)+(row*8)+column)>>3);
  
  // The first level LEDs are first in the sequence, then 2nd level, then third, and so on
  //the (level*64) is what indexes the level's starting place, so level 0 are LEDs 0-63, level 1 are LEDs 64-127, and so on
  
  //The column counts left to right 0-7 and the row is back to front 0-7
  //This means that if you had level 0, row 0, the bottom back row would count from 0-7, 
  
  //so if you looked down on the cube, and only looked at the bottom level
  // 00 01 02 03 04 05 06 07
  // 08 09 10 11 12 13 14 15
  // 16 17 18 19 20 21 22 23
  // 24 25 26 27 28 29 30 31
  // 32 33 34 35 36 37 38 39
  // 40 41 42 43 44 45 46 47  
  // 48 49 50 51 52 53 54 55  
  // 56 57 58 59 60 61 62 63

//Then, if you incremented the level, the top right of the grid above would start at 64
//The reason for doing this, is so you don't have to memorize a number for each LED, allowing you to use level, row, column

//Now, what about the divide by 8 in there?
//...well, we have 8 bits per byte, and we have 64 bytes in memory for all 512 bits needed for each LED, so
//we divide the number we just found by 8, and take the integ7er of it, so we know which byte, that bit is located
//confused? that's ok, let's take an example, if we wanted to write to the LED to the last LED in the cube, we would write a 7, 7, 7
// giving (7*64)+(7*8)=7 = 511, which is right, but now let's divide it by 8, 511/8 = 63.875, and take the int of it so, we get 63,
//this is the last byte in the array, which is right since this is the last LED
  
// This next variable is the same thing as before, but here we don't divide by 8, so we get the LED number 0-511
  uint8_t wholebyte=(level*64)+(row*8)+column;

   //This is 4 bit color resolution, so each color contains x4 64 byte arrays, explanation below:
  bitWrite(red0[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 0));
  bitWrite(red1[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 1));
  bitWrite(red2[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 2)); 
  bitWrite(red3[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 3)); 

  bitWrite(green0[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 0));
  bitWrite(green1[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 1));
  bitWrite(green2[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 2)); 
  bitWrite(green3[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 3));

  bitWrite(blue0[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 0));
  bitWrite(blue1[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 1));
  bitWrite(blue2[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 2)); 
  bitWrite(blue3[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 3));
} // end void LED

void clean(){
  uint8_t ii, jj, kk;
  for(ii=0; ii<8; ii++)
  for(jj=0; jj<8; jj++)
  for(kk=0; kk<8; kk++)
  LED(ii,jj,kk,0,0,0);
  
}

// Branchless programming way to clamp voxel x / y / z position to  0 - 7 (defined by MIN/MAX_VOXEL_POS)
// Looking back, this is probably not beneficial as many abs() commands with the ESP uP convert to a branch anyway.
uint8_t clamp_voxel(uint8_t value){
    uint8_t temp = value + MAX_VOXEL_POS - abs(value - MAX_VOXEL_POS);
#if MIN_VOXEL_POS == 0 
    return (temp + abs(temp)) * 0.25;
#else 
    return (temp + (2.0 * MIN_VOXEL_POS) + abs (temp-(2.0*MIN_VOXEL_POS))) * 0.25;
#endif
}

uint8_t clamp_intensity(uint8_t value){
    uint8_t temp = value + MAX_VOXEL_INTSY - abs(value - MAX_VOXEL_INTSY);
#if MIN_VOXEL_INTSY == 0
    return (temp + abs(temp)) * 0.25; 
#else
    return (temp + (2.0 * MIN_VOXEL_INTSY) + abs(temp-(2.0*MIN_VOXEL_INTSY))) * 0.25;
#endif
}

/*struct{
    uint8_t x;
    uint8_t y; 
    uint8_t z;
}v_cube[512];*/  // SOA setup


/**
 * Draws a straight line of LEDs along one axis.
 *
 * axis:
 *   'i' (default) → vertical line (level / height)
 *   'j'           → row direction
 *   'k'           → column direction
 *
 * startLevel, startRow, startColumn:
 *   Starting coordinate of the line
 *
 * length:
 *   Number of LEDs to draw along the selected axis
 *
 * red, green, blue:
 *   Brightness (0–15) for each color channel
 */
void drawLine(char axis, uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t length, uint8_t red, uint8_t green, uint8_t blue){
    int32_t index;
    switch(axis){
        case 'j':
            for(index = startRow; index <= startRow + length; index++) LED(startLevel, index, startColumn, red, green, blue);
            break;

        case 'k':
            for(index = startColumn; index <= startColumn + length; index++) LED(startLevel, startRow, index, red, green, blue);
            break;
            
        default:
            for(index = startLevel; index <= startLevel + length; index++) LED(index, startRow, startColumn, red, green, blue);
            
    }
}

/**
 * Draws a hollow square (2D wireframe) on a selected plane.
 *
 * axis:
 *   'i' → square lies in (level,row) plane
 *   'j' → square lies in (level,column) plane
 *   default → square lies in (row,column) plane
 *
 * startLevel, startRow, startColumn:
 *   Origin (top-left corner) of the square
 *
 * length:
 *   Side length of the square
 */
void drawSquare(char axis, uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t length, uint8_t red, uint8_t green, uint8_t blue){
  uint8_t i, j;
  switch(axis){
    case 'i':
      for(i = startLevel; i <= startLevel + length; i++){
        for(j = startRow; j <= startRow + length; j++){
          if(i != startLevel && i != startLevel + length){
            if(j == startRow || j == startRow + length){
              LED(i, j, startColumn, red, green, blue);
            }else{
              LED(i, j, startColumn, red, green, blue);
            }
          }
        }
      }
      return;
    case 'j':
      for(i = startLevel; i <= startLevel + length; i++){
        for(j = startColumn; j <= startColumn + length; j++){
          if(i != startLevel && i != startLevel + length){
            if(j == startColumn || j == startColumn + length){
              LED(i, startRow, j, red, green, blue);
            }else{
              LED(i, startRow, j, red, green, blue);
            }
          }
        }
      }
      return;

    default:
      for(i = startRow; i <= startRow + length; i++){
        for(j = startColumn; j <= startColumn + length; j++){
          if(i != startRow && i != startRow + length){
            if(j == startColumn || j == startColumn + length){
              LED(startLevel, i, j, red, green, blue);
            }else{
              LED(startLevel, i, j, red, green, blue);
            }
          }
        }
      }
  }
}

/**
 * Draws a solid cube (filled volume).
 *
 * level, row, column:
 *   Starting corner of the cube
 *
 * length:
 *   Cube edge length
 */
void drawCube(uint8_t level, uint8_t row, uint8_t column, uint8_t length, uint8_t red, uint8_t green, uint8_t blue){
    for(uint8_t i = level; i < length + level; i++){
        for(uint8_t j = row; j < length + row; j++){
            for(uint8_t k = column; k < length + column; k++){
                LED(i, j, k, red, green, blue);
            }
        }
    }
}

/**
 * Draws a solid rectangular prism (box).
 *
 * height, length, width:
 *   Dimensions along level, row, and column axes
 */
void drawRect(uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t height, uint8_t length, uint8_t width, uint8_t red, uint8_t green, uint8_t blue){
    for(uint8_t i = startLevel; i < height + startLevel; i++){
        for(uint8_t j = startRow; j < length + startRow; j++){
            for(uint8_t k = startColumn; k < width + startColumn; k++){
                LED(i, j, k, red, green, blue);
            }
        }
    }
}

/**
 * Draws a hollow cube (edges only).
 *
 * Only LEDs on the outer surfaces and edges are lit.
 */
void drawCubeWireFrame(uint8_t level, uint8_t row, uint8_t column, uint8_t length, uint8_t red, uint8_t green, uint8_t blue){
    for(uint8_t i = level; i < length+ level; i++)
    for(uint8_t j = row; j < length + row; j++)
    for(uint8_t k = column; k < length + column; k++)
        if(i != level && i != level + length - 1){
            if((j == row || j == row + length - 1) && (k == column || k == column + length - 1)){
                LED(i, j, k, red, green, blue);
            }
        }else if((j == row || j == row + length - 1) || (k == column || k == column + length - 1)){
            LED(i, j, k, red, green, blue);
        }  
}

/**
 * Draws a hollow rectangular prism (wireframe box).
 */
void drawRectWireFrame(uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t height, uint8_t length, uint8_t width, uint8_t red, uint8_t green, uint8_t blue){
    for(uint8_t i = startLevel; i < height + startLevel; i++)
    for(uint8_t j = startRow; j < length + startRow; j++)
    for(uint8_t k = startColumn; k < width + startColumn; k++)
        if(i != startLevel && i != startLevel + height - 1){
            if((j == startRow || j == startRow + length - 1) && (k == startColumn || k == startColumn + width - 1)){
                LED(i, j, k, red, green, blue);
            }
        }else if((j == startRow || j == startRow + length - 1) || (k == startColumn || k == startColumn + width - 1)){
            LED(i, j, k, red, green, blue);
        }      
}

/**
 * Draws half of an octagonal pattern using a bitmap.
 *
 * octo[][] stores bitmaps for each level.
 * Each bit represents whether an LED should be on or off.
 */
void drawHalfOcto(uint8_t level, uint8_t originJ, uint8_t originK, uint8_t red, uint8_t green, uint8_t blue){
    uint8_t i,j,k;
    uint8_t octo[4][8] =   {{B00011000, B00100100, B01000010, B10000001, B10000001, B01000010, B00100100, B00011000},
                            {B00100100, B01000010, B10000001, B00000000, B00000000, B10000001, B01000010, B00100100},
                            {B01000010, B10000001, B00000000, B00000000, B00000000, B00000000, B10000001, B01000010},
                            {B10000001, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B10000001}
                           };


    for(i = level; i < 8; i++){
        for(j = originJ; j < 8; j++){
            for(k = originK; k < 8; k++){
                if(bitRead(octo[i][j], k)){
                    LED(i, j, k, red, green, blue);
                }else{
                    LED(i, j, k, 0, 0, 0);
                }
            }
        }
    }
}

#endif