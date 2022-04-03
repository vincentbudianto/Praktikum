/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Stack.hpp
 * Topik     : Latihan 2
 * Tanggal   : 25 Januari 2019
 * Deskripsi : Header Stack.cpp */

#ifndef STACK_HPP
#define STACK_HPP

class Stack {
	public:
		//ctor -- dtor
		Stack(); 				//constructor
		Stack(int);				//constructor dengan ukuran stack
		Stack(const Stack&);	//copy constructor
		~Stack(); 				//destructor

		//fungsi-fungsi layanan
		void Pop(int&);
		void Push (int);
		int isEmpty() const
		//pendefinisian di dalam class body
		{
			return topStack == 0;
		}

	private:
		//data member
		const int defaultStackSize = 500; //ANSI: tidak boleh inisialisasi
		int topStack;
		int size;
		int *data;
};

class Stack {
	public:
		Stack();		//constructor
		Stack (int);	//constructor dengan ukuran stack
		Stack (const Stack&); // copy constructor
		~Stack(); // destructor
		// ...anggota-anggota lain tidak dituliskan...
}

#endif STACK_H
