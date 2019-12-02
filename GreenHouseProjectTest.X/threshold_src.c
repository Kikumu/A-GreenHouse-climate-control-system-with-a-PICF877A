#include "Threshold_driver.h"



void set_upper_threshold(int upper_val,int lower_val){
    if(shi ==  upper_val && ge  > lower_val){
    buzzer_watcher = 'w';
    write_char('W');
    write_char('A');
    write_char('R');
    write_char('M');
    }
}
//0x98

void set_lower_threshold(int upper_val,int lower_val){
    if(shi == upper_val && ge  < lower_val){
    buzzer_watcher = 'x';
    write_char('O');
    write_char('K');
    write_char(' ');
    write_char(' ');
    }
}

