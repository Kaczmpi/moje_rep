#include "Stos.hpp"
using namespace std;

Stos :: Stos(){
	value=new int[1];
	if(value==NULL){
		dlugosc=0;
		throw bad_alloc();
	}
	else{
		dlugosc=1;
		value[0]=0;
	}
}

Stos :: Stos(int wymiar){
	dlugosc=wymiar;
	value=new int[wymiar];
	if(value==NULL){
		dlugosc=0;
		throw bad_alloc();
	}
	for(int i=0;i<dlugosc;i++){
		value[i]=0;
	}	
}

Stos :: Stos(const Stos &source){
	dlugosc=source.dlugosc;
	value=new int[dlugosc];
	if(value==NULL){
		dlugosc=0;
		throw bad_alloc();
	}
	for(int i=0;i<dlugosc;i++){
		value[i]=source.value[i];
	}
	
}

Stos :: ~Stos(){
	delete[] value;
}

Stos Stos :: push(int a){
	int i;
	dlugosc++;
	Stos nowy(dlugosc);
	for(i=0;i<dlugosc-1;i++){
		nowy.value[i]=value[i];
	}
	nowy.value[dlugosc-1]=a;
	for(i=0;i<dlugosc;i++){
		value[i]=nowy.value[i];
	}
	delete[] nowy.value;
	return (*this);
}

int Stos :: top(){
	int a;
	a=value[dlugosc-1];
	return a;
}

Stos Stos :: pop(){
	int i;
	dlugosc--;
	Stos nowy(dlugosc);
	for(i=0;i<dlugosc;i++){
		nowy.value[i]=value[i];
	}
	for(i=0;i<dlugosc;i++){
		value[i]=nowy.value[i];
	}	
	delete[] nowy.value;
	return (*this);
}

int Stos :: size(){
	return dlugosc-1;
}

bool Stos :: isempty(){
	if(dlugosc==1){
		return 1;
	}
	else{return 0;}
}

