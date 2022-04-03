/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : X.cpp
 * Topik     : Latihan 1
 * Tanggal   : 25 Januari 2019
 * Deskripsi : Implementasi X.cpp */
 
#include "X.hpp"
#include <iostream>
using namespace std;
// perhatikan bahwa pada umumnya tidak dituliskan "cout" pada ctor, cctor, dtor
// pada contoh ini dituliskan utk menunjukkan bahwa ada pengaktifan

X::X()
//ctor
{
	//Kamus Lokal
	
	//Algoritma
	x = 0;
	cout << "ctor X().." << endl;
} 

X::X(int a)
// ctor dg parameter
{
	//Kamus Lokal
	
	//Algoritma
	x = a;
	cout << "ctor X(int).." << endl;
}

X::X(const X& OX)
//cctor
{
	//Kamus Lokal
	
	//Algoritma
	x = OX.x;
	cout << "cctorX.." << endl;
}

X::~X()
//dtor, kasus ini tak perlu
{
	//Kamus Lokal
	
	//Algoritma
	cout << "dtor.." << endl;
}

void X::Print()
//prosedur untuk memprint atribut
{
	//Kamus Lokal
	
	//Algoritma
	cout << " Nilai x=: " << x << endl;
}
