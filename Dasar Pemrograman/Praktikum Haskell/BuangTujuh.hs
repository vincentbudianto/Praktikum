--NIM/Nama  : 16515189 / Vincent Budianto
--Nama file : BuangTujuh.hs
--Topik     : List
--Tanggal   : 28 Feb 2018
--Deskripsi :

module BuangTujuh where

--Definisi dan Spesifikasi
buangTujuh :: [Int] -> [Int]
lib :: Int -> [Int] -> [Int]
konso :: Int -> [Int] -> [Int]
konsDot :: [Int] -> Int -> [Int]
isOneElmt :: [Int] -> Bool

--Realisasi
konso e l = [e] ++ l

konsDot l e = l ++ [e]

isOneElmt l = (length l) == 1 

buangTujuh l =
	let n = (length l) in
		(lib n l)
		
lib n l
	|isOneElmt l = []
	|otherwise =
		if mod n 7 /= 0 then
			konso (head l) (lib (n-1) (tail l))
		else
		lib (n-1) (tail l)
