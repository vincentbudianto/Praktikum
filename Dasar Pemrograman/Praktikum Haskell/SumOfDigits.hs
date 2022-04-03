-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : SumOfDigits.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : fungsi sumOfDigits menghasilkan jumlah dari setiap digit yang ada pada nilai integer yang dimasukan

module SumOfDigits where

-- Definisi dan Spesifikasi
sumOfDigits :: Int -> Int

-- Realisasi
sumOfDigits a
	|(a>=0) && (a<=9) = a
	|otherwise = sumOfDigits (div a 10) + (mod a 10)
