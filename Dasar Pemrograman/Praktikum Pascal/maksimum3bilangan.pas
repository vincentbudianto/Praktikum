{Program}
program maksimum3bilangan;

{Kamus}
var
a,b,c : longint;

{Algoritma}
begin
	readln (a);
	readln (b);
	readln (c);
	if ((a >= b) and (a >= c)) then
		writeln (a)
	else if ((b > a) and (b >= c)) then
		writeln (b)
	else {(c > a) and (c > b)}
		writeln (c);
end.
