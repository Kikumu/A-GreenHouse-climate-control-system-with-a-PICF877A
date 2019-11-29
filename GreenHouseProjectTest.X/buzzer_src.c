#include "Thermometer_driver.h"
#include "Buzzer_driver.h"


void set_beep_threshhold(char x, char y){
    if (shi + '0' == x && ge + '0' == y){
        beep_alert = 1;
        return;
    }
    else{
        beep_alert = 0;
    }
}