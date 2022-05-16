#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "delay.h"
#include "keypad.h"
#include "Gpio.h"



int main() {
char key;	
SysTick_Init();
init_lcd();
Keypad_Init();
	
	
while(1) {
	
key = Keypad_Getkey();	
	
switch(key)
{	
	
case 'A':
				lcd_clear();
				lcd_setCursor(5,1);                    
				lcd_print("Popcorn");
				delay_ms(2000);
			        lcd_clear();
				lcd_setCursor(1,1);
		                lcd_print ("EN s2 to start");
				while(sw2_in()==0){}
				lcd_clear();
				lcd_setCursor(5,1);                    
				lcd_print("Popcorn");
				lcd_timer("0100");
				break;

	
         }	
    }	
         }
