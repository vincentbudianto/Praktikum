/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : daftarnilai.c
 * Topik     : Praktikum 08
 * Tanggal   : 25 Oktober 2018
 * Deskripsi : Driver ADT LISTLINEAR */

#include <stdio.h>
#include "listlinier.c"

void Del (List *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
List SortList (List L);
/* I.S. L sembarang */
/* F.S. elemen list L terurut secara membesar */
/* Elemen pertama menjadi elemen dengan nilai terkecil */
/* Elemen terakhir menjadi elemen dengan nilai terbesar */

int main()
{
	//KAMUS
	List L;
	List Ln;
	int x;
	
	//ALGORITMA
	CreateEmpty(&L);
	scanf("%d", &x);
	while (x >= 0 && x <= 100)
	{
		if (x >= 0 && x <= 100)
		{
			InsVFirst(&L, x);
		}
		scanf("%d", &x);
	}
	if (IsEmpty(L))
	{
		printf("Daftar nilai kosong\n");
	}
	else
	{
		printf("%d\n", NbElmt(L));
		printf("%d\n", Max(L));
		printf("%d\n", Min(L));
		printf("%.2f\n", Average(L));
		Ln = SortList(L);
		PrintInfo(Ln);
		printf("\n");
		InversList(&Ln);
		PrintInfo(Ln);
		printf("\n");
	}
}

void Del (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//Kamus
	address i;
	address bi;
	address q;
	boolean cek;
	
	//Algoritma
	i = First(*L);
	bi = Nil;
	cek = false;
	while ((!cek) && (i != Nil))
	{
		if (Info(i) == X)
		{
			if (bi != Nil)
			{
				Next(bi) = Next(i);
			}
			else
			{
				First(*L) = Next(i);
			}
			q = Next(i);
			Dealokasi(&i);
			i = q;
			cek = true;
		}
		else
		{
			bi = i;
			i = Next(i);
		}
	}
}
List SortList (List L)
/* I.S. L sembarang */
/* F.S. elemen list L terurut secara membesar */
/* Elemen pertama menjadi elemen dengan nilai terkecil */
/* Elemen terakhir menjadi elemen dengan nilai terbesar */
{
	//KAMUS LOKAL
	List Ln;
	
	//ALGORITMA
	CreateEmpty(&Ln);
	InsVFirst(&Ln, Min(L));
	Del(&L, Min(L));
	while (!IsEmpty(L))
	{
		InsVLast(&Ln, Min(L));
		Del(&L, Min(L));
	}
	return (Ln);
}
