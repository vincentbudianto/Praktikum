{Program}
program jumlahderet;

{Kamus}
var
i, x, N : integer;

{Algoritma}
begin
	x := 0;
	readln (N);
	while (N>0) do
		begin
			x := x + N;
			N := N-1;
		end;
	writeln (x);
end.
