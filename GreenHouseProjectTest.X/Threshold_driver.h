#ifndef THRESHOLD_DRIVER_H
#define THRESHOLD_DRIVER_H

#include "Thermometer_driver.h"
#include "LCD_driver.h"
#include <pic.h>
unsigned int  heat_counter;          //counts how many system cycles temperature isabove the needed state
unsigned int  cold_counter;          //counts how many system cycles temperature isabove the needed state
unsigned char upper_t;               //upper value(ones bit)
unsigned char lower_t;               //lower value(tens bit)
char buzzer_watcher;                 //variable to trigger buzzer on or off
char buzzer_watcher1;                //variable to trigger buzzer on or off
int count;                           //reinforces 'reset' state
unsigned char heater_state;          //HEATER indicator ('1'- ON, '0' - OFF, '-' - ERROR)
unsigned char cooler_state;          //cooler indicator('1'- ON, '0' - OFF, '-' - ERROR)
char set_upper_threshold(int,int);   //hot range
char set_lower_threshold(int,int);   //normal range
char cold_threshold(int,int);        //cold range
char reset_alarm();                  //resets alarm
#endif