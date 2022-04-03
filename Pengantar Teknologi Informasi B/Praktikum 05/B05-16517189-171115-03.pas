{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B05-16517189-171115-01.pas}
{Tanggal    : 15 November 2017}
{Deskripsi  : membuat program yang dapat menetukan berapa sudut (0, 90, 180, atau 270) putaran yang dilakukan matriks}

{Judul}
program rotasimatriks;

{Kamus}
var
	M1 : array [1..100,1..100] of integer;
	M2 : array [1..100,1..100] of integer;
	N,i,j : integer;

{Algoritma}
begin
	write ('Masukan Nilai N: '); readln (N);
	for i:=1 to N do
		begin
			for j:=1 to N do
			begin	
				read (M1[i,j]);
			end;
		end;	
	writeln('Matriks A');
	for i:=1 to N do
		begin
			for j:=1 to N do
			begin
				write (M1[i,j], ' ');
			end;
			writeln;
		end;		
	for i:=1 to N do
		begin
			for j:=1 to N do
			begin	
				read (M2[i,j]);
			end;
		end;	
	writeln('Matriks B');
	for i:=1 to N do
		begin
			for j:=1 to N do
			begin
				write (M2[i,j], ' ');
			end;
			writeln;
		end;
	if (M1[i,j] = M2[i,j]) then
	begin
		writeln ('Matriks B merupakan Matriks A yang diputar 0 derajat');
	end
	else if (M2[i,j] = M1[j,(4-i)]) then
	begin
		writeln ('Matriks B merupakan Matriks A yang diputar 90 derajat');
	end
	else if (M2[i,j] = M1[(4-i),(4-j)]) then
	begin
		writeln ('Matriks B merupakan Matriks A yang diputar 180 derajat');
	end
	else if (M2[i,j] = M1[(4-j),i]) then
	begin
		writeln ('Matriks B merupakan Matriks A yang diputar 270 derajat');
	end;		
end.
