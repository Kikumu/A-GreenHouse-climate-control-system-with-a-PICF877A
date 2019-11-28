#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

//---------PORT DEFINITIONS FOR LCD-------------------------------------------//
#define rs RA5              //reset LCD
#define rw RA4              //write
#define e RA3               //pullup function
#define psb RA2          
#define rst RA0              

//--------------------function declarations-----------------------------------//
void init();               //initialise LCD ports
void lcd_init();           //Initialise LCD commands
void write_char(char x);   //used to write characters to LCD
void write_cmd(char x);    //Used to write commands to LCD
void delay_lcd();          //delay display to write functions to screen   
void delay_screen();
#endif