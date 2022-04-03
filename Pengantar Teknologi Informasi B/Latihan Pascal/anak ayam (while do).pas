program anakayam ;

var
N : integer ;
a : integer ;

begin
writeln ('Berapa jumlah anak ayam?') ;
readln (N) ;
writeln ('Anak ayam turunlah ', N) ;
a := 1 ;

while ( a <= N ) do
begin
N := N - 1 ;
writeln ('Mati satu tinggallah ', N) ;
end ;

writeln ('Mati satu tinggal induknya') ;

readln ;
end.