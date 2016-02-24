PROG_NAME = libtftgfx
PERFIX=/usr

CC = gcc
CFLAGS = -Wall -O0
LDFLAGS =

.PHONY:clean rebuild

all:$(PROG_NAME).so $(PROG_NAME).a

clean:
	@echo Cleaning workspace.....
	-rm ./*.o ./$(PROG_NAME).so ./$(PROG_NAME).a

rebuild:clean all

install:all
	install --mode=0644 libtftgfx.so $(PERFIX)/lib/
	install --mode=0644 libtftgfx.a  $(PERFIX)/lib/
	install --mode=0644 libtftgfx.h  $(PERFIX)/include/

uninstall:
	-rm $(PERFIX)/lib/libtftgfx.so
	-rm $(PERFIX)/lib/libtftgfx.a
	-rm $(PERFIX)/include/libtftgfx.h

$(PROG_NAME).so:libtftgfx.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) -shared -fPIC

$(PROG_NAME).a:libtftgfx.o
	ar -rcs $@ $^



libtftgfx.o: libtftgfx.c libtftgfx.h
