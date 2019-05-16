package searchengine;

import java.io.*;

public class Html2TextWithRegExp {
   private Html2TextWithRegExp() {}

   public static void main (String[] args) throws Exception{
     StringBuilder sb = new StringBuilder();
     BufferedReader br = new BufferedReader(new FileReader("java-new.html"));
     FileReader reader = new FileReader("java-new.html");
     String line;
     StringBuffer sf = new StringBuffer();
     
     while ( reader.read() != -1) 
     {
       sf.append((char)reader.read());
       // or
       //  sb.append(line).append(System.getProperty("line.separator"));
     }
     System.out.println(sf);
     String nohtml = sf.toString().replaceAll("\\<.*?>","");
     System.out.println(nohtml);
   }
}