#include "tm4c123gh6pm.h"
#include "Gpio.h"

// Initialization of Port F
void PortF_Init(){
	SYSCTL_RCGCGPIO_R |=0x20;                      //Activate the Clock on PortF
	while((SYSCTL_PRGPIO_R&0x20) == 0){}          //Wait until the Clock is Activated                            
	GPIO_PORTF_LOCK_R  = 0x4C4F434B;             //Unlock PortF                             
        GPIO_PORTF_CR_R    =0x1F;                   //enable control on PF0-PF4   (Allow Changes)
	GPIO_PORTF_AFSEL_R =0x00000000;            //Disable Alternate Function on Port F  
	GPIO_PORTF_PCTL_R  =0x00000000;           //All Pins in PortF are GPIO
	GPIO_PORTF_AMSEL_R =0X00000000;          //All pins are digital only so disable the AMSEL Register 
	GPIO_PORTF_DIR_R   =0x0E;               //PF0,PF4 inputs, PF1-PF3 output
	GPIO_PORTF_DEN_R   =0x1F;              //All pins are digital only
	GPIO_PORTF_PUR_R   =0x11;             //Enable Pull Up Resistor on PF0 and PF4
}


// Initialization of Port A
void PortA_Init(){
	SYSCTL_RCGCGPIO_R |=0x01;                            //Activate the Clock on PortA
	while((SYSCTL_PRGPIO_R&0x01) == 0){}                //Wait until the Clock is Activated                        
        GPIO_PORTA_CR_R    =0x1C;                          //enable control on PA2, PA3, PA4   (Allow Changes)
	GPIO_PORTA_AFSEL_R =0x00000000;                   //Disable Alternate Function on Port A
	GPIO_PORTA_PCTL_R  =0x00000000;                  //All Pins in PortA are GPIO
	GPIO_PORTA_AMSEL_R =0X00000000;                 //All pins are digital so disable the AMSEL Register   
	GPIO_PORTA_DIR_R   =0x0C;                      //PA4 input (Switch) , PA3 output (Buzzer) , PA2 output (red led)         
	GPIO_PORTA_DEN_R   =0xFF;                     //All pins are digital only
	GPIO_PORTA_PUR_R   =0x00000000;              //Disable Pull Up Resistor since the external switch will be connected to external pull up resistor
	GPIO_PORTA_IS_R    &= ~(0x10);              // PA4 is low level event
        GPIO_PORTA_IEV_R   &= ~(0x00);             // PA4 level event
        GPIO_PORTA_ICR_R   = 0x10;                // clear flag4
        GPIO_PORTA_IM_R   |= 0x10;               // arm interrupt on PA4	
        NVIC_PRI0_R = ((NVIC_PRI0_R&0xFF00FFFF)|0x00000000 );         // priority 5 of port f 
        NVIC_EN0_R        = 0x00000001;        //  enable interrupt of port A
        __enable_irq();                       // Enable global Interrupt 
}


 // This function returns 1 if sw1 is pressed and returns 0 if not pressed
int sw1_in()
{                                 
  char x = GPIO_PORTF_DATA_R & 0x10;
    if(x==0)
    { 
      return(1); 
    }
    else
    {
      return(0);
    }
}	

// This function returns 1 if sw2 is pressed and returns 0 if not pressed
int sw2_in()
{                                  
 char y = GPIO_PORTF_DATA_R & 0x01;
  if(y==0) 
    { 
     return(1);
    }
  else
  {
  return(0);
  }
}

// This function returns 1 if sw3 is pressed and returns 0 if not pressed	
int sw3_in()
{                                
 char z = GPIO_PORTA_DATA_R & 0x10;
  if(z==0) 
  {
   return(1);
  }
  else
  {
   return(0);
  }
}

  // call Buzzer_ON() to turn on the buzzer	
void Buzzer_ON()
{                            	
GPIO_PORTA_DATA_R |= 0x08;
}	

 // call Buzzer_OFF() to turn off the buzzer
void Buzzer_OFF()
{                       	
GPIO_PORTA_DATA_R &= 0xB7;
}

 // call RGB_ON() to turn on the RGB array
void RGB_ON() 
{                           
GPIO_PORTF_DATA_R |= 0x0E;
}

// call RGB_OFF() to turn of the RGB array
void RGB_OFF() 
{                           
GPIO_PORTF_DATA_R &= 0x11;
}

// call Red_ON() to turn on the external red led
void Red_ON()
{                              	
GPIO_PORTA_DATA_R |= 0x04;
}

 // call Red_OFF() to turn off the external red led
void Red_OFF()
{                         
GPIO_PORTA_DATA_R &= 0xFB;
}


