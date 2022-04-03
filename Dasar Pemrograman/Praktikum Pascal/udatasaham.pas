{Unit}
unit udataSaham;

{Interface}
interface
	const
		NMax = 100;

	type dataSaham  : record
			IdPemilik : string; { Kode Pemilik Saham}
			IdPT : string;      { Kode Perusahaan}
			Nilai : integer;    { Nilai saham, dalam juta rupiah}
	end;

	type tabPemilikSaham : record
			TSaham : array [1..NMax] of dataSaham;
			Neff : integer; { 0..100, nilai efektif, 0 jika tabel kosong}
	end;

	{Function EOP}
	function EOP (rek : dataSaham): boolean
	{Menghasilkan true jika rek = mark}

	{Procedure LoadDataNilai}
	procedure LoadDataNilai (filename : string; var T : tabPemilikSaham);
	{I.S. : filename terdefinisi, T sembarang}
	{F.S. : Tabel T terisi kepemilikan saham dengan data yang dibaca dari file dengan nama = filename. T.Neff = 0 jika tidak ada file kosong; T diisi dengan seluruh isi file atau sampai T penuh.}

	{Procedure UrutPemilikAsc}
	procedure UrutPemilikAsc (var T : tabPemilikSaham);

	{Procedure HitungRataRata}
	procedure HitungRataRata (T : tabPemilikSaham);

	{Procedure SaveDataNilai}
	procedure SaveDataNilai (T : tabPemilikSaham; filename : string);

{Implementation}

	{Function}
	function EOP (rek : dataSaham): boolean

	{Algoritma Function}
	begin
		if (rek.IdPemilik = 99999999) and (rek.IdPT = XX9999) and (rek.Nilai = -999) then
			begin 
				EOP := true;
			end;
	end;

	{Procedure}
	procedure LoadDataNilai (filename : string; var T : tabPemilikSaham);

	{Kamus Lokal}
	var
		F : text;
		
	{Algoritma Procedure}
	begin
		assign (F, filename);
		reset (F)
			T.Neff := 0
			while (not (EOF)) then
				begin
					T.Neff := T.Neff + 1;
					readln (T.TSaham[T.Neff].IdPemilik, T.TSaham[T.Neff].IdPT, T.TSaham[T.Neff].Nilai);
				end;
	end;

	{Procedure}
	procedure UrutPemilikAsc (var T : tabPemilikSaham);
	
	{Kamus Lokal}
	var
		a : string;
		i : integer;
	
	{Algoritma Procedure}
	begin
		while (i <= T.Neff) do
			begin
				if (T.TSaham[i].IdPemilik >= T.TSaham[i+1].IdPemilik) then
					begin
						i := i + 1;
					end
				else
					begin
						a := T.TSaham[i].IdPemilik;
						T.TSaham[i].IdPemilik := T.TSaham[i+1].IdPemilik;
						T.TSaham[i+1].IdPemilik := a;
						i := i + 1;
					end;
			end;
	end;

	{Procedure}
	procedure HitungRataRata (T : tabPemilikSaham);

	{Kamus Lokal}
	var
		i, jumlah, count : integer;
		kondisi : boolean
		
	{Algoritma Procedure}
	begin
		if (T.Neff = 0) then
			begin
				writeln ('Data kosong');
			end
		else
			begin
				kondisi = true
				while (i <= T.Neff) and (kondisi = true) do
					begin
						jumlah := T.TSaham[i].Nilai;
						count := 1;
						if (T.TSaham[i].IdPemilik = T.TSaham[i+1].IdPemilik) then
							begin
								jumlah := jumlah + T.TSaham[i+1].Nilai;
								count := count + 1;
							end
						else
							begin
								kondisi = false;
							end;
					end;
			end;
	end;

	{Procedure}
	procedure SaveDataNilai (T : tabPemilikSaham; filename : string);

	{Algoritma Procedure}
	begin
		
	end;
end.
