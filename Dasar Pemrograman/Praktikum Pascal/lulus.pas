{Program}
Program Lulus;

{Kamus}
type
	MahasiswaLulus = record
		indeks : integer;
		nilai : integer;
end;

TabelMahasiswa = array [1..100] of integer;

var
	N,E,i : integer;
	Mahasiswa: MahasiswaLulus;
	tabel: TabelMahasiswa;

{Function}
function CariLulus(N,E: integer; tabel:TabelMahasiswa): MahasiswaLulus;

{Kamus Lokal}
var
	found : boolean;
	x     : integer;

{Algoritma Function}
begin
	found := false; x := 1;
	while (x<=N) and (found = false) do
		begin
			if (tabel[x] > E) then
				begin
					CariLulus.indeks := x;
					CariLulus.nilai := tabel[x];
					found := true;
				end
			else
				begin
					inc(x);
				end;
		end;
	if (not(found)) then
		begin
			CariLulus.indeks := -1;
			CariLulus.nilai := 0;
		end;
end;

{Algoritma}
begin
    writeln('Masukan berapa nilai yang ingin dimasukkan :');
    readln(N);
    for i:=1 to N do
		begin
			writeln('Masukan Nilai :');
			readln(tabel[i])
		end;
    writeln('Masukan Nilai Minimal :');
    readln(E);
    Mahasiswa := CariLulus(N,E,tabel);
    writeln('Nilai Mahasiswa : ', Mahasiswa.nilai);
    writeln('Mahasiswa ke : ', Mahasiswa.indeks);
end.
