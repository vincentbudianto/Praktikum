/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : listurut.c
 * Topik     : Praktikum 09
 * Tanggal   : 01 November 2018
 * Deskripsi : Driver ADT LISTDP */
 
#include <stdio.h>
#include "listdp.h"
#include "boolean.h"

//Definisi Fungsi + Prosedur
address SearchPrec (List L, infotype X);
/* Mengirimkan address elemen sebelum elemen yang nilainya>=X */
void InsertUrut (List *L, infotype X);
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L */
infotype Max (List L);
/* Mengirimkan nilai info(P) maksimum */
infotype Min (List L);
/* Mengirimkan nilai info(P) minimum */
float Average (List L);
/* Mengirimkan nilai rata-rata dari seluruh elemen list L */

//Program Utama
int main()
{
	//Kamus
	infotype x;
	List L;
	
	//Algoritma
	CreateEmpty(&L);
	scanf("%d", &x);
	while (x != -9999)
	{
		InsertUrut(&L, x);
		scanf("%d", &x);
	}
	if (IsEmpty(L))
	{
		printf("[]\n");
	}
	else
	{
		printf("%d\n%d\n%.2f\n", Max(L), Min(L), Average(L));	
		PrintForward(L); printf("\n");
		PrintBackward(L); printf("\n");
	}
	return 0;
}

//Realisasi Fungsi + Prosedur
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya>=X */
{
	//Kamus
	address p;
	address q;
	boolean found;
	
	//Algoritma
	p = First(L);
	q = Nil;
	found = false;
	while ((!found) && (p != Nil))
		if (Info(p) >= X)
		{
			q = Prev(p);
			found = true;
		}
		else
		{
			p = Next(p);
		}
	return (q);
}
void InsertUrut (List *L, infotype X)
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L */
{
	//Kamus
	
	//Algoritma
	if (IsEmpty(*L))
		InsVLast(L, X);
	else {
		address prev = SearchPrec(*L,X);
		if (prev == Nil) {
			if (Info(First(*L)) < X)
				InsVLast(L, X);
			else
				InsVFirst(L, X);
		} else
			InsertAfter(L, Alokasi(X), prev);
	}
}
infotype Max (List L)
/* Mengirimkan nilai info(P) maksimum */
{
	//Kamus
	address p;
	infotype max;
	
	//Algoritma
	p = Next(First(L));
	max = Info(First(L));
	while (p != Nil) {
		if (Info(p) > max)
			max = Info(p);
		p = Next(p);
	}
	return (max);
}
infotype Min (List L)
/* Mengirimkan nilai info(P) minimum */
{
	//Kamus
	address p;
	infotype min;
	
	//Algoritma
	p = Next(First(L));
	min = Info(First(L));
	while (p != Nil)
	{
		if (Info(p) < min)
		{
			min = Info(p);
		}
		p = Next(p);
	}
	return (min);
}
float Average (List L)
/* Mengirimkan nilai rata-rata dari seluruh elemen list L */
{
	//Kamus
	address p
	float sum;
	int count;
	
	//Algoritma
	p = First(L);
	count = 0;
	sum = 0;
	while (p != Nil)
	{
		sum += Info(p);
		count++;
		p = Next(p);
	}
	return ((float)sum / (float)count);
}
