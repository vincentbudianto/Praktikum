/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : RekeningTabungan.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi class RekeningTabungan */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class RekeningTabungan extends Rekening
{
	RekeningTabungan(String nama, double saldo)
	{
		super(nama, saldo, 0.05);
	}
	
	void setor(double x)
	{
		this.saldo += x;
	}

	void tarik(double x)
	{
		if (saldo > x)
		{
			this.saldo -= x;
		}
	}

	void update()
	{
		this.saldo = this.saldo + (this.saldo * this.sukuBunga) - hitungBiaya();
		
		if (saldo < 0)
		{
			this.saldo = 0;
		}
	}
}
