#include "Matrix.hpp"
using namespace std;

Matrix :: Matrix(int def_matrix_size, int def_vector_size){
	if(def_matrix_size<1 || def_vector_size<1){
		vec=NULL;
		matrix_size=0;
		vector_size=0;
	}
	vec=new Vector[def_matrix_size];
	if (vec==NULL){
		matrix_size=0;
		vector_size=0;
	}
	matrix_size=def_matrix_size ;
	vector_size=def_vector_size;
	for (int i=0; i <matrix_size; i++){
		vec[i]=Vector(vector_size);
	}
}
Matrix :: Matrix(const Matrix &macierz){
	if(macierz.matrix_size<1 || macierz.vec==NULL){
		vec=NULL;
		matrix_size=0;
		vector_size=0;
	}
	
	vec=new Vector[macierz.matrix_size];
	if (vec==NULL){
		matrix_size=0;
		vector_size=0;
	}
	matrix_size=macierz.matrix_size ;
	vector_size=macierz.vector_size;
	for (int i=0; i<matrix_size; i++){
		vec[i]=macierz.vec[i];
	}
}

Matrix :: ~Matrix(){
	delete[] vec;	
}


ostream & operator<<(ostream &wy, const Matrix &out)
{
	if (out.matrix_size < 1 || out.vec==NULL){
		wy<<"Macierz 0"<<endl;
		return wy;
	}
	for (int i=0; i<out.matrix_size; i++){
		wy<<out.vec[i];
	}
	wy<<endl;
	return wy;
}


istream & operator>>(istream &we, const Matrix &in)
{
	if (in.matrix_size < 1 || in.vec==NULL){
		cout<<"Macierz 0"<<endl;
		return we;
	}
	for (int i=0; i<in.matrix_size; i++){
		we>>in.vec[i];
	}
	return we;
}

Matrix Matrix :: operator+(const Matrix &sum){
	if(matrix_size!=sum.matrix_size || vector_size!=sum.vector_size){
		return *this;
	}
	Matrix result(matrix_size,vector_size);
	for(int i=0;i<matrix_size;i++){
		result.vec[i]=vec[i];
		result.vec[i]+=sum.vec[i];
	}
	return result;
}

Matrix Matrix :: operator-(const Matrix &odj){
	if(matrix_size!=odj.matrix_size || vector_size!=odj.vector_size){
		return *this;
	}
	Matrix result(matrix_size,vector_size);
	for(int i=0;i<matrix_size;i++){
		result.vec[i]=vec[i];
		result.vec[i]-=odj.vec[i];
	}
	return result;
}

Matrix Matrix :: operator*(const int &stala){
	Matrix result(matrix_size,vector_size);
	for(int i=0;i<matrix_size;i++){
		result.vec[i]=vec[i]*stala;
	}
	return result;
}

Matrix Matrix :: operator*(const Matrix &ilo_skalarny){
	if(matrix_size!=ilo_skalarny.matrix_size || vector_size!=ilo_skalarny.vector_size){
		return *this;
	}
	Matrix result(matrix_size,vector_size);
	for(int i=0;i<matrix_size;i++){
		result.vec[i]=vec[i];
		result.vec[i]=result.vec[i]*ilo_skalarny.vec[i];
	}
	return result;
}

Matrix Matrix :: operator+=(const Matrix &add){
	if(matrix_size!=add.matrix_size || vector_size!=add.vector_size){
		return *this;
	}
	for(int i=0;i<matrix_size;i++){
		vec[i]+=add.vec[i];
	}
	return *this;
}

Matrix Matrix :: operator-=(const Matrix &sub){
	if(matrix_size!=sub.matrix_size || vector_size!=sub.vector_size){
		return *this;
	}
	for(int i=0;i<matrix_size;i++){
		vec[i]-=sub.vec[i];
	}
	return *this;
}

Matrix Matrix :: operator*=(const int &stala){
	for(int i=0;i<matrix_size;i++){
		vec[i]=vec[i]*stala;
	}
	return *this;
}

Matrix Matrix :: operator=(const Matrix& src){
	if(this==&src){
		return *this;
	}
	if(src.matrix_size<1 || src.vec==NULL){
		delete[] vec;
		matrix_size=0; vector_size=0;
		return *this;
	}
	delete[] vec;
	vec=new Vector[src.matrix_size];
	if(vec==NULL){
		matrix_size=0;
		vector_size=0;
	}

	matrix_size=src.matrix_size;
	vector_size=src.vector_size;
	for (int i=0; i <matrix_size; i++){
		vec[i]=src.vec[i];
	}
	return *this;
}

bool Matrix::operator==(const Matrix &row){
	if(this==&row){
		return true;
	}
	if(matrix_size!=row.matrix_size || vector_size!=row.vector_size){
		return false;	
	}
	for (int i=0; i<matrix_size; i++){
		if(vec[i]!=row.vec[i]){
			return false;
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix &roz){
	if(this==&roz){
		return false;
	}
	if(matrix_size!=roz.matrix_size || vector_size!=roz.vector_size){
		return true;	
	}
	for (int i=0; i<matrix_size; i++){
		if(vec[i]!=roz.vec[i]){
			return true;
		}
	}
	return false;
}
