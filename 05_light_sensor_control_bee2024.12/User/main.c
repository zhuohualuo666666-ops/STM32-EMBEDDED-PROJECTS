#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"



int main(void)
{
	Buzzer_init();
	LightSensor_Init();
	
	while(1)
	{
		if(LightSensor_GET()==1)
		{
		    Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}
	}
}
