/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : LabKomputer.java
 * Topik     : Praktikum 08
 * Tanggal   : 21 Maret 2019
 * Deskripsi : Class LabKomputer */
 
import java.io.*;
import java.util.*;
import java.lang.*;

class LabKomputer
{
	private String name;
	private Komputer matriksKomputer[][];
	private final int nBaris;
	private final int nKolom;
	
	public LabKomputer()
	{
		int i, j;

		this.name = "namaLab";
		this.nBaris = 5;
		this.nKolom = 5;
		this.matriksKomputer = new Komputer[this.nBaris][this.nKolom];

		for(i = 0; i < this.nBaris; i++)
		{
			for(j = 0; j < this.nKolom; j++)
			{
				this.matriksKomputer[i][j] = null;
			}
		}
	}
	
	public LabKomputer(String name, int nBaris, int nKolom)
	{
		int i, j;
		
		this.name = name;
		this.nBaris = nBaris;
		this.nKolom = nKolom;
		this.matriksKomputer = new Komputer[this.nBaris][this.nKolom];

		for(i = 0; i < this.nBaris; i++)
		{
			for(j = 0; j < this.nKolom; j++)
			{
				this.matriksKomputer[i][j] = null;
			}
		}
	}
	
	public LabKomputer copyLab()
	{
		int i, j;
		
		LabKomputer newLab = new LabKomputer(this.name, this.nBaris, this.nKolom);
		
		for(i = 0; i < newLab.nBaris; i++)
		{
			for(j = 0; j < newLab.nKolom; j++)
			{
				newLab.matriksKomputer[i][j] = this.matriksKomputer[i][j];
			}
		}
		
		return newLab;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public int getNBaris()
	{
		return this.nBaris;
	}
	
	public int getNKolom()
	{
		return this.nKolom;
	}
	
	public Komputer[][] getMatriksKomputer()
	{
		return matriksKomputer;
	}
	
	public void addKomputer(int id, int b, int k)
	{
		if ((b < this.nBaris) && (b >= 0) && (k < this.nKolom) && (k >= 0))
		{
			if (this.matriksKomputer[b][k] == null)
			{
				this.matriksKomputer[b][k] = new Komputer(id);
			}
		}
	}
	
	public void removeKomputer(int baris, int kolom)
	{
		if ((baris < this.nBaris) && (baris >= 0) && (kolom < this.nKolom) && (kolom >= 0))
		{
			if (this.matriksKomputer[baris][kolom] != null)
			{
				this.matriksKomputer[baris][kolom] = null;
			}
		}
	}
	
	public Komputer getKomputer(int b, int k)
	{
		if ((b < this.nBaris) && (b >= 0) && (k < this.nKolom) && (k >= 0))
		{
			return this.matriksKomputer[b][k];
		}
		else
		{
			return null;
		}
	}
	
	public boolean isKomputerExist(int n)
	{
		int i, j;
		
		for(i = 0; i < this.nBaris; i++)
		{
			for(j = 0; j < this.nKolom; j++)
			{
				if ((this.matriksKomputer[i][j] != null) && (this.matriksKomputer[i][j].getIdKomputer() == n))
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	public void printLab()
	{
		int i, j;
		
		System.out.println(this.name);
		
		for (i = 0; i < this.nBaris; i++)
		{
			for (j = 0; j < (this.nKolom - 1); j++)
			{
				if (this.matriksKomputer[i][j] == null)
				{
					System.out.print("x ");
				}
				else
				{
					if (this.matriksKomputer[i][j].isTurnedOn())
					{
						System.out.print(this.matriksKomputer[i][j].getIdKomputer() + " ");
					}
					else
					{
						System.out.print("0 ");
					}
				}
			}

			if (this.matriksKomputer[i][this.nKolom - 1] == null)
			{
				System.out.println("x");
			}
			else
			{
				if (this.matriksKomputer[i][this.nKolom - 1].isTurnedOn())
				{
					System.out.println(this.matriksKomputer[i][this.nKolom - 1].getIdKomputer());
				}
				else
				{
					System.out.println("0");
				}
			}
		}
	}
}
