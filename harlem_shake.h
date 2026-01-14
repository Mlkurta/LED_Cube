#ifndef HARLEM_SHAKE_H
#define HARLEM_SHAKE_H

/*
by Kevin Darrah
www.kevindarrah.comcl
kevin@kevindarrah.com
*/

#include "LED.h"

extern unsigned long start;

void harlem_shake(){
  
  
  
int greenx = random(1,7),greeny = random(1,7),bluex = random(1,7),bluey = random(1,7),redx = random(1,7),redy = random(1,7);
int greenmult=1, bluemult=1, redmult=1;
int greenmulty=1, bluemulty=1, redmulty=1;
int oredx, oredy,obluex,obluey,ogreenx,ogreeny, cb1=15,cb2=0,cr1=15,cr2=0,cg1=15,cg2=0;
int time_counter=10, timemult=2;
int m;
int c1=1,c2=1,c3=1,xmult=1,ymult=1,zmult=1,x=4,y=4,z=4,color_select, xo, yo, zo;
int c21=1,c22=1,c23=1,x2mult=1,y2mult=1,z2mult=1,x2=2,y2=2,z2=2,color_select2, x2o, y2o, z2o;

int counter, i, j, k;
for(counter=0; counter<150; counter++){
  for(i=0; i<8; i++){
  LED(i,oredx,oredx,0,0,0);
  }
  for(i=0; i<8; i++){
  LED(i,redx,redx,15,0,0);
  }
  
  oredx=redx;
  oredy=redy;
  
for(i=100; i>time_counter; i--)
  delay(2);

  time_counter=time_counter+timemult;
  if(time_counter>100||time_counter<10)
  timemult=timemult*-1;


   if(redy>6 || redy<1){
  redmulty=redmulty*-1;  
  
  }
 
   if(redx>6 || redx<1){
  redmult=redmult*-1;  
  
  cr1=random(16);
  cr2=random(16);
   }

  redy=redy+redmulty;
  redx=redx+redmult;
}//counter


for(counter=0; counter<85; counter++){
  for(i=0; i<8; i++){
  LED(i,oredx,oredx,0,0,0);
  LED(ogreenx,i,ogreeny,0,0,0);
  }
  for(i=0; i<8; i++){
  LED(i,redx,redx,15,0,0);
  LED(greenx,i,greeny,0,15,0);
  }
  ogreenx=greenx;
  ogreeny=greeny;
  oredx=redx;
  oredy=redy;
  
for(i=100; i>time_counter; i--)
  delay(2);

  time_counter=time_counter+timemult;
  if(time_counter>100||time_counter<10)
  timemult=timemult*-1;

   
     if(greeny>6 || greeny<1)
  greenmulty=greenmulty*-1;

   if(redy>6 || redy<1){
  redmulty=redmulty*-1;  
  
  }
 
   
     if(greenx>6 || greenx<1){
  greenmult=greenmult*-1;
  greeny = greeny + greenmulty;
  cg1=random(16);
  cg2=random(16);
  }

   if(redx>6 || redx<1){
  redmult=redmult*-1;  
  
  cr1=random(16);
  cr2=random(16);
   }
  greenx=greenx+greenmult;
  
  redy=redy+redmulty;
  redx=redx+redmult;
}//counter


for(counter=0; counter<85; counter++){
  for(i=0; i<8; i++){
  LED(i,oredx,oredx,0,0,0);
  LED(obluey,obluex,i,0,0,0);
  LED(ogreenx,i,ogreeny,0,0,0);
  }
  for(i=0; i<8; i++){
  LED(i,redx,redx,15,0,0);
  LED(bluey,bluex,i,0,0,15);
  LED(greenx,i,greeny,0,15,0);
  }
  ogreenx=greenx;
  ogreeny=greeny;
  obluex=bluex;
  obluey=bluey;
  oredx=redx;
  oredy=redy;
  
for(i=100; i>time_counter; i--)
  delay(2);

  time_counter=time_counter+timemult;
  if(time_counter>100||time_counter<10)
  timemult=timemult*-1;

   
     if(greeny>6 || greeny<1)
  greenmulty=greenmulty*-1;

   if(bluey>6 || bluey<1)
  bluemulty=bluemulty*-1;

   if(redy>6 || redy<1){
  redmulty=redmulty*-1;  
  
  }
 
   
     if(greenx>6 || greenx<1){
  greenmult=greenmult*-1;
  greeny = greeny + greenmulty;
  cg1=random(16);
  cg2=random(16);
  }
   if(bluex>6 || bluex<1){
  bluemult=bluemult*-1;
  bluey=bluey+bluemulty;
  cb1=random(16);
  cb2=random(16);
   }
   if(redx>6 || redx<1){
  redmult=redmult*-1;  
  
  cr1=random(16);
  cr2=random(16);
   }
  greenx=greenx+greenmult;
  bluex=bluex+bluemult;
  redy=redy+redmulty;
  redx=redx+redmult;
}//counter



for(counter=0; counter<3; counter++){
  for(i=0; i<8; i++)
  for(j=0; j<8; j++)
  for(k=0; k<8; k++)
  LED(i,j,k,15,15,15);
  delay(100);
  for(i=0; i<8; i++)
  for(j=0; j<8; j++)
  for(k=0; k<8; k++)
  LED(i,j,k,0,0,0);
  delay(100);
}//counter

  for(m=0; m<1; m++){
    
    
  for(i=0; i<8; i++)
  for(j=0; j<8; j++)
  for(k=0; k<8; k++)
  LED(i,j,k,0,random(16),random(16));

  for(i=7; i>=0; i--)
  for(j=0; j<8; j++)
  for(k=0; k<8; k++)
  LED(i,j,k,random(16),0,random(16));

  for(i=0; i<8; i++)
  for(j=0; j<8; j++)
  for(k=0; k<8; k++)
  LED(i,j,k,random(16),random(16),0);

  for(i=7; i>=0; i--)
  for(j=0; j<8; j++)
  for(k=0; k<8; k++)
  LED(i,j,k,random(16),0,random(16));
  }

clean();


for(m=0; m<3; m++){
    for(k=0; k<200; k++){
  LED(random(8),random(8),random(8),random(16),random(16),0);
  LED(random(8),random(8),random(8),random(16),0 ,random(16));
  LED(random(8),random(8),random(8),0, random(16),random(16));
   //   c1=random(8);
     // c2=random(8);
      //c3=random(8);
  //LED(c1,c2,c3,15,15,15);
  }
      for(k=0; k<200; k++){
  LED(random(8),random(8),random(8),0,0,0);
  }
  
}//m


  
  
clean();


color_select=random(0,3);
if(color_select==0){
c1 = 0;
c2 = random(0,16);
c3 = random(0,16);}
if(color_select==1){
c1 = random(0,16);
c2 = 0;
c3 = random(0,16);}
if(color_select==2){
c1 = random(0,16);
c2 = random(0,16);
c3 = 0;}


color_select2=random(0,3);
if(color_select2==0){
c21 = 0;
c22 = random(0,16);
c23 = random(0,16);}
if(color_select2==1){
c21 = random(0,16);
c22 = 0;
c23 = random(0,16);}
if(color_select2==2){
c21 = random(0,16);
c22 = random(0,16);
c23 = 0;}

for(counter=0; counter<200; counter++){

LED(xo,yo,zo,0,0,0);
LED(xo+1,yo,zo,0,0,0);
LED(xo+2,yo,zo,0,0,0);
LED(xo-1,yo,zo,0,0,0);
LED(xo-2,yo,zo,0,0,0);
LED(xo,yo+1,zo,0,0,0);
LED(xo,yo-1,zo,0,0,0);
LED(xo,yo+2,zo,0,0,0);
LED(xo,yo-2,zo,0,0,0);
LED(xo,yo,zo-1,0,0,0);
LED(xo,yo,zo+1,0,0,0);
LED(xo,yo,zo-2,0,0,0);
LED(xo,yo,zo+2,0,0,0);

LED(x2o,y2o,z2o,0,0,0);
LED(x2o+1,y2o,z2o,0,0,0);
LED(x2o+2,y2o,z2o,0,0,0);
LED(x2o-1,y2o,z2o,0,0,0);
LED(x2o-2,y2o,z2o,0,0,0);
LED(x2o,y2o+1,z2o,0,0,0);
LED(x2o,y2o-1,z2o,0,0,0);
LED(x2o,y2o+2,z2o,0,0,0);
LED(x2o,y2o-2,z2o,0,0,0);
LED(x2o,y2o,z2o-1,0,0,0);
LED(x2o,y2o,z2o+1,0,0,0);
LED(x2o,y2o,z2o-2,0,0,0);
LED(x2o,y2o,z2o+2,0,0,0);

LED(xo+1,yo+1,zo,0,0,0);
LED(xo+1,yo-1,zo,0,0,0);
LED(xo-1,yo+1,zo,0,0,0);
LED(xo-1,yo-1,zo,0,0,0);
LED(xo+1,yo+1,zo+1,0,0,0);
LED(xo+1,yo-1,zo+1,0,0,0);
LED(xo-1,yo+1,zo+1,0,0,0);
LED(xo-1,yo-1,zo+1,0,0,0);
LED(xo+1,yo+1,zo-1,0,0,0);
LED(xo+1,yo-1,zo-1,0,0,0);
LED(xo-1,yo+1,zo-1,0,0,0);
LED(xo-1,yo-1,zo-1,0,0,0);

LED(x2o+1,y2o+1,z2o,0,0,0);
LED(x2o+1,y2o-1,z2o,0,0,0);
LED(x2o-1,y2o+1,z2o,0,0,0);
LED(x2o-1,y2o-1,z2o,0,0,0);
LED(x2o+1,y2o+1,z2o+1,0,0,0);
LED(x2o+1,y2o-1,z2o+1,0,0,0);
LED(x2o-1,y2o+1,z2o+1,0,0,0);
LED(x2o-1,y2o-1,z2o+1,0,0,0);
LED(x2o+1,y2o+1,z2o-1,0,0,0);
LED(x2o+1,y2o-1,z2o-1,0,0,0);
LED(x2o-1,y2o+1,z2o-1,0,0,0);
LED(x2o-1,y2o-1,z2o-1,0,0,0);

LED(x,y,z,c1,c2,c3);
LED(x,y,z-1,c1,c2,c3);
LED(x,y,z+1,c1,c2,c3);
LED(x,y,z-2,c1,c2,c3);
LED(x,y,z+2,c1,c2,c3);
LED(x+1,y,z,c1,c2,c3);
LED(x-1,y,z,c1,c2,c3);
LED(x,y+1,z,c1,c2,c3);
LED(x,y-1,z,c1,c2,c3);
LED(x+2,y,z,c1,c2,c3);
LED(x-2,y,z,c1,c2,c3);
LED(x,y+2,z,c1,c2,c3);
LED(x,y-2,z,c1,c2,c3);
LED(x+1,y+1,z,c1,c2,c3);
LED(x+1,y-1,z,c1,c2,c3);
LED(x-1,y+1,z,c1,c2,c3);
LED(x-1,y-1,z,c1,c2,c3);
LED(x+1,y+1,z+1,c1,c2,c3);
LED(x+1,y-1,z+1,c1,c2,c3);
LED(x-1,y+1,z+1,c1,c2,c3);
LED(x-1,y-1,z+1,c1,c2,c3);
LED(x+1,y+1,z-1,c1,c2,c3);
LED(x+1,y-1,z-1,c1,c2,c3);
LED(x-1,y+1,z-1,c1,c2,c3);
LED(x-1,y-1,z-1,c1,c2,c3);

LED(x2,y2,z2,c21,c22,c23);
LED(x2,y2,z2-1,c21,c22,c23);
LED(x2,y2,z2+1,c21,c22,c23);
LED(x2,y2,z2-2,c21,c22,c23);
LED(x2,y2,z2+2,c21,c22,c23);
LED(x2+1,y2,z2,c21,c22,c23);
LED(x2-1,y2,z2,c21,c22,c23);
LED(x2,y2+1,z2,c21,c22,c23);
LED(x2,y2-1,z2,c21,c22,c23);
LED(x2+2,y2,z2,c21,c22,c23);
LED(x2-2,y2,z2,c21,c22,c23);
LED(x2,y2+2,z2,c21,c22,c23);
LED(x2,y2-2,z2,c21,c22,c23);
LED(x2+1,y2+1,z2,c21,c22,c23);
LED(x2+1,y2-1,z2,c21,c22,c23);
LED(x2-1,y2+1,z2,c21,c22,c23);
LED(x2-1,y2-1,z2,c21,c22,c23);
LED(x2+1,y2+1,z2+1,c21,c22,c23);
LED(x2+1,y2-1,z2+1,c21,c22,c23);
LED(x2-1,y2+1,z2+1,c21,c22,c23);
LED(x2-1,y2-1,z2+1,c21,c22,c23);
LED(x2+1,y2+1,z2-1,c21,c22,c23);
LED(x2+1,y2-1,z2-1,c21,c22,c23);
LED(x2-1,y2+1,z2-1,c21,c22,c23);
LED(x2-1,y2-1,z2-1,c21,c22,c23);





x2o=x2;
y2o=y2;
z2o=z2;

xo=x;
yo=y;
zo=z;

delay(90);

x = x+xmult;
y= y+ymult;
z= z+zmult;

x2 = x2+x2mult;
y2= y2+y2mult;
z2= z2+z2mult;

if(x>=7){
//x=7;
xmult=random(-1,1);
}
if(y>=7){
//y=7;
ymult=random(-1,1);}
if(z>=7){
//z=7;
zmult=random(-1,1);}
if(x<=0){
//x=0;
xmult=random(0,2);}
if(y<=0){
//y=0;
ymult=random(0,2);}
if(z<=0){
//z=0;
zmult=random(0,2);
}

if(x2>=7){
//x=7;
x2mult=random(-1,1);
}
if(y2>=7){
//y=7;
y2mult=random(-1,1);}
if(z2>=7){
//z=7;
z2mult=random(-1,1);}
if(x2<=0){
//x=0;
x2mult=random(0,2);}
if(y2<=0){
//y=0;
y2mult=random(0,2);}
if(z<=0){
//z=0;
z2mult=random(0,2);
}




}//counter  counter counter counter counter



for(counter=0; counter<15; counter++){
  color_select=random(0,3);
if(color_select==0){
c1 = 0;
c2 = random(0,16);
c3 = random(0,16);}
if(color_select==1){
c1 = random(0,16);
c2 = 0;
c3 = random(0,16);}
if(color_select==2){
c1 = random(0,16);
c2 = random(0,16);
c3 = 0;}
  
  
int num1=-1, num2=-4, num3=-6, num4=-10;
for(m=0; m<20; m++){
  
num1++;
num2++;
num3++;
num4++;


for(i=3; i<5; i++){
LED(num1, i,3,0,0,0);
LED(num1, 3,i,0,0,0);
LED(num1, 4,i,0,0,0);
LED(num1, i,4,0,0,0);
}
for(i=3; i<5; i++){
LED(num1+1, i,4,c1,c2,c3);
LED(num1+1, 4,i,c1,c2,c3);
LED(num1+1, 3,i,c1,c2,c3);
LED(num1+1, i,3,c1,c2,c3);
}
for(i=2; i<6; i++){
LED(num2, i,2,0,0,0);
LED(num2, 2,i,0,0,0);
LED(num2, 5,i,0,0,0);
LED(num2, i,5,0,0,0);
}
for(i=2; i<6; i++){
LED(num2+1, i,2,c1,c2,c3);
LED(num2+1, 2,i,c1,c2,c3);
LED(num2+1, 5,i,c1,c2,c3);
LED(num2+1, i,5,c1,c2,c3);
}
for(i=1; i<7; i++){
LED(num3, i,1,0,0,0);
LED(num3, 1,i,0,0,0);
LED(num3, 6,i,0,0,0);
LED(num3, i,6,0,0,0);
}
for(i=1; i<7; i++){
LED(num3+1, i,1,c1,c2,c3);
LED(num3+1, 1,i,c1,c2,c3);
LED(num3+1, 6,i,c1,c2,c3);
LED(num3+1, i,6,c1,c2,c3);
}
for(i=0; i<8; i++){
LED(num4, i,0,0,0,0);
LED(num4, 0,i,0,0,0);
LED(num4, 7,i,0,0,0);
LED(num4, i,7,0,0,0);
}
for(i=0; i<8; i++){
LED(num4+1, i,0,c1,c2,c3);
LED(num4+1, 0,i,c1,c2,c3);
LED(num4+1, 7,i,c1,c2,c3);
LED(num4+1, i,7,c1,c2,c3);
}
delay(2);
}//m

num1=8;
num2=11;
num3=13;
num4=17;

for(m=0; m<20; m++){
num1--;
num2--;
num3--;
num4--;
for(i=3; i<5; i++){
LED(num1, i,3,0,0,0);
LED(num1, 3,i,0,0,0);
LED(num1, 4,i,0,0,0);
LED(num1, i,4,0,0,0);
}
for(i=3; i<5; i++){
LED(num1-1, i,4,0,0,15);
LED(num1-1, 4,i,0,0,15);
LED(num1-1, 3,i,0,0,15);
LED(num1-1, i,3,0,0,15);
}
for(i=2; i<6; i++){
LED(num2, i,2,0,0,0);
LED(num2, 2,i,0,0,0);
LED(num2, 5,i,0,0,0);
LED(num2, i,5,0,0,0);
}
for(i=2; i<6; i++){
LED(num2-1, i,2,0,0,15);
LED(num2-1, 2,i,0,0,15);
LED(num2-1, 5,i,0,0,15);
LED(num2-1, i,5,0,0,15);
}
for(i=1; i<7; i++){
LED(num3, i,1,0,0,0);
LED(num3, 1,i,0,0,0);
LED(num3, 6,i,0,0,0);
LED(num3, i,6,0,0,0);
}
for(i=1; i<7; i++){
LED(num3-1, i,1,0,0,15);
LED(num3-1, 1,i,0,0,15);
LED(num3-1, 6,i,0,0,15);
LED(num3-1, i,6,0,0,15);
}
for(i=0; i<8; i++){
LED(num4, i,0,0,0,0);
LED(num4, 0,i,0,0,0);
LED(num4, 7,i,0,0,0);
LED(num4, i,7,0,0,0);
}
for(i=0; i<8; i++){
LED(num4-1, i,0,0,0,15);
LED(num4-1, 0,i,0,0,15);
LED(num4-1, 7,i,0,0,15);
LED(num4-1, i,7,0,0,15);
}
delay(2);
}//m

}//counter

}//harlem SHake


#endif
