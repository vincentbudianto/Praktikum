/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : bigint.c
 * Topik     : Praktikum 07
 * Tanggal   : 18 October 2018
 * Deskripsi : Driver ADT STACKT */

#include "stdio.h"
#include "stackt.h"

//Definisi Fungsi + Prosedur
int ChartoInt (char *A, int x);
int CtI (char *A);
int Fmin (int x, int y, int z);

int main()
{
	//KAMUS
	Stack S1;
	Stack S2;
	Stack SMin;
	char *x1;
	char *x2;
	int i;
	int j;
	int temp;
	int a;
	int b;
	int c;
	
	//ALGORITMA
	x1 = (char *) malloc (100 * sizeof (char));
	x2 = (char *) malloc (100 * sizeof (char));
	i = 0;
	j = 0;
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	scanf ("%s", &x1);
	while (i < 100)
	{
		Push (&S1, CtI(x1[i]));
		i++;
	}
	scanf ("%s", &x2);
	while (j < 100)
	{
		Push (&S2, CtI(x2[j]));
		j++;
	}
	if (ChartoInt(x1) < ChartoInt(x2))
	{
		printf ("-");
		while (!IsEmpty(S1) && !IsEmpty(S2))
		{
			if (a >= b)
			{
				temp = 0;
			}
			else
			{
				temp = 1;
			}
			Push (&SMin, Fmin(b, a, temp));
		}
	}
	else
	{
		while (!IsEmpty(S1) && !IsEmpty(S2))
		{
			if (a >= b)
			{
				temp = 0;
			}
			else
			{
				temp = 1;
			}
			Push (&SMin, Fmin(a, b, temp));
		}
	}
	while (!IsEmpty(SMin)
	{
		Pop(&SMin, c);
		if (c != 0)
		{
			printf("%d", c);
		}
	}
	printf("\n");
	return 0;
}

//Realisasi Fungsi + Prosedur
int ChartoInt (char *A, int x)
{
	//KAMUS LOKAL
	int i;
	int hasil;
	
	//ALGORITMA
	i = 0;
	hasil = 0;
	while ((i < 100) && ((*A)[x] != ""))
	{
		hasil = (hasil * 10) + (*A)[x];
		i++;
	}
	return (hasil);
}

int CtI (char *A)
{
	//KAMUS LOKAL
	int a;
	
	//ALGORITMA
	switch (*A) {
		case '0' : {
					   a = 0;
				   }
		case '1' : {
					   a = 1;
				   }
		case '2' : {
					   a = 2;
				   }
		case '3' : {
					   a = 3;
				   }
		case '4' : {
					   a = 4;
				   }
		case '5' : {
					   a = 5;
				   }
		case '6' : {
					   a = 6;
				   }
		case '7' : {
					   a = 7;
				   }
		case '8' : {
					   a = 8;
				   }
		case '9' : {
					   a = 9;
				   }
	}
	return (a);
}

int Fmin (int x, int y, int z)
{
	//KAMUS LOKAL
	int hasil;
	
	//ALGORITMA
	hasil = x - y - z;
	return (hasil);
}
