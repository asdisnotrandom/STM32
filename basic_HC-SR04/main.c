#include "stm32f103.h"

void	delay_ms(volatile uint32_t ms)
{
	ms *= 6;
	while (ms--);
}

int	main(void)
{
	RCC->APB2ENR |= (1 << 2) | (1 << 4);

	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= (0x2 << 20);

	GPIOA->CRL &= ~(0xF << 4);
	GPIOA->CRL |= (0x2 << 4);

	GPIOA->CRL &= ~(0xF << 8);
	GPIOA->CRL |= (0x4 << 8);
	while (1)
	{
		GPIOA->ODR &= ~(1 << 1);
		delay_ms(2);
		GPIOA->ODR |= (1 << 1);
		delay_ms(10);
		GPIOA->ODR &= ~(1 << 1);

		while (!(GPIOA->IDR & (1 << 2)));

		uint32_t	duration = 0;
		while (GPIOA->IDR & (1 << 2))
		{
			duration++;
			delay_ms(1);
			if (duration > 20000)
				break;
		}

		GPIOC->ODR &= ~(1 << 13);
		for (volatile uint32_t i = 0; i < duration * 100; i++);

		GPIOC->ODR |= (1 << 13);
		for (volatile uint32_t i = 0; i < duration * 100; i++);
	}
}