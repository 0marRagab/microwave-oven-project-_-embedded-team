#include "Functions.h"
#include "tm4c123gh6pm.h"
#include "delay.h"
#include "Gpio.h"


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