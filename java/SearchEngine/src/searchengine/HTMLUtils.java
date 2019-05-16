package searchengine;

import java.io.IOException;
import java.io.Reader;
import java.io.StringReader;
import java.util.List;
import java.util.ArrayList;

import javax.swing.text.html.parser.ParserDelegator;
import javax.swing.text.html.HTMLEditorKit.ParserCallback;
import javax.swing.text.html.HTML.Tag;
import javax.swing.text.MutableAttributeSet;

public class HTMLUtils
{
    public static List<String> extractText(Reader reader) throws IOException
    {
        final ArrayList<String> list = new ArrayList<String>();
        
        ParserDelegator parserDelegator = new ParserDelegator();
        ParserCallback parserCallback = new ParserCallback()
        {
            @Override
            public void handleText(final char[] data, final int pos)
            {
                list.add(new String(data));
            }

            @Override
            public void handleStartTag(Tag tag, MutableAttributeSet attribute, int pos)
            {
            }

            @Override
            public void handleEndTag(Tag t, final int pos)
            {
            }

            @Override
            public void handleSimpleTag(Tag t, MutableAttributeSet a, final int pos)
            {
            }

            @Override
            public void handleComment(final char[] data, final int pos)
            {
            }

            @Override
            public void handleError(final java.lang.String errMsg, final int pos)
            {
            }
        };
        parserDelegator.parse(reader, parserCallback, true);
        return list;
    }

    public final static void main(String[] args) throws Exception
    {
        
        String str  = new String();
        StringReader reader = new StringReader(str);
        List<String> lines = HTMLUtils.extractText(reader);
        for (int i = 0; i < lines.size(); i++)
        {
            String ln = lines.get(i);
            if( ln.length() <= 2 )
            {
                lines.remove(i);
                i--;
            }
        }
    }
}
