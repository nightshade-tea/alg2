SHELL = /bin/bash

COMMON_FLAGS = -pipe \
	       -ggdb3 -Wstrict-overflow=5 -fstack-protector-all \
	       -W -Wall -Wextra \
	       -Wcast-align \
	       -Wcast-qual \
	       -Wconversion \
	       -Wfloat-equal \
	       -Wformat-y2k \
	       -Winit-self \
	       -Winline \
	       -Winvalid-pch \
	       -Wmissing-declarations \
	       -Wmissing-field-initializers \
	       -Wmissing-format-attribute \
	       -Wmissing-include-dirs \
	       -Wmissing-noreturn \
	       -Wnormalized=nfc \
	       -Woverlength-strings \
	       -Wpacked \
	       -Wpointer-arith \
	       -Wredundant-decls \
	       -Wshadow \
	       -Wsign-compare \
	       -Wstack-protector \
	       -Wstrict-aliasing=2 \
	       -Wundef \
	       -Wunsafe-loop-optimizations \
	       -Wvolatile-register-var \

CFLAGS  = $(COMMON_FLAGS) \
          -std=c99 \
	  -Wbad-function-cast \
	  -Wmissing-prototypes \
	  -Wnested-externs \
	  -Wold-style-definition \
	  -Wstrict-prototypes \
	  -Wwrite-strings

#------------------------------------------------------------------------------
.PHONY : all clean

#------------------------------------------------------------------------------
all : testa

avalia.o testa.o : %.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

testa : testa.o avalia.o 
	$(CC) $(CFLAGS) -o $@ $^ -lm


#------------------------------------------------------------------------------
clean :
	$(RM) teste *.o
