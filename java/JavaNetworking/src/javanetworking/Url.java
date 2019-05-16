/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javanetworking;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.*;
import java.io.Serializable;
import java.net.MalformedURLException;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tanveer Muttaqueen
 */
class Myp //implements Serializable
{

    int c;

    Myp(int x)
    {
        c = x;
    }
}

class Person extends Myp implements Serializable
{

    int a;
    int b;
    private static final long serialVersionUID = -1322322139926390329L;
    Person(int a, int b, int c)
    {
        super(c);
        this.a = a;
        this.b = b;
        //System.out.println(""+ a + " " + b + " " + c);
    }

    @Override
    public String toString()
    {
        return "" + a + " " + b + " " + c;
    }
}

public class Url
{

    public static void main(String[] args)
    {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("out.bin")))
        {
            oos.writeObject(new Person(2, 4, 8));

        } catch (FileNotFoundException ex)
        {
            Logger.getLogger(Url.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex)
        {
            Logger.getLogger(Url.class.getName()).log(Level.SEVERE, null, ex);
        }

        System.out.println("ok");

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("out.bin")))
        {
            System.out.println(ois.readObject());

        } catch (FileNotFoundException ex)
        {
            Logger.getLogger(Url.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex)
        {
            Logger.getLogger(Url.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex)
        {
            Logger.getLogger(Url.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
