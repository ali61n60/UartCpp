#include "./DeveloperFiles/Header/Loop.h"
#include "./DeveloperFiles/Header/MainClass.h"
#include "string.h"
MainClass *p;
int delayTime;
extern "C" void Looper()
{
	
	p = new  MainClass();
	delayTime = 50;
	
	while (1)
	{		
		p->RepeatingLoop(delayTime);		
	}
}

//This function is called when UART_RX is completed as interrupt 
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	p->uart.UartRxCompleteInterrup(huart);	
}	


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
		const char *Message = "External Interrupt On Switch1 Detected\r\n";
		size_t length = strlen(Message) + 1;	
	delayTime = (delayTime == 50) ? 1000 : 50;
	
	p->uart.SendData((uint8_t *)Message,length );
}












/**
  * @brief  Sends an amount of data in non blocking mode.
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16) to be sent
  * @retval HAL status
  */
//HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)







//
///* USER CODE BEGIN Header */
///**
//  ******************************************************************************
//  * @file           : main.c
//  * @brief          : Main program body
//  ******************************************************************************
//  * @attention
//  *
//  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
//  * All rights reserved.</center></h2>
//  *
//  * This software component is licensed by ST under BSD 3-Clause license,
//  * the "License"; You may not use this file except in compliance with the
//  * License. You may obtain a copy of the License at:
//  *                        opensource.org/licenses/BSD-3-Clause
//  *
//  ******************************************************************************
//  */
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"
//#include "usart.h"
//#include "gpio.h"
//
///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//#include <../Loop.h>
///* USER CODE END Includes */
//
///* Private typedef -----------------------------------------------------------*/
///* USER CODE BEGIN PTD */
//
///* USER CODE END PTD */
//
///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
///* USER CODE END PD */
//
///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */
//
///* USER CODE END PM */
//
///* Private variables ---------------------------------------------------------*/
//
///* USER CODE BEGIN PV */
//
///* USER CODE END PV */
//
///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
///* USER CODE BEGIN PFP */
//
///* USER CODE END PFP */
//
///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */
//
///* USER CODE END 0 */
//
///**
//  * @brief  The application entry point.
//  * @retval int
//  */
//int main(void)
//{
//	/* USER CODE BEGIN 1 */
//
//	/* USER CODE END 1 */
//
//	/* MCU Configuration--------------------------------------------------------*/
//
//	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//	HAL_Init();
//
//	/* USER CODE BEGIN Init */
//
//	/* USER CODE END Init */
//
//	/* Configure the system clock */
//	SystemClock_Config();
//
//	/* USER CODE BEGIN SysInit */
//
//	/* USER CODE END SysInit */
//
//	/* Initialize all configured peripherals */
//	MX_GPIO_Init();
//	MX_USART1_UART_Init();
//	/* USER CODE BEGIN 2 */
//	Looper();
//	/* USER CODE END 2 */ 
//}
//
///**
//  * @brief System Clock Configuration
//  * @retval None
//  */
//void SystemClock_Config(void)
//{
//	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
//	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
//
//	/** Initializes the RCC Oscillators according to the specified parameters
//	* in the RCC_OscInitTypeDef structure.
//	*/
//	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
//	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
//	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
//	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//	{
//		Error_Handler();
//	}
//	/** Initializes the CPU, AHB and APB buses clocks
//	*/
//	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
//	                            | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
//	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
//	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//
//	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
//	{
//		Error_Handler();
//	}
//}
//
///* USER CODE BEGIN 4 */
//
///* USER CODE END 4 */
//
///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void)
//{
//	/* USER CODE BEGIN Error_Handler_Debug */
//	/* User can add his own implementation to report the HAL error return state */
//
//	/* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef  USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//	/* USER CODE BEGIN 6 */
//	/* User can add his own implementation to report the file name and line number,
//	   tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//	 /* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */
//
///************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
