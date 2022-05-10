#include "tm4c123gh6pm.h"
#include "Gpio.h"


void PortA_Init(){
	SYSCTL_RCGCGPIO_R |=0x01;                          
	while((SYSCTL_PRGPIO_R&0x01) == 0){}                                
        GPIO_PORTA_CR_R=0x18;                         
	GPIO_PORTA_AFSEL_R=0x00000000;                  
	GPIO_PORTA_PCTL_R=0x00000000;                
	GPIO_PORTA_AMSEL_R=0X00000000;                
	GPIO_PORTA_DIR_R=0x08;                            
	GPIO_PORTA_DEN_R=0xFF;                      
	GPIO_PORTA_PUR_R=0x00000000;               
}


void RGB_ON() {                            
	
	GPIO_PORTF_DATA_R |= 0x0E;
}


void RGB_OFF() {                           
	
	GPIO_PORTF_DATA_R &= 0x11;
}

