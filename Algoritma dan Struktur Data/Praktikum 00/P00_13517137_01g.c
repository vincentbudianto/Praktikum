/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01g.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Menjumlahkan dan mencacah (melakukan counting) nilai-nilai X yang dibaca. Mark = 9999 */
 
#include <stdio.h>
 
int main()
{
	//KAMUS
	int i;
	int X;
	int Sum;
	
	//ALGORITMA
	i = 0;
	Sum = 0;
	scanf ("%d", &X);
	while (X != 9999)
	{
		printf ("%d\n", X);
		Sum += X;
		i++;
		scanf ("%d", &X);
	}
	printf ("Jumlah : %d\n", Sum);
	printf ("Banyaknya bilangan : %d\n", i);
	return 0;
}
