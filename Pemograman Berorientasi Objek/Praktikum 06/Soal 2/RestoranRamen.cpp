/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : RestoranRamen.cpp
 * Topik     : Praktikum 6
 * Tanggal   : 28 Februari 2019
 * Deskripsi : Implementasi RestoranRamen.cpp */

#include "RestoranRamen.hpp"
#include  <iostream>
using namespace std;

void RestoranRamen::tambahOrder(int n, int p)
{
	map<int,int>::iterator i;
	
	i = daftarMeja.find(n);
	
	if (i != daftarMeja.end())
	{
		i->second += p;
	}
	else
	{
		daftarMeja.insert(pair<int,int>(n,p));
	}
}

int RestoranRamen::tutupOrder(int n)
{
	int harga;
	
	map<int,int>::iterator i;
	
	i = daftarMeja.find(n);
	harga = i->second;
	daftarMeja.erase(n);
	
	return harga;
}

int RestoranRamen::cekTotal(int n)
{
	int harga;
	
	map<int,int>::iterator i;
	
	i = daftarMeja.find(n);
	harga = i->second;
	
	return harga;
}

int RestoranRamen::totalMeja()
{
	return daftarMeja.size();
}

void RestoranRamen::cetakMeja()
{
	map<int,int> mejaTemp;
	
	mejaTemp = daftarMeja;
	
	map<int,int>::iterator i;
	
	if (daftarMeja.size() > 0)
	{
		while (mejaTemp.size() > 0)
		{
			i = mejaTemp.begin();
			cout << "Meja " << i->first << " = " << i->second << endl;
			mejaTemp.erase(i->first);
		}
	}
	else
	{
		cout << "Restoran kosong" << endl;
	}
}
