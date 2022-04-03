/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : ArtistUser.cpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Implementasi ArtistUser.cpp */

#include "User.h"
#include "ArtistUser.h"
#include <iostream>
#include <cstring>
using namespace std;

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* t): User(t)
{
	uploaded_music_list = new char*[100];
	num_of_music_uploaded = 0;
	num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& u): User(u)
{
	int i;
	
	uploaded_music_list = new char* [100];
	num_of_music_uploaded = u.num_of_music_uploaded;
	num_of_artist++;
	
	for (i = 0; i < u.num_of_music_uploaded; i++)
	{
		uploaded_music_list[i] = new char[strlen(u.uploaded_music_list[i])];
		strcpy(uploaded_music_list[i], u.uploaded_music_list[i]);
	}
}

ArtistUser::~ArtistUser()
{
	int i;
	
	num_of_artist--;

	for (i = 0; i < num_of_music_uploaded; i++)
	{
		delete[] uploaded_music_list[i];
	}

	delete[] uploaded_music_list;
	cout << "Artist user " << name << " deleted" << endl;
}

void ArtistUser::uploadMusic(char* t)
{
	uploaded_music_list[num_of_music_uploaded] = new char[strlen(t)];
	strcpy(uploaded_music_list[num_of_music_uploaded], t);
	num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char* judul)
{
	int i, j;
	
	for (i = 0; i < num_of_music_uploaded; i++)
	{
		if (strcmp(judul, uploaded_music_list[i]) == 0)
		{
			for (j = (i + 1); j < num_of_music_uploaded; j++)
			{
				delete[] uploaded_music_list[j - 1];
				uploaded_music_list[j - 1] = new char[strlen(uploaded_music_list[j])];
				strcpy(uploaded_music_list[j - 1], uploaded_music_list[j]);
			}
			
			num_of_music_uploaded--;
			break;
		}
	}
}

void ArtistUser::viewUploadedMusicList() const
{
	int i;
	
	if (num_of_music_uploaded > 0)
	{
		for (i = 0; i < num_of_music_uploaded; i++)
		{
			cout << (i + 1) << ". " << uploaded_music_list[i] << endl;
		}
	}
	else
	{
		cout << "No music uploaded" << endl;
	}
}

int ArtistUser::getNumOfMusicUploaded() const
{
	return num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist()
{
	return num_of_artist;
}
