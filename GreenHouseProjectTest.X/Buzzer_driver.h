#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#include <pic.h>


#define beep_alert RE1
char var1;
char var2;


void set_beep_threshhold(char x, char y);

#endif