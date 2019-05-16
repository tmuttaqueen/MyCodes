/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practice;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tanveer Muttaqueen
 */
class ReadClient implements Runnable
{
    Socket socket;
    ObjectInputStream ois;
    Thread t;
    
    public ReadClient( Socket c )
    {
        System.out.println("start read");
        socket = c;
        try
        {
           ois = new ObjectInputStream(socket.getInputStream());
           System.out.println("input");
           
        } catch (IOException ex)
        {
            Logger.getLogger(Read.class.getName()).log(Level.SEVERE, null, ex);
        }
        t = new Thread(this);
        t.start();
    }
    
    public void run()
    {
        System.out.println("start");
        while(true)
        {
            try{
                System.out.println(  (String)ois.readObject() );
            }
            catch( Exception e )
            {
                System.out.println(e);
            }
        }
        
    }
    
}

