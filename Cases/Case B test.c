#include "tm4c123gh6pm.h"
#include "Gpio.h"
#include "Keypad.h"
#include "delay.h"
#include "LCD.h"
#include "Std_INT.h"



int main(){
	char key;
	unsigned char my_temp;
	unsigned char weight;
	unsigned char time_arr[5];
	char temp;
	int index;
	char u[]="0000";
	char y,m,n,z;
	int i; char c;
	PortF_Init();
	PortA_Init();
	init_lcd();
	keypad_Init();
	SysTick_Init();
  
	while(1){
		
	key = Keypad_Getkey();	
	
       switch(key)	
       {
		       
	       case 'B':	       
		             
		       
		       time_arr[0]='0'; time_arr[3]='0'; 		        // since time always be 0x:x0 
		       
		       while(i){
			       
			lcd_clear();
			lcd_setCursor(1,1);
			lcd_print("Beef weight?");
			lcd_setCursor(1,2);
			lcd_print("weight:");
			index=0;
			lcd_setCursor(8,2);
			while(sw2_in()==0){
				c = keypad_getkey_caseD();
				delay_ms(200);
				if(c!='z'){
					lcd_write(c);
					u[index]=c;
					index++;
				}
			}
			if (index==1){
				if (u[0]<='9' & u[0]>='1'){ // check weight to be 1:9
					weight=u[0];
					weight = weight - 48;
					lcd_clear();
					lcd_setCursor(7,1);
					lcd_print("Beef");
					if(mod(weight,2) == 0){
time_arr[1]= (weight / 2) + 48;
time_arr[2]='0';
}else{
time_arr[1]= ((weight - 1) / 2) + 48;
time_arr[2]='3';
i=0;
}

}
else{
lcd_setCursor(8,2);
lcd_print(" ");
lcd_setCursor(8,2);
lcd_print("Err");
delay_ms(2000);
}
}else{
lcd_setCursor(8,2);
lcd_print(" ");
lcd_setCursor(8,2);
lcd_print("Err");
delay_ms(2000);
}

}
lcd_timer(time_arr);
break;
       }		
	}
