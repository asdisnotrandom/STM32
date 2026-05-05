#include "functions.h"
#include "structs.h"

void	delay_us(uint32_t us)
{
	Systick->LOAD = 72 - 1;
	Systick->VAL = 0;

	Systick->CTRL = (1 << 0) | (1 << 2); //0. bitte acip kapatma, 2 de ise islemci hizi secilir
	for (uint32_t i = 0; i < us; i++)
		while ((Systick->CTRL & (1 << 16)) == 0); //16. bit sayacin 0 a gelip gelmedigini verir.
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
	SysClock_Cnfg();

	RCC->APB2ENR |= (1 << 4);

	CNFGR_LED_PIN(GPIOC, 13);

	int	brightness = 11;
	int	step = 10;
	while (1)
	{
		PIN_RESET(GPIOC, 13);
		delay_us(brightness);
		PIN_SET(GPIOC, 13);
		delay_us(1000 - brightness);
		static int	counter = 0;
		if (++counter > 10)
		{
			brightness += step;
			if(brightness <= 10 || brightness >= 990) step = -step;
			counter = 0;
		}
	}
}