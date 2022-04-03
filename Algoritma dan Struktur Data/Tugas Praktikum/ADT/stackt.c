/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : stackt.c
 * Topik     : ADT STACKT
 * Tanggal   : 18 October 2018
 * Deskripsi : Realisasi ADT STACKT */

#include "stackt.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
	//Kamus
	
	//Algoritma
	Top(*S) = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	//Kamus
	
	//Algoritma
	return (Top(S) == Nil);
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	//Kamus
	
	//Algoritma
	return (Top(S) >= MaxEl);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	//Kamus
	
	//Algoritma
	Top(*S)++;
	InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack *S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	//Kamus
	
	//Algoritma
	*X = InfoTop(*S);
	Top(*S)--;
}
