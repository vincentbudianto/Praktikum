/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_02.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Mengetes batasan maksimum dan minimum nilai-nilai beberapa tipe dasar yang disediakan bahasa C dengan menggunakan konstanta yang ada di lib limits.h */
 
#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main()
{
	//KAMUS
	
	//ALGORITMA
	printf("Maximum integer: %d\n", INT_MAX);
	printf("Minimum integer: %d\n", INT_MIN);
	printf("Maximum short integer: %d\n", SHRT_MAX);
	printf("Minimum short integer: %d\n", SHRT_MIN);
	printf("Maximum long integer: %li\n", LONG_MAX);
	printf("Minimum long integer: %li\n", LONG_MIN);
	printf("Maximum unsigned integer: %d\n", UINT_MAX);
	printf("Minimum unsigned short integer: %d\n", USHRT_MAX);
	printf("Maximum unsigned long integer: %li\n", ULONG_MAX);
	printf("Maximum character: %d\n", CHAR_MAX);
	printf("Minimum character: %d\n", CHAR_MIN);
	printf("Maximum signed character: %d\n", SCHAR_MAX);
	printf("Minimum signed character: %d\n", SCHAR_MIN);
	printf("Maximum unsigned character: %d\n", UCHAR_MAX);
	printf("Maximum float: %f\n", FLT_MAX);
	printf("Minimum float: %f\n", FLT_MIN);
	printf("Maximum double float: %f\n", DBL_MAX);
	printf("Minimum double float: %f\n", DBL_MIN);
	printf("Maximum long double float: %Le\n", LDBL_MAX);
	printf("Minimum long double float: %Le\n", LDBL_MIN);
	return 0;
}
