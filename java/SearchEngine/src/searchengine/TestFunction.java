/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package searchengine;

import java.io.BufferedReader;

import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;

import java.net.MalformedURLException;
import java.net.URL;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class TestFunction
{

    static void extractUrl(String html, String webSite) throws MalformedURLException
    {
        String pattern1 = "a href=";
        int start = 0, index = html.indexOf(pattern1, start);
        URL baseUrl = new URL(webSite);
        //String hostName = baseUrl.getHost();
        while (index != -1)
        {

            int left = html.indexOf("\"", index);
            int right = html.indexOf("\"", left + 1);
            if (left != -1 && right != -1)
            {
                String s = html.substring(left + 1, right);
                int i;
                for( i = s.length() - 1; i >= 0; i-- )
                {
                    if( (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') || (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') || (s.charAt(i) >= '0' && s.charAt(i) <= '9') )
                        break;
                }
                i++;
                s = s.substring(0, i);
                URL myUrl = new URL(baseUrl, s);
                System.out.println(myUrl);
                System.out.println("YES"); //here push url in database
            }
            start = right;
            if (start != -1)
            {
                index = html.indexOf(pattern1, start);
            } else
            {
                index = -1;
            }
        }
    }

    public static void main(String[] args) throws IOException
    {

        BufferedReader bufferedReader = new BufferedReader(new FileReader("readme.txt"));

        StringBuffer stringBuffer = new StringBuffer();
        String line = null;
        while ((line = bufferedReader.readLine()) != null)
        {

            stringBuffer.append(line).append("\n");
        }
        String s = stringBuffer.toString();
        String w = "https://developer.salesforce.com/forums/?id=906F00000008pc4IAA";
        extractUrl(s, w);
    }
}
