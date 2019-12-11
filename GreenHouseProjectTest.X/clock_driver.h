#ifndef CLOCK_DRIVER_H
#define CLOCK_DRIVER_H

#include <pic.h>
#include "LCD_driver.h"
#include "clock_driver.h"
#include "Threshold_driver.h"
#include "Buzzer_driver.h"

//--------------PARAMETERS------------------------------------------------------
#define i_o        RB4                           //1302I_O           
#define sclk       RB0                           //1302 clock        
#define rst_time   RB5                           //1302 enable bit   


//define the time: sec,min,hour,day,month,week,year,control word.
//------------NEEDS EDITING-----------------------------------------------------
//const char a = '1';
//const char b = '3';
//const char c = 'x';
//const char d = '0';
//const char my_string[] = { '0','x','1', '3', '\0' };
char table[]={0,0x02,0x00,0x12,0x12,0x06,0x19,0x00}; //date time set up
char table1[7];
char temp_low;
char temp_high;

//------------FUNCTIONS---------------------------------------------------------
void ds1302_init();                             //DS1302 initilize subroutine.
void set_time();                                //set time subroutine.
void get_time();                                //get time subroutine.
void display_clock();                           //display subroutine.
void display_date();                            //disply date subroutine
void time_write_1(unsigned char time_tx);       //write one byte subroutine.
unsigned char  time_read_1();                   //read one byte subroutine.
void delay_time();                              //delay subroutine.

#endif