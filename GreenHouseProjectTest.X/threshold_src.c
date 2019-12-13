#include "Threshold_driver.h"


char set_upper_threshold(int upper_val,int lower_val){
    if(shi >=  upper_val && ge  >= lower_val ){
    heat_counter ++;
    heater_state = '0';
    cooler_state = '1';
    write_char('W');
    write_char('A');
    write_char('R');
    write_char('M');
    if(heat_counter > 100){
        cooler_state = '-';
        if(count == 2)
        buzzer_watcher = 'w';
    }
    }
    return buzzer_watcher;
}

char cold_threshold(int upper_val,int lower_val){
     if(shi <=  upper_val && (ge  <= lower_val  || ge >= lower_val)){
    cold_counter ++;
    heater_state = '1';
    cooler_state = '0';
    write_char('C');
    write_char('O');
    write_char('L');
    write_char('D');
    if(cold_counter > 1000){
        heater_state = '-';
        if(count == 2)
        buzzer_watcher = 'w';
    }
    }
    return buzzer_watcher;
}


char set_lower_threshold(int upper_val,int lower_val){
    if((shi <= upper_val && ge  <= lower_val))
    {
    count = 2;
    buzzer_watcher = 'x'; //silence sounder
    heater_state = '0';
    cooler_state = '0';
    heat_counter = 0;
    cold_counter = 0;
    write_char('O');
    write_char('K');
    write_char(' ');
    write_char(' ');
    }
    return buzzer_watcher;
}
//needs to be persistant
char reset_alarm(){
    RC0 = 1;
    RC1 = 1;
    RC2 = 1;
    RC3 = 0;
    if(RC4 == 0){
        count = 0;
        buzzer_watcher = 'x';
        heat_counter = 0;
        write_char('R');
        write_char('E');
        write_char('S');
        write_char('E');
        write_char('T');
    }
    return buzzer_watcher;
}

