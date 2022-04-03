/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Latihan1.hpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Header Latihan1.cpp */

#ifndef LATIHAN1_HPP
#define LATIHAN1_HPP

#include <iostream>
using namespace std;

class kendaraan
{
	public:
		//ctor
		kendaraan();
		kendaraan(int a, string b, string c, int d);
		
		//selektor
		void setNomor(int a);
		void setTahun(int a);
		void setKategori(string a);
		void setMerk(string a);
		
		int getNomor();
		int getTahun();
		string getKategori();
		string getMerk();
		
		//function + procedure
		void PrintInfo() const;
		int HitungBiayaSewa(int a) const;
		
	private:
		int nomor;
		int tahun;
		string kategori;
		string merk;
};

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
