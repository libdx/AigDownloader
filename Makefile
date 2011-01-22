APPNAME=downloader
#CC=colorgcc
CC = gcc

#CFLAGS = -export-dynamic
DEBUG = -Wall -g
LIBS = `pkg-config --libs gtk+-2.0`

PACKAGES = gtk+-2.0 gmodule-2.0
PKGCONFIG = pkg-config

CFLAGS += `$(PKGCONFIG) --cflags $(PACKAGES)`
LIBS = `$(PKGCONFIG) --libs $(PACKAGES)`

CCARGS = $(CFLAGS) $(LIBS) $(DEBUG)

main:preper main.o
	$(CC) -o bin/$(APPNAME) bin/main.o $(CCARGS)
	ln -sf bin/$(APPNAME) x

main.o:
	$(CC) -o bin/main.o -c src/main.c $(CCARGS)

preper:
	$(shell if ! test -d bin; then mkdir bin; fi)

clean:
	rm -f bin/$(APPNAME)
	rm -f bin/main.o
	rm -rf bin
	rm -f x

#debug:
#	$(CC) -o /tmp/widgetController.h -E src/AIWidgetController.h $(CFLAGS) $(LIBS)

.PHONY: clean
