/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : P00_13517137_01c.c
 * Topik     : Translasi Notasi Algoritmik ke Bahasa C
 * Tanggal   : 30 Agustus 2018
 * Deskripsi : Input  : JamAwal, JamAKhir  bertype Jam (HH:MM:DD);      
 * 						dan JamAkhir selalu lebih besar sama dengan JamAwal   
 * 			   Output : Selisih waktu dalam detik antara JamAwal dan JamAkhir */
 
#include <stdio.h>
 
int main()
{
	//KAMUS
	typedef struct {
		int HH; //00..23
		int MM; //00..59
		int DD; //00..59
	} Jam;
	
	Jam JamAwal;
	Jam JamAkhir;
	int Durasi; //>= 0
	
	//ALGORITMA
	scanf ("%d %d %d %d %d %d", &JamAwal.HH, &JamAwal.MM, &JamAwal.DD, &JamAkhir.HH, &JamAkhir.MM, &JamAkhir.DD);
	Durasi = (JamAkhir.HH * 3600 + JamAkhir.MM * 60 + JamAkhir.DD) - (JamAwal.HH * 3600 + JamAwal.MM * 60 + JamAwal.DD);
	printf ("%d\n", Durasi);
	return 0;
}
