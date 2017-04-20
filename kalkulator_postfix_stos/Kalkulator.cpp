#include "Kalkulator.hpp"
using namespace std;

Kalkulator :: Kalkulator(){
	cout<<"Nie podano wyra¿enia";
}

Kalkulator :: Kalkulator(char* t){
	size=0;
	int k=0;
	int i;
	for(i=0;t[i]!='\0';i++){
		if(t[i]!=' '){
			size++;
		}
	}
	s=new char[size+1];
	if(s==NULL){
		size=0;
		throw bad_alloc();
	}
	else{
		for(i=0;t[i]!='\0';i++){
			if(t[i]!=' '){
				s[k]=t[i];
				k++;
			}
		}
		s[k]='\0';
	}
}

Kalkulator :: Kalkulator(const Kalkulator &source){
	size=source.size;
	s=new char[size+1];
	if(s==NULL){
		size=0;
		throw bad_alloc();
	}
	else{
		int i;
		for(i=0;source.s[i]!='\0';i++){
			s[i]=source.s[i];
		}
		s[i]='\0';
	}
}

Kalkulator :: ~Kalkulator(){
	delete[] s;
}

int Kalkulator :: policz(){
	Stos stack;
	int wartosc;
	int liczby=0;
	int znaki=0;
	for(int i=0;i<size;i++){
		if(s[i]>='0' && s[i]<='9'){
			liczby++;
			wartosc=(int)s[i]-48;
			stack.push(wartosc);
		}
		if(s[i]=='+'){
			znaki++;
			if(znaki>=liczby){
				throw bad_alloc();
			}
			dodaj(stack);
		}
		if(s[i]=='-'){
			znaki++;
			if(znaki>=liczby){
				throw bad_alloc();
			}
			odejmij(stack);
		}
		if(s[i]=='*'){
			znaki++;
			if(znaki>=liczby){
				throw bad_alloc();
			}
			pomnoz(stack);
		}
	}
	return stack.top();
}

void Kalkulator :: dodaj(Stos &stack){
	int x,y;
	x=stack.top();
	stack.pop();
	y=stack.top();
	stack.pop();
	stack.push(x+y);
}


void Kalkulator :: odejmij(Stos &stack){
	int x,y;
	x=stack.top();
	stack.pop();
	y=stack.top();
	stack.pop();
	stack.push(y-x);
}

void Kalkulator :: pomnoz(Stos &stack){
	int x,y;
	x=stack.top();
	stack.pop();
	y=stack.top();
	stack.pop();
	stack.push(x*y);
}

