{Program}
program bilanganKompleks;

{ KAMUS }
const
        ERROR : real = 0.000001;
type
        { Definisi Type Kompleks }
        Kompleks = record
                      a : real; { bilangan real bilangan }
                      b : real; { koefisien real bilangan imajiner }
        end;
var
        A, B : Kompleks; { variabel untuk bilangan kompleks A dan B }
        hasiltambah, hasilkurang, hasilkali, hasilbagi : Kompleks;

{ FUNGSI DAN PROSEDUR }
procedure InputKompleks (var A : Kompleks);
{ I.S.: A sembarang }
{ F.S.: A terdefinisi sesuai dengan masukan pengguna. Memasukkan
        2 bilangan real dan membentuk bilangan kompleks dari input A yang dimasukkan }
	begin
		read(A.a, A.b);
	end;

procedure TulisKompleks (var A : Kompleks);
{ I.S.: A sembarang }
{ F.S.: A terdefinisi sesuai dengan masukan pengguna. Menuliskan bilangan kompleks
  dengan format a + bi}
	begin
		writeln(A.a:0:2, ' + ', A.b:0:2, 'i');
	end;

function TambahKompleks (A, B : Kompleks) : Kompleks; 
{ Menghasilkan hasil penjumlahaan 2 bilangan kompleks}
	begin
		TambahKompleks.a := (A.a + B.a);
		TambahKompleks.b := (A.b + B.b);
	end;

function KurangKompleks (A, B : Kompleks) : Kompleks; 
{ Menghasilkan hasil pengurangan 2 bilangan kompleks}
	begin
		KurangKompleks.a := (A.a - B.a);
		KurangKompleks.b := (A.b - B.b);
	end;

function KaliKompleks (A, B : Kompleks) : Kompleks;
{ Menghasilkan hasil perkalian 2 bilangan kompleks }
	begin
		KaliKompleks.a := (A.a * B.a - A.b * B.b);
		KaliKompleks.b := (A.a * B.b + A.b * B.a);
	end;

function BagiKompleks (A, B : Kompleks) : Kompleks;
{ Menghasilkan hasil pembagian 2 bilangan kompleks }
	begin
		BagiKompleks.a := ((A.a * B.a + A.b * B.b) / (B.a * B.a + B.b * B.b));
		BagiKompleks.b := ((A.b * B.a - A.a * B.b) / (B.a * B.a + B.b * B.b));
	end;


function IsSudutSama (A, B: Kompleks) : integer;
{ Menghasilkan integer yang menyatakan apakah kedua bilangan kompleks memiliki sudut yang
  sama terhadap sumbu x positif:
  1 =  A dan B sama;
  0 =  A dan B tidak sama; }
{ Lengkapi kamus lokal dan algoritma fungsi IsSudutSama }
begin
	if ((A.b / A.a) = (B.b / B.a)) then begin
		if (A.a > 0) and (A.b > 0) and (B.a > 0) and (B.b > 0) then begin
			IsSudutSama := 1;
		end else if (A.a < 0) and (A.b > 0) and (B.a < 0) and (B.b > 0) then begin
			IsSudutSama := 1;
		end else if (A.a > 0) and (A.b < 0) and (B.a > 0) and (B.b < 0) then begin
			IsSudutSama := 1;
		end else if (A.a < 0) and (A.b < 0) and (B.a < 0) and (B.b < 0) then begin
			IsSudutSama := 1;
		end else begin
			IsSudutSama := 0;
		end;
	end else begin
		IsSudutSama := 0;
	end;
end;

{ ALGORITMA PROGRAM UTAMA }
begin
        writeln('Masukkan bilangan A:');
			InputKompleks(A);
        writeln('Masukkan bilangan B:');
			InputKompleks(B);
        writeln('Hasil A+B =');
			hasiltambah := TambahKompleks(A,B);
			TulisKompleks(hasiltambah);
        writeln('Hasil A-B =');
			hasilkurang:= KurangKompleks(A,B);
			TulisKompleks(hasilkurang);
        writeln('Hasil A*B =');
			hasilkali := KaliKompleks(A,B);
			TulisKompleks(hasilkali);
        writeln('Hasil A/B =');
			hasilbagi := BagiKompleks(A,B);
			TulisKompleks(hasilbagi);
        write('Sudut A dan B adalah ');
        { Lengkapi dengan pemanggilan fungsi IsSudutSama dan mengkonversi
              integer hasil fungsi menjadi kata-kata sbb.:
              1 = ‘sama’
              0 = 'tidak sama' }
			if(IsSudutSama(A,B) = 1) then begin
				writeln('sama');
			end else begin
				writeln('tidak sama');
			end;
end.
