#include "io.h"
#include "LCD.h"
#include "delay.h"

//initilization port B for data
void PortB_Init(void)
{ 
SYSCTL_RCGCGPIO_R |= 0x02;                //Activate the Clock on port B
while ((SYSCTL_PRGPIO_R & 0x02) == 0){}; //waiting to until the clock is activated
GPIO_PORTB_LOCK_R = 0x4C4F434B;         //Unlocking of port B
GPIO_PORTB_CR_R |= 0xFF;               //to allow change in pin0--->pin7 in port B 
GPIO_PORTB_DIR_R |= 0xFF;             //make pin0--->pin7 in port B as output
GPIO_PORTB_DEN_R |= 0xFF;            //make pin0--->pin7 in port B as digital Pins 
GPIO_PORTB_AMSEL_R &= 0;            //Disable analog signal register
GPIO_PORTB_AFSEL_R &= 0;           //Disable alternate function register
GPIO_PORTB_PCTL_R &= 0;           //make all pins as GPIO pins
GPIO_PORTB_PUR_R = 0x00;         //disable pull up register
}

// initilization port D for en,rs,rw
void PortD_Init(void)
{ 
SYSCTL_RCGCGPIO_R |= 0x08;                        //Activate the Clock on port D
while ((SYSCTL_PRGPIO_R&0x08) == 0){};           //waiting to make change in port D
GPIO_PORTD_LOCK_R = 0x4C4F434B;                 //Unlocking of port D
GPIO_PORTD_CR_R |= 0xFF;                       //to allow change in pin0--->pin7 in port D
GPIO_PORTD_DIR_R |= 0xFF;                     //make pin0--->pin7 in port D as output
GPIO_PORTD_DEN_R |= 0xFF;                    //make pin0--->pin7 in port D as digital Pins
GPIO_PORTD_AMSEL_R &= 0x00;                 //Disable analog signal register
GPIO_PORTD_AFSEL_R &= 0x00;                //disable alternate function register on port D
GPIO_PORTD_PCTL_R &= 0x00;                //make pin0--->pin7 in port D as GPIO
GPIO_PORTD_PUR_R = 0x00;                 //disable pull up register
}
