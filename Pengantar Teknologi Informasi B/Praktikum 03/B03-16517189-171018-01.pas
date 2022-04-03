{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B03-16517189-171018-01.pas}
{Tanggal    : 18 Oktober 2017}
{Deskripsi  : membuat program yang dapat menghitung hasil pangkat}

{Judul}
program pangkat ;

{Kamus}
var
x , y : integer ;

{Procedure}
procedure pangkat (a : integer ; b : integer);

{Kamus Lokal}
var
i , hasil : integer ;

{Algoritma Procedure}
begin
i := 2 ;
hasil := a ;

while (i <= B) do
begin
hasil := hasil * a ;
i := i + 1 ;
end;

writeln ( x, '^', y, ' = ', hasil );
end;

{Algoritma}
begin
write ('Masukan A : '); readln (x);
write ('Masukan B : '); readln (y);
pangkat (x,y);
end.
