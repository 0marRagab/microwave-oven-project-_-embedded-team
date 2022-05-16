
#include "tm4c123gh6pm.h"
#include "Gpio.h"
#include "delay.h"
#include "LCD.h"




int main(){
	
	PortF_Init();
	init_lcd();      
	
	while(1){
	
	lcd_clear();
	lcd_setCursor(8,2);
	lcd_print("Welcome");
	delay_ms(1000);
	//lcd_clear();	
	lcd_setCursor(8,1);
	lcd_print("Omar");
	delay_ms(2000);
	lcd_clear();
	lcd_setCursor(2,1);
	lcd_print("Good Night");
	delay_ms(3000);	
	}
	
}
