#include "stm32f10x.h"                  
#include "HC-SR04.h"

// ---------------------- implementação das funções da biblioteca do sensor ----------------------


// configura as gpio's que o sensor será conectado
void gpioConfig()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	GPIOA->CRL |= 0x44444434;
	GPIOA->CRH |= 0x344434BB;
	GPIOB->CRL |= 0x43444444;
	GPIOB->BSRR = GPIO_BSRR_BR6;
}

void timerConfig() 
{		
	TIM1->PSC = 72-1;
	TIM1->ARR = 0xffff;
	TIM1->CCMR1 |= 0x4141;
	TIM1->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC2P;
	TIM1->CR1 |= TIM_CR1_CEN;
}

int StartReading()
{
	GPIOB->BSRR = GPIO_BSRR_BR6;
	
	GPIOB->BSRR = GPIO_BSRR_BS6;
	SystickDelayUs(10);
	GPIOB->BSRR = GPIO_BSRR_BR6;
}

void SystickDelayUs(int n)
{
	SysTick->LOAD = 9 -1;
	SysTick->VAL = 0;
	SysTick->CTRL = SysTick_CTRL_ENABLE;
	
	for (int i = 0; i<n; i++)
	{
		while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG) == 0);
	}
	
	SysTick->CTRL = 0;
}

void SystickDelayMs(int n)
{
	SysTick->LOAD = 9000 -1;
	SysTick->VAL = 0;
	SysTick->CTRL = SysTick_CTRL_ENABLE;
	
	for (int i = 0; i<n; i++)
	{
		while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG) == 0);
	}
	
	SysTick->CTRL = 0;
}

// -------------------- fim da implementação das funções da biblioteca do sensor ----------------------