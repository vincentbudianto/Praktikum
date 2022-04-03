/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Kendaraan.cpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Implementasi Kendaraan.cpp */

#include "Kendaraan.hpp"
#include <iostream>
using namespace std;

kendaraan::kendaraan()
{
	nomor = 0;
	kategori = "mobil";
	merk = "XXX";
	tahun = 0;
}

kendaraan::kendaraan(int a, string b, string c, int d)
{
	nomor = a;
	kategori = b;
	merk = c;
	tahun = d;
}

void kendaraan::setNomor(int a)
{
	nomor = a;
}

void kendaraan::setTahun(int a)
{
	tahun = a;
}

void kendaraan::setKategori(string a)
{
	kategori = a;
}

void kendaraan::setMerk(string a)
{
	merk = a;
}

int kendaraan::getNomor()
{
	return nomor;
}

int kendaraan::getTahun()
{
	return tahun;
}

string kendaraan::getKategori()
{
	return kategori;
}

string kendaraan::getMerk()
{
	return merk;
}

void kendaraan::PrintInfo() const
{
	cout << kategori << " " << merk << " " << tahun << " " << nomor << endl;
}

int kendaraan::HitungBiayaSewa(int a) const
{
	int harga;
	
	if (kategori == "Bus")
	{
		harga = a * 1000000;
	}
	else if (kategori == "Minibus")
	{
		if (a <= 5)
		{
			harga = 5000000;
		}
		else
		{
			harga = 5000000 + (a - 5) * 500000;
		}
	}
	else if (kategori == "Mobil")
	{
		harga = a * 500000;
	}
	
	return harga;
}
