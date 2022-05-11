#include "tm4c123gh6pm.h"
#include "Gpio.h"

void PortF_Init(){
	SYSCTL_RCGCGPIO_R |=0x20;                   
	while((SYSCTL_PRGPIO_R&0x20) == 0){}                                
	GPIO_PORTF_LOCK_R= 0x4C4F434B;                                       
        GPIO_PORTF_CR_R=0x1F;                 
	GPIO_PORTF_AFSEL_R=0x00000000;        
	GPIO_PORTF_PCTL_R=0x00000000;          
	GPIO_PORTF_AMSEL_R=0X00000000;        
	GPIO_PORTF_DIR_R=0x0E;                
	GPIO_PORTF_DEN_R=0x1F;               
	GPIO_PORTF_PUR_R=0x11;             
}

int sw1_in() {                                  
  char x = GPIO_PORTF_DATA_R & 0x10;
	
	if(x==0)
               { return(1); }
	
	else
           {return(0);}
}

int sw2_in() {                                  
 char y = GPIO_PORTF_DATA_R & 0x01;
	
	if(y==0) 
		        {return(1);}
		
	else
	        {return(0);}
	}	


void RGB_ON() {                            
	
	GPIO_PORTF_DATA_R |= 0x0E;
}


void RGB_OFF() {                           
	
	GPIO_PORTF_DATA_R &= 0x11;
}

