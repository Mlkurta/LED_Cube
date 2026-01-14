#ifndef BOXGROW_H
#define BOXGROW_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"

void boxGrow();

void growBoxDraw(int, int, uint8_t, uint8_t, uint8_t);

void boxGrow(){
  clean();
  int i,j,randSelect;
  static uint8_t redColor = 0;
  static uint8_t greenColor = 8;
  static uint8_t blueColor = 12;

  for(i = 0; i < 3; i++){
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

    for(j = 0; j < 8; j++){
      growBoxDraw(i, j, redColor, greenColor, blueColor);
      delay(100);
      growBoxDraw(i, j, 0, 0, 0);

    }
    for(j = 8; j >= 0; j--){
      growBoxDraw(i, j, redColor, greenColor, blueColor);
      delay(100);
      growBoxDraw(i, j, 0, 0, 0);

    }
  }
}

void growBoxDraw(int direction, int stage, uint8_t redColor, uint8_t greenColor, uint8_t blueColor){
    int i, j, k;


    switch(direction){
      // Case 0 begins at origin and is handled by "default"
      // Case 1 is the opposite, cube grows from 7,7,7
      // Case 2 begins at origin with j = 7
      // Case 3 is opposite of case 2 with (i, j, k) beginning at (7, 0, 7)
      // Case 4 begins at (0, 0, 7)
      // Case 5 is opposite of Case 4 at (7, 7, 0)
      // Case 6 begins at (0, 7, 7)
      // Case 7 is opposite of Case 6 at (7, 0, 0)

      case 1:
        i = 6 - stage;
        j = 6 - stage;
        k = 6 - stage;
        break;
      
      case 2:
        i = 0;
        j = 6 - stage;
        k = 0;
        break;

      case 3:
        i = 6 - stage;
        j = 0;
        k = 6 - stage;
        break;

      case 4:
        i = 0;
        j = 0;
        k = 6 - stage;
        break;

      case 5:
        i = 6 - stage;
        j = 6 - stage;
        k = 0;
        break;
      
      case 6:
        i = 0;
        j = 6 - stage;
        k = 6 - stage;
        break;

      case 7:
        i = 6 - stage;
        j = 0;
        k = 0;
        break;

      default:
        i = 0;
        j = 0;
        k = 0;
        break;

    }
    drawCubeWireFrame(i, j, k, stage + 2, redColor, greenColor, blueColor);
}


#endif
