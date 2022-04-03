/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : PhysicException.hpp
 * Topik     : Quiz Online
 * Tanggal   : 01 Maret 2019
 * Deskripsi : Header PhysicException.cpp */

#ifndef PHYSICEXCEPTION_HPP
#define PHYSICEXCEPTION_HPP

#include <iostream>
#include <cstring>
using namespace std;


class PhysicException
{
	private:
		string msg;
	
	public:
		//ctor
		PhysicException(std::string);
		
		string getMsg();
};

#endif
