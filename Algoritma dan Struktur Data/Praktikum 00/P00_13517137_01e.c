/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01e.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Program membaca sebuah karakter, dan melakukan konversi ke nilai integer serta menuliskannya, jika karakter mewakili angka, bernilai ['0'..'9']. Jika yang diketik bukan bernilai ['0'..'9'], program memeriksa apakah karakter itu A atau bukan kemudian menuliskan pesan */
 
#include <stdio.h>

#define boolean unsigned char
#define true 1
#define false 0

//FUNGSI
int KarakterToInteger (char x);
// Diberikan x berupa karakter '0'..'9', menghasilkan harga integer yang sesuai dengan penulisan pada karakter
boolean IsAnA (char x);
// Menghasilkan true jika x adalah 'A'

//ALGORITMA UTAMA
int main()
{
	//KAMUS
	char CC;
		
	//ALGORITMA
	scanf ("%c", &CC);
	switch (CC) {
		case '0' ... '9' :
		{
			printf ("%d\n", KarakterToInteger (CC));
			break;
		}
		default  : 
		{
			if ((IsAnA (CC)) == true)
			{
				printf ("Bukan angka, tapi merupakan karakter A\n");
			}
			else
			{
				printf ("Bukan angka dan bukan karakter A\n");
			}
		}
	};
	return 0;
}

//ALGORITMA FUNGSI
int KarakterToInteger (char x)
{
	//KAMUS LOKAL
	int a;
	
	//ALGORITMA
	switch (x) {
		case '0' :
		{
			a = 0;
			break;
		}
		case '1' :
		{
			a = 1;
			break;
		}
		case '2' :
		{
			a = 2;
			break;
		}
		case '3' :
		{
			a = 3;
			break;
		}
		case '4' :
		{
			a = 4;
			break;
		}
		case '5' :
		{
			a = 5;
			break;
		}
		case '6' :
		{
			a = 6;
			break;
		}
		case '7' :
		{
			a = 7;
			break;
		}
		case '8' :
		{
			a = 8;
			break;
		}
		case '9' :
		{
			a = 9;
			break;
		}
	}
	return (a);
}

boolean IsAnA (char x)
{
	//KAMUS LOKAL
	boolean Found;
	
	//ALGORITMA
	Found = false;
	if (x == 'A')
	{
		Found = true;
	}
	return (Found);
}
