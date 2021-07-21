/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum rtdmux_t {
	J1,
	J2,
	J3,
	J4
} rtdmux_t;


typedef enum loadInstanste {
	load_J3,
	load_J4,
	load_J5
}load_t;

typedef enum acCtrlMode_t {
	phaseAngleCtrl,
	onoffCtrl
} acCtrlMode_t;

typedef struct loadConf_t{
	load_t instance;
	acCtrlMode_t mode;
	uint32_t powerPercent;
	GPIO_TypeDef *GPIO_Port;
	uint16_t GPIO_Pin;
	uint32_t timerChannel;
	bool isSet; /* Flag indicating if the current configurations is set (if not at next ZC event the settings are set) */
}loadConf_t;

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
#define MUX1_IN1_Pin GPIO_PIN_13
#define MUX1_IN1_GPIO_Port GPIOC
#define MUX1_IN2_Pin GPIO_PIN_14
#define MUX1_IN2_GPIO_Port GPIOC
#define MUX2_EN_Pin GPIO_PIN_15
#define MUX2_EN_GPIO_Port GPIOC
#define MUX2_IN1_Pin GPIO_PIN_0
#define MUX2_IN1_GPIO_Port GPIOD
#define MUX2_IN2_Pin GPIO_PIN_1
#define MUX2_IN2_GPIO_Port GPIOD
#define J3_Pin GPIO_PIN_1
#define J3_GPIO_Port GPIOA
#define RELAY_Pin GPIO_PIN_4
#define RELAY_GPIO_Port GPIOA
#define J4_Pin GPIO_PIN_10
#define J4_GPIO_Port GPIOB
#define J5_Pin GPIO_PIN_11
#define J5_GPIO_Port GPIOB
#define DBG_LED1_Pin GPIO_PIN_8
#define DBG_LED1_GPIO_Port GPIOA
#define CS2_Pin GPIO_PIN_15
#define CS2_GPIO_Port GPIOA
#define CS1_Pin GPIO_PIN_6
#define CS1_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_7
#define BUZZER_GPIO_Port GPIOB
#define MUX1_EN_Pin GPIO_PIN_9
#define MUX1_EN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
