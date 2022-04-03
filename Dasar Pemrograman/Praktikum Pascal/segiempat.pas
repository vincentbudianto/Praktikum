{Program}
program SegiEmpat;

{Kamus}
var
	N, a : integer;
	C1, C2 : char;

{Procedure}
procedure ulangfl (x : integer; var y : char);

{Kamus Lokal}
var
	i : integer;
	
{Algoritma Procedure}
begin
	for i:=1 to x do
	begin
		write (y);
	end;
	writeln ;
end;

{Procedure}
procedure ulangisi (x : integer; var y : char; var z : char);

{Kamus Lokal}
var
	i : integer;
	
{Algoritma Procedure}
begin
	write (y);
	for i:=3 to x do
	begin
		write (z);
	end;
	writeln (y);
end;

{Algoritma}
begin
	readln (N);
	readln (C1);
	readln (C2);
	if (N <= 0) or (C1 = C2) then
		writeln ('Masukan tidak valid')
	else if (N = 1) then
		ulangfl (N,C1)
	else if (N > 1) then
	begin
		ulangfl (N,C1);
		for a:=2 to (N-1) do
		begin
			ulangisi (N,C1,C2);
		end;
		ulangfl (N,C1);
	end;
end.
