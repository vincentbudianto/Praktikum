/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Kendaraan.hpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Header Kendaraan.cpp */

#ifndef KENDARAAN_HPP
#define KENDARAAN_HPP

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

#endif
