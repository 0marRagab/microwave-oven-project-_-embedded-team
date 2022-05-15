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

//Some LCD Commands in Hexadecimal

#define lcd_Clear            0x01                 // replace all characters with ASCII 'space'
#define lcd_Home             0x02                // return cursor to first position on first line
#define lcd_EntryMode        0x06               // shift cursor from left to right on read/write
#define lcd_DisplayOff       0x08              // turn display off
#define lcd_DisplayOn        0x0F             // display on Cursor Blink
#define lcd_DisplayOn_Coff   0x0C            // display on Cursor off
#define lcd_FunctionReset    0x30           // reset the LCD
#define lcd_FunctionSet8bit  0x38          // 8-bit data, 2-line display, 5 x 7 font
#define first_line1          0x80         // set cursor position in first row
#define first_line2          0xC0        // set cursor position in second row

//initilization port B for data
void PortB_Init(void);
	
// initilization port D for en,rs,rw
void PortD_Init(void);

//Interface to send the configuration commands to the LCD Driver
void lcd_cmd(u8 cmd);

// Clear the Display
void lcd_clear();

//Apply initialization sequence for LCD module
void init_lcd(void);   

//Interface to write character on LCD screen        
void lcd_write(u8 data);

//Interface to write string on LCD screen
void lcd_print(); 

//Interface to start the writing process at certain digit in the LCD, call setCursor(col,row)
void lcd_setCursor(u8 x,u8 y);    


void lcd_string(u8 str1,u8 str2,u8 str3,u8 str4,u8 str5);

#endif
