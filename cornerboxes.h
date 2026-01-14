#ifndef CORNERBOXES_H
#define CORNERBOXES_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"

void cornerBoxDraw(int, int, uint8_t, uint8_t, uint8_t);

void cornerboxes(){
  clean();
  uint8_t i,j,randSelect;
  static uint8_t redColor = 0;
  static uint8_t greenColor = 8;
  static uint8_t blueColor = 12;

  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      randSelect = random(0,9);


      switch(randSelect){
        case 0:
          redColor = random(5, 15);
          greenColor = 0;
          blueColor = 0;
          break;
        case 1:
          redColor = 0;
          greenColor = random(5, 15);
          blueColor = 0;
          break;
        case 2:
          redColor = 0;
          greenColor = 0;
          blueColor = random(5, 15);
          break;
        case 3:
          redColor = random(5, 15);
          greenColor = random(0, 8);
          blueColor = 0;
          break;
        case 4:
          redColor = random(2, 8);
          greenColor = random(5, 15);
          blueColor = 0;
          break;
        case 5:
          redColor = random(5, 15);
          greenColor = 0;
          blueColor = random(5, 8);
          break;
        case 6:
          redColor = random(2, 8);
          greenColor = 0;
          blueColor = random(5, 15);
          break;
        case 7:
          redColor = 0;
          greenColor = random(2, 8);
          blueColor = random(5, 15);
          break;
        case 8:
          redColor = 0;
          greenColor = random(5, 15);
          blueColor = random(2, 8);
          break;
      }
      cornerBoxDraw(i, j, redColor, greenColor, blueColor);
      delay(1000);

    }
    clean();
    delay(1000);
  }
}

void cornerBoxDraw(int i, int j, uint8_t redColor, uint8_t greenColor, uint8_t blueColor){
    switch(i){
        case 0:
          drawCube(j*2, j*2, j*2, 2, redColor, greenColor, blueColor);
          break;
        case 1:
          drawCube(6 - (j*2), j*2, j*2, 2, redColor, greenColor, blueColor);
          break;
        case 2:
          drawCube(j*2, 6 - (j*2), j*2, 2, redColor, greenColor, blueColor);
          break;
        case 3:
          drawCube(6 - (j*2), 6 - (j*2), j*2, 2, redColor, greenColor, blueColor);
          break;
        case 4:
          drawCube(j*2, j*2, 6 - (j*2), 2, redColor, greenColor, blueColor);
          break;
        case 5:
          drawCube(6 - (j*2), j*2, 6 - (j*2), 2, redColor, greenColor, blueColor);
          break;
        case 6:
          drawCube(j*2, 6 - (j*2), 6 - (j*2), 2, redColor, greenColor, blueColor);
          break;
        case 7:
          drawCube(6 - (j*2), 6 - (j*2), 6 - (j*2), 2, redColor, greenColor, blueColor);
          break;
      }
}

#endif

