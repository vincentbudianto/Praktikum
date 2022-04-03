/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Time.hpp
 * Topik     : Praktikum 2
 * Tanggal   : 31 Januari 2019
 * Deskripsi : Header Time.cpp */

#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
using namespace std;

class Time {
    public:
        //ctor tanpa parameter
        Time();

        //ctor dengan parameter
        Time(int, int, int);

        //cctor
        Time(const Time&);

        //dtor
        ~Time();

        //Setter & Getter
        void setHour(int);
        void setMinute(int);
        void setSecond(int);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;

        //Static function
        static int countTimeInstance();
        /* Mengembalikan jumlah instance time yang sudah pernah dibuat */

        //Konversi ke detik
        int convertToSecond() const;

        //Menuliskan waktu ke layar (format: hh:mm:ss)
        void printTime();
        /* Menuliskan jam dalam format hh:mm:ss diakhiri dengan newline. Perhatikan bahwa setiap parameter harus dituliskan 2 digit. */

        //Time Operation
        void addTime(const Time&);
		/* Penjumlahan dua objek jam. Apabila hasil penjumlahan melebihi 23:59:59,
		 * maka Anda harus mengonversinya seperti tampilan jam digital asli.
		 * 
		 * Contoh : 24:00:00 dituliskan 00:00:00, 25:00:00 dituliskan 01:00:00, dst */
        void decreaseTime(const Time&);
		/* Selisih antara dua objek jam. Perhitungan selisih hanya dapat dilakukan
		 * jika objek ruas kiri lebih akhir dari atau sama dengan objek ruas kanan.
		 * Jika objek ruas kiri lebih awal, maka kembalikan nilai objek ruas kiri.
		 * 
		 * Contoh: 00:00:00 - 00:00:01 = 00:00:00 */
        bool earlierThan(const Time&);
		/* Membandingkan nilai dari objek jam.
		 * Method earlierThan akan bernilai true, jika objek jam lebih awal daripada parameter
		 * 
		 * Contoh:
		 * 00:00:00 < 00:00:01 = true; 00:00:00 > 00:00:01 = false */
        bool laterThan(const Time&);
		/* Membandingkan nilai dari objek jam.
		 * Method laterThan akan bernilai true, jika objek jam lebih akhir daripada parameter
		 * 
		 * Contoh:
		 * 00:00:00 < 00:00:01 = true; 00:00:00 > 00:00:01 = false */

    private:
        static int n_time;
        int hour;
        int minute;
        int second;
};

#endif //TIME_HPP
