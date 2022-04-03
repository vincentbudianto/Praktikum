/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : memo.cpp
 * Topik     : Praktikum 6
 * Tanggal   : 28 Februari 2019
 * Deskripsi : Realisasi memo.cpp */

#include "exception.h"
#include "memo.h"
#include <iostream>
using namespace std;

Memo::Memo()
{
	pesan = "";
	untuk = "";
}

Memo::Memo(string _pesan, string _untuk)
{
	if (pesan.length() <= PESAN_MAX)
	{
		pesan = _pesan;
		untuk = _untuk;
	}
	else
	{
		throw PesanKepanjanganException();
	}
}

Memo& Memo::operator=(Memo& obj)
{
	pesan = obj.pesan;
	untuk = obj.untuk;

	return *this;
}

string Memo::getPesan()
{
	return pesan;
}

string Memo::getUntuk()
{
	return untuk;
}
