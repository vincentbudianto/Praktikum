/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : main.cpp
 * Topik     : Praktikum 3
 * Tanggal   : 07 Februari 2019
 * Deskripsi : Driver Box.cpp */

#include "Box.h"

int main()
{
	Box b0(2);
	b0.set(0, 50);
	b0.set(1, 30);
	b0.show();
	Box b1(b0);
	Box b2(2);
	b2=b1;
	b0.set(0, 10);
	b0.show();
	b1.show();
	b2.show();
	Box b3(2);
	b3=((b0+b2)+b1);
	b3.show();
	return 0;
}
