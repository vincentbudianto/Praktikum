/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : bintree.c
 * Topik     : ADT BINTREE
 * Tanggal   : 22 November 2018
 * Deskripsi : Realisasi ADT BINTREE */

#include <stdlib.h>
#include "bintree.h"

//Definisi Fungsi dan Prosedur Lain
void PrintTreeRec (BinTree P, int g, int h);
void DelNode (BinTree *P, addrNode *q);

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	//Kamus
	addrNode T;
	
	//Algoritma
	T = AlokNode(Akar);
	if (T != Nil)
	{
		Left(T) = L;
		Right(T) = R;
	}
	return (T);
}
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
	//Kamus
	
	//Algoritma
	*P = Tree(Akar, L, R);
}
BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
{
	//Kamus
	addrNode T;
	BinTree L;
	BinTree R;
	infotype X;
	int nL;
	int nR;
	
	//Algoritma
	if (n == 0)
	{
		return (Nil);
	}
	else
	{
		scanf("%d", &X);
		T = AlokNode(X);
		if (T != Nil)
		{
			Akar(T) = X;
			nL = n / 2;
			nR = n - nL - 1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(T) = L; 
			Right(T) = R;
		}
		return (T);
	}
}

/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//Kamus
	addrNode T;
	
	//Algoritma
	T = (addrNode) malloc(sizeof(infotype));
	Akar(T) = X;
	Left(T) = Nil;
	Right(T) = Nil;
	return (T);
}
void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
	//Kamus
	
	//Algoritma
	free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	//Kamus
	
	//Algoritma
	return (P == Nil);
}
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
	//Kamus
	
	//Algoritma
	if (!IsTreeEmpty(P))
	{
		return ((Left(P) == Nil) && (Right(P) == Nil));
	}
	else
	{
		return (false);
	}
}
boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
	//Kamus
	
	//Algoritma
	if (!IsTreeEmpty(P))
	{
		return ((Left(P) != Nil) && (Right(P) == Nil));
	}
	else
	{
		return (false);
	}
}
boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
	//Kamus
	
	//Algoritma
	if (!IsTreeEmpty(P))
	{
		return ((Left(P) == Nil) && (Right(P) != Nil));
	}
	else
	{
		return (false);
	}
}
boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
	//Kamus
	
	//Algoritma
	if (!IsTreeEmpty(P))
	{
		return ((Left(P) != Nil) && (Right(P) != Nil));
	}
	else
	{
		return (false);
	}
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
	//Kamus
	
	//Algoritma
	printf("(");
	if (!IsTreeEmpty(P))
	{
		printf("%d", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}
void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
	//Kamus
	
	//Algoritma
	printf("(");
	if (!IsTreeEmpty(P))
	{
		PrintInorder(Left(P));
		printf("%d", Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
}
void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
	//Kamus
	
	//Algoritma
	printf("(");
	if (!IsTreeEmpty(P))
	{
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d", Akar(P));
	}
	printf(")");
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
	//Kamus
	
	//Algoritma
	PrintTreeRec(P,0,h);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return (false);
	}
	else if (Akar(P) == X)
	{
		return (true);
	}
	else
	{
		return ((SearchTree(Left(P),X)) || (SearchTree(Right(P),X)));
	}
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return 0;
	}
	else
	{
		return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
	}
}
int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return 0;
	}
	else if (IsTreeOneElmt(P))
	{
		return 1;
	}
	else
	{
		return (NbDaun(Left(P)) + NbDaun(Right(P)));
	}
}
boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return (true);
	}
	else
	{
		return ((Right(P) == Nil) && (IsSkewLeft(Left(P))));
	}
}
boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return (true);
	}
	else
	{
		return ((Left(P) == Nil) && (IsSkewRight(Right(P))));
	}
}
int Level(BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
	//Kamus
	
	//Algoritma
	if (Akar(P) == X)
	{
		return 1;
	}
	else if (SearchTree(Left(P),X))
	{
		return (1 + Level(Left(P),X));
	}
	else
	{
		return (1 + Level(Right(P),X));
	}
}
int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return 0;
	}
	else
	{
		if (Tinggi(Left(P)) > Tinggi(Right(P)))
		{
			return (1 + Tinggi(Left(P)));
		}
		else
		{
			return (1 + Tinggi(Right(P)));
		}
	}
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(*P))
	{
		*P = Tree(X,Nil,Nil);
	}
	else if (IsUnerRight(*P))
	{
		Left(*P) = Tree(X,Nil,Nil);
	}
	else
	{
		AddDaunTerkiri(P,X);
	}
}
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
	//Kamus
	List daun;
	
	//Algoritma
	if (!IsTreeEmpty(*P))
	{
		if (IsTreeOneElmt(*P) && Akar(*P) == X)
		{
			if (Kiri)
			{
				Left(*P) = Tree(Y, Nil, Nil);
			}
			else
			{
				Right(*P) = Tree(Y, Nil, Nil);
			}
		}
		else
		{
			daun = MakeListDaun(Left(*P));
			if (Search(daun, X))
			{
				AddDaun(&Left(*P), X, Y, Kiri);
			}
			else
			{
				AddDaun(&Right(*P), X, Y, Kiri);
			}
		}
	}
}
void DelDaunTerkiri(BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
	//Kamus
	
	//Algoritma
	if (IsTreeOneElmt(*P))
	{
		*X = Akar(*P);
		*P = Nil;
	}
	else if (IsUnerRight(*P))
	{
		if (IsTreeOneElmt(Right(*P)))
		{
			*X = Akar(Right(*P));
			DealokNode(Right(*P));
			Right(*P) = Nil;
		}
		else
		{
			DelDaunTerkiri(&Right(*P),X);
		}
	}
	else if (IsTreeOneElmt(Left(*P)))
	{
		*X = Akar(Left(*P));
		DealokNode(Left(*P));
		Left(*P) = Nil;
	}
	else
	{
		DelDaunTerkiri(&Left(*P),X);
	}
}
void DelDaun(BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
	//Kamus
	
	//Algoritma
	if (!IsTreeEmpty(*P))
	{
		if (IsTreeOneElmt(*P))
		{
			if (Akar(*P) == X)
			{
				DealokNode(*P);
				*P = Nil;
			}
		}
		else if ((Left(*P) != Nil) && (Akar(Left(*P)) == X) && (IsTreeOneElmt(Left(*P))))
		{
			DealokNode(Left(*P));
			Left(*P) = Nil;
		}
		else if ((Right(*P) != Nil) && (Akar(Right(*P)) == X) && (IsTreeOneElmt(Right(*P))))
		{
			DealokNode(Right(*P));
			Right(*P) = Nil;
		}
		if (!IsTreeEmpty(*P))
		{
			DelDaun(&Left(*P),X);
			DelDaun(&Right(*P),X);
		}
	}
}
List MakeListDaun(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return (Nil);
	}
	if (IsTreeOneElmt(P))
	{
		return (Alokasi(Akar(P)));
	}
	else
	{
		return (Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P))));
	}
}
List MakeListPreorder(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return (Nil);
	}
	if (IsTreeOneElmt(P))
	{
		return (Alokasi(Akar(P)));
	}
	else
	{
		return (Konso(Akar(P),Concat(MakeListPreorder(Left(P)),MakeListPreorder(Right(P)))));
	}
}
List MakeListLevel(BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	//Kamus
	
	//Algoritma
	if (!IsTreeEmpty(P) && (N == 1))
	{
		return (Alokasi(Akar(P)));
	}
	else if (!IsTreeEmpty(P))
	{
		return (Concat(MakeListLevel(Left(P),(N - 1)),MakeListLevel(Right(P),(N - 1))));
	}
	else
	{
		return (Nil);
	}
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(P))
	{
		return (false);
	}
	else
	{
		if (Akar(P) == X)
		{
			return (true);
		}
		else
		{
			if (Akar(P) > X)
			{
				return (BSearch(Left(P),X));
			}
			else if (Akar(P) < X)
			{
				return (BSearch(Right(P),X));
			}
		}
	}
}

void InsSearch(BinTree *P, infotype X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
{
	//Kamus
	
	//Algoritma
	if (IsTreeEmpty(*P))
	{
		MakeTree(X,Nil,Nil,P);
	}
	else
	{
		if (Akar(*P) > X)
		{
			InsSearch(&Left(*P),X);
		}
		else if (Akar(*P) < X)
		{
			InsSearch(&Right(*P),X);
		}
	}
}

void DelBtree(BinTree *P, infotype X)
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
{
	//Kamus Lokal
	BinTree q;
	
	//Algoritma
	if (Akar(*P) > X)
	{
		DelBtree(&Left(*P),X);
	}
	else if (Akar(*P) < X)
	{
		DelBtree(&Right(*P),X);
	}
	else
	{
		q = *P;
		Left(q) = Left(*P);
		Right(q) = Right(*P);
		if (IsTreeOneElmt(q))
		{
			*P = Nil;
		}
		else if (IsUnerLeft(q))
		{
			*P = Left(q);
		}
		else if (IsUnerRight(q))
		{
			*P = Right(q);
		}
		else
		{
			DelNode(&Left(q),&Left(q));
		}
		DealokNode(q);
	}
}

//Realisasi Fungsi dan Prosedur Lain
void PrintTreeRec (BinTree P, int g, int h)
{
	//Kamus
	int i;
	
	//Algoritma
	if (!IsTreeEmpty(P))
	{
		for (i = 0; i < (g * h); i++)
		{
			printf(" ");
		}
		printf("%d\n", Akar(P));
		PrintTreeRec(Left(P),(g + 1),h);
		PrintTreeRec(Right(P),(g + 1),h);
	}
}
void DelNode (BinTree *P, addrNode *q)
{
	//Kamus Lokal
	
	//Algoritma
	if (Right(*P) != Nil)
	{
		DelNode(&Right(*P),q);
	}
	else
	{
		*q = *P;
		Akar(*q) = Akar(*P);
		*P = Left(*P);
	}
}
