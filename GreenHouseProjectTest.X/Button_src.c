#include "Button_driver.h"
#include "LCD_driver.h"
#include <pic.h>
#include "Thermometer_driver.h"
#include "clock_driver.h"
#include "Buzzer_driver.h"

char var;


void initialise_buttons(){
    ADCON1 = 0x06;
    TRISC = 0xf0;//11110000
    
    var = '0';
}

void thermometer_threshhold_settings(){
 RC0 = 1;
 RC1 = 0;
 RC2 = 1;
 RC3 = 1;
  if (RC4 == 0){
      write_cmd(0x1);
      for(;;){
            write_cmd(0x80);
            write_char('T');
            write_char('e');
            write_char('m');
            write_char('p');
            write_char('_');
            write_char('t');
            write_char('h');
            write_char('r');
            write_char('e');
            write_char('s');
            write_char('h');
            write_char('o');
            write_char('l');
            write_char('d');
            write_cmd(0x90);
            write_char('C');
            write_char('u');
            write_char('r');
            write_char('r');
            write_char('e');
            write_char('n');
            write_char('t');
            write_char(':');
            set_beep_threshhold(var);
            write_char(var);
            write_char('0');
//------------------------------------------------------------------------------
            write_cmd(0x88);
            write_char('S');
            write_char('e');
            write_char('t');
            write_char('_');
            write_char('t');
            write_char('h');
            write_char('r');
            write_char('e');
            write_char('s');
            write_char('h');
            write_char('o');
            write_char('l');
            write_char('d');
            write_char(':');
//------------------------------------------------------------------------------            
            write_cmd(0x98); 
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            int x;
            x = 0x00;
            for(;;){
                 RC0 = 1;
                 RC1 = 0;
                 RC2 = 1;
                 RC3 = 1;
                if(RC7==0){
                    write_cmd(0x98);
                    x++;
                    //x= (x &0x0f);
                    //x=((x>>4)&0x0f);
                    //x=(x<<8);
                    write_char(x + '0');
                    for(int i=0;i<10000;i++);
//                    write_cmd(0x98);
//                    write_char('1');
//                    write_char('0');  
                    
                 RC0 = 0;
                 RC1 = 1;
                 RC2 = 1;
                 RC3 = 1;
                 if(RC6 == 0){
                     
                 }
                }
                 RC0 = 1;
                 RC1 = 1;
                 RC2 = 0;
                 RC3 = 1;
                if(RC7==0){
                
                    write_cmd(0x98);
                    write_char('2');
                    write_char('0');
                }
                 RC0 = 1;
                 RC1 = 1;
                 RC2 = 1;
                 RC3 = 0;
                 if(RC7==0){
                    write_cmd(0x98);
                    write_char('3');
                    write_char('0');
                }
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            write_cmd(0x1);
            return;   
            }
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            write_cmd(0x1);
            break;
            }
            }
      }
  }
}

void time_settings(){
 RC0 = 1;
 RC1 = 1;
 RC2 = 0;
 RC3 = 1; 

  if (RC4 == 0){
      write_cmd(0x1);
      for(;;){
            write_cmd(0x80);
            write_char('T');
            write_char('i');
            write_char('m');
            write_char('e');
            write_char('_');
            write_char('S');
            write_char('e');
            write_char('t');
            write_char('t');
            write_char('i');
            write_char('n');
            write_char('g');
            write_char('s');
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            write_cmd(0x1);
            break;
            }
      }
  } 
 
}

void date_settings(){
 RC0 = 0;
 RC1 = 1;
 RC2 = 1;
 RC3 = 1;
  if (RC4 == 0){
      write_cmd(0x1);
      for(;;){
            write_cmd(0x80);
            write_char('D');
            write_char('a');
            write_char('t');
            write_char('e');
            write_char('_');
            write_char('S');
            write_char('e');
            write_char('t');
            write_char('t');
            write_char('i');
            write_char('n');
            write_char('g');
            write_char('s');
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            write_cmd(0x1);
            break;
            }
      }
  } 
}