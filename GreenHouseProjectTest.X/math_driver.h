#ifndef MATH_DRIVER_H
#define MATH_DRIVER_H

#include "Button_driver.h"

int modulus_func(int,int);                  
char incrementor(int,int,char);                //increments chars
char decrementor(int,int,char);                //decrements chars
char time_date_delimiter(char,char,char,int);  //cut off point for time/date
char time_date_hex_terminator(char,char);      //resets time/date to 0

#endif