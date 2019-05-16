/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javanetworking;

import java.net.*;
import java.io.*;
import java.util.*;
import java.util.logging.*;

/**
 *
 * @author Tanveer Muttaqueen
 */
class Client implements Runnable
{

    Socket sc;
    String name;
    Thread t;
    Client(Socket s, String name)
    {
        sc = s;
        this.name = name;
        t = new Thread(this);
        t.start();
    }

    public void run()
    {
        try
        {
            String msg = null;
            String msgin = null;
            Scanner jin = new Scanner(System.in);
            ObjectInputStream in = new ObjectInputStream( sc.getInputStream() );
            ObjectOutputStream out = new ObjectOutputStream(sc.getOutputStream());
            do
            {
                msg = jin.nextLine();
                out.writeObject( name + "> " + msg );
                msgin = (String)in.readObject();
                System.out.println( msgin );
                
            }while( !msg.equals("bye") );
            in.close();
            out.close();
            
        }catch( IOException e )
        {
            System.out.println(e);
        } catch (ClassNotFoundException ex)
        {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        try
        {
            sc.close();
        } catch (IOException ex)
        {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}

public class TcpClient
{

    public static void main(String[] args)
    {
        try
        {
            Socket my = new Socket("localhost", 7654);
            System.out.println(my.getLocalPort());
            Scanner sc = new Scanner(System.in);
            String t = sc.nextLine();
            new Client(my, t);
        } catch (IOException ex)
        {
            Logger.getLogger(TcpClient.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}
