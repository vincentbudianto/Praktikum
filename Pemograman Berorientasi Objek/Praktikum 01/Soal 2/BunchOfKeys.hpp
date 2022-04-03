/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : BunchOfKeys.hpp
 * Topik     : Praktikum 1
 * Tanggal   : 24 Januari 2019
 * Deskripsi : Header BunchOfKeys.cpp */

#ifndef __BUNCH_OF_KEYS_HPP__
#define __BUNCH_OF_KEYS_HPP__

#include <iostream>
using namespace std;

class BunchOfKeys
{
  public:
    // ctor
    BunchOfKeys();
    
    // member function
    void add();
    void shake();
    
  private:
    int n_keys; // jumlah kunci yg ada
};

#endif 
