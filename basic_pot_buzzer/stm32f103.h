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
    typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t JSQR;
    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;
    volatile uint32_t DR;
} ADC_TypeDef;

#	define ADC1		((ADC_TypeDef *) 0x40012400)
#   define RCC		((RCC_TypeDef *) 0x40021000)
#   define GPIOA	((GPIO_TypeDef *) 0x40010800)
#   define GPIOB	((GPIO_TypeDef *) 0x40010C00)
#   define GPIOC	((GPIO_TypeDef *) 0x40011000)

#endif