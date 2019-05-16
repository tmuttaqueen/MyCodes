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
import java.net.UnknownHostException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Awesome Muttaqueen
 */
class ClientSend implements Runnable
{

    Thread t;
    ClientRun cr;
    Client client;

    ClientSend(ClientRun c, Client client)
    {
        this.client = client;
        cr = c;
        t = new Thread(this);
        t.start();
    }

    public void run()
    {
        while (true)
        {
            if (client.getSendFlag())
            {

                byte[] sendData = new byte[2048];
                Scanner sc = new Scanner(System.in);
                String msg;
                msg = client.getSend();//sc.nextLine();
                while (!msg.contains("$"))
                {
                    System.out.print("please add '$ ' after receiver name: ");
                    msg = sc.nextLine();
                }
                String too = msg.substring(0, msg.indexOf("$"));
                String bodyy = msg.substring(msg.indexOf("$") + 2);
                msg = "Via: " + cr.serverName + "\nTo: " + too + "\nFrom: " + cr.clientName + "\nBody: " + bodyy;
                System.out.println(msg);
                sendData = msg.getBytes();
                //String temp = new String(sendData);
                //System.out.println(temp);
                DatagramPacket send = new DatagramPacket(sendData, sendData.length, cr.serverIp, cr.serverPort);
                try
                {
                    cr.socket.send(send);

                } catch (IOException ex)
                {
                    Logger.getLogger(ClientRun.class.getName()).log(Level.SEVERE, null, ex);
                }
                client.negetSend();
            }
        }
    }
}

class ClientReceive implements Runnable
{

    Thread t;
    ClientRun cr;
    Client client;

    ClientReceive(ClientRun c, Client client)
    {
        this.client = client;
        cr = c;
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run()
    {
        while (true)
        {
            //if (client.getReceiveFlag())
            //{
                byte[] receiveData = new byte[2048];
                DatagramPacket receive = new DatagramPacket(receiveData, receiveData.length);
                try
                {
                    cr.socket.receive(receive);
                } catch (IOException ex)
                {
                    Logger.getLogger(ClientRun.class.getName()).log(Level.SEVERE, null, ex);
                }
                String data = new String(receive.getData());
                data = data.substring(0, data.indexOf(0));
                System.out.println(data);
                if (data.contains("Via: " + cr.serverName) && data.contains("To: " + cr.clientName))
                {
                    String from = data.substring(data.indexOf("From: ") + ("From: ").length(), data.indexOf("\nBody"));
                    String body = data.substring(data.indexOf("Body: ") + ("Body: ").length());
                    client.setReceive( from + "$" + body);
                    client.negetReceive();
                    //send the data to accurate user here
                    //System.out.println(from + " says: " + body);
                }
                
            //}
        }
    }

}

class ClientRun
{

    DatagramSocket socket;
    String clientName, serverName;
    InetAddress serverIp;
    int serverPort = 45555, port;
    Client client;

    ClientRun(String s, String c, InetAddress is, int mp, Client client)
    {
        port = mp;
        serverName = s;
        clientName = c;
        serverIp = is;
        this.client = client;
        try
        {
            socket = new DatagramSocket(port);
        } catch (SocketException ex)
        {
            Logger.getLogger(ClientRun.class.getName()).log(Level.SEVERE, null, ex);
        }

        sendSignal();
        run();

    }

    void sendSignal()
    {
        byte[] sendData = new byte[2048];
        String s = "Via: " + serverName + "\nTo: " + serverName + "\nFrom: " + clientName + "\nPort: " + port;
        sendData = s.getBytes();
        DatagramPacket send = new DatagramPacket(sendData, sendData.length, serverIp, serverPort);
        try
        {
            socket.send(send);
        } catch (IOException ex)
        {
            Logger.getLogger(ClientRun.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void run()
    {
        ClientSend cs = new ClientSend(this, client);
        ClientReceive cc = new ClientReceive(this, client);
    }

}

public class Client
{

    /*public static void main(String[] args) throws UnknownHostException
    {
        //str[0] = client name, str[1] = client port
	//str[2] = server ip, str[3] = server name
	InetAddress ip = InetAddress.getByName(args[2]);
        ClientRun ct = new ClientRun(args[3], args[0],ip , Integer.parseInt(args[1]));
        // TODO code application logic here
        Scanner ss = new Scanner(System.in);
        String[] str = new String[4];
        for (int i = 0; i < 2; i++)
        {
            str[i] = ss.next();
        }
        InetAddress ip = InetAddress.getByName("localhost");
        ClientRun ct = new ClientRun("god", str[0], ip, Integer.parseInt(str[1]));

    }*/
    boolean sendFlag = false;
    boolean receiveFlag = false;
    String sendString = "";
    String receiveString = "";

    synchronized void negetSend()
    {
        sendFlag = !sendFlag;
    }

    synchronized void negetReceive()
    {
        receiveFlag = !receiveFlag;
    }

    synchronized boolean getSendFlag()
    {
        return sendFlag;
    }

    synchronized boolean getReceiveFlag()
    {
        return receiveFlag;
    }

    synchronized void setSend(String s)
    {
        sendString = s;
    }

    synchronized void setReceive(String s)
    {
        receiveString = s;
    }

    synchronized String getSend()
    {
        return sendString;
    }

    synchronized String getReceive()
    {
        return receiveString;
    }

    Client(String s1, String s2, String s3, String s4) throws UnknownHostException
    {
        InetAddress ip = InetAddress.getByName(s3);
        ClientRun ct = new ClientRun(s4, s1, ip, Integer.parseInt(s2), this);
    }
}
