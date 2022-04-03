{Program}
program JumlahDeret;

{Kamus}
var
	N, sum : integer;

{Algoritma}
begin
	sum := 0;
	readln (N);
	while (N > 0) do
	begin
		if (N mod 2 = 1) then
		begin
			sum := sum + N;
			N := N - 1;
		end
		else
			N := N - 1;
	end;
	writeln (sum);
end.
