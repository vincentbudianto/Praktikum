{Program}
program ipmahasiswa;

{Kamus}
const
	Nmax = 1000;

var
	n : array [1..Nmax] of real;
	i : integer;
	count : integer;
	lulus : integer;
	tlulus : integer;
	jumlah : real;
	average : real;

{Function}
function IsWithinRange (X : real; min, max : real) : boolean;
{ Menghasilkan true jika min <= X <= max, menghasilkan false jika tidak }

{Algoritma Function}
begin
	if (X >= min) and (X <= max) then
		begin
			IsWithinRange := true;
		end
	else
		begin
			IsWithinRange := false;
		end;
end;

{Algoritma}
begin
	i := 1;
	count := 0;
	jumlah := 0;
	lulus := 0;
	tlulus := 0;
	readln (n[i]);
	if (n[i] = -999) then
		begin
			writeln ('Tidak ada data');
		end
	else
		begin
			repeat
				if (IsWithinRange (n[i], 0, 4) = true) then
					begin
						count := count + 1;
						jumlah := jumlah + n[i];
					end;
				average := jumlah / count;
				if (IsWithinRange (n[i], 0, 4) = true) and (n[i] >= 2.75) then
					begin
						lulus := lulus + 1;
					end
				else if (IsWithinRange (n[i], 0, 4) = true) and (n[i] < 2.75) then
					begin
						tlulus := tlulus + 1;
					end;
				i := i + 1;
				readln (n[i]);
			until (n[i] = -999);
			writeln (count);
			writeln (lulus);
			writeln (tlulus);
			writeln (average:0:2);
		end;
end.
