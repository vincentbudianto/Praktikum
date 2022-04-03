/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Circle.cpp
 * Topik     : Praktikum 5
 * Tanggal   : 21 Februari 2019
 * Deskripsi : Implementasi Circle.cpp */

#include "Shape.hpp"
#include "Circle.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::area()
{
	return (3.14 * radius * radius);
}

float Circle::perimeter()
{
	return (2 * 3.14 * radius);
}

void Circle::print()
{
	cout << "CIRCLE(" << radius	<< ")" << endl;
}
