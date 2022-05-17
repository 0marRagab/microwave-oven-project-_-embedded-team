#include "Functions.h"
#include "tm4c123gh6pm.h"
#include "delay.h"
#include "Gpio.h"


unsigned int mod(u32 num, u32 div){	// func to return remainder (modulo)
	while (num >= div){
		num = num - div;
	}
	return num;
}


void RGB_BLINK() {                            // call RGB_BLINK() to blink the RGB array
	GPIO_PORTF_DATA_R ^= 0x0E;
	delay_ms(500);
}


void RGB_FLASH() {                           // call RGB_FlASH() to Flash the RGB array 3 times
	RGB_ON();
	delay_ms(500);
	RGB_OFF();
	delay_ms(500);
        RGB_ON();
	delay_ms(500);
	RGB_OFF();
	delay_ms(500);
	RGB_ON();
	delay_ms(500);
	RGB_OFF();
        delay_ms(500);
}

 //call super_timer to display timer on screen
int super_timer(u8 min,u8 mmin,u8 sec,u8 msec){
	int i;
	if(mmin=='9'){
		min++;
		mmin='0';
	}
	if(min>'3'||(min=='3'&&mmin>'0')||(min=='3'&&mmin=='0'&&sec>'0')||(min=='3'&&mmin=='0'&&sec=='0'&&msec>'0')){
		lcd_setCursor(2,2);
		lcd_print("ErrMax=30:00");
		delay_ms(2000);
	        lcd_clear();
	        lcd_setCursor(6,2);
	        lcd_print("00:00");
	        return 0;
	}
	if(sec>'5'){
		mmin+=1;
		sec='1';
	}
	while(1){
		lcd_setCursor(6,2);
		lcd_string(min,mmin,':',sec,msec);
		delay_ms(1000);
		if (sw1_in()==1) {
			while (sw2_in()==0){
				delay_ms(500); 
				RGB_OFF();
			        delay_ms(1000);
			        RGB_ON();
				delay_ms(1000);
				if(sw1_in() ==1){
					RGB_OFF();
					lcd_clear();
					lcd_print("cooking stoped");
					delay_ms(2000);
					return 0; 
				}
			}
			RGB_ON();
		}
		if(msec!='0'){
			msec--;
		}
		if(msec=='0'&&sec=='1'){
			lcd_setCursor(6,2);
			lcd_string(min,mmin,':',sec,msec);
			delay_ms(1000);
		}
		if(msec=='0'&&sec!='0'){
			msec='9';
			sec--;
			}
		if(msec=='0'&&sec=='0'&&mmin!='0'){
			mmin--;
			sec='5';
			msec='9';
		}
		if(msec=='0'&&sec=='0'&&mmin=='0'&&min!='0'){
			min--;
			mmin='9';
			sec='5';
			msec='9';
		}
		if(msec=='0'&&sec=='0'&&min=='0'&&mmin=='0'){
			lcd_setCursor(6,2);
			lcd_string('0','0',':','0','0');
			 break;
		}
	}
	return 0;
}
