/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Bear.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Parent Class Bear */

import java.io.*;
import java.lang.*;
import java.util.*;

public class Bear implements CaraMakan
{
    protected int umur;
    protected int len;
    protected int memo[];

    public Bear()
    {
        this.umur = 0;
        this.len = 100;
        this.memo = new int[len];
    }

    public Bear(int _umur, int _len)
    {
        this.umur = _umur;
        this.len = _len;
        this.memo = new int[len];
    }

    public void copy(Bear _Bear)
    {
        this.umur = _Bear.umur;
        this.len = _Bear.len;
        this.memo = new int[len];
    }

    public void caraMakan()
    {
        System.out.println("Makan cara si Bear");
    }

    public void hobby()
    {
        System.out.println("Berkelananya Bear");
    }

    public void print()
    {
        System.out.println("Bear:" + this.umur + "," + this.len);
    }
}