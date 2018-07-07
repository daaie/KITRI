INCLUDEDIR :=/root/2.PXA255/2.Kernel/linux-2.4.19-pro3_usb20/include
CROSS_COMPILE := arm-linux-

CFLAGS :=-DEXPORT_SYMTAB -D__KERNEL__ -DMODULE -Wall -O2 -I$(INCLUDEDIR) -lpthread

CC = $(CROSS_COMPILE)gcc 
LD = $(CROSS_COMPILE)ld

all : key_gpio.o acidrain

key_gpio.o:
	$(CC) $(CFLAGS) -c key_gpio.c -o key_gpio.o

acidrain : acidrain.c
	$(CC) -o acidrain acidrain.c

clean :
	rm -f *.o
	rm -f acidrain

