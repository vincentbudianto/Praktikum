/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : KoleksiKendaraan.cpp
 * Topik     : Latihan Inheritance
 * Tanggal   : 22 Februari 2019
 * Deskripsi : Implementasi KoleksiKendaraan.cpp */

#include "KoleksiKendaraan.hpp"
#include <iostream>
using namespace std;

koleksiKendaraan::koleksiKendaraan()
{
	data = new kendaraan* [100];
	size = 100;
	Neff = 0;
}

koleksiKendaraan::koleksiKendaraan(int s)
{
	data = new kendaraan* [s];
	size = s;
	Neff = 0;
}

koleksiKendaraan::koleksiKendaraan(const koleksiKendaraan& _koleksiKendaraan)
{
	int i;
	
	delete []data;
	data = new kendaraan* [_koleksiKendaraan.size];
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

void KoleksiKendaraan::SetKendaraan(Kendaraan& a, int b)
{
	data[b] = &a;
}

void koleksiKendaraan::setSize(int a)
{
	size = a;
}

void koleksiKendaraan::setNeff(int a)
{
	Neff = a;
}

Kendaraan& KoleksiKendaraan::getKendaraan(int a)
{
	return koleksi[a];
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
		cout << "Koleksi ke-" << (i+1) << endl;
		data[i].PrintInfo();
	    cout << endl;
	}
}

void koleksiKendaraan::operator+(kendaraan a)
{
	data[Neff] = a;
	Neff++;
}

void koleksiKendaraan::operator+(koleksiKendaraan a)
{
	bool full;
	int i;
	
	full = false;
	i = 0;
	
	while ((i < a.Neff) && !full)
	{
		if (Neff == size)
		{
			full = true;
		}
		else
		{
			data[Neff] = a.data[i];
			Neff++;
			i++;
		}
	}
}
