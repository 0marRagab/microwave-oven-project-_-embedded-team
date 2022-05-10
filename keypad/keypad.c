#include "tm4c123gh6pm.h"
#include "keypad.h"
#include "Std_INT.h"
#include "delay.h"

// adding array of charachter in keypad
u8 symbol[N_row][N_col] = {{ '1', '2',  '3', 'A'},      // row 1
                           { '4', '5',  '6', 'B'},      // row 2
                           { '7', '8',  '9', 'C'},      // row 3
                           { '*', '0',  '#', 'D'}};     // row 4


// Keypad_Init() configures PORTC and PORTA to scan keypad keys
void Keypad_Init(void)
{
  SYSCTL_RCGCGPIO_R |= 0x00000005;        //Enable clock for PORTA and PORTC  
  while ((SYSCTL_PRGPIO_R&0x05) == 0){};  //Wait for clock to be setted
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
  GPIO_PORTC_CR_R |= 0xF0;             //Allow settings for pins (4,5,6,7) of PORTC
  GPIO_PORTA_CR_R |= 0x3C;             //Allow settings for pins (2,3,4,5) of PORTA
	GPIO_PORTC_DIR_R |= 0xF0;             //PC4-PC7 are used with col and set them as digital output pins
  GPIO_PORTA_DIR_R = 0x00;             //PA2-PA5 are used with row and set them as digital input pins
  GPIO_PORTA_PDR_R = 0x3C;             //Enable pull down resistor on PORTA for rows
  GPIO_PORTC_DEN_R |= 0xF0;
  GPIO_PORTA_DEN_R = 0x3C;
	GPIO_PORTA_AMSEL_R = 0x00;
	GPIO_PORTA_AFSEL_R = 0x00;
	GPIO_PORTA_PCTL_R = 0x00000000;
}

