#ifndef Gpio_H
#define Gpio_H
#include "Std_INT.h"

// To initialize Port F
void PortF_Init();


// To initialize Port A
void PortA_Init();


// To return 1 if sw1 is pressed and 0 if not Pressed
int sw1_in();


// To return 1 if sw2 is pressed and 0 if not Pressed
int sw2_in();


// To return 1 if sw3 is pressed and 0 if not Pressed
int sw3_in();


// call Buzzer_ON() to turn on the buzzer
void Buzzer_ON();


// call Buzzer_OFF() to turn off the buzzer
void Buzzer_OFF();


// call RGB_ON() to turn on the RGB array
void RGB_ON();


// call RGB_OFF() to turn of the RGB array
void RGB_OFF();


#endif

