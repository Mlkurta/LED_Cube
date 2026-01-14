#ifndef FLASHER_H
#define FLASHER_H

#include "LED.h"

void flasher();

void flasher(){

  const int cubeIHeight   = 7;
  const int cubeJWidth    = 7;
  const int cubeKLength   = 7;
  int rectIHeight         = 7;
  int rectJWidth          = 7;
  int rectKLength         = 7;

  int i, j, k;

  extern unsigned long start;

  clean();
  start = millis();
  while(millis() - start < 4000){
    for(i = cubeIHeight - (rectIHeight - 1); i < cubeIHeight + 1; i++){
      for(j = (cubeJWidth / 2) - (rectJWidth / 2); j < (cubeJWidth / 2) - (rectJWidth / 2) + cubeJWidth; j++){
        for(k = (cubeKLength / 2) - (rectKLength / 2); k < (cubeKLength / 2) - (rectKLength / 2) + cubeKLength; k++){
          LED(i, j, k, 2, 2, 2);
        }
      }
    }
    delay(5);
    for(i = cubeIHeight - (rectIHeight - 1); i < cubeIHeight + 1; i++){
      for(j = (cubeJWidth / 2) - (rectJWidth / 2); j < (cubeJWidth / 2) - (rectJWidth / 2) + cubeJWidth; j++){
        for(k = (cubeKLength / 2) - (rectKLength / 2); k < (cubeKLength / 2) - (rectKLength / 2) + cubeKLength; k++){
          LED(i, j, k, 8, 8, 8);
        }
      }
    }
    delay(3);
    for(i = cubeIHeight - (rectIHeight - 1); i < cubeIHeight + 1; i++){
      for(j = (cubeJWidth / 2) - (rectJWidth / 2); j < (cubeJWidth / 2) - (rectJWidth / 2) + cubeJWidth; j++){
        for(k = (cubeKLength / 2) - (rectKLength / 2); k < (cubeKLength / 2) - (rectKLength / 2) + cubeKLength; k++){
          LED(i, j, k, 15, 15, 15);
        }
      }
    }
    delay(15);
    for(i = cubeIHeight - (rectIHeight - 1); i < cubeIHeight + 1; i++){
      for(j = (cubeJWidth / 2) - (rectJWidth / 2); j < (cubeJWidth / 2) - (rectJWidth / 2) + cubeJWidth; j++){
        for(k = (cubeKLength / 2) - (rectKLength / 2); k < (cubeKLength / 2) - (rectKLength / 2) + cubeKLength; k++){
          LED(i, j, k, 8, 8, 8);
        }
      }
    }
    delay(5);
    for(i = cubeIHeight - (rectIHeight - 1); i < cubeIHeight + 1; i++){
      for(j = (cubeJWidth / 2) - (rectJWidth / 2); j < (cubeJWidth / 2) - (rectJWidth / 2) + cubeJWidth; j++){
        for(k = (cubeKLength / 2) - (rectKLength / 2); k < (cubeKLength / 2) - (rectKLength / 2) + cubeKLength; k++){
          LED(i, j, k, 2, 2, 2);
        }
      }
    }
    delay(5);
    for(i = cubeIHeight - (rectIHeight - 1); i < cubeIHeight + 1; i++){
      for(j = (cubeJWidth / 2) - (rectJWidth / 2); j < (cubeJWidth / 2) - (rectJWidth / 2) + cubeJWidth; j++){
        for(k = (cubeKLength / 2) - (rectKLength / 2); k < (cubeKLength / 2) - (rectKLength / 2) + cubeKLength; k++){
          LED(i, j, k, 0, 0, 0);
        }
      }
    }
    delay(1000);
  }
}

#endif