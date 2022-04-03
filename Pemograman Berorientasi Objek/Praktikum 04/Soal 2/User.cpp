/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : User.cpp
 * Topik     : Praktikum 4
 * Tanggal   : 14 Februari 2019
 * Deskripsi : Implementasi User.cpp */

#include "User.h"
#include <iostream>
#include <cstring>
using namespace std;

int User::n_user = 0;

User::User(char* s)
{
	music_list = new char*[100];
	name = new char[strlen(s)];
	strcpy(name, s);
	num_of_favourite_music = 0;
	n_user++;
}

User::User(const User& u)
{
	int i;
	
	music_list = new char*[100];
	name = new char[strlen(u.name)];
	strcpy(name, u.name);	
	num_of_favourite_music=u.num_of_favourite_music;
	
	for (i = 0; i < u.num_of_favourite_music; i++)
	{
		music_list[i] = new char[strlen(u.music_list[i])];
		strcpy(music_list[i], u.music_list[i]);
	}
	
	n_user++;
}

User::~User()
{
	int i;
	
	cout << "User " << name << " deleted" << endl;
	delete [] name;
	
	for (i = 0; i < num_of_favourite_music; i++)
	{
		delete[] music_list[i];
	}
	
	delete[] music_list;
	n_user--;
}

void User::addFavouriteMusic(char* judul)
{
	music_list[num_of_favourite_music] = new char[strlen(judul)];
	strcpy(music_list[num_of_favourite_music], judul);
	num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* judul)
{
	int i, j;
	
	for (i = 0; i < num_of_favourite_music; i++)
	{
		if (strcmp(judul,music_list[i]) == 0)
		{
			for (j = (i + 1); j < num_of_favourite_music; j++)
			{
				delete[] music_list[j - 1];
				music_list[j - 1] = new char[strlen(music_list[j])];
				strcpy(music_list[j - 1], music_list[j]);
			}
			
			num_of_favourite_music--;
			break;
		}
	}
}

void User::setName(char* _name)
{
	delete [] name;
	name = new char[strlen(_name)];
	strcpy(name, _name);
}

char* User::getName() const
{
	return name;
}

int User::getNumOfFavouriteMusic() const
{
	return num_of_favourite_music;
}

void User::viewMusicList() const
{
	int i;
	
	if (num_of_favourite_music>0)
	{
		for (i = 0; i < num_of_favourite_music; i++)
		{
			cout << (i + 1) << ". " << music_list[i] << endl;
		}
	}
	else
	{
		cout << "No music in your favourite list" << endl;
	}
}
	
int User::getNumOfUser()
{
	return n_user;
}
