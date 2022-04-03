-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : HitungBensin.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : Fungsi hitungBensin menerima 2 buah bilangan bulat, A dan B (A <= B). Fungsi ini kemudian mengeluarkan sebuah bilangan bulat yang menunjukan konsumsi bensin dari tiap-tiap kendaraan dari A sampai B

module HitungBensin where

-- Definisi dan Spesifikasi
hitungBensin :: Int -> Int -> Int
hB :: Int -> Int

-- Realisasi
hB c
	|c == 1 = 0
	|mod c 2 == 0 = div c 2
	|otherwise = 3*c +1

hitungBensin a b
	|a<b = hB a + (hitungBensin (a+1) b)
	|otherwise = hB a
