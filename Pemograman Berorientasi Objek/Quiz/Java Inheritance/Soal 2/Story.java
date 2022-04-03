/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Story.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Class Story */

public class Story extends Submission
{
    private String textStory;
    private String synopsis;

    public Story(String title, String description, String synopsis, String textStory)
    {
        super(title,description);
        this.textStory = textStory;
        this.synopsis = synopsis;
    }

    public void printInfo()
    {
        System.out.println("Type: Story; title: " + this.title + "; description: " + this.description + "; views: " + String.valueOf(this.viewCount) + "; favorites: " + String.valueOf(this.favoriteCount) + "; synopsis: " + this.synopsis + ";");
    }

    public void printStory()
    {
        System.out.println(this.textStory);
    }
}