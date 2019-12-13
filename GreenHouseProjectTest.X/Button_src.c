#include "Button_driver.h"
#include "LCD_driver.h"
#include <pic.h>
#include "Thermometer_driver.h"
#include "clock_driver.h"
#include "Buzzer_driver.h"
#include "math_driver.h"
#include "Day_of_week_driver.h"


void initialise_buttons(){
    ADCON1 = 0x06;
    TRISC = 0xf0;//11110000
    a = 0x00;    //hours increments
    b = 0x00;    //b utton chooser
    c = 0x00;    //m ins increments
    z = 0;       //base increment
    day_low = 0;
    stats = 1;
    p = 0;
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
            write_char('h');
            write_char('r');
            write_char('e');
            write_char('s');
            write_char('h');
            write_char('o');
            write_char('l');
            write_char('d');
            write_char('s');
            write_char(':');
            
            //-------------------display current temp---------------------------//
            
           //------------------------------------------------------------------//
           //-------PORT_CHANGE------------------------------------------------//
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            //--------TEMP----INCREMENTOR---------------------------//
            if(RC7 == 0 && b =='x'){
                    x++ ;
                    x = modulus_func(x,10);
                    if (p == 1){
                        y = incrementor(y,x,'0');
                        p = 0;
                    }
                    if (x == 9){
                        p = 1;
                    }
                    //y = incrementor(y,x,'9');
                    // a = time_date_hex_terminator(a,'T'); //resets hex value to 0 depending on limiter
                    button_delay();
            }
             RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            if(RC7==0 && b == 'y'){ 
                    t++;
                    t = modulus_func(t,10);
                   if (p == 1){
                        w = incrementor(w,t,'0');
                        p = 0;
                    }
                    if (t == 9){
                        p = 1;
                    }
                    button_delay();
            }
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            if(RC7==0 && b == 'z'){ 
                    night_lower_lower++;
                    night_lower_lower = modulus_func(night_lower_lower,10);
                   if (p == 1){
                        night_lower_upper = incrementor(night_lower_upper,night_lower_lower,'0');
                        p = 0;
                    }
                    if (night_lower_lower == 9){
                        p = 1;
                    }
                    button_delay();
            }
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            if(RC7==0 && b == 'a'){ 
                    day_lower_lower++;
                    day_lower_lower = modulus_func(day_lower_lower,10);
                   if (p == 1){
                        day_lower_upper = incrementor(day_lower_upper,day_lower_lower,'0');
                        p = 0;
                    }
                    if (day_lower_lower == 9){
                        p = 1;
                    }
                    button_delay();
            }
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            z = modulus_func(z,4);
            if(RC4 == 0 && z ==0){
            z++;
            write_cmd(0x90);
            write_char('D');
            write_char('a');
            write_char('y');
            write_char('(');
            write_char('U');
            write_char(')');
            write_char(':');
            write_char(' ');
            write_char(' ');
           write_char(var1 + '0');
           write_char(var2 + '0');
            b = 'x';
            button_delay();
            }
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            if(RC4 == 0 && z ==1){
            write_cmd(0x90);
            write_char('N');
            write_char('i');
            write_char('g');
            write_char('h');
            write_char('t');
            write_char('(');
            write_char('U');
            write_char(')');
            write_char(':');
            write_char(cold_high + '0');
            write_char(cold_low + '0');
            b = 'y';
            z++;
            button_delay();
            }
            RC0 = 1;
            RC1 = 0;
            RC2 = 1;
            RC3 = 1;
            if(RC4 == 0 && z ==2){
            write_cmd(0x90);
            write_char('N');
            write_char('i');
            write_char('g');
            write_char('h');
            write_char('t');
            write_char('(');
            write_char('L');
            write_char(')');
            write_char(':');
           write_char(cold_high_night + '0');
           write_char(cold_low_night + '0');
            b = 'z';
            z++;
            button_delay();
            }
            if(RC4 == 0 && z ==3){
            z++;
            write_cmd(0x90);
            write_char('D');
            write_char('a');
            write_char('y');
            write_char('(');
            write_char('L');
            write_char(')');
            write_char(':');
            write_char(' ');
            write_char(' ');
           write_char(var1 + '0');
           write_char(var2 + '0');
            b = 'a';
            button_delay();
            }
            write_cmd(0x88);
            write_char('T');
            write_char('1');
            write_char(':');
            write_char(y + '0');
            write_char(x + '0');
            write_char('T');
            write_char('2');
            write_char(':');
            write_char(w + '0');
            write_char(t + '0');
            write_char('T');
            write_char('3');
            write_char(':');
            write_char(night_lower_upper + '0');
            write_char(night_lower_lower + '0');
            write_cmd(0x98);
            write_char('T');
            write_char('4');
            write_char(':');
            write_char(day_lower_upper + '0');
            write_char(day_lower_lower + '0');
//------------------------------------------------------------------------------            
//            t = 0;     //used for counting down
//            w = 0;     //used for counting down
//            x = 0;     //used for counting tens digit
//            y = 0; //used for counting ones digit
//            for(;;){
//                 RC0 = 1;
//                 RC1 = 0;
//                 RC2 = 1;
//                 RC3 = 1;
//                 //-------------INCREMENT------------------------------------//
//                if(RC7==0){
//                    write_cmd(0x98);
//                    x++;
//                    y = (unsigned char )y;
//                    x = (unsigned char )(modulus_func(x,10));
//                    write_char(y + '0');
//                    write_char(x + '0');
//                    y = incrementor(y,x,'9'); //x is lower val, y is upper val to be incremented and 9 is x's limit
//                    t = x;
//                    w = y;
//                    button_delay();
//                }
//                  RC0 = 0;
//                    RC1 = 1;
//                    RC2 = 1;
//                    RC3 = 1;
//                    if(RC6 == 0){ 
//                        var1 = y;
//                        var2 = x;
//                        //set_beep_threshhold(var1,var2);
//                        write_cmd(0x1);
//                        write_char('S');
//                        write_char('A');
//                        write_char('V');
//                        write_char('E');
//                        write_char('D');
//                        for(int i=0;i<30000;i++);
//                        return;
//                    }
//                 RC0 = 1;
//                 RC1 = 1;
//                 RC2 = 0;
//                 RC3 = 1;
//                 //------------DECREMENT-------------------------------------//
//                 if(RC7 == 0){
//                    write_cmd(0x98);
//                      t--;
//                    w = (unsigned char )w;
//                    t = (unsigned char )(modulus_func(t,10));
//                    write_char(w + '0');
//                    write_char(t + '0');
//                    w = decrementor(w,t,'0');
//                    if((t + '0')=='0'){
//                        t = 10;
//                    }
//
//                    x = t;
//                    y = w;
//                    button_delay();
//                 }
                RC0 = 0;
                RC1 = 1;
                RC2 = 1;
                RC3 = 1;
                    if(RC6 == 0){
                        var1 = w;
                        var2 = t;
                        w = 0;
                        t = 0;
                        x = 0;
                        t = 0;
                        //set_beep_threshhold(var1,var2);
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
             w = 0;
                        t = 0;
                        x = 0;
                        t = 0;
            return;   
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
                if(stats == 1)
                   a++;
                if(stats == 0){
                   stats = 1;
                }
                // a++;//hrs incrementor
                    x++ ;
                    x = modulus_func(x,10);
                    if (p == 1){
                        y = incrementor(y,x,'0');
                        p = 0;
                    }
                    if (x == 9){
                        p = 1;
                    }
                    //y = incrementor(y,x,'9');
                    //hrs_limiter = (a + '0');
                    a = time_date_hex_terminator(a,'T'); //resets hex value to 0 depending on limiter
                    if(y == 2 && x  == 4){
                        x = 0;
                        y = 0;
                    }
                    button_delay();
            }
            if(RC7==0 && b == 'y'){ 
                 if(stats == 1)
                   c++;
                if(stats == 0){
                    stats = 1;
                }
                    //c++; //mins incrementor
                    t++;
                    t = modulus_func(t,10);
                      if (p == 1){
                        w = incrementor(w,t,'0');
                        p = 0;
                    }
                    if (t == 9){
                        p = 1;
                    }
                    
                    if(c == (0x59 + 1)){               //different terminator due to hex val
                        c = 0x00; 
                    }
                    if(w == 6){
                        w = 0;
                        t = 0;
                    }
                    button_delay();
            }
            //---------------24HR-LIMIT-TIME-CODE-AND-DISPLAY-----------------//
             write_cmd(0x88);
              if(stats==0){
                  table[2] = prev_hex_hours;               //hrs
                  table[1] = prev_hex_mins;                //mins
              }     
              else if(stats==1)
              {
                 table[2]=  a;                            //hrs
                 table[1] = c;                            //mins
              }
     
           //--------------HOURS-CONTROL-HEX-----------------------------------//
                    a = time_date_delimiter(a,0x11,'9',4);//ABOVE 9
                    a = time_date_delimiter(a,0x21,'J',4);//ABOVE 19
           //--------------------MINS LIMITER-HEX-----------------------------//      
                    c = time_date_delimiter(c,0x11,'9',5);//ABOVE 9
                    c = time_date_delimiter(c,0x21,'J',5);//ABOVE 19
                    c = time_date_delimiter(c,0x31,'Y',5); //ABOVE 29
                    c = time_date_delimiter(c,0x41,'j',5); //ABOVE 39
                    c = time_date_delimiter(c,0x51,'z',5); //ABOVE 49
            //---------------------SAVER---------------------------------------//
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
                    if (RC6 == 0 ){
                          write_cmd(0x1);
                          set_time();
                          a = 0x00;
                          c = 0x00;
                          x = 0;
                          y = 0;
                          w = 0;
                          t = 0;
                         
                          return;
                            }  
                  RC0 = 1;
                  RC1 = 1;
                  RC2 = 0;
                  RC3 = 1;
                  z = modulus_func(z,2);
                  if(RC4 == 0 && z ==0){
                      write_cmd(0x90);
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
                   write_cmd(0x88);
            //--------MINS CONTROL HEX----------------------------------------//
                    
                    
                  RC0 = 1;
                  RC1 = 1;
                  RC2 = 0;
                  RC3 = 1;
            //-------note: think of reusing variables to save space----------// 
             write_cmd(0x88);
             write_char('T');
             write_char('i');
             write_char('m');
             write_char('e');
             write_char(':');
             write_char(y + '0');
             write_char(x + '0');
             write_char(':');
             write_char(w + '0');
             write_char(t + '0');
             
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            a = 0x00;
            c = 0x00;
            x = 0;
            y = 0;
            w = 0;
            t = 0;
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
            if(RC7 == 0 && b =='x'){
                if(stats == 1)
                    a++;
                if(stats == 0){
                    stats = 1;
                }
                //month incrementor
                    x++ ;
                    x = modulus_func(x,10);
                     if (p == 1){
                        y = incrementor(y,x,'0');
                        p = 0;
                    }
                    if (x == 9){
                        p = 1;
                    }
                    a = time_date_hex_terminator(a,'C');            //resets hex value to 0 depending on limiter
                    
                    if(y == 1 && x  == 3){
                        x = 0;
                        y = 0;
                    }
                    button_delay();
            }
            if(RC7==0 && b == 'y'){ 
                 if(stats == 1)
                    day_hex++;
                if(stats == 0){
                    stats = 1;
                }
                    //day_hex++;                                       //date incrementor
                    day_low++;
                    day_low = modulus_func(day_low,10);
                    day_counter = modulus_func(day_low,8);
                    if (p == 1){
                        day_high = incrementor(day_high,day_low,'0');
                        p = 0;
                    }
                    if (day_low == 9){
                        p = 1;
                    }
                    day_hex = time_date_hex_terminator(day_hex,'c'); //resets hex value to 0 depending on limiter
                    if(day_high == 3 && day_low==2 ){
                        day_high = 0;
                        day_low = 0;
                    }
                    button_delay();
            }
            if(RC7==0 && b == 'z'){ 
                if(stats == 1)
                   c++;
                if(stats == 0){
                    stats = 1;
                }
                    //c++;                                            //year incrementor
                    t++;
                    t = modulus_func(t,10);
                     if (p == 1){
                        w = incrementor(w,t,'0');
                        p = 0;
                    }
                    if (t == 9){
                        p = 1;
                    }
                    //w = incrementor(w,t,'9');
                     if(c == (0x59 + 1)){                            //different terminator due to hex val
                        c = 0x00; 
                    }
                    if(w == 6){
                        w = 0;
                        t = 0;
                    }
                    button_delay();
            }
            //-----------------------table-set---------------------------------//
            //3,4,6
            //if(stats ==0)
             
            //--------MONTH----HEX--------------------------------------------//
                    a = time_date_delimiter(a,0x11,'9',1);//ABOVE 9
            //--------DATE-----HEX--------------------------------------------//
                    day_hex = time_date_delimiter(day_hex,0x11,'9',2);//ABOVE 9
                    day_hex = time_date_delimiter(day_hex,0x21,'J',2);//ABOVE 19
                    day_hex = time_date_delimiter(day_hex,0x11,'9',2);//ABOVE 9
                    day_hex = time_date_delimiter(day_hex,0x21,'J',2);//ABOVE 19
                    day_hex = time_date_delimiter(day_hex,0x31,'Y',2); //ABOVE 29
            //--------YEAR-----HEX--------------------------------------------//
                    c = time_date_delimiter(c,0x11,'9',3);//ABOVE 9
                    c = time_date_delimiter(c,0x21,'J',3);//ABOVE 19
                    c = time_date_delimiter(c,0x11,'9',3);//ABOVE 9
                    c = time_date_delimiter(c,0x21,'J',3);//ABOVE 19
                    c = time_date_delimiter(c,0x31,'Y',3); //ABOVE 29
                    c = time_date_delimiter(c,0x41,'j',3); //ABOVE 39
                    c = time_date_delimiter(c,0x51,'z',3); //ABOVE 49
            //holding state== done. saving state............fuk
              if(stats==0){
                  table[4] = prev_hex;               //month
                  table[6] = prev_hex_year;          //year
                  table[3] = prev_hex_day;           //day
              }     
              else if(stats==1)
              {
                 table[4]=  a;          //month
                 table[6] = c;          //year
                 table[3] = day_hex;    //day
              }
                
             write_cmd(0x88);
                   
                  RC0 = 0;
                  RC1 = 1;
                  RC2 = 1;
                  RC3 = 1;
            //-------------------SAVER----------------------------------------//
                    if (RC6 == 0 ){
                          set_time();
                          a = 0x00;
                          c = 0x00;
                          day_hex = 0x00;
                          day_high = 0;
                          day_low = 0;
                          x = 0;
                          y = 0;
                          w = 0;
                          t = 0;
                          write_cmd(0x1);
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
                      write_char(' ');
                      write_char(' ');
                      b = 'y';
                      //write_cmd(0x88);
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
                      b = 'x';
                      //write_cmd(0x88);
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
                      write_char(' ');
                      b = 'z';
                     // write_cmd(0x88);
                  }
              write_cmd(0x88);
              write_char(day_high + '0');
              write_char(day_low + '0');
              write_char('/');
              write_char(y + '0');
              write_char(x + '0');
              write_char('/');
              write_char(w+ '0');
              write_char(t+ '0');
            
            //-------note: think of reusing variables to save space----------// 
            RC0 = 0;
            RC1 = 1;
            RC2 = 1;
            RC3 = 1;
            if (RC7 == 0 ){
            a = 0x00;
            c = 0x00;
            day_hex = 0x00;
            x = 0;
            y = 0;
            w = 0;
            t = 0;
            day_high = 0;
            day_low = 0;
            write_cmd(0x1);
            break;
            }
      }
  }
  } 

void button_delay(){
    for(int i=0;i<10000;i++);
}