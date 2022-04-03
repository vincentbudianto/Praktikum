/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : listdp.c
 * Topik     : ADT LISTDP
 * Tanggal   : 01 November 2018
 * Deskripsi : Realisasi ADT LISTDP */

#include <stdlib.h>
#include "listdp.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	//Kamus
	
	//Algoritma
	return ((First(L) == Nil) && (Last(L) == Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	//Kamus
	
	//Algoritma
	First(*L) = Nil;
	Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	//Kamus
	address p;
	
	//Algoritma
	p = (address) malloc(sizeof(ElmtList));
	if (p != Nil)
	{
		Info(p) = X;
		Next(p) = Nil;
		Prev(p) = Nil;
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	//Kamus
	address i;
	address p;
	
	//Algoritma
	i = First(L);
	p = Nil;
	while ((p == Nil) && (i != Nil))
	{
		if (Info(i) == X)
		{
			p = i;
		}
		i = Next(i);
	}
	return (p);
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
		Next(p) = First(*L);
		if (First(*L) != Nil)
		{
			Prev(First(*L)) = p;
		}
		First(*L) = p;
		if (Last(*L) == Nil)
		{
			Last(*L) = p;
		}
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
		Prev(p) = Last(*L);
		if (Last(*L) != Nil)
		{
			Next(Last(*L)) = p;
		}
		Last(*L) = p;
		if (First(*L) == Nil)
		{
			First(*L) = p;
		}
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
	*X = Info(First(*L));
	p = First(*L);
	First(*L) = Next(p);
	if (First(*L) != Nil)
	{
		Prev(First(*L)) = Nil;
	}
	else
	{
		Last(*L) = Nil;
	}
	Dealokasi(p);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//Kamus
	address p;
	
	//Algoritma
	*X = Info(Last(*L));
	p = Last(*L);
	Last(*L) = Prev(p);
	if (Last(*L) != Nil)
	{
		Next(Last(*L)) = Nil;
	}
	else
	{
		First(*L) = Nil;
	}
	Dealokasi(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	//Kamus
	
	//Algoritma
	Next(P) = First(*L);
	if (First(*L) != Nil)
	{
		Prev(First(*L)) = P;
	}
	else
	{
		Last(*L) = P;
		Next(Last(*L)) = Nil;
	}
	First(*L) = P;
	Prev(First(*L)) = Nil;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//Kamus
	
	//Algoritma
	Prev(P) = Last(*L);
	if (Last(*L) != Nil)
	{
		Next(Last(*L)) = P;
	}
	else
	{
		First(*L) = P;
		Prev(First(*L)) = Nil;
	}
	Last(*L) = P;
	Next(Last(*L)) = Nil;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Kamus
	
	//Algoritma
	Prev(P) = Prec;
	Next(P) = Next(Prec);
	Next(Prec) = P;
	if (Next(P) != Nil)
	{
		Prev(Next(P)) = P;
	}
	else
	{
		Last(*L) = P;
		Next(Last(*L)) = Nil;
	}
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	//Kamus
	
	//Algoritma
	Next(P) = Succ;
	Prev(P) = Prev(Succ);
	Prev(Succ) = P;
	if (Prev(P) != Nil)
	{
		Next(Prev(P)) = P;
	}
	else
	{
		First(*L) = P;
		Prev(First(*L)) = Nil;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	//Kamus
	
	//Algoritma
	*P = First(*L);
	First(*L) = Next(First(*L));
	if (First(*L) == Nil)
	{
		Last(*L) = Nil;
	}
	else
	{
		Prev(First(*L)) = Nil;
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	//Kamus
	
	//Algoritma
	*P = Last(*L);
	Last(*L) = Prev(Last(*L));
	if (Last(*L) == Nil)
	{
		First(*L) = Nil;
	}
	else
	{
		Next(Last(*L)) = Nil;
	}
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//Kamus
	address p;
	address q;
	
	//Algoritma
	p = First(*L);
	while (p != Nil)
	{
		q = Next(p);
		if (Info(p) == X)
		{
			if (Prev(p) != Nil)
			{
				Next(Prev(p)) = Next(p);
			}
			else
			{
				First(*L) = Next(p);
				if (First(*L) != Nil)
				{
					Prev(First(*L)) = Nil;
				}
			}
			if (Next(p) != Nil)
			{
				Prev(Next(p)) = Prev(p);
			}
			else
			{
				Last(*L) = Prev(p);
				if (Last(*L) != Nil)
				{
					Next(Last(*L)) = Nil;
				}
			}
			Dealokasi(p);
		}
		p = q;
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	//Kamus
	address p;
	
	//Algoritma
	*Pdel = Next(Prec);
	p = Next(Prec);
	if (p != Nil)
	{
		if (Next(p) != Nil)
		{
			Prev(Next(p)) = Prec;
		}
		else
		{
			Last(*L) = Prec;
			Next(Last(*L)) = Nil;
		}
		Next(Prec) = Next(p);
	}
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	//Kamus
	address p;
	
	//Algoritma
	*Pdel = Prev(Succ);
	p = Prev(Succ);
	if (p != Nil)
	{
		if (Prev(p) != Nil)
		{
			Next(Prev(p)) = Succ;
		}
		else
		{
			First(*L) = Succ;
			Prev(First(*L)) = Nil;
		}
		Prev(Succ) = Prev(p);
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//Kamus
	address p;
	boolean cek;
	
	//Algoritma
	printf("[");
	p = First(L);
	cek = true;
	while (p != Nil)
	{
		if (!cek)
		{
			printf(",");
		}
		printf("%d", Info(p));
		cek = false;
		p = Next(p);
	}
	printf("]");
}
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//Kamus
	address p;
	boolean cek;
	
	//Algoritma
	printf("[");
	p = Last(L);
	cek = true;
	while (p != Nil) {
		if (!cek)
			printf(",");
		printf("%d", Info(p));
		cek = false;
		p = Prev(p);
	}
	printf("]");
}
