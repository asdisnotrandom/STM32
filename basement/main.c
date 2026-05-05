#include "stm32f103.h"

void	delay_ms(uint32_t ms)
{
	Systick->LOAD = 72000 - 1;
	Systick->VAL = 0;

	Systick->CTRL = (1 << 0) | (1 << 2); //0. bitte acip kapatma, 2 de ise islemci hizi secilir
	for (uint32_t i = 0; i < ms; i++)
		while ((Systick->CTRL & (1 << 16)) == 0); //16. bit counterin su an hangi degerde oldugunu verir
	Systick->CTRL = 0;
}

void	SysClock_Cnfg(void)
{
	RCC->CR |= (1 << 16);
	while(!(RCC->CR & (1 << 17)));

	#define	FLASH (*((volatile uint32_t *) 0x40022000))
	FLASH |= (0x2 << 0);

	RCC->CFGR |= (0x4 << 8) | (1 << 16) | (0x7 << 18);

	RCC->CR |= (1 << 24);
	while (!(RCC->CR & (1 << 25)));

	RCC->CFGR |= (0x2 << 0);

	while((RCC->CFGR & (0xC << 0)) != (0x8 << 0));
}

int	main(void)
{
}