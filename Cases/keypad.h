#ifndef keypad_H_
#define keypad_H_
#include "Std_INT.h"

// definitions of numbers of rows and cols of our keypad 
#define N_col 4
#define N_row 4

// Keypad_Init() configures PORTC and PORTA to scan keypad keys
void Keypad_Init(void);

// This function Returns the character pressed it the keypad
u8 Keypad_Getkey(void);

// Function used to get number from user in case d
char keypad_getkey_caseD(void);
 

#endif
