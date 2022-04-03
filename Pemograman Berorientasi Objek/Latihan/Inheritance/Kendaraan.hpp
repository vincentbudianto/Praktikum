/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Kendaraan.hpp
 * Topik     : Latihan Class
 * Tanggal   : 22 Februari 2019
 * Deskripsi : Header Kendaraan.cpp */

#ifndef KENDARAAN_HPP
#define KENDARAAN_HPP

#include <iostream>
#include <string.h>
using namespace std;

class kendaraan
{
	public:
		//ctor
		kendaraan();
		kendaraan(int, int, string);

		//selektor
		void setNomor(int);
		void setTahun(int);
		void setMerk(string);
		
		int getNomor();
		int getTahun();
		string getMerk();
		
		//function + procedure
		virtual void PrintInfo() = 0;
		virtual int HitungBiayaSewa(int a) = 0;
		
	protected:
		int nomor;
		int tahun;
		string merk;
};

class Bus: public kendaraan
{
	public:
		//ctor
		Bus();
		Bus(int, int, string, int);
		
		//selektor
		void setKapasitas(int);
		
		int getKapasitas();
		
		void PrintInfo() const;
		int HitungBiayaSewa(int) const;
		
	protected:
		int kapasitas;
};

class Minibus: public kendaraan
{
	public:
		//ctor
		Minibus();
		Minibus(int, int, string);
				
		void PrintInfo() const;
		int HitungBiayaSewa(int) const;
		float CalculateDiscount(int);
};

class Mobil: public kendaraan
{
	public:
		//ctor
		Mobil();
		Mobil(int, int, string, string);
		
		//selektor
		void setSupir(string);
		
		string getSupir();
		
		void PrintInfo() const;
		int HitungBiayaSewa(int) const;
		
	protected:
		string supir;
};

#endif
