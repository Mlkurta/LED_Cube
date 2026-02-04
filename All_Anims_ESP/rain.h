#ifndef RAIN_H
#define RAIN_H

/*
by Kevin Darrah
www.kevindarrah.comcl
kevin@kevindarrah.com
*/

#include "LED.h"

extern unsigned long start; 

void rainVersionTwo(){//****rainVersionTwo****rainVersionTwo****rainVersionTwo****rainVersionTwo****rainVersionTwo
  int x[64], y[64], z[64], addr, leds=32, bright=1, ledcolor, colowheel, ii, jj, kk;
  int xx[64], yy[64], zz[64], xold[64], yold[64], zold[64], xyoung[64], yyoung[64], zyoung[64], xstale[64],
  ystale[64], zstale[64], slowdown;
  
  for(addr=0; addr<64; addr++){
    x[addr]=random(8);
    y[addr]=random(8);
    z[addr]=random(8);
    xx[addr]=random(16);
    yy[addr]=random(16);
    zz[addr]=random(16);     
  }
  
  start=millis();
  while(millis()-start<10000){
  //wipe_out();
  //for(addr=0; addr<leds; addr++)
  //LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
  
if(ledcolor<20000){ 
  for(addr=0; addr<leds; addr++){
    LED(0, xold[addr], yold[addr], 0, 0, 0);
  if(z[addr]>=7)
  LED(z[addr], x[addr], y[addr], 0, 15, 0);
  if(z[addr]==6)
  LED(z[addr], x[addr], y[addr], 0, 15, 0);
   if(z[addr]==5)
  LED(z[addr], x[addr], y[addr], 0, 15, 0);
   if(z[addr]==4)
  LED(z[addr], x[addr], y[addr], 0, 15, 0); 
    if(z[addr]==3)
  LED(z[addr], x[addr], y[addr], 0, 15, 0);
    if(z[addr]==2)
  LED(z[addr], x[addr], y[addr], 0, 15, 0);
    if(z[addr]==1)
  LED(z[addr], x[addr], y[addr], 0, 15, 0);
    if(z[addr]<=0)
  LED(0, x[addr], y[addr], 0, 10, 0);
    if(z[addr]<=-4)
  LED(0, x[addr], y[addr], 0, 5, 0);
    if(z[addr]<=-10)
  LED(0, x[addr], y[addr], 0, 1, 0);
}}//200
/*
  if(ledcolor>=200&&ledcolor<300){
  for(addr=0; addr<leds; addr++){
    LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
  if(z[addr]>=7)
  LED(z[addr], x[addr], y[addr], 15, 15, 0);
  if(z[addr]==6)
  LED(z[addr], x[addr], y[addr], 10, 10, 0);
   if(z[addr]==5)
  LED(z[addr], x[addr], y[addr], 15, 5, 0);
   if(z[addr]==4)
  LED(z[addr], x[addr], y[addr], 15, 2, 0); 
    if(z[addr]==3)
  LED(z[addr], x[addr], y[addr], 15, 1, 0);
    if(z[addr]==2)
  LED(z[addr], x[addr], y[addr], 15, 0, 0);
    if(z[addr]==1)
  LED(z[addr], x[addr], y[addr], 12, 0, 0);
    if(z[addr]<=0)
  LED(0, x[addr], y[addr], 10, 0, 0);
}}//300

    if(ledcolor>=300&&ledcolor<400){

  }
     if(ledcolor>=500&&ledcolor<600){

}  
*/
  ledcolor++;
if(ledcolor>=100)
ledcolor=0;
    for(addr=0; addr<leds; addr++){
      xold[addr]=x[addr];
      yold[addr]=y[addr];
      zold[addr]=z[addr];
   } 
  
  
  delay(90);
  
  for(addr=0; addr<leds; addr++)
    LED(z[addr], x[addr], y[addr], 0, 0, 0);
    for(addr=0; addr<leds; addr++){
      
      //slowdown = random(2);
      //if(bitRead(z[addr],0))
      z[addr] = z[addr]-1;
      //x[addr] = x[addr]+1;
      //y[addr] = y[addr]+1;
  if(z[addr]<random(-100,0)){
    x[addr]=random(8);
    y[addr]=random(8);
    int select=random(3);
    if(select==0){
    xx[addr]=0;
    zz[addr]=random(16);
    yy[addr]=random(16);
    //zz[addr]=0;
    }
    if(select==1){
    xx[addr]=random(16);
    zz[addr]=0;
    yy[addr]=random(16);
    //yy[addr]=0;
    }
    if(select==2){
    xx[addr]=random(16);
    zz[addr]=random(16);
    yy[addr]=0;
    
    
    }    
   z[addr]=7; 
   
  }//-check
  }//add

  
  }//while
 
}//rainv2

#endif

