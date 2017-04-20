main: main.o life.o array.o
	gcc main.o life.o array.o -o main
main.o: main.c
	gcc -Wall -c main.c -o main.o
life.o: life.c life.h
	gcc -Wall -c life.c -o life.o
array.o: array.c array.h
	gcc -Wall -c array.c -o array.o
	
.Phony: clean

clean:
	rm -f main.o life.o array.o