program urutan ;
{mengurutkan angka dari yang terbesar sampai yang terkecil}

{Kamus}
var
A, B, C : integer ;

{Algoritma}
begin
writeln ('masukan nilai A') ;
readln (A) ;
writeln ('masukan nilai B') ;
readln (B) ;
writeln ('masukan nilai C') ;
readln (C) ;

if ( (A > B) and (B > C) ) then
writeln ( A, ' ', B, ' ', C )
else if ( (A > B) and (C > B) ) then
writeln ( A, ' ', C, ' ', B )
else if ( (B > A) and (A > C) ) then
writeln ( B, ' ', A, ' ', C )
else if ( (B > C) and (C > A) ) then
writeln ( B, ' ', C, ' ', A )
else if ( (C > A) and (A > B) ) then
writeln ( C, ' ', A, ' ', B )
else
writeln ( C, ' ', B, ' ', A ) ;

readln ;

end.
