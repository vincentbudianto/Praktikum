{Program}
program hargaMakanan;

{Kamus}
var
	i, N, total : integer;
	x : array [1..1000] of integer;
	
{Algoritma}
begin
	i := 1;
	total := 0;
	readln (N);
	for i:=1 to N do
		begin
			readln (x[i]);
		end;
	for i:=1 to N do
		begin
			if (x[i] mod 2 = 1) then
				begin
					total := total + x[i]*100;
				end
			else {x[i] mod 2 = 0}
				begin
					total := total + x[i]*200;
				end
		end;
	writeln (total, ' rupiah');
end.
