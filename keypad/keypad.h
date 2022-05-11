#ifndef keypad_H_
#define keypad_H_
#include "Std_INT.h"

// difines
#define N_col 4
#define N_row 4

// Keypad_Init() configures PORTC and PORTA to scan keypad keys
void Keypad_Init(void);

// put func here
u8 Keypad_Getkey(void);

#endif
