CC = gcc
CFLAGS = -g -O1 -Wall


arrayList: main.o arrayList.o

main.o: main.c arrayList.h

arrayList.o: arrayList.c arrayList.h

clean:
	rm -f *.o
