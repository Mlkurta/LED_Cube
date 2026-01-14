#ifndef COLOR_WHEEL_H
#define COLOR_WHEEL_H

/*
by Kevin Darrah
www.kevindarrah.comcl
kevin@kevindarrah.com
*/

#include "LED.h"

extern unsigned long start;

void color_wheelTWO(){//*****colorWheelTwo*****colorWheelTwo*****colorWheelTwo*****colorWheelTwo*****colorWheelTwo
  int xx, yy, zz, rr=1, gg=1, bb=1, ranx, rany ,ranz, select, swiper, time_delay = 40;
  
        start=millis();
      
  while(millis()-start<10000){
    swiper=random(6);
    select=random(3);
    if(select==0){
     ranx=0;
     rany=random(16);
     ranz=random(16);}
    if(select==1){
     ranx=random(16);
     rany=0;
     ranz=random(16);}   
      if(select==2){
     ranx=random(16);
     rany=random(16);
     ranz=0;}  
    
     
    if(swiper==0){
    for(yy=0;yy<8;yy++){//left to right
    for(xx=0;xx<8;xx++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(time_delay);
 }}
    if(swiper==1){//bot to top
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(time_delay);
 }}  
    if(swiper==2){//back to front
    for(zz=0;zz<8;zz++){
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(time_delay);
}}    
    if(swiper==3){
    for(yy=7;yy>=0;yy--){//right to left
    for(xx=0;xx<8;xx++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(time_delay);
}}
    if(swiper==4){//top to bot
    for(xx=7;xx>=0;xx--){
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
 delay(time_delay);
}}  
    if(swiper==5){//front to back
    for(zz=7;zz>=0;zz--){
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(time_delay);
}}
  
  
  
  
  }//while
    
}//color wheel

#endif 

