#ifndef Vector_hpp
#define Vector_hpp
#include<iostream>
#include<new>
#include<stdexcept>
#include<iomanip>
using namespace std;

class Vector{
	private:
		int* value;
		int size;
	public:
		Vector(int def_size=2);
		Vector(const Vector & source);
		~Vector();
		friend istream & operator>> (istream &we, Vector &in);
		friend ostream & operator<< (ostream &wy, const Vector &out);
		Vector operator+(const Vector &sum);
		Vector operator-(const Vector &odj);
		Vector operator*(const Vector &iloczyn_poi);
		Vector operator*(const int &stala);
		Vector operator=(const Vector& src);
		Vector operator+=(const Vector &add);
		Vector operator-=(const Vector &sub);
		Vector operator*=(const int &stala);
		bool operator==(const Vector &rowne);
		bool operator!=(const Vector &rozne);
		//int operator[](const int i);
};

#endif
