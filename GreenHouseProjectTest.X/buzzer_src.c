#include "Thermometer_driver.h"
#include "Buzzer_driver.h"
#include "Button_driver.h"

void set_beep_threshhold(char x){
    if (x == 'w'){ //warn beep
        beep_alert = 1;
        button_delay();
        beep_alert = 0;
        button_delay();
        beep_alert = 1;
        button_delay();
        beep_alert = 0;
        return;
    }
    else{
        beep_alert = 0;
    }
}