/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Physic.cpp
 * Topik     : Quiz Online
 * Tanggal   : 01 Maret 2019
 * Deskripsi : Implementasi Physic.cpp */

#include "Physic.hpp"
#include "PhysicException.hpp"
#include <iostream>
using namespace std;

Physic::Physic(int _pressure, int _temperature)
{
	pressure = _pressure;
	temperature = _temperature;
}

int Physic::constant()
{
	int a;
	
	a = pressure / temperature;
	
	if (a == 0)
	{
		throw PhysicException("Suhu tidak valid");
	}
	
	return (a);
}
