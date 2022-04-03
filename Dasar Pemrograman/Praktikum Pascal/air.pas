{Program}
program air;

{Kamus}
var
T : integer;

{Algoritma}
begin
	readln (T);
	if (T < 0) then
		writeln ('PADAT')
	else if (T = 0) then
		writeln ('ANTARA PADAT-CAIR')
	else if ((T > 0) and (T < 100)) then
		writeln ('CAIR')
	else if (T = 100) then
	writeln ('ANTARA CAIR-GAS')
	else {T > 100}
	writeln ('GAS');	
end.
