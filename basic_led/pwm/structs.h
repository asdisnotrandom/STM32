#ifndef STM32F103_H
#   define STM32F103_H
#   include <stdint.h>

typedef struct
{
	volatile uint32_t	CR;			//temel baslatici, 8 ya da 72mhz baslangicindan da sorumlu
	//HSI icin 0, HSIready icin 1; HSE icin 16, HSEready icin 17; PLL icin 24, PLLready icin 25 
	volatile uint32_t	CFGR;		//temel hizin (mesela 8mhz) kac ile carpilacagi (hiz ayari) yapilir
	volatile uint32_t	CIR;		//hata registeridir, islemcide herhangi bir sikinti oldugunda degeri degisir.
	volatile uint32_t	APB2RSTR;	//apb2 yolu icin resetleme registeri, kurtarma
	volatile uint32_t	APB1RSTR;	//apb1 yolu icin resetleme registeri, kurtarma
	volatile uint32_t	AHBENR;		//DMA, SDIO, CRC yolu
	volatile uint32_t	APB2ENR;	//72mhzye cikan yol; gpio, spi1, usart1, adc
	volatile uint32_t	APB1ENR;	//en fazla 36 mhz ye cikan yol; i2c1, i2c2, spi2, timer ve uart2/3
	volatile uint32_t	BDCR;		//uykusuz, saat ve log sayaci, elektrigi kessen de ayakta
	volatile uint32_t	CSR;		//yazilimin neden ve nerede coktugunu anlamak icindir, lsi(40khz) de acar
}	RCC_t;	//islemci ana saati

typedef struct
{
	volatile uint32_t	CRL;	//0-7 arasi pin
	volatile uint32_t	CRH;	//8-15 arasi pin
	volatile uint32_t	IDR;	//read only, sensor okuması
	volatile uint32_t	ODR;	//veri gönderilen alan
	volatile uint32_t	BSRR;	//pine odr uzerinden dolayli degil direkt atama yapar
	volatile uint32_t	BRR;	//bsrrnin 0 yapan hali, bsrr halleder
	volatile uint32_t	LCKR;	//crl ve crh kilitler, hata sonucu deger degisimi onlenir
}	GPIO;	//general input outputlar

typedef struct
{
	volatile uint32_t	CTRL;	//saati ac,kapat; hiz kaynagi
	volatile uint32_t	LOAD;	//hedef deger
	volatile uint32_t	VAL;	//guncel deger
	volatile uint32_t	CALIB;	//kalibrasyon
}	Systick_t;

#	define	RCC		((RCC_t *) 0x40021000)
#	define	GPIOA	((GPIO *) 0x40010800)
#	define	GPIOB	((GPIO *) 0x40010C00)
#	define	GPIOC	((GPIO *) 0x40011000)
#	define	Systick	((Systick_t *) 0xE000E010)

#endif