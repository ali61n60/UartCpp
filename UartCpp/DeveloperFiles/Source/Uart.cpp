#include <./CubeFiles/Inc/main.h>
#include <./CubeFiles/Inc/usart.h>
#include "./DeveloperFiles/Header/Uart.h"

void Uart::UartRxCompleteInterrup(UART_HandleTypeDef *huart)
{	
	HAL_UART_Transmit_IT(huart, this->uartBuffer, sizeof(this->uartBuffer));	
	this->EnableUsartRxInterrupt();
}


void Uart::EnableUsartRxInterrupt()
{	
	HAL_UART_Receive_IT(&huart1 , this->uartBuffer, sizeof(this->uartBuffer));
}



void Uart::UsartPollingModeExample()
{	
	HAL_UART_Receive(&huart1, uartBuffer, sizeof(uartBuffer), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, uartBuffer, sizeof(uartBuffer), HAL_MAX_DELAY);	
}

void Uart::SendData(uint8_t *data,  uint16_t size)
{
	
		
	
	
	
	HAL_UART_Transmit(&huart1, data, size, HAL_MAX_DELAY);	
}

