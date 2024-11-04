/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define A1_Pin GPIO_PIN_0
#define A1_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_1
#define B1_GPIO_Port GPIOA
#define C1_Pin GPIO_PIN_2
#define C1_GPIO_Port GPIOA
#define D1_Pin GPIO_PIN_3
#define D1_GPIO_Port GPIOA
#define E1_Pin GPIO_PIN_4
#define E1_GPIO_Port GPIOA
#define F1_Pin GPIO_PIN_5
#define F1_GPIO_Port GPIOA
#define G1_Pin GPIO_PIN_6
#define G1_GPIO_Port GPIOA
#define DP1_Pin GPIO_PIN_7
#define DP1_GPIO_Port GPIOA
#define A2_Pin GPIO_PIN_0
#define A2_GPIO_Port GPIOB
#define B2_Pin GPIO_PIN_1
#define B2_GPIO_Port GPIOB
#define V2_Pin GPIO_PIN_10
#define V2_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_11
#define D2_GPIO_Port GPIOB
#define X1_Pin GPIO_PIN_12
#define X1_GPIO_Port GPIOB
#define V1_Pin GPIO_PIN_13
#define V1_GPIO_Port GPIOB
#define D1B14_Pin GPIO_PIN_14
#define D1B14_GPIO_Port GPIOB
#define C2_Pin GPIO_PIN_3
#define C2_GPIO_Port GPIOB
#define D2B4_Pin GPIO_PIN_4
#define D2B4_GPIO_Port GPIOB
#define E2_Pin GPIO_PIN_5
#define E2_GPIO_Port GPIOB
#define F2_Pin GPIO_PIN_6
#define F2_GPIO_Port GPIOB
#define G2_Pin GPIO_PIN_7
#define G2_GPIO_Port GPIOB
#define DP2_Pin GPIO_PIN_8
#define DP2_GPIO_Port GPIOB
#define X2_Pin GPIO_PIN_9
#define X2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
