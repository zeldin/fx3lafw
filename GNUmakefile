

CC = arm-none-eabi-gcc

WARN = -Wall -Wextra -Werror
OPTIMZE = -g -Os
INCLUDE = -I.

CFLAGS = -std=c11 -mcpu=arm926ej-s -mthumb-interwork -fno-pie $(WARN) $(OPTIMIZE) $(INCLUDE)
LDFLAGS = -static -T bsp/fx3.ld -Wl,-z,max-page-size=4096,-Map,$(basename $@).map

VPATH = bsp

OBJS = main.o gctl.o gpio.o uart.o util.o

all : fx3lafw.img

fx3lafw.img : fx3lafw.elf
	python3 elf2img.py $< $@

clean :
	rm -f fx3lafw.img fx3lafw.elf fx3lafw.map $(OBJS)

fx3lafw.elf : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
