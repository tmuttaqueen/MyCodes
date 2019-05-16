/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package threadlearning;

import java.util.ArrayList;
import static java.util.Collections.sort;
import java.util.Comparator;

/**
 *
 * @author Tanveer Muttaqueen
 */

class Custom extends Exception
{
    String str;
    Custom( String s )
    {
        str = s;
    }
    public String toString()
    {
        return str;
    }
}

class MyC
{
    public static void test( int t ) throws Custom
    {
        if( t < 0 )
            throw new Custom("negative");
        else
            System.out.println(t);
    }
}

public class Test
{
    
    
    public static void main( String[] args )
    {
        try
        {
            MyC.test(-10);
        }
        catch( Exception e )
        {
            System.out.println(e);
        }finally
        {
            System.out.println("finally");
        }
    }
}
