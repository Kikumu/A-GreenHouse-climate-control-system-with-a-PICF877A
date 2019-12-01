#include "math_driver.h"



int modulus_func(int x,int y){
    x = x % y;
    return x;
}

char incrementor(int y,int x,char z){
     if(z == (x + '0')){
     y++;
     y =(modulus_func(y,10));
   }
     return y;
}

char decrementor(int w,int t ,char z){
     if(z == (t + '0')){
       // t = 10;
        w--;
        w = (modulus_func(w,10));
        }
     return w;
}

