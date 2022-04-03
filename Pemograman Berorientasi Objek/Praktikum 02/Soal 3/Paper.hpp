/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : Paper.cpp
 * Topik     : Praktikum 2
 * Tanggal   : 31 Januari 2019
 * Deskripsi : Header Paper.cpp */

#ifndef FOO_HPP
#define FOO_HPP

#include <iostream>

class Paper {
    public:
        Paper(char c);
        Paper(const Paper&);
        ~Paper();
        
        void fold();
        void glue();
        void setName(char c);
        
    private:
        char name;
        int n_fold;
};

#endif
