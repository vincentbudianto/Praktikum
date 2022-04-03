/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Latihan1.cpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Implementasi Latihan1.cpp */

#include "Latihan1.hpp"
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

koleksiKendaraan::koleksiKendaraan()
{
	data = new kendaraan [100];
	size = 100;
	Neff = 0;
}

koleksiKendaraan::koleksiKendaraan(int s)
{
	data = new kendaraan [s];
	size = s;
	Neff = 0;
}

koleksiKendaraan::koleksiKendaraan(const koleksiKendaraan& _koleksiKendaraan)
{
	int i;
	
	delete []data;
	size = _koleksiKendaraan.size;
	Neff = _koleksiKendaraan.Neff;
	for (i = 0; i < _koleksiKendaraan.Neff; i++)
	{
		data[i] = _koleksiKendaraan.data[i];
	}
}

koleksiKendaraan::~koleksiKendaraan()
{
	delete [] data;
	size = 0;
	Neff = 0;
}

void koleksiKendaraan::setSize(int a)
{
	size = a;
}

void koleksiKendaraan::setNeff(int a)
{
	Neff = a;
}

int koleksiKendaraan::getSize()
{
	return size;
}

int koleksiKendaraan::getNeff()
{
	return Neff;
}

void koleksiKendaraan::PrintAll() const
{
	int i;
	
	for (i = 0; i < Neff; i++)
	{
		data[i].PrintInfo();
	}
}

void koleksiKendaraan::operator+(kendaraan a)
{
	data[Neff] = a;
	Neff++;
}

void koleksiKendaraan::operator+(koleksiKendaraan a)
{
	int i;
	
	i = 0;
	while ((Neff <= size) and (i < a.Neff))
	{
		data[Neff] = a.data[i];
		Neff++;
		i++;
	}
}
