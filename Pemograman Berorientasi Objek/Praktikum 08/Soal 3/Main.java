/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Main.java
 * Topik     : Praktikum 08
 * Tanggal   : 21 Maret 2019
 * Deskripsi : Driver Class A */
 
import java.io.*;
import java.util.*;
import java.lang.*;

public class Main
{
	public static void main(String[] args)
	{
		int i, j, k;
		
		System.out.println("----- section 1 -----");
		System.out.println("Number of objects created so far: " + A.getNumOfACreated() + "\n");
		
		System.out.println("----- section 2 -----");
		A a = new A();
		a.copy();
		A b = new A(10, 5);
		b.copy();
		A c = new A(5, 10);
		c.print();
		b.print();
		a.print();
		System.out.println("Number of objects created so far: " + A.getNumOfACreated() + "\n");
		
		System.out.println("----- section 3 -----");
		i = 0;
		j = 0;

		while (i < 200)
		{
			k = j * j;
			A d = new A(i, k);
			i += 2;
			j++;
		}

		System.out.println("Number of objects created so far: " + A.getNumOfACreated());
		System.out.println("----- FIN -----");
	}
}
