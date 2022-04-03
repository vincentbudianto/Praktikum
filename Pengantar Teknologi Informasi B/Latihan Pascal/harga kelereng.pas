program hargakelereng;

var
m, h, k : integer ;
harga : integer ;

begin
	writeln ('jumlah kelereng merah =');
	readln(m);
	writeln ('jumlah kelereng hijau =');
	readln(h);
	writeln('jumlah kelereng kuning =');
	readln(k);
	if (m>=0) then
	begin
		if (h>=0) then
		begin
			if (k>=0) then
			begin
			harga := (m*1000) + (h*1500) + (k*2000) ;
			writeln ('harga = Rp.', harga);
			end
			else
			begin
				writeln('error');
			end;
		end
		else
		begin
			writeln('error')
		end;
	end
	else
	begin
		writeln('error')
	end;
	readln;
end.
