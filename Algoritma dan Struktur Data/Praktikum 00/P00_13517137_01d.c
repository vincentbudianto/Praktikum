/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01d.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Dibaca T(integer), temperatur air (dalam oC) pada tekanan atmosfir */
 
#include <stdio.h>
 
int main()
{
	//KAMUS
	int T;
	
	//ALGORITMA
	scanf ("%d", &T);
	if (T <= 0)
	{
		printf ("Beku\n");
	}
	if ((T > 0) && (T <= 100))
	{
		printf ("Cair\n");
	}
	if (T > 100)
	{
		printf ("Uap\n");
	}
	return 0;
}
