/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : MultiplyServer.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi class MultiplyServer */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class MultiplyServer implements Server
{
	private final int constant;
	private static int numMultiplyServerCreated = 0;
	
	public MultiplyServer()
	{
		this.constant = 0;
		numMultiplyServerCreated++;
	}
	
	public MultiplyServer(int constant)
	{
		this.constant = constant;
		numMultiplyServerCreated++;
	}
	
	public int processRequest(int request)
	{
		if (this.constant <= 0)
		{
			return (request * request);
		}
		else
		{
			System.out.println("Server " + numMultiplyServerCreated + " execute " + this.constant + " * " + request);
			return (this.constant * request);
		}
	}
}
