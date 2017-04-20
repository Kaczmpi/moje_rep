#include "Kalkulator.hpp"
using namespace std;

int main(){
	try{
		int b;
		char a[100];
		do{
			fgets(a,100,stdin);
			Kalkulator kalk(a);
			if(a[0]!='q'){
				b=kalk.policz();
				cout<<b<<endl;
			}
		}while(a[0]!='q');
	}
	catch (bad_alloc& ba){
		cout << ba.what() << endl;
	}
	
return 0;	
}

