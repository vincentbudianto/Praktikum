module ListOfInteger where

--Definisi dan Spesifikasi
konso :: Int -> [Int] -> [Int]
konsDot :: [Int] -> Int -> [Int]
isEmpty :: [Int] -> Bool
isOneElmt :: [Int] -> Bool
offsetList :: [Int] -> (Int -> Int) -> [Int]

--Realisasi
konso e li = [e] ++ li

konsDot li e = li ++ [e]

isEmpty l = null l

isOneElmt l = (length l) == 1

offsetList l f
 |isEmpty l = []
 |otherwise = konso (f(head l)) (offsetList (tail l) f)
