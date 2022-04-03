/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : cipher.c
 * Topik     : Praktikum 05
 * Tanggal   : 27 September 2018
 * Deskripsi : Driver ADT MESINKATA */

#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"

int main()
{
	//KAMUS
	char a;
	int i;
	int N;
	
	//ALGORITMA
	STARTKATA();
	N = CKata.Length;
	while (!EndKata) 
	{
		for (i = 1; i <= CKata.Length; i++)
		{
			a = CKata.TabKata[i] + N;
			if (a > 'Z')
			{
				a -= 26;
			}
			printf("%c", a);
		}
		if (CC != MARK)
		{
			printf(" ");
		}
		ADVKATA();
	}
	printf(".\n");
	return 0;
}
