/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : main.cpp
 * Topik     : Praktikum 2
 * Tanggal   : 31 Januari 2019
 * Deskripsi : Driver Paper.cpp */

#include "Paper.hpp"

int main()
{
    Paper a('A');
    Paper b('B');
    Paper c('C');
    Paper x(c);
    a.fold();
    b.fold();
    c.fold();
    c.glue();
    c.setName('X');
    x.fold();
    x.glue();
    return 0;
}
