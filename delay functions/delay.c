#include "MACROS.h"
#include "Std_INT.h"
#include "delay.h"
#include "Gpio.h

/*                                    ********************************
************************************** ___SysTick_Init() function___  **************************************
                                      ********************************
Initialization of SysTick Timer
*/
void SysTick_Init()
{
NVIC_ST_CTRL_R=0;
NVIC_ST_RELOAD_R=0x00FFFFFF;
NVIC_ST_CURRENT_R=0;
NVIC_ST_CTRL_R=0X5;
}


/*                                    *******************************
************************************** ___delay_onems() function___  **************************************
                                      *******************************
to make delay one millisecond
*/
void delay_onems()	
{
NVIC_ST_CTRL_R=0;                                 // disable timer
NVIC_ST_RELOAD_R=16000-1;                         // 16000 clock means 1 ms because the clock frequency is 16 MHz not 80 MHz
NVIC_ST_CURRENT_R=0;                              // clear counter value
NVIC_ST_CTRL_R=0X5;                               // enable timer to start count
while ((NVIC_ST_CTRL_R & 0X10000)==0){}           // loop untill count bit =1 which mean that timer complete counting
}


/*                                    *******************************
************************************** ___delay_oneus() function___  **************************************
                                      *******************************
to make delay one microsecond
*/
void delay_oneus()
{
NVIC_ST_CTRL_R=0;                                     // disable timer
NVIC_ST_RELOAD_R=16-1;                                // 16 clock means 1 us because the clock frequency is 16 MHz not 80 MHz
NVIC_ST_CURRENT_R=0;                                  // clear counter value 
NVIC_ST_CTRL_R=0X5;                                   // enable timer to start count
while ((NVIC_ST_CTRL_R & 0X10000)==0){}               // loop untill count bit =1 which mean that timer complete counting  
}


/*                                    *****************************
**************************************  ___delay_ms() function___  **************************************
                                      *****************************
call delay_ms(*time*) and send number of milliseconds to delay (wait)
*/
void delay_ms(unsigned int x)                        
{
int i;
   for(i=0 ; i<x ; i++)
   {
    delay_onems();
   }
}


/*                                    ****************************
************************************** ___delay_us() function___  **************************************
                                      ****************************
call delay_us(*time*) and send number of microseconds to delay (wait)
*/
void delay_us(unsigned int y)                       
{
int i;
 for(i=0 ; i<y ; i++)
 {
  delay_oneus();
 }
}
/*                                    ****************************************
************************************** ___delay_Functions_when switches are pressed___ **************************************
                                      ****************************************

int delay_m_s(unsigned int x) { 
int i;
for(i=0 ; i<x ; i++){ 
delay_onems(); 
if ( sw2_in() ==1 | sw1_in() ==1){
return 0;
}
}
return 0;
}


/*                                    ****************************************
************************************** ___delay_portA_interrupt() function___ **************************************
                                      ****************************************
to make cheeking sw3 more guik in interrupt function                                       
*/
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





