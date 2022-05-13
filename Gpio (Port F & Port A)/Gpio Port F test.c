#include "tm4c123gh6pm.h"
#include "Gpio.h"

int main(){

PortF_Init();

while(1){

if(sw1_in()==1){             
   RGB_ON();
}

else if (sw2_in()==1){
RGB_ON();
}

else {
RGB_OFF();
}

}


}
