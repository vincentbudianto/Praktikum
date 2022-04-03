program calculatorSS ;
{membuat kalkulator dengan beberapa fungsi yang dapat menghitung 2 bilangan secara aritmatik}

{Kamus}
var
pilihan : char ;
A, B : integer ;

{Algoritma}
begin
writeln ('Masukan bilangan pertama (A)') ;
readln (A) ;
writeln ('Masukan bilangan kedua (B)') ;
readln (B) ;
Writeln ('Masukan fungsi yang diinginkan') ;
readln (pilihan) ;

case pilihan of
'a' :
writeln ('A + B = ', A + B : 0) ;
'b' :
writeln ('A - B = ', A - B : 0) ;
'c' :
writeln ('A * B = ', A * B : 0) ;
'd' :
writeln ('A / B = ', A / B : 0) ;
'e' :
writeln ('A div B = ', A div B : 0) ;
'f' :
writeln ('A mod B = ', A mod B : 0)
else
writeln ('Bukan pilihan menu yang benar') ;
end;

readln ;

end.
