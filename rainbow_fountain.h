#ifndef RAINBOW_FOUNTAIN_H
#define RAINBOW_FOUNTAIN_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"

void rainbowFountain(){
  const short redFrame[18] = {15,15,15,15,10,5,0,0,0,0,0,0,0,5,10,15,15,15}; //0-17
  const short greenFrame[18] = {0,5,10,15,15,15,15,15,15,15,10,5,0,0,0,0,0,0};
  const short blueFrame[18] = {0,0,0,0,0,0,0,5,10,15,15,15,15,15,15,15,10,5};
  short count = 0; //cycle counter, increments at end of loop
  int mil = 30;
  int i = 0; //color iteration counter 
  int sa = -14;
  int sb = -13;
  int sc = -12;
  int sd = -11;
  int se = -10;
  int sf = -9;
  int sg = -8;
  int sh = -7;
  int si = -6;
  int sj = -5;
  int sk = -4;
  int sl = -3;
  int sm = -2;
  int sn = -1;
  int rr = 0;
  int rg = 0;
  int rb = 0;
  /*for(i=0;i<18;i++){
    rr = random(0,15);
    rg = random(0,15);
    rb = random(0,15);
    redFrame[i] = rr;
    greenFrame[i] = rg;
    blueFrame[i] = rb;
  }*/
  
    while(count < 6){
      if(sa + 14 >= 18){
        sa -= 4;
      }else{
        sa += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,0,2,0,0,0);                                    
      LED(0,0,3,0,0,0);
      LED(2,0,4,0,0,0);
      LED(2,0,5,0,0,0);
      LED(4,0,6,0,0,0);
      LED(4,0,7,0,0,0);
      LED(6,1,7,0,0,0);
      LED(6,2,7,0,0,0);
      LED(0,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(0,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(2,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(2,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(4,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(4,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(6,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(6,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(5,3,2,0,0,0);
      LED(7,3,1,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(7,4,1,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(1,3,3,0,0,0);
      LED(4,2,2,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      }
      LED(0,3,3,redFrame[sa],greenFrame[sa],blueFrame[sa]); //1
      delay(mil);
      if(count > 0){
      LED(6,3,2,0,0,0);
      LED(7,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(7,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(2,3,3,0,0,0);
      LED(5,2,2,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      }
      LED(1,3,3,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      delay(mil);
      if(count > 0){
      LED(1,0,4,0,0,0);
      LED(1,0,5,0,0,0);
      LED(3,0,6,0,0,0);
      LED(3,0,7,0,0,0);
      LED(5,1,7,0,0,0);
      LED(5,2,7,0,0,0);
      LED(7,3,7,0,0,0);
      LED(7,4,7,0,0,0);
      LED(1,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(1,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(3,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(3,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(5,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(5,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(7,3,2,0,0,0);
      LED(3,2,2,0,0,0);
      LED(6,2,2,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      }
      LED(2,3,3,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      delay(mil);
      if(count > 0){
      LED(7,3,1,0,0,0);
      LED(7,4,1,0,0,0);
      LED(4,2,2,0,0,0);
      LED(7,2,2,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      }
      LED(0,3,3,0,0,0);                                     
      LED(3,2,2,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      if(sb + 14 >= 18){
        sb -= 4;
      }else{
        sb += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,0,4,0,0,0);
      LED(0,0,5,0,0,0);
      LED(2,0,6,0,0,0);
      LED(2,0,7,0,0,0);
      LED(4,1,7,0,0,0);
      LED(4,2,7,0,0,0);
      LED(6,3,7,0,0,0);
      LED(6,4,7,0,0,0);
      LED(0,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(0,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(2,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(2,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(4,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(4,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(6,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(6,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(5,2,2,0,0,0);
      LED(7,1,1,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(7,2,1,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      }
      LED(0,3,3,redFrame[sb],greenFrame[sb],blueFrame[sb]); //5
      LED(1,3,3,0,0,0);
      LED(4,2,2,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      delay(mil);
      if(count > 0){
        LED(6,2,2,0,0,0);
      }
      LED(1,3,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(2,3,3,0,0,0);
      LED(5,2,2,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      delay(mil);
      if(count > 0){
      LED(1,0,6,0,0,0);
      LED(1,0,7,0,0,0);
      LED(3,1,7,0,0,0);
      LED(3,2,7,0,0,0);
      LED(5,3,7,0,0,0);
      LED(5,4,7,0,0,0);
      LED(7,5,7,0,0,0);
      LED(7,6,7,0,0,0);
      LED(1,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(1,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(3,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(3,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(5,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(5,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(7,2,2,0,0,0);
      LED(7,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(7,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);  
      }
      LED(2,3,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(3,2,2,0,0,0);
      LED(6,2,2,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      delay(mil);
      if(count > 0){
      LED(7,1,1,0,0,0);
      LED(7,2,1,0,0,0);
      }
      LED(0,3,3,0,0,0);
      LED(3,2,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(4,2,2,0,0,0);
      LED(7,2,2,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      if(sc + 14 >= 18){
        sc -= 4;
      }else{
       sc += 14; 
      }
      delay(mil);
      if(count > 0){
      LED(0,0,6,0,0,0);
      LED(0,0,7,0,0,0);
      LED(2,1,7,0,0,0);
      LED(2,2,7,0,0,0);
      LED(4,3,7,0,0,0);
      LED(4,4,7,0,0,0);
      LED(6,5,7,0,0,0);
      LED(6,6,7,0,0,0);
      LED(0,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(0,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(2,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(2,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(4,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(4,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(6,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(6,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);    
      }
      LED(1,3,3,0,0,0);                                     //9
      LED(4,2,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(5,2,2,0,0,0);
      LED(7,1,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(0,3,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      delay(mil);
      LED(2,3,3,0,0,0);                                     
      LED(5,2,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(6,2,2,0,0,0);
      LED(7,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(7,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(1,3,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      delay(mil);
      if(count > 0){
      LED(1,1,7,0,0,0);
      LED(1,2,7,0,0,0);
      LED(3,3,7,0,0,0);
      LED(3,4,7,0,0,0);
      LED(5,5,7,0,0,0);
      LED(5,6,7,0,0,0);
      LED(7,7,7,0,0,0);
      LED(7,7,6,0,0,0);
      LED(1,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(1,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(3,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(3,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(5,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(5,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);    
      }
      LED(7,2,2,0,0,0);
      LED(3,2,3,0,0,0);
      LED(6,2,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(2,3,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      delay(mil);
      LED(4,2,3,0,0,0);
      LED(7,1,1,0,0,0);
      LED(7,2,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(0,3,4,0,0,0);
      LED(3,2,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      if(sd + 14 >= 18){
        sd -= 4;
      }else{
        sd += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,1,7,0,0,0);
      LED(0,2,7,0,0,0);
      LED(2,3,7,0,0,0);
      LED(2,4,7,0,0,0);
      LED(4,5,7,0,0,0);
      LED(4,6,7,0,0,0);
      LED(6,7,7,0,0,0);
      LED(6,7,6,0,0,0);
      LED(0,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(0,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(2,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(2,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(4,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(4,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);      
      }
      LED(6,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]); //13
      LED(6,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(5,2,3,0,0,0);
      LED(7,1,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(7,1,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(1,3,4,0,0,0);
      LED(4,2,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(0,3,4,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      delay(mil);
      LED(6,2,3,0,0,0);
      LED(7,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(7,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(2,3,4,0,0,0);
      LED(5,2,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(1,3,4,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      delay(mil);
      if(count > 0){
      LED(1,3,7,0,0,0);
      LED(1,4,7,0,0,0);
      LED(3,5,7,0,0,0);
      LED(3,6,7,0,0,0);
      LED(5,7,7,0,0,0);
      LED(5,7,6,0,0,0);
      LED(7,7,5,0,0,0);
      LED(7,7,4,0,0,0);
      LED(1,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(1,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(3,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(3,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);   
      }
      LED(5,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(5,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(7,2,3,0,0,0);
      LED(3,2,4,0,0,0);
      LED(6,2,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(2,3,4,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      delay(mil);
      LED(7,1,2,0,0,0);
      LED(7,1,3,0,0,0);
      LED(4,2,4,0,0,0);
      LED(7,2,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(0,3,4,0,0,0);
      LED(3,2,5,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      if(se + 14 >= 18){
        se -= 4;
      }else{
        se += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,3,7,0,0,0);
      LED(0,4,7,0,0,0);
      LED(2,5,7,0,0,0);
      LED(2,6,7,0,0,0);
      LED(4,7,7,0,0,0);
      LED(4,7,6,0,0,0);
      LED(6,7,5,0,0,0);
      LED(6,7,4,0,0,0);
      LED(0,3,0,redFrame[sm],greenFrame[sm],blueFrame[sm]); 
      LED(0,4,0,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(2,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(2,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);     
      }
      LED(4,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]); //17
      LED(4,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(6,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(6,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(5,2,4,0,0,0);
      LED(7,1,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(7,1,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(1,3,4,0,0,0);
      LED(4,2,5,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(0,3,4,redFrame[se],greenFrame[se],blueFrame[se]);
      delay(mil);
      LED(6,2,4,0,0,0);
      LED(7,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(7,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(2,3,4,0,0,0);
      LED(5,2,5,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(1,3,4,redFrame[se],greenFrame[se],blueFrame[se]);
      delay(mil);
      if(count > 0){
      LED(1,5,7,0,0,0);
      LED(1,6,7,0,0,0);
      LED(3,7,7,0,0,0);
      LED(3,7,6,0,0,0);
      LED(5,7,5,0,0,0);
      LED(5,7,4,0,0,0);
      LED(7,7,3,0,0,0);
      LED(7,7,2,0,0,0);
      LED(1,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(1,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);    
      }
      LED(3,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]); 
      LED(3,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(5,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(5,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(7,2,4,0,0,0);
      LED(3,2,5,0,0,0);
      LED(6,2,5,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(2,3,4,redFrame[se],greenFrame[se],blueFrame[se]);
      delay(mil);
      LED(7,1,4,0,0,0);
      LED(7,1,5,0,0,0);
      LED(4,2,5,0,0,0);
      LED(7,2,5,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(0,3,4,0,0,0);
      LED(3,3,5,redFrame[se],greenFrame[se],blueFrame[se]);
      if(sf + 14 >= 18){
        sf -= 4;
      }else{
        sf += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,5,7,0,0,0);
      LED(0,6,7,0,0,0);
      LED(2,7,7,0,0,0);
      LED(2,7,6,0,0,0);
      LED(4,7,5,0,0,0);
      LED(4,7,4,0,0,0);
      LED(6,7,3,0,0,0);
      LED(6,7,2,0,0,0);
      LED(0,1,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      LED(0,2,0,redFrame[sn],greenFrame[sn],blueFrame[sn]);    
      }
      LED(2,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]); //21
      LED(2,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(4,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(4,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(6,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(6,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(5,2,5,0,0,0);
      LED(7,1,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(1,3,4,0,0,0);
      LED(4,3,5,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(0,4,4,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      delay(mil);
      LED(6,2,5,0,0,0);
      LED(7,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(7,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(2,3,4,0,0,0);
      LED(5,3,5,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(1,4,4,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      delay(mil);
      if(count > 0){
      LED(1,7,7,0,0,0);
      LED(1,7,6,0,0,0);
      LED(3,7,5,0,0,0);
      LED(3,7,4,0,0,0);
      LED(5,7,3,0,0,0);
      LED(5,7,2,0,0,0);
      LED(7,7,1,0,0,0);
      LED(7,7,0,0,0,0);
      }
      LED(1,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]); 
      LED(1,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(3,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(3,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(5,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(5,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(7,2,5,0,0,0);
      LED(3,3,5,0,0,0);
      LED(6,3,5,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(2,4,4,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      delay(mil);
      LED(7,1,6,0,0,0);
      LED(4,3,5,0,0,0);
      LED(7,3,5,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(0,4,4,0,0,0);
      LED(3,4,5,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      if(sg + 14 >= 18){
        sg -= 4;
      }else{
        sg += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,7,7,0,0,0);
      LED(0,7,6,0,0,0);
      LED(2,7,5,0,0,0);
      LED(2,7,4,0,0,0);
      LED(4,7,3,0,0,0);
      LED(4,7,2,0,0,0);
      LED(6,7,1,0,0,0);
      LED(6,7,0,0,0,0);
      }
      LED(0,0,0,redFrame[sa],greenFrame[sa],blueFrame[sa]); //25
      LED(0,0,1,redFrame[sa],greenFrame[sa],blueFrame[sa]);
      LED(2,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(2,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(4,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(4,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(6,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(6,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(5,3,5,0,0,0);
      LED(7,1,6,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(7,2,6,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(1,4,4,0,0,0);
      LED(4,4,5,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(0,4,4,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      delay(mil);
      LED(6,3,5,0,0,0);
      LED(7,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(7,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(2,4,4,0,0,0);
      LED(5,4,5,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(1,4,4,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      delay(mil);
      if(count > 0){
      LED(1,7,5,0,0,0);
      LED(1,7,4,0,0,0);
      LED(3,7,3,0,0,0);
      LED(3,7,2,0,0,0);
      LED(5,7,1,0,0,0);
      LED(5,7,0,0,0,0);
      LED(7,6,0,0,0,0);
      LED(7,5,0,0,0,0);
      }
      LED(1,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(1,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(3,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(3,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(5,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(5,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(7,3,5,0,0,0);
      LED(3,4,5,0,0,0);
      LED(6,4,5,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(2,4,4,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      delay(mil);
      LED(7,1,6,0,0,0);
      LED(7,2,6,0,0,0);
      LED(4,4,5,0,0,0);
      LED(7,4,5,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(0,4,4,0,0,0);
      LED(3,5,5,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      if(sh + 14 >= 18){
        sh -= 4;
      }else{
        sh += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,7,5,0,0,0);
      LED(0,7,4,0,0,0);
      LED(2,7,3,0,0,0);
      LED(2,7,2,0,0,0);
      LED(4,7,1,0,0,0);
      LED(4,7,0,0,0,0);
      LED(6,6,0,0,0,0);
      LED(6,5,0,0,0,0);
      }
      LED(0,0,2,redFrame[sb],greenFrame[sb],blueFrame[sb]);//29
      LED(0,0,3,redFrame[sb],greenFrame[sb],blueFrame[sb]);
      LED(2,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(2,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(4,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(4,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(6,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(6,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(5,4,5,0,0,0);
      LED(7,3,6,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(7,4,6,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(1,4,4,0,0,0);
      LED(4,5,5,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(0,4,4,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      delay(mil);
      LED(6,4,5,0,0,0);
      LED(7,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(7,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(2,4,4,0,0,0);
      LED(5,5,5,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(1,4,4,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      delay(mil);
      if(count > 0){
      LED(1,7,3,0,0,0);
      LED(1,7,2,0,0,0);
      LED(3,7,1,0,0,0);
      LED(3,7,0,0,0,0);
      LED(5,6,0,0,0,0);
      LED(5,5,0,0,0,0);
      LED(7,4,0,0,0,0);
      LED(7,3,0,0,0,0);
      }
      LED(1,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(1,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(3,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(3,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(5,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(5,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(7,4,5,0,0,0);
      LED(3,5,5,0,0,0);
      LED(6,5,5,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(2,4,4,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      delay(mil);
      LED(7,3,6,0,0,0);
      LED(7,4,6,0,0,0);
      LED(4,5,5,0,0,0);
      LED(7,5,5,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(0,4,4,0,0,0);
      LED(3,5,5,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      if(si + 14 >= 18){
        si -= 4;
      }else{
        si += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,7,3,0,0,0);
      LED(0,7,2,0,0,0);
      LED(2,7,1,0,0,0);
      LED(2,7,0,0,0,0);
      LED(4,6,0,0,0,0);
      LED(4,5,0,0,0,0);
      LED(6,4,0,0,0,0);
      LED(6,3,0,0,0,0);
      }
      LED(0,0,4,redFrame[sc],greenFrame[sc],blueFrame[sc]);//33
      LED(0,0,5,redFrame[sc],greenFrame[sc],blueFrame[sc]);
      LED(2,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(2,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(4,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(4,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(6,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(6,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(5,5,5,0,0,0);
      LED(7,5,6,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(7,6,6,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(1,4,4,0,0,0);
      LED(4,5,5,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(0,4,4,redFrame[si],greenFrame[si],blueFrame[si]);
      delay(mil);
      LED(6,5,5,0,0,0);
      LED(7,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(7,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(2,4,4,0,0,0);
      LED(5,5,5,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(1,4,4,redFrame[si],greenFrame[si],blueFrame[si]);
      delay(mil);
      if(count > 0){
      LED(1,7,1,0,0,0);
      LED(1,7,0,0,0,0);
      LED(3,6,0,0,0,0);
      LED(3,5,0,0,0,0);
      LED(5,4,0,0,0,0);
      LED(5,3,0,0,0,0);
      LED(7,2,0,0,0,0);
      LED(7,1,0,0,0,0);
      }
      LED(1,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(1,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(3,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(3,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(5,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(5,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(7,5,5,0,0,0);
      LED(3,5,5,0,0,0);
      LED(6,5,5,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(2,4,4,redFrame[si],greenFrame[si],blueFrame[si]);
      delay(mil);
      LED(7,5,6,0,0,0);
      LED(7,6,6,0,0,0);
      LED(4,5,5,0,0,0);
      LED(7,5,5,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(0,4,4,0,0,0);
      LED(3,5,4,redFrame[si],greenFrame[si],blueFrame[si]);
      if(sj + 14 >= 18){
        sj -= 4;
      }else{
        sj += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,7,1,0,0,0);
      LED(0,7,0,0,0,0);
      LED(2,6,0,0,0,0);
      LED(2,5,0,0,0,0);
      LED(4,4,0,0,0,0);
      LED(4,3,0,0,0,0);
      LED(6,2,0,0,0,0);
      LED(6,1,0,0,0,0);
      }
      LED(0,0,6,redFrame[sd],greenFrame[sd],blueFrame[sd]);//37
      LED(0,0,7,redFrame[sd],greenFrame[sd],blueFrame[sd]);
      LED(2,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(2,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(4,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(4,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(6,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(6,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(5,5,5,0,0,0);
      LED(7,6,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(1,4,4,0,0,0);
      LED(4,5,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(0,4,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      delay(mil);
      LED(6,5,5,0,0,0);
      LED(7,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(7,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(2,4,4,0,0,0);
      LED(5,5,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(1,4,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      delay(mil);
      if(count > 0){
      LED(1,6,0,0,0,0);
      LED(1,5,0,0,0,0);
      LED(3,4,0,0,0,0);
      LED(3,3,0,0,0,0);
      LED(5,2,0,0,0,0);
      LED(5,1,0,0,0,0);
      }
      LED(7,0,0,0,0,0);
      LED(7,0,1,0,0,0);
      LED(1,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(1,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(3,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(3,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(5,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(5,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(7,5,5,0,0,0);
      LED(3,5,4,0,0,0);
      LED(6,5,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(2,4,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      delay(mil);
      LED(7,6,6,0,0,0);
      LED(4,5,4,0,0,0);
      LED(7,5,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(0,4,3,0,0,0);
      LED(3,5,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      if(sk + 14 >= 18){
        sk -= 4;
      }else{
        sk += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,6,0,0,0,0);
      LED(0,5,0,0,0,0);
      LED(2,4,0,0,0,0);
      LED(2,3,0,0,0,0);
      LED(4,2,0,0,0,0);
      LED(4,1,0,0,0,0);
      }
      LED(6,0,0,0,0,0);                                    //41 start clearing sa
      LED(6,0,1,0,0,0);
      LED(0,1,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(0,2,7,redFrame[se],greenFrame[se],blueFrame[se]);
      LED(2,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(2,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(4,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(4,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(6,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(6,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(5,5,4,0,0,0);
      LED(7,6,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(7,6,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(1,4,3,0,0,0);
      LED(4,5,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(0,4,3,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      delay(mil);
      LED(6,5,4,0,0,0);
      LED(7,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(7,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(2,4,3,0,0,0);
      LED(5,5,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(1,4,3,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      delay(mil);
      if(count > 0){
      LED(1,4,0,0,0,0);
      LED(1,3,0,0,0,0);
      LED(3,2,0,0,0,0);
      LED(3,1,0,0,0,0);
      }
      LED(5,0,0,0,0,0);                                    
      LED(5,0,1,0,0,0);
      LED(7,0,2,0,0,0);                                    
      LED(7,0,3,0,0,0);
      LED(1,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(1,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(3,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(3,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(5,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(5,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(7,5,4,0,0,0);
      LED(3,5,3,0,0,0);
      LED(6,5,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(2,4,3,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      delay(mil);
      LED(7,6,4,0,0,0);
      LED(7,6,5,0,0,0);
      LED(4,5,3,0,0,0);
      LED(7,5,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(0,4,3,0,0,0);
      LED(3,5,2,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      if(sl + 14 >= 18){
        sl -= 4;
      }else{
        sl += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,4,0,0,0,0);
      LED(0,3,0,0,0,0);
      LED(2,2,0,0,0,0);
      LED(2,1,0,0,0,0);
      }
      LED(4,0,0,0,0,0);                                    //45 clearing sb      
      LED(4,0,1,0,0,0);
      LED(6,0,2,0,0,0);                                    
      LED(6,0,3,0,0,0);
      LED(0,3,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(0,4,7,redFrame[sf],greenFrame[sf],blueFrame[sf]);
      LED(2,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(2,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(4,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(4,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(6,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(6,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(5,5,3,0,0,0);
      LED(7,6,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(7,6,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(1,4,3,0,0,0);
      LED(4,5,2,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(0,4,3,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      delay(mil);
      LED(6,5,3,0,0,0);
      LED(7,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(7,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(2,4,3,0,0,0);
      LED(5,5,2,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(1,4,3,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      delay(mil);
      if(count > 0){
      LED(1,2,0,0,0,0);
      LED(1,1,0,0,0,0);
      }
      LED(3,0,0,0,0,0);                                       
      LED(3,0,1,0,0,0);
      LED(5,0,2,0,0,0);                                    
      LED(5,0,3,0,0,0);
      LED(7,0,4,0,0,0);
      LED(7,0,5,0,0,0);
      LED(1,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(1,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(3,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(3,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(5,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(5,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(7,5,3,0,0,0);
      LED(3,5,2,0,0,0);
      LED(6,5,2,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(2,4,3,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      delay(mil);
      LED(7,6,2,0,0,0);
      LED(7,6,3,0,0,0);
      LED(4,5,2,0,0,0);
      LED(7,5,2,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(0,4,3,0,0,0);
      LED(3,4,2,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      if(sm + 14 >= 18){
        sm -= 4;
      }else{
        sm += 14;
      }
      delay(mil);
      if(count > 0){
      LED(0,2,0,0,0,0);
      LED(0,1,0,0,0,0);
      }
      LED(2,0,0,0,0,0);                                    //49 clearing sc
      LED(2,0,1,0,0,0);
      LED(4,0,2,0,0,0);                                    
      LED(4,0,3,0,0,0);
      LED(6,0,4,0,0,0);
      LED(6,0,5,0,0,0);
      LED(0,5,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(0,6,7,redFrame[sg],greenFrame[sg],blueFrame[sg]);
      LED(2,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(2,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(4,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(4,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(6,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(6,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(5,5,2,0,0,0);
      LED(7,6,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(1,4,3,0,0,0);
      LED(4,4,2,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(0,3,3,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      delay(mil);
      LED(6,5,2,0,0,0);
      LED(7,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(7,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(2,4,3,0,0,0);
      LED(5,4,2,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(1,3,3,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      delay(mil);
      LED(1,0,0,0,0,0);                                       
      LED(1,0,1,0,0,0);
      LED(3,0,2,0,0,0);                                    
      LED(3,0,3,0,0,0);
      LED(5,0,4,0,0,0);
      LED(5,0,5,0,0,0);
      LED(7,0,6,0,0,0);
      LED(7,0,7,0,0,0);
      LED(1,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(1,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(3,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(3,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(5,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(5,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(7,5,2,0,0,0);
      LED(3,4,2,0,0,0);
      LED(6,4,2,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(2,3,3,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      delay(mil);
      LED(7,6,1,0,0,0);
      LED(4,4,2,0,0,0);
      LED(7,4,2,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(0,3,3,0,0,0);
      LED(3,3,2,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      if(sn + 14 >= 18){
        sn -= 4;
      }else{
        sn += 14;
      }
      delay(mil);
      LED(0,0,0,0,0,0);                                     //53 clearing sd, sa cleared fully                                        
      LED(0,0,1,0,0,0);
      LED(2,0,2,0,0,0);                                    
      LED(2,0,3,0,0,0);
      LED(4,0,4,0,0,0);
      LED(4,0,5,0,0,0);
      LED(6,0,6,0,0,0);
      LED(6,0,7,0,0,0);
      LED(0,7,7,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(0,7,6,redFrame[sh],greenFrame[sh],blueFrame[sh]);
      LED(2,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(2,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(4,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(4,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(6,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(6,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(5,4,2,0,0,0);
      LED(7,5,1,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(7,6,1,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(1,3,3,0,0,0);
      LED(4,3,2,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(0,3,3,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      delay(mil);
      LED(6,4,2,0,0,0);
      LED(7,5,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(7,6,0,redFrame[sl],greenFrame[sl],blueFrame[sl]);
      LED(2,3,3,0,0,0);
      LED(5,3,2,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(1,3,3,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      delay(mil);
      LED(1,0,2,0,0,0);                                    
      LED(1,0,3,0,0,0);
      LED(3,0,4,0,0,0);
      LED(3,0,5,0,0,0);
      LED(5,0,6,0,0,0);
      LED(5,0,7,0,0,0);
      LED(7,1,7,0,0,0);
      LED(7,2,7,0,0,0);
      LED(1,7,4,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(1,7,5,redFrame[si],greenFrame[si],blueFrame[si]);
      LED(3,7,3,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(3,7,2,redFrame[sj],greenFrame[sj],blueFrame[sj]);
      LED(5,7,0,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(5,7,1,redFrame[sk],greenFrame[sk],blueFrame[sk]);
      LED(7,4,2,0,0,0);
      LED(3,3,2,0,0,0);
      LED(6,3,2,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(2,3,3,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      delay(mil);
      LED(7,5,1,0,0,0);
      LED(7,6,1,0,0,0);
      LED(4,3,2,0,0,0);
      LED(7,3,2,redFrame[sm],greenFrame[sm],blueFrame[sm]);
      LED(0,3,3,0,0,0);
      LED(3,2,2,redFrame[sn],greenFrame[sn],blueFrame[sn]);
      count++;
  }//end while
  
}//end rainbowFountain

#endif

