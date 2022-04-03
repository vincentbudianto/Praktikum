/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : merkle.c
 * Topik     : Praktikum 11
 * Tanggal   : 22 November 2018
 * Deskripsi : Driver ADT BINTREE */

#include <math.h>
#include <stdio.h>
#include "bintree.h"

//Definisi Fungsi + Prosedur
BinTree BacaDaun(int N);

//Program Utama
int main()
{
	//Kamus
	BinTree T;
	int N;
	
	//Algoritma
	scanf("%d", &N);
	if (((N > 0)) && (log2(N) == floor(log2(N))))
	{
		T = BacaDaun(N);
		PrintTree(T,2);
	}
	else
	{
		printf("Jumlah masukan tidak sesuai\n");
	}
	return 0;
}

//Realisasi Fungsi + Prosedur
BinTree BacaDaun(int N)
{
	//Kamus
	BinTree T;
	BinTree T1;
	BinTree T2;
	BinTree L1;
	BinTree L2;
	BinTree R1;
	BinTree R2;
	infotype W;
	infotype X;
	infotype Y;
	infotype Z;
	
	//Algoritma
	if (N == 0)
	{
		return (Nil);
	}
	else if (N == 1)
	{
		scanf("%d", &X);
		T = AlokNode(X);
			return (T);
	}
	else if (N == 2)
	{
		scanf("%d", &X);
		scanf("%d", &Y);
		L = AlokNode(X);
		R = AlokNode(Y);
		Akar(T) = Akar(X) + Akar(Y);
		Left(T) = L;
		Right(T) = R;
		return (T);
	}
	else if (N == 4)
	{
		scanf("%d", &W);
		scanf("%d", &X);
		scanf("%d", &Y);
		scanf("%d", &Z);
		L1 = AlokNode(W);
		R1 = AlokNode(X);
		L2 = AlokNode(Y);
		R2 = AlokNode(Z);
		MakeTree((Akar(W) + Akar(X)),L1,R1,&T1);
		MakeTree((Akar(Y) + Akar(Z)),L2,R2,&T2);
		MakeTree((Akar(T1) + Akar(T2)),T1,T2,&T);
		return (T);
	}
}

