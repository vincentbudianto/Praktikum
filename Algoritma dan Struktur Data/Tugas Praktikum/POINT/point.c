/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : point.c
 * Topik     : ADT POINT
 * Tanggal   : 6 September 2018
 * Deskripsi : Realisasi ADT POINT */

#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	//KAMUS LOKAL
	POINT P;
	
	//ALGORITMA
	Absis(P) = X;
	Ordinat(P) = Y;
	return (P);
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT *P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	//KAMUS LOKAL
	float x;
	float y;
	
	//ALGORITMA
	scanf ("%f %f", &x, &y);
	*P = MakePOINT(x, y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	printf ("(%.2f,%.2f)\n", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return (Absis(P) == 0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
	//KAMUS LOKAL
	int nilai;
	
	//ALGORITMA
	if ((Absis(P) > 0) && (Ordinat(P) > 0))
	{
		nilai = 1;
	}
	else if ((Absis(P) < 0) && (Ordinat(P) > 0))
	{
		nilai = 2;
	}
	else if ((Absis(P) < 0) && (Ordinat(P) < 0))
	{
		nilai = 3;
	}
	else if ((Absis(P) > 0) && (Ordinat(P) < 0))
	{
		nilai = 4;
	}
	return (nilai);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	//KAMUS LOKAL
	POINT salin;
	
	//ALGORITMA
	salin.X = Absis(P) + 1;
	salin.Y = Ordinat(P);
	return (salin);
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	//KAMUS LOKAL
	POINT salin;
	
	//ALGORITMA
	salin.X = Absis(P);
	salin.Y = Ordinat(P) + 1;
	return (salin);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	//KAMUS LOKAL
	POINT salin;
	
	//ALGORITMA
	salin.X = Absis(P) + deltaX;
	salin.Y = Ordinat(P) + deltaY;
	return (salin);
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	//KAMUS LOKAL
	POINT salin;
	
	//ALGORITMA
	if (SbX == true)
	{
		salin.X = Absis(P);
		salin.Y = -(Ordinat(P));
	}
	else
	{
		salin.X = -(Absis(P));
		salin.Y = Ordinat(P);
	}
	return (salin);
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return (sqrt(((Absis(P)) * (Absis(P))) + ((Ordinat(P)) * (Ordinat(P)))));
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	return (sqrt(((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2))) + ((Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2)))));
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	*P = PlusDelta (*P, deltaX, deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	if (SbX == true)
	{
		Ordinat(*P) = -(Ordinat(*P));
	}
	else
	{
		Absis(*P) = -(Absis(*P));
	}
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
	//KAMUS LOKAL
	float temp;
	
	//ALGORITMA
	Sudut = Sudut / 180 * 3.14159265359;
	temp = Absis(*P);
	Absis(*P) = Absis(*P) * cos(Sudut) - Ordinat(*P) * sin(Sudut);
	Ordinat(*P) = temp * sin(Sudut) + Ordinat(*P) * cos(Sudut);
}
