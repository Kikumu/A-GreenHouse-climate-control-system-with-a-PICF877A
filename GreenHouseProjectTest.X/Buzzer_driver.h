#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#include <pic.h>


#define beep_alert RE2
char var1;
char var2;
unsigned int var_night_low;
unsigned int var_night_high;
unsigned char alarm__;

void set_beep_threshhold(char x);

#endif