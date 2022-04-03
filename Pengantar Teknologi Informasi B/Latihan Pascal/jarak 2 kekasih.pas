program jarak2kekasih;

type
point = record
x : real ;
y : real ;
end;

var
p1 : point ;
p2 : point ;
jarak : real ;

begin
writeln ('koordinat cowo =');
readln (p1.x , p1.y);
writeln ('koordinat cewe =');
readln (p2.x , p2.y);

jarak := sqrt( ((p1.x-p2.x)*(p1.x-p2.x)) + ((p1.y-p2.y)*(p1.y-p2.y)) ) ;

writeln ('jarak antara mereka adalah', jarak:0:2);

readln;
end.
