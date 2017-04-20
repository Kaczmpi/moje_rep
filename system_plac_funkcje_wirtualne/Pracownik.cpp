#include "Pracownik.h"
#include <iostream>
using namespace std;

Pracownik::Pracownik(string im, string naz, string ni, string pe){
	imie=im;
	nazwisko=naz;
	nip=ni;
	pesel=pe;
}

void Pracownik::wypisz() const{
	cout<<"Imie "<<imie<<endl<<"Nazwisko "<<nazwisko<<endl<<"NIP "<<nip<<endl<<"PESEL "<<pesel<<endl;
}

void Pracownik::wylicz_zarobki(){
}

Pracownik::~Pracownik(){
	cout<<"Zgin, przepadnij pracowniku"<<endl;
}

Stale::Stale(string im, string naz, string ni, string pe, double pens) : Pracownik(im,naz,ni,pe) {
	pensja=pens;
}

void Stale::wylicz_zarobki(){
}


void Stale::wypisz() const{
	Pracownik::wypisz();
	cout<<"Wynagrodzenie "<<pensja<<endl;
}

Stale::~Stale(){
	cout<<"Zgin, przepadnij zatrudniony na stale"<<endl;
}

Zlecenie::Zlecenie(string im, string naz, string ni, string pe, double staw, double godz) : Pracownik(im,naz,ni,pe){
	stawka=staw;
	godziny=godz;
}

void Zlecenie::wylicz_zarobki(){
	if(godziny>40){
		pensja=godziny*1.5*stawka;
	}
	else{
		pensja=godziny*stawka;
	}
}

void Zlecenie::wypisz() const{
	Pracownik::wypisz();
	cout<<"Stawka godzinowa "<<stawka<<endl<<"Przepracowane godziny "<<godziny<<endl<<"Wynagrodzenie "<<pensja<<endl;
}

Zlecenie::~Zlecenie(){
	cout<<"Zgin, przepadnij zatrudniony na zlecenie"<<endl;
}

Handlowiec::Handlowiec(string im, string naz, string ni, string pe, double sprzed, double pro) : Pracownik(im,naz,ni,pe) {
	sprzedarz=sprzed;
	procent=pro;
}

void Handlowiec::wylicz_zarobki(){
	pensja=sprzedarz*procent;
	pensja=pensja/100;
}

void Handlowiec::wypisz() const{
	Pracownik::wypisz();
	cout<<"Watrosc sprzedarzy "<<sprzedarz<<endl<<"Procent od sprzedarzy "<<procent<<endl<<"Wynagdodzenie "<<pensja<<endl;
}

Handlowiec::~Handlowiec(){
	cout<<"Zgiñ, przepadnij zatrudniony handlowcu"<<endl;
}
