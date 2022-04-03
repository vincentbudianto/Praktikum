program AnakAyam ;

var
N : integer ;
a : integer ;

begin
writeln ('Berapa jumlah anak ayam?') ;
readln (N) ;
writeln ('Anak ayam turunlah ', N) ;

for a := 1 to N do
begin
N := N - 1 ;
writeln ('Mati satu tinggallah ', N) ;
end ;

writeln ('Mati satu tinggal induknya') ;

readln ;
end.
