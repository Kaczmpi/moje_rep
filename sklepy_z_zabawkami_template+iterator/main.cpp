#include <fstream>
#include "vector.h"
#include "baza.h"

int menu(){
	int wybor;
	cout<<"Menu"<<endl;
	cout<<"Wpisz numer oznaczajacy dzialanie:"<<endl;
	cout<<"1 - Dodaj zabawke"<<endl;
	cout<<"2 - Wyswietl dane sklepow" << endl;
	cout<<"3 - Wyswietl zabawki" << endl;
	cout<<"4 - Wyjscie" << endl;
	cin>>wybor;
	return wybor;
}

int main(){
	vector<sklepy> shops;
	vector<baza> base;
	iter<sklepy> it_shops(shops);
	iter<baza> it_base(base);
	ifstream plik;
	plik.open("dane.txt");
	string naz;
	string ul;
	string zab;
	int num;
	int k=1;
	int dzialanie;
	double cen;
	while(!plik.eof()){
		plik>>naz>>ul>>num;
		shops.push_back(sklepy(naz,ul,num));
	}
	while(k==1){
		dzialanie=menu();
		switch(dzialanie){
			case 1:
				cout<<"Podaj:"<<endl;
				cout<<"nazwe sklepu "; cin>>naz; cout<<endl;
				cout<<"nazwe zabawki "; cin>>zab; cout<<endl;
				cout<<"cene "; cin>>cen; cout<<endl;
				base.push_back(baza(zab,naz,cen,shops));
				break;
			case 2:
				for(it_shops=shops.pocz();it_shops!=shops.kon();it_shops++){
					cout<<*it_shops<<endl;
				}
				break;
			case 3:
				for(it_base=base.pocz();it_base!=base.kon();it_base++){
					cout<<*it_base<<endl;
				}
				break;
			case 4:
				k=0;
				break;
			default:
				cout<<"Nieprawidlowa komenda";
				break;
		}
	}
	plik.close();
}
