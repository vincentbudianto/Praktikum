/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : main.cpp
 * Topik     : Quiz Online
 * Tanggal   : 01 Maret 2019
 * Deskripsi : Driver Physic.cpp */

#include "Physic.cpp"
#include <iostream>
using namespace std;

int main()
{
	//Kamus
	
	//Algoritma
	try
	{
		Physic X1(25, 1);
		Physic X2(32, 2);
		Physic X3(12, 0);
		Physic X4(21, 0);
	}
	catch (PhysicException a)
	{
		
	}
	
	return 0;
}
