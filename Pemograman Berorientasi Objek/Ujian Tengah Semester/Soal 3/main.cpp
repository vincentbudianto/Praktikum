/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : main.cpp
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Driver entry.h + dictionary.h */

#include "entry.h"
#include "dictionary.h"
#include <iostream>
using namespace std;

int main()
{
	dictionary<int,string> d; // dapat berisi sekumpulan entry<int,string>
		
	try
	{
		d.put(1,"one"); // isi d saat ini: [1:one]                        (menyimpan entry(1,"one") ke d)
		cout<<1<<": "<<d.get(1)<<endl; // mencetak "1: one"   (mengambil value entry yang memiliki key 1)
		
		d.put(2,"two"); // isi d saat ini: [1:one,2:two]
		cout<<1<<": "<<d.get(1)<<endl; // mencetak "1: one"
		cout<<2<<": "<<d.get(2)<<endl; // mencetak "2: two"
		
		d.put(1,"satu");  // isi d saat ini: [1:satu,2:two],     (menimpa value dari key 1 dengan "satu")
						  // BUKAN [1:one,2:two,1:satu]
		d.put(3,"three"); // isi d saat ini: [1:satu,2:two,3:three]
		cout<<1<<": "<<d.get(1)<<endl; // mencetak "1: satu"
		cout<<2<<": "<<d.get(2)<<endl; // mencetak "2: two"
		cout<<3<<": "<<d.get(3)<<endl; // mencetak "3: three"
		
		d.remove(2); // isi d saat ini: [1:satu,3:three]            (menghapus entry yang memiliki key 2)
		cout<<1<<": "<<d.get(1)<<endl; // mencetak "1: satu"
		
		if (d.containsKey(2))
		{                // (mengembalikan true jika d memiliki entry dengan key 2)
			cout<<2<<": "<<d.get(2)<<endl; // tidak ada output 
		}
		
		cout<<2<<": "<<d.get(2)<<endl; // mencetak "exception: key not found!"     (key 2 tidak ada di d)
		cout<<3<<": "<<d.get(3)<<endl; // tidak ada output karena sudah exception
	}
	catch (const char* c)
	{
		cout<<"exception: "<<c<<endl;
		return 1;
	}
	
	return 0;
}
