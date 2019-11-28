#ifndef CLOCK_DRIVER_H
#define CLOCK_DRIVER_H

#include <pic.h>

//--------------PARAMETERS------------------------------------------------------
#define i_o        RB4                           //1302I_O           
#define sclk       RB0                           //1302 clock        
#define rst_time   RB5                           //1302 enable bit   


//define the time: sec,min,hour,day,month,week,year,control word.
//------------NEEDS EDITING-----------------------------------------------------
const char table[]={0x00,0x43,0x07,0x24,0x11,0x06,0x09,0x00}; //date time set up
char table1[7];


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