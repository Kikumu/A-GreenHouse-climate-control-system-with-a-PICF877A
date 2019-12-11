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


char time_date_delimiter(char val,char hex,char limiter, int type){
    if((val + '0') == limiter){
    val = hex;
    stats=0;
    if(limiter == '9' && type ==1)
        prev_hex= 0x09;
    if(limiter == 'J'&& type ==1)
        prev_hex = 0x19;
    if(limiter == 'Y'&& type ==1)
        prev_hex = 0x29;
    if(limiter == 'j'&& type ==1)
        prev_hex =0x39;
    if(limiter == 'z'&& type ==1)
        prev_hex = 0x49;
    if(limiter == '9' && type ==2)
        prev_hex_day= 0x09;
    if(limiter == 'J'&& type ==2)
        prev_hex_day = 0x19;
    if(limiter == 'Y'&& type ==2)
        prev_hex_day = 0x29;
    if(limiter == 'j'&& type ==2)
        prev_hex_day =0x39;
    if(limiter == 'z'&& type ==2)
        prev_hex_day = 0x49;
    if(limiter == '9' && type ==3)
        prev_hex_year= 0x09;
    if(limiter == 'J'&& type ==3)
        prev_hex_year = 0x19;
    if(limiter == 'Y'&& type ==3)
        prev_hex_year = 0x29;
    if(limiter == 'j'&& type ==3)
        prev_hex_year =0x39;
    if(limiter == 'z'&& type ==3)
        prev_hex_year = 0x49;
     if(limiter == '9' && type ==4)
        prev_hex_hours= 0x09;
    if(limiter == 'J'&& type ==4)
        prev_hex_hours = 0x19;
    if(limiter == 'Y'&& type ==4)
        prev_hex_hours = 0x29;
    if(limiter == 'j'&& type ==4)
        prev_hex_hours =0x39;
    if(limiter == 'z'&& type ==4)
        prev_hex_hours = 0x49;
     if(limiter == '9' && type ==5)
        prev_hex_mins= 0x09;
    if(limiter == 'J'&& type ==5)
        prev_hex_mins = 0x19;
    if(limiter == 'Y'&& type ==5)
        prev_hex_mins = 0x29;
    if(limiter == 'j'&& type ==5)
        prev_hex_mins =0x39;
    if(limiter == 'z'&& type ==5)
        prev_hex_mins = 0x49;
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

