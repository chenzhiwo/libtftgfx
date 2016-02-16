PROG_NAME = libtftgfx

CC = gcc
CFLAGS = -Wall -O0
LDFLAGS = 

.PHONY:clean rebuild

all:$(PROG_NAME).so $(PROG_NAME).a

clean:
	@echo Cleaning workspace.....
	-rm ./*.o ./$(PROG_NAME).so ./$(PROG_NAME).a

rebuild:clean all

$(PROG_NAME).so:libtftgfx.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) -shared -fPIC

$(PROG_NAME).a:libtftgfx.o
	ar -rcs $@ $^ 



libtftgfx.o: libtftgfx.c libtftgfx.h
