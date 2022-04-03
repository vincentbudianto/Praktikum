/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : mesintoken.c
 * Topik     : ADT MESINTOKEN
 * Tanggal   : 27 September 2018
 * Deskripsi : Realisasi ADT MESINTOKEN */

#include "mesinkar.h"
#include "mesintoken.h"

//KAMUS UMUM
boolean EndToken;
Token CToken;

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

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
	//Kamus

	//Algoritma
	START();
	EndToken = false;
	IgnoreBlank();
	ADVTOKEN();
}

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	//Kamus

	//Algoritma
	if (CC == MARK)
	{
		EndToken = true;
	}
	else 
	{
		SalinToken();
		IgnoreBlank();
	}
}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	//Kamus

	//Algoritma
	CToken.tkn = CC;
	if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^'))
	{
		CToken.val = -1;
		ADV();
	}
	else
	{
		CToken.tkn = 'b';
		CToken.val = 0;
		while (CC != MARK && CC != BLANK)
		{
			CToken.val *= 10;
			CToken.val += (int) (CC - '0');
			ADV();
		}
	}
}
