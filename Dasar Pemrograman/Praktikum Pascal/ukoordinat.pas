unit ukoordinat;

interface
	type
		Cartesian = record
			x : integer;
			y : integer;
			z : integer;
		end;

	function GetManhattanDistance(p1, p2 : Cartesian): integer;
{Menghasilkan jarak manhattan antara dua buah titik koordinat Cartesian p1 dan p2, jarak
manhattan merupakan penjumlahan dari perubahan x, y dan z anatara dua buah titik. Rumus Manhattan
Distance antara p1(x,y) dan p2(a,b) = |x−a|+|y−b|.}

	function GetEuclideanDistance(p1, p2 : Cartesian): real;
{Menghasilkan jarak euclidean antara dua buah titik koordinat Cartesian p1 dan p2, jarak euclidean
merupakan jarak terdekat antara dua buah titik. Rumus Euclidean Distance antara p1(x,y) dan p2(a,b) = 
√(x - a)² + (y - b)².}

	function sphereAt(p1 : Cartesian; r : integer): integer;
{Jika dimisalkan p1 adalah titik pusat bola dengan jari-jari r, maka fungsi ini mengembalikan banyak
bidang (x=0, y=0, dan z=0) yang berpotongan dengan bola. Bidang x=0 dikatakan berpotongan dengan bola
apabila (p1.x + r) * (p1.x - r) <0. Cara yang sama dapat digunakan untuk mengecek y=0 ataupun z=0
(dengan mengganti x menjadi y ataupun z)}

	procedure Translation(var p1 : Cartesian ; delta : Cartesian);
{Menghasilkan translasi dari titik p1 jika digeser dengan delta}
{I.S : p1 dan delta terdefinisi}
{F.S : p1 digeser dengan delta, misal untuk p1.x digeser sejauh delta.x}

implementation
	function GetManhattanDistance(p1, p2 : Cartesian): integer;
	begin
		GetManhattanDistance := abs(p1.x-p2.x) + abs(p1.y-p2.y) + abs(p1.z-p2.z)
	end;
	
	function GetEuclideanDistance(p1, p2 : Cartesian): real;
	begin
		GetEuclideanDistance := sqrt((sqr(p1.x-p2.x)) + (sqr(p1.y-p2.y)) + (sqr(p1.z-p2.z)))
	end;
	
	function sphereAt(p1 : Cartesian; r : integer): integer;
	begin
		sphereAt := 0;
		if ((p1.x + r) * (p1.x - r) < 0) then
			begin
				sphereAt := sphereAt + 1;
			end;
			
		if ((p1.y + r) * (p1.y - r) < 0) then
			begin
				sphereAt := sphereAt + 1;
			end;
			
		if ((p1.z + r) * (p1.z - r) < 0) then
			begin
				sphereAt := sphereAt + 1;
			end;
	end;
	
	procedure Translation(var p1 : Cartesian ; delta : Cartesian);
	begin
		p1.x := p1.x + delta.x;
		p1.y := p1.y + delta.y;
		p1.z := p1.z + delta.z;
	end;
end.
