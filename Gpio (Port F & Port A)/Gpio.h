#ifndef Gpio_H
#define Gpio_H
#include "Std_INT.h"

void PortF_Init();
void PortA_Init();
int sw1_in();
int sw2_in();
int sw3_in();
void Buzzer_ON();
void Buzzer_OFF();
void RGB_ON();
void RGB_OFF();


#endif
