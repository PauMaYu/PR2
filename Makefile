all: UNO.exe

baraja.o: baraja.c dades.h baraja.h
	gcc -c -g baraja.c

lectura.o: lectura.c lectura.h
	gcc -c -g lectura.c

UNO.o: UNO.c dades.h baraja.h
	gcc -c -g UNO.c

UNO.exe: UNO.o baraja.o lectura.o
	gcc UNO.o baraja.o lectura.o -o UNO.exe
