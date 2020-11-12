#include <stdint.h>
#include <./CubeFiles/Inc/main.h>

class Uart
{	
	uint8_t uartBuffer[1];
	
	
public:
	void UsartPollingModeExample();
	void EnableUsartRxInterrupt();
	void SendData(uint8_t *data,uint16_t size);
	void UartRxCompleteInterrup(UART_HandleTypeDef *huart1);
};