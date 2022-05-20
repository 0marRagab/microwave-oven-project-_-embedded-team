#include "io.h"
#include "Gpio.h"
#include "Keypad.h"
#include "delay.h"
#include "LCD.h"
#include "Std_INT.h"
#include "used_function.h"
#include "functions.h"

int previous_state;
int state;
char y,m,n,z;
char q[4];
char ch[4];
int d; 


int main(){  
	unsigned int x=1;
	unsigned char input;
	unsigned char weight;
	unsigned char time_arr[5];
	char ch[4]={' '};
  char q[4]={' '};
	char temp;
	char c;
	char timer;
	char u[]="0000";
	int index;
	int i=1;
  state = initial_state;
	PortF_Init();
	PortA_Init();
	init_lcd();
	keypad_Init();
	SysTick_Init();
