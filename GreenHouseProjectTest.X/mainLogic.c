#include "SystemHeader.h"
#include "LCD_driver.h"
#include "Thermometer_driver.h"
#include "clock_driver.h"
#include "Button_driver.h"
#include "Threshold_driver.h"
#include "Buzzer_driver.h"
void main() {
    TRISB=0X02; 
    init_temp(); 
    set_time();
    ds1302_init();
    
    init();                               //I/O init
    lcd_init();                           //LCD init
    init_temp();                          //Initialise temperature variables
    initialise_buttons();                 //Initialise button variables
    
    
    
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
    set_lower_threshold(2,4);
    set_upper_threshold(2,5);
    set_beep_threshhold(buzzer_watcher);
    }
    
}

