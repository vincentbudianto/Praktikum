-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : ListOfInteger.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : fungsi nbElmt yang menerima masukan sebuah list of integer (mungkin kosong) dan menghasilkan banyaknya elemen dalam list (0 jika list kosong) secara rekursif

module ListOfInteger where

-- Definisi dan Spesifikasi
nbElmt :: [Int] -> Int

-- Realisasi
nbElmt a = length a
