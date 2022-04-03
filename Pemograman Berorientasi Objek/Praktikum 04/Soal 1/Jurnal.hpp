/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Jurnal.hpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Header Jurnal.cpp */

#ifndef JURNAL_H
#define JURNAL_H

#include "Artikel.hpp"
#include <iostream>
#include <cstring>

#define DEFSIZE 256

class Jurnal
{
	private:
		Artikel* data;
		int size;
	
	public:
		//ctor
		Jurnal();

		Jurnal(Artikel*, int);

		//cctor
		Jurnal(const Jurnal&);

		//dtor
		~Jurnal();

		Jurnal& operator=(const Jurnal&);

		//selektor
		void setData(int, Artikel);
		void setSize(int);
		
		Artikel getData(int) const;
		int getSize() const;

		void print() const;
		void add(Artikel);
		void insert(int, Artikel);
		int findByTahun(int) const;
};

#endif
