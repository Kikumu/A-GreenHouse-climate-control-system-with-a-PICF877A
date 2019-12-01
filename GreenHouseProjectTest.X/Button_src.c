#include "Button_driver.h"
#include "LCD_driver.h"
#include <pic.h>
#include "Thermometer_driver.h"
#include "clock_driver.h"
#include "Buzzer_driver.h"
#include "math_driver.h"


void initialise_buttons(){
    ADCON1 = 0x06;
    TRISC = 0xf0;//11110000
    a = 0x00;
    b = 0x00;
    z = 0;  
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
            t = 0;     //used for counting down
            w = 0;     //used for counting down
            x = 0;     //used for counting tens digit
            y = 0; //used for counting ones digit
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
                    y = (unsigned char )y;
                    x = (unsigned char )(modulus_func(x,10));
                    write_char(y + '0');
                    write_char(x + '0');
                    y = incrementor(y,x,'9'); //x is lower val, y is upper val to be incremented and 9 is x's limit
                    t = x;
                    w = y;
                    button_delay();
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
                    w = (unsigned char )w;
                    t = (unsigned char )(modulus_func(t,10));
                    write_char(w + '0');
                    write_char(t + '0');
                    w = decrementor(w,t,'0');
                    if((t + '0')=='0'){
                        t = 10;
                    }

                    x = t;
                    y = w;
                    button_delay();
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
                        button_delay();
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
            //-------PORT_CHANGE------------------------//
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            //--------TIME----INCREMENTOR---------------------------//
            if(RC7 == 0 && b =='x'){
                    a++;//hrs incrementor
                    x++ ;
                    x = modulus_func(x,10);
                    y = incrementor(y,x,'9');
                    button_delay();
            }
            else if(RC7==0 && b == 'y'){ //mins incrementor
                    t++;
                    t = modulus_func(t,10);
                    w = incrementor(w,x,'9');
                    button_delay();
            }
            //---------------24HR-LIMIT-TIME-CODE-AND-DISPLAY---------------------//
             write_cmd(0x88);
                    (table[1]) = a; 
                   
                    // write_char(y + '0');
                    //write_char(x + '0');
                    write_char(a + '0');
                    
                    if((a + '0') == '9'){ //ABOVE 9
                        a = 0x11;
                        a--;
                    }
                    if((a + '0')=='J'){ //ABOVE 19
                        a = 0x21;
                        a--;
                    }
                    //25 ==u---- w ==27 x==28  y==29,//z==30//i ==39 //j = 40
                    if((a + '0')== 'Y'){
                        a = 0x31;
                        a--;
                    }
                    if((a + '0')== 'j'){
                        a = 0x41;
                        a--;
                    }
                    //t ==44
                    if((a + '0')== 'z'){
                        a = 0x51;
                        a--;
                    }
                    if(a == 0x59){
                        a =0x00;
                    }
                    
                    //if()
//                    if((a + '0')=='T'){ //24 HR LIMIT
//                        //a = 0x00;
//                        x = 0x00;
//                        y = 0x00;
//                    }
                    //23 =m;
//                    if(a + '0'==){
//                        
//                    }
            //---------------------SAVER---------------------------------------//
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
                    if (RC6 == 0 ){
                          write_cmd(0x1);
                          set_time();
                          return;
                            }  
                  RC0 = 1;
                  RC1 = 1;
                  RC2 = 0;
                  RC3 = 1;
                  z = modulus_func(z,2);
                  if(RC4 == 0 && z ==0){
                      
                      write_cmd(0x90);
                      x = 0;
                      y = 0;
                     // a = 0x00;
                      write_char('H');
                      write_char('o');
                      write_char('u');
                      write_char('r');
                      write_char(':');
                      b = 'x';
                      button_delay();
                      z++;
                  }
                  RC0 = 1;
                  RC1 = 1;
                  RC2 = 0;
                  RC3 = 1;
                 
                  if(RC4 == 0&& z ==1){
                      z++;
                      button_delay();
                      write_cmd(0x90);
                      write_char('M');
                      write_char('i');
                      write_char('n');
                      write_char('s');
                      write_char(':');
                       b = 'y';
                  }
                  RC0 = 1;
                  RC1 = 1;
                  RC2 = 0;
                  RC3 = 1;
            //-------note: think of reusing variables to save space----------// 
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
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            //--------TIME----INCREMENTOR---------------------------//
            if(RC7 == 0 && b =='x'){
                    a++;//hrs incrementor
                    button_delay();
            }
            else if(RC7==0 && b == 'y'){ //mins incrementor
                    //b++;
                    button_delay();
            }
            else if(RC7==0 && b == 'z'){ //mins incrementor
                   // b++;
                    button_delay();
            }
            
            //---------------24HR-LIMIT-TIME-CODE-AND-DISPLAY---------------------//
             write_cmd(0x88);
                    (table[2]) = a; 
                    write_char(a + '0');
                    if((a + '0') == '9'){ //ABOVE 9
                        a = 0x11;
                        a--;
                    }
                    if((a + '0')=='J'){ //ABOVE 19
                        a = 0x21;
                        a--;
                    }
                    if((a + '0')=='T'){ //24 HR LIMIT
                        a = 0x00;
                    }
                    //-------------------SAVER-------------------------//
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
                    if (RC6 == 0 ){
                          write_cmd(0x1);
                          set_time();
                          return;
                            }  
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
                  z = modulus_func(z,3);
                  if(RC4 == 0 && z ==0){
                      write_cmd(0x90);
                      write_char('D');
                      write_char('a');
                      write_char('y');
                      write_char(':');
                      b = 'x';
                      write_cmd(0x88);
                      button_delay();
                      z++;
                  }
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
                  if(RC4 == 0&& z ==1){
                      z++;
                      button_delay();
                      //write_cmd(0x1);
                      write_cmd(0x90);
                      write_char('M');
                      write_char('o');
                      write_char('n');
                      write_char('t');
                      write_char('h');
                      write_char(':');
                      b = 'y';
                      write_cmd(0x88);
                  }
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
                  if(RC4 == 0&& z ==2){
                      button_delay();
                      z++;
                      //write_cmd(0x1);
                      write_cmd(0x90);
                      write_char('Y');
                      write_char('e');
                      write_char('a');
                      write_char('r');
                      write_char(':');
                      b = 'z';
                      write_cmd(0x88);
                  }
            //-------note: think of reusing variables to save space----------// 
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

void button_delay(){
    for(int i=0;i<10000;i++);
}