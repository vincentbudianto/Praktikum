/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01f.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Program yang membaca 3 buah integer dan “memutar” 3 buah integer tersebut (Jika inputnya: a=A dan b=B, dan c=C, maka outputnya: a=C, b=A, c=B) */
 
#include <stdio.h>

//PROCEDURE
void PROCTUKAR (int *a, int *b);
// Prosedur untuk menukar dua buah harga yang tersimpan dalam dua nama integer
// I.S. : a = A dan b = B
// F.S. : a = B dan b = A

//ALGORITMA UTAMA
int main()
{
	//KAMUS
	int a;
	int b;
	int c;
	
	//ALGORITMA
	scanf ("%d %d %d", &a, &b, &c);
	PROCTUKAR (&a, &c);
	PROCTUKAR (&b, &c);
	printf ("%d %d %d\n", a, b, c);
	return 0;
}

//ALGORITMA PROCEDURE PROCTUKAR
void PROCTUKAR (int *a, int *b)
{
	//KAMUS LOKAL
	int Temp;
	
	//ALGORITMA
	Temp = *a;
	*a = *b;
	*b = Temp;
}
