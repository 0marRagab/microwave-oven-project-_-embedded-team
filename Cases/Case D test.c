#include "MACROS.h"
#include "Std_INT.h"
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
		switch(key){
			case'D':
				while(1){
					lcd_setCursor(1,1);
					lcd_print("Cooking Time?");
					while(check1(ch)<='9'){
						if(x==1){
							lcd_setCursor(6,2);
						        lcd_string('0','0',':','0',ch[0]);
							q[0]='0',q[1]='0',q[2]='0',q[3]=ch[0];
							}
						else if(x==2){
							lcd_setCursor(6,2);
							lcd_string('0','0',':',ch[0],ch[1]);
							q[0]='0',q[1]='0',q[2]=ch[0],q[3]=ch[1];
						}
						else if(x==3){
							lcd_setCursor(6,2);
							lcd_string('0',ch[0],':',ch[1],ch[2]);
							q[0]='0',q[1]=ch[0],q[2]=ch[1],q[3]=ch[2];
						}
						else if(x==4){
							lcd_setCursor(6,2);
							lcd_string(ch[0],ch[1],':',ch[2],ch[3]);
							x=0;
							q[0]=ch[0],q[1]=ch[1],q[2]=ch[2],q[3]=ch[3];
							ch[0]='0',ch[1]='0',ch[2]='0',ch[3]='0';
						}
						else if(x==5){
							lcd_setCursor(6,2);
							lcd_string('0','0',':','0','0');
						}
						x++;
					}
					lcd_setCursor(6,2);
					super_timer(q[0],q[1],q[2],q[3]);
				}
				break;
		}
	}
}		
