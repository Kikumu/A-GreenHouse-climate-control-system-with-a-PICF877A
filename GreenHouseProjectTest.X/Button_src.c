#include "Button_driver.h"
#include "LCD_driver.h"
#include <pic.h>
#include "Thermometer_driver.h"
#include "clock_driver.h"
#include "Buzzer_driver.h"


void initialise_buttons(){
    ADCON1 = 0x06;
    TRISC = 0xf0;//11110000
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
            //-------------------display current temp---------------------------//
            write_char(var1 + '0');
            write_char(var2 + '0');
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
            int t = 0;     //used for counting down
            int w = 0;     //used for counting down
            int x = 0;     //used for counting tens digit
            int y = 0; //used for counting ones digit
            x = 0x00;
            for(;;){
                 RC0 = 1;
                 RC1 = 0;
                 RC2 = 1;
                 RC3 = 1;
                 //-------------INCREMENT------------------------------------//
                if(RC7==0){
                    write_cmd(0x98);
                    x++;
                    x = (unsigned char )(x % 10);
                    write_char(y + '0');
                    write_char(x + '0');
                    if('9' == (x + '0')){
                        y++;
                        y = (unsigned char )(y % 10);
                    }
                    t = x;
                    w = y;
                    for(int i=0;i<10000;i++);
                }
                  RC0 = 0;
                    RC1 = 1;
                    RC2 = 1;
                    RC3 = 1;
                    if(RC6 == 0){
                       
                        
                        var1 = y;
                        var2 = x;
                        set_beep_threshhold(var1,var2);
                        write_cmd(0x1);
                        write_char('S');
                        write_char('A');
                        write_char('V');
                        write_char('E');
                        write_char('D');
                        for(int i=0;i<30000;i++);
                        return;
                    }
                 RC0 = 1;
                 RC1 = 1;
                 RC2 = 0;
                 RC3 = 1;
                 //------------DECREMENT-------------------------------------//
                 if(RC7 == 0){
                    write_cmd(0x98);
                    t--;
                    t = (unsigned char)(t % 10);
                    write_char(w + '0');
                    write_char(t + '0');
                    if('0' == (t + '0')){
                        w--;
                        w = (unsigned char)(w % 10);
                        t = 10;
                    }
                    x = t;
                    y = w;
                    for(int i=0;i<10000;i++);  
                 }
                RC0 = 0;
                RC1 = 1;
                RC2 = 1;
                RC3 = 1;
                    if(RC6 == 0){
                        var1 = w;
                        var2 = t;
                        set_beep_threshhold(var1,var2);
                        write_cmd(0x1);
                        write_char('S');
                        write_char('A');
                        write_char('V');
                        write_char('E');
                        write_char('D');
                        for(int i=0;i<10000;i++);
                        return;
                    }
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            write_cmd(0x1);
            return;   
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