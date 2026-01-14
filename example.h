#pragma once

#include "LED.h"


void example();

void example(){
  int i, j, k;
  for(i=0;i<8;i++)
  for(j=0;j<8;j++)
  for(k=0;k<8;k++){
    LED(i, j, k, 8-i, 8-j, k);
    delay(250);
  }
}



