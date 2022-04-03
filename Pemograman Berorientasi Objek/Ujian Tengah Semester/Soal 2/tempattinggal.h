/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : tempattinggal.h
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Header tempattinggal.cpp */

#ifndef TEMPATTINGGAL_H
#define TEMPATTINGGAL_H

#include <iostream>
using namespace std;

class Kendaraan
{
	public:
		virtual float hitung_jarakTempuh() = 0;
};

class TempatTinggal
{
	private:
		int luas;
		float hargaBahanBangunan;
	
	public:
		//ctor
		TempatTinggal(int, float);
		
		//selektor
		virtual void setluas(int);
		virtual void sethargaBahanBangunan(float);
		virtual int getluas();
		virtual float gethargaBahanBangunan();
		
		//Rumus standar: biayaBangun= luas * hargaBahanBangunan
		virtual float hitung_biayaBangun();
};

class Rumah: public TempatTinggal
{
};

class Karavan: public Kendaraan, public TempatTinggal
{
	private:
		float bensin;
		float pemakaianBensin;
	
	public:
		//ctor
		Karavan(int, float, float, float);
		
		//selektor
		void setbensin(float);
		void setpemakaianbensin(float);
		float getbensin();
		float getpemakaianbensin();
		
		//Rumus: biayaBangun = (luas * hargaBahanBangunan) * 3
		float hitung_biayaBangun();
		
		//Rumus: jarakTempuh = (bensin * pemakaianBensin)
		float hitung_jarakTempuh();
};

#endif
