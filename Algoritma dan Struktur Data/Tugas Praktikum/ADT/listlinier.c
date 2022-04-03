/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : listlinier.c
 * Topik     : ADT LISTLINIER
 * Tanggal   : 25 Oktober 2018
 * Deskripsi : Realisasi ADT LISTLINIER */

#include <stdlib.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	//Kamus
	
	//Algoritma
	return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
{
	//Kamus
	
	//Algoritma
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
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
	return p;

}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	//Kamus
	
	//Algoritma
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	//Kamus
	address p;
	address i;
	
	//Algoritma
	p = First(L);
	i = Nil;
	while ((i == Nil) && (p != Nil))
	{
		if (Info(p) == X)
		{
			i = p;
		}
		p = Next(p);
	}
	return (i);

}
boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	//Kamus
	address i;
	boolean found;
	
	//Algoritma
	i = First(L);
	found = false;
	while ((!found) && (i != Nil))
	{
		if (i == P)
		{
			found = true;
		}
		i = Next(i);
	}
	return (found);
}
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	//Kamus
	address p;
	address prec;
	boolean found;
	
	//Algoritma
	p = First(L);
	prec = Nil;
	found = false;
	while ((!found) && (p != Nil))
	{
		if (Info(p) == X)
		{
			found = true;
		}
		else
		{
			prec = p;
			p = Next(p);
		}
	}
	if (found)
	{
		return (prec);
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
		Next(p) = First(*L);
		First(*L) = p;
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
	address last;
	
	//Algoritma
	p = First(*L);
	last = Nil;
	while (p != Nil)
	{
		last = p;
		p = Next(p);
	}
	if (last == Nil)
	{
		First(*L) = Alokasi(X);
	}
	else
	{
		Next(last) = Alokasi(X);
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
	p = First(*L);
	First(*L) = Next(p);
	*X = Info(p);
	Dealokasi(&p);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//Kamus
	address p;
	address last;
	address blast;
	
	//Algoritma
	p = First(*L);
	last = Nil;
	blast = Nil;
	while (p != Nil)
	{
		blast = last;
		last = p;
		p = Next(p);
	}
	if (blast != Nil)
	{
		Next(blast) = Nil;
	}
	else
	{
		First(*L) = Nil;
	}
	*X = Info(last);
	Dealokasi(&last);
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
	First(*L) = P;
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
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//Kamus
	address i;
	address last;
	
	//Algoritma
	i = First(*L);
	last = Nil;
	while (i != Nil)
	{
		last = i;
		i = Next(i);
	}
	Next(P) = Nil;
	if (last == Nil)
	{
		First(*L) = P;
	}
	else
	{
		Next(last) = P;
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
	address first;
	
	//Algoritma
	first = First(*L);
	First(*L) = Next(first);
	*P = first;
}
void DelP (List *L, infotype X)
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
	
	//Algoritma
	i = First(*L);
	bi = Nil;
	while (i != Nil)
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
		}
		else
		{
			bi = i;
			i = Next(i);
		}
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	//Kamus
	address i;
	address last;
	address blast;
	
	//Algoritma
	i = First(*L);
	last = Nil;
	blast = Nil;
	while (i != Nil)
	{
		blast = last;
		last = i;
		i = Next(i);
	}
	*P = last;
	if (blast != Nil)
	{
		Next(blast) = Nil;
	}
	else
	{
		First(*L) = Nil;
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
	if (*Pdel != Nil)
	{
		Next(Prec) = Next(*Pdel);
	}
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
	p = First(L);
	cek = true;
	printf("[");
	while (p != Nil)
	{
		if (!cek)
		{
			printf(",");
		}
		printf("%d", Info(p));
		p = Next(p);
		cek = false;
	}
	printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	//Kamus
	address p;
	int count;
	
	//Algoritma
	count = 0;
	p = First(L);
	while (p != Nil)
	{
		count++;
		p = Next(p);
	}
	return (count);
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) maksimum */
{
	//Kamus
	address p;
	infotype max;
	
	//Algoritma
	max = Info(First(L));
	p = Next(First(L));
	while (p != Nil)
	{
		if (Info(p) > max)
		{
			max = Info(p);
		}
		p = Next(p);
	}
	return (max);
}
address AdrMax (List L)
/* Mengirimkan address info(P) maksimum */
{
	//Kamus
	address max;
	address p;
	
	//Algoritma
	max = First(L);
	p = Next(First(L));
	while (p != Nil) {
		if (Info(max) < Info(p))
			max = p;
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
	min = Info(First(L));
	p = Next(First(L));
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
address AdrMin (List L)
/* Mengirimkan address info(P) minimum */
{
	//Kamus
	address min;
	address p;
	
	//Algoritma
	min = First(L);
	p = Next(First(L));
	while (p != Nil) {
		if (Info(min) > Info(p))
			min = p;
		p = Next(p);
	}
	return (min);
}
float Average (List L)
/* Mengirimkan nilai rata-rata dari seluruh elemen list L */
{
	//Kamus
	address p;
	float sum;
	int count;
	
	//Algoritma
	p = First(L);
	sum = 0;
	count = 0;
	while (p != Nil)
	{
		sum += Info(p);
		count++;
		p = Next(p);
	}
	return (float)sum/(float)count;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	//Kamus
	address p;
	address q;
	
	//Algoritma
	p = First(*L);
	while (p != Nil)
	{
		q = Next(p);
		Dealokasi(&p);
		p = q;
	}
	First(*L) = Nil;
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
	//Kamus
	address p;
	address q;
	address r;
	
	//Algoritma
	p = First(*L);
	q = Nil;
	r = Nil;
	while (p != Nil)
	{
		if (q != Nil)
		{
			Next(q) = r;
		}
		r = q;
		q = p;
		p = Next(p);
	}
	if (q != Nil)
	{
		Next(q) = r;
	}
	First(*L) = q;
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	//Kamus
	address p;
	address q;
	boolean cek;
	List Ln;
	
	//Algoritma
	p = First(L);
	cek = false;
	CreateEmpty(&Ln);
	while ((!cek) && (p != Nil))
	{
		q = Alokasi(Info(p));
		if (q == Nil)
		{
			cek = true;
		}
		if (!cek)
		{
			Next(q) = First(Ln);
			First(Ln) = q;
			p = Next(p);
		}
	}
	if (cek)
	{
		DelAll(&Ln);
	}
	return (Ln);
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	//Kamus
	
	//Algoritma
	First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	//Kamus
	address p;
	address q;
	address last;
	boolean cek;
	List Ln;
	
	//Algoritma
	p = First(L);
	cek = false;
	CreateEmpty(&Ln);
	last = First(Ln);
	while ((!cek) && (p != Nil))
	{
		q = Alokasi(Info(p));
		if (q == Nil)
		{
			cek = true;
		}
		if (!cek)
		{
			if (last == Nil)
			{
				last = First(Ln) = q;
			}
			else
			{
				Next(last) = q;
				last = Next(last);
			}
			Next(last) = Nil;
		}
		p = Next(p);
	}
	if (cek)
	{
		DelAll(&Ln);
	}
	return (Ln);
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	//Kamus
	
	//Algoritma
	*Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
	//Kamus
	address p;
	address q;
	address last;
	boolean cek1;
	boolean cek2;
	
	//Algoritma
	p = First(L1);
	cek1 = false;
	CreateEmpty(L3);
	last = First(*L3);
	cek2 = true;
	if (p == Nil)
	{
		p = First(L2);
		cek2 = false;
	}
	while ((!cek1) && (p != Nil))
	{
		q = Alokasi(Info(p));
		if (q == Nil)
		{
			cek1 = true;
		}
		if (!cek1)
		{
			if (last == Nil)
			{
				last = First(*L3) = q;
			}
			else
			{
				Next(last) = q;
				last = Next(last);
			}
			Next(last) = Nil;
		}
		p = Next(p);
		if (p == Nil && cek2)
		{
			cek2 = false;
			p = First(L2);
		}
	}
	if (cek1)
	{
		DelAll(L3);
	}
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	//Kamus
	address p;
	address last;
	
	//Algoritma
	if (IsEmpty(*L1))
	{
		First(*L3) = First(*L2);
	}
	else
	{
		First(*L3) = First(*L1);
		p = First(*L1);
		last = Nil;
		while (p != Nil)
		{
			last = p;
			p = Next(p);
		}
		Next(last) = First(*L2);
	}
	First(*L1) = First(*L2) = Nil;
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
	//Kamus
	address p;
	address q;
	address last;
	int count;
	int half;
	
	//Algoritma
	p = First(L);
	count = 0;
	half = NbElmt(L) / 2;
	CreateEmpty(L1);
	CreateEmpty(L2);
	last = First(*L1);
	while (p != Nil)
	{
		count++;
		q = Alokasi(Info(p));
		if (last == Nil)
		{
			last = count > half ? (First(*L2) = q) : (First(*L1) = q);
		}
		else
		{
			Next(last) = q;
			last = Next(last);
		}
		if (count == half)
		{
			Next(last) = Nil;
			last = Nil;
		}
		p = Next(p);
	}
}
