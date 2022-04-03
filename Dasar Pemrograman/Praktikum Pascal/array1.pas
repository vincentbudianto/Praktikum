{Program}
program Array1;

{Kamus}
var
	N, i, K, count : integer;
	x : array [1..100] of integer;

{Algoritma}
begin
	count := 0;
	readln (N);
	if (N = 0) then
		writeln ('Tidak ada bilangan')
	else
		begin
			for i:=1 to N do
			begin
				readln (x[i]);
			end;
		readln (k);
		case k of
			1  : begin
					for i:=1 to N do
					begin
						if (x[i] > 0) then
							count := count + 1;
					end;
					writeln (count);
					for i:=1 to N do
					begin	
						if (x[i] > 0) then
							writeln (x[i]);
					end;
				 end;			
			0  : begin
					for i:=1 to N do
					begin
						if (x[i] = 0) then
							count := count + 1;
					end;
					writeln (count);
				 end;
			-1 : begin
					for i:=1 to N do
					begin
						if (x[i] < 0) then
							count := count + 1;
					end;
					writeln (count);
					for i:=1 to N do
					begin	
						if (x[i] < 0) then
							writeln (x[i]);
					end;
				 end;
		end;
		end;
end.
