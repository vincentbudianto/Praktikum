/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Memo.java
 * Topik     : Praktikum 07
 * Tanggal   : 14 Maret 2019
 * Deskripsi : Class Printer */

// sebuah kelas menyimpan sebuah value
// lengkapilah dengan package yang diperlukan

class Memo
{
	private int val;

	// ctor
	public Memo(int _val)
	{
		val = _val;
	};

	// getter
	public int getVal()
	// mengirim nilai val
	{
		return val;
	};

	// setter
	public void setVal(int _val)
	// set nilai val
	{
		val = _val;
	};
	
	// fungsi lain, jika anda tak sempat membuat dg benar, tutup sebagai komentar
	public void mirror()
	// "membalik" atribut val, misalnya 123 menjadi 321
	{
		int a = 0;
		
		while (val != 0)
		{
			a = a * 10;
			a = a + val%10;
			val = val/10;
		}
		
		val = a;
	};

	public String toString()
	// membentuk String dari angka 
	// misalnya val=8 dituliskan 8
	{
		return (Integer.toString(val));
	};
}
