

CC = arm-none-eabi-gcc

WARN = -Wall -Wextra -Werror
OPTIMZE = -g -Os
INCLUDE = -I.

CFLAGS = -std=c11 -mcpu=arm926ej-s -mthumb-interwork -fno-pie $(WARN) $(OPTIMIZE) $(INCLUDE)
LDFLAGS = -static -nostartfiles -T bsp/fx3.ld -Wl,-z,max-page-size=4096,-Map,$(basename $@).map

VPATH = bsp

OBJS = main.o usb.o gctl.o gpio.o uart.o util.o dma.o irq.o cache.o vectors.o

all : fx3lafw.img

fx3lafw.img : fx3lafw.elf
	python3 elf2img.py $< $@

clean :
	rm -f fx3lafw.img fx3lafw.elf fx3lafw.map $(OBJS)

fx3lafw.elf : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
