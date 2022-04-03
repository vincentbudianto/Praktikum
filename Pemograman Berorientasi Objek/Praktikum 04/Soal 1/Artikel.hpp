/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Artikel.hpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Header Artikel.cpp */

#ifndef ARTIKEL
#define ARTIKEL

#include <iostream>
#include <cstring>

#define DEFSIZE 256

using namespace std;

class Artikel
{
	private:
		char* judul;
		char* penulis;
		int tahun;
	
	public:
		//ctor
		Artikel();
		Artikel(char*, char*, int);

		//cctor
		Artikel(const Artikel&);

		//dtor
		~Artikel();

		Artikel& operator=(Artikel&);
		
		//selektor
		void setJudul(char*);
		void setPenulis(char*);
		void setTahun(int);
		
		char* getJudul() const;
		char* getPenulis() const;
		int getTahun() const;

		void print() const;
};

#endif
