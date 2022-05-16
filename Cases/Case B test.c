
int main(){
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
    time_arr[0]='0'; time_arr[3]='0'; 		// time always be 0x:x0 
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
