TARGET = mygame
OBJS = main.o callbacks.o

INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = My PSP Game

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak