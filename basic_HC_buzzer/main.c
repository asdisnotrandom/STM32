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

	GPIOA->CRL &= ~(0xF << 12);
	GPIOA->CRL |= (0x2 << 12);

	GPIOA->ODR |= (1 << 3);
	GPIOC->ODR |= (1 << 13);

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
		if (duration < 7000 && duration > 20)
		{
			GPIOA->ODR &= ~(1 << 3);
			GPIOC->ODR &= ~(1 << 13);

			delay_ms(10000);

			GPIOA->ODR |= (1 << 3);
			GPIOC->ODR |= (1 << 13);
			for (volatile uint32_t i = 0; i < (duration * 40) + 20000; i++);
		}
		else
		{
			GPIOA->ODR |= (1 << 3);
			GPIOC->ODR |= (1 << 13);
		}
	}
}