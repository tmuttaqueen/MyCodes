package javascene;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.ObjectInputStream;


public class G5
{

    public static void main(String args[]) throws Exception
    {
        //FileReader fileReader = new FileReader(new File("test.txt"));
        FileInputStream fileReader= new FileInputStream(new File("test.txt"));
        ObjectInputStream br = new ObjectInputStream(fileReader);

        String line = null;
        // if no more lines the readLine() returns null
        while ((line = br.readLine()) != null)
        {
            // reading lines until the end of the file

        }

    }
}
