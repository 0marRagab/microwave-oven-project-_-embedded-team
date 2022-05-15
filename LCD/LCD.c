#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "delay.h"
//====================================================================================================
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
//====================================================================================================
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
//====================================================================================================
//Apply initialization sequence for LCD module
void init_lcd (void)                     
{
 PortB_Init();
 PortD_Init();	
	
  //Function Set
lcd_cmd(lcd_FunctionSet8bit);
delay_ms(1);

	
// Entry Mode Set  
lcd_cmd(lcd_EntryMode);
delay_ms(1);
	
 // Turn Display ON with Cursor Blinking  
lcd_cmd(lcd_DisplayOn);
delay_ms(1);
	
// Clear Display 
lcd_clear();
delay_ms(2);
	
//Return Home 
lcd_cmd(lcd_Home);
delay_ms(2);
	
return;
}
//====================================================================================================
//to clear lcd 
void lcd_clear()
{
lcd_cmd(lcd_Clear);	
}
//====================================================================================================
//Interface to send the configuration commands to the LCD Driver
void lcd_cmd(u8 cmd)            
{
GPIO_PORTB_DATA_R=cmd;
	
GPIO_PORTD_DATA_R=(LOW<<PIN2)|(LOW<<PIN3)|(HIGH<<PIN6);
delay_ms(1);
GPIO_PORTD_DATA_R=(LOW<<PIN2)|(LOW<<PIN3)|(LOW<<PIN6);
delay_ms(50);
	
return;
}
//====================================================================================================
//Interface to start the writing process at certain digit in the LCD, call lcd_goto(col,row) 
void lcd_setCursor(u8 x,u8 y)    
{
	u8 firstcharadr[]={first_line1, first_line2}; // FirstCharAddress[0]=0x80  ,,,, FirstCharAddress[1]=0xC0 
	lcd_cmd(firstcharadr[y-1] + x - 1);
	delay_ms(50);
}
//====================================================================================================
//Interface to write character on LCD screen
void lcd_write(u8 data)
{
GPIO_PORTB_DATA_R=data;
	
GPIO_PORTD_DATA_R=(HIGH<<PIN2)|(LOW<<PIN3)|(HIGH<<PIN6);
delay_ms(1);
GPIO_PORTD_DATA_R=(HIGH<<PIN2)|(LOW<<PIN3)|(LOW<<PIN6);
delay_ms(50);
	
return;
}
//====================================================================================================
//Interface to write string on LCD screen
void lcd_print(u8 *str)  
{
int		i=0;
while(str[i]!='\0')
{
lcd_write(str[i]);
i++;	
}
delay_ms(100);
return;	
}

//====================================================================================================
// Function used to make timer on LCD
// call lcd_timer (char array of counter digits without coulmn ex to set timer for 2 min lcd_timer(0200) )
void lcd_string(u8 str1,u8 str2,u8 str3,u8 str4,u8 str5)  
{
lcd_write(str1);
lcd_write(str2);
lcd_write(str3);
lcd_write(str4);
lcd_write(str5);
delay_ms(100);
	
return;
	
}

int super_timer(u8 min,u8 mmin,u8 sec,u8 msec){
	int i;
	if(mmin=='9'){min++;
		mmin='0';}
	
	if(min>'3'||(min=='3'&&mmin>'0')||(min=='3'&&mmin=='0'&&sec>'0')||(min=='3'&&mmin=='0'&&sec=='0'&&msec>'0')){
		lcd_setCursor(2,2);
		lcd_print("ErrMax=30:00");
			delay_ms(2000);
	   lcd_clear();
	   lcd_setCursor(6,2);
		  lcd_print("00:00");
	return 0;}
		
	if(sec>'5'){
		
			mmin+=1;
		sec='1';
	
	}
	

while(1){
	
	lcd_setCursor(6,2);
	lcd_string(min,mmin,':',sec,msec);
	
   delay_ms(1000);
	if (sw1_in()==1) {
            while (sw2_in()==0)
             {
							delay_ms(500); 
              RGB_OFF();
		          delay_ms(1000);
		          RGB_ON();
							 
		          delay_ms(1000); 
              if(sw1_in() ==1)
              {
								RGB_OFF();
								lcd_clear();
								lcd_print("cooking stoped");
								delay_ms(2000);
                return 0; 
              }
				    }
					RGB_ON();	 
					}
	
if(msec!='0'){
msec--;
	
}
if(msec=='0'&&sec=='1'){
	
lcd_setCursor(6,2);
	lcd_string(min,mmin,':',sec,msec);
	
	delay_ms(1000);
}
if(msec=='0'&&sec!='0'){
msec='9';
	sec--;
}
if(msec=='0'&&sec=='0'&&mmin!='0'){
mmin--;
	sec='5';
	msec='9';
}
if(msec=='0'&&sec=='0'&&mmin=='0'&&min!='0'){
min--;
	mmin='9';
	sec='5';
	msec='9';

}
if(msec=='0'&&sec=='0'&&min=='0'&&mmin=='0'){
	lcd_setCursor(6,2);
	lcd_string('0','0',':','0','0');
  break;
}


}
return 0;
}
//====================================================================================================

int lcd_timer(u8* x){
	char i,j,k,l;
	char y = x[0];
	char m = x[1];
	char n = x[2];
	char z = x[3];
	RGB_ON();
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
					delay_m_s(1000);
					if (sw1_in()==1) {
						while (sw2_in()==0){
							delay_ms(500); 
							RGB_OFF();
							delay_m_s(1000);
							RGB_ON();
							delay_m_s(1000); 
						        if(sw1_in() ==1){
								RGB_OFF();
								lcd_clear();
								lcd_print("cooking stoped");
								delay_ms(2000);
								return 0; 
							}
						}
						RGB_ON();
					}
					z='9';
				}
				n='5';
			}
			m='9';
		}
	}
	Buzzer_ON();
	for( i=0 ; i< 3 ; i++ ){
		RGB_OFF();
		delay_ms(500);
		RGB_ON();
		delay_ms(500);
		RGB_OFF();
	}
	Buzzer_OFF();
	return 0;
}
