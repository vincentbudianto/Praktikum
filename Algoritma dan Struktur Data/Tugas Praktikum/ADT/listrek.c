/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : listrek.c
 * Topik     : ADT LISTREK
 * Tanggal   : 08 November 2018
 * Deskripsi : Realisasi ADT LISTREK */

#include <stdlib.h>
#include "listrek.h"

/* *** Manajemen Memori *** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//Kamus
	address P;
	
	//Algoritma
	P = (address) malloc(sizeof(infotype));
	if (P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
	}
	return (P);
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	//Kamus
	
	//Algoritma
	free(P);
}

/* Pemeriksaan Kondisi List */
int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
	//Kamus
	
	//Algoritma
	return (L == Nil);
}
int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
	//Kamus
	
	//Algoritma
	if (!(IsEmpty(L)))
	{
		return (Next(L) == Nil);
	}
	else
	{
		return 0;
	}
}

/* *** Selektor *** */
infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
	//Kamus
	
	//Algoritma
	return (Info(L));
}
List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
	//Kamus
	
	//Algoritma
	return (Next(L));
}

/* *** Konstruktor *** */
List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
	//Kamus
	address P;
	
	//Algoritma
	P = Alokasi(e);
	if (P == Nil)
	{
		return (L);
	}
	else
	{
		Next(P) = L;
		return (P);
	}
}
List KonsB(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
	//Kamus
	address i;
	address j;
	address P;
	
	//Algoritma
	P = Alokasi(e);
	if (P != Nil)
	{
		if (IsEmpty(L))
		{
			return (P);
		}
		else
		{
			i = L;
			j = Nil;
			while (i != Nil)
			{
				j = i;
				i = Next(i);
			}
			Next(j) = P;
		}
	}
	return (L);

}

/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
{
	//Kamus
	
	//Algoritma
	if (IsEmpty(L))
	{
		return (Nil);
	}
	else
	{
		return (Konso(Info(L), Tail(L)));
	}
}
void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
	//Kamus
	List L;
	
	//Algoritma
	L = Copy(Lin);
	*Lout = L;
}
List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
	//Kamus
	
	//Algoritma
	if (IsEmpty(L1))
	{
		return (L2);
	}
	else if (IsEmpty(L2))
	{
		return (L1);
	}
	else
	{
		return (Concat(KonsB(L1, Info(L2)), Tail(L2)));
	}
}
void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
	//Kamus
	
	//Algoritma
	*LHsl = Concat(L1, L2);
}
void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
	//Kamus
	
	//Algoritma
	if (!IsEmpty(L))
	{
		printf("%d\n", FirstElmt(L));
		PrintList(Tail(L));
	}
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
	//Kamus
	
	//Algoritma
	if (IsEmpty(L))
	{
		return 0;
	}
	else
	{
		return (1 + NbElmtList(Tail(L)));
	}
}
boolean Search (List L, infotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
	//Kamus
	
	//Algoritma
	if (IsEmpty(L))
	{
		return (false);
	}
	else if (Info(L) == X)
	{
		return (true);
	}
	else
	{
		return (Search(Tail(L), X));
	}
}

/* *** Operasi-Operasi Lain *** */
List InverseList (List L)
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
	//Kamus
	
	//Algoritma
	if (L == Nil)
	{
		return (Nil);
	}
	else
	{
		return (KonsB(InverseList(Tail(L)), FirstElmt(L)));
	}
}
void SplitPosNeg (List L, List *L1, List *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
{
	//Kamus
	
	//Algoritma
	if (L != Nil)
	{
		if (FirstElmt(L) >= 0)
		{
			*L1 = KonsB(*L1, FirstElmt(L));
		}
		else
		{
			*L2 = KonsB(*L2, FirstElmt(L));
		}
		SplitPosNeg(Tail(L), L1, L2);
	}
}
void SplitOnX (List L, infotype X, List *L1, List *L2)
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
{
	//Kamus
	
	//Algoritma
	if (L != Nil)
	{
		if (FirstElmt(L) < X)
		{
			*L1 = KonsB(*L1, FirstElmt(L));
		}
		else
		{
			*L2 = KonsB(*L2, FirstElmt(L));
		}
		SplitOnX(Tail(L), X, L1, L2);
	}
}
int ListCompare (List L1, List L2)
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
{
	//Kamus
	
	//Algoritma
	if (L1 == Nil && L2 == Nil)
	{
		return 0;
	}
	else if (L1 == Nil)
	{
		return -1;
	}
	else if (L2 == Nil)
	{
		return 1;
	}
	else if (FirstElmt(L1) < FirstElmt(L2))
	{
		return -1;
	}
	else if (FirstElmt(L1) == FirstElmt(L2))
	{
		return ListCompare(Tail(L1), Tail(L2));
	}
	else
	{
		return 1;
	}
}
boolean IsAllExist (List L1, List L2)
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
{
	//Kamus
	
	//Algoritma
	if (L1 == Nil)
	{
		return (true);
	}
	else
	{
		return ((Search(L2, FirstElmt(L1))) && (IsAllExist(Tail(L1), L2)));
	}
}

/* *** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
	//Kamus
	infotype x;
	
	//Algoritma
	if (IsOneElmt(L))
	{
			return (FirstElmt(L));
	}
	else
	{
		x = Max(Tail(L));
		if (x > FirstElmt(L))
		{
			return (x);
		}
		else
		{
			return (FirstElmt(L));
		}
	}
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
	//Kamus
	infotype x;
	
	//Algoritma
	if (IsOneElmt(L))
	{
			return (FirstElmt(L));
	}
	else
	{
		x = Min(Tail(L));
		if (x < FirstElmt(L))
		{
			return (x);
		}
		else
		{
			return (FirstElmt(L));
		}
	}
}
infotype SumList (List L)
/* Mengirimkan total jumlah elemen List L */
{
	//Kamus
	
	//Algoritma
	if (L == Nil)
	{
		return 0;
	}
	else
	{
		return (FirstElmt(L) + SumList(Tail(L)));
	}
}
float Average (List L)
/* Mengirimkan nilai rata-rata elemen list L */
{
	//Kamus
	
	//Algoritma
	return ((float)SumList(L) / (float)NbElmtList(L));
}
