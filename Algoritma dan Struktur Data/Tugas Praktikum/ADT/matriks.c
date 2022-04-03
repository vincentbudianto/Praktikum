/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : matriks.c
 * Topik     : ADT MATRIKS
 * Tanggal   : 20 September 2018
 * Deskripsi : Realisasi ADT MATRIKS */

#include "matriks.h"

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS *M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	//Kamus

 	//Algoritma
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	//Kamus

 	//Algoritma
	return ((i >= BrsMin) && (i <= BrsMax)) && ((j >= KolMin) && (j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
 	//Kamus

 	//Algoritma
	return (BrsMin);
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
 	//Kamus

 	//Algoritma
	return (KolMin);
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
 	//Kamus

 	//Algoritma
	return (NBrsEff(M));
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	//Kamus

 	//Algoritma
	return (NKolEff(M));
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	//Kamus

 	//Algoritma
	return ((i >= BrsMin) && (i <= NBrsEff(M)) && ((j >= KolMin) && (j <= NKolEff(M))));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
 {
 	//Kamus

 	//Algoritma
	return (Elmt(M, i, i));
}

 /* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS *MHsl)
/* Melakukan assignment MHsl  MIn */
{
 	//Kamus
	indeks i;
	indeks j;

 	//Algoritma
	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
	for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++)
	{
		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++)
		{
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
		}
	}
 }

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS *M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
 	//Kamus
	indeks i;
	indeks j;

 	//Algoritma
	MakeMATRIKS(NB, NK, M);
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			scanf ("%d", &Elmt(*M, i, j));
		}
	}
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
 	//Kamus
	indeks i;
	indeks j;

 	//Algoritma
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			printf("%d", Elmt(M, i, j));
			if (j != GetLastIdxKol(M))
			{
				printf(" ");
			}
		}
		if (i != GetLastIdxBrs(M))
		{
			printf("\n");
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
 	//Kamus
	MATRIKS M;
	indeks i;
	indeks j;

 	//Algoritma
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			Elmt(M, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
		}
	}
	return (M);
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
	//Kamus
	MATRIKS M;
	indeks i;
	indeks j;

 	//Algoritma
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			Elmt(M, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
		}
	}
	return (M);
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
 	//Kamus
	MATRIKS M;
	indeks i;
	indeks j;
	indeks k;
	int sum;

 	//Algoritma
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			sum=0;
			for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++)
			{
				sum = sum + (Elmt(M1,i,k) * Elmt(M2,k,j));
			}
			Elmt(M, i, j) = sum;
		}
	}
	return M;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
 	//Kamus
	MATRIKS MOut;
	indeks i;
	indeks j;

 	//Algoritma
	CopyMATRIKS(M, &MOut);
	for (i = GetFirstIdxBrs(MOut); i <= GetLastIdxBrs(MOut); i++)
	{
		for (j = GetFirstIdxKol(MOut); j <= GetLastIdxKol(MOut); j++)
		{
			Elmt(MOut, i, j) = Elmt(MOut, i, j) * X;
		}
	}
	return (MOut);
}
void PKaliKons (MATRIKS *M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	//Kamus

 	//Algoritma
	*M = KaliKons(*M, K);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	//Kamus
	indeks i;
	indeks j;
	boolean found;

 	//Algoritma
	if ((GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetFirstIdxKol(M1) != GetFirstIdxKol(M2)))
	{
		return (false);
	}
	else if ((NBrsEff(M1) != NBrsEff(M2)) || (NKolEff(M1) != NKolEff(M2)))
	{
		return (false);
	}
	else
	{
		found = false;
		i = GetFirstIdxBrs(M1);
		while ((i <= GetLastIdxBrs(M1)) && (found == false))
		{
			j = GetFirstIdxKol(M1);
			while ((j <= GetLastIdxKol(M1)) && (found == false))
			{
				if (Elmt(M1, i, j) != Elmt(M2, i, j))
				{
					found = true;
				}
				else
				{
					j++;
				}
			}
			i++;
		}
		if (found == true)
		{
			return (false);
		}
		else
		{
			return (true);
		}
	}
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	//Kamus

 	//Algoritma
	return (EQ(M1, M2) != true);
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
 	//Kamus

 	//Algoritma
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
 	//Kamus

 	//Algoritma
	return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
 	//Kamus

 	//Algoritma
	return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	//Kamus
	indeks i;
	indeks j;
	boolean found;

 	//Algoritma
	found = (IsBujurSangkar(M) == true);
	i = GetFirstIdxBrs(M);
	while ((i <= GetLastIdxBrs(M)) && (found == true))
	{
		j = i;
		while ((j <= GetLastIdxKol(M)) && (found == true))
		{
			found = (Elmt(M, i, j) == Elmt(M, j, i));
			j++;
		}
		i++;
	}
	return (found);
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
	//Kamus
	indeks i;
	indeks j;
	boolean found;

 	//Algoritma
	found = (IsSimetri(M) == true);
	i = GetFirstIdxBrs(M);
	while ((i <= GetLastIdxBrs(M)) && (found == true))
	{
		j = i;
		while ((j <= GetLastIdxKol(M)) && (found == true))
		{
			if (i == j)
			{
				found = (Elmt(M, i, j) == 1);
			}
			else
			{
				found = (Elmt(M, i, j) == 0);
			}
			j++;
		}
		i++;
	}
	return (found);
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
 	//Kamus
	indeks i;
	indeks j;
	boolean found;
	int count;

 	//Algoritma
	found = true;
	count = 0;
	i = GetFirstIdxBrs(M);
	while ((i <= GetLastIdxBrs(M)) && (found == true))
	{
		j = GetFirstIdxKol(M);
		while ((j <= GetLastIdxKol(M)) && (found == true))
		{
			if (Elmt(M, i, j) != 0)
			{
				count += 1;
				found = (count <= (NBElmt(M) * 5 / 100));
			}
			j++;
		}
		i++;
	}
	return (found);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	//Kamus
	
 	//Algoritma
	return (KaliKons(M, (-1)));
}
 float Determinan (MATRIKS M)
 /* Prekondisi: IsBujurSangkar(M) */
 /* Menghitung nilai determinan M */
 {
 	//Kamus
	MATRIKS temp;
	indeks i;
	indeks j;
	indeks k;
	indeks x;
	indeks y;
	int sign;
	float sum;
	
 	//Algoritma
	if (NBrsEff(M) == 1)
	{
		return (Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M)));
	}
	else if (NBrsEff(M) == 2)
	{
		return ((Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M))) - ((Elmt(M, GetFirstIdxBrs(M), GetLastIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetFirstIdxKol(M)))));
	}
	else
	{
		sign = 1;
		sum = 0;
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			MakeMATRIKS((NBrsEff(M) - 1), (NKolEff(M) - 1), &temp);
			x = GetFirstIdxBrs(temp);
			y = GetFirstIdxKol(temp);
			for (j = GetFirstIdxBrs(M); j <= GetLastIdxBrs(M); j++)
			{	
				for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++)
				{
					if ((j != i) && (k != GetFirstIdxKol(M)))
					{
						Elmt(temp, x, y) = Elmt(M, j, k);
						y++;
						if (y > GetLastIdxKol(temp))
						{
							y = GetFirstIdxKol(temp);
							x++;
						}
					}
				}
			}
			sum += sign * Elmt(M, i, GetFirstIdxKol(M)) * Determinan(temp);
			sign *= (-1);
		}
		return (sum);
	}
}
void PInverse1 (MATRIKS *M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	//Kamus

 	//Algoritma
	*M = Inverse1(*M);
}
void Transpose (MATRIKS *M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
 	//Kamus
	indeks i;
	indeks j;
	MATRIKS temp;

	//Algoritma
	MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &temp);
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
		Elmt(temp, i, j) = Elmt(*M, j, i);
		}
	}
	*M = temp;
}

/* Operasi berbasis baris dan per kolom */
float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
 	//Kamus
 	indeks j;
 	float sum;

	//Algoritma
	sum = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		sum += Elmt(M, i, j);
	}
	return (sum / NKolEff(M));
}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
 	//Kamus
 	indeks i;
 	float sum;

	//Algoritma
	sum = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		sum += Elmt(M, i, j);
	}
	return (sum / NBrsEff(M));
}
void MaxMinBrs (MATRIKS M, indeks i, ElType *max, ElType *min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
 	//Kamus
 	indeks j;

	//Algoritma
	*max = Elmt(M, i, GetFirstIdxKol(M));
	*min = Elmt(M, i, GetFirstIdxKol(M));
	for (j = (GetFirstIdxKol(M) + 1); j <= GetLastIdxKol(M); j++)
	{
		if (*max < Elmt(M, i, j))
		{
			*max = Elmt(M, i, j);
		}
		if (*min > Elmt(M, i, j))
		{
			*min = Elmt(M, i, j);
		}
	}
}
void MaxMinKol (MATRIKS M, indeks j, ElType *max, ElType *min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
 	//Kamus
 	indeks i;

	//Algoritma
	*max = Elmt(M, GetFirstIdxBrs(M), j);
	*min = Elmt(M, GetFirstIdxBrs(M), j);
	for (i = (GetFirstIdxBrs(M) + 1); i <= GetLastIdxBrs(M); i++)
	{
		if (*max < Elmt(M, i, j))
		{
			*max = Elmt(M, i, j);
		}
		if (*min > Elmt(M, i, j))
		{
			*min = Elmt(M, i, j);
		}
	}
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
 	//Kamus
 	indeks j;
 	int count;

	//Algoritma
	count = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		if (X == Elmt(M, i, j))
		{
			count += 1;
		}
	}
	return (count);
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
 	//Kamus
 	indeks i;
 	int count;

	//Algoritma
	count = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		if (X == Elmt(M, i, j))
		{
			count += 1;
		}
	}
	return (count);
}
