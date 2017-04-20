#ifndef WEKTOR_H
#define WEKTOR_H

#include <string>
#include <iostream>
using namespace std;

template <typename typ> class iter;

template<typename typ> class vector{
	friend class iter<typ>;
	private:
		int size;
		int poz;
		typ *wsk;
	public:
		vector();
		vector(vector<typ>& wektor);
		~vector();
		void push_back(typ war);
		void push(typ war,int k);
		void pop_back();
		void pop(int k);
		void powieksz();
		void zeruj();
		iter<typ> pocz();
		iter<typ> kon();
		typ& operator [] (int);
		int siz(){return poz;};
		typ* adr(int i) {return wsk+i;};
};

template<typename typ> class iter{
	private:
		vector<typ>* wsk;
		int poz;
	public:
		iter(vector<typ>&, int n=0);
		iter(const iter<typ>& iterator);
		typ& operator *();	
		typ& operator [](int i);
		typ* operator ->() const;
		iter<typ> operator ++(int i);
		bool operator ==(iter<typ> iterator);
		bool operator !=(iter<typ> iterator);
		iter<typ> & operator =(const iter<typ> iterator);
};

#endif
