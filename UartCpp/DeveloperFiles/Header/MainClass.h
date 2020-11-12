#include "Led.h"
#include "Uart.h"

class MainClass
{
	
public:
	MainClass();
	Uart uart;
	Led led;
	
	void RepeatingLoop(int delay);
	
};