{Program}
program caricharacter;

{Kamus}
const
	Nmax = 1000;

var
	N, i, j : integer;
	C : array [1..Nmax] of char;
	CC : char;
	b, k : boolean;

{Algoritma}
begin
	b := false;
	while (b = false) do
		begin
			readln (N);
			if (N <= 100) and (N >= 0) then
				begin
					b := true;
				end
			else
				begin
					writeln ('Masukan salah. Ulangi!');
					readln (N);
				end;
		end;
	if (b = true) then
		begin
			for i:=1 to N do
				begin
				readln (C[i]);
				end;
			readln (CC);
			
			case CC of
				'S'       : begin
								 j := 1;
								 k := false;
								 while (j <= N) and (k = false) do
									begin
										 if (byte(C[j]) >= 97) and (byte(C[j]) <= 122) then
											 begin
												 k := true;
											 end
										 else
											 begin
												 j := j + 1;
											 end;
									end;
								 if (k = true) then
									 begin
										 writeln (j, ' ', C[j]);
									 end
								 else
									 begin
										 writeln ('Tidak ada huruf kecil');
									 end;
							 end;
				's'       : begin
								 j := 1;
								 k := false;
								 while (j <= N) and (k = false) do
									begin
										 if (byte(C[j]) >= 97) and (byte(C[j]) <= 122) then
											 begin
												 k := true;
											 end
										 else
											 begin
												 j := j + 1;
											 end;
									end;
								 if (k = true) then
									 begin
										 writeln (j, ' ', C[j]);
									 end
								 else
									 begin
										 writeln ('Tidak ada huruf kecil');
									 end;
							 end;
				'L'        : begin
								 j := 1;
								 k := false;
								 while (j <= N) and (k = false) do
									begin
										 if (byte(C[j]) >= 65) and (byte(C[j]) <= 90) then
											 begin
												 k := true;
											 end
										 else
											 begin
												 j := j + 1;
											 end;
									end;
								 if (k = true) then
									 begin
										 writeln (j, ' ', C[j]);
									 end
								 else
									 begin
										 writeln ('Tidak ada huruf besar');
									 end;
							 end;
				'l'        : begin
								 j := 1;
								 k := false;
								 while (j <= N) and (k = false) do
									begin
										 if (byte(C[j]) >= 65) and (byte(C[j]) <= 90) then
											 begin
												 k := true;
											 end
										 else
											 begin
												 j := j + 1;
											 end;
									end;
								 if (k = true) then
									 begin
										 writeln (j, ' ', C[j]);
									 end
								 else
									 begin
										 writeln ('Tidak ada huruf besar');
									 end;
							 end;
				'X'        : begin
								 j := 1;
								 k := false;
								 while (j <= N) and (k = false) do
									begin
										 if (byte(C[j]) < 97) and (byte(C[j]) > 122) and (byte(C[j]) < 65) and (byte(C[j]) > 90) then
											 begin
												 k := true;
											 end
										 else
											 begin
												 j := j + 1;
											 end;
									end;
								 if (k = true) then
									 begin
										 writeln (j, ' ', C[j]);
									 end
								 else
									 begin
										 writeln ('Semua huruf');
									 end;
							 end;
				'x'        : begin
								 j := 1;
								 k := false;
								 while (j <= N) and (k = false) do
									begin
										 if (byte(C[j]) < 97) and (byte(C[j]) > 122) and (byte(C[j]) < 65) and (byte(C[j]) > 90) then
											 begin
												 k := true;
											 end
										 else
											 begin
												 j := j + 1;
											 end;
									end;
								 if (k = true) then
									 begin
										 writeln (j, ' ', C[j]);
									 end
								 else
									 begin
										 writeln ('Semua huruf');
									 end;
							 end;
				else
					begin
						writeln ('Tidak diproses');
					end;
		end;
	end;
end.
