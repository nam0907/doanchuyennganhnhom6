/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int i;
int xanh1=10;
int vang1=3;
int do1=10;
int chedo=0;
unsigned char maled[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void LCD_Data(char data1)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,1);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,data1&(1<<0));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,data1&(1<<1));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,data1&(1<<2));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,data1&(1<<3));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,data1&(1<<4));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,data1&(1<<5));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,data1&(1<<6));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,data1&(1<<7));
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,0);
	HAL_Delay(10);
}

void LCD_Command(char data)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,1);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,data&(1<<0));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,data&(1<<1));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,data&(1<<2));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,data&(1<<3));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,data&(1<<4));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,data&(1<<5));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,data&(1<<6));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,data&(1<<7));
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,0);
	HAL_Delay(10);
}

void LCD_Init()
{
	LCD_Command(0x00);
	LCD_Command(0x03);
	LCD_Command(0x02);
	LCD_Command(0x06);
	LCD_Command(0x0C);
	LCD_Command(0x80);
	LCD_Command(0x38);
	LCD_Command(0x01);
}

void LCD_ghichuoi(char *str)
{
	while(*str)
	{
		LCD_Data(*str);
		str++;
	}
}

void hienthiled7_1(int data)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,data&(1<<0));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,data&(1<<1));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,data&(1<<2));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,data&(1<<3));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,data&(1<<4));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,data&(1<<5));
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,data&(1<<6));
}

void hienthi1(int d2, int x1)
{
	  int i;
	  int chucd2,dvid2,chucx1,dvix1;
	
		chucx1=x1/10;
		dvix1=x1%10;
	
		chucd2=d2/10;
		dvid2=d2%10;
	
			for(i=0;i<25;i++)
			{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1); hienthiled7_1(maled[chucd2]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1); hienthiled7_1(maled[dvid2]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1); hienthiled7_1(maled[chucx1]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1); hienthiled7_1(maled[dvix1]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0);
			}
}
void hienthi2(int d1, int x2)
{
	  int i;
	  int chucd1,dvid1,chucx2,dvix2;
	
		chucx2=x2/10;
		dvix2=x2%10;
	
		chucd1=d1/10;
		dvid1=d1%10;
	
			for(i=0;i<10;i++)
			{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1); hienthiled7_1(maled[chucd1]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1); hienthiled7_1(maled[dvid1]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1); hienthiled7_1(maled[chucx2]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1); hienthiled7_1(maled[dvix2]); HAL_Delay(10); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0);
			}
}
void chedobanngay()
{
	  int i;
	  int lan1=0;
		int do2,vang2,xanh2;
		do2=xanh1+vang1;
		vang2=vang1;
		xanh2=do1-vang1;
		int demdo1=do1;
		int demdo2=do2;
		int demx1=xanh1;
		int demx2=xanh2;
		LCD_Command(0x01);
	  LCD_ghichuoi("che do ban ngay");
//	  if(chedo==0)
//		{
//			if(demdo2>0&&lan1==0)
	    while(demdo2>=0)
			{
			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==0)
			{
				break;
			}
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,1);
			if(demx1>0)
			{
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
			}
			hienthi1(demdo2,demx1);
			demdo2--;
			demx1--;
			if(demx1<0)
			{
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				demx1=0;
			}
		}
			while(demdo1>=0)
	   {
			 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==0)
			{
				break;
			}
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
			if(demx2>0)
			{
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,0);
			}
			hienthi1(demdo1,demx2);
			demdo1--;
			demx2--;
			if(demx2<0)
			{
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,0);
				demx2=0;
			}
		}
//	}
}
void chedobandem()
{
//	  if(chedo==1)
//		{
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,0);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0);
	
			LCD_Command(0x01); //xoa man hinh
			LCD_ghichuoi("che do ban dem");
	
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_10);
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_13);
			HAL_Delay(1000);
//		}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
//	LCD_Init();
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	LCD_Init();
//	LCD_ghichuoi("Che do ban ngay");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==0)
		{
			while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==0);
			chedo++;
			if(chedo>1)
			{
				chedo=0;
			}
		}
    /* USER CODE END WHILE */
		if(chedo==0)
		{
			chedobanngay();
		}
		else if(chedo==1)
		{
			chedobandem();
		}
    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
	}
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, A1_Pin|B1_Pin|C1_Pin|D1_Pin
                          |E1_Pin|F1_Pin|G1_Pin|DP1_Pin
                          |GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|V2_Pin|D2_Pin
                          |X1_Pin|V1_Pin|D1B14_Pin|GPIO_PIN_15
                          |C2_Pin|D2B4_Pin|E2_Pin|F2_Pin
                          |G2_Pin|DP2_Pin|X2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : A1_Pin B1_Pin C1_Pin D1_Pin
                           E1_Pin F1_Pin G1_Pin DP1_Pin
                           PA8 PA11 PA12 PA15 */
  GPIO_InitStruct.Pin = A1_Pin|B1_Pin|C1_Pin|D1_Pin
                          |E1_Pin|F1_Pin|G1_Pin|DP1_Pin
                          |GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A2_Pin B2_Pin V2_Pin D2_Pin
                           X1_Pin V1_Pin D1B14_Pin PB15
                           C2_Pin D2B4_Pin E2_Pin F2_Pin
                           G2_Pin DP2_Pin X2_Pin */
  GPIO_InitStruct.Pin = A2_Pin|B2_Pin|V2_Pin|D2_Pin
                          |X1_Pin|V1_Pin|D1B14_Pin|GPIO_PIN_15
                          |C2_Pin|D2B4_Pin|E2_Pin|F2_Pin
                          |G2_Pin|DP2_Pin|X2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
