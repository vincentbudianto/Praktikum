--NIM/Nama  : 16515189 / Vincent Budianto
--Nama file : MeanDistribution.hs
--Topik     : List
--Tanggal   : 28 Feb 2018
--Deskripsi :

module MeanDistribution where

--Definisi dan Spesifikasi
meanDistribution :: [Int] -> ([Int],[Int])
meanDistribution1 :: [Int] -> [Int]
meanDistribution2 :: [Int] -> [Int]
mean1 :: [Int] -> Int
mean2 :: [Int] -> Int
konso :: Int -> [Int] -> [Int]
konsDot :: [Int] -> Int -> [Int]
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong
-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong
-- last :: [Int] -> Int
-- last l menghasilkan elemen terakhir list l, l tidak kosong
-- init :: [Int] -> [Int]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong
isEmpty :: [Int] -> Bool
isOneElmt :: [Int] -> Bool

--Realisasi
konso e l = [e] ++ l

konsDot l e = l ++ [e]

isEmpty l = null l

isOneElmt l = (length l) == 1 

mean1 l
	|isOneElmt l = head l
	|otherwise = (head l) + mean1 (tail l)
	
mean2 l = mod (mean1 l) (length l)

meanDistribution1 l
	|isEmpty l = []
	|otherwise =
		if (head l) < (mean2 l) then
			konso (head l) (meanDistribution1 (tail l))
		else
			meanDistribution1 (tail l)

meanDistribution2 l
	|isEmpty l = []
	|otherwise =
		if (head l) >= (mean2 l) then
			konso (head l) (meanDistribution2 (tail l))
		else
			meanDistribution2 (tail l)

meanDistribution l = (meanDistribution1 l, meanDistribution2 l)
