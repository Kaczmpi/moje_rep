#include "vector.h"
#include "baza.h"

template<typename typ> vector<typ>::vector(){
	wsk=new typ[3];
	size=0;
	poz=0;
}

template<typename typ> vector<typ>::vector(vector<typ>& wektor){
	wsk=new typ[wektor.size];
	size=wektor.size;
	poz=wektor.poz;
	for(int i=0;i<poz;i++){
		wsk[i]=wektor.wsk[i];
	}
}

template<typename typ> vector<typ>::~vector(){
	delete[] wsk;
}

template<typename typ> void vector<typ>::push_back(typ war){
	if(poz==size){
		powieksz();
	}
	wsk[poz]=war;
	poz++;
}

template<typename typ> void vector<typ>::push(typ war,int k){
	if(poz==size){
		powieksz();
	}
	for(int i=poz;i==k;i--){
		wsk[i]=wsk[i-1];
	}
	wsk[k]=war;
	poz++;
}

template<typename typ> void vector<typ>::pop_back(){
	if(size!=0){
		poz--;
	}
	else{
		cout<<"Nie mozna pomniejszyc wektora";
	}
}

template<typename typ> void vector<typ>::pop(int k){
	if(size!=0 && k<poz){
		for(int i=k;i<poz-1;i++){
			wsk[i]=wsk[i+1];
		}
		poz--;
	}
	else{
		cout<<"Nie mozna pomniejszyc wektora";
	}
}

template<typename typ> void vector<typ>::powieksz(){
	typ* nowy;
	nowy=new typ[size+5];
	for(int i=0;i<poz;i++){
		nowy[i]=wsk[i];
	}
	size=size+5;
	delete[] wsk;
	wsk=nowy;
}

template<typename typ> void vector<typ>::zeruj(){
	poz=0;
}

template <typename typ> iter<typ> vector<typ>::pocz(){
	return iter<typ>(*this,0);
}

template <typename typ> iter<typ> vector<typ>::kon()
	{
	return iter<typ>(*this,poz);
	}

template <typename typ> typ& vector<typ>::operator [](int k){
	return wsk[k];	
}

template<typename typ> iter<typ>::iter(vector<typ>& wektor,int k){
	wsk=&wektor;
	poz=k;
}

template<typename typ> iter<typ>::iter(const iter<typ>& iterator){
	wsk=iterator.wsk;
	poz=iterator.poz;
}

template<typename typ> typ& iter<typ>::operator *(){
	return (*wsk)[poz];
}

template<typename typ> typ& iter<typ>::operator [](int i){
	if(i<0){
		i=0;
	}
	if(i>=wsk->poz){
		i=wsk->poz;
	}
	return wsk->wsk[i];
}

template <typename typ> typ* iter<typ>::operator ->() const{
	return &((*wsk)[poz]);
}

template<typename typ> iter<typ> iter<typ>::operator ++(int i){
	poz++;
	return (*this);
}

template<typename typ> bool iter<typ>::operator==(iter<typ> iterator){
	if(poz==iterator.poz){
		return true;
	}
	return false;
}

template<typename typ> bool iter<typ>::operator!=(iter<typ> iterator){
	if(poz!=iterator.poz){
		return true;
	}
	return false;
}

template<typename typ> iter<typ>& iter<typ>::operator =(const iter<typ> iterator){
	wsk=iterator.wsk;
	poz=iterator.poz;
	return (*this);
}

template class vector<sklepy>;
template class vector<baza>;

template class iter<sklepy>;
template class iter<baza>;
