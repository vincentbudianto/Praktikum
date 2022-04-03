/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : jam_driver.c
 * Topik     : ADT JAM
 * Tanggal   : 6 September 2018
 * Deskripsi : Driver ADT JAM */
 
#include <stdio.h>
#include "jam.c"

int main()
{
	//KAMUS
	JAM J1;
	JAM J2;
	long x;
	int y;
	int z;
	
	//ALGORITMA
	//TEST BacaJAM + IsJAMValid + MakeJAM
	printf ("TEST BacaJAM + IsJAMValid + MakeJAM\n");
	printf ("Ketikan jam J1 : "); BacaJAM(&J1);
	printf ("Ketikan jam J2 : "); BacaJAM(&J2);
	printf ("\n");
	//TEST TulisJAM
	printf ("TEST TulisJAM\n");
	printf ("Jam J1 : "); TulisJAM(J1);
	printf ("Jam J2 : "); TulisJAM(J2);
	printf ("\n");
	//TEST JAMToDetik
	printf ("TEST JAMToDetik\n");
	printf ("Jumlah detik : %ld\n", JAMToDetik(J1));
	printf ("\n");
	//TEST DetikToJAM
	printf ("TEST DetikToJAM\n");
	printf ("Ketikan detik : "); scanf ("%ld", &x);
	printf ("Jam : "); TulisJAM(DetikToJAM(x));
	printf ("\n");
	//TEST JEQ
	printf ("TEST JEQ\n");
	if (JEQ(J1, J2) == true)
	{
		printf ("JEQ1 = JEQ2\n");
	}
	else
	{
		printf ("JEQ1 != JEQ2\n");
	}
	printf ("\n");
	//TEST JNEQ
	printf ("TEST JNEQ\n");
	if (JNEQ(J1, J2) == true)
	{
		printf ("JNEQ1 = JNEQ2\n");
	}
	else
	{
		printf ("JNEQ1 != JNEQ2\n");
	}
	printf ("\n");
	//TEST JLT
	printf ("TEST JLT\n");
	if (JLT(J1, J2) == true)
	{
		printf ("JLT1 < JLT2\n");
	}
	else
	{
		printf ("JLT1 > JLT2\n");
	}
	//TEST JGT
	printf ("TEST JGT\n");
	if (JGT(J1, J2) == true)
	{
		printf ("JGT1 > JGT2\n");
	}
	else
	{
		printf ("JGT1 < JGT2\n");
	}
	printf ("\n");
	//TEST NextDetik
	printf ("TEST NextDetik\n");
	printf ("Jam + 1 detik: "); TulisJAM(NextDetik(J1));
	printf ("\n");
	//TEST NextNDetik
	printf ("TEST NextNDetik\n");
	printf ("+ detik : "); scanf ("%d", &y);
	printf ("Jam + %d detik: ", y); TulisJAM(NextNDetik(J1, y));
	printf ("\n");
	//TEST PrevDetik
	printf ("TEST PrevDetik\n");
	printf ("Jam : "); TulisJAM(PrevDetik(J1));
	printf ("\n");
	//TEST PrevNDetik
	printf ("TEST PrevNDetik\n");
	printf ("- detik : "); scanf ("%d", &z);
	printf ("Jam - %d detik: ", z); TulisJAM(PrevNDetik(J1,z));
	printf ("\n");
	//TEST DURASI
	printf ("TEST DURASI\n");
	printf ("durasi : %ld\n", (Durasi(J1, J2)));
	return 0;
}
