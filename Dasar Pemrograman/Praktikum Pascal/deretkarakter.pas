{Program}
program deretkarakter;

{Kamus}
var
C : char;
i, N : integer;

{Algoritma}
begin
	readln (C);
	readln (N);
	for i:=1 to (N-1) do
		begin	
			write (C);
		end;
	writeln (C);
end.
