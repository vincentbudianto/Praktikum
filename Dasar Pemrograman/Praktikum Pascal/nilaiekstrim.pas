{Program}
program nilaiekstrim;

{Kamus}
var
	i, N, x : integer;
	tab : array [1..10000] of integer;
	ada, max, min : boolean;
	
{Algoritma}
begin
	ada := false;
	i := 1;
	readln (N);
	for i:=1 to N do
		begin
			readln (tab[i]);
		end;
	readln (x);
	max := true;
	min := true;
	for i:=1 to N do
		begin
			if (x < tab[i]) then
				begin
					max := false;
				end;
			if (x > tab[i]) then
				begin
					min := false;
				end;
			if (x = tab [i]) then
				begin
					ada := true;
				end;
		end;
	if (ada = false) then
		begin
			writeln (x, ' tidak ada');
		end
	else {ada = true}
		begin
			if (max = true) and (min = true) then
				begin
					writeln ('maksimum');
					writeln ('minimum');
				end
			else if (max = true) and (min = false) then
				begin
					writeln ('maksimum');
				end
			else if (max = false) and (min = true) then
				begin
					writeln ('minimum');
				end
			else {(max = false) and (min = false)}
				begin
					writeln ('N#A');
				end;
		end;
end.
