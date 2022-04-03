/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Main.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Driver Kelas-kelas */
 
import java.io.*;
import java.util.*;
import java.lang.*;

public class Main
{
	public static void main(String[] args)
	{
		int i, j, k;
		
		System.out.println("-----1-----");
		A.stat();
		B.stat();
		C.stat();
		D.stat();
		E.stat();
		System.out.println("-----------\n");
		
		System.out.println("-----2-----");
		A e2 = new E();
		A c2 = new C(10, 5);
		A d2 = new D(3, 3);
		A.stat();
		B.stat();
		C.stat();
		D.stat();
		E.stat();
		System.out.println("-----------\n");
		
		System.out.println("-----3-----");
		A e3 = new E(1, 2);
		A c3 = new C(1, 1);
		A d3 = new D(1, 1);
		A a3 = new A(1, 2);
		A b3 = new B(1, 1);
		b3.show();
		d3.show();
		e3.show();
		c3.show();
		a3.show();
		System.out.println("-----------\n");
		
		System.out.println("-----4-----");
		A c41 = new C(14, 4);
		A c42 = new C(15, 8);
		A a41 = new A(11, 3);
		A b41 = new B(12, 5);
		A a42 = new A(10, 1);
		A d41 = new D(16, 6);
		A d42 = new D(17, 7);
		A e41 = new E(18, 9);
		A b42 = new B(13, 2);
		A e42 = new E(19, 0);
		d41.calc();
		d42.calc();
		a41.calc();
		b41.calc();
		e42.calc();
		b42.calc();
		c41.calc();
		c42.calc();
		e41.calc();
		a42.calc();
		System.out.println("-----------\n");
		
		A.stat();
		B.stat();
		C.stat();
		D.stat();
		E.stat();
	}
}
