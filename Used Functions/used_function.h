#ifndef used_function_H
#define used_function_H
#include "Std_INT.h"
#include "Gpio.h"
#include "delay.h"


extern char O[4];
extern char y,m,n,z;
extern char temp;
extern char O[4]; 
extern char y,m,n,z;
extern char temp;
extern unsigned int x;
extern unsigned char input;
extern unsigned char weight;
extern unsigned char time_arr[5];
extern char c;
extern char timer;
extern char u[];
extern int index;
extern int i;
extern int d; 
extern int previous_state;
extern int state;
extern state ;



enum states { initial_state = 1 , choosing_state , popcorn_state, beef_state, chicken_state, setTime_state, cooking_state, pause_state, stop_state, done_state } ;


//to stop the code blinking and turn on the buzzer when sw_3 == 1(door is open) 
void GPIOA_Handler(void);


//call super_timer to display timer on screen
int super_timer(u8 min,u8 mmin,u8 sec,u8 msec);
                         

// call RGB_BLINK() to blink the RGB array
void RGB_BLINK();                           
  

// call RGB_FlASH() to Flash the RGB array 3 times
void RGB_FLASH();    


//to print error msg if unexpected button is pressed
void Error_msg1();


//to print error msg if unexpected button is pressed
void Error_msg2();


//func to return remainder (modulo)
unsigned int mod(u32 num, u32 div);


#endif


