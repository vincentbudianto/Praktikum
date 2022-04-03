{Program}
program TigaInteger;

{KAMUS}
var
	A, B, C : integer;
	nilaitengah : integer;
 
{Procedure}
procedure CekInteger (x : integer);

{Algoritma Procedure}
begin
	if (x > 0) and (x mod 2 = 0) then
		writeln ('POSITIF-GENAP')
	else if (x > 0) and (x mod 2 = 1) then
		writeln ('POSITIF-GANJIL')
	else if (x < 0) then
		writeln ('NEGATIF')
	else if (x = 0) then
		writeln ('NOL');
end;

{Function}              
function Max (a, b, c : integer) : integer;

{Algoritma Function}
 begin
	if (a >= b) and (a >= c) then
		Max := a
	else if (b > a) and (b >= c) then
		Max := b
	else if (c > a) and (c > b) then
		Max := c;
 end;
 
{Function} 
function Min (a, b, c : integer): integer;

{Algoritma Function}
begin
	if (a <= b) and (a <= c) then
		Min := a
	else if (b < a) and (b <= c) then
		Min := b
	else if (c < a) and (c < b) then
		Min := c;
end;

{Algoritma}
begin
	readln(A);
    readln(B);
    readln(C);
    CekInteger(A);
    CekInteger(B);
    CekInteger(C);
    writeln(Max(A,B,C));
    writeln(Min(A,B,C));
    nilaitengah := A + B + C - Max(A,B,C) - Min(A,B,C); 
    writeln(nilaitengah);
end.
