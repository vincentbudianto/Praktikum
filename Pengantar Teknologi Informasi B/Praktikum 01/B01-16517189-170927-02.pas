{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B01-16517189-170927-02.pas}
{Tanggal    : 27 September 2017}
{Deskripsi  : membuat program untuk menentukan kualifikasi orang tersebut dengan jawaban ya atau ada untuk menerima bantuan dana dari Tuan Vin}

{Judul}
program bantuandana ;

{Kamus}
var
usia : real ;
syarat : string ;

{Algoritma}
begin

writeln ('Usia :') ; readln (usia) ;

if (usia <= 30) then
begin

writeln ('Pelajar :') ; readln (syarat) ;

if (syarat = 'ya') then
writeln ('Selamat! Anda mendapatkan limpahan rezeki Tuan Vin')
else
writeln ('Sayang sekali anda kurang  beruntung') ;

end
else if (usia > 50) then
begin

writeln ('Ada dana pensiunan :') ; readln (syarat) ;

if (syarat = 'ada') then
writeln ('Selamat! Anda mendapatkan limpahan rezeki Tuan Vin')
else
writeln ('Sayang sekali anda kurang  beruntung') ;

end
else
writeln ('Sayang sekali anda kurang  beruntung') ;

end.
