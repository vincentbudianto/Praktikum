/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : mainStack.cpp
 * Topik     : Latihan 2
 * Tanggal   : 25 Januari 2019
 * Deskripsi : Driver Stack.cpp */

#include <Stack.cpp>
#include <iostream>
using namespace std;

#include <Stack.h>
2
3 Stack s0; /* global (static) */
4
5 int reverse() {
6 static Stack tstack = ...; /* local static */
7
8 // kode untuk fungsi reverse() di sini
9 }
10
11 main () {
12 Stack s1; // automatic
13 Stack s2 (20); // automatic
14 Stack *ptr;
15
16 ptr = new Stack(50); /* free store object */
17 while (...) {
18 Stack s3; // automatic
19
20 /* assignment dgn automatic object */
21 s3 = Stack (5); // ctor Stack(5) is called
22 /* dtor Stack(5) is called */
23
24 // ... instruksi lain ...
25 }
26 /* dtor s3 is called */
27
28 delete ptr; /* dtor *ptr is called */
29 }
30 /* dtor s2 is called */
31 /* dtor s1 is called */
32
33 /* dtor s0 is called */


/* Versi 2
void f1 (const Stack& _)
//instruksi tidak dituliskan
{
	
}

void f2 (Stack _)
//instruksi tidak dituliskan
{
	
}

Stack f3 (int)
//instruksi tidak dituliskan
{
	return ...; // return objek bertipe "Stack"
}

int main ()
{
	Stack s2 (20);		//constructor Stack (int)

	//s3 diciptakan dengan inisialisasi oleh s2
	Stack s3 = s2;		//BITWISE COPY, jika
	
	// tidak ada cctor yang didefinisikan
	f1 (s2);			//tidak ada pemanggilan cctor
	f2 (s3);			//ada pemanggilan cctor
	s2 = f3 (-100);		//ada pemanggilan cctor dan assignment
}
*/

/* Versi 3
f (Stack _)
{
	printf ("ffffffff\n");
}

Stack ll;

int main()
{
	//Kamus
	
	//Algoritma
	printf ("11111111\n");
	Stack x;
	printf ("22222222\n");
	Stack y = x;
	printf ("33333333\n");
	f(x);
	printf ("44444444\n");
	
	return 0;
}
*/
