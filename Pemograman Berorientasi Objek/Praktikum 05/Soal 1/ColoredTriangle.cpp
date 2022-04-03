/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : ColoredTriangle.cpp
 * Topik     : Praktikum 5
 * Tanggal   : 21 Februari 2019
 * Deskripsi : Implementasi ColoredTriangle.cpp */

#include "Shape.hpp"
#include "Triangle.hpp"
#include "ColoredTriangle.hpp"
#include <iostream>

using namespace std;

ColoredTriangle::ColoredTriangle(float s1, float s2, float s3, int r, int g, int b): Triangle(s1,s2,s3)
{
	rgb = new int[3];
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

ColoredTriangle::ColoredTriangle(const ColoredTriangle& coloredTriangle): Triangle(coloredTriangle)
{
	rgb = new int[3];
	rgb[0] = coloredTriangle.rgb[0];
	rgb[1] = coloredTriangle.rgb[1];
	rgb[2] = coloredTriangle.rgb[2];
}

ColoredTriangle::~ColoredTriangle()
{
	delete [] rgb;
	cout << "COLORED TRIANGLE DELETED" << endl;
}

ColoredTriangle& ColoredTriangle::operator=(const ColoredTriangle& coloredTriangle)
{
	Triangle::operator=(coloredTriangle);
	delete [] rgb;
	rgb = new int[3];
	rgb[0] = coloredTriangle.rgb[0];
	rgb[1] = coloredTriangle.rgb[1];
	rgb[2] = coloredTriangle.rgb[2];
	
	return *this;
}

// getter & setter
int ColoredTriangle::getRed() const
{
	return rgb[0];
}

int ColoredTriangle::getGreen() const
{
	return rgb[1];
}

int ColoredTriangle::getBlue() const
{
	return rgb[2];
}

void ColoredTriangle::setRed(int r)
{
	rgb[0] = r;
}

void ColoredTriangle::setGreen(int g)
{
	rgb[1] = g;
}

void ColoredTriangle::setBlue(int b)
{
	rgb[2] = b;
}

void ColoredTriangle::print()
{
	cout << "COLOREDTRIANGLE(" << s[0] << "," << s[1] << "," << s[2] << "," << rgb[0] << "," << rgb[1] << "," << rgb[2] << ")" << endl;
}
