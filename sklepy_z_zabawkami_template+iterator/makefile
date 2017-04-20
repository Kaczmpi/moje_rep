main: main.o vector.o baza.o
	g++ main.o vector.o baza.o -o main
vector.o: vector.cpp vector.h
	g++ -c vector.cpp
baza.o: baza.cpp baza.h
	g++ -c baza.cpp
main.o: main.cpp
	g++ -c main.cpp