/* hafıza dağılımı */
MEMORY
{
	FLASH (rx)	: ORIGIN = 0x08000000, LENGTH = 64K
	RAM (xrw)	: ORIGIN = 0x20000000, LENGTH = 20K
}

/* ilk fonksiyon */
ENTRY(Reset_Handler)

/* ram sonu başlayacak stack */
_estack = 0x20005000;

SECTIONS
{
	/* arm mimarisine optimizasyon */
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	}	>FLASH

	/* C Kodları */
	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text.*)
		. = ALIGN(4);
	}	>FLASH

	/* Read only sabitler */
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
	}	>FLASH

	/* .datanın baslayacagi yer tutulur. */
	_sidata = LOADADDR(.data);
	/* baslangic degerine sahip degiskenler */
	.data :
	{
		. = ALIGN(4);
		_sdata = .;		/* ramde data baslangici */
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_edata = .;		/* ramde data bitisi */
	}	>RAM AT> FLASH
	
	/* baslangic degeri olmayan degiskenler */
	.bss :
	{
		. = ALIGN(4);
		_sbss = .;		/* ramde bss baslangici */
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;		/* ramde bss bitisi */
	}	>RAM
}