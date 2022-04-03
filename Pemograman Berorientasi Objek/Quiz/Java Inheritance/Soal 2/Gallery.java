/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Gallery.java
 * Topik     : Quiz Online Java Inheritance
 * Tanggal   : 22 Maret 2019
 * Deskripsi : Implementasi Class Gallery */

public class Gallery
{
    Submission g[];
    int num;

    public Gallery(int capacity)
    {
        this.num = 0;
        this.g = new Submission[capacity];
    }

    public void addSubmission(Submission s)
    {
        this.g[num] = s;
        this.num++;
    }

    public void printGallery()
    {
        int i;

        for (i = 0; i < num; i++)
        {
            this.g[i].printInfo();
        }
    }
}