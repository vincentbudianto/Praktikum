/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : undian.c
 * Topik     : Praktikum 10
 * Tanggal   : 08 November 2018
 * Deskripsi : Driver ADT LISTREK */
  
#include <stdio.h>
#include "listrek.c"

//Definisi Fungsi + Prosedur
List SplitOddIndex(List L);
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
List SplitEvenIndex(List L);
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
List SplitBeforeX(List L, infotype X);
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai X pada list L, sesuai dengan urutannya. Jika X tidak ada pada list, maka
kembalikan list L.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
List ReverseList(List L);
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list L.
Jika L kosong, kembalikan list kosong. */

//Program Utama
int main ()
{
	//Kamus
	char X;
	infotype k;
	List L;
	List temp;
	
	//Algoritma
	L = Nil;
	scanf("%c", &X);
	while (X != 'X')
	{
		switch (X)
		{
			case 'F' :
			{
				scanf("%d", &k);
				temp = ReverseList(L);
				temp = KonsB(temp, k);
				L = ReverseList(temp);
				break;
			}
			case 'B' :
			{
				scanf("%d", &k);
				L = KonsB(L, k);
				break;
			}
			case 'O' :
			{
				L = SplitOddIndex(L);
				break;
			}
			case 'E' :
			{
				L = SplitEvenIndex(L);
				break;
			}
			case 'R' :
			{
				L = ReverseList(L);
				break;
			}
			case 'P' :
			{
				scanf("%d", &k);
				L = SplitBeforeX(L,k);
				break;
			}
		}
		scanf("%c", &X);
	}
	if (IsEmpty(L))
	{
		printf("Semua gugur\n");
	}
	else
	{
		PrintList(L);
	}
	return 0;
}

//Realisasi Fungsi + Prosedur
List SplitOddIndex(List L)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
{
	//Kamus
	int i;
	List Ln;
	
	//Algoritma
	Ln = Nil;
	if (!IsEmpty(L))
	{
		for (i = 1; i <= NbElmtList(L); i++)
		{
			if (i % 2 == 1)
			{
				Ln = KonsB(Ln, FirstElmt(L));
			}
			L = Tail(L);
		}
	}
	return (Ln);
}
List SplitEvenIndex(List L)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
{
	//Kamus
	int i;
	List Ln;
	
	//Algoritma
	Ln = Nil;
	if (!IsEmpty(L))
	{
		for (i = 1; i <= NbElmtList(L); i++)
		{
			if (i % 2 == 0)
			{
				Ln = KonsB(Ln, FirstElmt(L));
			}
			L = Tail(L);
		}
	}
	return (Ln);
}
List SplitBeforeX(List L, infotype X)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai X pada list L, sesuai dengan urutannya. Jika X tidak ada pada list, maka
kembalikan list L.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
{
	//Kamus
	boolean found;
	List Ln;
	
	//Algoritma
	found = false;
	if (Search(L, X))
	{
		Ln = Nil;
		while (!found)
		{
			if (FirstElmt(L) == X)
			{
				found = true;
			}
			else
			{
				Ln = KonsB(Ln, FirstElmt(L));
				L = Tail(L);
			}
		}
		return (Ln);
	}
	else
	{
		return (L);
	}
}
List ReverseList(List L)
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list L.
Jika L kosong, kembalikan list kosong. */
{
	//Kamus
	
	//Algoritma
	if (L == Nil)
	{
		return (Nil);
	}
	else
	{
		return (KonsB(ReverseList(Tail(L)), FirstElmt(L)));
	}
}
