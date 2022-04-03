-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : LuasLayang.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : fungsi layang yang menerima masukan 2 nilai integer, yaitu kedua diagonal sebuah layang-layang

module LuasLayang where

-- Definisi dan Spesifikasi
layang :: Int -> Int -> Float

-- Realisasi
layang a b = fromIntegral (a*b)/2
