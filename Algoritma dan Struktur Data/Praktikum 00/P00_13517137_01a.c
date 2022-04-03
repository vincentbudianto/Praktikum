/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01a.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Menulis "HELLO" berikut nama yang diberikan dari piranti masukan ke piranti keluaran */

#include <stdio.h>

int main()
{
	//KAMUS
	char name[20];

	//ALGORITMA
	scanf ("%s", name);
	printf("HELLO %s\n", name);
	return 0;
}
