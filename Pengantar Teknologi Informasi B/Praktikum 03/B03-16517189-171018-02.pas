{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B03-16517189-171018-02.pas}
{Tanggal    : 18 Oktober 2017}
{Deskripsi  : membuat program yang bisa menentukan jika suatu bilangan adalah bilangan menanjak atau bukan}

{Judul}
program bilangan ;

{Kamus}
var
bil : longint ;

{Procedure}
procedure bilangan (z : longint);

{Kamus Lokal}
var
a, b, c, d, e, f, g, h, i, j, r, s, t ,u, v, w, x, y : longint ;

{Algoritma Procedure}
begin
a := z div 1000000000 ;

y := z mod 1000000000 ;
b := y div 100000000 ;

x := y mod 100000000 ;
c := x div 10000000 ;

w := x mod 10000000 ;
d := w div 1000000 ;

v := x mod 1000000 ;
e := v div 100000 ;

u := x mod 100000 ;
f := u div 10000 ;

t := x mod 10000 ;
g := t div 1000 ;

s := x mod 1000 ;
h := s div 100 ;

r := x mod 100 ;
i := r div 10 ;

j := r mod 10 ;

if (j>i) and (i>h) or (h>g) and (g>f) or (f>e) and (e>d) or (d>c) and (c>b) or (b>a) then
writeln ('Bilangan ', z, ' bukan bilangan menanjak.')
else
writeln ('Bilangan ', z, ' adalah bilangan menanjak.')

end;

{Algoritma}
begin
write ('Masukkan bilangan :'); readln (bil);
bilangan (bil);
end.
