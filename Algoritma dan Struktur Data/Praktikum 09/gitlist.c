/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : gitlist.c
 * Topik     : Praktikum 09
 * Tanggal   : 01 November 2018
 * Deskripsi : Driver ADT LISTDP */

#include <stdio.h>
#include "listdp.h"

//Program Utama
int main()
{
	//Kamus
	address		HEAD;
	address		i;
	address		temp;
	char		X;
	infotype	k;
	int			n;
	int			j;
	List		L;
	
	//Algoritma
	HEAD = Nil;
	k = 0;
	CreateEmpty(&L);
	do
	{
		scanf("%c", &X);
		switch (X)
		{
			case 'C' :
			{
				if (HEAD == Nil)
				{
					InsVFirst(&L,k);
					HEAD = First(L);
				}
				else
				{
					i = Alokasi(k);
					InsertAfter(&L, i, HEAD);
					HEAD = i;
				}
				k++;
				break;
			}
			case 'R' :
			{
				scanf("%d", &n);
				if (Search(L,n) != Nil)
				{
					HEAD = Search(L,n);
				}
				break;
			}
			case 'H' :
			{
				scanf("%d", &n);
				if (Search(L,n) != Nil)
				{
					HEAD = Search(L,n);
					while (Next(HEAD) != Nil)
					{
						DelAfter(&L, &temp, HEAD); 
					}
				}
				break;
			}
			case 'B' :
			{
				scanf("%d", &n);
				if (!(IsEmpty(L)))
				{
					j = 1;
					while ((j <= n) && (Prev(HEAD) != Nil))
					{
						HEAD = Prev(HEAD);
						j++;
					}
				}
				break;
			}
			case 'F' :
			{
				scanf("%d", &n);
				if (!(IsEmpty(L)))
				{
					j = 1;
					while ((j <= n) && (Next(HEAD) != Nil))
					{
						HEAD = Next(HEAD);
						j++;
					}
				}
				break;
			}
			case 'L' :
			{
				if (IsEmpty(L))
				{
					printf("Tidak ada elemen\n");
				}
				else
				{
					printf("Isi List : ");
					PrintForward(L);
					printf("\n");
					printf("HEAD : %d\n", Info(HEAD));
				}
				break;
			}
			case 'V' :
			{
				if (IsEmpty(L))
				{
					printf("Tidak ada elemen\n");
				}
				else
				{
					printf("Isi List : ");
					PrintBackward(L);
					printf("\n");
					printf("HEAD : %d\n", Info(HEAD));
				}
				
				break;
			}
		}
	} while (X != 'X');
	return 0;
}
