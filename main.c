#include "stm32f10x.h"                  // Device header
#include "stdint.h"											// Standard int library
#include "HC-SR04.h"										// Sensor library

//PA1 - Trigger
//PB0 - Echo

int timeStamp1;
int timeStamp2;
int diference;
int distance;

int main (void)
{
	gpioConfig();
	timerConfig();
	
	while(1)
	{
		
//		StartReading();
//		
//		timeStamp1 = TIM1->CCR1;
//		timeStamp2 = TIM1->CCR2;
//		
//		SystickDelayMs(100);
//		
//	
	StartReading();		
		
		if(TIM1->SR & 2)
		{
			timeStamp1 = TIM1->CCR1;
		}
		
		if(TIM1->SR & 4)
		{
			timeStamp2 = TIM1->CCR2;
			diference = timeStamp2 - timeStamp1;
			distance = diference / 58;
		}
		
		SystickDelayMs(100);
	}
}
