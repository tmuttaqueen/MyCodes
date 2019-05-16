/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package searchengine;

import java.io.*;
import java.net.*;
import java.util.StringTokenizer;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class SearchEngine
{

    /**
     * @param args the command line arguments
     */
    
    String downloadWebsite(String siteName)
    {
        String line;
        StringBuffer strbuffer = new StringBuffer("");
        try
        {
            URL url = new URL(siteName);
            InputStream is = url.openStream();
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            while ((line = br.readLine()) != null)
            {
                strbuffer.append(line);
            }
        } catch ( IOException e)
        {
            //System.out.println("WEBSITE READ ERROR");
        }
        String str = strbuffer.toString();
        return str;
    }

    public static String extractParagraph(String site)
    {
        String paragraph = "";
        String[] pattern = new String[50];
        pattern[0] = "<p>";
        pattern[1] = "</p>";
        pattern[2] = "<li>";
        pattern[3] = "</li>";
        int totalPattern = 4;
        site = site.toLowerCase();

        for (int patternCounter = 0; patternCounter < totalPattern; patternCounter += 2)
        {
            int from, to, i = 0;
            String pattern1 = pattern[patternCounter];
            String pattern2 = pattern[patternCounter+1];
            from = site.indexOf(pattern1, i);
            while (from != -1)
            {
                to = site.indexOf(pattern2, i);
                //System.out.println( from + "   " + to );
                if (to != -1)
                {
                    paragraph = paragraph + site.substring(from, to);
                }
                i = to + 3;
                from = site.indexOf(pattern1, i);
            }
        }
        return processParagraph(paragraph);
    }
    
    static String processParagraph( String paragraph )
    {
        paragraph = paragraph.replaceAll("-", " "); 
        paragraph = paragraph.replaceAll("\\.", " "); ////delete .
        paragraph = paragraph.replaceAll("\\:", " "); //delete :
        paragraph = paragraph.replaceAll("\\,", " "); //delete ,
        paragraph = paragraph.replaceAll("<[^>]*>", ""); //delete all in <>
        paragraph = paragraph.replaceAll("^[a-z.\\s_-]+$", ""); //delete all except lowercase and space
        paragraph = paragraph.replaceAll("\\s{2,}", " ").trim(); ////delete all extra space
        return paragraph;
    }
    
    static void extractUrl(String html, String webSite) throws MalformedURLException
    {
        String pattern1 = "a href=";
        int start = 0, index = html.indexOf(pattern1, start);
        URL baseUrl = new URL(webSite);
        String hostName = baseUrl.getHost();
        while (index != -1)
        {

            int left = html.indexOf("\"", index);
            int right = html.indexOf("\"", left + 1);
            if (left != -1 && right != -1)
            {
                String s = html.substring(left + 1, right);
                URL myUrl = new URL(baseUrl, s);
                String derivedHost = myUrl.getHost();
                if (derivedHost.contains(hostName))
                {
                    try
                    {
                        System.out.println(myUrl);
                        InputStream is = myUrl.openStream();
                        //BufferedReader br = new BufferedReader(new InputStreamReader(is));
                        System.out.println("YES"); //here push url in database

                    } catch (Exception e)
                    {
                        System.out.println("WEBSITE READ ERROR");
                    }
                }
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
    
    
    static void extractWord( String paragraph )
    {
        StringTokenizer token = new StringTokenizer(paragraph, " ");
        while( token.hasMoreElements() )
        {
            System.out.println(token.nextToken());
        }
    }

    public static void main(String[] args)
    {

    }

}
