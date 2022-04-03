/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : warna.h
 * Topik     : Praktikum 6
 * Tanggal   : 28 Februari 2019
 * Deskripsi : Kelas generik warna.h */

#include <math.h>

template <class T>
class Warna
{
	public:
		// Ctor tanpa parameter
		Warna<T>()
		{	
		}
		
		// Ctor berparameter, parameter berturut-turut R,G,B
		Warna<T>(T R, T G, T B)
		{
			r = R;
			g = G;
			b = B;
		}

		// Getter dan setter
		T getRed() const
		{
			return r;
		}
		
		T getGreen() const
		{
			return g;
		}
		
		T getBlue() const
		{
			return b;
		}
		
		void setRed(T R)
		{
			r = R;
		}
		
		void setGreen(T G)
		{
			g = G;
		}
		
		void setBlue(T B)
		{
			b = B;
		}

		//menghasilkan perbedaan absolut antara nilai R, G, dan B (Warna(abs(r1-r2),abs(g1-g2),abs(b1-b2)))
		T countDifference(Warna<T> A)
		{
			return (abs(r - A.r) + abs(g - A.g) + abs(b - A.b));
		}

		// Operator overloading, mengubah nilai warna
		//rnew=r1+r2, gnew=g1+g2, bnew = b1+b2
		Warna<T> operator +(const Warna<T>& A) const
		{
			Warna<T> W;
			
			W.r = r + A.r;
			W.g = g + A.g;
			W.b = b + A.b;
			
			return W;
		}
		
		//rnew=r1-r2, gnew=g1-g2, bnew = b1-b2
		Warna<T> operator -(const Warna<T>& A) const
		{
			Warna<T> W;
			
			W.r = r - A.r;
			W.g = g - A.g;
			W.b = b - A.b;
			
			return W;
		}
		
	private:
		T r;
		T g;
		T b;
};
