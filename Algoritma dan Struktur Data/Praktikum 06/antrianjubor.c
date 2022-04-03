/* NIM/Nama		: 13517137/Vincent Budianto
 * Nama File	: antrianjubor.c
 * Topik		: Praktikum 06
 * Tanggal		: 4 Oktober 2018
 * Deskripsi	: Program yang mensimulasikan antrian Kantin Jubor */

#include <stdio.h>
#include "queue.h"

//Definisi Fungsi + Prosedur
float Average (Queue Q);

int main()
{
	//KAMUS
	int x;	//Ukuran Max Queue
	int y;		//Kode Operasi
	infotype z;	//Input masuk ke Queue
	Queue A;
	
	//ALGORITMA
	scanf("%d", &x);
	CreateEmpty (&A, x);
	scanf("%d", &y);
	while (y != 0)
	{
		if (y == 1)
		{
			scanf("%d", &z);
		}
		if ((y == 1) && IsFull(A))
		{
			printf("Antrian penuh\n");
		}
		else if ((y == 2) && IsEmpty(A))
		{
			printf("Antrian kosong\n");
		}
		else if (y == 1)
		{
			Add(&A, z);
		}
		else
		{
			Del(&A, &z);
		}
		scanf("%d", &y);
	}
	if (IsEmpty(A))
	{
		printf("0\n");
		printf("Tidak bisa dihitung\n");
	}
	else
	{
		printf("%d\n", NBElmt(A));
		printf("%.2f\n", Average(A));
	}
	DeAlokasi (&A);
	return 0;
}

//Realisasi Fungsi + Prosedur
float Average (Queue Q)
{
	//KAMUS LOKAL
	int i;
	infotype sum;
	infotype temp;
	
	//ALGORITMA
	i = 0;
	sum = 0;
	while (!IsEmpty(Q))
	{
		Del(&Q, &temp);
		sum += temp;
		i++;
	}
	return ((float)sum / (float)i);
}
