/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : PhysicException.cpp
 * Topik     : Quiz Online
 * Tanggal   : 01 Maret 2019
 * Deskripsi : Implementasi PhysicException.cpp */

#include "PhysicException.hpp"
#include <iostream>
#include <cstring>
using namespace std;


PhysicException::PhysicException(string)
{
	msg = string;
}	

string PhysicException::getMsg()
{
	return msg;
}
