#include "SystemHeader.h"
#include "LCD_driver.h"
#include "Thermometer_driver.h"
#include "clock_driver.h"
#include "Button_driver.h"
#include "Threshold_driver.h"
#include "Buzzer_driver.h"
#include "Day_of_week_driver.h"
#include "math_driver.h"
void main() {
    TRISB=0X02; 
    init_temp(); 
    set_time();
    ds1302_init();
    
    init();                               //I/O init
    lcd_init();                           //LCD init
    init_temp();                          //Initialise temperature variables
    initialise_buttons();                 //Initialise button variables
    var1 = 3;
    var2 = 4;
    var_night_low = 4;
    var_night_high = 2;
    
    
    while(1){
    get_temp();                           //get temperature variables from device
    get_time();                           //get time variables from hardware
    write_cmd(0x80);
    write_char('T');
    write_char('e');
    write_char('m');
    write_char('p');
    write_char(':');
    display_temp();                       //Display tempperature to screen
    
    write_cmd(0x90);
    write_char('D');
    write_char('a');
    write_char('t');
    write_char('e');
    write_char(':');
    write_char(' ');
    
    display_date();                      //Display date to screen
    
    write_cmd(0x88);
    write_char('T');
    write_char('i');
    write_char('m');
    write_char('e');
    write_char(':');
    display_clock();                     //Display clock settings
    thermometer_threshhold_settings();   //access thermometer settings
    date_settings();                     //access date settings
    time_settings();                     //access time settings
    write_cmd(0x98);
    //day_threshhold
     if((temp_high+'0')<= 1 && (temp_low + '0') < 8){
    alarm__ = set_lower_threshold(var1,var2);
    alarm__ = set_upper_threshold(var1,var2);
    }
    //night_threshhold
    if((temp_high+'0') >= 1 && (temp_low + '0') >= 8){
    alarm__ = set_lower_threshold(var_night_high,var_night_low);
    alarm__ = set_upper_threshold(var_night_high,var_night_low);
    }
    alarm__ = reset_alarm();
    set_beep_threshhold(alarm__);
    write_char(' ');
    write_char('H');
    write_char(':');
    write_char(heater_state);
    write_char('C');
    write_char(':');
    write_char(cooler_state);
    for(int i = 0; i < 3; i++)
    write_char(' ');
    day_counter = modulus_func(day_low,8);
    display_day(day_counter);
}
}
