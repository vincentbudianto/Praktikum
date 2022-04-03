{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B03-16517189-171018-03.pas}
{Tanggal    : 18 Oktober 2017}
{Deskripsi  : membuat program yang dapat menentukan urutan kartu setelah dikocok dengan asumsi jumlah kartu yang dikocok adalah 4 kartu}

{Judul}
program kartu ;

{Kamus}
var
x , n : integer ;

{Procedure}
procedure urutan (z : integer ; y : integer);

{Kamus Lokal}
var
a, b, c, d : integer ;
tukar, i : integer ;

{Algoritma Procedure}
begin
a := z div 1000 ;
b := (z mod 1000) div 100 ;
c := ((z mod 1000) mod 100) div 10 ;
d := ((z mod 1000) mod 100) mod 10 ;

for i:= 1 to y do
begin
tukar := a ;
a := b ;
b := c ;
c := d ;
d := tukar ;
end;

writeln (a,b,c,d) ;
end;

{Algoritma}
begin
write ('Masukan urutan awal :'); readln (x);
write ('Masukan nilai N :'); readln (n);
urutan (x,n) ;
end.
