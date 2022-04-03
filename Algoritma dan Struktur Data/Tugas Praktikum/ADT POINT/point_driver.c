/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : point_driver.c
 * Topik     : ADT POINT
 * Tanggal   : 6 September 2018
 * Deskripsi : Driver ADT POINT */
 
#include <stdio.h>
#include "point.c"

int main()
{
	//KAMUS
	POINT P1;
	POINT P2;
	POINT P3;
	POINT P4;
	float a;
	float b;
	float c;
	float d;
	float e;
	
	//ALGORITMA
	//TEST BacaPOINT + MakePOINT
	printf ("TEST BacaPOINT + MakePOINT\n");
	printf ("Ketikan point P1 : "); BacaPOINT(&P1);
	printf ("Ketikan point P2 : "); BacaPOINT(&P2);
	printf ("Ketikan point P3 : "); BacaPOINT(&P3);
	printf ("Ketikan point P4 : "); BacaPOINT(&P4);
	printf ("\n");
	//TEST TulisPOINT + Kuadran
	printf ("TEST TulisPOINT + Kuadran\n");
	printf ("point P1 : "); TulisPOINT(P1);
	if ((IsOrigin(P1) == false) && (IsOnSbX(P1) == false) && (IsOnSbY(P1) == false))
	{
		printf ("Kuadran P1 : %d\n", Kuadran(P1));
	}
	else
	{
		printf ("Titik P1 tidak berada di kuadran manapun\n");
	}
	printf ("point P2 : "); TulisPOINT(P2);
	if ((IsOrigin(P2) == false) && (IsOnSbX(P2) == false) && (IsOnSbY(P2) == false))
	{
		printf ("Kuadran P2 : %d\n", Kuadran(P2));
	}
	else
	{
		printf ("Titik P2 tidak berada di kuadran manapun\n");
	}
	printf ("point P3 : "); TulisPOINT(P3);
	if ((IsOrigin(P3) == false) && (IsOnSbX(P3) == false) && (IsOnSbY(P3) == false))
	{
		printf ("Kuadran P3 : %d\n", Kuadran(P3));
	}
	else
	{
		printf ("Titik P3 tidak berada di kuadran manapun\n");
	}
	printf ("point P4 : "); TulisPOINT(P4);
	if ((IsOrigin(P4) == false) && (IsOnSbX(P4) == false) && (IsOnSbY(P4) == false))
	{
		printf ("Kuadran P4 : %d\n", Kuadran(P4));
	}
	else
	{
		printf ("Titik P4 tidak berada di kuadran manapun\n");
	}
	printf ("\n");
	//TEST EQ
	printf ("TEST EQ\n");
	if (EQ(P1, P2) == true)
	{
		printf ("EQ\n");
	}
	else
	{
		printf ("not EQ\n");
	}
	printf ("\n");
	//TEST NEQ
	printf ("TEST NEQ\n");
	if (NEQ(P1, P2) == true)
	{
		printf ("NEQ\n");
	}
	else
	{
		printf ("not NEQ\n");
	}
	printf ("\n");
	//TEST IsOrigin
	printf ("TEST IsOrigin\n");
	if (IsOrigin(P1) == true)
	{
		printf ("origin\n");
	}
	else
	{
		printf ("not origin\n");
	}
	printf ("\n");
	//TEST IsOnSbX
	printf ("TEST IsOnSbX\n");
	if (IsOnSbX(P1) == true)
	{
		printf ("sumbu X\n");
	}
	else
	{
		printf ("not sumbu X\n");
	}
	printf ("\n");
	//TEST IsOnSbY
	printf ("TEST IsOnSbY\n");
	if (IsOnSbY(P1) == true)
	{
		printf ("sumbu Y\n");
	}
	else
	{
		printf ("not sumbu Y\n");
	}
	printf ("\n");
	//TEST NextX
	printf ("TEST NextX\n");
	printf ("salinan point P1 nextX : "); TulisPOINT(NextX(P1));
	printf ("point P1 : "); TulisPOINT(P1);
	printf ("\n");
	//TEST NextY
	printf ("TEST NextY\n");
	printf ("salinan point P1 nextY : "); TulisPOINT(NextY(P1));
	printf ("point P1 : "); TulisPOINT(P1);
	printf ("\n");
	//TEST PlusDelta
	printf ("TEST PlusDelta\n");
	printf ("delta X : "); scanf ("%f", &a);
	printf ("delta Y : "); scanf ("%f", &b);
	printf ("salinan point P1 PlusDelta : "); TulisPOINT(PlusDelta(P1, a, b));
	printf ("point P1 : "); TulisPOINT(P1);
	printf ("\n");
	//TEST MirrorOf
	printf ("TEST MirrorOf\n");
	printf ("salinan point P3 MirrorOf SbX: "); TulisPOINT(MirrorOf(P3, true));
	printf ("point P3 : "); TulisPOINT(P3);
	printf ("salinan point P4 MirrorOf SbY: "); TulisPOINT(MirrorOf(P4, false));
	printf ("point P4 : "); TulisPOINT(P4);
	printf ("\n");
	//TEST Jarak0
	printf ("TEST Jarak0\n");
	printf ("panjang point P1 ke titik (0.00,0.00) : %.2f\n", Jarak0(P1));
	printf ("\n");
	//TEST Panjang
	printf ("TEST Panjang\n");
	printf ("panjang point P1 P2 : %.2f\n", Panjang(P1, P2));
	printf ("\n");
	//TEST Geser
	printf ("TEST Geser\n");
	printf ("point P1 : "); TulisPOINT(P1);
	printf ("delta X : "); scanf ("%f", &c);
	printf ("delta Y : "); scanf ("%f", &d);
	Geser(&P1, c, d);
	printf ("point P1 baru : "); TulisPOINT(P1);
	printf ("\n");
	//TEST GeserKeSbX
	printf ("TEST GeserKeSbX\n");
	printf ("point P1 : "); TulisPOINT(P1);
	GeserKeSbX(&P1);
	printf ("point P1 ke sumbu X : "); TulisPOINT(P1);
	printf ("\n");
	//TEST GeserKeSbY
	printf ("TEST GeserKeSbY\n");
	printf ("point P2 : "); TulisPOINT(P2);
	GeserKeSbY(&P2);
	printf ("point P2 ke sumbu Y : "); TulisPOINT(P2);
	printf ("\n");
	//TEST Mirror
	printf ("TEST Mirror\n");
	printf ("point P3 : "); TulisPOINT(P3);
	Mirror(&P3, true);
	printf ("point P3 mirror SbX : "); TulisPOINT(P3);
	printf ("point P4 : "); TulisPOINT(P4);
	Mirror(&P4, false);
	printf ("point P4 mirror SbY : "); TulisPOINT(P4);
	printf ("\n");
	//TEST Putar
	printf ("TEST Putar\n");
	printf ("point P4 : "); TulisPOINT(P4);
	printf ("sudut : "); scanf ("%f", &e);
	Putar(&P4, e);
	printf ("point P4 putar : "); TulisPOINT(P4);
	return 0;
}
