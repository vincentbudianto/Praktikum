/* NIM       : 13517137
 * Nama      : Vincent Budianto
 * Tanggal   : 30 Agustus 2018
 * Topik     : Praktikum 01
 * Deskripsi : Mengkonversi suhu dari satuan Celcius ke satuan suhu yang lain, yaitu Fahrenheit, Reamur, atau Kelvin */

#include <stdio.h>

int main()
{
	//KAMUS
	float t;
	char k;
	
	//ALGORITMA
	scanf ("%f %c", &t, &k);
	if (k == 'R'){
		t = t * 4 / 5;
		printf ("%.2f\n", t);
	}
	else if (k == 'F'){
		t = (t * 9 / 5) + 32;
		printf ("%.2f\n", t);
	}
	else if (k == 'K'){
		t = t + 273.15;
		printf ("%.2f\n", t);
	}
	return 0;
}
