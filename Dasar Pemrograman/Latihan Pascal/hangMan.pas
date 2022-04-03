Program HangMan;
uses crt;

{KAMUS}

const
ListClue: Array [0..4] of String = ('BUAH','BINATANG','KENDARAAN','BUNGA','PLANET');
ListKata: Array [0..4] of Array [0..4] of String = (('MELON','JERUK','MANGGA','PISANG','JAMBU'),('GAJAH','KELINCI','PANDA','KUCING','JERAPAH'),('MOBIL','MOTOR','SEPEDA','HELIKOPTER','PERAHU'),('MELATI','MAWAR','ANGGREK','TULIP','KAMBOJA'),('BUMI','VENUS','MARS','MERKURIUS','SATURNUS'));
Hangmans: Array [0..6] of String =
(
'|--|  '+#13#10+
'|     '+#13#10+
'|     '+#13#10+
'|     '+#13#10+
'|     ',

'|--|  '+#13#10+
'|  o  '+#13#10+
'|     '+#13#10+
'|     '+#13#10+
'|     ',

'|--|  '+#13#10+
'|  o  '+#13#10+
'|  |  '+#13#10+
'|     '+#13#10+
'|     ',

'|--|  '+#13#10+
'|  o  '+#13#10+
'| /|  '+#13#10+
'|     '+#13#10+
'|     ',

'|--|  '+#13#10+
'|  o  '+#13#10+
'| /|\ '+#13#10+
'|     '+#13#10+
'|     ',

'|--|  '+#13#10+
'|  o  '+#13#10+
'| /|\ '+#13#10+
'| /   '+#13#10+
'|     ',

'|--|  '+#13#10+
'|  o  '+#13#10+
'| /|\ '+#13#10+
'| / \ '+#13#10+
'|     '
);
	
	
var
	GLetter: Array [0..25] of Char;
	Kata: String;
	letter:Char;
	NoF, i, j, n, idx: Integer;
	win: Boolean;


procedure TampilKalimat (Kata: String; GLetter : Array of Char; Var win : Boolean);
var
    found : Boolean;
begin
	win := true;
	for i := 1 to Length(Kata) do
		begin
			found:= false;
			for j := 0 to 25 do
				begin
					if (Kata[i] = GLetter[j]) then
						begin
							write(GLetter[j], ' ');
							found := true;
						end;
				end;
			if not(found) then	
				begin
					write('_ ');
					win := false;
				end;
		end;
	writeln;writeln;
end;


procedure ValidasiHuruf (Kata:String; letter : Char; Var NoF:Integer);
var
	found : Boolean;
begin
	found := false;
	for i := 1 to Length(Kata) do
		begin
			if(letter = Kata[i]) then
				begin
					found := true;
				end;
		end;
	if not(found) then
		begin
			NoF := NoF + 1;
		end;
end;

function CekAda (GLetter : Array of Char; letter : Char):Boolean;
begin
	i := 0;
	cekAda := false;
	while (i < 26) and not(cekAda) do
		begin
			if (letter = GLetter[i]) then
				begin
					cekAda := true;
				end;
			i := i + 1;
		end;
end;

{ALGORITMA}

Begin

    //Inisialisasi Guessed Letter
	for i := 0 to 25 do
		begin
			GLetter[i] := '@';
		end;
	
	//Inisialisasi Indeks Guessed Letter
	n := 0;
	
	//Inisialisasi Win
	win := false;
		
	//Inisialisasi Number of False
	NoF:=0;
	
	//Memilih kata secara random dari list kata
	Randomize;
	idx := Round(Random(4));
	Randomize;
	Kata:=ListKata[idx][Round(Random(4))];
	
	clrscr;
	writeln('=========');
	writeln('=HANGMAN=');
	writeln('=========');
	writeln;
	Writeln(HangMans[NoF]);writeln;
	writeln(ListClue[idx]);
	TampilKalimat(Kata,GLetter,win);
			
	while (NoF < 6) and not(win) do
		begin
			
			//Meminta Input
			write('Tebak sebuah huruf (gunakan huruf kapital): '); Readln(letter);
			
			//Meminta jika huruf yang dimasukkan sudah pernah dimasukkan
			while(cekAda(GLetter, letter)) do
				begin
					writeln('Huruf sudah pernah dicoba!');
					write('Masukkan huruf lagi : ');readLn(letter);
				end;
			
			//Mengupdate isi Guessed Letter
			GLetter[n] := letter; n := n + 1;

			//Mengupdate nilai NoF apabila huruf tidak ada di kata
			ValidasiHuruf(Kata, letter, NoF);
			
			//Update Gambar dan Kata
			clrscr;
			writeln('=========');
			writeln('=HANGMAN=');
			writeln('=========');
			writeln;
			Writeln(HangMans[NoF]);writeln;
			writeln(ListClue[idx]);
			TampilKalimat(Kata,GLetter,win);
		end;
	
	//Game Selesai
	if win then
		begin
			writeln('SELAMAT!');
			readln;
		end
	else
		begin
			writeln('MAAF ANDA GAGAL :(');
			readln;
		end;
End.