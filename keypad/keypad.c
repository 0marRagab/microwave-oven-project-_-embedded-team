#include "tm4c123gh6pm.h"
#include "keypad.h"
#include "Std_INT.h"
#include "delay.h"

// adding array of charachter in keypad
//			     col1  col2  col3  col4
u8 symbol[N_row][N_col] = {{ '1',  '2',  '3',  'A'},  // row 1
                           { '4',  '5',  '6',  'B'},  // row 2
                           { '7',  '8',  '9',  'C'},  // row 3
                           { '*',  '0',  '#',  'D'}}; // row 4
/*
 * We will use pins		        in Port E as inputs (keypad rows)
 *		    PE4, PE3, PE2, PE1
 *    x    x    x    0    0    0    0    x 			-->  & 11100001
 *								-->  &= 0xE1
 *
 * We will use pins			in Port C as outputs (keypad columns)
 *		    PC7, PC6, PC5, PC4
 *		     1    1    1    1    x    x    x    x	-->  | 11110000
 * 								-->  |= 0xF0
 */

/*                                    ******************************
************************************** ___Keypad_Init() function___ **************************************
                                      ******************************
Keypad_Init() configures PORTC and PORTE to scan keypad keys
*/
void Keypad_Init(void)
{												// FE DCBA
	SYSCTL_RCGCGPIO_R |= 0x14;			// enable clock for PORTC and PORTE       (01 0100) --> (0x14)
	while ((SYSCTL_PRGPIO_R&0x14) == 0){};		// wait for clock to be setted
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R  |= 0xF0;			// allow settings for pins (4,5,6,7) of PORTC	11110000 --> 0xF0
  	GPIO_PORTE_CR_R  |= 0x1E;			// allow settings for pins (1,2,3,4) of PORTE	00011110 --> 0x1E
	GPIO_PORTC_DIR_R |= 0xF0;			// setting PC4-PC7 as output pins
  	GPIO_PORTE_DIR_R &= 0xE1;			// setting PE2-PE5 as input pins
  	GPIO_PORTA_PDR_R |= 0x1E;			// enable pull down resistor on PORTE for rows
  	GPIO_PORTC_DEN_R |= 0xF0;
  	GPIO_PORTA_DEN_R |= 0x1E;
}

/*                                    **********************************
************************************** ___keypad_getkey() function___   **************************************
                                      **********************************
keypad_getkey() is a function that returns the value of the pressed key by the user.
*/
u8 keypad_getkey(void)
{
 int i; 
 int j;
 while(1)
  {
   for(i = 0; i < 4; i++)                        
    {
      GPIO_PORTC_DATA_R = (1U << i+4);
      delay_us(2);
      for(j = 0; j < 4; j++)                     
      {
        if((GPIO_PORTE_DATA_R & 0x1E) & (1U << j+1))
        return symbol[j][i];
      }
    }
  }
}

/*                                    *************************************
************************************** ___keypad_getkey_caseD()function___ ***************************************
                                      *************************************
Special Function used to get number from user in case d
*/ 
char keypad_getkey_caseD(void)
{
 int i;
 int j;
 while(sw2_in()==0 & sw1_in()==0)
  {
    for(i = 0; i < 4; i++)                        //columns traverse
    {
      GPIO_PORTC_DATA_R = (1U << i+4);
      delay_us(2);
      for(j = 0; j < 4; j++)                     //raws traverse
      {
        if((GPIO_PORTE_DATA_R & 0x1E) & (1U << j+1))
	return symbol[j][i];
      }
    }
  }
    return 'z';
}

/*                                    ****************************
**************************************   ___check1() function___  **************************************
                                      ****************************
get pressed key and save it to use later
*/
u8 check1( u8 ch[])
{ 
 static int index=0;
 int i;
 int j;
 if(index>3){	index=0;}
 while(sw2_in()==0)
  {
    for(i = 0; i < 4; i++)                        //columns traverse
    {
      GPIO_PORTC_DATA_R = (1U << i+4);
      delay_us(2);
      for(j = 0; j < 4; j++)                     //raws traverse
      {
        if((GPIO_PORTE_DATA_R & 0x1E) & (1U << j+1))
	{
	  ch[index]=symbol[j][i];
	  index++;
	  return symbol[j][i];}
        } 
      }
    } 
    return ';';	
 }


