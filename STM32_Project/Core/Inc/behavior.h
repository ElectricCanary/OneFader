/*
 * behavior.h
 *
 *  Created on: 13 oct. 2021
 *  Author: Electric Canary
 *
 *  Behavior has all the functions needed for
 */

#ifndef INC_BEHAVIOR_H_
#define INC_BEHAVIOR_H_

#define TARGET_WIDTH 20

extern uint16_t faderpos;

//Dictates the on board LED behavior
void Behavior_LED(void);

//Dictates the whole fader process
void Behavior_Fader(void);

//Calculates the speed of the fader based on it's travel
uint16_t Adaptive_Speed(void);

//Makes an average of the ADC values in the ADC buffer
void ADC_Average(void);

//Function that join every behavior functions, it goes in the main loop
void Behavior(void);

#endif /* INC_BEHAVIOR_H_ */
