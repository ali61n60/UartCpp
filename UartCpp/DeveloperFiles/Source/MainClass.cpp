#include "./DeveloperFiles/Header/MainClass.h"
//This function is being called repeatedly in a loop from main 
void MainClass::Init()
{	
		this->uart.EnableUsartRxInterrupt();
}

void MainClass::RepeatingLoop()
{	
	this->led.BlinkPollingMode(1000);
}

