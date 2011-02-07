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

main:main.o DLApplication.o DLDownloadWidgetController.o
	$(CC) -o bin/$(APPNAME) bin/main.o bin/DLApplication.o $(CCARGS)
	ln -sf bin/$(APPNAME) x

main.o:
	$(CC) -o bin/main.o -c src/main.c $(CCARGS)

DLApplication.o:
	$(CC) -o bin/DLApplication.o -c src/DLApplication.c $(CCARGS)

DLDownloadWidgetController.o:
	$(CC) -o bin/DLDownloadWidgetController.o -c src/controllers/DLDownloadWidgetController.c $(CCARGS)

clean:
	rm -f bin/*
	rm -f x

.PHONY: clean
