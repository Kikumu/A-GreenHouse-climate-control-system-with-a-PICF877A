#include "math_driver.h"



int modulus_func(int x,int y){
    x = x % y;
    return x;
}

char incrementor(int upper_val,int lower_val,char z){
     if(z == (lower_val + '0')){
     upper_val++;
     upper_val =(modulus_func(upper_val,10));
   }
     return upper_val;
}


char decrementor(int lower_val,int upper_val ,char z){
     if(z == (upper_val + '0')){
        lower_val--;
        lower_val = (modulus_func(lower_val,10));
        }
     return lower_val;
}

char time_date_delimiter(char val,char hex,char limiter){
    if((val + '0') == limiter){
    val = hex;
    val--;
    }
    return val;
}

char time_date_hex_terminator(char val, char limiter){
    if((val + '0')  == limiter){
    val = 0x00;
    }
    return val;
}

