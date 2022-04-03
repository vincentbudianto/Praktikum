/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : RekeningGiro.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi class RekeningGiro */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class RekeningGiro extends Rekening
{
	private boolean penalti;
	
	RekeningGiro(String nama, double saldo)
	{
		super(nama, saldo, 0.07);
		this.penalti = false;
	}
	
	void setor(double x)
	{
		this.saldo += (x - 0.1);
	}

	void tarik(double x)
	{
		if (saldo > x)
		{
			this.saldo -= (x + 0.1);
		}
	}

	void update()
	{
		this.saldo = this.saldo + (this.saldo * this.sukuBunga) - hitungBiaya();
		
		if (penalti)
		{
			this.saldo -= 10;
		}
		
		if (saldo < 0)
		{
			this.saldo = 0;
		}
	}
}
