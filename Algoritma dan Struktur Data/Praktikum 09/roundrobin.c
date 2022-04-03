/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : roundrobin.c
 * Topik     : Praktikum 09
 * Tanggal   : 01 November 2018
 * Deskripsi : Driver ADT LISTSIRKULER */

#include <stdio.h>
#include "listsirkuler.h"
#include "boolean.h"

//Definisi Fungsi + Prosedur
void RoundRobin (List *L, infotype TQ);
/* Menghapus elemen terakhir sesuai aturan round robin */
/* Jika nilai elemen terakhir lebih besar dari TQ maka elemen diantrikan kembali dengan nilai elemen dikurangi TQ */
/* Jika nilai elemen terakhir lebih kecil dari TQ maka elemen dihapus dari list dan ditampilkan ke layar */
float Average (List L);
/* Mengirimkan nilai rata-rata dari seluruh elemen list L */

//Program Utama
int main()
{
	//Kamus
	char input[2];
	int x;
	int TQ;
	List list;
	
	//Algoritma
	TQ = 0
	do {
		scanf("%d", &TQ);
	} while (TQ <= 0);
	CreateEmpty(&L);
	scanf("%s", input);
	while (input[0] != 'F')
	{
		switch (input[0]) {
			case 'A':
				scanf("%d", &x);
				if (x > 0)
				{
					InsVFirst(&L, x);
				}
				break;
			case 'D':
				{
					RoundRobin(&L, TQ);
				}
				break;
			default:
				{
					printf("Kode salah\n");
					break;
				}
		}
		scanf("%s", input);
	}
	if (IsEmpty(L))
	{
		printf("Proses selesai\n");
	}
	else
	{
		printf("%.2f\n", Average(L));
	}
	return 0;
}

//Realisasi Fungsi + Prosedur
void RoundRobin (List *L, infotype TQ)
/* Menghapus elemen terakhir sesuai aturan round robin */
/* Jika nilai elemen terakhir lebih besar dari TQ maka elemen diantrikan kembali dengan nilai elemen dikurangi TQ */
/* Jika nilai elemen terakhir lebih kecil dari TQ maka elemen dihapus dari list dan ditampilkan ke layar */
{
	//Kamus
	address last;
	infotype a;
	
	//Algoritma
	if (IsEmpty(*L))
	{
		printf("List kosong\n");
	}
	else
	{
		last = First(*L);
		while (Next(last) != First(*L))
		{
			last = Next(last);
		}
		if (Info(last) > TQ)
		{
			printf("%d\n", TQ);
			Info(last) -= TQ;
			First(*L) = last;
		}
		else
		{
			printf("%d\n", Info(last));
			DelVLast(L, &a);
		}
	}
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
	do {
		sum += Info(p);
		count++;
		p = Next(p);
	} while (p != First(L));
	return ((float)sum / (float)count);
}
