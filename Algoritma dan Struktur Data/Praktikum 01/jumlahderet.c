/* NIM       : 13517137
 * Nama      : Vincent Budianto
 * Tanggal   : 30 Agustus 2018
 * Topik     : Praktikum 01
 * Deskripsi : Membaca sebuah integer N (asumsi N > 0), dan menuliskan hasil perhitungan deret: 1+2+3+ ... +N */

#include <stdio.h>

int main()
{
	//KAMUS
	int N;
	int hasil;
	
	//ALGORITMA
	hasil = 0;
	scanf ("%d", &N);
	while (N > 0)
	{
		hasil = hasil + N;
		N = N - 1;
	}
	printf ("%d\n", hasil);
	return 0;
}
