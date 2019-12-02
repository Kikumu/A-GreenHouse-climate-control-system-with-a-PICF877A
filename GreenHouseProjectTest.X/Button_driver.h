#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include "SystemHeader.h"
#include <pic.h>

unsigned char a; //hrs incrementor
unsigned char b; //button chooser
unsigned char c; //mins incrementor
unsigned char hrs_limiter;
unsigned int t;
unsigned int w;
unsigned int x;
unsigned int y;
unsigned int z;
void thermometer_threshhold_settings();
void date_settings();
void time_settings();
void initialise_buttons();
void button_delay();
#endif