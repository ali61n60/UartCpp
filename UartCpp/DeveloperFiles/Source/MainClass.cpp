#include "./DeveloperFiles/Header/MainClass.h"

//This function is being called repeatedly in a loop from main 
void MainClass::RepeatingLoop(int delayTime)
{	
	this->led.BlinkPollingMode(delayTime);
}

MainClass::MainClass()
{
	this->uart.EnableUsartRxInterrupt();
}

