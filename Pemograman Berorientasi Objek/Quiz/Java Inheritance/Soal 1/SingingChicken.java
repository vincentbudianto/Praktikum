/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : SingingChicken.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Class SingingChicken */
 
import java.io.*;
import java.lang.*;
import java.util.*;

public class SingingChicken extends SingingAnimal
{
    public SingingChicken(String name, String voice)
    {
        super(2, name, voice);
    }

    public void sing()
    {
        System.out.println("Cock-a-doodle-doo");
    }

    public void dance() 
    {
        super.dance();
        System.out.println("I am also flying");
    }
}