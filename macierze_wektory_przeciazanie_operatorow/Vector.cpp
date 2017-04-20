#include "Vector.hpp"
using namespace std;

Vector :: Vector(int def_size){
	if(def_size<1){
		value=NULL;
	}
	value=new int[def_size];
	if(value==NULL){
		size=0;
	}
	size=def_size;
	for(int i=0; i<size; i++){
		value[i]=0;
	}
}

Vector :: Vector(const Vector &vec){
	if(vec.size<1){
		value=NULL;
	}
	value=new int[vec.size];
	if(value==NULL){
		size=0;
	}
	size=vec.size;
	for(int i=0; i<size; i++){
		value[i]=vec.value[i];
	}
}

Vector :: ~Vector(){
	delete[] value;
}

istream & operator>> (istream &we,Vector &in){
	if (in.size>=1 && in.value!=NULL){
		for (int i=0; i<in.size; i++){
			we>>in.value[i];
		}
	}
	return we;
}

ostream & operator<< (ostream &wy,const Vector &out){
	if (out.size!=0 && out.value!=NULL){
		wy<<"[";
		for (int i=0; i<out.size-1; i++){
			wy<<out.value[i]<<",";
		}
		wy<<out.value[out.size-1]<<"]"<<endl;
	}
	return wy;
}

Vector Vector :: operator+(const Vector &sum){
	if(size!=sum.size){
		return *this;
	}
	Vector result(size);
	for (int i=0; i<sum.size; i++){
		result.value[i]=value[i]+sum.value[i];
	}
	return result;
}

Vector Vector :: operator-(const Vector &odj){
	if(size!=odj.size){
		return *this;
	}
	Vector result(size);
	for (int i=0; i<odj.size; i++){
		result.value[i]=value[i]-odj.value[i];
	}
	return result;
}

Vector Vector :: operator*(const Vector &iloczyn_poi){
	if(size!=iloczyn_poi.size){
		return *this;
	}
	Vector result(size);
	for (int i=0; i<iloczyn_poi.size; i++){
		result.value[i]=value[i]*iloczyn_poi.value[i];
	}
	return result;
}

Vector Vector :: operator*(const int &stala){
	Vector result(size);
	for (int i=0; i<size; i++){
		result.value[i]=value[i]*stala;
	}
	return result;
}

Vector Vector :: operator=(const Vector& src){
	if (this==&src){
		return *this;
	}
	if (src.size<1 || src.value == NULL){
		delete[] value;
		value=NULL;
		size=0;
	}
	else{
		if (size==src.size){
			for (int i=0; i<size; i++){
				value[i]=src.value[i];
			}
		}
		else{
			delete [] value;
			value = new int[src.size];
			if (value==NULL) {
				size=0;;
			}
			size=src.size;
			for (int i=0; i<size; i++){
				value[i]=src.value[i];
			}
		}
	}
	return *this;
}

Vector Vector :: operator+=(const Vector &add){
	if(size!=add.size){
		return *this;
	}
	for (int i=0; i<add.size; i++){
		value[i]=value[i]+add.value[i];
	}
	return *this;
}

Vector Vector :: operator-=(const Vector &sub){
	if(size!=sub.size){
		return *this;
	}
	for (int i=0; i<sub.size; i++){
		value[i]=value[i]-sub.value[i];
	}
	return *this;
}

Vector Vector :: operator*=(const int &stala){

	for (int i=0; i<size; i++){
		value[i]=value[i]*stala;
	}
	return *this;
}


bool Vector:: operator==(const Vector &rowne){
	if(this==&rowne){
		return true;
	}
	if(size!=rowne.size){
		return false;
	}
	for (int i=0; i<size; i++){
		if(value[i]!=rowne.value[i]){
			return false;
		}
	}
	return true;	
}
bool Vector:: operator!=(const Vector &rozne){
	if(this==&rozne){
		return false;
	}
	if(size!=rozne.size){
		return true;
	}
	for (int i=0; i<size; i++){
		if(value[i]!=rozne.value[i]){
			return true;
		}
	}
	return false;
}
/*
int Vector :: operator[](int i){
	if (i<0 || i>size){
		return 99999994;
	}
	return value[i-1];	
}
*/

