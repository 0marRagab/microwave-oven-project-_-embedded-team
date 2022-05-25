#include "io.h"
#include "Std_INT.h"
#include "Gpio.h"
#include "keypad.h"

int main(){
  u8 key;
	PortF_Init();
	Keypad_Init();
	while(1){
    key = Keypad_Getkey();
    if(key == 'A'){
      RGB_ON();
    }else if(key == '1'){
      RGB_OFF();
    }else{
      RGB_OFF();
    }
  }
}
