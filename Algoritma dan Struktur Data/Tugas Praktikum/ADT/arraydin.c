/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : arraydin.c
 * Topik     : ADT ARRAY DINAMIK
 * Tanggal   : 13 September 2018
 * Deskripsi : Realisasi ADT ARRAY DINAMIK */

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
	//Kamus

	//Algoritma
	TI(*T) = (int*) malloc (maxel + 1);
	MaxEl(*T) = maxel;
	Neff(*T) = 0;
}
void Dealokasi(TabInt *T)
/* I.S. T terdefinisi;
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
	//Kamus

	//Algoritma
	MaxEl(*T) = 0;
	Neff(*T) = 0;
	free (T);
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
	//Kamus

	//Algoritma
	return (Neff(T));
}
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
	//Kamus

	//Algoritma
	return (MaxEl(T));
}
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	//Kamus

	//Algoritma
	return (IdxMin);
}
IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	//Kamus

	//Algoritma
	return (Neff(T));
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	//Kamus

	//Algoritma
	return ((i >= IdxMin) && (i <= MaxEl(T)));
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	//Kamus

	//Algoritma
	return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	//Kamus

	//Algoritma
	return (Neff(T) == 0);
}
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	//Kamus

	//Algoritma
	return (Neff(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	//Kamus
	int N;
	IdxType i;

	//Algoritma
	scanf ("%d", &N);
	while ((N < 0) || (N > MaxEl(*T)))
	{
		scanf ("%d", &N);
	}
	if (N == 0)
	{
		MakeEmpty(T, MaxEl(*T));
	}
	else
	{
		for (i = GetFirstIdx(*T); i <= N; i++)
		{
			scanf ("%d", &Elmt(*T, i));
			Neff(*T) += 1;
		}
	}
}
void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	//Kamus
	IdxType i;

	//Algoritma
	printf("[");
	if (Neff(T) != 0)
	{
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			printf("%d", Elmt(T, i));
			if (i != GetLastIdx(T))
			{
				printf(",");
			}
		}
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	//Kamus
	IdxType i;
	TabInt T;

	//Algoritma
	MakeEmpty(&T, MaxEl(T1));
	if (plus == true)
	{
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		{
			Elmt(T, i) = Elmt(T1, i) + Elmt(T2, i);
		}
	}
	else
	{
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		{
			Elmt(T, i) = Elmt(T1, i) - Elmt(T2, i);
		}
	}
	Neff(T) = Neff(T1);
	return (T);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (IsEmpty(T1) && IsEmpty(T2))
	{
	return (true);
	}
	else if (NbElmt(T1) == NbElmt(T2))
	{
	  i = GetFirstIdx(T1);
	  while ((i < GetLastIdx(T1)) && (Elmt(T1,i) == Elmt(T2,i)))
	  {
		i++;
	  }
	  return (Elmt(T1,i) == Elmt(T2,i));
	}
	else
	{
	  return (false);
	}
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (IsEmpty(T) == false)
	{
		i = GetFirstIdx(T);
		while ((i < GetLastIdx(T)) && (X != Elmt(T, i)))
		{
			i++;
		}
		if (X == Elmt(T, i))
		{
			return (i);
		}
		else
		{
			return (IdxUndef);
		}
	}
	else
	{
		return (IdxUndef);
	}
}
boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	//Kamus

	//Algoritma
	return (Search1(T, X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	//Kamus
	IdxType i;

	//Algoritma
	*Max = Elmt(T, GetFirstIdx(T));
	*Min = Elmt(T, GetFirstIdx(T));
	for (i = (GetFirstIdx(T) + 1); i <= GetLastIdx(T); i++)
	{
		if (*Max < Elmt(T, i))
		{
			*Max = Elmt(T, i);
		}
		if (*Min > Elmt(T, i))
		{
			*Min = Elmt(T, i);
		}
	}
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
	//Kamus
	IdxType i;

	//Algoritma
	MakeEmpty(Tout, MaxEl(Tin));
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
	{
		Elmt(*Tout, i) = Elmt(Tin, i);
	}
	Neff(*Tout) = Neff(Tin);
}
ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	//Kamus
	IdxType i;
	ElType sum;

	//Algoritma
	if (IsEmpty(T) == true)
	{
		sum = 0;
	}
	else
	{
		sum = 0;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			sum += Elmt(T, i);
		}
	}
	return (sum);
}
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	//Kamus
	IdxType i;
	int count;

	//Algoritma
	if (IsEmpty(T) == true)
	{
		count = 0;
	}
	else
	{
		count = 0;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (Elmt(T, i) == X)
			{
				count += 1;
			}
		}
	}
	return (count);
}
boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
	//Kamus
	IdxType i;
	boolean genap;

	//Algoritma
	if (IsEmpty(T) == true)
	{
		genap = false;
	}
	else
	{
		i = GetFirstIdx(T);
		while ((i <= GetLastIdx(T)) && (genap == true))
		{
			if (Elmt(T, i) % 2 == 0)
			{
				i++;
			}
			else
			{
				genap = false;
			}
		}
	}
	return (genap);
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	//Kamus
	IdxType i;
	IdxType j;
	IdxType idmax;
	ElType temp;

	//Algoritma
	if (asc == true)
	{
		for (i = (GetFirstIdx(*T) + 1); i < GetLastIdx(*T); i++)
		{
			j = i;
			while ((j > GetFirstIdx(*T)) && (Elmt(*T, (j - 1)) > Elmt(*T, j)))
			{
				temp = Elmt(*T, j);
				Elmt(*T, j) = Elmt(*T, (j - 1));
				Elmt(*T, (j - 1)) = temp;
				j--;
			}
		}
	}
	else
	{
		for (i = GetFirstIdx(*T); i < GetLastIdx(*T); i++)
		{
			idmax = i;
			for (j = (i + 1); j <= GetLastIdx(*T); j++)
			{
					if (Elmt(*T, j) > Elmt(*T, idmax))
					{
						idmax = j;
					}
			}
			temp = Elmt(*T, idmax);
			Elmt(*T, idmax) = Elmt(*T, i);
			Elmt(*T, i) = temp;
		}
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	//Kamus

	//Algoritma
	Neff(*T) += 1;
	Elmt(*T, (GetLastIdx(*T))) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	//Kamus

	//Algoritma
	*X = Elmt(*T, GetLastIdx(*T));
	Neff(*T) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
	//Kamus

	//Algoritma
	MaxEl(*T) += num;
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
	//Kamus

	//Algoritma
	MaxEl(*T) -= num;
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
	//Kamus

	//Algoritma
	MaxEl(*T) = Neff(*T);
}
