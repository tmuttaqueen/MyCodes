/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myserver;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class MyServer
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        try
        {
            ServerSocket server = new ServerSocket(10000);
            Socket mysocket = server.accept();
            DataInputStream dis = new DataInputStream( mysocket.getInputStream() );
            String str = (String)dis.readUTF();
            System.out.println("client: " + str);
            server.close();
        } catch (IOException ex)
        {
            Logger.getLogger(MyServer.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
}
