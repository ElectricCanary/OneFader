/*
 * motor.h
 *
 *  Created on: 17 nov. 2021
 *      Author: antoi
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#define MOTOR_SPEED_MIN 700
#define MOTOR_SPEED_MAX 2000
#define MOTOR_DEADZONE 40

//Stops the Motor (doesn't brake, the motor can still have momentum)
void Motor_Stop(void);

//Motor brake
void Motor_Brake(void);

//Motor goes forward at a certain speed
void Motor_Down(uint16_t pwm);

//Motor goes backward at a certain speed
void Motor_Up(uint16_t pwm);

//Conditions for moving the fader with PWM
uint16_t Motor_Move_Clip(uint16_t in);

#endif /* INC_MOTOR_H_ */
