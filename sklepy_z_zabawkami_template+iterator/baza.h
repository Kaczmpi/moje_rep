#ifndef baza_h
#define baza_h

#include "vector.h"

using namespace std;

class sklepy{
	private:
		string nazwa;
		string ulica;
		int numer;
	public:
		sklepy(){};
		sklepy(string naz,string ul,int num);
		sklepy(const sklepy& sklep);
		~sklepy();
		friend std::ostream& operator<<(std::ostream& out, sklepy sklep);
		string naz();
		sklepy & operator =(const sklepy& sklep);
		bool operator ==(string naz);
};

class baza{
	friend class sklepy;
	private:
		string nazwa;
		double cena;
		sklepy **dane;
		int ilosc;
	public:
		baza(){dane=NULL;};
		baza(string skl,string naz,double cen,vector<sklepy>& wekt);
		baza(const baza& base);
		~baza();
		friend std::ostream& operator<< (std::ostream& out, baza base);
		string naz();
		baza & operator =(const baza& base);
};

#endif
