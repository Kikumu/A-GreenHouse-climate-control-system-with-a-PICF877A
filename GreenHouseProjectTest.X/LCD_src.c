#include <pic.h>
#include "LCD_driver.h"


void init()                              //initialise LCD ports
{
 ADCON1 = 0X07;                          //a port as ordinary i/o.
 TRISA0=1;                               //a port as output.
 TRISD=0X00;                             //d port as output.
 OPTION_REG=0X00;                        //open b port internal pull high.
 TRISE = 0X00;                           //E as output forr my beeper(alarm))
}  

void lcd_init()                          //Initialise LCD commands
{
 int i;
 TRISA = 0x00;
 rst=0;
 delay_screen();
 rst=1;
 psb=1;
 write_cmd(0x30);                         //basic operation instruction 8 bit
 write_cmd(0x01);                         //clr screen
 write_cmd(0x06);                         //left to right
 write_cmd(0x0c);                         //display on,cursor on,blink on.
}       

void write_char(char x)                   //used to write characters to LCD
{
 int i;
 rs=1;                                    //is data not command.
 rw=0;                                    //is write not read.
 e=0;
 delay_screen();
 e=1;
 PORTD= x;                                //data send to PORTD
 delay_screen();
 e=0;                                     //pull low enable signal.  
}   

void write_cmd(char x)                    //Used to write commands to LCD
{
 int i;
 rs=0;                                    //is command not data
 rw=0;                                    //is write not read.
 e=0;
 delay_screen();
 e=1;
 PORTD=x;                                 //data send to PORTD
 delay_screen();
 e=0;                                     //pull low enable signal.
    
//    rs = 1;
//    rw = 0;
//    e = 0;
//    delay_screen();
//    e = 1;
//    delay_screen();
//    PORTD = x;
//    delay_screen();
//    e = 0;
}    

void delay_lcd()                          // delay lcd screen for writing
{
 int i;
 for(i=0;i<4000;i++);
}

void delay_screen(){
    int i;
 for(i=0;i<5;i++);
}
