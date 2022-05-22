#include "MACROS.h"
#include "Std_INT.h"
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
				time_arr[0]='0'; 		// time always be 0x:xx
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
						
		if (u[0]<='9' & u[0]>='1'){		// check weight to be 1:9
                weight=u[0];
                weight = weight - 48;
                lcd_clear();
                lcd_setCursor(5,1);
                lcd_print("Chicken");
                lcd_setCursor(6,2);
                time_arr[3]= mod(weight*2,10) + 48;
                time_arr[2]= mod(weight,5) + 48;
                if(weight < 5){
                    time_arr[1]='0';
                }else{
                    time_arr[1]='1';
                }
                i=0;
		    }else{
                lcd_setCursor(8,2);
                lcd_print("       ");
                lcd_setCursor(8,2);
                lcd_print("Err");
                delay_ms(2000);
            }
				}
					}
					else{
						lcd_setCursor(8,2);
						lcd_print("       ");
						lcd_setCursor(8,2);
						lcd_print("Err");
						delay_ms(2000);
					}
				}
				super_timer(time_arr[0],time_arr[1],time_arr[2],time_arr[3]);
				break;
		}
	}
