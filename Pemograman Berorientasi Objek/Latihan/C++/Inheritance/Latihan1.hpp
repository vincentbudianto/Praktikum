/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Latihan1.hpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Header Latihan1.cpp */

#ifndef LATIHAN1_HPP
#define LATIHAN1_HPP

#include <iostream>
#include <string.h>
using namespace std;

class kendaraan
{
	public:
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
		void setNomor(int);
		void setTahun(int);
		void setMerk(string);
		void setKapasitas(int);
		
		int getNomor();
		int getTahun();
		string getMerk();
		int getKapasitas();
		
		void PrintInfo() const;
		int HitungBiayaSewa(int) const;
		
	private:
		int kapasitas;
};

class Minibus: public kendaraan
{
	public:
		//ctor
		Minibus();
		Minibus(int, int, string);
		
		//selektor
		void setNomor(int);
		void setTahun(int);
		void setMerk(string);
		
		int getNomor();
		int getTahun();
		string getMerk();
		
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
		void setNomor(int);
		void setTahun(int);
		void setMerk(string);
		void setSupir(string);
		
		int getNomor();
		int getTahun();
		string getMerk();
		string getSupir();
		
		void PrintInfo() const;
		int HitungBiayaSewa(int) const;
		
	private:
		string supir;
};

#endif
