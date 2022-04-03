/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : PremiumUser.h
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Header PremiumUser.cpp */

#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"
#include <iostream>

class PremiumUser : public User
{
	public:
		//ctor, active = true, parameter: nama pengguna
		PremiumUser(char*);
		
		// cctor
		PremiumUser(const PremiumUser&); // implementasikan jika diperlukan, 
		// jika tidak diperlukan, hapus cctor
		// jika perlu diimplementasikan, print "Premium User Copied<endl>"

		// dtor; implementasikan jika diperlukan
		~PremiumUser();
		// jika tidak diperlukan, hapus dtor
		// jika diperlukan
		// selain implementasi, print juga "Premium user <nama user> deleted<endl>"
		// Contoh:
		// Premium user A deleted
		
		// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
		// Contoh: 
		// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
		//
		// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
		void downloadMusic(char*);
		void inactivatePremium();
		void activatePremium();
		
		int getNumOfMusicDownloaded() const;

		// mengembalikan nilai active
		bool getPremiumStatus() const;
	
	private:
		int num_of_music_downloaded;
		bool active; //true : active, false : inactive
};

#endif
