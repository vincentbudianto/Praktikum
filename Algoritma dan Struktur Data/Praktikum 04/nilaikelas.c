/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : nilaikelas.c
 * Topik     : Praktikum 04
 * Tanggal   : 20 September 2018
 * Deskripsi : Driver ADT MATRIKS */

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X);
/* Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. */
/* Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. */
/* Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir */
/* I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi */
/* F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
Jika tidak ada elemen dengan nilai = X, menuliskan [] */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 2 dan X = 3, akan tercetak: [1,3]
*/
void TulisStatistikMhs (MATRIKS M, indeks i);
/* Menuliskan statistik untuk mahasiswa dengan nomor urut i. */
/* Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. */
/* Pada dasarnya: menuliskan statistik untuk data pada baris ke-i */
/* I.S. M terdefinisi, i adalah indeks baris efektif M */
/* F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min> */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 2 akan tercetak:
[2] 62.33 72 55
*/
void TulisStatistikMK (MATRIKS M, indeks j);
/* Menuliskan statistik untuk mata kuliah dengan nomor urut j. */
/* Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). */
/* Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j */
/* I.S. M terdefinisi, j adalah indeks kolom efektif M */
/* F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika j = 2 akan tercetak:
[2] 77.00 [93 1 [3]] [55 1 [2]]
*/

int main()
{
	//KAMUS
	MATRIKS MNilai;
	int N;
	int M;
	indeks i;
	indeks j;
	
	//ALGORITMA
	scanf ("%d", &N);
	scanf ("%d", &M);
	BacaMATRIKS(&MNilai, N, M);
	j = GetFirstIdxKol(MNilai);
	printf("STATISTIK PER MAHASISWA\n");
	for (i = GetFirstIdxBrs(MNilai); i <= GetLastIdxBrs(MNilai); i++)
	{
		TulisStatistikMhs(MNilai, i);
		printf("\n");
	}
	printf("STATISTIK PER MATA KULIAH\n");
	for (j = GetFirstIdxKol(MNilai); j <= GetLastIdxKol(MNilai); j++)
	{
		TulisStatistikMK(MNilai, j);
		printf("\n");
	}
}

//FUNCTION + PROCEDURE
//procedure TulisNilaiX
void TulisNilaiX (MATRIKS M, indeks j, ElType X)
{
 	//KAMUS LOKAL
 	indeks i;
 	int count;
 	int hitung;

	//ALGORITMA
	printf ("[");
	count = CountXKol(M, j, X);
	hitung = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		if (X == Elmt(M, i, j))
		{
			printf ("%d", i);
			hitung += 1;
			if (hitung < count)
			{
				printf (",");
			}
		}
	}
	printf ("]");
}

//procedure TulisStatistikMhs
void TulisStatistikMhs (MATRIKS M, indeks i)
{
 	//KAMUS LOKAL
 	ElType max;
 	ElType min;

	//ALGORITMA
	MaxMinBrs(M, i, &max, &min);
	printf ("[%d] ", i);
	printf ("%.2f ", RataBrs(M, i));
	printf ("%d " ,max);
	printf ("%d" ,min);
}

//procedure TulisStatistikMK
void TulisStatistikMK (MATRIKS M, indeks j)
{
 	//KAMUS LOKAL
 	ElType max;
 	ElType min;

	//ALGORITMA
	MaxMinKol(M, j, &max, &min);
	printf ("[%d] ", j);
	printf ("%.2f ", RataKol(M, j));
	printf ("[%d ", max);
	printf ("%d ", CountXKol(M, j, max));
	TulisNilaiX(M, j, max);
	printf ("] ");
	printf ("[%d ", min);
	printf ("%d ", CountXKol(M, j, min));
	TulisNilaiX(M, j, min);
	printf ("]");
}
