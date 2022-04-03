/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : pecahan.cpp
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Implementasi pecahan.cpp */

#include "pecahan.h"
#include <iostream>
using namespace std;

pecahan::pecahan()
{
	n = 0;
	d = 0;
}
		
pecahan::pecahan(int _n, int _d)
{
	n = _n;
	d = _d;
}

pecahan::pecahan(const pecahan& P)
{
	n = P.n;
	d = P.d;
}

/*		
pecahan::~pecahan()
{
	tidak dibutuhkan
}
*/

pecahan& pecahan::operator= (const pecahan& P)
{
	n = P.n;
	d = P.d;
	
	return *this;
}

int pecahan::getPemb()
{
	return n;
}

int pecahan::getPeny()
{
	return d;
}

void pecahan::setPemb(int _n)
{
	n = _n;
}

void pecahan::setPeny(int _d)
{
	d = _d;
}

pecahan pecahan::operator+ (pecahan P)
{
	pecahan X;
	
	X.n = (n * P.d) + (P.n * d);
	X.d = d * P.d;
	
	return X;
}

pecahan operator+ (pecahan P1, pecahan P2)
{
	pecahan X;
	
	X.n = (P1.n * P2.d) + (P2.n * P1.d);
	X.d = P1.d * P2.d;
	
	return X;
}

pecahan pecahan::operator* (int x)
{
	pecahan X;
	
	X.n = n;
	X.d = d;
	
	if (x > 0)
	{
		X.n *= x;
		X.d *= x;
	}
	
	return X;
}

pecahan operator* (int x, pecahan P)
{
	pecahan X;
	
	X.n = P.n;
	X.d = P.d;
	
	if (x > 0)
	{
		X.n *= x;
		X.d *= x;
	}
	
	return X;
}

float pecahan::RealP()
{
	return (float(n) / float(d));
}

void pecahan::Print()
{
	cout << n << "/" << d;
}
