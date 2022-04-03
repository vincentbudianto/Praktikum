/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : mesinkata.c
 * Topik     : ADT MESINKATA
 * Tanggal   : 27 September 2018
 * Deskripsi : Realisasi ADT MESINKATA */

#include "mesinkar.h"
#include "mesinkata.h"

//KAMUS UMUM
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	//Kamus

	//Algoritma
	while (CC == BLANK)
	{
		ADV();
	}
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	//Kamus

	//Algoritma
	START();
	EndKata = false;
	IgnoreBlank();
	ADVKATA();	
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	//Kamus

	//Algoritma
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		SalinKata();
		IgnoreBlank();
	}
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	//Kamus

	//Algoritma
	CKata.Length = 0;
	while ((CC != BLANK) && (CC != MARK))
	{
		if (CKata.Length < NMax)
		{
			CKata.TabKata[++CKata.Length] = CC;
		}
		ADV();
	}
}
