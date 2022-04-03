/* NIM/Nama  : 13517/JiwaJiwa
 * Nama File : Stack.java
 * Topik     : Latihan Java
 * Tanggal   : 15 Maret 2019
 * Deskripsi : Class Stack */

import java.io.*;
import java.util.*;
import java.lang.*;

class Stack
{
	private int defaultStackSize = 500; 
	private int topStack;
	private int size;
	private int[] data;
	
	public Stack()
	{
		data = new int [defaultStackSize];
		topStack = 0;
		size = defaultStackSize;
	}

	public Stack(int a)
	{
		data = new int [a];
		topStack = 0;
		size = a;
	}

	public Push(int a)
	{
		data[topStack] = a;
		topStack++;
	}

	public Pop(ref int a)
	{
		topStack--;
		a = data[topStack];
	}
}
