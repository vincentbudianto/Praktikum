/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : KoleksiKendaraan.hpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Header KoleksiKendaraan.cpp */

#ifndef KOLEKSIKENDARAAN_HPP
#define KOLEKSIKENDARAAN_HPP

#include "Kendaraan.hpp"
#include <iostream>
using namespace std;

class koleksiKendaraan
{
	public:
		//ctor
		koleksiKendaraan();
		koleksiKendaraan(int s);
		
		//cctor
		koleksiKendaraan(const koleksiKendaraan&);
		
		//dtor
		~koleksiKendaraan();
		
		//selektor
		void setSize(int a);
		void setNeff(int a);
		
		int getSize();
		int getNeff();
		
		//function + procedure
		void PrintAll() const;
		void operator+(kendaraan a);
		void operator+(koleksiKendaraan a);
		
	private:
		kendaraan *data;
		int size;
		int Neff;
};

#endif
