{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B04-16517189-171101-01.pas}
{Tanggal    : 01 November 2017}
{Deskripsi  : membuat program yang dapat menentukan jumlah pasangan 2 angka (a dan b) dari 2 array yang berbeda (A dan B) sehingga a + b = N}

{Judul}
program pasanganangka;

{Kamus}
const
	Nmaks = 100;
	
type
	AInt = array [1..Nmaks] of integer;
var
	A : AInt;
	B : Aint;
	x, y, N, nA, nB, jumlah, count : integer;

{Procedure}
procedure ArrayA (var A : AInt; N : integer);

{Kamus Lokal}
var
	i : integer;

{Algoritma Procedure}
begin
	writeln ('Masukan elemen pada A:');
	for i := 1 to N do
	begin
		read (A[i]);
	end;
end;

{Procedure}
procedure ArrayB (var B : AInt; N : integer);

{Kamus Lokal}
var
	i : integer;

{Algoritma Procedure}
begin
	writeln ('Masukan elemen pada B:');
	for i := 1 to N do
	begin
		read (B[i]);
	end;
end;

{Algoritma}
begin
	write ('Masukan banyak elemen pada A : '); readln (nA);
	ArrayA (A,nA);
	write ('Masukan banyak elemen pada B : '); readln (nB);
	ArrayB (B,nB);
	write ('Masukan nilai N : '); readln (N);
	count := 0;
	for x:=1 to nA do
	begin
		for y:=1 to nB do
		begin
			jumlah := A[x] + B[y];
			if (jumlah = N) then
			begin
			count := count + 1;
			end;
		end;
	end;
	writeln ('Banyak pasangan ada sebanyak ', count);
end.
