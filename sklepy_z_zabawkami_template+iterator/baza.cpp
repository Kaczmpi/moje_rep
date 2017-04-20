#include "baza.h"

sklepy::sklepy(string naz,string ul,int num){
	nazwa=naz;
	ulica=ul;
	numer=num;
}

sklepy::sklepy(const sklepy& sklep){
	nazwa=sklep.nazwa;
	ulica=sklep.ulica;
	numer=sklep.numer;
}

sklepy::~sklepy(){
}

std::ostream& operator<< (std::ostream& out,sklepy sklep){
	out.width(20);
	out<<left<<sklep.nazwa;
	out.width(5);
	out<<left<<"ul.";
	out.width(20);
	out<<left<<sklep.ulica;
	out.width(5);
	out<<left<<sklep.numer<<endl;
	return out;
}

string sklepy::naz(){
	return nazwa;
}

sklepy & sklepy::operator =(const sklepy& sklep){
	nazwa=sklep.nazwa;
	ulica=sklep.ulica;
	numer=sklep.numer;
	return (*this);
}

bool sklepy::operator ==(string naz){
	if(nazwa==naz){
		return true;
	}
	return false;
}

baza::baza(string naz,string skl,double cen,vector<sklepy>& wekt){
	nazwa=naz;
	cena=cen;
	ilosc=0;
	dane=new sklepy*[10];
	for(int i=0;i<wekt.siz();i++){
		if(wekt[i].naz()==skl){
			dane[ilosc]=wekt.adr(i);
			ilosc++;
		}
	}
}

baza::baza(const baza& base){
	nazwa=base.nazwa;
	cena=base.cena;
	ilosc=base.ilosc;
	dane=new sklepy*[10];
	for(int i=0;i<ilosc;i++){
		dane[i]=base.dane[i];
	}
}

baza::~baza(){
	delete[] dane;
}

std::ostream& operator<< (std::ostream& out, baza base){
	for(int i=0;i<base.ilosc;i++){
		out.width(20);
		out<<left<<base.nazwa;
		out.width(10);
		out<<left<<base.cena;
		out<<*base.dane[i]<<endl;
	}
	return out;
}

string baza::naz(){
	return nazwa;
}

baza& baza::operator =(const baza& base){
	nazwa=base.nazwa;
	cena=base.cena;
	ilosc=base.ilosc;
	dane=new sklepy*[10];
	for(int i=0;i<ilosc;i++){
		dane[i]=base.dane[i];
	}
	return (*this);
}
