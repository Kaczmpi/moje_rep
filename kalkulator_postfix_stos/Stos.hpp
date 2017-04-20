#ifndef Stos_hpp
#define Stos_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <new>
using namespace std;

class Stos{
	private:
		int *value;
		int dlugosc;
	public:
		Stos();
		Stos(int wymiar);
		Stos(const Stos &source);
		~Stos();
		Stos push(int a);
		int top();
		Stos pop();
		bool isempty();
		int size();
};

#endif
