package searchengine;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;

import javax.swing.text.AttributeSet;
import javax.swing.text.Element;
import javax.swing.text.ElementIterator;
import javax.swing.text.StyleConstants;
import javax.swing.text.html.HTML;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.HTMLEditorKit;
import javax.swing.text.html.parser.ParserDelegator;

public class ElementIteratorExample {

  public static void main(String args[]) throws Exception {

    ArrayList<String> list = new ArrayList<String>();
    for( int i = 0; i <= 20; i++ )
    {
        list.add( "tanveer" + i );
    }
    System.out.println(list);
    for( int i = 0; i < list.size(); i++ )
    {
        String s = list.get(i);
        if( s.length() <= 8 )
        {
            list.remove(i);
            i--;
        }
    }
      System.out.println(list);
  }
}
