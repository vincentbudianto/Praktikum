/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Latihan1.cpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Implementasi Latihan1.cpp */

#include "Latihan1.hpp"
#include <iostream>
using namespace std;

Bus::Bus()
{
	nomor = 0;
	tahun = 0;
	merk = "XXX";
	kapasitas = 0;
}

Bus::Bus(int a, int b, string c, int d)
{
	nomor = a;
	tahun = b;
	merk = c;
	kapasitas = d;
}

void Bus::setNomor(int a)
{
	nomor = a;
}

void Bus::setTahun(int a)
{
	tahun = a;
}

void Bus::setMerk(string a)
{
	merk = a;
}

void Bus::setKapasitas(int a)
{
	kapasitas = a;
}

int Bus::getNomor()
{
	return nomor;
}

int Bus::getTahun()
{
	return tahun;
}

string Bus::getMerk()
{
	return merk;
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

Minibus::Minibus()
{
	nomor = 0;
	tahun = 0;
	merk = "XXX";
}

Minibus::Minibus(int a, int b, string c)
{
	nomor = a;
	tahun = b;
	merk = c;
}

void Minibus::setNomor(int a)
{
	nomor = a;
}

void Minibus::setTahun(int a)
{
	tahun = a;
}

void Minibus::setMerk(string a)
{
	merk = a;
}

int Minibus::getNomor()
{
	return nomor;
}

int Minibus::getTahun()
{
	return tahun;
}

string Minibus::getMerk()
{
	return merk;
}

void Minibus::PrintInfo() const
{
	cout << "Minibus " << merk << " " << tahun << " " << nomor << endl;
}

int Minibus::HitungBiayaSewa(int a) const
{
	int harga;
	
	if (a <= 5)
	{
		harga = 5000000;
	}
	else
	{
		harga = 5000000 + (a - 5) * 500000;
	}
	
	return harga;
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

Mobil::Mobil()
{
	nomor = 0;
	tahun = 0;
	merk = "XXX";
	supir = "XXXX";
}

Mobil::Mobil(int a, int b, string c, string d)
{
	nomor = a;
	tahun = b;
	merk = c;
	supir = d;
}

void Mobil::setNomor(int a)
{
	nomor = a;
}

void Mobil::setTahun(int a)
{
	tahun = a;
}

void Mobil::setMerk(string a)
{
	merk = a;
}

void Mobil::setSupir(string a)
{
	supir = a;
}

int Mobil::getNomor()
{
	return nomor;
}

int Mobil::getTahun()
{
	return tahun;
}

string Mobil::getMerk()
{
	return merk;
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
