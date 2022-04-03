/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : GhostPokemon.java
 * Topik     : Praktikum 10
 * Tanggal   : 04 April 2019
 * Deskripsi : Implementasi Kelas GhostPokemon */

import java.io.*;

// Buat kelas GhostPokemon yang merupakan turunan dari kelas Pokemon dan mengimplementasi interface ElementalType<String>
public class GhostPokemon extends Pokemon implements ElementalType<String>
{
// Atribut tolong dilihat sendiri pada diagram kelas
	private String id;
	private String elementalName;
	
// Buat constructor tanpa parameter, meng-assign "Ghost" ke atribut elementalName dan mencetak "ctor1 GhostPokemon" ke layar
	GhostPokemon()
	{
		super();
		elementalName = "Ghost";
		System.out.println("ctor1 GhostPokemon");
	}
	
// Buat constructor dengan parameter String name, meng-assign "Ghost" ke atribut elementalName dan mencetak "ctor2 GhostPokemon" ke layar
	GhostPokemon(String name)
	{
		super(name);
		elementalName = "Ghost";
		System.out.println("ctor2 GhostPokemon");
	}
	
// Buat prosedur checkElement yang mencetak "[name] have [elementName] type" ke layar
	public void checkElement()
	{
		System.out.println(getName() + " have " + this.elementalName + " type");
	}
	
// Override prosedur displayClass yang mencetak "Sub Class GhostPokemon"
	public void displayClass()
	{
		System.out.println("Sub Class GhostPokemon");
	}
	
// Realisasi prosedur displayAura, mencetak "There is ominous aura around"
	public void displayAura()
	{
		System.out.println("There is ominous aura around");
	}
	
// Realisasi prosedur specialSkill, mencetak "Special skill invisible"
	public void specialSkill()
	{
		System.out.println("Special skill invisible");
	}

// Realisasi setUniqueID dan getUniqueID
	public void setUniqueID(String a)
	{
		this.id = a;
	}
	
	public String getUniqueID()
	{
		return this.id;
	}
}
