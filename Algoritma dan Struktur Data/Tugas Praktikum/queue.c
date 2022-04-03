/* File : queue.c */
/* Implementasi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi */
{    /* Kamus Lokal */
    /* Algoritma */
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{    /* Kamus Lokal */
    /* Algoritma */
    return (Head(Q) == (Tail(Q) % MaxEl(Q)) + 1);
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{    /* Kamus Lokal */
    /* Algoritma */
    if (!IsEmpty(Q)) {
        if (Head(Q) <= Tail(Q)) {
            return (Tail(Q)-Head(Q)+1);
        } else { /* Head(Q) > Tail(Q) */
            return ((MaxEl(Q)-Head(Q)+1) + Tail(Q));
        }
    } else {
        return 0;
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, Membuat sebuah Q kosong */
{    /* Kamus Lokal */
    /* Algoritma */
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    } else { /* Alokasi gagal */
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{    /* Kamus Lokal */
    /* Algoritma */
    free((*Q).T);
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{    /* Kamus Lokal */
    /* Algoritma */
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    } else { /* Q tidak kosong */
        if (Tail(*Q) < MaxEl(*Q)) {
            Tail(*Q)++;
        } else { /* Tail(*Q) = MaxEl(*Q) */
            Tail(*Q) = 1;
        }
    }
    InfoTail(*Q) = X;
}
void Del(Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{    /* Kamus Lokal */
    /* Algoritma */
    *X = InfoHead(*Q);
    if (Head(*Q)==Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else { /* Q > 1 elemen */
        if (Head(*Q) < MaxEl(*Q)) {
            Head(*Q)++;
        } else { /* Head(*Q) = MaxEl(*Q) */
            Head(*Q) = 1;
        }
    }
}
