/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Circle.hpp
 * Topik     : Praktikum 5
 * Tanggal   : 21 Februari 2019
 * Deskripsi : Header Circle.cpp */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
	public:
		//ctor
		Circle(float radius);

		// getter & setter
		float getRadius() const;
		void setRadius(float radius);

		// implementasi area (method untuk menghitung luas)
		// untuk nilai phi gunakan nilai 3.14

		// implementasi perimeter (method untuk menghitung keliling)
		// untuk nilai phi gunakan nilai 3.14

		// implementasi print (method untuk menampilkan informasi)
		//format: CIRCLE(radius) diahkhiri endline
		//contoh: CIRCLE(7)

		float area();
		float perimeter();
		void print();

	private:
		float radius;
};

#endif
