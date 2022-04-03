{Program}
program konversisuhu;

{Kamus}
var
t, o : real;
k : char;

{Algoritma}
begin
	readln (t);
	readln (k);
	case k of
		'R' : o := 4/5 * t;
		'F' : o := (9/5 * t) + 32;
		'K' : o := t + 273.15;
	end;
	writeln (o:0:2);
end.
