{Program}
program sumOfDigits;

{Kamus}
var
	i, N : integer;
	x : array [1..1000] of integer;
	
{Algoritma}
begin
	i := 1;
	N := 0;
	repeat
		readln (x[i]);
		while (x[i] > 0) do
			begin
				N := N + x[i] mod 10;
				x[i] := x[i] div 10;
			end;
	until (x[i] = - 999);
	writeln (N);
	readln ;
end.
