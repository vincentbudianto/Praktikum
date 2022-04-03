--NIM/Nama  : 16515189 / Vincent Budianto
--Nama file : InfoNilaiMaks.hs
--Topik     : List
--Tanggal   : 28 Feb 2018
--Deskripsi :

module InfoNilaiMaks where

--Definisi dan Spesifikasi
infoNilaiMaks :: [Int] -> (Int,Int)
max1 :: Int -> Int -> Int
max2 :: [Int] -> Int
lulus :: [Int] -> Int
isOneElmt :: [Int] -> Bool

--Realisasi
isOneElmt l = (length l) == 1 

max1 a b = if a >= b then a
			else b

max2 l = if (isOneElmt l) then head l
		else max1 (head l) (max2 (tail l))

lulus l = if (isOneElmt l) then 1
			else
				let a = 0 in
					if ((head l) >= 75) then (a+1)
					else a

infoNilaiMaks l = (lulus l , max2 l)
