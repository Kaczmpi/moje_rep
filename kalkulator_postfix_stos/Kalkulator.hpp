#ifndef Kalkulatorr_hpp
#define Matrix_hpp

#include "Stos.hpp"
using namespace std;

class Kalkulator{
	private:
		char* s;
		int size;
	public:
		Kalkulator();
		Kalkulator(char* t);
		Kalkulator(string t);
		Kalkulator(const Kalkulator &source);
		~Kalkulator();
		int policz();
		void dodaj(Stos &stack);
		void odejmij(Stos &stack);
		void pomnoz(Stos &stack);
};

#endif
