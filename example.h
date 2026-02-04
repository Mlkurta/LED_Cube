#pragma once

#include "LED.h"

/////////////////////////////////
/////Example LED Cube Sketch///// 
/////////////////////////////////


void example(){
  int i, j, k;

  // Turns on LEDs in a doubly nested for loop; Within every verticl level, it increments every row to 8 rows, and within every row, it incrments every column to 8 columns (0 - 7)
  // Also changes the colors of the LED depending on the level / row / column.  Uses a delay of 250 ms.  
  // **Note** if you want to turn LEDs off, you must write a zero value to the red, green and blue brightness values
  for(i=0;i<8;i++)
  for(j=0;j<8;j++)
  for(k=0;k<8;k++){
    // void LED(int16_t level, int16_t row, int16_t column, uint8_t red, uint8_t green, uint8_t blue);
    // Enter values 0 - 7 for level, row, and column.  Enter values (brightness --> higher = more from 0 - 15) for red, green, and blue.
    LED(i, j, k, 8-i, 8-j, k);
    delay(250);
  }

  // Does the exact same thing excepts it turns off the LEDs in the same order, but turns them off faster than they were turned on (less delay)
  for(i=0;i<8;i++)
  for(j=0;j<8;j++)
  for(k=0;k<8;k++){
    // void LED(int16_t level, int16_t row, int16_t column, uint8_t red, uint8_t green, uint8_t blue);
    // Enter values 0 - 7 for level, row, and column.  Enter values (brightness --> higher = more from 0 - 15) for red, green, and blue.
    LED(i, j, k, 8-i, 8-j, k);
    delay(50);
  
}





