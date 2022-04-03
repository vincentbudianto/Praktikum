/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : KoleksiKendaraan.cpp
 * Topik     : Latihan Class
 * Tanggal   : 01 Februari 2019
 * Deskripsi : Implementasi KoleksiKendaraan.cpp */

#include "KoleksiKendaraan.hpp"
#include <iostream>
using namespace std;

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
