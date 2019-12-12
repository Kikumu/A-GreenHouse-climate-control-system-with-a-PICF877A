#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#include <pic.h>


#define beep_alert RE2             //port assigned for buzzer
char var1;                         //holds tens _bit for day threshhold
char var2;                         //holds ones bit for day thershold
unsigned int var_night_low;        //holds tens bit for night threshold
unsigned int var_night_high;       //holds ones bit for night threshold
unsigned int cold_high;            //holds tens bit for cold threshold
unsigned int cold_low;             //holds ones bit for cold threshold
unsigned int cold_high_night;      //holds tens bit for cold threshold
unsigned int cold_low_night;       //holds ones bit for cold threshold
unsigned char alarm__;             //holds alarm states(on,off)

void set_beep_threshhold(char x);  

#endif