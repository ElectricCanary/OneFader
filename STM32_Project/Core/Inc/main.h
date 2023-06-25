/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define BTN5_Pin GPIO_PIN_12
#define BTN5_GPIO_Port GPIOB
#define BTN4_Pin GPIO_PIN_13
#define BTN4_GPIO_Port GPIOB
#define BTN1_Pin GPIO_PIN_14
#define BTN1_GPIO_Port GPIOB
#define Touch_Pin GPIO_PIN_15
#define Touch_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_8
#define BTN3_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_9
#define BTN2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define TOUCH_SENSITIVITY 800
#define DEBOUNCE_MS 1
#define DEBOUNCE_INPUTS 6
#define DEBOUNCE_TOUCH 0
#define DEBOUNCE_BUTTON1 1
#define DEBOUNCE_BUTTON2 2
#define DEBOUNCE_BUTTON3 3
#define DEBOUNCE_BUTTON4 4
#define DEBOUNCE_BUTTON5 5
#define ADC_BUF_LEN 4096

extern uint8_t Debounce[DEBOUNCE_INPUTS];
void Debounce_Sequence(void);

extern uint8_t touch_state;

//Set buffer for ADC results
extern uint16_t ADC_Buf[ADC_BUF_LEN];

//Indicates when the buffer is half full or full
extern uint8_t ADC_Half;
extern uint8_t ADC_Complete;
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

extern TIM_HandleTypeDef htim1;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
