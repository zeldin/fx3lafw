

CC = arm-none-eabi-gcc

CGENFLAGS = -mcpu=arm926ej-s -mthumb-interwork -fno-pie
WARN = -Wall -Wextra -Werror
OPTIMIZE = -g -Os
INCLUDE = -I.
GENDEP = -MMD -MP
DEFS = -DPLL_FBDIV=20

CFLAGS = -std=c11 $(CGENFLAGS) $(WARN) $(OPTIMIZE) $(INCLUDE) $(GENDEP) $(DEFS)
LDFLAGS = -static -nostartfiles -T bsp/fx3.ld -Wl,-z,max-page-size=4096,-Map,$(basename $@).map

VPATH = bsp

OBJS = main.o usb.o gpif.o gctl.o gpio.o uart.o util.o dma.o irq.o cache.o vectors.o descriptors.o acquisition.o

all : fx3lafw-cypress-fx3.fw

fx3lafw-cypress-fx3.fw : fx3lafw.elf
	python3 elf2img.py $< $@

clean :
	rm -f fx3lafw.img fx3lafw.elf fx3lafw.map $(OBJS) $(OBJS:.o=.d)

fx3lafw.elf : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

-include $(OBJS:.o=.d)
