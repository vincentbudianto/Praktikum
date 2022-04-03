module ListOfInteger where

--Definisi dan Spesifikasi
konso :: Int -> [Int] -> [Int]
konsDot :: [Int] -> Int -> [Int]
isEmpty :: [Int] -> Bool
isOneElmt :: [Int] -> Bool
deleteIf :: [Int] -> (Int -> Bool) -> [Int]

--Realisasi
konso e li = [e] ++ li

konsDot li e = li ++ [e]

isEmpty l = null l

isOneElmt l = (length l) == 1

deleteIf l f
 |isEmpty l = []
 |otherwise =
  if ((f(head l)) == False) then
   konso (head l) (deleteIf (tail l) f)
  else
   deleteIf (tail l) f
