/* NIM       : 13517137
 * Nama      : Vincent Budianto
 * Tanggal   : 30 Agustus 2018
 * Topik     : Praktikum 01
 * Deskripsi : Program yang menerima masukan sebuah bilangan bulat, misal N dan kemudian menampilkan gambar belah ketupat bintang seperti contoh di bawah, jika N adalah bilangan bulat ganjil (N > 0) */

#include <stdio.h>

//PROGRAM UTAMA
int main()
{	
	//KAMUS
	int i;
	int j;
	int n;
	
	//ALGORITMA
	scanf ("%d", &n);
	if (n % 2 == 0 || n < 0)
	{
		printf("Masukan tidak valid\n");
	}
	else
	{
		for (i = 0; i < n/2; i++)
		{
			for (j = 0; j < n/2-i; j++)
			{
				printf(" ");
			}
			for (j = 0; j < 2*i+1; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		for (i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");
		for (i = n/2-1; i >= 0; i--)
		{
			for (j = 0; j < n/2-i; j++)
			{
				printf(" ");
			}
			for (j = 0; j < 2*i+1; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
