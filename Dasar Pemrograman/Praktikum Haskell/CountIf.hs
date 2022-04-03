module ListOfInteger where

--Definisi dan Spesifikasi
konso :: Int -> [Int] -> [Int]
konsDot :: [Int] -> Int -> [Int]
isEmpty :: [Int] -> Bool
isOneElmt :: [Int] -> Bool
countIf :: [Int] -> (Int -> Bool) -> Int

--Realisasi
konso e li = [e] ++ li

konsDot li e = li ++ [e]

isEmpty l = null l

isOneElmt l = (length l) == 1

countIf l f
 |isEmpty l = 0
 |otherwise =
  if ((f(head l)) == True) then
   countIf (tail l) f + 1
  else
   countIf (tail l) f
