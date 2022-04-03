/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Panda.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Class Panda */

import java.io.*;
import java.lang.*;
import java.util.*;

public final class Panda extends Bear
{
    final private int khas;

    public Panda()
    {
        super();
        this.khas = 5;
    }

    public Panda(int _umur, int _len, int _khas)
    {
        super(_umur, _len);
        this.khas = _khas;
    }

    public void caraMakan()
    {
        System.out.println("Makan cara si Panda");
    }

    public void hobby()
    {
        System.out.println("Berkelananya Panda");
    }

    public void print()
    {
        super.print();
        System.out.println("Panda:" + this.khas);
    }
}