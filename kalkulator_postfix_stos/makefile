main: main.o Stos.o Kalkulator.o
	g++ main.o Stos.o Kalkulator.o -o main
Stos.o: Stos.cpp Stos.hpp
	g++ -c Stos.cpp
Kalkulator.o: Kalkulator.cpp Kalkulator.hpp
	g++ -c Kalkulator.cpp

main.o: main.cpp
	g++ -c main.cpp