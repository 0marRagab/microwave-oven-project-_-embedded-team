# Microwave Oven Controller System Project #
This project is for *Introduction to Embedded Systems* Course and simulates a **microwave device** using some electrical components like: (LCD, Keypad, Push Buttons, Buzzer and LEDS) to simulate its different modes of working like (cooking, stop, pause, resume and finish) using ARM Cortex-M4 processor, Tiva C series EK-TM4C123GH6PM board.

## Language used ##
Embedded C

## Members ##
This project is Done by Group of 8 members of CSE and ECE departements at Faculty of Engineering Ain Shams Univeristy:
|**Name**|**ID**|**github link**|**dep.**|
|:-------|:----:|:--------------|:-------|
|Omar Ragab Mohamed|1901171|https://github.com/0marRagab|ECE|
|Mina Gamal Fayez Labib|1900101|https://github.com/Mina-Gamal-210|ECE|
|Omar Karam Samir Foad|1900868|https://github.com/omarnkaram771|CSE| 
|Yasmeen Abdelrazek Mohamed|1900434|https://github.com/yasmeen-abdelrazek|CSE|
|Tarek Magdy Sayed|1900702|https://github.com/Tarek-Magdy|ECE|
|Moustafa Yasser Abdelmonem|1900092|https://github.com/Eng-DO4|ECE|
|Youssef Emad mohamed|1701739|https://github.com/Yossef-Emad|CSE|
|Shimaa Rashad Saeed Nassar|1901338|https://github.com/shimaa204|CSE|

## the details of what was asked to do in this project ##

**While not cooking (stopped), enter a choice to begin cooking:


• If A is pushed on the keypad (for popcorn), the LCD should show “Popcorn” and then 
cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD, 
then clear the LCD after cooking completes.


• If B (for Beef) or C (for chicken) is pushed on the keypad, the words “Beef weight?” or 
“Chicken weight?” (respectively) should appear on the LCD. After that, the user must 
enter an integer value between 1 and 9 on the keypad to indicate how many kilos are 
there to be defrosted.
Note that only whole kilo values are to be entered. After a valid number is entered, clear 
the LCD display and show the value of the weight on the LCD for 2 seconds, and then 
start cooking while the remaining cook time counts down (in seconds) on the LCD

_ Beef is defrosted at a rate of 0.5 minutes per kilo.

_ Chicken is defrosted at a rate of 0.2 minutes per kilo.

_ If an illegal number is entered, then the LCD should show “Err” for 2 seconds, 
then show previous message.


If D is pushed on the keypad, the words “Cooking Time?” should appear on the LCD. 
After that the user can enter a value between 1 and 30 to indicate the cooking time 
required in minutes and seconds. This value is displayed on the LCD as it is entered, right 
to left. 
For example, pressing 1 displays 00:01, then pressing 2 displays 00:12, then pressing 4 
displays 01:24, then pressing 5 displays 12:45. Press push button SW1 to clear the LCD 
display and press SW2 to start cooking and counting down (in seconds) the cooking time 
on the LCD

**Start/Stop/Pause cooking conditions:


• Switch SW3 (external push button), position 1, will simulate the microwave oven door 
latch, where the switch being down would be simulating the open-door situation and the 
switch being up would be simulating the door closed situation. Only when the latch is 
closed should the oven be able to be started.

_ When SW2 is pressed, the oven starts operation.

_ When SW1 (external push button) is pressed for first time, the oven operation 
pauses (keeping remaining time on the display).

_ When SW1 is pushed for second time after pressing it for first time, the time is 
cleared and the cooking stops.

_ If SW2 is pushed after the oven is paused and the door is closed, then cooking 
must resume from the time it was paused.

• If it is cooking, opening the door should pause the cooking and keep the remaining time 
on display.

• When the microwave is running, the array of LEDs should be on. When it is stopped, 
they should go off. If paused, the array of LEDs should blink (wait time on and wait time 
off) till the cooking is resumed or stopped.

When the microwave completes its function and timer has counted down to zero (regular 
timed cooking or defrosting), the array of LEDs should flash 3 times (wait time on and 
wait time off), and the buzzer should produce an audible tone/alarm during these 3 
second times periods.

# Project Pdf #
this pdf include all project details

https://drive.google.com/file/d/1ipNVOugnh0EojabgTCZ1MZuad37eOj7P/view
# Project Video #
https://drive.google.com/file/d/1PVcwUsDFOByYo7tiICcqBacrgwSGQQwJ/view
