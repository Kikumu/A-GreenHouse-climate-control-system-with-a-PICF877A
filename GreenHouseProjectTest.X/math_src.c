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

//                    c = time_date_delimiter(c,0x11,'9');//ABOVE 9
//                    c = time_date_delimiter(c,0x21,'J');//ABOVE 19
//                    c = time_date_delimiter(c,0x31,'Y'); //ABOVE 29
//                    c = time_date_delimiter(c,0x41,'j'); //ABOVE 39
//                    c = time_date_delimiter(c,0x51,'z'); //ABOVE 49
char time_date_delimiter(char val,char hex,char limiter){
    if((val + '0') == limiter){
    val = hex;
    stats=0;
    if(limiter == '9')
    prev_hex= 0x09;
    if(limiter == 'J')
        prev_hex = 0x19;
    if(limiter == 'Y')
        prev_hex = 0x29;
    if(limiter == 'j')
        prev_hex =0x39;
    if(limiter == 'z')
        prev_hex = 0x49;
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

