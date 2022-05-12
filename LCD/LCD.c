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
// Function used to make timer on LCD
// call lcd_timer (char array of counter digits without coulmn ex to set timer for 2 min lcd_timer(0200) )
void lcd_timer(u8* x){
	char i,j,k,l;
	char y = x[0];
	char m = x[1];
	char n = x[2];
	char z = x[3];
	lcd_setCursor(9,2);
	lcd_write(':');
	for(i=y ; i>='0' ; i--){
		lcd_setCursor(7,2);
		lcd_write(i);
		for (j=m ; j>='0' ; j--){
			lcd_setCursor(8,2);
			lcd_write(j);
			for (k=n ; k>='0' ; k--){
				lcd_setCursor(10,2);
				lcd_write(k);
				for (l=z ; l>='0' ; l--){
					lcd_setCursor(11,2);
					lcd_write(l);
					delay_ms(1000);
				}
				z='9';
			}
			n='5';
		}
		m='9';
	}
}

//Interface to start the writing process at certain digit in the LCD, call lcd_goto(col,row) 
void lcd_setCursor(u8 x,u8 y)    
{
	u8 firstcharadr[]={first_line1, first_line2}; // FirstCharAddress[0]=0x80  ,,,, FirstCharAddress[1]=0xC0 
	lcd_cmd(firstcharadr[y-1] + x - 1);
	delay_ms(50);
}
