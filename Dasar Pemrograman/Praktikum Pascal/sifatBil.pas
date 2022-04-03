{Program}
program sifatBil;

{Kamus}
var
x : integer;

{Algoritma}
begin
	readln (x);
	if (x = 0) then
		writeln ('NOL')
	else if (x < 0) then
		writeln ('NEGATIF')
	else {x > 0}
		begin
			if (x mod 2 = 0) then
			begin
				writeln ('POSITIF');
				writeln ('GENAP');
			end
			else if (x mod 2 = 1) then
			begin
				writeln ('POSITIF');
				writeln ('GANJIL');
			end;
		end;		
end.
