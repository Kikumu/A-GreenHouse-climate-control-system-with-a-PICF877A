#ifndef THRESHOLD_DRIVER_H
#define THRESHOLD_DRIVER_H

#include "Thermometer_driver.h"
#include "LCD_driver.h"
unsigned char upper_t;
unsigned char lower_t;
char buzzer_watcher;
void set_upper_threshold(int,int);
void set_lower_threshold(int,int);
#endif