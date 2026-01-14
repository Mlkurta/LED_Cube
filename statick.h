#ifndef STATICK_H
#define STATICK_H

#include "LED.h"

extern unsigned long start, sTwo;

void statick(){
  int i,t,m,b;
  short middlej[256], bottomj[256], topj[256], middlek[256], bottomk[256], topk[256];
  const short colorWheel[36] = {15,0,0,15,8,0,15,15,0,8,15,0,0,15,0,0,15,8,0,15,15,0,8,15,0,0,15,8,0,15,15,0,15,15,0,8};
  start = millis();
  for(i=0;i<256;i++){
    middlej[i] = random(8);
    bottomj[i] = random(8);
    topj[i] = random(8);
    middlek[i] = random(8);
    bottomk[i] = random(8);
    topk[i] = random(8);
  }
  
  while(millis() - start <2000){
    for(i=0;i<256;i++){
      t = random(12)*3;
      m = random(12)*3;
      b = random(12)*3;
      LED(0,bottomj[i],bottomk[i],colorWheel[b],colorWheel[b+1],colorWheel[b+2]);
      LED(1,bottomj[i],bottomk[i],colorWheel[b],colorWheel[b+1],colorWheel[b+2]);
      LED(3,middlej[i],middlek[i],colorWheel[m],colorWheel[m+1],colorWheel[m+2]);
      LED(4,middlej[i],middlek[i],colorWheel[m],colorWheel[m+1],colorWheel[m+2]);
      LED(6,topj[i],topk[i],colorWheel[t],colorWheel[t+1],colorWheel[t+2]);
      LED(7,topj[i],topk[i],colorWheel[t],colorWheel[t+1],colorWheel[t+2]);
      delay(10);
      LED(0,bottomj[i],bottomk[i],0,0,0);
      LED(1,bottomj[i],bottomk[i],0,0,0);
      LED(3,middlej[i],middlek[i],0,0,0);
      LED(4,middlej[i],middlek[i],0,0,0);
      LED(6,topj[i],topk[i],0,0,0);
      LED(7,topj[i],topk[i],0,0,0);
      delay(30);
    }
    
  }
    
}

#endif
