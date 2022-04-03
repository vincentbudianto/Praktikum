{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B02-16517189-171004-03.pas}
{Tanggal    : 4 Oktober 2017}
{Deskripsi  : Membuat program yang dapat menentukan suatu bilangan integer (0-99) adalah prima super atau bukan}

{Judul}
program primasuper ;

{Kamus}
var
A, B, tukar : integer ;

{Algoritma}
begin

writeln ('Masukan nilai A : '); readln (A);
writeln ('Masukan nilai B : '); readln (B);

writeln ('Prima super dari ', A, ' – ', B, ' : ');

while (A <= B) do
begin

A := A+1 ;

if (A mod 2 <> 0) and (A mod 3 <> 0) and (A mod 5 <> 0) and (A mod 7 <> 0) then
begin

tukar := (A*10) - (100*(A div 10) - (A div 10));

if (tukar mod 2 <> 0) and (tukar mod 3 <> 0) and (tukar mod 5 <> 0) and (tukar mod 7 <> 0) then
writeln (A);

end;

end;

end.
