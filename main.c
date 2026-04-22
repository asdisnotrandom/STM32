#include "stm32f103.h"

int	main(void)
{
	RCC->APB2ENR |= (1 << 4);
	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= (0x2 << 20);

	while (1)
	{
		GPIOC->ODR ^= (1 << 13);
		for (volatile uint32_t i = 0; i < 500000; i++);
	}
}