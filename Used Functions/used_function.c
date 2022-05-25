#include "used_function.h"
#include "io.h"
#include "LCD.h"
#include "delay.h"
#include "Gpio.h"


char O[4]; 
char y,m,n,z;
char temp;


// function used to calculate number of input numbers from keypad	
unsigned int num_input (char y){
	static int x=0;
	while (y<='9'){
		x++;
		if (x==5){
			x=1;
		}
		return x;
		}
	return 10;
}
        

/*                                    **********************************
**************************************   ___fetch_input() function___   **************************************
                                      **********************************
to store user inputs in case d till pressing sw_2
*/
void fetch_input(){
	y=m;
 	m=n;
	n=z;
	z=temp;
	lcd_setCursor(6,2);
	lcd_string(y,m,':',n,z);
}

/*                                    *********************************
**************************************   ___Error_msg1() function___   **************************************
                                      *********************************
to print error msg if unexpected button is pressed
*/

void Error_msg1(){
	lcd_clear();
	lcd_setCursor(6,2);
	lcd_print("Error");
	Buzzer_ON();
	delay_ms(1500);
	Buzzer_OFF();
}

/*                                    *********************************
**************************************   ___Error_msg2() function___   **************************************
                                      *********************************
to print error msg if unexpected button is pressed (in beef & chicken cases)
*/

void Error_msg2(){
	RGB_OFF();
	lcd_setCursor(8,2);
	lcd_print("       ");
	lcd_setCursor(8,2);
	lcd_print("Error");
	Buzzer_ON();
	delay_ms(1500);
	Buzzer_OFF();
	lcd_clear();
	lcd_setCursor(1,1);
	lcd_print("Enter Bet 1:9");
	delay_ms(1500);
	lcd_clear();
}


/*                                    ******************************
**************************************   ___int mod() function___   **************************************
                                      ******************************
 func to return remainder (modulo)
*/

unsigned int mod(u32 num, u32 div){
	while (num >= div){
		num = num - div;
	}
	return num;
}

/*                                    ******************************
**************************************  ___RGB_BLINK() function___  **************************************
                                      ******************************
 call RGB_BLINK() to blink the RGB array
*/

void RGB_BLINK() {                            
	RGB_OFF();
	delay_m_s(1000);
	RGB_ON();
	delay_m_s(1000);
}

/*                                    *********************
**************************************   ___RGB_FLASH___   **************************************
                                      *********************
 call RGB_FlASH() to Flash the RGB array 3 times
*/

void RGB_FLASH() {                           
	int i ;
	for( i=0 ; i< 3 ; i++ ){
		RGB_OFF();
		delay_m_s(500);
		RGB_ON();
		delay_m_s(500);
		RGB_OFF();
	}
}

/*                                    **************************
**************************************     ___super_timer___    **************************************
                                      **************************
call super_timer to display timer on screen
*/ 

int super_timer(u8 min,u8 mmin,u8 sec,u8 msec){
	int i;
	if( (min<='9' && min>='0') && (mmin<='9' && mmin>='0') && (sec<='9' && sec>='0') && (msec<='9' && msec>='0')){
		if(mmin == '9' && sec > '5'){
			min++;
			mmin='0';
			sec = sec - 6;
		}
		if(sec>'5'){
		mmin+=1;
		sec = sec - 6;
		}
		if(min>'3'||(min=='3'&&mmin>'0')||(min=='3'&&mmin=='0'&&sec>'0')||(min=='3'&&mmin=='0'&&sec=='0'&&msec>'0')){
			RGB_OFF();
			lcd_setCursor(2,2);
		  	lcd_print("ErrMax=30:00");
		  	Buzzer_ON();
			delay_ms(1500);
			Buzzer_OFF();
	    		lcd_clear();
	    		return 0;
		}
	}
	else {
		RGB_OFF();
		Error_msg1();
		lcd_clear();
		lcd_print("Enter bet 1:9");
		delay_ms(1500);
	  	lcd_clear();
	  	return 0;
	}
	while(1){
		if (sw1_in()==1){
			delay_ms(400);
			O[0]=min ;O[1]= mmin ;O[2]=sec ;O[3]=msec ;
			return 2;
		}
		RGB_ON();
		lcd_setCursor(6,2);
		lcd_string(min,mmin,':',sec,msec);
		delay_ms(1000);
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
	return 1;
}
