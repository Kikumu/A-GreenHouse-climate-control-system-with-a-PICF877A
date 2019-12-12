#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include "SystemHeader.h"
#include <pic.h>

unsigned char a;               //hrs/YEAR incrementor          
unsigned char b;               //button chooser
unsigned char c;               //mins/MONTH incrementor
unsigned char day_hex;         //Day incrementor
unsigned char hrs_limiter;      
unsigned int t;                 //stores ones bit
unsigned int w;                 //stores 10s bit
unsigned int x;                 //stores ones bit
unsigned int y;                 //stores 10s bit
unsigned int z;                 //used for button cycles
unsigned int day_low;          //day lower value(display)
unsigned int day_high;         //day upper value(display)
unsigned int day_of_week_var;  //monitor day of week
unsigned int stats;            //switches save state
unsigned char prev_hex;        //holds previous hex value for months variable
unsigned char prev_hex_day;    //holds previous hex value for day variable
unsigned char prev_hex_year;   //holds previous hex value for year variable
unsigned char prev_hex_hours;  //holds previous hex value for hours variable
unsigned char prev_hex_mins;   //holds previous hex value for mins variable
unsigned int d_type;
unsigned int p;                //holds state for counter variable
unsigned int night_lower_upper;
unsigned int night_lower_lower;
unsigned int day_lower_upper;
unsigned int day_lower_lower;
void thermometer_threshhold_settings();
void date_settings();          //change date settings
void time_settings();          //change time settings
void initialise_buttons();     //initialise necessary variables
void button_delay();           //delays system for user input
#endif