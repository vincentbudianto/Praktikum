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
	tahun = 0;
	merk = "XXX";
}

kendaraan::kendaraan(int a, int b, string c)
{
	nomor = a;
	tahun = b;
	merk = c;
}

int kendaraan::getNomor()
{
	return nomor;
}

int kendaraan::getTahun()
{
	return tahun;
}

string kendaraan::getMerk()
{
	return merk;
}

void kendaraan::setNomor(int a)
{
	nomor = a;
}

void kendaraan::setTahun(int a)
{
	tahun = a;
}

void kendaraan::setMerk(string a)
{
	merk = a;
}

Bus::Bus(): kendaraan::kendaraan()
{
	kapasitas = 0;
}

Bus::Bus(int a, int b, string c, int d): kendaraan::kendaraan(a, b, c)
{
	kapasitas = d;
}

void Bus::setKapasitas(int a)
{
	kapasitas = a;
}

int Bus::getKapasitas()
{
	return kapasitas;
}

void Bus::PrintInfo() const
{
	cout << "Bus " << merk << " " << tahun << " " << nomor << " " << kapasitas << endl;
}

int Bus::HitungBiayaSewa(int a) const
{
	return (a * 1000000);
}

Minibus::Minibus(): kendaraan::kendaraan()
{
}

Minibus::Minibus(int a, int b, string c): kendaraan::kendaraan(a, b, c)
{
}

void Minibus::PrintInfo() const
{
	cout << "Minibus " << merk << " " << tahun << " " << nomor << endl;
}

int Minibus::HitungBiayaSewa(int a) const
{
	if (a <= 5)
	{
		return 5000000;
	}
	else
	{
		return (5000000 + (a - 5) * 500000);
	}
}

float Minibus::CalculateDiscount(int a)
{
	int harga;
	
	harga = HitungBiayaSewa(a);
	
	if (a > 10)
	{
		harga *= 0.1;
	}
	
	return harga;
}

Mobil::Mobil(): kendaraan::kendaraan()
{
	supir = "XXXX";
}

Mobil::Mobil(int a, int b, string c, string d): kendaraan::kendaraan(a, b, c)
{
	supir = d;
}

void Mobil::setSupir(string a)
{
	supir = a;
}

string Mobil::getSupir()
{
	return supir;
}

void Mobil::PrintInfo() const
{
	cout << "Mobil " << merk << " " << tahun << " " << nomor << " " << supir << endl;
}

int Mobil::HitungBiayaSewa(int a) const
{
	return (a * 500000);
}
