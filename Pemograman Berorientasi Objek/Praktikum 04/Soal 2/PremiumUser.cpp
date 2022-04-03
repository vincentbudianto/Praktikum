/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : PremiumUser.cpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Implementasi PremiumUser.cpp */

#include "User.h"
#include "PremiumUser.h"
#include <iostream>
using namespace std;

PremiumUser::PremiumUser(char* n): User(n)
{
	num_of_music_downloaded = 0;
	active = true;
}

void PremiumUser::downloadMusic(char* j)
{
	if (!active)
	{
		cout << "Activate premium account to download music" << endl;
	}
	else
	{
		cout << "Music Downloaded: " << j << endl;
		num_of_music_downloaded++;
	}
}
void PremiumUser::inactivatePremium()
{
	active = false;
}

void PremiumUser::activatePremium()
{
	active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const
{
	return num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const
{
	return active;
}

