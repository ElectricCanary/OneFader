/*
 * motor.c
 *
 *  Created on: 17 nov. 2021
 *      Author: antoi
 */
#include "main.h"
#include "motor.h"

void Motor_Stop(void)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
}

void Motor_Brake(void)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 2000);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 2000);
}

void Motor_Down(uint16_t pwm)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, Motor_Move_Clip(pwm));
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
}

void Motor_Up(uint16_t pwm)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, Motor_Move_Clip(pwm));
}

uint16_t Motor_Move_Clip(uint16_t in)
{
		return(MOTOR_SPEED_MIN + ((in*(0xFFFF - MOTOR_SPEED_MIN))/0xFFFF));
}
