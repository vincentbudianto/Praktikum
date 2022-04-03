--NIM/Nama  : 16515189 / Vincent Budianto
--Nama file : CountEven.hs
--Topik     : List
--Tanggal   : 28 Feb 2018
--Deskripsi :

module CountEven where

--Definisi dan Spesifikasi
countEven :: [Int] -> Int
cen :: [Int] -> [Int]
isEmpty :: [Int] -> Bool
konsDot :: [Int] -> Int -> [Int]

--Realisasi
isEmpty l = null l

konsDot l e = l ++ [e]

cen l
	|isEmpty l = []
	|otherwise =
		if mod (last l) 2 == 0 then
			konsDot (cen (init l)) (last l)
		else
			cen (init l)

countEven l = length (cen l)
