#include "Thermometer_driver.h"
#include "Buzzer_driver.h"


void set_beep_threshhold(char x){
    if (shi + '0' == x){
        beep_alert = 1;
    }
    else{
        beep_alert = 0;
    }
}