#ifndef STM32F103_H
#   define STM32F103_H

    #include <stdint.h>

    typedef	struct
    {
        volatile uint32_t	CR;
        volatile uint32_t	CFGR;
        volatile uint32_t	CIR;
        volatile uint32_t	APB2RSTR;
        volatile uint32_t	APB1RSTR;
        volatile uint32_t	AHBENR;
        volatile uint32_t	APB2ENR;
        volatile uint32_t	APB1ENR;
    }	RCC_TypeDef;
    typedef	struct
    {
        volatile uint32_t	CRL;
        volatile uint32_t	CRH;
        volatile uint32_t	IDR;
        volatile uint32_t	ODR;
        volatile uint32_t	BSRR;
        volatile uint32_t	BRR;
        volatile uint32_t	LCKR;
    }	GPIO_TypeDef;

#   define RCC     ((RCC_TypeDef *) 0x40021000)
#   define GPIOA   ((GPIO_TypeDef *) 0x40010800)
#   define GPIOB   ((GPIO_TypeDef *) 0x40010C00)
#   define GPIOC   ((GPIO_TypeDef *) 0x40011000)

#endif