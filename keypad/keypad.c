#include "tm4c123gh6pm.h"
#include "keypad.h"
#include "Std_INT.h"

// adding array of charachter in keypad
u8 symbol[N_row][N_col] = {{ '1', '2',  '3', 'A'},      // row 1
                           { '4', '5',  '6', 'B'},      // row 2
                           { '7', '8',  '9', 'C'},      // row 3
                           { '*', '0',  '#', 'D'}};     // row 4

