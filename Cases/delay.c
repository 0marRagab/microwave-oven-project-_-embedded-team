#include "tm4c123gh6pm.h"
#include "delay.h"

// Initialization of SysTick Timer
void SysTick_Init()
{
NVIC_ST_CTRL_R=0;
NVIC_ST_RELOAD_R=0x00FFFFFF;
NVIC_ST_CURRENT_R=0;
NVIC_ST_CTRL_R=0X5;
}


//to make delay one millisecond
void delay_onems()	
{
NVIC_ST_CTRL_R=0;                                 // disable timer
NVIC_ST_RELOAD_R=16000-1;                         // 16000 clock means 1 ms because the clock frequency is 16 MHz not 80 MHz
NVIC_ST_CURRENT_R=0;                              // clear counter value
NVIC_ST_CTRL_R=0X5;                               // enable timer to start count
while ((NVIC_ST_CTRL_R & 0X10000)==0){}           // loop untill count bit =1 which mean that timer complete counting
}

//to make delay one microsecond
void delay_oneus()
{
NVIC_ST_CTRL_R=0;                                     // disable timer
NVIC_ST_RELOAD_R=16-1;                                // 16 clock means 1 us because the clock frequency is 16 MHz not 80 MHz
NVIC_ST_CURRENT_R=0;                                  // clear counter value 
NVIC_ST_CTRL_R=0X5;                                   // enable timer to start count
while ((NVIC_ST_CTRL_R & 0X10000)==0){}               // loop untill count bit =1 which mean that timer complete counting  
}

// call delay_ms(*time*) and send number of milliseconds to delay (wait)
void delay_ms(unsigned int x)                        
{
    int i;
for(i=0 ; i<x ; i++)
{
   delay_onems();
                   }
}


// call delay_us(*time*) and send number of microseconds to delay (wait)
void delay_us(unsigned int y)                       
{
   int i;
for(i=0 ; i<y ; i++)
{
  delay_oneus();
                  }
}


int delay_portA_interrupt(unsigned int x) { 
int i;
for(i=0 ; i<x ; i++){ 
delay_onems(); 
if ( sw3_in() ==0){
return 0;
}
}
return 0;
}













