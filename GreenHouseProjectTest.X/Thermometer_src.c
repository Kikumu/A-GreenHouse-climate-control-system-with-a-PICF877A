#include "Thermometer_driver.h"
#include "LCD_driver.h"
#include "Buzzer_driver.h"

void init_temp()                            //access and load thermometer
{
    TRISE=0X00;                                 //set A PORT direct OUTPUT 
    PORTE = 0X00;
 // TRISD=0X00;                                 //set D PORT direct OUTPUT      
}
void display_temp()                           //display thermometer to screen
{
 write_char(shi + '0');                       //display integer ten bit                                                                                
// delay_temp(10,70);                                                                           
 write_char(ge + '0');                        //display integer Entries bit and decimal dot    
 write_char('.');                                                                       
 //delay_temp(10,70);                                                                          
 write_char(shifen + '0');                    //display decimal ten cent bit                                                                              
 //delay_temp(10,70);                                                                          
 write_char(baifen + '0');                    //display decimal hundred cent bit               
                                                                        
 //delay_temp(10,70);
 
}
void reset_temp(void)                         //reset temperature
{
  char presence=1;
  while(presence)
  { 
    DQ_LOW() ;                                //MAIN MCU PULL LOW                                                                       
    delay_temp(2,70);                         //delay 503us                                                                             
    DQ_HIGH();                                //release general line and wait for resistance pull high general line and keep 15~60us    
    delay_temp(2,8);                          //delay 70us                                                                              
    if(DQ==1) presence=1;                     // not receive responsion signal,continue reset                                           
    else presence=0;                          //receive responsion signal                                                               
    delay_temp(2,60);                         //delay 430us                                                                             
   }
}

void write_byte(uch val)                      //write characters from thermometer scratch pad
{
 uch i;
 uch temp;
 for(i=8;i>0;i--)
 {
   temp=val&0x01;                             //shift the lowest bit                   
   DQ_LOW();                                                                           
   NOP();                                                                              
   NOP();                                                                              
   NOP();                                                                              
   NOP();                                                                              
   NOP();                                     //pull high to low,produce write time    
   if(temp==1)  DQ_HIGH();                    //if write 1,pull high                   
   delay_temp(2,7);                                //delay 63us                             
   DQ_HIGH();                                                                          
   NOP();                                                                              
   NOP();                                                                              
   val=val>>1;                                //right shift a bit                      
  }
}

uch  read_byte(void)                        //read characters from thermometer scratch pad
{
 uch i;
 uch value=0;                                 //read temperature         
 static _Bool j;
 for(i=8;i>0;i--)
 {
   value>>=1; 
   DQ_LOW();
   NOP();
   NOP();
   NOP();
   NOP();
   NOP();
   NOP();                                    //6us              
   DQ_HIGH();                                // pull high       
   NOP();                                                       
   NOP();                                                       
   NOP();                                                       
   NOP();                                                       
   NOP();                                   //4us               
   j=DQ;                                                        
   if(j) value|=0x80;                                           
   delay_temp(2,7);                              //63us              
  }
  return(value);
}
void get_temp()
{
int i;
DQ_HIGH();
reset_temp();                              //reset,wait for  18b20 responsion                                                                                                               
write_byte(0XCC);                     //ignore ROM matching  
delay2();
write_byte(0X44);                     //send  temperature convert command                                                                                                              
                                                                                                                                                                                
reset_temp();                              //reset again,wait for 18b20 responsion                                                                                                          
write_byte(0XCC);                     //ignore ROM matching                                                                                                                            
write_byte(0XBE);                     //send read temperature command                                                                                                                  
TLV=read_byte();                      //read temperature low byte                                                                                                                      
THV=read_byte();                      //read temperature high byte                                                                                                                     
DQ_HIGH();                            //release general line                                                                                                                           
TZ=(TLV>>4)|(THV<<4)&0X3f;            //temperature integer                                                                                                                            
TX=TLV<<4;                            //temperature decimal                                                                                                                            
if(TZ>100) TZ/100;                    //not display hundred bit                                                                                                                        
ge=TZ%10;                     //integer Entries bit                                                                                                                            
shi=TZ/10;                    //integer ten bit                                                                                                                                
wd=0;                                                                                                                                                                                  
if (TX & 0x80) wd=wd+5000;
if (TX & 0x40) wd=wd+2500;
if (TX & 0x20) wd=wd+1250;
if (TX & 0x10) wd=wd+625;                //hereinbefore four instructions are turn  decimal into BCD code                         
shifen=wd/1000;                          //ten cent bit                                                                           
baifen=(wd%1000)/100;                    //hundred cent bit                                                                       
qianfen=(wd%100)/10;                     //thousand cent bit                                                                      
wanfen=wd%10;                            //myriad cent bit                                                                        
NOP();                                            
}

void delay_temp(char x, char y)                          //delay so that temperatures can be read  
{
 char z;
 do{
 z=y;
 do{;}while(--z);
 }while(--x);
}

void delay2(){
 for (int i = 0; i<50;i++){
 }
}