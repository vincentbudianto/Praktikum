/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Stack.hpp
 * Topik     : Latihan Class Generic
 * Tanggal   : 22 Februari 2019
 * Deskripsi : Template Class Generic Stack */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <class T>
class Stack
{
	public:
		//ctor
		Stack();				// default ctor
		Stack(int);				// ctor dengan ukuran max stack
		
		//cctor
		Stack(const Stack&);	// cctor
		
		//dtor
		~Stack();
		
		//services
		void Pust(T);			// <=== parameter generik
		void Pop (T&);			// <=== parameter generik
		int isEmpty() const;
		int isFull() const;
		
		//operator
		Stack& operator= (const Stack&);
		void operator<<(T);		// <=== parameter generik
		void operator>>(T&);	// <=== parameter generik
		
	private:
		const int defaultStackSize = 500;
		int topStack;
		int size;
		T *data;
}

template <class T>
Stack<T>::Stack()
{
	//Kamus Lokal
	
	//Algoritma
	data = new int [defaultStackSize];
	topStack = 0;
	size = defaultStackSize;
}

template <class T>
Stack<T>::Stack(int s)
{
	//Kamus Lokal
	
	//Algoritma
	data = new int [s];	//alokasi array integer dengan 18 * index 0 .. s-1
	topStack = 0;
	size = s;
}

template <class T>
Stack<T>::Stack(const Stack& s)
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

template <class T>
Stack<T>::~Stack()
{
	//Kamus Lokal
	
	//Algoritma
	delete [] data;	//dealokasi array integer
	size = 0;
	data = 0;
}

template <class T>
void Stack<T>::Pop(int& item)
{
	//Kamus Lokal
	
	//Algoritma
	if (isEmpty())
	{
		
	}
	else
	{
		topStack--;
		item = data [topStack];
	}
}

template <class T>
void Stack<T>::Push(int item)
{
	//Kamus Lokal
	
	//Algoritma
	data [topStack] = item;
	topStack++;
}

template <class T>
int Stack<T>::isEmpty() const
{
	return (topStack == 0);
}

template <class T>
int Stack<T>::isFull() const
{
	return (topStack == size);
}

template <class T>
Stack<T>& Stack<T>::operator= (const Stack&)
{
	
}

template <class T>
void Stack<T>::operator<<(T)
{
	
}

template <class T>
void Stack<T>::operator>>(T&)
{
	
}

#endif
