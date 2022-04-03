/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : KoleksiKendaraan.hpp
 * Topik     : Latihan Inheritance
 * Tanggal   : 22 Februari 2019
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
		koleksiKendaraan(int);
		
		//cctor
		koleksiKendaraan(const koleksiKendaraan&);
		
		//dtor
		~koleksiKendaraan();
		
		//selektor
		void SetKendaraan(Kendaraan&, int);
		void setSize(int);
		void setNeff(int);
		
		Kendaraan& getKendaraan(int);
		int getSize();
		int getNeff();
		
		//function + procedure
		void PrintAll() const;
		void operator+(kendaraan);
		void operator+(koleksiKendaraan);
		
	private:
		kendaraan **data;
		int size;
		int Neff;
};

#endif
