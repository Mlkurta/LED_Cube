#ifndef BRESENHAM_H
#define BRESENHAM_H

/*
by Michael Kurta
github.com/Mlkurta
*/

#include "LED.h"

void endpoint3D(int, int, int, float, float, int);
void bresenham3D(int,int,int, int);
float convertToRads(float);
void endpoint(double, int, int, int);
void line(int, int, int, int, int, int);

extern unsigned long start, sTwo;
extern short endX, endY, eX, eY, eZ; 
extern const short colorWheel[];


void line(int x1, int y1, int x2, int y2, int k, int c){
  const bool steep = fabs(y2-y1) > fabs(x2-x1);
  if(steep){
    std::swap(x1,y1);
    std::swap(x2,y2);
  }
  if(x1 > x2){
    std::swap(x1,x2);
    std::swap(y1,y2);
  }
  const float dx = x2 - x1;
  const float dy = fabs(y2 - y1);

  float error = dx/2.0f;
  const int ystep = (y1<y2) ? 1 : -1;
  int y = y1;
  const int maxX = x2;

  for(int x = x1;x < maxX; x++){
    if(steep){
      if(c == 36){
        LED(x,y,k,0,0,0);
      }else{
        LED(x,y,k,colorWheel[c],colorWheel[c+1],colorWheel[c+2]);
      }
    }else{
      if(c == 36){
        LED(y,x,k,0,0,0);
      }else{
        LED(y,x,k,colorWheel[c],colorWheel[c+1],colorWheel[c+2]);
      }
    }
    error -= dy;
    if(error < 0){
      y += ystep;
      error += dx;
    }
  }
}

void endpoint(double angle, int x1, int y1, int length){
  double radians = (3.1416/180)*angle;
  double x2 = x1 + (length * cos(radians));
  double y2 = y1 + (length * sin(radians));
  endY = round(y2);
  endX = round(x2);
}

float convertToRads(float a){
  a = (a * 3.14f)/180;
  return a;
}

void bresenham3D(int x1,int y1,int z1, int c){
  int i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc, err_1, err_2, dx2, dy2, dz2;
  int point[3];
//0,3,0     2,5,3
  point[0] = x1;
  point[1] = y1;
  point[2] = z1;

  dx = eX - x1; //2
  dy = eY - y1; //2
  dz = eZ - z1; //3
  x_inc = (dx < 0) ? -1 : 1;//1
  l = abs(dx);//1
  y_inc = (dy < 0) ? -1 : 1;//1
  m = abs(dy);//1
  z_inc = (dz < 0) ? -1 : 1;//1
  n = abs(dz);//1
  dx2 = l << 1;//2
  dy2 = m << 1;//2
  dz2 = n << 1;//2

  if((l >= m) && (l >= n)){
    err_1 = dy2 - 1;//1
    err_2 = dz2 - 1;
    for(i=0;i<l;i++){
      if(c == 36){
        LED(point[2], point[0], point[1], 0,0,0);
      }else{
        LED(point[2], point[0], point[1], colorWheel[c],colorWheel[c+1],colorWheel[c+2]);
      }
      if(err_1 > 0){
        point[1] += y_inc;
        err_1 -= dx2;
      }
      if(err_2 > 0){
        point[2] += z_inc;
        err_2 -= dx2;
      }
      err_1 += dy2;
      err_2 += dz2;
      point[0] += x_inc;
    }
  }else if((m >= l) && (m >= n)){
    err_1 = dx2 - m;
    err_2 = dz2 - m;
    for(i=0;i<m;i++){
      if(c == 36){
        LED(point[2], point[0], point[1], 0,0,0);
      }else{
        LED(point[2], point[0], point[1], colorWheel[c],colorWheel[c+1],colorWheel[c+2]);
      }
      if(err_1 > 0){
        point[0] += x_inc;
        err_1 -= dy2;
      }
      if(err_2 > 0){
        point[2] += z_inc;
        err_2 -= dy2;
      }
      err_1 += dx2;
      err_2 += dz2;
      point[1] += y_inc;
    }
  }else{
    err_1 = dy2 - n;
    err_2 = dx2 - n;
    for(i=0;i<n;i++){
      if(c == 36){
        LED(point[2], point[0], point[1], 0,0,0);
      }else{
        LED(point[2], point[0], point[1], colorWheel[c],colorWheel[c+1],colorWheel[c+2]);
      }
      if(err_1 > 0){
        point[1] += y_inc;
        err_1 -= dz2;
      }
      if(err_2 > 0){
        point[0] += x_inc;
        err_2 -= dz2;
      }
      err_1 += dy2;
      err_2 += dx2;
      point[2] += z_inc;
    }
  }
  if(c == 36){
    LED(point[2], point[0], point[1], 0,0,0);
  }else{
    LED(point[2], point[0], point[1], colorWheel[c],colorWheel[c+1],colorWheel[c+2]);
  } 
}

void endpoint3D(int sX, int sY, int sZ, float angY, float angX, int rad){
  float radius  = rad;
  float startX = sX;
  float startY = sY;
  float startZ = sZ;
  float endZ = startZ + (sin(angX) * radius);
  float endX = startX + (cos(angY) * radius * cos(angX));
  float endY = startY + (sin(angY) * radius * cos(angX));
  eX = round(endX);
  eY = round(endY);
  eZ = round(endZ);
}

void bresenhamSpiralV2(){
  int i,j,ii,jj,kk;
int offset = 0;
//int c defines the color of each / of the spiral we're talking about (c[0] = line of level 0)
int c[8];
double a[8] = {0,0,0,0,0,0,0,0};
// seq defines set angles for each line in the spiral
short seq[47] = {0,0,15,30,45,60,75,90,105,120,135,150,165,180,195,210,225,240,255,270,285,300,315,330,345,0,15,30,45,60,75,90,105,120,135,150,165,180,195,210,225,240,255,270,285,300,315};
int startX = 4; //x coordinate of center point
float t = 20.00f; //starting time interval, measuring time between angle changes
int startY = 4; //y coordinate of center point
int len = 4; //length of line from the center point
start = millis();
while(millis() - start < 10000){
    i = 0;
    while(1){
      offset = 21;
      for(j=0;j<8;j++){
        switch(seq[i+offset+1]){  //switch statement analyzes each line's angle and assigns a color
          case 0 ... 29:
            c[j] = 0;
            break;
          case 30 ... 59:
            c[j] = 3;
            break;
          case 60 ... 89:
            c[j] = 6;
            break;
          case 90 ... 119:
            c[j] = 9;
            break;
          case 120 ... 149:
            c[j] = 12;
            break;
          case 150 ... 179:
            c[j] = 15;
            break;
          case 180 ... 209:
            c[j] = 18;
            break;
          case 210 ... 239:
            c[j] = 21;
            break;
          case 240 ... 269:
            c[j] = 24;
            break;
          case 270 ... 299:
            c[j] = 27;
            break;
          case 300 ... 329:
            c[j] = 30;
            break;
          case 330 ... 359:
            c[j] = 33;
            break;
        }
        endpoint(seq[i+offset],startX,startY,len); //cast a calculated endpoint for the line to ERASE the previous line
        line(startX,startY,endX,endY,j,36);  //draw a BLANK line to erase, denoted by color 36
        offset++;  //increment offset so seq[] denotes the next angle
        endpoint(seq[i+offset],startX,startY,len); //calculate endpoint for next angle
        line(startX,startY,endX,endY,j,c[j]); //draw next line, to color of current j value.
        offset -= 4;  //decrement offset by four to prepare for next line; each line has its own set of 3 (RGB) colors
      }
      if(i==23){ //max index of 23 reset to 0
        i = 0;
        LED(3,7,7,0,0,0);
        if(t >= 125){ //break out of loop when time delay reaches max setting
          break;
        }
      }else{
        i++; // next stage of angles
      }
      t *= 1.03f; //slowly increase time delay between movements;  faster to slower
      delay(t);  //delay by current value of float t
    }
    i = 46;
    clean();
    while(1){
      offset = 0;
      for(j=0;j<8;j++){
        switch(seq[i-offset-1]){
          case 0 ... 29:
            c[j] = 0;
            break;
          case 30 ... 59:
            c[j] = 3;
            break;
          case 60 ... 89:
            c[j] = 6;
            break;
          case 90 ... 119:
            c[j] = 9;
            break;
          case 120 ... 149:
            c[j] = 12;
            break;
          case 150 ... 179:
            c[j] = 15;
            break;
          case 180 ... 209:
            c[j] = 18;
            break;
          case 210 ... 239:
            c[j] = 21;
            break;
          case 240 ... 269:
            c[j] = 24;
            break;
          case 270 ... 299:
            c[j] = 27;
            break;
          case 300 ... 329:
            c[j] = 30;
            break;
          case 330 ... 359:
            c[j] = 33;
            break;
        }
        endpoint(seq[i-offset],startX,startY,len);
        line(startX,startY,endX,endY,j,36);
        offset++;
        endpoint(seq[i-offset],startX,startY,len);
        line(startX,startY,endX,endY,j,c[j]);
        offset += 2;
      }
      if(i==23){
        i = 46;
        if(t <= 20){
          break;
        }
      }else{
        i--;
      }
      t *= .95;
      delay(t);
    }
    while(1){
      offset = 0;
      for(j=0;j<8;j++){
        switch(seq[i-offset-1]){
          case 0 ... 29:
            c[j] = 0;
            break;
          case 30 ... 59:
            c[j] = 3;
            break;
          case 60 ... 89:
            c[j] = 6;
            break;
          case 90 ... 119:
            c[j] = 9;
            break;
          case 120 ... 149:
            c[j] = 12;
            break;
          case 150 ... 179:
            c[j] = 15;
            break;
          case 180 ... 209:
            c[j] = 18;
            break;
          case 210 ... 239:
            c[j] = 21;
            break;
          case 240 ... 269:
            c[j] = 24;
            break;
          case 270 ... 299:
            c[j] = 27;
            break;
          case 300 ... 329:
            c[j] = 30;
            break;
          case 330 ... 359:
            c[j] = 33;
            break;
        }
        endpoint(seq[i-offset],startX,startY,len);
        line(startX,startY,endX,endY,j,36);
        offset++;
        endpoint(seq[i-offset],startX,startY,len);
        line(startX,startY,endX,endY,j,c[j]);
        offset += 2;
      }
      if(i==23){
        i = 46;
        if(t >= 125){
          break;
        }
      }else{
        i--;
      }
      t *= 1.03;
      delay(t);
    }
    i = 0;
    while(1){
      offset = 21;
      for(j=0;j<8;j++){
        switch(seq[i+offset+1]){
          case 0 ... 29:
            c[j] = 0;
            break;
          case 30 ... 59:
            c[j] = 3;
            break;
          case 60 ... 89:
            c[j] = 6;
            break;
          case 90 ... 119:
            c[j] = 9;
            break;
          case 120 ... 149:
            c[j] = 12;
            break;
          case 150 ... 179:
            c[j] = 15;
            break;
          case 180 ... 209:
            c[j] = 18;
            break;
          case 210 ... 239:
            c[j] = 21;
            break;
          case 240 ... 269:
            c[j] = 24;
            break;
          case 270 ... 299:
            c[j] = 27;
            break;
          case 300 ... 329:
            c[j] = 30;
            break;
          case 330 ... 359:
            c[j] = 33;
            break;
        }
        endpoint(seq[i+offset],startX,startY,len);
        line(startX,startY,endX,endY,j,36);
        offset++;
        endpoint(seq[i+offset],startX,startY,len);
        line(startX,startY,endX,endY,j,c[j]);
        offset -= 4;
      }
      if(i==23){
        i = 0;
        LED(3,7,7,0,0,0);
        if(t <= 10){
          break;
        }
      }else{
        i++;
      }
      t *= .95;
      delay(t);
    }
  }
}

void chopstick3D(){
  int i;
  int sX = 4;
  int sY = 3;
  int sZ = 4;
  float angY = 0.0;
  float angX = 45.0;
  int rad = 4;
  const uint32_t TICK_DELAY = 3;
  angX = convertToRads(angX);
  start = millis();
  while(millis() - start < 10000){
    for(i=0;i<360;i++){
      angY = i;
      angY = convertToRads(angY);
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 12);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 24);
      delay(TICK_DELAY);
      bresenham3D(sX, sY, sZ, 12);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 24);
    }
    for(i=0;i<360;i++){
      angY = i;
      angY = convertToRads(angY);
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 12);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 24);
      delay(TICK_DELAY);
      bresenham3D(sX, sY, sZ, 36);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 36);
    }
    for(i=0;i<360;i++){
      angY = i;
      angY = convertToRads(angY);
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 3);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 30);
      delay(TICK_DELAY);
      bresenham3D(sX, sY, sZ, 3);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 30);
    }
    for(i=0;i<360;i++){
      angY = i;
      angY = convertToRads(angY);
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 3);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 30);
      delay(TICK_DELAY);
      bresenham3D(sX, sY, sZ, 36);
      angX *= -1.0;
      angY = (angY < PI) ? angY + PI : angY - PI;
      endpoint3D(sX,sY,sZ,angY,angX,rad);
      bresenham3D(sX, sY, sZ, 36);
    }
  }
}

#endif

