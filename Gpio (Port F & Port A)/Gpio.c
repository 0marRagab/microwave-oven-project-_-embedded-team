#include "tm4c123gh6pm.h"
#include "Gpio.h"

// Initialization of Port F
void PortF_Init(){
	SYSCTL_RCGCGPIO_R |=0x20;                    //Activate the Clock on PortF
	while((SYSCTL_PRGPIO_R&0x20) == 0){}        //Wait until the Clock is Activated                            
	GPIO_PORTF_LOCK_R= 0x4C4F434B;             //Unlock PortF                             
        GPIO_PORTF_CR_R=0x1F;                     //enable control on PF0-PF4   (Allow Changes)
	GPIO_PORTF_AFSEL_R=0x00000000;           //Disable Alternate Function on Port F  
	GPIO_PORTF_PCTL_R=0x00000000;           //All Pins in PortF are GPIO
	GPIO_PORTF_AMSEL_R=0X00000000;         //All pins are digital only so disable the AMSEL Register 
	GPIO_PORTF_DIR_R=0x0E;                //PF0,PF4 inputs, PF1-PF3 output
	GPIO_PORTF_DEN_R=0x1F;               //All pins are digital only
	GPIO_PORTF_PUR_R=0x11;              //Enable Pull Up Resistor on PF0 and PF4
}


// Initialization of Port A
void PortA_Init(){
	SYSCTL_RCGCGPIO_R |=0x01;                          //Activate the Clock on PortA
	while((SYSCTL_PRGPIO_R&0x01) == 0){}              //Wait until the Clock is Activated                        
        GPIO_PORTA_CR_R=0x18;                            //enable control on PA3, PA4   (Allow Changes)
	GPIO_PORTA_AFSEL_R=0x00000000;                  //Disable Alternate Function on Port A
	GPIO_PORTA_PCTL_R=0x00000000;                  //All Pins in PortA are GPIO
	GPIO_PORTA_AMSEL_R=0X00000000;                //All pins are digital so disable the AMSEL Register   
	GPIO_PORTA_DIR_R=0x08;                       //PA4 input (Switch) , PA3 output (Buzzer)          
	GPIO_PORTA_DEN_R=0xFF;                      //All pins are digital only
	GPIO_PORTA_PUR_R=0x00000000;               //Disable Pull Up Resistor since the external switch will be connected to external pull up resistor  
}



int sw1_in() {                                  // This function returns 1 if sw1 is pressed and returns 0 if not pressed
  char x = GPIO_PORTF_DATA_R & 0x10;
	
	if(x==0)
               { return(1); }
	
	else
           {return(0);}
}	


	
	
int sw2_in() {                                  // This function returns 1 if sw2 is pressed and returns 0 if not pressed
 char y = GPIO_PORTF_DATA_R & 0x01;
	
	if(y==0) 
		        {return(1);}
		
	else
	        {return(0);}
	}	
	
int sw3_in() {                                // This function returns 1 if sw3 is pressed and returns 0 if not pressed
 char z = GPIO_PORTA_DATA_R & 0x10;
	
	if(z==0) 
	        {return(1);}
		
	else
	    {return(0);}
	}

	
void Buzzer_ON(){                              // call Buzzer_ON() to turn on the buzzer
	
GPIO_PORTA_DATA_R |= 0x08;
}	

void Buzzer_OFF(){                          // call Buzzer_OFF() to turn off the buzzer
	
GPIO_PORTA_DATA_R &= 0xB7;
}	

void RGB_ON() {                            // call RGB_ON() to turn on the RGB array
	
	GPIO_PORTF_DATA_R |= 0x0E;
}

void RGB_OFF() {                           // call RGB_OFF() to turn of the RGB array
	
	GPIO_PORTF_DATA_R &= 0x11;
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


