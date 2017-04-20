#ifndef Matrix_hpp
#define Matrix_hpp

#include "Vector.hpp"
using namespace std;

class Matrix{
	private:
		Vector *vec;
		int matrix_size;
		int vector_size;
	public:
		Matrix(int def_matrix_size=2,int def_vector_size=2);
		Matrix(const Matrix &macierz);
		~Matrix();
		friend ostream & operator<<(ostream& wy, const Matrix& out);
		friend istream & operator>>(istream& we, const Matrix& in);
		Matrix operator+(const Matrix &sum);
		Matrix operator-(const Matrix &odj);
		Matrix operator*(const int &stala);
		Matrix operator*(const Matrix &ilo_skalarny);
		Matrix operator+=(const Matrix &add);
		Matrix operator-=(const Matrix &sub);
		Matrix operator*=(const int &stala);
		Matrix operator=(const Matrix& src);
		bool operator==(const Matrix &row);
		bool operator!=(const Matrix &roz);
	
};

#endif
