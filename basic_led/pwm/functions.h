#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"
//LED
# define	PIN_SET(PORT, PIN)		(PORT->BSRR = (1 << PIN))
# define	PIN_RESET(PORT, PIN)	(PORT->BSRR = (1 << (PIN + 16)))
# define	PIN_TOGGLE(PORT, PIN)	(PORT->ODR ^= (1 << PIN))
# define	PIN_READ(PORT, PIN)		(PORT->IDR & (1 << PIN) ? 1 : 0)
# define	CNFGR_LED_PIN(PORT, PIN)	do \
										{	\
											_Static_assert((PIN) >= 0 && (PIN) <= 15, "HATA: Pin numarasi 0 ile 15 arasinda olmali!");  \
											if ((PIN) < 8) \
											{ \
												PORT->CRL &= ~(0xF << ((PIN & 0x7) * 4)); \
												PORT->CRL |= (0x2 << ((PIN & 0x7) * 4));  \
											}  \
											else if ((PIN) >= 8 && (PIN) < 16)  \
											{  \
												PORT->CRH &= ~(0xF << (((PIN) - 8) * 4));  \
												PORT->CRH |= (0x2 << (((PIN) - 8) * 4));  \
											}  \
										}while(0)
#endif