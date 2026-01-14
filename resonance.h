#ifndef RESONANCE_H
#define RESONANCE_H

#include "LED.h"

extern unsigned long start;

void resonance(){
  const uint32_t TICK_DELAY = 20;
  int i,ii,jj,kk=0;
  int colorWheel[36] = {15,0,0,15,8,0,15,15,0,8,15,0,0,15,0,0,15,8,0,15,15,0,8,15,0,0,15,8,0,15,15,0,15,15,0,8};
  int a,b,c,d,e,f,g,h;
  int ap,bp,cp,dp,ep,fp,gp,hp,ac,bc,cc,dc,ec,fc,gc,hc;
  ap = bp = cp = dp = ep = fp = gp = hp = 0; //level 0 = a, 2 = b, etc. ap, bp equals level (previous)
  ac = bc = cc = dc = ec = fc = gc = hc = 0;  //ac, bc equals color
  int iter = 0;
  bool zero,one,two,three,four,five,six,seven;
  zero = one = two = three = four = five = six = seven = true; //indicates direction of NEXT move  True = ++, False = --
  a = b = c = d = e = f = g = h = 0;  //letters indicate what column the row is on.  Row a is level 0
  int q = 0;
  start = millis();
  for(ii=0;ii<8;ii++){ //draw all LEDs as red on levels 0-7, rows 0-7, column 0 only
      for(jj=0;jj<8;jj++){
        LED(ii,jj,kk,15,0,0);}}
    delay(100);
    a = b = c = d = e = f = g = h = 1;  //declare all as "1" for next move
  while(millis()-start<5000){
    if(a==7){
      zero = false;
      if(ac >= 30){
        ac = 0;
      }else{
        ac += 3;
      }
    }else if(a==0){
      zero = true;
      ac += 3;
    }
    if(zero==true){
      for(jj=0;jj<8;jj++){
        LED(0,jj,ap,0,0,0);
        LED(7,jj,ap,0,0,0);
        LED(0,jj,a,colorWheel[ac],colorWheel[ac+1],colorWheel[ac+2]);
        LED(7,jj,a,colorWheel[ac],colorWheel[ac+1],colorWheel[ac+2]);
        }
        ap = a;
        a++;
        iter++;
     }else{
      for(jj=0;jj<8;jj++){
        LED(0,jj,ap,0,0,0);
        LED(7,jj,ap,0,0,0);
        LED(0,jj,a,colorWheel[ac],colorWheel[ac+1],colorWheel[ac+2]);
        LED(7,jj,a,colorWheel[ac],colorWheel[ac+1],colorWheel[ac+2]);
        }
        ap = a;
        a--;
        iter++;  
      }
    
    if(iter%2==0){
      if(b==7){
        one = false;
        if(bc >= 30){
          bc = 0;
        }else{
          bc += 3;
        }
      }else if(b==0){
        one = true;
        bc += 3;
      }
      if(one==true){
        for(jj=0;jj<8;jj++){
        LED(1,jj,bp,0,0,0);
        LED(6,jj,bp,0,0,0);
        LED(1,jj,b,colorWheel[bc],colorWheel[bc+1],colorWheel[bc+2]);
        LED(6,jj,b,colorWheel[bc],colorWheel[bc+1],colorWheel[bc+2]);
        }
        bp=b;
        b++;
      }else{
        for(jj=0;jj<8;jj++){
        LED(1,jj,bp,0,0,0);
        LED(6,jj,bp,0,0,0);
        LED(1,jj,b,colorWheel[bc],colorWheel[bc+1],colorWheel[bc+2]);
        LED(6,jj,b,colorWheel[bc],colorWheel[bc+1],colorWheel[bc+2]);}
        bp=b;
        b--;
      }
    }
    
    if(iter%4==0){
      if(c==7){
        two = false;
        if(cc >= 30){
          cc = 0;
        }else{
          cc += 3;
        }
      }else if(c==0){
        two = true;
        cc += 3;
      }
      if(two==true){
        for(jj=0;jj<8;jj++){
        LED(2,jj,cp,0,0,0);
        LED(5,jj,cp,0,0,0);
        LED(2,jj,c,colorWheel[cc],colorWheel[cc+1],colorWheel[cc+2]);
        LED(5,jj,c,colorWheel[cc],colorWheel[cc+1],colorWheel[cc+2]);
        }
        cp=c;
        c++;
      }else{
        for(jj=0;jj<8;jj++){
        LED(2,jj,cp,0,0,0);
        LED(5,jj,cp,0,0,0);
        LED(2,jj,c,colorWheel[cc],colorWheel[cc+1],colorWheel[cc+2]);
        LED(5,jj,c,colorWheel[cc],colorWheel[cc+1],colorWheel[cc+2]);
        }
        cp=c;
        c--;
      }
    }
    
    if(iter%8==0){
      if(d==7){
        three = false;
        if(dc >= 30){
          ec = 0;
          dc = 0;
        }else{
          dc += 3;
          ec += 3;
        }
    }else if(d==0){
      three = true;
      dc += 3;
      ec += 3;
    }  
    if(three==true){
      for(jj=0;jj<8;jj++){
      LED(3,jj,dp,0,0,0);
      LED(4,jj,dp,0,0,0);
      LED(3,jj,d,colorWheel[dc],colorWheel[dc+1],colorWheel[dc+2]);
      LED(4,jj,d,colorWheel[dc],colorWheel[dc+1],colorWheel[dc+2]);}
      dp=d;
      d++;
    }else{
      for(jj=0;jj<8;jj++){
      LED(3,jj,dp,0,0,0);
      LED(4,jj,dp,0,0,0);
      LED(3,jj,d,colorWheel[dc],colorWheel[dc+1],colorWheel[dc+2]);
      LED(4,jj,d,colorWheel[dc],colorWheel[dc+1],colorWheel[dc+2]);}
      dp=d;
      d--;
    }
  }
    delay(TICK_DELAY);
  }
}

#endif
