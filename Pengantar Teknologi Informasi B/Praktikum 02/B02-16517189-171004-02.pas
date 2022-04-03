{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B02-16517189-171004-02.pas}
{Tanggal    : 4 Oktober 2017}
{Deskripsi  : Membuat program yang dapat menentukan permen yang harus dibawa Tuan Vin agar habis saat dibagikan ke mahasiswanya}

{Judul}
program bagipermen ;

{Kamus}
var
X, Y, p : integer ;


{Algoritma}
begin

writeln ('Masukan nilai X : '); readln (X);
writeln ('Masukan nilai Y : '); readln (Y);

p := 1 ;

while (p mod X <> 0) or (p mod Y <> 0) do
p := p + 1 ;

writeln ('Tuan Vin harus membawa ', p, ' buah permen');

end.
