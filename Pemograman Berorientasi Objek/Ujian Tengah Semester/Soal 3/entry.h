/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : entry.h
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Template class entry */

#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <iostream>
using namespace std;

template<class K, class V>
class entry
{
	private:  
		K key;
		V value;
	
	public:
	   entry(K k, V v): key(k), value(v) {}
	   K getKey() { return key; }
	   V getValue() { return value; }
	   void setValue (V newValue) { value = newValue; }
};

#endif
