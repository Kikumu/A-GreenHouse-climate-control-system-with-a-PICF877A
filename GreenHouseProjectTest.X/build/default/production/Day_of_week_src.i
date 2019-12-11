# 1 "Day_of_week_src.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Day_of_week_src.c" 2
# 1 "./Day_of_week_driver.h" 1



# 1 "./LCD_driver.h" 1
# 12 "./LCD_driver.h"
void init();
void lcd_init();
void write_char(char x);
void write_cmd(char x);
void delay_lcd();
void delay_screen();
# 4 "./Day_of_week_driver.h" 2


int day_counter;
void display_day(int);
# 1 "Day_of_week_src.c" 2



void display_day(int num){
    if(num == 1 || num == 0){
    write_char('M');
    write_char('o');

    }
    if(num == 2){
    write_char('T');
    write_char('u');

    }
    if(num == 3){
    write_char('W');
    write_char('e');

    }
    if(num == 4){
    write_char('T');
    write_char('h');

    }
    if(num == 5){
    write_char('F');
    write_char('r');

    }
    if(num == 6){
    write_char('S');
    write_char('a');

    }
    if(num == 7){
    write_char('S');
    write_char('u');

    }
}
