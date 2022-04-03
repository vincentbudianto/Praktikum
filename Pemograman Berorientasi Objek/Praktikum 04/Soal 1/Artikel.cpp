/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Artikel.cpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Implementasi Artikel.cpp */

#include "Artikel.hpp"
#include <iostream>
using namespace std;

Artikel::Artikel()
{
	int i;
	
	penulis = new char[DEFSIZE];
	judul = new char[DEFSIZE];
	
	for (i = 0; i < DEFSIZE; i++)
	{
		penulis[i] = '\0';
		judul[i] = '\0';
	}
	
	tahun = 0;
}
Artikel::Artikel(char* _judul, char* _penulis, int _tahun)
{
	penulis = new char[DEFSIZE];
	judul = new char[DEFSIZE];
	strcpy(judul,_judul);
	strcpy(penulis,_penulis);
	tahun = _tahun;
}

Artikel::Artikel(const Artikel& a)
{
	penulis = new char[DEFSIZE];
	judul = new char[DEFSIZE];
	strcpy(judul,a.judul);
	strcpy(penulis,a.penulis);
	tahun = a.tahun;
}

Artikel::~Artikel()
{
	delete [] penulis;
	delete [] judul;
}

Artikel& Artikel::operator=(Artikel& a)
{
	delete [] penulis;
	delete [] judul;
	penulis = new char[DEFSIZE];
	judul = new char[DEFSIZE];
	strcpy(judul,a.judul);
	strcpy(penulis,a.penulis);
	tahun = a.tahun;
	return *this;
}

void Artikel::setJudul(char* j)
{
	strcpy(judul,j);
}

void Artikel::setPenulis(char* p)
{
	strcpy(penulis,p);
}

void Artikel::setTahun(int t)
{
	tahun = t;
}

char* Artikel::getJudul() const
{
	return judul;
}

char* Artikel::getPenulis() const
{
	return penulis;
}

int Artikel::getTahun() const
{
	return tahun;
}

void Artikel::print() const
{
	cout << penulis << ". " << tahun << ". " << "\"" << judul << "\"." << endl;
}
