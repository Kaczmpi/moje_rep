#include "Vector.hpp"
using namespace std;

int main(){
	Vector a(3);
	Vector b(3);
	Vector c(3);
	cin>>a>>b;
	c=a;
	cout <<"a:"<<a<<endl;
	cout <<"b:"<<b<<endl;
	if((a+b)!=c){
		cout <<"a+b "<<a+b<<endl;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	if((a-b)!=c){
		cout <<"a-b "<<a-b<<endl;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	if((a*b)!=c){
		cout<<"a*b "<<a*b<<endl;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	cout <<"a*3 "<<a*3<<endl;
	a+=b;
	if(a!=c){
		cout<<"a+= "<<a<<endl;
		c=a;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	a-=b;
	if(a!=c){
		cout<<"a-= "<<a<<endl;
		c=a;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	};
	a*=2;
	cout<<"a*=2 "<<a<<endl;
	if (a==b)cout<<"a==b"<< endl;
	if (a!=b)cout<<"a!=b"<< endl;
	if (a==a)cout<<"a==a"<< endl;
	if (a!=a)cout<<"a!=a"<< endl;
//	cout<<a[2]<< endl;

return 0;	
}
