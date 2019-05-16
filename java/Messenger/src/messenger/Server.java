package messenger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package messenger;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Awesome Muttaqueen
 */
class ClientData
{

    public InetAddress ip;
    public int port;

    ClientData(InetAddress s, int t)
    {
        ip = s;
        port = t;
    }
}

class ServerThread implements Runnable
{

    DatagramSocket socket;
    DatagramPacket send, receive;
    Thread t;
    String serverName;
    int port = 45555;

    HashMap hm = new HashMap();

    ServerThread(String s)
    {

        serverName = s;
        try
        {
            socket = new DatagramSocket(port);
        } catch (SocketException ex)
        {
            Logger.getLogger(ServerThread.class.getName()).log(Level.SEVERE, null, ex);
        }

        t = new Thread(this);
        t.start();
    }

    public void run()
    {
        while (true)
        {
            byte[] sendData = new byte[2048];
            byte[] receiveData = new byte[2048];
            DatagramPacket receive = new DatagramPacket(receiveData, receiveData.length);
            try
            {
                socket.receive(receive);

            } catch (IOException ex)
            {
                Logger.getLogger(ServerThread.class.getName()).log(Level.SEVERE, null, ex);
            }
            String data = new String(receive.getData(), 0, receive.getLength());
            //data = data.substring(0, data.indexOf(0));
            if (!data.contains("To"))
            {
                System.out.println("Don't know the receipent");
                continue;
            }
            if (!data.contains("From"))
            {
                System.out.println("Don't know the Sender");
                continue;
            }

            if (data.contains("Via: " + serverName))
            {
                System.out.println(data + "\n");
                if (data.contains("Port: "))
                {
                    int d = data.indexOf("From: ") + ("From: ").length();
                    String nm = data.substring(d, data.indexOf("\nPort"));
		    String g = data.substring(data.indexOf("Port")+("Port: ").length());
		    int id = Integer.parseInt(g);
		    //System.out.println(id);
                    ClientData dd = new ClientData(receive.getAddress(), id);
                    hm.put(nm, dd);
                } else if (data.contains("Body: "))
                {
                    String to = data.substring(data.indexOf("To: ") + ("To: ").length(), data.indexOf("\nFrom"));
                    sendData = data.getBytes();
                    if (hm.containsKey(to))
                    {
                        ClientData temp = (ClientData) hm.get(to);
                        //System.out.println( to + " " + temp.ip + " " + temp.port );
                        send = new DatagramPacket(sendData, sendData.length, temp.ip, temp.port);
                        try
                        {
                            socket.send(send);

                        } catch (IOException ex)
                        {
                            Logger.getLogger(ServerThread.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    } else
                    {
                        System.out.println("Warning: Unknown recipient. Message dropped.");
                    }
                }
            } else
            {
                System.out.println("Warning: Server name mismatch. Message dropped.");
            }
        }
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}

public class Server
{

    public static void main(String[] args)
    {
        //every string is case sensitive
	//arg[0] = server name
	//System.out.println(args[0]);
        //ServerThread st = new ServerThread(args[0]);
        //TODO code application logic here
        ServerThread st = new ServerThread("myserver");
    }
}
