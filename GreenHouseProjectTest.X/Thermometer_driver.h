#ifndef THERMOMETER_DRIVER_H
#define THERMOMETER_DRIVER_H

#include <pic.h>
//---------------------DEFINITIONS AND PORTS-----------------------------------
# define uch unsigned char   
# define DQ RE0                              //define 18B20 data PORT                    
# define DQ_DIR TRISE0                       //define 18B20 D PORT direct register       
# define DQ_HIGH() DQ_DIR =1                 //set data PORT INPUT                       
# define DQ_LOW() DQ = 0; DQ_DIR = 0  

//--------------------PARAMETERS-----------------------------------------------
unsigned char  TLV=0 ;                      //temperature high byte                     
unsigned char  THV=0;                       //temperature low byte                      
unsigned char  TZ=0;                         //temperature integer after convert         
unsigned char TX=0;                         //temperature decimal  after convert        
unsigned int wd;                            //temperature BCD code  after convert       
                                                                                         
unsigned char shi;                           //integer ten bit                           
unsigned char ge;                            //integer Entries bit                       
unsigned char shifen;                        //ten cent bit                              
unsigned char baifen;                        //hundred cent bit                          
unsigned char qianfen;                       //thousand cent bit                         
unsigned char wanfen;  

//---------------------FUNCTIONS------------------------------------------------
void init_temp();                            //access and load thermometer
void display_temp();                         //display thermometer to screen
void reset_temp(void);                       //reset temperature
void write_byte(uch val);                    //write characters from thermometer scratch pad
uch  read_byte(void);                        //read characters from thermometer scratch pad
void get_temp();
void delay_temp(char , char );                          //delay so that temperatures can be read  
void delay2();

#endif