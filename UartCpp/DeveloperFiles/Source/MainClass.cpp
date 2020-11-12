#include "./DeveloperFiles/Header/MainClass.h"

//This function is being called repeatedly in a loop from main 
void MainClass::RepeatingLoop()
{	
	this->led.BlinkPollingMode(50);
}

MainClass::MainClass()
{
	this->uart.EnableUsartRxInterrupt();
}

