#include "./DeveloperFiles/Header/Led.h"

void Led::BlinkPollingMode(uint32_t delay)
{
	this->TurnOnLed();
	HAL_Delay(delay);
	this->TurnOffLed();
	HAL_Delay(delay);	
}


void Led::TurnOnLed()
{
	HAL_GPIO_WritePin(MyPort, myPin, GPIO_PIN_RESET);
}

void Led::TurnOffLed()
{
	HAL_GPIO_WritePin(MyPort, myPin, GPIO_PIN_SET);  
}

void Led::ToggleLed()
{
	HAL_GPIO_TogglePin(MyPort, myPin);
}