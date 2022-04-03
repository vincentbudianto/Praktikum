/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Pecahan.cpp
 * Topik     : Praktikum 2
 * Tanggal   : 31 Januari 2019
 * Deskripsi : Implementasi Pecahan.cpp */

#include "Pecahan.h"
#include <iostream>
using namespace std;

int GCD (int nx, int ny);

int GCD (int nx, int ny)
{
	int n1, n2;
	
	n1 = nx;
	n2 = ny;
	
	while(n1 != n2)
	{
		if (n1 > n2)
		{
			n1 -= n2;
		}
		else
		{
			n2 -= n1;
		}
	}
	
	return n1;
}

Pecahan::Pecahan()
{
	n = 1;
	a = 0;
	b = 1;
}

Pecahan::Pecahan (int _n, int _a, int _b)
{
	n = _n;
	a = _a / GCD(_a, _b);
	b = _b / GCD(_a, _b);
}

int Pecahan::getBulat ()
{
	return n;
}

int Pecahan::getPembilang ()
{
	return a;
}

int Pecahan::getPenyebut()
{
	return b;
}

void Pecahan::setBulat(int _n)
{
	n = _n;
}

void Pecahan::setPembilang(int _a)
{
	a = _a;
}

void Pecahan::setPenyebut(int _b)
{
	b = _b;
}

bool Pecahan::isValid (int n, int a, int b)
{
	return ((n >= 0) && (a >= 0) && (b > 1));
}

Pecahan Pecahan::addWithThis (Pecahan P)
{
	int x;
	Pecahan A;
	
	A.n = n + P.n;
	A.a = (a * P.b) + (b * P.a);
	A.b = b * P.b;
	x = GCD(A.a, A.b);
	A.n += (A.a / A.b);
	A.a %= A.b;
	A.a /= x;
	A.b /= x;
	
	return A;
}

void Pecahan::accumulate(Pecahan P)
{
	Pecahan A;
	
	A = addWithThis(P);
	n = A.n;
	a = A.a;
	b = A.b;
}

Pecahan Pecahan::add(Pecahan P1, Pecahan P2)
{
	int x;
	Pecahan A;
	
	A.n = P1.n + P2.n;
	A.a = (P1.a * P2.b) + (P1.b * P2.a);
	A.b = P1.b * P2.b;
	x = GCD(A.a, A.b);
	A.n += (A.a / A.b);
	A.a %= A.b;
	A.a /= x;
	A.b /= x;
	
	return A;
}

bool Pecahan::isEQMe(Pecahan P)
{
	return (P.value() == value());
}

bool Pecahan::isGTMe(Pecahan P)
{
	return (P.value() > value());
}

bool Pecahan::isLTMe(Pecahan P)
{
	return (P.value() < value());
}

float Pecahan::value()
{
	float x;
	
	x = n + ((float)a / (float)b);

	return x;
}
