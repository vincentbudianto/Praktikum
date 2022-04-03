-- NIM/Nama  : 16515189 / Vincent Budianto
-- Nama file : JamBangun.hs
-- Topik     : Responsi 2
-- Tanggal   : 21 Feb 2018
-- Deskripsi : fungsi jamBangun menghitung selisih jam bangun dengan waktu yang ditentukan

module JamBangun where

-- Definisi dan Spesifikasi
jamBangun :: Int -> Int -> Int -> (Bool,Int,Int,Int)
cdetik :: Int -> Int -> Int -> Int

-- Realisasi
cdetik h m s = h*3600 + m*60 + s

jamBangun h m s
	|(cdetik h m s) > 27900 = (False, (div ((cdetik h m s)-27900) 3600), (div (mod ((cdetik h m s)-27900) 3600) 60), (mod (mod (mod ((cdetik h m s)-27900) 3600) 60) 60))
	|(cdetik h m s) <= 27900  = (True, (div (27900-(cdetik h m s)) 3600), (div (mod (27900-(cdetik h m s)) 3600) 60), (mod (mod (mod (27900-(cdetik h m s)) 3600) 60) 60))
