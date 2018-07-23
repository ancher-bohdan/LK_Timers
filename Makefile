ifneq ($(KERNELRELEASE),)
obj-m += timer.o
else
KDIR ?= ~/repos/linux

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M+$$PWD clean
endif
