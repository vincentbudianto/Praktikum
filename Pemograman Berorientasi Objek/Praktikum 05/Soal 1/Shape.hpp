/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Shape.hpp
 * Topik     : Praktikum 5
 * Tanggal   : 21 Februari 2019
 * Deskripsi : Header Shape.cpp */

#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
	public:
		// dtor
		// print "SHAPE DELETED<endl>"
		virtual ~Shape();

		 // method yang belum diimplementasi, pure virtual
		virtual float area() = 0;
		virtual float perimeter() = 0;
		virtual void print() = 0;
};

#endif
