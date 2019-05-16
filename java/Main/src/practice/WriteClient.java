package practice;


import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


class Write implements Runnable
{

    Socket socket;
    ObjectOutputStream oos;
    Thread t;
    String name;
    public Write( Socket c, String n )
    {
        System.out.println("start write");
        socket = c;
        name = n;
        try
        {
            oos = new ObjectOutputStream(socket.getOutputStream());
            System.out.println("output");
        } catch (IOException ex)
        {
            Logger.getLogger(Write.class.getName()).log(Level.SEVERE, null, ex);
        }
        t = new Thread(this);
        t.start();
    }
    
    public void run()
    {
        System.out.println("start");
        Scanner in = new Scanner( System.in );
        String s;
        while(true)
        {
            try
            {
                s = in.nextLine();
                s = name + " says: " + s;
                oos.writeObject( (Object)s);
            }
            catch( Exception e )
            {
                System.out.println(e);
            }
        }
    }
    
}