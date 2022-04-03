{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B05-16517189-171115-01.pas}
{Tanggal    : 15 November 2017}
{Deskripsi  : membuat program yang dapat menerima masukan 2 matriks lalu menggunakan operasi-operasi matriks}

{Judul}
program operasimatriks;

{Kamus}
var
	M1 : array [1..100,1..100] of integer;  
	NBrs1, NKol1 : integer;
	M2 : array [1..100,1..100] of integer;  
	NBrs2, NKol2 : integer;
	Mhasil : array [1..100,1..100] of integer;
	i, j, k, N : integer;

{Algoritma}
begin
	write ('Input jumlah baris matriks A : '); readln (NBrs1);
	write ('Input jumlah kolom matriks A : '); readln (NKol1);
	begin
		for i:=1 to NBrs1 do
			begin	
				for j:=1 to NKol1 do
				begin	
					read (M1[i,j]);
				end;
			end;
	end;
	writeln ('Matriks A');
	begin
		for i:=1 to NBrs1 do
			begin
				for j:=1 to NKol1 do
					begin
						write (M1[i,j], ' ');
					end;
				writeln;
			end;
	end;
	write ('Input jumlah baris matriks B : '); readln (NBrs2);
	write ('Input jumlah kolom matriks B : '); readln (NKol2);
	begin
		for i:=1 to NBrs2 do
			begin
				for j:=1 to NKol2 do
				begin
					read (M2[i,j]);
				end;
			end;
	end;
	writeln ('Matriks B');	
	begin
		for i:=1 to NBrs2 do
		begin
			for j:=1 to NKol2 do
				begin
					write (M2[i,j], ' ');
				end;
			writeln;
		end;
	end;
	writeln ('Operasi pada matriks :');
	writeln ('1. Penjumlahan');
	writeln ('2. Pengurangan');
	writeln ('3. Perkalian');
	write ('Masukan operasi yang diinginkan : '); readln (N);
	if ((NBrs1 = NBrs2) and (NKol1 = NKol2)) then
		begin
			if ((N>0) and (N<2)) then {Penjumlahan}
				begin
					for i:=1 to NBrs1 do
						begin
							for j:=1 to NKol1 do
								begin
									Mhasil[i,j] := M1[i,j] + M2[i,j] ;
								end;
						end;
						for i:=1 to NBrs1 do
							begin
								for j:=1 to NKol1 do
									begin
										write (Mhasil[i,j], ' ');
									end;
								writeln;
							end;
				end 
				else if ((N>1) and (N<3)) then {Pengurangan}
					begin
						for i:=1 to NBrs1 do
							begin
								for j:=1 to NKol1 do
									begin
										Mhasil[i,j] := M1[i,j] - M2[i,j] ;
									end;
							end;
						for i:=1 to NBrs1 do
							begin
								for j:=1 to NKol1 do
									begin
										write (Mhasil[i,j], ' ');
									end;
								writeln;
							end;
					end 
					else if ((N>2) and (N<4)) then {Perkalian}
						begin
							for i:=1 to NBrs1 do
								begin
									for j:=1 to NKol2 do
										begin
											Mhasil[i,j] := 0 ;
											for k:=1 to NKol1 do
												begin
													Mhasil[i,j] := Mhasil[i,j] + (M1[i,k] * M2[k,j]) ;
												end;
										end;
								end;
							for i:=1 to NBrs1 do
								begin
									for j:=1 to NKol2 do
										begin
											write (Mhasil[i,j], ' ');
										end;
									writeln;
								end;
						 end 
						 else
						 begin
							writeln ('Matriks Tidak Memenuhi Syarat');
						 end;					
		end 
		else
		begin
			writeln ('Matriks Tidak Memenuhi Syarat');
		end;
end.
