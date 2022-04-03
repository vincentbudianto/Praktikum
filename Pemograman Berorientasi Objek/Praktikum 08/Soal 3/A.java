/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : A.java
 * Topik     : Praktikum 08
 * Tanggal   : 21 Maret 2019
 * Deskripsi : Class A */
 
import java.io.*;
import java.util.*;
import java.lang.*;

public class A 
{
    private static int numOfACreated;
    private int x;
    private int y;

    public A()
    {
        x = 0;
        y = 0;
        System.out.println("ctor1 A");
        numOfACreated++;
    }
    
    public A(int x, int y)
    {
        this.x = x;
        this.y = y;
        System.out.println("ctor2 A x:" + Integer.toString(x) + ", y:" + Integer.toString(y));
        numOfACreated++;
    }
    
    public A copy()
    {
        System.out.println("copy");
        A newA = new A();
        newA.x = x;
        newA.y = y;
        return newA;
    }
    
    public void print()
    {
        System.out.println("current value >> x:" + Integer.toString(x) + ", y:" + Integer.toString(y));
    }

    public static int getNumOfACreated()
    {
        return numOfACreated;
    }
}
