-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : Midrange.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : fungsi midrange yang menerima masukan 4 buah integer yang urutannya bisa acak dan mengembalikan nilai rata-rata dari nilai maksimum dan nilai minimum dari keempat bilangan tersebut

module Midrange where

-- Definisi dan Spesifikasi
midrange :: Int -> Int -> Int -> Int -> Float
max4 :: Int -> Int -> Int -> Int -> Int
min4 :: Int -> Int -> Int -> Int -> Int

-- Realisasi
max4 a b c d
	|(a>=b) && (a>=c) && (a>=d) = a
	|(b>a) && (b>=c) && (b>=d) = b
	|(c>a) && (c>b) && (c>=d) = c
	|otherwise = d

min4 a b c d
	|(a<b) && (a<c) && (a<d) = a
	|(b<a) && (b<c) && (b<d) = b
	|(c<a) && (c<b) && (c<d) = c
	|otherwise = d
	
midrange a b c d = fromIntegral ((max4 a b c d)+(min4 a b c d))/2
