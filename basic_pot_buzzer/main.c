#include "stm32f103.h"

void	delay_ms(volatile uint32_t ms)
{
	ms *= 6;
	while(ms--);
}

int	main(void)
{
	RCC->APB2ENR |= (1 << 2) | (1 << 9);

	GPIOA->CRL &= ~(0xF << 0);

	GPIOA->CRL &= ~(0xF << 12);
	GPIOA->CRL |= (0x2 << 12);

	ADC1->CR2 |= (1 << 0);
	delay_ms(100);
	ADC1->SQR3 &= ~(0x1F);

	GPIOA->ODR |= (1 << 3);
	while (1)
	{
		ADC1->CR2 |= (1 << 0);
		while(!(ADC1->SR & (1 << 1)));
		uint32_t	pot_val = ADC1->DR;
		if (pot_val > 100)
		{
			GPIOA->ODR &= ~(1 << 3);
			delay_ms(8000);
			GPIOA->ODR |= (1 << 3);
			for (volatile uint32_t i = 0; i < ((4095 - pot_val) * 50) + 10000; i++);
		}
		else
		{
			GPIOA->ODR |= (1 << 3);
		}
	}
}