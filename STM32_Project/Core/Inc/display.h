/*
 * display.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Electric Canary
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

//Displays the VU meters on top
void Display_VU(void);

//Displays the mute indicator
void Display_Mute(void);

//Displays the solo indicator
void Display_Solo(void);

//Displays the big center name of the display
void Display_Big(void);

//Displays dB in small at the bottom center
void Display_Small(void);

//Function that execute all other needed display function to get a frame
void Display_Frame(void);

#endif /* INC_DISPLAY_H_ */
