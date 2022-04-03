/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Matriks.java
 * Topik     : Praktikum 08
 * Tanggal   : 21 Maret 2019
 * Deskripsi : Class Matriks */

import java.io.*;
import java.util.*;
import java.lang.*;

class Matriks
{
	private int baris;
	private int kolom;
	private int data[][];
	
	public Matriks()
	{
		this.baris = 0;
		this.kolom = 0;
		this.data = new int[baris][kolom];
	}
	
	public Matriks(int baris, int kolom)
	{
		int i, j;
		
		this.baris = baris;
		this.kolom = kolom;
		this.data = new int[baris][kolom];
		
		for(i = 0; i < this.baris; i++)
		{
			for(j = 0; j < this.kolom; j++)
			{
				this.data[i][j] = 0;
			}
		}
	}
	
	public int getBrs()
	{
		return this.baris;
	}
	
	public int getKol()
	{
		return this.kolom;
	}
	
	public int getData(int baris, int kolom)
	{
		return (this.data[baris][kolom]);
	}
	
	public void setData(int baris, int kolom, int data)
	{
		this.data[baris][kolom] = data;
	}
	
	public boolean isEqSize(Matriks M)
	{
		return ((this.baris == M.baris) && (this.kolom == M.kolom));
	}
	
	public Matriks tambah(Matriks M)
	{
		int i, j, x, y;
		
		if (this.baris > M.baris)
		{
			x = this.baris;
		}
		else
		{
			x = M.baris;
		}
		
		if (this.kolom > M.kolom)
		{
			y = this.kolom;
		}
		else
		{
			y = M.kolom;
		}
		
		Matriks newM = new Matriks(x, y);

		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				if ((i < this.baris) && (j < this.kolom))
				{
					newM.data[i][j] += this.data[i][j];
				}
				
				if ((i < M.baris) && (j < M.kolom))
				{
					newM.data[i][j] += M.data[i][j];
				}
			}
		}
		
		return newM;
	}

	public Matriks kurang(Matriks M)
	{
		int i, j, x, y;
		
		if (this.baris > M.baris)
		{
			x = this.baris;
		}
		else
		{
			x = M.baris;
		}
		
		if (this.kolom > M.kolom)
		{
			y = this.kolom;
		}
		else
		{
			y = M.kolom;
		}
		
		Matriks newM = new Matriks(x, y);

		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				if ((i < this.baris) && (j < this.kolom))
				{
					newM.data[i][j] += this.data[i][j];
				}
				
				if ((i < M.baris) && (j < M.kolom))
				{
					if ((i < this.baris) && (j < this.kolom))
					{
						newM.data[i][j] -= M.data[i][j];
					}
					else
					{
						newM.data[i][j] += M.data[i][j];
					}
				}
			}
		}
		
		return newM;
	}
	
	public Matriks kali(int a)
	{
		int i, j;
		
		Matriks newM = new Matriks(this.baris, this.kolom);
		
		for (i = 0; i < newM.baris; i++)
		{
			for (j = 0; j < newM.kolom; j++)
			{
				newM.data[i][j] = this.data[i][j] * a;
			}
		}
		
		return newM;
	}
	
	public boolean isSimetri()
	{
		return (this.baris == this.kolom);
	}
}
