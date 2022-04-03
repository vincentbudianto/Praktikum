/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : SingingAnimal.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Parent Class SingingAnimal */
 
import java.io.*;
import java.lang.*;
import java.util.*;

public class SingingAnimal
{
    private int legs;
    private String voice;
    private String name;

    public SingingAnimal(int legs, String name, String voice)
    {
        this.legs = legs;
        this.name = name;
        this.voice = voice;
    }
    
    public void sing()
    {
        System.out.println(voice);
    }
    
    public void dance()
    {
        System.out.println("I am dancing using my " + legs + " legs");
    }
    
    public String getName()
    {
        return name;
    }
    
    public void setName(String name)
    {
        this.name = name;
    }
}