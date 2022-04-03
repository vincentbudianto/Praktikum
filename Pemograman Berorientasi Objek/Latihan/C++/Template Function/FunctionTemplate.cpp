/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : FunctionTemplate.cpp
 * Topik     : Latihan Function Template
 * Tanggal   : 20 Februari 2019
 * Deskripsi : Implementasi FunctionTemplate.cpp */

#include <iostream>
using namespace std;

template <class T>
T MinArray(T* a, T N)
{
	//Kamus Lokal
	T result;
	int i;
	
	//Algoritma
	result = a[0];
	
	for (i = 1; i < N; i++)
	{
		if (a[i] < result)
		{
			result = a[i];
		}
	}
	
	return result;
}

int main()
{
	//Kamus
	int* X;
	int size;
	int a, i;
	
	//Algoritma
	cout << "Size : ";
	cin >> size;
	X = new int[size];
	
	for (i = 0; i < size; i++)
	{
		cout << "X[" << (i + 1) << "] : ";
		cin >> a;
		X[i] = a;
	}
	
	cout << "Nilai minimum adalah " << MinArray(X, size);	
	
	return 0;
}
