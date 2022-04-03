{Program}
program ThemePark;

{Kamus}
var
	t, b, k : integer;

{Algoritma}
begin
	readln (t);
	readln (b);
	readln (k);
	case k of
		0 : writeln ('FALSE');
		1 : begin
				if (t <= 100) and (b <= 150) then
					writeln ('TRUE')
				else
					writeln ('FALSE')
			end;
		2 : begin
				if (t <= 200) and (b > 30) then
					writeln ('TRUE')
				else
					writeln ('FALSE')
			end;
		3 : begin
				if (t > 100) and (b <= 200) and (b > 150) then
					writeln ('TRUE')
				else
					writeln ('FALSE')
			end;
		4 : begin
				if (t > 100) and (b <= 150) then
					writeln ('TRUE')
				else
					writeln ('FALSE')
			end;
	end;
end.
