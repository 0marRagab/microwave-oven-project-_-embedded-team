#include "tm4c123gh6pm.h"
#include "Gpio.h"
#include "Keypad.h"
#include "delay.h"
#include "LCD.h"
#include "Std_INT.h"
#include "used_function.h"
#include "functions.h"

int previous_state;
int state;
char y,m,n,z;
char q[4];
char ch[4];
int d; 

void SystemInit(); 


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


int main(){  
	unsigned int x=1;
	unsigned char input;
	unsigned char weight;
	unsigned char time_arr[5];
	char ch[4]={' '};
	char q[4]={' '};
	char temp;
	char c;
	char timer;
	char u[]="0000";
	int index;
	int i=1;
 	state = initial_state;
	PortF_Init();
	PortA_Init();
	init_lcd();
	keypad_Init();
	
	
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
					lcd_clear();
					lcd_print("Error");
					Buzzer_ON();
					delay_ms(1500);
					Buzzer_OFF();
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
					lcd_clear();
					lcd_print("Error");
					Buzzer_ON();
					delay_ms(1500);
					Buzzer_OFF();
					state = choosing_state;
				}
				previous_state = choosing_state;
				break;
				
				
			case done_state:
				lcd_clear();
				lcd_setCursor(1,1);
			  	lcd_print("cooking done");
				Buzzer_ON();
				for( i=0 ; i< 3 ; i++ ){
					RGB_OFF();
					delay_m_s(500);
					RGB_ON();
					delay_m_s(500);
					RGB_OFF();
				}
				Buzzer_OFF();
				lcd_clear();
				state = initial_state;
				break;
				
				
		}
	}
}
