/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Submission.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Abstract Class Submission */

public abstract class Submission
{
	protected String title;
	protected String description;
	protected int viewCount;
	protected int favoriteCount;

	public Submission(String title, String description)
	{
		this.title = title;
		this.description = description;
		this.viewCount = 0;
		this.favoriteCount = 0;
	}

	public void view()
	{
		this.viewCount++;
	}

	public void addFavorite()
	{
		this.favoriteCount++;
	}

	public abstract void printInfo();
}
