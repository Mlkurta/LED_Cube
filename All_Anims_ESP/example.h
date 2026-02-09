#pragma once

#include "LED.h"

// Variable created in "All_Anims_ESP.ino" (Parent file). Access global variables in that file with extern keyword
// |||
// VVV
extern unsigned long start;    

// Macro for program runtime
const unsigned int RUNTIME_MS = 20000;

// Name your animation function whatever you want
void example(){

  // Create a timestamp
  start = millis();

  // Let the program run for 20 seconds, give or take. If the loop below takes 19 seconds it will have to loop through again before it's checked and ended
  while(millis() - start < 20000){
    int i, j , k;

    // Light LEDs starting at level 0, row 0, column 0 (bottom corner)
    // For every level (i) we increment, we increment 8 rows. For every row (j) we increment, we increment through 8 (k) columns
    for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
    for(k = 0; k < 8; k++){
      // LED function lights one LED at a time 
      // enter values 0 - 7 for i (level), j(rows), and k(columns), and brightness 0-15 for red, green, and blue.
      // e.g. LED(7, 7, 7, 15, 15, 15) creates a bright white LED color in the top corner
      LED(i, j, k, i, 8-i, 8-i);

    // Time between LEDs lit in milliseconds.
    delay(37);
    }
  }
}




