/* NIM       : 13517137
 * Nama      : Vincent Budianto
 * Tanggal   : 06 September 2018
 * Topik     : Praktikum 02
 * Deskripsi : Membaca beberapa pasangan JAM yang merepresentasikan waktu mulai dan waktu selesai pembicaraan telepon di suatu perusahaan penyedia layanan telepon, misalnya <J1, J2>. Selanjutnya untuk masing-masing pasangan, dituliskan durasi pembicaraan telepon dalam detik. Durasi pembicaraan telepon harus positif, sehingga harus diperiksa dulu manakah di antara J1 dan J2 yang lebih awal. Jam yang lebih awal adalah jam mulai sedangkan jam yang lebih akhir adalah jam selesai */

#include <stdio.h>
#include "jam.h"

int main()
{
	//KAMUS
	int N;
	int i;
	JAM J1;
	JAM J2;
	JAM max;
	JAM min;
	
	//ALGORITMA
	i = 1;
	scanf ("%d", &N);
	printf ("[%d]\n", i);
	BacaJAM(&J1);
	BacaJAM(&J2);
	if ((JLT(J1, J2) == true) || (JEQ(J1, J2) == true))
	{
		max = J2;
		min = J1;
		printf ("%ld\n", Durasi(J1, J2));
	}
	else if (JGT(J1, J2) == true)
	{
		max = J1;
		min = J2;
		printf ("%ld\n", Durasi(J2, J1));
	}
	while (i < N)
	{
		i++;
		printf ("[%d]\n", i);
		BacaJAM(&J1);
		BacaJAM(&J2);
		if ((JLT(J1, J2) == true) || (JEQ(J1, J2) == true))
		{
			if (JAMToDetik(max) <= JAMToDetik(J2))
			{
				max = J2;
			}
			if (JAMToDetik(min) > JAMToDetik(J1))
			{
				min = J1;
			}
			printf ("%ld\n", Durasi(J1, J2));
		}
		else if (JGT(J1, J2) == true)
		{
			if (JAMToDetik(max) <= JAMToDetik(J1))
			{
				max = J1;
			}
			if (JAMToDetik(min) > JAMToDetik(J2))
			{
				min = J2;
			}
			printf ("%ld\n", Durasi(J2, J1));
		}
	}
	TulisJAM(min); printf ("\n");
	TulisJAM(max); printf ("\n");
	return 0;
}
