#include <stdint.h>

extern uint32_t	_estack;
extern uint32_t	_sidata;
extern uint32_t	_sdata;
extern uint32_t	_edata;
extern uint32_t	_sbss;
extern uint32_t	_ebss;

void	main(void);
void	Reset_Handler(void);

__attribute__((section(".isr_vector")))
const void*	vectors[] = {
	(void*)&_estack,
	(void*)Reset_Handler
};
void	Reset_Handler(void)
{
	uint32_t	*pSrc = &_sidata;
	uint32_t	*pDest = &_sdata;
	
	while (pDest < &_edata)
		*pDest++ = *pSrc++;
	
	pDest = &_sbss;
	while (pDest < &_ebss)
		*pDest++ = 0;
	
	main();
	while (1);
}