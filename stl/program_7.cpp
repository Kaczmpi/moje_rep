#include <iostream>
#include <vector>

using namespace std;

template <typename It>
void wypisuj_na_cout(It pocz, It kon){
	for(It i=pocz; i!=kon; i++){
		cout<<*i<<endl;   	
	}
}

template <typename It>
void wypisuj_na_cout(It pocz, int n){
	for(It i=pocz; i!=pocz+n; i++){
		cout<<*i<<endl;   	
	}
}

template<typename DT>
struct Oper{
	void zeruj(DT& a){
		a=0;
	}
};

template<typename DT>
struct Cond{
	bool operator ()(const DT& a) const{
		return a<4;
	}
};

template <typename Iter, typename Cond, typename Oper>
void zrealizuj_dla_spelniajacych(Iter poczatek, Iter za_koncem, Cond warunek, Oper czynnosc){
	for(Iter i=poczatek; i!=za_koncem; i++){
		if(warunek(*i)) czynnosc.zeruj(*i);
	}
}
  
int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(10);
	v.push_back(3);
	v.push_back(2);
	v.push_back(11);
	v.push_back(1);
	
	cout<<"Przeciazone funkcje wypisuj_na_cout dla wektora:"<<endl;	
	wypisuj_na_cout(v.begin(), v.end());
	cout<<endl;
	wypisuj_na_cout(v.begin(), 6);
	cout<<endl;
	
	int a[6];
	a[0]=5;
	a[1]=10;
	a[2]=3;
	a[3]=2;
	a[4]=11;
	a[5]=1;
	
	cout<<"przeciazone funkcje wypisuj_na_cout dla tablicy:"<<endl;
	wypisuj_na_cout(a, a+6);
	cout<<endl;
	wypisuj_na_cout(a, 6);
	cout<<endl;
	
	Cond<int> warunek_v;
	Cond<int> warunek_a;
	Oper<int> dzialanie_v;
	Oper<int> dzialanie_a;
	
	cout<<"Przy warunku v[i]<4 nastepuje zerowanie v[i]=0"<<endl;
	zrealizuj_dla_spelniajacych(v.begin(), v.end(), warunek_v, dzialanie_v);
	wypisuj_na_cout(v.begin(), v.end());
	
	cout<<"Przy warunku a[i]<4 nastepuje zerowanie a[i]=0"<<endl;
	zrealizuj_dla_spelniajacych(a, a+6, warunek_a, dzialanie_a);
	wypisuj_na_cout(a, a+6);
	
return 0;
}
