/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Komputer.java
 * Topik     : Praktikum 08
 * Tanggal   : 21 Maret 2019
 * Deskripsi : Class Komputer */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class Komputer
{
	private int idKomputer;
	private boolean turnedOn;
	
	public Komputer(int idKomputer)
	{
		this.idKomputer = idKomputer;
		this.turnedOn = false;
	}
	
	public int getIdKomputer()
	{
		return this.idKomputer;
	}
	
	public void setIdKomputer(int idKomputer)
	{
		this.idKomputer = idKomputer;
	}
	
	public void turnOn()
	{
		this.turnedOn = true;
	}
	
	public void turnOff()
	{
		this.turnedOn = false;
	}
	
	public boolean isTurnedOn()
	{
		return this.turnedOn;
	}
}
