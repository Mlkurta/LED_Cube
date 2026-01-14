#ifndef FIREWORK_H
#define FIREWORK_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"

#define COORDS 2
#define NUMWORKS 3

extern const short grid[][COORDS], colorWheel[];
extern unsigned long start;

void splode(int, int, int, int);
void shoot(int, int);

void fireWorks(){
int t = 75;
int i, z = 0;
int p[NUMWORKS];
int clr[NUMWORKS];
int cnt[NUMWORKS];
int interval[NUMWORKS];
int h[NUMWORKS];
int maxHt[NUMWORKS];
bool phase[NUMWORKS] = {false,false};
start = millis();
  // Set time to run the animation before it resets
  while(millis() - start < 15000){
    for(i=0;i<NUMWORKS;i++){
      p[i] = random(0,100);
      clr[i] = random(0,12)*3;
      interval[i] = random(0,8);
      h[i] = random(3,8);
      maxHt[i] = h[i] * 2;
      cnt[i] = 50;
      phase[i] = false;
    }
    z = 0;
    while(z < 50){
      if(z == interval[0]){
        cnt[0] = 0;
      }
      if(z == interval[1]){
        cnt[1] = 0;
      }
      if(z == interval[2]){
        cnt[2] = 0;
      }
      if(cnt[0] < 42){
        switch(phase[0]){
          case false:
            if(maxHt[0] >= cnt[0]){
              shoot(cnt[0], p[0]);
              cnt[0]++;
            }else{
              shoot(15,p[0]);
              cnt[0] = 16;
              phase[0] = true;
            }
            break;
          case true:
            splode(cnt[0],p[0],h[0],clr[0]);
            cnt[0]++;
            break;
        }
      }
      if(cnt[1] < 42){
        switch(phase[1]){
          case false:
            if(maxHt[1] >= cnt[1]){
              shoot(cnt[1], p[1]);
              cnt[1]++;
            }else{
              shoot(15,p[1]);
              cnt[1] = 16;
              phase[1] = true;
            }
            break;
          case true:
            splode(cnt[1],p[1],h[1],clr[1]);
            cnt[1]++;
            break;
        }
      }
      if(cnt[2] < 42){
        switch(phase[2]){
          case false:
            if(maxHt[2] >= cnt[2]){
              shoot(cnt[2], p[2]);
              cnt[2]++;
            }else{
              shoot(15,p[2]);
              cnt[2] = 16;
              phase[2] = true;
            }
            break;
          case true:
            splode(cnt[2],p[2],h[2],clr[2]);
            cnt[2]++;
            break;
        }
      }
      z++;
      delay(t);
    }
    clean();
  }
}

void shoot(int cnt, int pos){
  if(pos > 63){
    return;
  }
  switch(cnt){
    case 0:
      LED(0,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 1:
      break;
    case 2:
      LED(0,grid[pos][0],grid[pos][1],0,0,0);
      LED(1,grid[pos][0],grid[pos][1],7,0,0);
    case 3:
      break;
    case 4:
      LED(1,grid[pos][0],grid[pos][1],0,0,0);
      LED(2,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 5:
      break;
    case 6:
      LED(2,grid[pos][0],grid[pos][1],0,0,0);
      LED(3,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 7:
      break;
    case 8:
      LED(3,grid[pos][0],grid[pos][1],0,0,0);
      LED(4,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 9:
      break;
    case 10:
      LED(4,grid[pos][0],grid[pos][1],0,0,0);
      LED(5,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 11:
      break;
    case 12:
      LED(5,grid[pos][0],grid[pos][1],0,0,0);
      LED(6,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 13:
      break;
    case 14:
      LED(6,grid[pos][0],grid[pos][1],0,0,0);
      LED(7,grid[pos][0],grid[pos][1],7,0,0);
      break;
    case 15:
      for(int g=3;g<8;g++){
        LED(g,grid[pos][0],grid[pos][1],0,0,0);
      }
      break;
  }
}

void splode(int cnt, int pos, int ht, int clr){
   switch(cnt){
    case 16:
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0],grid[pos][1],15,10,3);
        LED(ht+1,grid[pos][0],grid[pos][1],15,10,3);
        LED(ht-1,grid[pos][0],grid[pos][1],15,10,3);
      }
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+1,grid[pos][1],15,10,3);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-1,grid[pos][1],15,10,3);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+1,15,10,3);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-1,15,10,3);
      }
      break;
    case 17:
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0],grid[pos][1],0,0,0);
        LED(ht+1,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-1,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      break;
    case 18:
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht+1,grid[pos][0],grid[pos][1],0,0,0);
        LED(ht-1,grid[pos][0],grid[pos][1],0,0,0);
        LED(ht+2,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-2,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+1,grid[pos][1],0,0,0);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-1,grid[pos][1],0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+1,0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-1,0,0,0);
      }
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht+1,grid[pos][0]+1,grid[pos][1]+1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-1,grid[pos][0]+1,grid[pos][1]+1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht+1,grid[pos][0]-1,grid[pos][1]+1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-1,grid[pos][0]-1,grid[pos][1]+1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht+1,grid[pos][0]+1,grid[pos][1]-1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-1,grid[pos][0]+1,grid[pos][1]-1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht+1,grid[pos][0]-1,grid[pos][1]-1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-1,grid[pos][0]-1,grid[pos][1]-1,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+2,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-2,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }      
      break;
    case 19:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht+2,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-3,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht+1,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-2,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht+1,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-2,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht+1,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-2,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht+1,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-2,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      break;
    case 20:
      break;    
    case 21:      
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht+1,grid[pos][0]+1,grid[pos][1]+1,0,0,0);
        LED(ht-1,grid[pos][0]+1,grid[pos][1]+1,0,0,0);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1]+1 > -1) && (grid[pos][1]+1 < 8)){
        LED(ht+1,grid[pos][0]-1,grid[pos][1]+1,0,0,0);
        LED(ht-1,grid[pos][0]-1,grid[pos][1]+1,0,0,0);
      }
      if((grid[pos][0]+1 > -1) && (grid[pos][0]+1 < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht+1,grid[pos][0]+1,grid[pos][1]-1,0,0,0);
        LED(ht-1,grid[pos][0]+1,grid[pos][1]-1,0,0,0);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1]-1 > -1) && (grid[pos][1]-1 < 8)){
        LED(ht+1,grid[pos][0]-1,grid[pos][1]-1,0,0,0);
        LED(ht-1,grid[pos][0]-1,grid[pos][1]-1,0,0,0);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+2,grid[pos][1],0,0,0);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-2,grid[pos][1],0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+2,0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-2,0,0,0);
      }
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht+1,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht - 4 >= 0)){
        LED(ht-4,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht+2,grid[pos][0],grid[pos][1],0,0,0);
        LED(ht-2,grid[pos][0],grid[pos][1],0,0,0); 
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-3,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-3,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-3,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        LED(ht-3,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-1,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-1,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8)){
        LED(ht-1,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8)){
        LED(ht-1,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      break;
    case 22:
      break;
    case 23:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht+2,grid[pos][0]-1,grid[pos][1],0,0,0);
        LED(ht,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht - 3 >= 0)){
        LED(ht-3,grid[pos][0],grid[pos][1],0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht+1,grid[pos][0]+2,grid[pos][1]+2,0,0,0);
        LED(ht-2,grid[pos][0]+2,grid[pos][1]+2,0,0,0);        
        LED(ht-1,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }     
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht+1,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        LED(ht-2,grid[pos][0]-2,grid[pos][1]+2,0,0,0);        
        LED(ht-1,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }       
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht+1,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        LED(ht-2,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        LED(ht-1,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }    
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht+1,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        LED(ht-2,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        LED(ht-1,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }   
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]+3,grid[pos][1],0,0,0);
        LED(ht-2,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-3,grid[pos][1],0,0,0);
        LED(ht-2,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]-3,0,0,0);
        LED(ht-2,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8)){
        LED(ht,grid[pos][0],grid[pos][1]+3,0,0,0);
        LED(ht-2,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      break;
    case 24:
      break;
    case 25:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht+1,grid[pos][0]-1,grid[pos][1],0,0,0);
        LED(ht-1,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht - 4 >= 0)){
        LED(ht-4,grid[pos][0],grid[pos][1],0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]); 
        }
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht,grid[pos][0]+2,grid[pos][1]+2,0,0,0);
        LED(ht-3,grid[pos][0]+2,grid[pos][1]+2,0,0,0);        
        LED(ht-2,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        } 
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        LED(ht-3,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        LED(ht-2,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }       
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        LED(ht-3,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        LED(ht-2,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }    
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        LED(ht-3,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        LED(ht-2,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }   
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-1,grid[pos][0]+3,grid[pos][1],0,0,0);
        LED(ht-3,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-1,grid[pos][0]-3,grid[pos][1],0,0,0);
        LED(ht-3,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8)){
        LED(ht-1,grid[pos][0],grid[pos][1]-3,0,0,0);
        LED(ht-3,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8)){
        LED(ht-1,grid[pos][0],grid[pos][1]+3,0,0,0);
        LED(ht-3,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      break;
    case 26:
      break;
    case 27:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht,grid[pos][0]-1,grid[pos][1],0,0,0);
        LED(ht-2,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht - 5 >= 0)){
        LED(ht-5,grid[pos][0],grid[pos][1],0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0],grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]); 
        }
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht-1,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+2,grid[pos][1]+2,0,0,0); 
        }
        LED(ht-3,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        } 
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht-1,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        }
        LED(ht-3,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }       
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht-1,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        }
        LED(ht-3,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }    
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht-1,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-2,grid[pos][1]-2,0,0,0); 
        }
        LED(ht-3,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }   
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-2,grid[pos][0]+3,grid[pos][1],0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-2,grid[pos][0]-3,grid[pos][1],0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8)){
        LED(ht-2,grid[pos][0],grid[pos][1]-3,0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8)){
        LED(ht-2,grid[pos][0],grid[pos][1]+3,0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      break;
    case 28:
      break;
    case 29:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-1,grid[pos][0]-1,grid[pos][1],0,0,0);
        LED(ht-3,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht - 6 >= 0)){
        LED(ht-6,grid[pos][0],grid[pos][1],0,0,0);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht-2,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+2,grid[pos][1]+2,0,0,0); 
        }
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        } 
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht-2,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        }
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }       
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht-2,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        }
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }    
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht-2,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-2,grid[pos][1]-2,0,0,0); 
        }
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }   
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-3,grid[pos][0]+3,grid[pos][1],0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-3,grid[pos][0]-3,grid[pos][1],0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8)){
        LED(ht-3,grid[pos][0],grid[pos][1]-3,0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8)){
        LED(ht-3,grid[pos][0],grid[pos][1]+3,0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      break;
    case 30:
      break;
    case 31:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-2,grid[pos][0]-1,grid[pos][1],0,0,0);
        if(ht-4 >= 0){
          LED(ht-4,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht - 7 >= 0)){
        LED(ht-7,grid[pos][0],grid[pos][1],0,0,0);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht-3,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+2,grid[pos][1]+2,0,0,0); 
        }
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8)){
        LED(ht-3,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        }
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }      
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht-3,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        }
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8)){
        LED(ht-3,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-2,grid[pos][1]-2,0,0,0); 
        }
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]+3,grid[pos][1],0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]-3,grid[pos][1],0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0],grid[pos][1]-3,0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0],grid[pos][1]+3,0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      break;
    case 32:
      break;
    case 33:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8)){
        LED(ht-3,grid[pos][0]-1,grid[pos][1],0,0,0);
        if(ht-5 >= 0){
          LED(ht-5,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+2,grid[pos][1]+2,0,0,0); 
        }
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        }
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }      
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        }
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-2,grid[pos][1]-2,0,0,0); 
        }
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]+3,grid[pos][1],0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]-3,grid[pos][1],0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-3,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0],grid[pos][1]-3,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0],grid[pos][1]-3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0],grid[pos][1]+3,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0],grid[pos][1]+3,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      break;
    case 34:
      break;
    case 35:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-4 >= 0)){
        LED(ht-4,grid[pos][0]-1,grid[pos][1],0,0,0);
        if(ht-6 >= 0){
          LED(ht-6,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]-2,grid[pos][1]+2,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-2,grid[pos][1]+2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }      
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]+2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-2,grid[pos][1]-2,colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]+3,grid[pos][1],0,0,0);
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]-3,grid[pos][1],0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0],grid[pos][1]-3,0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0],grid[pos][1]+3,0,0,0);
      }
      break;
    case 36:
      break;
    case 37:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-5 >= 0)){
        LED(ht-5,grid[pos][0]-1,grid[pos][1],0,0,0);
        if(ht-7 >= 0){
          LED(ht-7,grid[pos][0]-1,grid[pos][1],colorWheel[clr],colorWheel[clr+1],colorWheel[clr+2]);
        }
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]-2,grid[pos][1]+2,0,0,0);     
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
      }
      if((grid[pos][0]+3 > -1) && (grid[pos][0]+3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0]+3,grid[pos][1],0,0,0);
      }
      if((grid[pos][0]-3 > -1) && (grid[pos][0]-3 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0]-3,grid[pos][1],0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]-3 > -1) && (grid[pos][1]-3 < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0],grid[pos][1]-3,0,0,0);
      }
      if((grid[pos][0] > -1) && (grid[pos][0] < 8) && (grid[pos][1]+3 > -1) && (grid[pos][1]+3 < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0],grid[pos][1]+3,0,0,0);
      }
      break;
    case 38:
      break;
    case 39:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]-1,grid[pos][1],0,0,0);
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0]+2,grid[pos][1]+2,0,0,0);      
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]+2 > -1) && (grid[pos][1]+2 < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0]-2,grid[pos][1]+2,0,0,0);     
      }
      if((grid[pos][0]+2 > -1) && (grid[pos][0]+2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0]+2,grid[pos][1]-2,0,0,0);
      }
      if((grid[pos][0]-2 > -1) && (grid[pos][0]-2 < 8) && (grid[pos][1]-2 > -1) && (grid[pos][1]-2 < 8) && (ht-7 >= 0)){
        LED(ht-7,grid[pos][0]-2,grid[pos][1]-2,0,0,0);
      }
      break;
    case 40:
      break;
    case 41:
      if((grid[pos][0]-1 > -1) && (grid[pos][0]-1 < 8) && (grid[pos][1] > -1) && (grid[pos][1] < 8) && (ht-6 >= 0)){
        LED(ht-6,grid[pos][0]-1,grid[pos][1],0,0,0);
      }
      break;
   }
}

#endif

