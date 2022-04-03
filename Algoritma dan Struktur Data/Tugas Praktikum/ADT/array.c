/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : array.c
 * Topik     : ADT ARRAY
 * Tanggal   : 13 September 2018
 * Deskripsi : Realisasi ADT ARRAY */

#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt *T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	//Kamus

	//Algoritma
	Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
	//Kamus

	//Algoritma
	return (Neff(T));
}
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
	//Kamus

	//Algoritma
	return (IdxMax - IdxMin + 1);
}
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	//Kamus

	//Algoritma
	return (IdxMin);
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	//Kamus

	//Algoritma
	return (IdxMin + NbElmt(T) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	//Kamus

	//Algoritma
	return ((i >= IdxMin) && (i <= IdxMax));
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	//Kamus

	//Algoritma
	return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	//Kamus

	//Algoritma
	return (Neff(T) == 0);
}
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	//Kamus

	//Algoritma
	return (Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
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
	while ((N < 0) || (N > MaxNbEl(*T)))
	{
		scanf ("%d", &N);
	}
	if (N == 0)
	{
		MakeEmpty(T);
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
void BacaIsiTab (TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
	//Kamus
	IdxType i;
	boolean found;
	ElType isi;

	//Algoritma
	i = GetFirstIdx(*T);
	found = false;
	MakeEmpty(T);
	while ((found == false) && (NbElmt(*T) < MaxNbEl(*T)))
	{
		scanf ("%d", &isi);
		if (isi == -9999)
		{
			found = true;
		}
		else
		{
			Elmt(*T, i) = isi;
			Neff(*T) += 1;
			i++;
		}
	}
}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50 */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (IsEmpty(T) == true)
	{
		printf ("Tabel kosong\n");
	}
	else
	{
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			printf("[%d]%d\n", i, Elmt(T, i));
		}
	}
}
void TulisIsiTab (TabInt T)
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
	if (GetLastIdx(T) != 0)
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
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
	//Kamus
	IdxType i;
	TabInt T;

	//Algoritma
	MakeEmpty(&T);
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
	{
		Elmt(T, i) = Elmt(T1, i) + Elmt(T2, i);
	}
	Neff(T) = Neff(T1);
	return (T);
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	//Kamus
	IdxType i;
	TabInt T;

	//Algoritma
	MakeEmpty(&T);
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
	{
		Elmt(T, i) = Elmt(T1, i) - Elmt(T2, i);
	}
	Neff(T) = Neff(T1);
	return (T);
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
	//Kamus
	IdxType i;
	TabInt T;

	//Algoritma
	MakeEmpty(&T);
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
	{
		Elmt(T, i) = Elmt(T1, i) * Elmt(T2, i);
	}
	Neff(T) = Neff(T1);
	return (T);
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
	//Kamus
	IdxType i;
	TabInt T;

	//Algoritma
	MakeEmpty(&T);
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
	{
		Elmt(T, i) = c * Elmt(Tin, i);
	}
	Neff(T) = Neff(Tin);
	return (T);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (IsEmpty(T1) && IsEmpty(T2))
  {
    return (true);
  }
  else
  {
    if (NbElmt(T1) != NbElmt(T2))
    {
      return (false);
    }
    else
    {
      i = GetFirstIdx(T1);
      while ((i < GetLastIdx(T1)) && (Elmt(T1, i) == Elmt(T2, i)))
      {
        i++;
      }
      return (Elmt(T1, i) == Elmt(T2, i));
    }
  }
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < 'Badu'; maka [0, 1] < [2, 3] */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (NbElmt(T1) > NbElmt(T2))
	{
		return (false);
	}
	else if (NbElmt(T1) < NbElmt(T2))
	{
		return (true);
	}
	else
	{
		i = GetFirstIdx(T1);
		while ((i < NbElmt(T1)) && (Elmt(T1, i) == Elmt(T2, i)))
		{
			i++;
		}
			return (Elmt(T1, i) < Elmt(T2, i));
	}
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
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
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
	//Kamus
	IdxType i;
	boolean found;

	//Algoritma
	if (IsEmpty(T) == false)
	{
		i = GetFirstIdx(T);
		found = false;
		while ((i <= GetLastIdx(T)) && (found == false))
		{
				if (Elmt(T, i) == X)
				{
					found = true;
				}
				else
				{
					i++;
				}
		}
		if (found == true)
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
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
	//Kamus

	//Algoritma
	return (Search2(T, X) != IdxUndef);
}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
	//Kamus
	IdxType i;

	//Algoritma
	i = GetLastIdx(T);
	Elmt(T, (GetFirstIdx(T) - 1)) = X;
	while (Elmt(T, i) != X)
	{
		i--;
	}
	return (i != 0);
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
	//Kamus
	IdxType i;
	ElType max;

	//Algoritma
	max = Elmt(T, GetFirstIdx(T));
	for (i = (GetFirstIdx(T) + 1); i <= GetLastIdx(T); i++)
	{
		if (max < Elmt(T, i))
		{
			max = Elmt(T, i);
		}
	}
	return (max);
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
	//Kamus
	IdxType i;
	ElType min;

	//Algoritma
	min = Elmt(T, GetFirstIdx(T));
	for (i = (GetFirstIdx(T) + 1); i <= GetLastIdx(T); i++)
	{
		if (min > Elmt(T, i))
		{
			min = Elmt(T, i);
		}
	}
	return (min);
}
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
	//Kamus

	//Algoritma
	return (Search1(T, ValMax(T)));
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
	//Kamus

	//Algoritma
	return (Search1(T, ValMin(T)));
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
	//Kamus
	IdxType i;

	//Algoritma
	MakeEmpty(Tout);
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
	{
		Elmt(*Tout, i) = Elmt(Tin, i);
	}
	Neff(*Tout) = Neff(Tin);
}
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
	//Kamus
	IdxType i;
	TabInt Temp;

	//Algoritma
	MakeEmpty(&Temp);
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		Elmt(Temp, (GetLastIdx(T) - i + 1)) = Elmt(T, i);
	}
	Neff(Temp) = Neff(T);
	return (Temp);
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
	//Kamus
	IdxType i;
	IdxType j;

	//Algoritma
	if (IsEmpty(T) == true)
	{
		return (true);
	}
	else
	{
		i = GetFirstIdx(T);
		j = GetLastIdx(T);
		while ((Elmt(T, i) == Elmt(T, j)) && (i < j))
		{
			i++;
			j--;
		}
		return (Elmt(T, i) == Elmt(T, j));
	}
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
	//Kamus
	IdxType i;
	IdxType j;
	IdxType idmax;
	ElType temp;

	//Algoritma
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
void InsSortAsc (TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
	//Kamus
	IdxType i;
	IdxType j;
	ElType temp;

	//Algoritma
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

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	//Kamus

	//Algoritma
	Neff(*T) += 1;
	Elmt(*T, (GetLastIdx(*T))) = X;
}
void AddEli (TabInt *T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	//Kamus
	IdxType j;

	//Algoritma
	for (j = GetLastIdx(*T); j >= i; j--)
	{
		Elmt(*T, (j + 1)) = Elmt(*T, j);
	}
	Elmt(*T, i) = X;
	Neff(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt *T, ElType *X)
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
void DelEli (TabInt *T, IdxType i, ElType *X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	//Kamus
	IdxType j;

	//Algoritma
	*X = Elmt(*T, i);
	if (IsEmpty(*T) == false)
	{
		for(j = i; j < GetLastIdx(*T); j++)
		{
			Elmt(*T, j) = Elmt(*T, (j + 1));
		}
		Neff(*T) -= 1;
	}
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt *T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
	//Kamus

	//Algoritma
	if (SearchSentinel(*T, X) == false)
	{
		AddAsLastEl(T, X);
	}
	else
	{
		printf("nilai sudah ada\n");
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
	//Kamus
	IdxType i;

	//Algoritma
	i = GetFirstIdx(T);
	if (IsEmpty(T) == true)
	{
		return (IdxUndef);
	}
	else
	{
		while ((Elmt(T, i) < X) && (i <= GetLastIdx(T)))
		{
			i++;
		}
		if (Elmt(T, i) == X)
		{
			return (i);
		}
		else
		{
			return (IdxUndef);
		}
	}
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
	//Kamus

	//Algoritma
	return (Elmt(T, GetLastIdx(T)));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
	//Kamus

	//Algoritma
	return (Elmt(T, GetFirstIdx(T)));
}
void MaxMinUrut (TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	//Kamus

	//Algoritma
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}
void Add1Urut (TabInt *T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
	//Kamus
	IdxType i;

	//Algoritma
	i = GetFirstIdx(*T);
	if (IsEmpty(*T) == true)
	{
		AddAsLastEl(T, X);
	}
	else if (IsFull(*T) == false)
	{
		while ((Elmt(*T, i) < X) && (i <= GetLastIdx(*T)))
		{
			i++;
		}
		AddEli(T, X, i);
	}
}
void Del1Urut (TabInt *T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
	//Kamus

	//Algoritma
	if (SearchB(*T, X) == true)
	{
		DelEli (T, SearchUrut(*T, X), &X);
	}
}
