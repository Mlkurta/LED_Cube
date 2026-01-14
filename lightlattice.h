#ifndef LIGHTLATTICE_H
#define LIGHTLATTICE_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"

#define NUMLINES 4
#define COORDS 2

void drawKCol(int, int, int, bool);
void drawJCol(int, int, int, bool);
void drawCol(int, int, int, bool);
void kExclude(int *, int *, int, int, int);
void jExclude(int *, int *, int, int, int);
void iExclude(int *, int *, int, int, int);

extern unsigned long start, sTwo;
extern const short colorWheel[];
extern const short gridLat[][COORDS];
extern const int w[][8];
const uint32_t TICK_DELAY = 40;

void lightLattice(){
  int a[NUMLINES], aInt[NUMLINES], aCnt[NUMLINES], aOr[NUMLINES], clr[NUMLINES],g, iIndex = 0, jIndex = 0, kIndex = 0, i,j=0, b,c, pass = 0;
  bool dir[NUMLINES], go = false;
  int numAct = 0, cnt = 0;
  int iTindex = 0, jTindex = 0, kTindex = 0;
  int iNum = 0, jNum = 0, kNum = 0;
  int dIsect[64] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64};
  int dJsect[64] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64};
  int dKsect[64] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,
                    64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64};
  int tI[24] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,};
  int tJ[24] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,};
  int tK[24] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,};
  int tIC = 0, tJC = 0, tKC = 0;

  for(i=0;i<NUMLINES;i++){
    a[i] = 0;
    aInt[i] = 0;
    aCnt[i] = 0;
    aOr[i] = 0;
    clr[i] = 0;
  }
  i=0;
  start = millis();
  while(millis()-start<30000){
    if(numAct < 4){
      a[i] = random(0,64);
      clr[i] = random(0,12)*3;
      aInt[i] = random(0,16);
      if(aInt[i]%2 == 1){
        dir[i] = false;
      }else{
        dir[i] = true;
      }
      aOr[i] = i%3;
      switch(aOr[i]){
        case 0:
          while(!go){
            for(b=0;b<64;b++){
              if(a[i] == dIsect[b]){
                pass++;
              }
            }
            if(pass > 0){
              a[i] = random(0,64);
              pass = 0;
            }else{
              go = true;
              pass = 0;
            }
          }
          go = false;
          dIsect[iIndex] = a[i];
          tI[tIC] = iIndex;
          tIC++;
          tI[tIC] = 1;
          tIC++;
          iIndex++;
          if(iIndex == 64){
            iIndex = 0;
          }
          if(jIndex + 8 >= 64){
            jIndex = 0;
          }
          if(kIndex + 8 >= 64){
            kIndex = 0;
          }
          tJ[tJC] = jIndex;
          tJC++;
          tJ[tJC] = 8;
          tJC++;
          tK[tKC] = kIndex;
          tKC++;
          tK[tKC] = 8;
          tKC++;
          iExclude(dJsect,dKsect,jIndex,kIndex,a[i]);
          jIndex += 8;
          kIndex += 8;
          break;
        case 1:
          while(!go){
            for(b=0;b<64;b++){
              if(a[i] == dJsect[b]){
                pass++;
              }
            }
            if(pass > 0){
              a[i] = random(0,64);
              pass = 0;
            }else{
              go = true;
              pass = 0;
            }
          }
          go = false;
          dJsect[jIndex] = a[i];
          tJ[tJC] = jIndex;
          tJC++;
          tJ[tJC] = 1;
          tJC++;
          jIndex++;
          if(jIndex == 64){
            jIndex = 0;
          }
          if(iIndex + 8 >= 64){
            iIndex = 0;
          }
          if(kIndex + 8 >= 64){
            kIndex = 0;
          }
          tI[tIC] = iIndex;
          tIC++;
          tI[tIC] = 8;
          tIC++;
          tK[tKC] = kIndex;
          tKC++;
          tK[tKC] = 8;
          tKC++;
          jExclude(dIsect,dKsect,iIndex,kIndex,a[i]);
          iIndex += 8;
          kIndex += 8;
          break;
        case 2:   
          while(!go){
            for(b=0;b<64;b++){
              if(a[i] == dKsect[b]){
                pass++;
              }
            }
            if(pass > 0){
              a[i] = random(0,64);
              pass = 0;
            }else{
              go = true;
              pass = 0;
            }
          }
          go = false;
          dKsect[kIndex] = a[i];
          kIndex++;
          if(kIndex == 64){
            kIndex = 0;
          }
          if(iIndex + 8 >= 64){
            iIndex = 0;
          }
          if(jIndex + 8 >= 64){
            jIndex = 0;
          }
          kExclude(dIsect,dJsect,iIndex,jIndex,a[i]);
          iIndex += 8;
          jIndex += 8;
          break;
      }
      numAct++;
      if(i == 3){
        i = 0; 
      }else{
        i++;
      }
    }
    for(b=0;b<numAct;b++){
      switch(aOr[b]){
        case 0:
          drawCol(aCnt[b], a[b], clr[b], dir[b]);
          aCnt[b]++;
          break;
        case 1:
          drawJCol(aCnt[b], a[b], clr[b], dir[b]);
          aCnt[b]++;
          break;
        case 2:
          drawKCol(aCnt[b], a[b], clr[b], dir[b]);
          aCnt[b]++;
          break;
      }
      if(aCnt[b] == 12){
        switch(aOr[b]){
          case 0:
            if(jTindex + 8 >= 64){
              jTindex = 0;
            }
            if(kTindex + 8 >= 64){
              kTindex = 0;
            }
            dIsect[iTindex] = 64;
            iTindex++;
            if(iTindex == 64){
              iTindex = 0;
            }
            for(c=0;c<8;c++){
              dJsect[jTindex+c] = 64;
              dKsect[kTindex+c] = 64;
            }
            jTindex += 8;
            kTindex += 8;
            numAct--;
            i = b;
            aCnt[b] = 0;
            break;
          case 1:
            if(iTindex + 8 >= 64){
              iTindex = 0;
            }
            if(kTindex + 8 >= 64){
              kTindex = 0;
            }
            dJsect[jTindex] = 64;
            jTindex++;
            if(jTindex == 64){
              jTindex = 0;
            }
            for(c=0;c<8;c++){
              dIsect[iTindex+c] = 64;
              dKsect[kTindex+c] = 64;
            }
            iTindex += 8;
            kTindex += 8;
            numAct--;
            i = b;
            aCnt[b] = 0;
            break;
          case 2:
            if(iTindex + 8 >= 64){
              iTindex = 0;
            }
            if(jTindex + 8 >= 64){
              jTindex = 0;
            }
            dKsect[kTindex] = 64;
            kTindex++;
            if(kTindex == 64){
              kTindex = 0;
            }
            for(c=0;c<8;c++){
              dIsect[iTindex+c] = 64;
              dJsect[jTindex+c] = 64;
            }
            iTindex += 8;
            jTindex += 8;
            numAct--;
            i = b;
            aCnt[b] = 0;
            break;
        }
      }
    }
    delay(TICK_DELAY);
  }
}

void iExclude(int *dJsect, int *dKsect, int jIndex, int kIndex, int a){
   if((a >= 0 ) && (a < 8)){
     dJsect[jIndex+0] = 0;
     dJsect[jIndex+1] = 1;
     dJsect[jIndex+2] = 2;
     dJsect[jIndex+3] = 3;
     dJsect[jIndex+4] = 4;
     dJsect[jIndex+5] = 5;
     dJsect[jIndex+6] = 6;
     dJsect[jIndex+7] = 7;
   }else if((a >= 8 ) && (a < 16)){
     dJsect[jIndex+0] = 8;
     dJsect[jIndex+1] = 9;
     dJsect[jIndex+2] = 10;
     dJsect[jIndex+3] = 11;
     dJsect[jIndex+4] = 12;
     dJsect[jIndex+5] = 13;
     dJsect[jIndex+6] = 14;
     dJsect[jIndex+7] = 15;
   }else if((a >= 16 ) && (a < 24)){
     dJsect[jIndex+0] = 16;
     dJsect[jIndex+1] = 17;
     dJsect[jIndex+2] = 18;
     dJsect[jIndex+3] = 19;
     dJsect[jIndex+4] = 20;
     dJsect[jIndex+5] = 21;
     dJsect[jIndex+6] = 22;
     dJsect[jIndex+7] = 23;
   }else if((a >= 24 ) && (a < 32)){
     dJsect[jIndex+0] = 24;
     dJsect[jIndex+1] = 25;
     dJsect[jIndex+2] = 26;
     dJsect[jIndex+3] = 27;
     dJsect[jIndex+4] = 28;
     dJsect[jIndex+5] = 29;
     dJsect[jIndex+6] = 30;
     dJsect[jIndex+7] = 31;
   }else if((a >= 32 ) && (a < 40)){
     dJsect[jIndex+0] = 32;
     dJsect[jIndex+1] = 33;
     dJsect[jIndex+2] = 34;
     dJsect[jIndex+3] = 35;
     dJsect[jIndex+4] = 36;
     dJsect[jIndex+5] = 37;
     dJsect[jIndex+6] = 38;
     dJsect[jIndex+7] = 39;
   }else if((a >= 40 ) && (a < 48)){
     dJsect[jIndex+0] = 40;
     dJsect[jIndex+1] = 41;
     dJsect[jIndex+2] = 42;
     dJsect[jIndex+3] = 43;
     dJsect[jIndex+4] = 44;
     dJsect[jIndex+5] = 45;
     dJsect[jIndex+6] = 46;
     dJsect[jIndex+7] = 47;
   }
   else if((a >= 48 ) && (a < 56)){
     dJsect[jIndex+0] = 48;
     dJsect[jIndex+1] = 49;
     dJsect[jIndex+2] = 50;
     dJsect[jIndex+3] = 51;
     dJsect[jIndex+4] = 52;
     dJsect[jIndex+5] = 53;
     dJsect[jIndex+6] = 54;
     dJsect[jIndex+7] = 55;
   }
   else if((a >= 56 ) && (a < 64)){
     dJsect[jIndex+0] = 56;
     dJsect[jIndex+1] = 57;
     dJsect[jIndex+2] = 58;
     dJsect[jIndex+3] = 59;
     dJsect[jIndex+4] = 60;
     dJsect[jIndex+5] = 61;
     dJsect[jIndex+6] = 62;
     dJsect[jIndex+7] = 63;
   }
   switch(a%8){
    case 0:
      dKsect[kIndex+0] = 0;
      dKsect[kIndex+1] = 1;
      dKsect[kIndex+2] = 2;
      dKsect[kIndex+3] = 3;
      dKsect[kIndex+4] = 4;
      dKsect[kIndex+5] = 5;
      dKsect[kIndex+6] = 6;
      dKsect[kIndex+7] = 7;
      break;
    case 1:
      dKsect[kIndex+0] = 8;
      dKsect[kIndex+1] = 9;
      dKsect[kIndex+2] = 10;
      dKsect[kIndex+3] = 11;
      dKsect[kIndex+4] = 12;
      dKsect[kIndex+5] = 13;
      dKsect[kIndex+6] = 14;
      dKsect[kIndex+7] = 15;
      break;
    case 2:
      dKsect[kIndex+0] = 16;
      dKsect[kIndex+1] = 17;
      dKsect[kIndex+2] = 18;
      dKsect[kIndex+3] = 19;
      dKsect[kIndex+4] = 20;
      dKsect[kIndex+5] = 21;
      dKsect[kIndex+6] = 22;
      dKsect[kIndex+7] = 23;
      break;
    case 3:
      dKsect[kIndex+0] = 24;
      dKsect[kIndex+1] = 25;
      dKsect[kIndex+2] = 26;
      dKsect[kIndex+3] = 27;
      dKsect[kIndex+4] = 28;
      dKsect[kIndex+5] = 29;
      dKsect[kIndex+6] = 30;
      dKsect[kIndex+7] = 31;
      break;
    case 4:
      dKsect[kIndex+0] = 32;
      dKsect[kIndex+1] = 33;
      dKsect[kIndex+2] = 34;
      dKsect[kIndex+3] = 35;
      dKsect[kIndex+4] = 36;
      dKsect[kIndex+5] = 37;
      dKsect[kIndex+6] = 38;
      dKsect[kIndex+7] = 39;
      break;
    case 5:
      dKsect[kIndex+0] = 40;
      dKsect[kIndex+1] = 41;
      dKsect[kIndex+2] = 42;
      dKsect[kIndex+3] = 43;
      dKsect[kIndex+4] = 44;
      dKsect[kIndex+5] = 45;
      dKsect[kIndex+6] = 46;
      dKsect[kIndex+7] = 47;
      break;
    case 6:
      dKsect[kIndex+0] = 48;
      dKsect[kIndex+1] = 49;
      dKsect[kIndex+2] = 50;
      dKsect[kIndex+3] = 51;
      dKsect[kIndex+4] = 52;
      dKsect[kIndex+5] = 53;
      dKsect[kIndex+6] = 54;
      dKsect[kIndex+7] = 55;
      break;
    case 7:
      dKsect[kIndex+0] = 56;
      dKsect[kIndex+1] = 57;
      dKsect[kIndex+2] = 58;
      dKsect[kIndex+3] = 59;
      dKsect[kIndex+4] = 60;
      dKsect[kIndex+5] = 61;
      dKsect[kIndex+6] = 62;
      dKsect[kIndex+7] = 63;
      break;
   }  
}

void jExclude(int *dIsect, int *dKsect, int iIndex, int kIndex, int a){
  if((a >= 0 ) && (a < 8)){
     dIsect[iIndex+0] = 0;
     dIsect[iIndex+1] = 1;
     dIsect[iIndex+2] = 2;
     dIsect[iIndex+3] = 3;
     dIsect[iIndex+4] = 4;
     dIsect[iIndex+5] = 5;
     dIsect[iIndex+6] = 6;
     dIsect[iIndex+7] = 7;
   }else if((a >= 8 ) && (a < 16)){
     dIsect[iIndex+0] = 8;
     dIsect[iIndex+1] = 9;
     dIsect[iIndex+2] = 10;
     dIsect[iIndex+3] = 11;
     dIsect[iIndex+4] = 12;
     dIsect[iIndex+5] = 13;
     dIsect[iIndex+6] = 14;
     dIsect[iIndex+7] = 15;
   }else if((a >= 16 ) && (a < 24)){
     dIsect[iIndex+0] = 16;
     dIsect[iIndex+1] = 17;
     dIsect[iIndex+2] = 18;
     dIsect[iIndex+3] = 19;
     dIsect[iIndex+4] = 20;
     dIsect[iIndex+5] = 21;
     dIsect[iIndex+6] = 22;
     dIsect[iIndex+7] = 23;
   }else if((a >= 24 ) && (a < 32)){
     dIsect[iIndex+0] = 24;
     dIsect[iIndex+1] = 25;
     dIsect[iIndex+2] = 26;
     dIsect[iIndex+3] = 27;
     dIsect[iIndex+4] = 28;
     dIsect[iIndex+5] = 29;
     dIsect[iIndex+6] = 30;
     dIsect[iIndex+7] = 31;
   }else if((a >= 32 ) && (a < 40)){
     dIsect[iIndex+0] = 32;
     dIsect[iIndex+1] = 33;
     dIsect[iIndex+2] = 34;
     dIsect[iIndex+3] = 35;
     dIsect[iIndex+4] = 36;
     dIsect[iIndex+5] = 37;
     dIsect[iIndex+6] = 38;
     dIsect[iIndex+7] = 39;
   }else if((a >= 40 ) && (a < 48)){
     dIsect[iIndex+0] = 40;
     dIsect[iIndex+1] = 41;
     dIsect[iIndex+2] = 42;
     dIsect[iIndex+3] = 43;
     dIsect[iIndex+4] = 44;
     dIsect[iIndex+5] = 45;
     dIsect[iIndex+6] = 46;
     dIsect[iIndex+7] = 47;
   }
   else if((a >= 48 ) && (a < 56)){
     dIsect[iIndex+0] = 48;
     dIsect[iIndex+1] = 49;
     dIsect[iIndex+2] = 50;
     dIsect[iIndex+3] = 51;
     dIsect[iIndex+4] = 52;
     dIsect[iIndex+5] = 53;
     dIsect[iIndex+6] = 54;
     dIsect[iIndex+7] = 55;
   }
   else if((a >= 56 ) && (a < 64)){
     dIsect[iIndex+0] = 56;
     dIsect[iIndex+1] = 57;
     dIsect[iIndex+2] = 58;
     dIsect[iIndex+3] = 59;
     dIsect[iIndex+4] = 60;
     dIsect[iIndex+5] = 61;
     dIsect[iIndex+6] = 62;
     dIsect[iIndex+7] = 63;
   }
   switch(a%8){
    case 0:
      dKsect[kIndex+0] = 0;
      dKsect[kIndex+1] = 8;
      dKsect[kIndex+2] = 16;
      dKsect[kIndex+3] = 24;
      dKsect[kIndex+4] = 32;
      dKsect[kIndex+5] = 40;
      dKsect[kIndex+6] = 48;
      dKsect[kIndex+7] = 56;
      break;
    case 1:
      dKsect[kIndex+0] = 1;
      dKsect[kIndex+1] = 9;
      dKsect[kIndex+2] = 17;
      dKsect[kIndex+3] = 25;
      dKsect[kIndex+4] = 33;
      dKsect[kIndex+5] = 41;
      dKsect[kIndex+6] = 49;
      dKsect[kIndex+7] = 57;
      break;
    case 2:
      dKsect[kIndex+0] = 2;
      dKsect[kIndex+1] = 10;
      dKsect[kIndex+2] = 18;
      dKsect[kIndex+3] = 26;
      dKsect[kIndex+4] = 34;
      dKsect[kIndex+5] = 42;
      dKsect[kIndex+6] = 50;
      dKsect[kIndex+7] = 58;
      break;
    case 3:
      dKsect[kIndex+0] = 3;
      dKsect[kIndex+1] = 11;
      dKsect[kIndex+2] = 19;
      dKsect[kIndex+3] = 27;
      dKsect[kIndex+4] = 35;
      dKsect[kIndex+5] = 43;
      dKsect[kIndex+6] = 51;
      dKsect[kIndex+7] = 59;
      break;
    case 4:
      dKsect[kIndex+0] = 4;
      dKsect[kIndex+1] = 12;
      dKsect[kIndex+2] = 20;
      dKsect[kIndex+3] = 28;
      dKsect[kIndex+4] = 36;
      dKsect[kIndex+5] = 44;
      dKsect[kIndex+6] = 52;
      dKsect[kIndex+7] = 60;
      break;
    case 5:
      dKsect[kIndex+0] = 5;
      dKsect[kIndex+1] = 13;
      dKsect[kIndex+2] = 21;
      dKsect[kIndex+3] = 29;
      dKsect[kIndex+4] = 37;
      dKsect[kIndex+5] = 45;
      dKsect[kIndex+6] = 53;
      dKsect[kIndex+7] = 61;
      break;
    case 6:
      dKsect[kIndex+0] = 6;
      dKsect[kIndex+1] = 14;
      dKsect[kIndex+2] = 22;
      dKsect[kIndex+3] = 30;
      dKsect[kIndex+4] = 38;
      dKsect[kIndex+5] = 46;
      dKsect[kIndex+6] = 54;
      dKsect[kIndex+7] = 62;
      break;
    case 7:
      dKsect[kIndex+0] = 7;
      dKsect[kIndex+1] = 15;
      dKsect[kIndex+2] = 23;
      dKsect[kIndex+3] = 31;
      dKsect[kIndex+4] = 39;
      dKsect[kIndex+5] = 47;
      dKsect[kIndex+6] = 55;
      dKsect[kIndex+7] = 63;
      break;
   }  
}

void kExclude(int *dIsect, int *dJsect, int iIndex, int jIndex, int a){
  if((a >= 0 ) && (a < 8)){
     dIsect[iIndex+0] = 0;
     dIsect[iIndex+1] = 8;
     dIsect[iIndex+2] = 16;
     dIsect[iIndex+3] = 24;
     dIsect[iIndex+4] = 32;
     dIsect[iIndex+5] = 40;
     dIsect[iIndex+6] = 48;
     dIsect[iIndex+7] = 56;
   }else if((a >= 8 ) && (a < 16)){
     dIsect[iIndex+0] = 1;
     dIsect[iIndex+1] = 9;
     dIsect[iIndex+2] = 17;
     dIsect[iIndex+3] = 25;
     dIsect[iIndex+4] = 33;
     dIsect[iIndex+5] = 41;
     dIsect[iIndex+6] = 49;
     dIsect[iIndex+7] = 57;
   }else if((a >= 16 ) && (a < 24)){
     dIsect[iIndex+0] = 2;
     dIsect[iIndex+1] = 10;
     dIsect[iIndex+2] = 18;
     dIsect[iIndex+3] = 26;
     dIsect[iIndex+4] = 34;
     dIsect[iIndex+5] = 42;
     dIsect[iIndex+6] = 50;
     dIsect[iIndex+7] = 58;
   }else if((a >= 24 ) && (a < 32)){
     dIsect[iIndex+0] = 3;
     dIsect[iIndex+1] = 11;
     dIsect[iIndex+2] = 19;
     dIsect[iIndex+3] = 27;
     dIsect[iIndex+4] = 35;
     dIsect[iIndex+5] = 43;
     dIsect[iIndex+6] = 51;
     dIsect[iIndex+7] = 59;
   }else if((a >= 32 ) && (a < 40)){
     dIsect[iIndex+0] = 4;
     dIsect[iIndex+1] = 12;
     dIsect[iIndex+2] = 20;
     dIsect[iIndex+3] = 28;
     dIsect[iIndex+4] = 36;
     dIsect[iIndex+5] = 44;
     dIsect[iIndex+6] = 52;
     dIsect[iIndex+7] = 60;
   }else if((a >= 40 ) && (a < 48)){
     dIsect[iIndex+0] = 5;
     dIsect[iIndex+1] = 13;
     dIsect[iIndex+2] = 21;
     dIsect[iIndex+3] = 29;
     dIsect[iIndex+4] = 37;
     dIsect[iIndex+5] = 45;
     dIsect[iIndex+6] = 53;
     dIsect[iIndex+7] = 61;
   }
   else if((a >= 48 ) && (a < 56)){
     dIsect[iIndex+0] = 6;
     dIsect[iIndex+1] = 14;
     dIsect[iIndex+2] = 22;
     dIsect[iIndex+3] = 30;
     dIsect[iIndex+4] = 38;
     dIsect[iIndex+5] = 46;
     dIsect[iIndex+6] = 54;
     dIsect[iIndex+7] = 62;
   }
   else if((a >= 56 ) && (a < 64)){
     dIsect[iIndex+0] = 7;
     dIsect[iIndex+1] = 15;
     dIsect[iIndex+2] = 23;
     dIsect[iIndex+3] = 31;
     dIsect[iIndex+4] = 39;
     dIsect[iIndex+5] = 47;
     dIsect[iIndex+6] = 55;
     dIsect[iIndex+7] = 63;
   }
   switch(a%8){
    case 0:
      dJsect[jIndex+0] = 0;
      dJsect[jIndex+1] = 8;
      dJsect[jIndex+2] = 16;
      dJsect[jIndex+3] = 24;
      dJsect[jIndex+4] = 32;
      dJsect[jIndex+5] = 40;
      dJsect[jIndex+6] = 48;
      dJsect[jIndex+7] = 56;
      break;
    case 1:
      dJsect[jIndex+0] = 1;
      dJsect[jIndex+1] = 9;
      dJsect[jIndex+2] = 17;
      dJsect[jIndex+3] = 25;
      dJsect[jIndex+4] = 33;
      dJsect[jIndex+5] = 41;
      dJsect[jIndex+6] = 49;
      dJsect[jIndex+7] = 57;
      break;
    case 2:
      dJsect[jIndex+0] = 2;
      dJsect[jIndex+1] = 10;
      dJsect[jIndex+2] = 18;
      dJsect[jIndex+3] = 26;
      dJsect[jIndex+4] = 34;
      dJsect[jIndex+5] = 42;
      dJsect[jIndex+6] = 50;
      dJsect[jIndex+7] = 58;
      break;
    case 3:
      dJsect[jIndex+0] = 3;
      dJsect[jIndex+1] = 11;
      dJsect[jIndex+2] = 19;
      dJsect[jIndex+3] = 27;
      dJsect[jIndex+4] = 35;
      dJsect[jIndex+5] = 43;
      dJsect[jIndex+6] = 51;
      dJsect[jIndex+7] = 59;
      break;
    case 4:
      dJsect[jIndex+0] = 4;
      dJsect[jIndex+1] = 12;
      dJsect[jIndex+2] = 20;
      dJsect[jIndex+3] = 28;
      dJsect[jIndex+4] = 36;
      dJsect[jIndex+5] = 44;
      dJsect[jIndex+6] = 52;
      dJsect[jIndex+7] = 60;
      break;
    case 5:
      dJsect[jIndex+0] = 5;
      dJsect[jIndex+1] = 13;
      dJsect[jIndex+2] = 21;
      dJsect[jIndex+3] = 29;
      dJsect[jIndex+4] = 37;
      dJsect[jIndex+5] = 45;
      dJsect[jIndex+6] = 53;
      dJsect[jIndex+7] = 61;
      break;
    case 6:
      dJsect[jIndex+0] = 6;
      dJsect[jIndex+1] = 14;
      dJsect[jIndex+2] = 22;
      dJsect[jIndex+3] = 30;
      dJsect[jIndex+4] = 38;
      dJsect[jIndex+5] = 46;
      dJsect[jIndex+6] = 54;
      dJsect[jIndex+7] = 62;
      break;
    case 7:
      dJsect[jIndex+0] = 7;
      dJsect[jIndex+1] = 15;
      dJsect[jIndex+2] = 23;
      dJsect[jIndex+3] = 31;
      dJsect[jIndex+4] = 39;
      dJsect[jIndex+5] = 47;
      dJsect[jIndex+6] = 55;
      dJsect[jIndex+7] = 63;
      break;
   }  
}

void drawCol(int cnt, int sector, int C, bool dir){
   int z = 0;
  if(!dir){
    z = 1;
  }
  switch(cnt){
    case 0:
      LED(w[z][0],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 1:
      LED(w[z][1],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 2:
      LED(w[z][2],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 3:
      LED(w[z][3],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 4:
      LED(w[z][0],gridLat[sector][0],gridLat[sector][1],0,0,0);
      LED(w[z][4],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 5:
      LED(w[z][1],gridLat[sector][0],gridLat[sector][1],0,0,0);
      LED(w[z][5],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 6:
      LED(w[z][2],gridLat[sector][0],gridLat[sector][1],0,0,0);
      LED(w[z][6],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 7:
      LED(w[z][3],gridLat[sector][0],gridLat[sector][1],0,0,0);
      LED(w[z][7],gridLat[sector][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 8:
      LED(w[z][4],gridLat[sector][0],gridLat[sector][1],0,0,0);
      break;
    case 9:
      LED(w[z][5],gridLat[sector][0],gridLat[sector][1],0,0,0);
      break;
    case 10:
      LED(w[z][6],gridLat[sector][0],gridLat[sector][1],0,0,0);
      break;
    case 11:
      LED(w[z][7],gridLat[sector][0],gridLat[sector][1],0,0,0);
      break;
  }
}

void drawJCol(int cnt, int sector, int C, bool dir){
   int z = 0;
  if(!dir){
    z = 1;
  }
  switch(cnt){
    case 0:
      LED(gridLat[sector][0],w[z][0],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 1:
      LED(gridLat[sector][0],w[z][1],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 2:
      LED(gridLat[sector][0],w[z][2],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 3:
      LED(gridLat[sector][0],w[z][3],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 4:
      LED(gridLat[sector][0],w[z][0],gridLat[sector][1],0,0,0);
      LED(gridLat[sector][0],w[z][4],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 5:
      LED(gridLat[sector][0],w[z][1],gridLat[sector][1],0,0,0);
      LED(gridLat[sector][0],w[z][5],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 6:
      LED(gridLat[sector][0],w[z][2],gridLat[sector][1],0,0,0);
      LED(gridLat[sector][0],w[z][6],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 7:
      LED(gridLat[sector][0],w[z][3],gridLat[sector][1],0,0,0);
      LED(gridLat[sector][0],w[z][7],gridLat[sector][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 8:
      LED(gridLat[sector][0],w[z][4],gridLat[sector][1],0,0,0);
      break;
    case 9:
      LED(gridLat[sector][0],w[z][5],gridLat[sector][1],0,0,0);
      break;
    case 10:
      LED(gridLat[sector][0],w[z][6],gridLat[sector][1],0,0,0);
      break;
    case 11:
      LED(gridLat[sector][0],w[z][7],gridLat[sector][1],0,0,0);
      break;
  }
}

void drawKCol(int cnt, int sector, int C, bool dir){
   int z = 0;
  if(!dir){
    z = 1;
  }
  switch(cnt){
    case 0:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][0],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 1:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][1],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 2:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][2],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 3:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][3],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 4:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][0],0,0,0);
      LED(gridLat[sector][0],gridLat[sector][1],w[z][4],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 5:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][1],0,0,0);
      LED(gridLat[sector][0],gridLat[sector][1],w[z][5],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 6:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][2],0,0,0);
      LED(gridLat[sector][0],gridLat[sector][1],w[z][6],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 7:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][3],0,0,0);
      LED(gridLat[sector][0],gridLat[sector][1],w[z][7],colorWheel[C],colorWheel[C+1],colorWheel[C+2]);
      break;
    case 8:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][4],0,0,0);
      break;
    case 9:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][5],0,0,0);
      break;
    case 10:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][6],0,0,0);
      break;
    case 11:
      LED(gridLat[sector][0],gridLat[sector][1],w[z][7],0,0,0);
      break;
  }
}

#endif

