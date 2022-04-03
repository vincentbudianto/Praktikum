/* NIM/Nama		: 13517137/Vincent Budianto
 * Nama File	: prioqueue.c
 * Topik		: ADT PRIOQUEUE
 * Tanggal		: 4 Oktober 2018
 * Deskripsi	: Realisasi ADT PRIOQUEUE */

#include <stdlib.h>
#include "prioqueue.h"
 
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	//Kamus
    
	//Algoritma
	return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	//Kamus
    
	//Algoritma
    return (NBElmt(Q) == MaxEl(Q));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//Kamus
    
	//Algoritma
	if (IsEmpty(Q))
		return 0;
	else
		return (((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q)) + 1);
}

/* *** Kreator *** */
void CreateEmpty (Queue *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	//Kamus
    
	//Algoritma
	DeAlokasi(Q);
	(*Q).T = (infotype*) malloc((Max + 1) * sizeof(infotype));
	MaxEl(*Q) = Max;
}

/* *** Destruktor *** */
void DeAlokasi(Queue *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	//Kamus
    
	//Algoritma
	if (Q == Nil)
	{
		Q = (Queue *) malloc(sizeof(Queue));
	}
	if ((*Q).T != Nil)
	{
		free((*Q).T);
	}
	MaxEl(*Q) = 0;
	Head(*Q) = 0;
	Tail(*Q) = 0;

}

/* *** Primitif Add/Delete *** */
void Add (Queue *Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
	//Kamus
    int i;
    int previ;
    boolean insert;
    infotype temp;
    
	//Algoritma
	if (IsEmpty(*Q))
	{
		Head(*Q) = 1;
	}
	Tail(*Q) = Tail(*Q) % MaxEl(*Q) + 1;
	i = Tail(*Q);
	InfoTail(*Q) = X;	
	insert = true;
	while (i != Head(*Q) && insert)
	{
		previ = i - 1 == 0 ? MaxEl(*Q) : i - 1;
		if (Prio(Elmt(*Q,i)) > Prio(Elmt(*Q,previ)))
		{
			temp = Elmt(*Q,i);
			Elmt(*Q,i) = Elmt(*Q,previ);
			Elmt(*Q,previ) = temp;
		}
		else
		{
			insert = false;
		}
		i = previ;
	}
}
void Del (Queue *Q, infotype *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	//Kamus
    
	//Algoritma
	*X = InfoHead(*Q);
	if (NBElmt(*Q) == 1)
	{
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else
	{
		Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
	}
}

/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	//Kamus
	infotype last;
	
	//Algoritma
	while (!IsEmpty(Q))
	{
		Del(&Q, &last);
		printf("%d %d\n", Prio(last), Info(last)); 
	}
	printf("#\n");

}
