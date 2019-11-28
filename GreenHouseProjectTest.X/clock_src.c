#include <pic.h>
#include "LCD_driver.h"
#include "clock_driver.h"


void ds1302_init()                    //DS1302 initilize subroutine.
{
   sclk=0;                            //pull low clock
   rst_time =0;                       //reset DS1302
   rst_time=1;                        //enable DS1302
   time_write_1(0x8e);                //send control command
   time_write_1(0);                   //enable write DS1302
   rst_time=0;                        //reset
}
void set_time()                       //set time subroutine.
{
   int i;                             //define the loop counter.
   rst_time=1;                        //enable DS1302
   time_write_1(0xbe);                //
   for(i=0;i<8;i++)                   //continue to write 8 bytes.
     {
       time_write_1(table[i]);        //write one byte
     }
   rst_time=0;                        //reset
}
void get_time()                       //get time subroutine.
{
   int i;                             //set loop counter.
   rst_time=1;                        //enable DS1302
   time_write_1(0xbf);                //
   for(i=0;i<7;i++)                   //continue to read 7 bytes.
     {
        table1[i]=time_read_1();      
     }
   rst_time=0;                        //reset DS1302
}
void display_clock()                  //display subroutine.
{
     int i;                           //define table variable.
     if(RB1==0)                       //judge rb1.
       {
          table1[0]=table1[3];     
          table1[1]=table1[4];
       }
                                      //delay some times.
     i=table1[2]&0xf0;                //sec's high
     i=i>>4;                          //rotate right for 4 bits.
     write_char(i + '0');
     //delay_time();                    //delay some times. 
     
     
     i=table1[2]&0x0f;                //sec's low.
     write_char(i + '0');
     write_char(':');
     //delay_time();      
     
                                       
     i=table1[1]&0xf0;                //min's high                 
     i=i>>4;                          //rotate right for 4 bits.  
     write_char(i + '0');   
     //delay_time();                    //delay some times.       
     
     i=table1[1]&0x0f;                //min's low.                 
     write_char(i + '0');
     write_char(':');
    // delay_time();            
     
     i=table1[0]&0xf0;                //hour's high                 
     i=i>>4;                          //rotate right for 4 bits.   
     write_char(i + '0');
    // delay_time();                    //delay some times.         
     
     i=table1[0]&0x0f;                //hour's low.             
     write_char(i + '0');    
    // delay_time();                    //delay some times.   
     
     
}
void display_date()                   //disply date subroutine
{
     int i;                         
     if(RB1==0)                     
       {
          table1[0]=table1[3];     
          table1[1]=table1[4];
       }
     i=table1[3]&0xf0;     
     i=i>>4;
     write_char(i + '0');
    // delay_time(); 
     i=table1[3]&0x0f;                                  
     write_char(i + '0');
     write_char('/');
    // delay_time();   
    
                    
     i=table1[4]&0xf0; 
     i=i>>4;
     write_char(i + '0');
    // delay_time();      
     i=table1[4]&0x0f; 
     write_char(i + '0');
     write_char('/');
   //  delay_time();      
                                                  
     
     i=table1[6]&0xf0;                                                             
     write_char(i + '0');   
   //  delay_time(); 
     i=table1[6]&0x0f;                                   
     write_char(i + '0');   
    // delay_time();       
   
}
void time_write_1(unsigned char time_tx)       //write one byte subroutine.
{
    int j;                                     //set the loop counter.
    for(j=0;j<8;j++)                           //continue to write 8bit
   {
        i_o=0;                                 //
        sclk=0;                                //pull low clk
        if(time_tx&0x01)                       //judge the send bit is 0 or 1.
          {
            i_o=1;                             //is 1
          }
        time_tx=time_tx>>1;                    //rotate right 1 bit.
        sclk=1;                                //pull high clk
    }
      sclk=0;                                  //finished 1 byte,pull low clk
}
unsigned char  time_read_1()                   //read one byte subroutine.
{
   unsigned char time_rx=0;
   int j;                                      //set the loop counter.  
   TRISB4=1;                                   //continue to write 8bit 
   for(j=0;j<8;j++)                  
      {
        sclk=0;                                //pull low clk                   
        time_rx=time_rx>>1;                    //judge the send bit is 0 or 1.  
        if(i_o)time_rx=time_rx|0x80;
    //    time_rx7=i_o;                        //put the received bit into the reg's highest.
       sclk=1;                                 //pull high clk                 
      }                                                              
    TRISB4=0;                                  //finished 1 byte,pull low clk  
    sclk=0;                          
    return(time_rx);                  
}
void delay_time()                              //delay subroutine.
{
     int i;                                    //define variable
     for(i=0x64;i--;);                         //delay
}
