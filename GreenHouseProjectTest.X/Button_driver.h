#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include "SystemHeader.h"
#include <pic.h>

unsigned char a;               //hrs/YEAR incrementor          
unsigned char b;               //button chooser
unsigned char c;               //mins/MONTH incrementor
unsigned char day_hex;         //Day incrementor
unsigned char hrs_limiter;
unsigned int t;
unsigned int w;
unsigned int x;
unsigned int y;
unsigned int z;
unsigned int day_low;          //day lower value(display)
unsigned int day_high;         //day upper value(display)
unsigned int day_of_week_var;  //monitor day of week
unsigned int stats;
unsigned char prev_hex;
unsigned int p;
unsigned int var_night_low;
unsigned int var_night_high;
void thermometer_threshhold_settings();
void date_settings();
void time_settings();
void initialise_buttons();
void button_delay();
#endif