#include "io.h"
#include "Std_INT.h"
#include "Gpio.h"

int main(){

PortA_Init();

while(1){

if(sw3_in()==1){             
   Buzzer_ON();
   Red_ON();
}

else {
   Buzzer_OFF();
   Red_OFF();
}

}


}
