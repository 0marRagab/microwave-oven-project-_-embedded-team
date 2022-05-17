#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "delay.h"
#include "keypad.h"
#include "Gpio.h"

unsigned int mod(u32 num, u32 div){		// func to return remainder (modulo)
	while (num >= div){
		num = num - div;
	}
	return num;
}

int main() {
	char key;
	SysTick_Init();
	init_lcd();
	Keypad_Init();
	while(1) {
		key = Keypad_Getkey();	
		switch(key){	
			case 'C':
				while(i){
					lcd_clear();
					lcd_setCursor(1,1);
					lcd_print("Chicken weight?");
					lcd_setCursor(1,2);
					lcd_print("weight:");
					index=0;
					lcd_setCursor(8,2);
					while(sw2_in()==0){
						c = keypad_getkey_caseD();
						delay_ms(200);
						if(c!='z'){
							lcd_write(c);
							u[index]=c;
							index++;
						}
					}
					if (index==1){
						// put Ur code here
					}
					else{
						lcd_setCursor(8,2);
						lcd_print("       ");
						lcd_setCursor(8,2);
						lcd_print("Err");
						delay_ms(2000);
					}
				}
				break;
		}
	}
