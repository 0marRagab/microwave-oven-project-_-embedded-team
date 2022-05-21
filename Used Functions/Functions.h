#ifndef Functions_H
#define Functions_H
#include "Std_INT.h"
#include "Gpio.h"
#include "delay.h"


// call RGB_BLINK() to blink the RGB array
void RGB_BLINK();                           
  
  
// call RGB_FlASH() to Flash the RGB array 3 times
void RGB_FLASH();    

enum states { initial_state = 1 , choosing_state , popcorn_state, beef_state, chicken_state, setTime_state, cooking_state, puase_state, stop_state, done_state } ;
int super_timer(u8 min,u8 mmin,u8 sec,u8 msec);
                         

#endif


