/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : AddServer.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi class AddServer */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class AddServer implements Server
{
	private final int constant;
	private static int numAddServerCreated = 0;
	
	public AddServer()
	{
		this.constant = 0;
		numAddServerCreated++;
	}
	
	public AddServer(int constant)
	{
		this.constant = constant;
		numAddServerCreated++;
	}
	
	public int processRequest(int request)
	{
		if (this.constant <= 0)
		{
			return (request * 2);
		}
		else
		{
			System.out.println("Server " + numAddServerCreated + " execute " + this.constant + " + " + request);
			return (this.constant + request);
		}
	}
}
