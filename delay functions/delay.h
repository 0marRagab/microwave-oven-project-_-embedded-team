#ifndef delay_H
#define delay_H


// to initialize the SysTick Timer
void SysTick_Init();
  
//to make delay one millisecond
void delay_onems(); 

//to make delay one microsecond
void delay_oneus();

// call delay_ms(*time*)
void delay_ms(unsigned int x);

// call delay_us(*time*)
void delay_us(unsigned int y);

int delay_portA_interrupt(unsigned int x);


	
#endif
