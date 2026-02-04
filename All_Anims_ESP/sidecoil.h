#ifndef SIDECOIL_H
#define SIDECOIL_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"
void sideCoilDraw(int, int, uint8_t, uint8_t, uint8_t);

void sideCoil(){
    clean();
    int k, redColor = 0, greenColor = 0, blueColor = 0, colorSelect;
    int t = 35;
    enum stage     {
                        outer = 0,
                        firstInner = 1,
                        secondInner = 2,
                        centerFour = 3
                    };

    for(k = 0; k < 8; k++){
        colorSelect = random(0, 9);
        switch(colorSelect){
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
          greenColor = random(2, 8);
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
          blueColor = random(2, 8);
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
      sideCoilDraw(k, t, redColor, greenColor, blueColor);

    }
    delay(3000);
    clean();

}

void sideCoilDraw(int k, int timeDelay, uint8_t redColor, uint8_t greenColor, uint8_t blueColor){
    int i, ii, jj;
    int order = k % 2;
    switch(order){
        case 0:
            // Draw outer ring of coil
            for(i = 0; i < 28; i++){
                if(i > 7 && i < 15){
                    ii = i - 7;
                    jj = 0;

                }else if(i > 14 && i < 22){
                    ii = 7;
                    jj = i - 14;

                }else if(i > 21){
                    ii = 28 - i;
                    jj = 7;

                }else{
                    ii = 0;
                    jj = 7 - i;
                }
                LED(ii, jj, k, redColor, greenColor, blueColor);
                delay(timeDelay);
            }
            // Draw first inner layer ring of coil
            for(i = 0; i < 20; i++){
                if(i > 5 && i < 11){
                    ii = i - 4;
                    jj = 1;

                }else if(i > 10 && i < 16){
                    ii = 6;
                    jj = i - 9;

                }else if(i > 15){
                    ii = 21 - i;
                    jj = 6;

                }else{
                    ii = 1;
                    jj = 6 - i;
                }
                LED(ii, jj, k, redColor, greenColor, blueColor);
                delay(timeDelay);
            }
            // Draw second (4 x 4) inner layer ring of coil
            for(i = 0; i < 12; i++){
                if(i > 3 && i < 7){
                    ii = i - 1;
                    jj = 2;

                }else if(i > 6 && i < 10){
                    ii = 5;
                    jj = i - 4;

                }else if(i > 9){
                    ii = 14 - i;
                    jj = 5;

                }else{
                    ii = 2;
                    jj = 5 - i;
                }
                LED(ii, jj, k, redColor, greenColor, blueColor);
                delay(timeDelay);
            }
            LED(3, 4, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            LED(3, 3, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            LED(4, 3, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            LED(4, 4, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            break;

        case 1:
            LED(3, 4, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            LED(3, 3, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            LED(4, 3, k, redColor, greenColor, blueColor);
            delay(timeDelay);
            LED(4, 4, k, redColor, greenColor, blueColor);
            // Draw second (4 x 4) inner layer ring of coil
            for(i = 0; i < 12; i++){
                if(i > 3 && i < 7){
                    ii = i - 1;
                    jj = 2;

                }else if(i > 6 && i < 10){
                    ii = 5;
                    jj = i - 4;

                }else if(i > 9){
                    ii = 14 - i;
                    jj = 5;

                }else{
                    ii = 2;
                    jj = 5 - i;
                }
                LED(ii, jj, k, redColor, greenColor, blueColor);
                delay(timeDelay);
            }
            // Draw first inner layer ring of coil
            for(i = 0; i < 20; i++){
                if(i > 5 && i < 11){
                    ii = i - 4;
                    jj = 1;

                }else if(i > 10 && i < 16){
                    ii = 6;
                    jj = i - 9;

                }else if(i > 15){
                    ii = 21 - i;
                    jj = 6;

                }else{
                    ii = 1;
                    jj = 6 - i;
                }
                LED(ii, jj, k, redColor, greenColor, blueColor);
                delay(timeDelay);
            }
            // Draw outer ring of coil
            for(i = 0; i < 28; i++){
                if(i > 7 && i < 15){
                    ii = i - 7;
                    jj = 0;

                }else if(i > 14 && i < 22){
                    ii = 7;
                    jj = i - 14;

                }else if(i > 21){
                    ii = 28 - i;
                    jj = 7;

                }else{
                    ii = 0;
                    jj = 7 - i;
                }
                LED(ii, jj, k, redColor, greenColor, blueColor);
                delay(timeDelay);
            }
            break;
    }
}


#endif
