{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B01-16517189-170927-01.pas}
{Tanggal    : 27 September 2017}
{Deskripsi  : membuat program yang mengurutkan 3 nilai dari yang terbesar sampai yang terkecil dan disertai nama yang mendapat nilai tersebut}

{Judul}
program urutannilai ;

{Kamus}
var
n1, n2, n3 : integer ; {variabel untuk nilai}
a1, a2, a3 : string ; {variabel nama pemilik nilai}

{Algoritma}
begin

writeln ('Masukan nama 1:') ; readln (a1) ;
writeln ('Masukan nilai 1 :') ; readln (n1) ;
writeln ('Masukan nama 2:') ; readln (a2) ;
writeln ('Masukan nilai 2 :') ; readln (n2) ;
writeln ('Masukan nama 3:') ; readln (a3) ;
writeln ('Masukan nilai 3 :') ; readln (n3) ;

if (n1 > n2) and (n2 > n3) then
begin

writeln (a1, '-', n1) ;
writeln (a2, '-', n2) ;
writeln (a3, '-', n3) ;

end
else if (n1 > n3) and (n3 > n2) then
begin

writeln (a1, '-', n1) ;
writeln (a3, '-', n3) ;
writeln (a2, '-', n2) ;

end

else if (n2 > n1) and (n1 > n3) then
begin

writeln (a2, '-', n2) ;
writeln (a1, '-', n1) ;
writeln (a3, '-', n3) ;

end

else if (n2 > n3) and (n3 > n1) then
begin

writeln (a2, '-', n2) ;
writeln (a3, '-', n3) ;
writeln (a1, '-', n1) ;

end

else if (n3 > n1) and (n1 > n2) then
begin

writeln (a3, '-', n3) ;
writeln (a1, '-', n1) ;
writeln (a2, '-', n2) ;

end

else
begin

writeln (a3, '-', n3) ;
writeln (a2, '-', n2) ;
writeln (a1, '-', n1) ;

end ;

end.
