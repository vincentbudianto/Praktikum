/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Time.cpp
 * Topik     : Praktikum 2
 * Tanggal   : 31 Januari 2019
 * Deskripsi : Implementasi Time.cpp */

#include "Time.h"
#include <iostream>
using namespace std;

int Time::n_time = 0;

Time::Time()
{
	setHour(0);
	setMinute(0);
	setSecond(0);
	n_time++;
}

Time::Time(int a, int b, int c)
{
	setHour(a);
	setMinute(b);
	setSecond(c);
	n_time++;
}

Time::Time(const Time& Time)
{
	setHour(Time.hour);
	setMinute(Time.minute);
	setSecond(Time.second);
	n_time++;
}

Time::~Time()
{
	n_time--;
}

void Time::setHour(int H)
{
	hour = H;
}

void Time::setMinute(int M)
{
	minute = M;
}

void Time::setSecond(int S)
{
	second = S;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

int Time::getSecond() const
{
	return second;
}

int Time::countTimeInstance()
/* Mengembalikan jumlah instance time yang sudah pernah dibuat */
{
	return n_time;
}

int Time::convertToSecond() const
{
	return ((((hour * 60) + minute) * 60) + second);
}

void Time::printTime()
/* Menuliskan jam dalam format hh:mm:ss diakhiri dengan newline.
 * Perhatikan bahwa setiap parameter harus dituliskan 2 digit. */
{
	printf("%.2d:%.2d:%.2d\n", hour, minute, second);
}

void Time::addTime(const Time& Time)
/* Penjumlahan dua objek jam. Apabila hasil penjumlahan melebihi 23:59:59,
 * maka Anda harus mengonversinya seperti tampilan jam digital asli.
 * 
 * Contoh : 24:00:00 dituliskan 00:00:00, 25:00:00 dituliskan 01:00:00, dst */
{
	int a;
	
	a = (convertToSecond() + Time.convertToSecond()) % 86400;
	
	hour = a / 3600;
	minute = (a % 3600) / 60;
	second = (a % 3600) % 60;
}

void Time::decreaseTime(const Time& Time)
/* Selisih antara dua objek jam. Perhitungan selisih hanya dapat dilakukan
 * jika objek ruas kiri lebih akhir dari atau sama dengan objek ruas kanan.
 * Jika objek ruas kiri lebih awal, maka kembalikan nilai objek ruas kiri.
 * 
 * Contoh: 00:00:00 - 00:00:01 = 00:00:00 */
{
	int a;
	
	a = convertToSecond() - Time.convertToSecond();
	
	if (a < 0)
	{
		a = convertToSecond();
	}
	
	a %= 86400;
	
	hour = a / 3600;
	minute = (a % 3600) / 60;
	second = (a % 3600) % 60;
}

bool Time::earlierThan(const Time& Time)
/* Membandingkan nilai dari objek jam.
 * Method earlierThan akan bernilai true, jika objek jam lebih awal daripada parameter
 * 
 * Contoh:
 * 00:00:00 < 00:00:01 = true; 00:00:00 > 00:00:01 = false */
{
	int a, b;
	bool cek;
	
	a = convertToSecond();
	b = Time.convertToSecond();
	
	if (a < b)
	{
		cek = true;
	}
	else if (a >= b)
	{
		cek = false;
	}
	
	return cek;
}

bool Time::laterThan(const Time& Time)
/* Membandingkan nilai dari objek jam.
 * Method laterThan akan bernilai true, jika objek jam lebih akhir daripada parameter
 * 
 * Contoh:
 * 00:00:00 < 00:00:01 = true; 00:00:00 > 00:00:01 = false */
{
	int a, b;
	bool cek;
	
	a = convertToSecond();
	b = Time.convertToSecond();
	
	if (a > b)
	{
		cek = true;
	}
	else if (a <= b)
	{
		cek = false;
	}
	
	return cek;
}
