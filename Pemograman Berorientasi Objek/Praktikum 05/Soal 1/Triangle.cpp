/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Triangle.cpp
 * Topik     : Praktikum 5
 * Tanggal   : 21 Februari 2019
 * Deskripsi : Implementasi Triangle.cpp */

#include "Shape.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle(float s1, float s2, float s3)
{
	s = new float[3];
	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
}

Triangle::Triangle(const Triangle& triangle)
{
	s = new float[3];
	s[0] = triangle.getS1();
	s[1] = triangle.getS2();
	s[2] = triangle.getS3();
}

Triangle::~Triangle()
{
	delete [] s;
	cout << "TRIANGLE DELETED" << endl;
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
	delete [] s;
	s = new float[3];
	s[0] = triangle.getS1();
	s[1] = triangle.getS2();
	s[2] = triangle.getS3();
	return *this;
}

float Triangle::getS1() const
{
	return s[0];
}

float Triangle::getS2() const
{
	return s[1];
}

float Triangle::getS3() const
{
	return s[2];
}

void Triangle::setS1(float s1)
{
	s[0] = s1;
}

void Triangle::setS2(float s2)
{
	s[1] = s2;
}

void Triangle::setS3(float s3)
{
	s[2] = s3;
}

bool Triangle::isValid(float s1, float s2, float s3)
{
	return (((((s1 < s2) && (s2 < s3)) || ((s2 < s1) && (s1 < s3))) && (s1 + s2 > s3)) || ((((s1 < s3) && (s3 < s2)) || ((s3 < s1) && (s1 < s2))) && (s1 + s3 > s2)) || ((((s3 < s2) && (s2 < s1)) || ((s2 < s3) && (s3 < s1))) && (s3 + s2 > s1)));
}

float Triangle::area()
{
	float a;
	
	a = perimeter() * 0.5;
	
	return sqrt(a * (a - s[0]) * (a - s[1]) * (a - s[2]));
}

float Triangle::perimeter()
{
	return (s[0] + s[1] + s[2]);
}

void Triangle::print()
{
	cout << "TRIANGLE(" << s[0] << "," << s[1] << "," << s[2] << ")" << endl; 
}
