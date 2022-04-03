-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : HitungIndeks.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : fungsi hitungIndeks yang menerima 3 input bertipe float yaitu (berturut-turut) nilaiUTS, nilaiUAS, dan nilaiTubes dan mengeluarkan mengeluarkan indeks mahasiswa (dinotasikan dengan bilangan bulat)

module HitungIndeks where

-- Definisi dan Spesifikasi
hitungIndeks :: Float -> Float -> Float -> Int

-- Realisasi
hitungIndeks a b c
	|(a==0) || (b==0) || (c==0) = 0
	|(a<40) || (b<40) = 1
	|(c<40) = 2
	|(a<75) && (b<75) && (c<75) && (a>=40) && (b>=40) && (c>=40) = 2
	|(a>=75) || (b>=75) || (c>=75) = 3
	|(a>=75) && (b>=75) && (c>=75) = 4
