package practice;

import java.net.Socket;

public class Client
{

    public Client()
    {
        try
        {
            Socket client = new Socket("localhost", 7575);
            System.out.println("inet address:" + client.getInetAddress());
            System.out.println("local address:" + client.getLocalAddress());
            System.out.println("local port:" + client.getLocalPort());
            System.out.println("port:" + client.getPort());
            new Write(client, "client");
            System.out.println("DONE");
            new Read(client);
        } catch (Exception e)
        {
            System.out.println(e);
        }
    }
    public static void main( String[] args )
    {
        new Client();
    }
}
