/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : tempattinggal.cpp
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Implementasi tempattinggal.cpp */

#include "tempattinggal.h"
#include <iostream>
using namespace std;

TempatTinggal::TempatTinggal(int a, float b)
{
	luas = a;
	hargaBahanBangunan = b;
}

void TempatTinggal::setluas(int _luas)
{
	luas = _luas;
}

void TempatTinggal::sethargaBahanBangunan(float _hargaBahanBangunan)
{
	hargaBahanBangunan = _hargaBahanBangunan;
}

int TempatTinggal::getluas()
{
	return luas;
}

float TempatTinggal::gethargaBahanBangunan()
{
	return hargaBahanBangunan;
}

float TempatTinggal::hitung_biayaBangun()
{
	return (getluas() * gethargaBahanBangunan());
}

Karavan::Karavan(int a, float b, float c, float d): TempatTinggal(a, b)
{
	bensin = c;
	pemakaianBensin = d;
}

void Karavan::setbensin(float _bensin)
{
	bensin = _bensin;
}

void Karavan::setpemakaianbensin(float _pemakaianBensin)
{
	pemakaianBensin = _pemakaianBensin;
}

float Karavan::getbensin()
{
	return bensin;
}

float Karavan::getpemakaianbensin()
{
	return pemakaianBensin;
}

float Karavan::hitung_biayaBangun()
{
	return (getluas() * gethargaBahanBangunan() * 3);
}

float Karavan::hitung_jarakTempuh()
{
	return (bensin * pemakaianBensin);
}
