/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : marray.c
 * Topik     : Praktikum 03
 * Tanggal   : 13 September 2018
 * Deskripsi : Driver ADT ARRAY */

#include <stdio.h>
#include "array.h"


int CountX(TabInt T, ElType X);
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */

int main()
{
	//KAMUS
	TabInt T;
	IdxType i;
	int X;
	int n;
	
	//ALGORITMA
	MakeEmpty(&T);
	BacaIsi(&T);
	TulisIsiTab(T); printf ("\n");
	n = Neff(T);
	scanf ("%d", &X);
	printf ("%d\n", CountX(T, X));
	if ((n % 2) == 0)
	{
		i = n / 2;
	}
	else if ((n % 2) == 1)
	{
		i = (n / 2) + 1;
	}
	if (CountX(T, X) != 0)
	{
		printf ("%d\n", Search1(T, X));
		InsSortAsc(&T);
		if (X == ValMax(T))
		{
			printf ("maksimum\n");
		}
		if (X == ValMin(T))
		{
			printf ("minimum\n");
		}
		if (X == Elmt(T, i))
		{
			printf ("median\n");
		}
	}
	else
	{
		printf ("%d tidak ada\n", X);
	}
}

//PROCEDURE DAN FUNCTION
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	//KAMUS LOKAL
	IdxType i;
	int count;

	//ALGORITMA
	if (IsEmpty(T) == true)
	{
		count = 0;
	}
	else
	{
		count = 0;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (Elmt(T, i) == X)
			{
				count += 1;
			}
		}
	}
	return (count);
}
