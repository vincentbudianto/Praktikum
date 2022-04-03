/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : X.hpp
 * Topik     : Latihan 1
 * Tanggal   : 25 Januari 2019
 * Deskripsi : Header X.cpp */

#ifndef _X_HPP
#define _X_HPP

class X
{
	public:
		X();			//ctor
		X(int);			//ctor dengan parameter
		X(const X&);	//cctor
		~X();			//dtor
		
		void Print();	//prosedur untuk memprint atribut
		
	private:
		int x;			//atribut kelas
};

#endif
