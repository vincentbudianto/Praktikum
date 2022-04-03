--NIM/Nama  : 16515189 / Vincent Budianto
--Nama file : ListofCharacter.hs
--Topik     : List
--Tanggal   : 28 Feb 2018
--Deskripsi :

module ListOfCharacter where

--Definisi dan Spesifikasi
pajakMakan :: [Char] -> [Int] -> [Char]
konso :: Char -> [Char] -> [Char]
konsDot :: [Char] -> Char -> [Char]
-- head :: [Char] -> Char
-- head l menghasilkan elemen pertama list l, l tidak kosong
-- tail :: [Char] -> [Char]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong
-- last :: [Char] -> Char
-- last l menghasilkan elemen terakhir list l, l tidak kosong
-- init :: [Char] -> [Char]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong
isEmpty :: [Char] -> Bool
isOneElmt :: [Char] -> Bool

--Realisasi
konso e li = [e] ++ li

konsDot li e = li ++ [e]

isEmpty l = null l

isOneElmt l = (length l) == 1 

pajakMakan x y
	|isEmpty x = ""
	|otherwise =
		if ((head y)+ div (head y) 10) <= 200 then
			konso (head x) (pajakMakan (tail x) (tail y))
		else
			pajakMakan (tail x) (tail y)
