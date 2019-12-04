#include "Day_of_week_driver.h"


void display_day(int num){
    if(num == 1 || num == 0){
    write_char('M');
    write_char('o');
    write_char('n');
    }
    if(num == 2){
    write_char('T');
    write_char('u');
    write_char('e');
    }
    if(num == 3){
    write_char('W');
    write_char('e');
    write_char('d');
    }
    if(num == 4){
    write_char('T');
    write_char('h');
    write_char('u');   
    }
    if(num == 5){
    write_char('F');
    write_char('r');
    write_char('i'); 
    }
    if(num == 6){
    write_char('S');
    write_char('a');
    write_char('t');
    }
    if(num == 7){
    write_char('S');
    write_char('u');
    write_char('n');
    }
}