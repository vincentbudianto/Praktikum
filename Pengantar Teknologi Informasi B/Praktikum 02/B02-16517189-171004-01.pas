{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B02-16517189-171004-01.pas}
{Tanggal    : 4 Oktober 2017}
{Deskripsi  : Membuat program yang dapat mengetahui suatu angka (X) merupakan angka biner atau bukan biner}

{Judul}
program angkabiner ;

{Kamus}
var
X : longint ;
i : integer ;

{Algoritma}
begin

writeln ('Masukan nilai X : '); readln (X);

i := 0 ;

repeat
i := i + 1;
until i = 10 ;

if (X mod i = 1) or (X mod i = 0) then
writeln (X, ' merupakan angka biner')
else {X mod 10 <> 1 or X mod 10 <> 0}
writeln (X, ' bukan angka biner');

end.
