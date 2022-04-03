/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Jurnal.hpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Implementasi Jurnal.cpp */

#include "Jurnal.hpp"
#include <iostream>
#include <cstring>

using namespace std;

Jurnal::Jurnal()
{
	int i;
	
	data = new Artikel[DEFSIZE];
	
	for (i = 0; i < DEFSIZE; i++)
	{
		Artikel a;
		data[i] = a;
	}
	
	size = 0;
}

Jurnal::Jurnal(Artikel* a, int s)
{
	int i;

	size = s;
	data = new Artikel[DEFSIZE];
	for (i = 0; i < size; i++)
	{
		data[i] = a[i];
	}
}

Jurnal::Jurnal(const Jurnal& j)
{
	int i;
	
	data = new Artikel[DEFSIZE];
	size = j.size;

	for (i = 0; i < size; i++)
	{
		data[i] = j.data[i];
	}
}

Jurnal::~Jurnal()
{
	delete [] data;
}

Jurnal& Jurnal::operator=(const Jurnal& j)
{
	int i;
	
	size = j.size;
	delete [] data;
	data = new Artikel[DEFSIZE];
	
	for (i = 0; i < size; i++)
	{
		data[i] = j.data[i];
	}

	return *this;
}

void Jurnal::setData(int i, Artikel a)
{
	data[i] = a;
}

void Jurnal::setSize(int s)
{
	size = s;
}

Artikel Jurnal::getData(int i) const
{
	return data[i];
}

int Jurnal::getSize() const
{
	return size;
}

void Jurnal::print() const
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		cout << "Konten "<< (i + 1) << endl;
		data[i].print();
	}
}

void Jurnal::add(Artikel a)
{
	data[size] = a;
	size++;
}

void Jurnal::insert(int i, Artikel a)
{
	int j;
	
	for (j = size; j > i; j--)
	{
		data[j] = data[j - 1];
	}
	
	data[i] = a;
	size++;
}

int Jurnal::findByTahun(int t) const
{
	bool found;
	int i;
	
	i = 0;
	found = false;
	
	while ((not found) && (i < size))
	{
		if (data[i].getTahun() == t)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	
	return i;
}
