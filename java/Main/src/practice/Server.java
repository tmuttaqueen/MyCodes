/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practice;

import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class Server
{


    public Server()
    {
        try
        {
            ServerSocket server = new ServerSocket( 7575);
            Socket client = server.accept();
            System.out.println("inet address:" + client.getInetAddress());
            System.out.println("local address:" + client.getLocalAddress());
            System.out.println("local port:" + client.getLocalPort());
            System.out.println("port:" + client.getPort());
            new Write(client, "server");
            System.out.println("DONE");
            new Read(client );
        } catch (Exception e)
        {
            System.out.println(e);
        }
    }
    public static void main( String[] args )
    {
        new Server();
    }

}
