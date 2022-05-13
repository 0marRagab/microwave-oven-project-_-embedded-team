#ifndef LCD_H
#define LCD_H
#include "Std_INT.h"

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/*
                  
                                      LCD wiring (pins connection) with tiva TM4C123gh6pm


                                              PB7|---------------->|D7        
                                              PB6|---------------->|D6        
                                              PB5|---------------->|D5        
                                              PB4|---------------->|D4        
                                              PB3|---------------->|D3        
                                              PB2|---------------->|D2        
                                              PB1|---------------->|D1        
                                              PB0|---------------->|D0        
                                            ------------------------------          
                                              PD6|---------------->|E         
                                              PD3|---------------->|RW        
                                              PD2|---------------->|RS        
                    
 */
