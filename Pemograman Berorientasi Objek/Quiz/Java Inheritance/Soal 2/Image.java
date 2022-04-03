/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Image.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Class Image */

public class Image extends Submission
{
    private String imageUrl;

    public Image(String title, String description, String imageUrl)
    {
        super(title,description);
        this.imageUrl = imageUrl;
    }

    public void printInfo()
    {
        System.out.println("Type: Image; title: " + this.title + "; description: " + this.description + "; views: " + String.valueOf(this.viewCount) + "; favorites: " + String.valueOf(this.favoriteCount) + "; URL: " + this.imageUrl + ";");
    }
}