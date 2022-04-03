{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B01-16517189-170927-03.pas}
{Tanggal    : 27 September 2017}
{Deskripsi  : membuat program yang dapat memberikan kemungkinan operator yang dipakai}

{Judul}
program catatanvin ;

{Kamus}
var
a, b, c, d : integer ;

{Algoritma}
begin

writeln ('Masukan A :') ; readln (a) ;
writeln ('Masukan B :') ; readln (b) ;
writeln ('Masukan C :') ; readln (c) ;
writeln ('Masukan D :') ; readln (d) ;

if (d = a * b * c) then
writeln ('Operator yang mungkin :', a, '*', b, '*', c, '=', d)
else if (d = a * b div c) then
writeln ('Operator yang mungkin :', a, '*', b, 'div', c, '=', d)
else if (d = a * b + c) then
writeln ('Operator yang mungkin :', a, '*', b, '+', c, '=', d)
else if (d = a * b - c) then
writeln ('Operator yang mungkin :', a, '*', b, '-', c, '=', d)
else if (d = a div b * c) then
writeln ('Operator yang mungkin :', a, 'div', b, '*', c, '=', d)
else if (d = a div b div c) then
writeln ('Operator yang mungkin :', a, 'div', b, 'div', c, '=', d)
else if (d = a div b + c) then
writeln ('Operator yang mungkin :', a, 'div', b, '+', c, '=', d)
else if (d = a div b - c) then
writeln ('Operator yang mungkin :', a, 'div', b, '-', c, '=', d)
else if (d = a + b * c) then
writeln ('Operator yang mungkin :', a, '+', b, '*', c, '=', d)
else if (d = a + b div c) then
writeln ('Operator yang mungkin :', a, '+', b, 'div', c, '=', d)
else if (d = a + b + c) then
writeln ('Operator yang mungkin :', a, '+', b, '+', c, '=', d)
else if (d = a + b - c) then
writeln ('Operator yang mungkin :', a, '+', b, '-', c, '=', d)
else if (d = a - b * c) then
writeln ('Operator yang mungkin :', a, '-', b, '*', c, '=', d)
else if (d = a - b div c) then
writeln ('Operator yang mungkin :', a, '-', b, 'div', c, '=', d)
else if (d = a - b + c) then
writeln ('Operator yang mungkin :', a, '-', b, '+', c, '=', d)
else if (d = a - b - c) then
writeln ('Operator yang mungkin :', a, '-', b, '-', c, '=', d)
else
writeln ('Tidak ada operator yang cocok') ;

end.
