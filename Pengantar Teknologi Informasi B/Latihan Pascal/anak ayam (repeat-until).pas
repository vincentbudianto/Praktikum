program anakayam ;

var
N : integer ;

begin
writeln ('Berapa jumlah anak ayam?') ;
readln (N) ;
writeln ('Anak ayam turunlah ', N) ;

repeat
N := N - 1 ;
writeln ('Mati satu tinggallah ', N) ;
until (N = 1) ;

writeln ('Mati satu tinggal induknya') ;

readln ;
end.
