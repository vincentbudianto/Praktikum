/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Rekening.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi abstract class Rekening */
 
import java.io.*;
import java.util.*;
import java.lang.*;

abstract class Rekening
{
	protected String nama;
	protected double saldo;
	protected double sukuBunga;
	
	Rekening(String nama, double saldo, double sukuBunga)
	{
		this.nama = nama;
		
		if (saldo < 0)
		{
			this.saldo = 0;
		}
		else
		{
			this.saldo = saldo;
		}
		
		this.sukuBunga = sukuBunga;
	}
	
	abstract void setor(double x);
	
	abstract void tarik(double x);
	
	abstract void update();
	
	double hitungBiaya()
	{
		if ((this.saldo * 0.1) > 10)
		{
			return 10;
		}
		else
		{
			return (this.saldo * 0.1);
		}
	}
	
	String getNama()
	{
		return this.nama;
	}
	
	double getSaldo()
	{
		return this.saldo;
	}
	
	double getSukuBunga()
	{
		return this.sukuBunga;
	}
}
