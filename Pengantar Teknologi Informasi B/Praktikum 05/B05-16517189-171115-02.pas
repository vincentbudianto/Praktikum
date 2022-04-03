{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B05-16517189-171115-01.pas}
{Tanggal    : 15 November 2017}
{Deskripsi  : membuat program yang dapat menerima N buah bilangan lalu menyimpannya ke dalam file "Vin.dat" dan menentukan apakah bilangan tersebut prima atau tidak}

{Judul}
program bilanganprima;

{Kamus}
var
	vin : file of integer ;
	M : array [1..100] of integer ;	
	N, countp : integer ;
	i, j, a, b, hasil : integer ;
	CP : boolean ;

{Algoritma}
begin
	assign (vin, 'Vin.dat');
	rewrite (vin);
	write ('Masukan banyaknya bilangan : '); readln (N);
	writeln('Masukan ',N,' bilangan tersebut :');
	begin
	countp := 0 ;
	i:= 1 ;
	while i <= N do
		begin
			readln (M[i]);
			if ((M[i] mod 2 <> 0) and (M[i] mod 3 <> 0) and (M[i] mod 5 <> 0) and (M[i] mod 7 <> 0) and (M[i] <> 1)) then
			begin
			write (vin, M[i]);
			countp := countp + 1 ;
			end;
		i := i + 1 ;	
		end;
	end;		
	writeln ('File berhasil dimasukkan ke dalam Vin.dat');
	close(vin);
		
	assign (vin, 'Vin.dat');
	reset (vin);
	writeln ('Ada', countp ,'bilangan prima yaitu :');
	CP := true;
	for i:=1 to N do
		begin
			read (vin, M[i]);
			writeln (M[i]);
		end;	
	close(vin);
end.
