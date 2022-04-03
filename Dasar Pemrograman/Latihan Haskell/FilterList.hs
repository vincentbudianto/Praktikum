module ListOfInteger where

--Definisi dan Spesifikasi
konso :: Int -> [Int] -> [Int]
konsDot :: [Int] -> Int -> [Int]
isEmpty :: [Int] -> Bool
isOneElmt :: [Int] -> Bool
filterList :: [Int] -> (Int -> Bool) -> [Int]

--Realisasi
konso e li = [e] ++ li

konsDot li e = li ++ [e]

isEmpty l = null l

isOneElmt l = (length l) == 1

filterList l f
 |isEmpty l = []
 |otherwise =
  if ((f(head l)) == True) then
   konso (head l) (filterList (tail l) f)
  else
   filterList (tail l) f
