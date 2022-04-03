/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Stack.cpp
 * Topik     : Latihan 2
 * Tanggal   : 25 Januari 2019
 * Deskripsi : Implementasi Stack.cpp */

#include <Stack.h>

Stack::Stack()
//Stack constructor
{
	//Kamus Lokal
	
	//Algoritma
	data = new int [defaultStackSize];
	topStack = 0;
	size = defaultStackSize;
}

Stack::Stack(int s)
//constructor dengan ukuran stack
// parameter s = ukuran stack
{
	//Kamus Lokal
	
	//Algoritma
	data = new int [s];	//alokasi array integer dengan 18 * index 0 .. s-1
	topStack = 0;
	size = s;
}

Stack::Stack(const Stack& s)
//copy constructor
{
	//Kamus Lokal
	int i;
	
	//Algoritma
	size = s.size;
	topStack = s.topStack;
	data = new int [size]; // PERHATIKAN: data member "data" harus di-alokasi ulang, tidak disalin dari "s.data".
	for (i = 0; i < size; i++)
	{
		data[i] = s.data[i];
	}
}

Stack::~Stack()
//destructor
{
	//Kamus Lokal
	
	//Algoritma
	delete [] data;	//dealokasi array integer
	size = 0;
	data = 0;
}

void Stack::Pop(int& item)
{
	//Kamus Lokal
	
	//Algoritma
	if (isEmpty())
	{
		// error message
	}
	else
	{
		topStack--;
		item = data [topStack];
	}
}

void Stack::Push(int item)
// . . .
{
	//Kamus Lokal
	
	//Algoritma
	data [topStack] = item;
	topStack++;
	// . . .
}
