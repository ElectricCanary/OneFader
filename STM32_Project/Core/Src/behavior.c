/*
 * behavior.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Electric Canary
 */


#include "protocol.h"
#include "behavior.h"
#include "main.h"
#include "motor.h"
#include <math.h>

uint16_t faderpos = 11730;


void ADC_Average(void)
{
	uint16_t i;
	uint32_t sum = 0;
	static uint16_t half;

	if (ADC_Half)
	{
		for(i=0; i<(ADC_BUF_LEN/2); i++)
		{
			sum += ADC_Buf[i];
		}
		half = sum/(ADC_BUF_LEN/2);
		sum = 0;
		ADC_Half = 0;
	}

	if (ADC_Complete)
	{
		for(i=(ADC_BUF_LEN/2); i<4096; i++)
		{
			sum += ADC_Buf[i];
		}
		faderpos = 4096 - (((sum/(ADC_BUF_LEN/2)) + half) /2);
		sum = 0;
		ADC_Complete = 0;
	}
}

uint16_t Adaptive_Speed(void)
{
	if(abs((FaderPositions[0]>>2)- faderpos) < 200)
	{
		return(MOTOR_SPEED_MIN);
	}

	else
	{
		//simple linear speed
		//return(MOTOR_SPEED_MIN + (abs((FaderPositions[0]>>2)- faderpos)*(MOTOR_SPEED_MAX - MOTOR_SPEED_MIN))/0xFFF)

		//part of a parabol (better imo)
		return((-4*pow((abs((FaderPositions[0]>>2)- faderpos))-4095,2)/51597)+2000);
	}
}

void Behavior_Fader(void)
{

	static uint8_t touched = 0;

	if (!Debounce[DEBOUNCE_TOUCH])
	{
		if(!touched)
		{
			Motor_Stop();
			FaderTouch(0);
			touched = 1;
		}

		FaderMove(0, faderpos);
	}

	else
	{

		if (touched)
		{
			FaderRelease(0);
			touched = 0;
		}

		if (abs((FaderPositions[0]>>2)- faderpos) > MOTOR_DEADZONE)
		{
			if (faderpos<<2 < FaderPositions[0])
					{
						Motor_Up(Adaptive_Speed());
					}

					else
					{
						Motor_Down(Adaptive_Speed());
					}
		}

		else
		{
			Motor_Brake();
		}

	}
}

void Behavior_LED(void)
{
	if (Debounce[DEBOUNCE_TOUCH])
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		}
}

void Behavior(void)
{
	ADC_Average();
	Behavior_Fader();
	Behavior_LED();
}
