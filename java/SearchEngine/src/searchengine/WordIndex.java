/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package searchengine;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class WordIndex
{
    public String website;
    public int count;
    public WordIndex( String s )
    {
        website = s;
        count = 1;
    }
    public void increaseCount()
    {
        count++;
    }
    public String getWebsite()
    {
        return website;
    }
    public int getCount()
    {
        return count;
    }
}
