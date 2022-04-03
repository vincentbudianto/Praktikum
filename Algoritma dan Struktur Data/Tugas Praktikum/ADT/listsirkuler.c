/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : listsirkuler.c
 * Topik     : ADT LISTSIRKULER
 * Tanggal   : 01 November 2018
 * Deskripsi : Realisasi ADT LISTSIRKULER */

#include <stdlib.h>
#include "listsirkuler.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	//Kamus
	
	//Algoritma
	return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	//Kamus
	
	//Algoritma
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//Kamus
	address p;
	
	//Algoritma
	p = (address) malloc(sizeof(ElmtList));
	if (p != Nil)
	{
		Info(p) = X;
		Next(p) = Nil;
	}
	return (p);
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	//Kamus
	address p;
	address q;
	
	//Algoritma
	if (!IsEmpty(L))
	{
		p = First(L);
		q = Nil;
		do
		{
			if (Info(p) == X)
			{
				q = p;
			}
			p = Next(p);
		} while ((q == Nil) && (p != First(L)));
		return (q);
	} 
	else
	{
		return (Nil);
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	//Kamus
	address p;
	
	//Algoritma
	p = Alokasi(X);
	if (p != Nil)
	{
		InsertFirst(L, p);
	}
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	//Kamus
	address p;
	
	//Algoritma
	p = Alokasi(X);
	if (p != Nil)
	{
		InsertLast(L, p);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//Kamus
	address p;
	
	//Algoritma
	DelFirst(L, &p);
	*X = Info(p);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//Kamus
	address p;
	
	//Algoritma
	DelLast(L, &p);
	*X = Info(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	//Kamus
	address last;
	
	//Algoritma
	if (IsEmpty(*L))
	{
		First(*L) = P;
		Next(P) = P;
	}
	else
	{
		last = First(*L);
		while (Next(last) != First(*L))
		{
			last = Next(last);
		}
		Next(P) = First(*L);
		First(*L) = P;
		Next(last) = P;
	}
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//Kamus
	address last;
	
	//Algoritma
	if (IsEmpty(*L))
	{
		First(*L) = P;
		Next(P) = P;
	}
	else
	{
		last = First(*L);
		while (Next(last) != First(*L))
		{
			last = Next(last);
		}
		Next(P) = First(*L);
		Next(last) = P;
	}
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Kamus
	
	//Algoritma
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	//Kamus
	address last;
	
	//Algoritma
	*P = First(*L);
	if (Next(First(*L)) == First(*L))
	{
		First(*L) = Nil;
	}
	else
	{
		last = First(*L);
		while (Next(last) != First(*L))
		{
			last = Next(last);
		}
		First(*L) = Next(First(*L));
		Next(last) = First(*L);
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	//Kamus
	address last;
	address blast;
	
	//Algoritma
	if (Next(First(*L)) == First(*L))
	{
		*P = First(*L);
		First(*L) = Nil;
	}
	else
	{
		last = First(*L);
		blast = Nil;
		while (Next(last) != First(*L))
		{
			blast = last;
			last = Next(last);
		}
		*P = last;
		Next(blast) = First(*L);
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	//Kamus
	
	//Algoritma
	*Pdel = Next(Prec);
	if (Next(Prec) == Prec)
	{
		First(*L) = Nil;
	}
	else
	{
		if (Next(Prec) == First(*L))
		{
			First(*L) = Next(Next(Prec));
		}
		Next(Prec) = Next(Next(Prec));
	}
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//Kamus
	address p;
	address prec;
	boolean found;
	
	//Algoritma
	p = First(*L);
	prec = First(*L);
	while (Next(prec) != First(*L))
	{
		prec = Next(prec);
	}
	found = false;
	do
	{
		if (Info(p) == X)
		{
			if (prec == p)
			{
				First(*L) = Nil;
			}
			else
			{
				if (p == First(*L))
				{
					First(*L) = Next(p);
				}
				Next(prec) = Next(p);
			}
			found = true;
		}
		prec = p;
		p = Next(p);
	} while ((!found) && (p != First(*L)));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//Kamus
	address p;
	boolean cek;
	
	//Algoritma
	printf("[");
	if (!IsEmpty(L)) {
		p = First(L);
		cek = true;
		do {
			if (!cek)
				printf(",");
			printf("%d", Info(p));
			p = Next(p);
			cek = false;
		} while (p != First(L));
	}
	printf("]");
}
