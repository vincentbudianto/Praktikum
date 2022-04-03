module ListOfString where
-- DEFINISI DAN SPESIFIKASI LIST
{- type List of String: [ ] atau [e o List] atau [List o e]  
   Definisi type List of String
   Basis: List of String kosong adalah list of String
   Rekurens:
   List tidak kosong dibuat dengan menambahkan sebuah elemen bertype String di awal
   sebuah list atau
   dibuat dengan menambahkan sebuah elemen bertype String di akhir sebuah list -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: String -> [String] -> [String]
{- konso e li menghasilkan sebuah list of string dari e (sebuah string) dan li
   (list of string), dengan e sebagai elemen pertama: e o li -> li' -}
-- REALISASI
konso e li = [e] ++ li

konsDot :: [String] -> String -> [String]
{- konsDot li e menghasilkan sebuah list of string dari li (list of string) dan
   e (sebuah string), dengan e sebagai elemen terakhir: li o e -> li' -}
-- REALISASI
konsDot li e = li ++ [e]

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [String] -> String
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [String] -> [String]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- last :: [String] -> String
-- last l menghasilkan elemen terakhir list l, l tidak kosong

-- init :: [String] -> [String]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [String] -> Bool
-- isEmpty l  true jika list of string l kosong
-- REALISASI
isEmpty l = null l

isOneElmt :: [String] -> Bool
-- isOneElmt l true jika list of string l hanya mempunyai satu elemen
-- REALISASI
isOneElmt l = (length l) == 1
