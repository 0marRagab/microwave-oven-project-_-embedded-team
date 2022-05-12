#include "tm4c123gh6pm.h"
#include "Gpio.h"

// Initialization of Port F
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

// Initialization of Port D
void PortD_Init(){
	SYSCTL_RCGCGPIO_R |=0x08;                   
	while((SYSCTL_PRGPIO_R&0x08) == 0){}                                
	GPIO_PORTF_LOCK_R= 0x4C4F434B;                                       
        GPIO_PORTF_CR_R=0xFF;                 
	GPIO_PORTF_AFSEL_R=0x00000000;        
	GPIO_PORTF_PCTL_R=0x00000000;          
	GPIO_PORTF_AMSEL_R=0X00000000;        
	GPIO_PORTF_DIR_R=0x20;                
	GPIO_PORTF_DEN_R=0xFF;               
	GPIO_PORTF_PUR_R=0x40;             
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

int sw3_in() {                                
 char z = GPIO_PORTD_DATA_R & 0x80;
	
	if(z==0) 
	        {return(1);}
		
	else
	    {return(0);}
	}

void Buzzer_ON(){
	GPIO_PORTD_DATA_R |=0x40;
}

void Buzzer_OFF(){                         
	
        GPIO_PORTD_DATA_R &= 0xBF;
}


void RGB_ON() {                            
	
	GPIO_PORTF_DATA_R |= 0x0E;
}


void RGB_OFF() {                           
	
	GPIO_PORTF_DATA_R &= 0x11;
}

