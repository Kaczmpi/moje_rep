#include"Matrix.hpp"
using namespace std;

int main(){
	Matrix a(3);
	Matrix b(3);
	Matrix c(3);
	cin>>a>>b;
	c=a;
	cout <<"a:"<<endl<<a<<endl;
	cout <<"b:"<<endl<<b<<endl;
	if((a+b)!=c){
		cout <<"a+b"<<endl<<a+b<<endl;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	if((a-b)!=c){
		cout <<"a-b"<<endl<<a-b<<endl;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	if((a*b)!=c){
		cout<<"a*b"<<endl<<a*b<<endl;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	cout <<"a*3"<<endl<<a*3<<endl;
	a+=b;
	if(a!=c){
		cout<<"a+="<<endl<<a<<endl;
		c=a;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	}
	a-=b;
	if(a!=c){
		cout<<"a-="<<endl<<a<<endl;
		c=a;
	}
	else{
		cout<<"Operacji nie mo¿na wykonaæ"<<endl;
	};
	a*=2;
	cout<<"a*=2"<<endl<<a<<endl;
	if (a==b)cout<<"a==b"<< endl;
	if (a!=b)cout<<"a!=b"<< endl;
	if (a==a)cout<<"a==a"<< endl;
	if (a!=a)cout<<"a!=a"<< endl;

return 0;	
}
