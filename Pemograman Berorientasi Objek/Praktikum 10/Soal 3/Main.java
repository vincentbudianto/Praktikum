/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Main.java
 * Topik     : Praktikum 10
 * Tanggal   : 04 April 2019
 * Deskripsi : Driver Kelas Pokemon */
 
import java.io.*;
import java.lang.*;
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		System.out.println("--- Section 1 ---");
		GhostPokemon A1 = new GhostPokemon();
		FightingPokemon A2 = new FightingPokemon();
		NormalPokemon A3 = new NormalPokemon();
		Pokemon A4 = new Pokemon();
		System.out.println(A1.getName());
		System.out.println(A2.getName());
		System.out.println(A3.getName());
		System.out.println(A4.getName());
		A1 = new GhostPokemon("Gastly");
		A2 = new FightingPokemon("Machop");
		A3 = new NormalPokemon("Rattata");
		A4 = new Pokemon("Big Boss");
		System.out.println(A1.getName());
		System.out.println(A2.getName());
		System.out.println(A3.getName());
		System.out.println(A4.getName());
		A1.displayClass();
		A2.displayClass();
		A3.displayClass();
		A4.displayClass();
		System.out.println("G1");
		System.out.println("12");
		System.out.println("--- Section 2 ---");
		A1.checkElement();
		A2.checkElement();
		A3.checkElement();
		A1.specialSkill();
		A2.displayAura();
		A1.displayAura();
		A2.specialSkill();
		System.out.println("--- Section 3 ---");
		A1.displayClass();
		A3.displayClass();
		System.out.println("Gastly vs Rattata");
		PokemonAction B1 = new PokemonAction(A1);
		PokemonAction B3 = new PokemonAction(A3);
		B1.attack();
		B3.defense();
		B1.attack();
		B3.defense();
		B1.attack();
		B3.defense();
		B1.attack();
		B3.defense();
		B1.attack();
		B3.defense();
		B1.attack();
		B3.defense();
		B1.attack();
		B3.defense();
		B3.attack();
		B1.defense();
		B3.attack();
		B1.defense();
		B3.attack();
		B1.defense();
		B3.useSkill();
		B1.useSkill();
		B3.run();
		System.out.println("--- Section 4 ---");
		System.out.println("New Battle Found");
		A2.displayClass();
		A4.displayClass();
		System.out.println("Big Boss vs Machop");
		PokemonAction B2 = new PokemonAction(A2);
		PokemonAction B4 = new PokemonAction(A4);
		B2.attack();
		B4.defense();
		B2.attack();
		B4.defense();
		B2.attack();
		B4.defense();
		B2.attack();
		B4.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B4.attack();
		B2.defense();
		B2.useSkill();
		B4.useSkill();
		B2.run();
		System.out.println("All Battle Finished");
	}
}
