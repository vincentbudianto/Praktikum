/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : pecahan.h
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Header pecahan.cpp */

#ifndef _PECAHAN_H_
#define _PECAHAN_H_

class pecahan
{
	private:
		int n; // pembilang, n >= 0
		int d; // penyebut, d > 0
	
	public:
		// ctor: set n = 0 dan d = 1
		pecahan();
		
		// ctor: set n = _n dan d = _d
		pecahan(int _n, int _d);
		
		pecahan(const pecahan& P); // cctor: 
		
		//~pecahan(); // dtor
		
		pecahan& operator= (const pecahan& P); // operator assignment4
	
		int getPemb(); // Menghasillkan pembilang n
		int getPeny(); // Menghasilkan penyebut d
		
		void setPemb(int _n); // Mengubah nilai n menjadi _n
		void setPeny(int _d); // Mengubah nilai d menjadi _d
		
		pecahan operator+ (pecahan P);
		// Menambahkan pecahan dengan P
		// Rumus = n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2
		
		friend pecahan operator+ (pecahan P1, pecahan P2);
		// Menghasilkan P1 + P2
		// Rumus = n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2
		
		pecahan operator* (int x);
		// Mengalikan pembilang P dengan x dan penyebut P dengan x
		// Syarat: x > 0
		// Rumus = n1/d1 = (n1*x)/(d1*x)
		
		friend pecahan operator* (int x, pecahan P);
		// Mengalikan pembilang P dengan x dan penyebut P dengan x
		// Syarat: x > 0
		// Rumus = n1/d1 = (n1*x)/(d1*x) 
		
		float RealP();
		// Menghasilkan bentuk desimal dari pecahan
		
		void Print();
		// Mencetak pecahan dalam format: n/d (tanpa tambahan karakter apa pun 
		// di depan, tengah, atau belakang)
};

#endif
