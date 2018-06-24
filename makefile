all: tp0 clean
tp0: main.o scanner.o
	gcc -o tp0 main.o scanner.o

main.o: main.c scanner.h
	gcc -c main.c

scanner.o: scanner.c scanner.h
	gcc -c scanner.c

clean: 
	rm -f *.o
