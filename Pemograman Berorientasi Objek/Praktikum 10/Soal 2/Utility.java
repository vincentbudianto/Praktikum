/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : GhostPokemon.java
 * Topik     : Praktikum 10
 * Tanggal   : 04 April 2019
 * Deskripsi : Implementasi Kelas Utility */

public class Utility
{
	public static Double add(Number t, Number u)
	{
		return t.doubleValue() + u.doubleValue();
	}

	public static String add(Object t, Object u)
	{
		return t.toString() + u.toString();
	}

	public static Double[] add(Number[] t, Number u)
	{
		Double temp[];
		int i;
		
		temp = new Double[t.length];
		
		for (i = 0; i < t.length; i++)
		{
			temp[i] = t[i].doubleValue() + u.doubleValue();
		}
		
		return temp;
	}

	public static Double[] add(Number t, Number[] u)
	{
		Double temp[];
		int i;
		
		temp = new Double[u.length];
		
		for (i = 0; i < u.length; i++)
		{
			temp[i] = u[i].doubleValue() + t.doubleValue();
		}
		
		return temp;
	}

	public static Double[] add(Number[] t, Number[] u)
	{
		Double temp[];
		int i, len;
		
		if (t.length > u.length)
		{
			len = t.length;
		}
		else
		{
			len = u.length;
		}
		
		temp = new Double[len];
		
		for (i = 0; i < len; i++)
		{
			if ((i < t.length) && (i < u.length))
			{
				temp[i] = t[i].doubleValue() + u[i].doubleValue();
			}
			else if (i < t.length)
			{
				temp[i] = t[i].doubleValue();
			}
			else
			{
				temp[i] = u[i].doubleValue();
			}
		}
		
		return temp;
	}

	public static String[] add(Object[] t, Object[] u)
	{
		int i;
		String temp[];
		
		temp = new String[t.length + u.length];
		
		for (i = 0; i < (t.length + u.length); i++)
		{
			if (i < t.length)
			{
				temp[i] = t[i].toString();
			}
			else
			{
				temp[i] = u[i - t.length].toString();
			}
		}
		
		return temp;
	}

	public static String[] add(Object[] t, Object u)
	{
		int i;
		String temp[];
		
		temp = new String[t.length + 1];
		
		for (i = 0; i < t.length; i++)
		{
			temp[i] = t[i].toString();
		}
		
		temp[t.length] = u.toString();
		
		return temp;
	}

	public static String[] add(Object t, Object[] u)
	{
		int i;
		String temp[];
		
		temp = new String[u.length + 1];
		temp[0] = t.toString();
		
		for (i = 1; i < u.length + 1; i++)
		{
			temp[i] = u[i - 1].toString();
		}
		
		return temp;
	}

	public static void printList(Object[] list)
	{
		int i;
		
		System.out.print("[");
		
		for (i = 0; i < list.length; i++)
		{
			System.out.print(list[i]);
			
			if (i != (list.length - 1))
			{
				System.out.print(", ");
			}
		}
		
		System.out.println("]");
	}
}
