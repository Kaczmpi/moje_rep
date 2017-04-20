Matrix_main: Matrix_main.o Vector.o Matrix.o
	g++ Matrix_main.o Vector.o Matrix.o -o Matrix_main
Vector.o: Vector.cpp Vector.hpp
	g++ -c Vector.cpp
Matrix.o: Matrix.cpp Matrix.hpp
	g++ -c Matrix.cpp

Matrix_main.o: Matrix_main.cpp
	g++ -c Matrix_main.cpp