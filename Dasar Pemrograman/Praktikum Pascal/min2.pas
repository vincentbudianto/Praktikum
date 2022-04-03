{Program}
program min2;

{Kamus}
var
a,b : longint;

{Algoritma}
begin
	readln (a);
	readln (b);
	if (a <= b) then
		writeln (a)
	else
		writeln (b);
end.
