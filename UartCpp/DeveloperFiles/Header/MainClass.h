#include "Led.h"
#include "Uart.h"

class MainClass
{
	
public:
	Uart uart;
	Led led;
	void Init();
	void RepeatingLoop();
	
};