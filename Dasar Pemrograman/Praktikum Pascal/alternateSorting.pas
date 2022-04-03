{Program}
program alternateSorting;

{Kamus}
const
	Nmax = 1000;

var
	N, a, i, j, k, l, m, o, p : integer;
	x, ganjil, genap : array [1..Nmax] of integer;

{Algoritma}
begin
	write ('Masukan nilai N : '); readln (N);
	for i:=1 to N do
		begin
			readln (x[i]);
		end;
	j := 1;
	k := 1;
	for i:=1 to N do
		begin
			if (x[i] mod 2 = 1) then
				begin
					ganjil[j] := x[i];
					j := j + 1;
				end
			else if (x[i] mod 2 = 1) then
				begin
					genap[k] := x[i];
					k := k + 1;
				end;
		end;
	l := 1;
	while (l <= j) do
		begin
			if (ganjil[l] >= ganjil[l+1]) then
				begin
					l := l + 1;
				end
			else
				begin
					a := ganjil[l];
					ganjil[l] := ganjil[l+1];
					ganjil[l+1] := a;
					l := l + 1;
				end;
		end;
	m := 1;
	while (m <= k) do
		begin
			if (genap[m] <= genap[m+1]) then
				begin
					m := m + 1;
				end
			else
				begin
					a := genap[m];
					genap[m] := genap[m+1];
					genap[m+1] := a;
					m := m + 1;
				end;
		end;
	o := 1;
	p := 1;
	while (o <= l) and (p <= m) do
		begin
			write (ganjil[o]);
			write (' ');
			write (genap[p]);
			o := o + 1;
			p := p + 1;
		end;
	writeln;
end.
