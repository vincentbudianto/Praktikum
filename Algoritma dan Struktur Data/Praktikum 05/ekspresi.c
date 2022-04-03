/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : ekspresi.c
 * Topik     : Praktikum 05
 * Tanggal   : 27 September 2018
 * Deskripsi : Driver ADT MESINTOKEN */
 
#include "stdio.h"
#include "mesintoken.h"

int main()
{
	//KAMUS
	
	//ALGORITMA
	STARTTOKEN();
	if (EndToken)
	{
		printf("Ekspresi kosong\n");
	}
	else
	{
		while (!EndToken)
		{
			if (CToken.tkn != 'b')
			{
				printf("%c\n", CToken.tkn);
			}
			else
			{
				printf("%d\n", CToken.val);
			}
			ADVTOKEN();
		}
	}
	return 0;
}
