program luastanah;
var p,l : real;
luas : real ;
begin
writeln ('masukan panjang');
readln (p);
writeln('masukan lebar');
readln (l);

if (p>0) then
begin
if (l>0) then
begin
luas := p * l;
writeln ('luas adalah', luas:0:2);
end

else
begin
writeln ('error');
end;
end

else
begin
writeln ('error');
end;

readln;

end.