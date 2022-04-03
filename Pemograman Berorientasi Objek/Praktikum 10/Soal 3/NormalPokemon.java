/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : NormalPokemon.java
 * Topik     : Praktikum 10
 * Tanggal   : 04 April 2019
 * Deskripsi : Implementasi Kelas NormalPokemon */

import java.io.*;

// Buat kelas NormalPokemon yang merupakan turunan dari kelas Pokemon
public class NormalPokemon extends Pokemon
{
// Buat constructor tanpa parameter, mencetak "ctor1 NormalPokemon" ke layar
	NormalPokemon()
	{
		super();
		System.out.println("ctor1 NormalPokemon");
	}

// Buat constructor dengan parameter String name, mencetak "ctor2 NormalPokemon" ke layar
	NormalPokemon(String name)
	{
		super(name);
		System.out.println("ctor2 NormalPokemon");
	}
	
// Buat prosedur checkElement yang mencetak "No element for NormalPokemon" ke layar
	public void checkElement()
	{
		System.out.println("No element for NormalPokemon");
	}
	
// Override prosedur displayClass yang mencetak "Sub Class NormalPokemon"
	public void displayClass()
	{
		System.out.println("Sub Class NormalPokemon");
	}
}
