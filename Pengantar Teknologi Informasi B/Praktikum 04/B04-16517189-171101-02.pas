{NIM / Nama : 16517189 / Vincent Budianto}
{Nama File  : B04-16517189-171101-02.pas}
{Tanggal    : 01 November 2017}
{Deskripsi  : membuat program yang menerima input 2 kata (s1 dan s2) dan menentukan apakah 2 kata tersebut anagram atau bukan}

{Judul}
program anagram;

{Kamus}
var
	s1, s2 : string;
	x, y, n1, n2 : integer;
	ana : boolean;

{Algoritma}
begin
	write ('Masukan s1 : '); readln (s1);
	write ('Masukan s2 : '); readln (s2);
	n1 := length (s1);
	n2 := length (s2);
	
	if (n1 <> n2) then
	begin
		ana := false;
	end
	else {n1 = n2}
	ana := true;
	begin
		for x := 1 to n2 do
		begin
			for y := 1 to n1 do
			begin
				if (s2[x] = s1[y]) then
				begin
				s2[x] := 0;
				s1[y] := 0;
				end
				else
				begin
					ana := false;
				end;
			end;
		end;
	end;
	
	if (ana = true) then
	writeln (s1, ' dan ', s2, ' adalah anagram.')
	else {ana = false}
	writeln (s1, ' dan ', s2, ' bukanlah anagram.');
	
end.
