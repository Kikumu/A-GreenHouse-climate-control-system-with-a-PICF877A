#include "Threshold_driver.h"



void set_upper_threshold(int upper_val,int lower_val){
    if(shi ==  upper_val && ge  > lower_val && count == 2){
    
    buzzer_watcher = 'w';  //alets sounder
    write_char('W');
    write_char('A');
    write_char('R');
    write_char('M');
    }
}
//0x98

void set_lower_threshold(int upper_val,int lower_val){
    if(shi == upper_val && ge  < lower_val)
    {
    count = 2;
    buzzer_watcher = 'x'; //silence sounder
    write_char('O');
    write_char('K');
    write_char(' ');
    write_char(' ');
    }
}
//needs to be persistant
void reset_alarm(){
    RC0 = 1;
    RC1 = 1;
    RC2 = 1;
    RC3 = 0;
    if(RC4 == 0){
        count = 0;
        buzzer_watcher = 'x';
    }
}

//3 states, upper, lower, persistance