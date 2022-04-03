/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : mainXY.cpp
 * Topik     : Latihan 1
 * Tanggal   : 25 Januari 2019
 * Deskripsi : Driver X.cpp dan Y.cpp */

#include "X.cpp"
#include "Y.cpp"
#include <iostream>
using namespace std;

int main()
{
	//Kamus

	//Algoritma
	X x; 			//x adalah seperti "struct" pada bhs C
	X x1 = x; 		//karena ada cctor maka bukan bitwise copy, tapi cctor dijalankan
	X* ptrx; 		//ptrx adalah pointer; hrs di-new
	X* ptr1 = new X();
	x.Print();
	x1.Print();
	ptr1 -> Print();
	Y oY;
	oY.Print();
	Y y1 = oY;
	y1.Print();
	Y* Ptry = new Y();
	Ptry -> Print();
	//delete ptr1

	return 0;
} 
