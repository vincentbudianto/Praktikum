{Program}
program KincirAngin;

{Kamus}
var
	n : integer;
	c : char;
	k : boolean;
	
{Algoritma}
begin
	k := false;
	readln (n);
	while (k <> true) do
		begin
			if (n >= 1) and (n <= 23) then
				begin
					k := true;
					readln (c);
				end
			else
				begin
					writeln ('Masukan Salah.');
					readln (n);
				end;
		end;
	writeln ('Mahasiswa menggambar kincir angin berukuran ', n , ' dengan karakter ', c);
end.
