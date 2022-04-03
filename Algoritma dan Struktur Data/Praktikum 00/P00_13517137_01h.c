/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01h.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Menghitung deret S = 1 - 1/2 + 1/3 - 1/4 + ... + 1/999 - 1/1000 */
 
#include <stdio.h>
 
int main()
{
	//KAMUS
	const int N = 1000;
	int i;
	int TANDA; //-1 || 1
	float S; //>= 0.0
	
	//ALGORITMA
	TANDA = 1;
	S = 1;
	i = 2;
	while (i <= N)
	{
		TANDA = - TANDA;
		S += (float)TANDA/i;
		i++;
	}
	printf ("%f\n", S);
	return 0;
}
