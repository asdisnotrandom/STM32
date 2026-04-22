MACH = cortex-m3

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -c -mcpu=$(MACH) -mthumb -O0 -Wall -std=gnu11
LDFLAGS = -nostdlib -T linker.ld -Wl,-Map=final.map

SRCS =	main.c \
		startup.c

OBJS =	$(SRCS:.c=.o)

all: final.elf final.bin

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

final.elf: $(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o final.elf

final.bin: final.elf
		$(OBJCOPY) -O binary final.elf final.bin

clean:
		rm -f $(OBJS) final.elf final.bin final.map

flash: final.bin
		openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program final.bin verify reset exit 0x08000000"