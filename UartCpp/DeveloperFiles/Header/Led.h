#include <stdint.h>
#include <./CubeFiles/Inc/main.h>

class Led
{
	GPIO_TypeDef *MyPort = GPIOC;
	uint16_t myPin = GPIO_PIN_13;
	
	void TurnOnLed();  
	void TurnOffLed();
	
	
	
public:
	/*
	 @delay Delay time in millisecond
	 	 */
	void BlinkPollingMode(uint32_t delay);
	void ToggleLed();
};