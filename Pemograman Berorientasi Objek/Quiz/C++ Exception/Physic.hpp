/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Physic.hpp
 * Topik     : Quiz Online
 * Tanggal   : 01 Maret 2019
 * Deskripsi : Header Physic.cpp */

#ifndef PHYSIC_HPP
#define PHYSIC_HPP

#include "PhysicException.hpp"

class Physic {
	public:
		//Constructor dengan parameter.
		Physic(int pressure, int temperature);

		//Kembalikan nilai pressure/temperature (pembagian, pembulatan ke bawah).
		//Jika temperature bernilai 0, 
		//maka akan melemparkan sebuah PhysicException dengan pesan "Suhu tidak valid", tanpa newline.
		int constant();

	private:
		int pressure;
		int temperature;
};

#endif
