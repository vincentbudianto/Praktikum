/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : BunchOfKeys.cpp
 * Topik     : Praktikum 1
 * Tanggal   : 24 Januari 2019
 * Deskripsi : Implementasi BunchOfKeys.cpp */

#include "BunchOfKeys.hpp"
#include <iostream>
using namespace std;

BunchOfKeys::BunchOfKeys()
{
	n_keys = 0;
}

void BunchOfKeys::add()
{
	n_keys++;
}

void BunchOfKeys::shake()
{
	int i;
	
	if (n_keys > 1)
	{
		for (i = 0; i < n_keys; i++)
		{
			cout << "krincing" << endl;
		}
	}
	else
	{
		cout << "Tidak terjadi apa-apa" << endl;
	}
}

