/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : dictionary.h
 * Topik     : Ujian Tengah Semester Praktikum 
 * Tanggal   : 08 Maret 2019
 * Deskripsi : Template class dictionary */

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "entry.h"
#include <iostream>
using namespace std;

template<class K, class V>
class dictionary
{
	private:
		entry<K, V> *data;
		int neff;

	public:
		dictionary()
		{
			data = new entry[100];
			neff = 0;
		}
		
		void put(K key, V value)
		{
			data[neff] = entry(key, value);
			neff++;
		}
		
		void get(K key)
		{
			bool found;
			int i;
			
			found = false;
			i = 0;
			
			while ((i <= neff) && !found)
			{
				if (key == data[i].getKey())
				{
					found == true;
				}
				else
				{
					i++;
				}
			}
			
			if (found)
			{
				cout << data[i].getValue();
			}
		}
		
		void remove(K key)
		{
			
		}
		
		bool containsKey(K key)
		{
			bool found;
			int i;
			
			found = false;
			i = 0;
			
			while ((i <= neff) && !found)
			{
				if (key == data[i].getKey())
				{
					found == true;
				}
				else
				{
					i++;
				}
			}
			
			return found;
		}
};

#endif
