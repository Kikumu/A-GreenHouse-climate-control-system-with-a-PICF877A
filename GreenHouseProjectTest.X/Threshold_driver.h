#ifndef THRESHOLD_DRIVER_H
#define THRESHOLD_DRIVER_H

#include "Thermometer_driver.h"
#include "LCD_driver.h"
#include <pic.h>

unsigned char upper_t;
unsigned char lower_t;
char buzzer_watcher;
char buzzer_watcher1;
int count;
unsigned char heater_state;
unsigned char cooler_state;
char set_upper_threshold(int,int);
char set_lower_threshold(int,int);
char reset_alarm();
#endif