/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Calculator.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi class Calculator */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class Calculator
{
	private Server server;
	
	Server getServer()
	{
		return server;
	}
	
	void addNumber(int angka1, int angka2)
	{
		AddServer a = new AddServer(angka1);
	
		this.server = a;
		System.out.println("Server returned " + this.server.processRequest(angka2));
	}
	
	void doubleNumber(int angka)
	{
		AddServer a = new AddServer();
	
		this.server = a;
		System.out.println("Server returned " + this.server.processRequest(angka));
	}
	
	void multiplyNumber(int angka1, int angka2)
	{	
		MultiplyServer a = new MultiplyServer(angka1);
		
		this.server = a;
		System.out.println("Server returned " + this.server.processRequest(angka2));
	}
	
	void squareNumber(int angka)
	{
		MultiplyServer a = new MultiplyServer();
		
		this.server = a;
		System.out.println("Server returned " + this.server.processRequest(angka));
	}
}
