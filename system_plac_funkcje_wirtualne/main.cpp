#include "Pracownik.h"
#include <iostream>
#include <vector>
using namespace std;

int menu(){
	int wybor;
	cout<<"Menu"<<endl;
	cout<<"Wpisz numer oznaczajacy dzialanie:"<<endl;
	cout<<"1 - Dodaj pracownika na stale"<<endl;
	cout<<"2 - Dodaj praconika na zlecenie"<<endl;
	cout<<"3 - Dodaj handlowca" << endl;
	cout<<"4 - Wyswietl pracownikow" << endl;
	cout<<"5 - Wyjscie" << endl;
	cin>>wybor;
	return wybor;
}

int main(){
	string imie,nazwisko,nip,pesel;
	double pens,stawka,godziny,sprzedarz,procent;
	int k=1;
	int dzialanie;
	vector <Pracownik*> baza;
	int dlugosc;
	while(k==1){
		dzialanie=menu();
		switch(dzialanie){
			case 1:
				cout<<"Podaj:"<<endl;
				cout<<"imie "; cin>>imie; cout<<endl;
				cout<<"nazwisko "; cin>>nazwisko; cout<<endl;
				cout<<"nip "; cin>>nip; cout<<endl;
				cout<<"pesel "; cin>>pesel; cout<<endl;
				cout<<"pensje "; cin>>pens; cout<<endl;
				baza.push_back(new Stale(imie,nazwisko,nip,pesel,pens));
				break;
			case 2:
				cout<<"Podaj:"<<endl;
				cout<<"imie "; cin>>imie; cout<<endl;
				cout<<"nazwisko "; cin>>nazwisko; cout<<endl;
				cout<<"nip "; cin>>nip; cout<<endl;
				cout<<"pesel "; cin>>pesel; cout<<endl;
				cout<<"stawke godzinowa "; cin>>stawka; cout<<endl;
				cout<<"liczbe przepracowanych godzin "; cin>>godziny; cout<<endl;
				baza.push_back(new Zlecenie(imie,nazwisko,nip,pesel,stawka,godziny));
				break;
			case 3:
				cout<<"Podaj:"<<endl;
				cout<<"imie "; cin>>imie; cout<<endl;
				cout<<"nazwisko "; cin>>nazwisko; cout<<endl;
				cout<<"nip "; cin>>nip; cout<<endl;
				cout<<"pesel "; cin>>pesel; cout<<endl;
				cout<<"wartosc sprzedanych towarow "; cin>>sprzedarz; cout<<endl;
				cout<<"procent od sprzedarzy "; cin>>procent; cout<<endl;
				baza.push_back(new Handlowiec(imie,nazwisko,nip,pesel,sprzedarz,procent));
				break;
			case 4:
				for(int i=0;i<baza.size();i++){
					baza[i]->wylicz_zarobki();
					baza[i]->wypisz();
					cout<<endl;
				}
				break;
			case 5:
				k=0;
		}
	}
	dlugosc=baza.size();
	for (int i=0;i<dlugosc;i++){
		delete baza[i];
	}
}
