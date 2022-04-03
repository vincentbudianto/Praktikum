/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : array_warna.h
 * Topik     : Praktikum 6
 * Tanggal   : 28 Februari 2019
 * Deskripsi : Kelas generik array_warna.h */

#include "warna.h"

template <class T>
class ArrayWarna
{
	public:
		// cctor tanpa parameter dengan ukuran maksimum 10
		ArrayWarna<T>()
		{
			size = 10;
			neff = 0;
			data = new T[size];
			warna = new Warna<T>[size];
		}
		
		// Membuat sebuah ArrayWarna dengan ukuran maksimum n
		ArrayWarna<T>(int n)
		{
			size = n;
			neff = 0;
			data = new T[size];
			warna = new Warna<T>[size];
		}
		
		// cctor
		ArrayWarna<T>(const ArrayWarna<T>& A)
		{
			int i;
			
			size = A.size;
			neff = A.neff;
			data = new T[size];
			
			for (i = 0; i < neff; i++)
			{
				data[i] = A.data[i];
			}
			
			warna = new Warna<T>[size];
			
			for (i = 0; i < neff; i++)
			{
				warna[i] = A.warna[i];
			}
		}
		
		// Operator=
		ArrayWarna<T>& operator=(const ArrayWarna<T>& A)
		{
			int i;
			
			delete[] data;
			delete[] warna;
			size = A.size;
			neff = A.neff;
			data = new T[size];
			
			for (i = 0; i < neff; i++)
			{
				data[i] = A.data[i];
			}
			
			warna = new Warna<T>[size];
			
			for (i = 0; i < neff; i++)
			{
				warna[i] = A.warna[i];
			}
			
			return *this;
		}

		// true jika array penuh
		bool isFull()
		{
			return (neff == size);
		}
		
		// true jika array kosong
		bool isEmpty()
		{
			return (neff == 0);
		}

		// Getter
		int getSize() const
		{
			return size;
		}
		
		int getNeff() const
		{
			return neff;
		}
		
		// Menambahkan elemen warna dan data di akhir array
		void addElement(T x, Warna<T> y)
		{
			if (neff < size)
			{
				data[neff] = x;
				warna[neff] = y;
				neff++;
			}
		}
		
		// Mengubah warna dan data pada index ke n
		void setElement(T x, Warna<T> y, int n)
		{
			if ((n < neff) && (n >= 0))
			{
				data[n] = x;
				warna[n] = y;
			}
		}

		// Mengembalikan data pada index ke n; n mungkin di luar index
		T getData(int n)
		{
			if ((n < neff) && (n >= 0))
			{
				return data[n];
			}
		}
		
		// Mengembalikan warna pada index ke n; n mungkin di luar index
		Warna<T> getWarna(int n)
		{
			if ((n < neff) && (n >= 0))
			{
				return warna[n];
			}
		}
		
	private:
		T *data;
		Warna<T> *warna;
		int size;
		int neff;
};
