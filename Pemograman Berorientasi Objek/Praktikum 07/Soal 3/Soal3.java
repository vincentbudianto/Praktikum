/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Soal3.java
 * Topik     : Praktikum 07
 * Tanggal   : 14 Maret 2019
 * Deskripsi : Math operation in Java */

import java.io.*;
import java.util.*;
import java.lang.*;

public class Soal3
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(a+b);
        System.out.println(a*b);
        System.out.println(a/b);
        System.out.println(a%b);
        System.out.printf("%.0f\n", Math.pow(a, b));
    }
}
