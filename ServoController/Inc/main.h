/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "ctrler.h"
#include "cmd.h"
#include "misc.h"
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
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart3;

extern int Position_Target;
extern int Position_Current;
extern int Step_Status;
extern int Speed_Value;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STEP_SIGNAL_Pin GPIO_PIN_2
#define STEP_SIGNAL_GPIO_Port GPIOC
#define STEP_SIGNAL_EXTI_IRQn EXTI2_IRQn
#define TRIG_SIGNAL_Pin GPIO_PIN_4
#define TRIG_SIGNAL_GPIO_Port GPIOC
#define SPEED_SIGNAL_Pin GPIO_PIN_0
#define SPEED_SIGNAL_GPIO_Port GPIOB
#define ENC_SIGNAL_Pin GPIO_PIN_11
#define ENC_SIGNAL_GPIO_Port GPIOB
#define INA_SIGNAL_Pin GPIO_PIN_12
#define INA_SIGNAL_GPIO_Port GPIOD
#define INB_SIGNAL_Pin GPIO_PIN_13
#define INB_SIGNAL_GPIO_Port GPIOD
#define PWM_SIGNAL_Pin GPIO_PIN_8
#define PWM_SIGNAL_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
