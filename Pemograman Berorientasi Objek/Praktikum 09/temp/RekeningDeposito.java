/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : RekeningDeposito.java
 * Topik     : Praktikum 09
 * Tanggal   : 28 Maret 2019
 * Deskripsi : Implementasi class RekeningDeposito */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class RekeningDeposito extends Rekening
{
	private int bulan;
	
	RekeningDeposito(String nama, double saldo)
	{
		super(nama, saldo, 0.15);
		this.bulan = 0;
	}
	
	void setor(double x)
	{
		System.out.println("Tidak dapat melakukan penyetoran uang untuk rekening ini.");
	}

	void tarik(double x)
	{
		System.out.println("Tidak dapat melakukan penarikan uang sebagian untuk rekening ini.");
	}

	void update()
	{
		if ((bulan % 12) == 0)
		{
			this.saldo = this.saldo + (this.saldo * this.sukuBunga) - hitungBiaya();
		}
	}
	
	void tarik()
	{
		if (bulan < 12)
		{
			System.out.println("Anda terkena penalti sebesar <penalti>.");
		}
	}
}
