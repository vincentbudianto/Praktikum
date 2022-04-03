{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B04-16517189-171101-03.pas}
{Tanggal    : 01 November 2017}
{Deskripsi  : membuat program yang dapat menghitung frekuensi nama}

{Judul}
program nama;

{Kamus}
const
	Nmaks = 100;
	
type
	AStr = array [1..Nmaks] of string;
	
var
	A, CountA: AStr;
	N : integer;

{Procedure}
procedure ArrayA (var A : AStr; N : integer);

{Kamus Lokal}
var
	i : integer;

{Algoritma Procedure}
begin
	for i := 1 to N do
	begin
		write ('Masukan nama ke-', i, ': '); readln (A[i]);
	end;
end;

{Procedure}
procedure FreA (var CA : AStr; N : integer; A : AStr);

{Kamus Lokal}
var
	i, count, y : integer;
	ACount : array [1..100] of integer;

{Algoritma Procedure}
begin
	CA[1] := A[1];
	count := 0;

	for i := 1 to N do
	begin
		for y := 1 to N do
		if CA[i] = A[y] then
		begin
			ACount[i] := count + 1;
		end
		else
		begin
			CA[i] := A[y];
		end;
	end;

	for i := 1 to N do
	begin
		writeln (CA[i], ' : ');
	end;

end;

{Algoritma}
begin
	write ('Masukan nilan N : '); readln (N);
	ArrayA (A,N);
	writeln;
	FreA (CountA, N, A);
end.
