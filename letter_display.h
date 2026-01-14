#ifndef LETTER_DISPLAY_H
#define LETTER_DISPLAY_H
#include "LED.h"

extern const byte A[],B[],C[],D[],E[],F[],G[],H[],I[],J[],K[],L[],M[],N[],O[],P[],Q[],R[],S[],T[],U[],V[],W[],X[],Y[],Z[],Sp[],Two[],Four[],Exp[];

void scrollText();
void disp(int, int, int, int, int);
byte whichChar(char, int);

void scrollText(){
  extern int ii[][8];
  extern char phrase[];
  int i = 0,j,k,t = 22, iterator;
  byte tmp;
  int l = 0;
  uint8_t select;
  uint8_t rr,gg,bb;
  iterator = 0;
  while(iterator < 2){
  
  select=random(3);
  switch(select){
    case 0:
      rr=random(1, 16);
      gg=random(1, 16);
      bb=0;
      break;
       
    case 1:
      rr=random(1, 16);
      gg=0;
      bb=random(1, 16);
      break;
          
    case 2:
      rr=0;
      gg=random(1, 16);
      bb=random(1, 16);
      break;
  }// end switch
    
  
    for(i=0;i<22;i++){ //clears virtual plane to blank
      for(j=0;j<8;j++){
        ii[i][j] = 0;
      }
    }
    do{
      l++;
    }while(phrase[l++] != '\0'); //determines strlen
    
    for(k=0;k<(22+(l*6));k++){ //creates loop tailored to string size
      for(j=21;j>0;j--){ //writes existing virtual plane in segments 21 to 1
        for(i=0;i<8;i++){
          ii[j][i] = ii[j-1][i]; 
          switch(ii[j][i]){
            case 0:
              disp(j,i,0,0,0);
              break;
            case 1:
              disp(j,i,rr,gg,bb);
              break;
          }
        }
      }
      if(k<(l*6)){
        for(i=0;i<8;i++){
          ii[0][i] = bitRead(whichChar(phrase[k/6],k%6),i);
          switch(ii[0][i]){
            case 0:
              disp(0,i,0,0,0);
              break;
            case 1:
              disp(0,i,rr,gg,bb);
              break;
          }
        }
        delay(80);
      }else{
        for(i=0;i<8;i++){
          ii[0][i] = 0;
        }
        LED(0,0,0,0,0,0);
        LED(1,0,0,0,0,0);
        LED(2,0,0,0,0,0);
        LED(3,0,0,0,0,0);
        LED(4,0,0,0,0,0);
        LED(5,0,0,0,0,0);
        LED(6,0,0,0,0,0);
        LED(7,0,0,0,0,0);
        delay(80);
      }
    }
    iterator++;
  }
}

void disp(int num, int level, int red, int green, int blue){
  switch(num){
    case 0:
      LED(level,0,0,red,green,blue);
      break;
    case 1:
      LED(level,0,1,red,green,blue);
      break;
    case 2:
      LED(level,0,2,red,green,blue);
      break;
    case 3:
      LED(level,0,3,red,green,blue);
      break;
    case 4:
      LED(level,0,4,red,green,blue);
      break;
    case 5:
      LED(level,0,5,red,green,blue);
      break;
    case 6:
      LED(level,0,6,red,green,blue);
      break;
    case 7:
      LED(level,0,7,red,green,blue);
      break;
    case 8:
      LED(level,1,7,red,green,blue);
      break;
    case 9:
      LED(level,2,7,red,green,blue);
      break;
    case 10:
      LED(level,3,7,red,green,blue);
      break;
    case 11:
      LED(level,4,7,red,green,blue);
      break;
    case 12:
      LED(level,5,7,red,green,blue);
      break;
    case 13:
      LED(level,6,7,red,green,blue);
      break;
    case 14:
      LED(level,7,7,red,green,blue);
      break;
    case 15:
      LED(level,7,6,red,green,blue);
      break;
    case 16:
      LED(level,7,5,red,green,blue);
      break;
    case 17:
      LED(level,7,4,red,green,blue);
      break;
    case 18:
      LED(level,7,3,red,green,blue);
      break;
    case 19:
      LED(level,7,2,red,green,blue);
      break;
    case 20:
      LED(level,7,1,red,green,blue);
      break;
    case 21:
      LED(level,7,0,red,green,blue);
      break;
  }
}

byte whichChar(char letter, int i){
  byte temp;
  switch(letter){
    case 'A':
      temp = A[i];
      return temp;
      break;
    case 'B':
      temp = B[i];
      return temp;
      break;
    case 'C':
      temp = C[i];
      return temp;
      break;
    case 'D':
      temp = D[i];
      return temp;
      break;
    case 'E':
      temp = E[i];
      return temp;
      break;
    case 'F':
      temp = F[i];
      return temp;
      break;
    case 'G':
      temp = G[i];
      return temp;
      break;
    case 'H':
      temp = H[i];
      return temp;
      break;
    case 'I':
      temp = I[i];
      return temp;
      break;
    case 'J':
      temp = J[i];
      return temp;
      break;
    case 'K':
      temp = K[i];
      return temp;
      break;
    case 'L':
      temp = L[i];
      return temp;
      break;
    case 'M':
      temp = M[i];
      return temp;
      break;
    case 'N':
      temp = N[i];
      return temp;
      break;
    case 'O':
      temp = O[i];
      return temp;
      break;
    case 'P':
      temp = P[i];
      return temp;
      break;
    case 'Q':
      temp = Q[i];
      return temp;
      break;
    case 'R':
      temp = R[i];
      return temp;
      break;
    case 'S':
      temp = S[i];
      return temp;
      break;
    case 'T':
      temp = T[i];
      return temp;
      break;
    case 'U':
      temp = U[i];
      return temp;
      break;
    case 'V':
      temp = V[i];
      return temp;
      break;
    case 'W':
      temp = W[i];
      return temp;
      break;
    case 'X':
      temp = X[i];
      return temp;
      break;
    case 'Y':
      temp = Y[i];
      return temp;
      break;
    case 'Z':
      temp = Z[i];
      return temp;
      break;
    case '-':
      temp = Sp[i];
      return temp;
      break;
    case '!':
      temp = Exp[i];
      return temp;
      break;
    case '0':
      temp = O[i];
      return temp;
      break;
    case '2':
      temp = Two[i];
      return temp;
      break;
    case '4':
      temp = Four[i];
      return temp;
      break;
    case '\0':
      temp = B00000000;
      return temp;
      break;
    default:
      return B00000000;
  }
}

#endif
