#include "MACROS.h"
#include "Gpio.h"
#include "Keypad.h"
#include "delay.h"
#include "LCD.h"
#include "Std_INT.h"
#include "used_function.h"


void SystemInit(); 


/*                                    ************************************
**************************************   ___GPIOA_Handler() function___   **************************************
                                      ************************************
to stop the code blinking and turn on the buzzer when sw_3 == 1(door is open) 
*/
void GPIOA_Handler(void){
	GPIO_PORTA_ICR_R |= 0x10; // acknowledge flag4 of pin 4
	RGB_OFF();
	Buzzer_ON();
	while(sw3_in()==1){
		leds_ON();
		delay_portA_interrupt(1000);
		leds_OFF();
		delay_portA_interrupt(1000);
	}
	Buzzer_OFF();
} 

/*                                    ************************************
**************************************   ___Main Function___   **************************************
                                      ************************************
*/


int main(){  
	unsigned int x=1;
	unsigned char input;
	unsigned char weight;
	unsigned char time_arr[5];
	char c;
	char timer;
	char u[]="0000";
 	int d; 
	int index;
	int i=1;
	int previous_state;
	int state;
 	state = initial_state;
	PortA_Init();
	init_lcd();
	keypad_Init();
	SysTick_Init();
	
	while(1){
		switch(state){	
			case initial_state:
				lcd_clear();
			   	lcd_print("Enter * to start");
				input = keypad_getkey();
				if(input == '*'){
					previous_state = initial_state;
					state = choosing_state; 
					break;
				}
				else{
					Error_msg1();
					state = initial_state;
				}
				break;
				
				
			case choosing_state:
				lcd_clear();
			 	lcd_print("En your choice");
		  		input = keypad_getkey();
			  	if(input == 'A'){
					state = popcorn_state;
				}
				else if(input == 'B'){
					state = beef_state;
				}
				else if(input == 'C'){
					state = chicken_state;
				}
				else if(input == 'D'){
					state = setTime_state;
				}
				else{
					Error_msg1();
					state = choosing_state;
				}
				previous_state = choosing_state;
				break;
				
				
			case popcorn_state:
				lcd_clear();
				lcd_setCursor(5,1);                    
				lcd_print("Popcorn");
				lcd_setCursor(2,2);
		  		lcd_print ("EN s2 to start");
				while(sw2_in()==0){}
				previous_state = popcorn_state;
				state = cooking_state;
				break;
				
				
			case beef_state:
				time_arr[0]='0'; time_arr[3]='0'; 		// time always be 0x:x0 
				while(i){
					lcd_clear();
					lcd_setCursor(1,1);
					lcd_print("Beef weight?");
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
					i=0 ; 	
					previous_state = beef_state;
					state = cooking_state;
				}
				break;
			
			
			case chicken_state:
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
					i = 0;
					previous_state = chicken_state;
					state = cooking_state;
				}
				break;
				
				
			case setTime_state:
				while(i){
					lcd_clear();
					u[0]='0';u[1]='0';u[2]='0';u[3]='0';
					lcd_setCursor(1,1);
					lcd_print("cooking time?");
					lcd_setCursor(6,2);
					lcd_string('0','0',':','0','0');
					y = u[0];
					m = u[1];
					n = u[2];
					z = u[3];
					while (sw2_in()==0){
						temp =keypad_getkey_caseD();
						index = num_input(temp);
						if (sw1_in()== 1 ){
							y='0';m='0';n='0';z='0';
							lcd_setCursor(6,2);
							lcd_string(y,m,':',n,z);
						}
						if (index ==1){
							fetch_input();
						}
						else if (index==2){
							fetch_input();
						}
						else if (index==3){
							fetch_input();
						}
						else if (index==4){
							fetch_input();
						}
					}
					i = 0;
					previous_state = setTime_state;
					state = cooking_state;
				}
					break;
				
				
			case cooking_state:
				i=1;
				
				if( previous_state == popcorn_state ){
					lcd_clear();
					lcd_setCursor(5,1);    					// call lcd_goto(col,row) to set cursor at specific location
					lcd_print("Popcorn");
					d = super_timer('0','1','0','0');
				}
				
				else if( previous_state == beef_state ){
					if (index==1){
						if (u[0]<='9' && u[0]>='1'){		// check weight to be 1:9
							weight=u[0];
							weight = weight - 48;
							lcd_clear();
							lcd_setCursor(7,1);
							lcd_print("Beef");
							if(mod(weight,2) == 0){
								time_arr[1]= (weight / 2) + 48;
								time_arr[2]='0';
							}
							else{
								time_arr[1]= ((weight - 1) / 2) + 48;
								time_arr[2]='3';
							}
						}
						else{
							Error_msg2();
							i = 1;
              						previous_state= cooking_state;
							state = beef_state;
						  break;
						}
					}
					else{
						Error_msg2();
						i = 1;
						previous_state= cooking_state;
						state = beef_state;
					  break;				
					}
					d = super_timer(time_arr[0],time_arr[1],time_arr[2],time_arr[3]);
					
				}
				
				else if( previous_state == chicken_state ){
					if (index==1){
						if (u[0]<='9' && u[0]>='1'){       // check weight to be 1:9
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
							}
							else{
								time_arr[1]='1';
							}
						}
						else{
							Error_msg2();
							i=1;
							previous_state = cooking_state;
							state = chicken_state;
							break;
						}
					}
					else{
						Error_msg2();
						i=1;
						previous_state = cooking_state;
						state = chicken_state;
						break;
					}
					d = super_timer(time_arr[0],time_arr[1],time_arr[2],time_arr[3]);
				}
				
				else if( previous_state == setTime_state){
					u[0]=y;
					u[1]=m;
					u[2]=n;
				  	u[3]=z;
					lcd_setCursor(6,2);
	        			d = super_timer(u[0],u[1],u[2],u[3]);
					if(d == 0 ){
						i = 1;
						state = setTime_state;
						break;
					}
					else if(d == 1){}
				}
				
				else if(previous_state == pause_state){
					u[0]=O[0];
					u[1]=O[1];
				  	u[2]=O[2];
				  	u[3]=O[3];
					lcd_setCursor(6,2);
	        			d = super_timer(u[0],u[1],u[2],u[3]);
				}
				if(d == 2){
					i = 1;
					state = pause_state;
					break;
				}
				previous_state = cooking_state;
				state = done_state;
				break;
				
				
			case pause_state:
				i = 1;
				while(i){
					RGB_BLINK();
					if(sw1_in() ==1){
						i=0;
						state = stop_state;
					}
					else if(sw2_in() == 1){
						i=1;
				  		previous_state = pause_state;
				  		state = cooking_state;
				  		break;
					}
				}
				break;
			
			
			case stop_state:
				RGB_OFF();
				lcd_clear();
				lcd_print("cooking stoped");
				delay_ms(1500);
				lcd_clear();
			        i =1;	
			        state = initial_state;
			    break;	
				
				
			case done_state:
				lcd_clear();
				lcd_setCursor(1,1);
			  	lcd_print("cooking done");
				Buzzer_ON();
				RGB_FLASH();
				Buzzer_OFF();
				lcd_clear();
				state = initial_state;
				break;		
		}
	}
}
