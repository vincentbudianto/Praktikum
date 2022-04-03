/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01b.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Dibaca arus I dan hambatan R, dihitung besarnya tegangan V = I * R  dan dituliskan hasilnya */

#include <stdio.h>

int main()
{
	//KAMUS
	float I; //Arus listrik, ampere
	float R; //Hambatan, ohm
	float V; //Tegangan listrik, volt

	//ALGORITMA
	printf ("Input nilai arus : "); scanf ("%f", &I);
	printf ("Input nilai hambatan : "); scanf ("%f", &R);
	V = I * R;
	printf ("Tegangan listrik = %f volt\n", V);
	return 0;
}
